# iOS CocoaPods 库开发、构建、校验与发布指南

> 本指南涵盖了 /Users/luowei/projects/libs 目录下33个iOS CocoaPods库的完整开发流程和自动化工具使用说明

---

## 目录

1. [概述](#1-概述)
2. [环境配置](#2-环境配置)
3. [项目结构规范](#3-项目结构规范)
4. [开发工作流](#4-开发工作流)
5. [构建与校验](#5-构建与校验)
6. [发布流程](#6-发布流程)
7. [批量操作工具](#7-批量操作工具)
8. [Python自动化工具](#8-python自动化工具)
9. [GitHub Actions CI/CD](#9-github-actions-cicd)
10. [常见问题与解决方案](#10-常见问题与解决方案)
11. [脚本工具索引](#11-脚本工具索引)
12. [项目列表](#12-项目列表)
13. [最佳实践](#13-最佳实践)

---

## 1. 概述

### 1.1 当前环境介绍

本工作区包含 **33个iOS CocoaPods开源库**，所有库名均以 `LW` 开头：

- **所有库**都配置了 `.podspec` 文件
- **所有库**都是Git仓库
- **31个库**使用Travis CI（LWWebLoader和LWWebSocket除外）
- **33个库**现已全部配置GitHub Actions工作流
- **10个库**支持Carthage构建

### 1.2 工作流程总览

```
开发 → 构建 → 校验 → 发布
  ↓      ↓      ↓      ↓
本地   静态库   Pod    私有
调试   打包    校验   Spec
```

**两种发布方式：**
- **GitLab源码发布**: 适用于内部开发，发布源代码
- **Gitee二进制发布**: 适用于外部分发，发布静态库(.a文件)

### 1.3 自动化工具概览

**Shell脚本工具** (位于 `/Users/luowei/bin/`):
- 主工作流脚本: 5个
- 核心模块脚本: 10+个
- 实用工具脚本: 多个

**Python工具** (位于 `/Users/luowei/bin/py/modules/ios_pod/`):
- `pod_manager.py`: 完整的Pod管理和发布解决方案

---

## 2. 环境配置

### 2.1 CocoaPods 安装和配置

```bash
# 安装CocoaPods
sudo gem install cocoapods

# 设置CocoaPods
pod setup

# 验证安装
pod --version
```

### 2.2 私有Spec仓库配置

本项目使用两个私有Spec仓库：

#### GitLab私有Spec仓库

```bash
# 添加GitLab Spec仓库
pod repo add mygitlabrepo https://gitlab.com/ioslibraries1/mygitlabrepo.git

# 验证仓库
pod repo list
```

#### Gitee私有Spec仓库

```bash
# 添加Gitee Spec仓库
pod repo add mygiteerepo https://gitee.com/lw_ios_project/mylibrepo.git

# 验证仓库
pod repo list
```

### 2.3 Xcode 和 iOS SDK 要求

- **Xcode**: 推荐使用最新稳定版本（14.3+）
- **iOS SDK**: 最低支持 iOS 8.0/9.0（根据库而定）
- **命令行工具**: `xcode-select --install`

### 2.4 Git 配置（多远程仓库支持）

```bash
# 配置Git用户信息
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"

# 为单个仓库配置多个远程仓库
cd LWKBCore
git remote add origin_github https://github.com/username/LWKBCore.git
git remote add origin_gitlab https://gitlab.com/username/LWKBCore.git
git remote -v
```

---

## 3. 项目结构规范

### 3.1 标准CocoaPods库结构

```
LWLibraryName/
├── LWLibraryName/           # 源代码目录
│   └── Classes/             # 源文件和头文件
│       ├── *.h              # 公开头文件
│       └── *.m/.swift       # 实现文件
├── LWLibraryName/Assets/    # 资源文件（可选）
│   └── *.png, *.bundle
├── Example/                 # 示例项目
│   ├── LWLibraryName.xcworkspace
│   ├── LWLibraryName.xcodeproj
│   ├── Podfile
│   └── Pods/
├── .github/                 # GitHub Actions工作流
│   └── workflows/
│       └── ci.yml
├── LWLibraryName.podspec    # Pod规范文件
├── README.md                # 项目说明文档
├── LICENSE                  # 开源协议
└── .gitignore               # Git忽略文件
```

### 3.2 Podspec 文件配置

**源码发布版本示例** (GitLab):

```ruby
Pod::Spec.new do |s|
  s.name             = 'LWKBCore'
  s.version          = '1.0.0'
  s.summary          = '简短描述'
  s.description      = '详细描述'

  s.homepage         = 'https://gitlab.com/username/LWKBCore'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Your Name' => 'email@example.com' }

  s.source           = { :git => 'https://gitlab.com/username/LWKBCore.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'

  # 源文件
  s.source_files = 'LWKBCore/Classes/**/*'

  # 公开头文件
  s.public_header_files = 'LWKBCore/Classes/**/*.h'

  # 资源文件
  # s.resources = 'LWKBCore/Assets/**/*'

  # 系统框架依赖
  s.frameworks = 'UIKit', 'Foundation'

  # Pod依赖
  # s.dependency 'AFNetworking', '~> 4.0'
end
```

**二进制发布版本示例** (Gitee):

```ruby
Pod::Spec.new do |s|
  s.name             = 'LWKBCore'
  s.version          = '1.0.0'
  s.summary          = '简短描述'

  s.homepage         = 'https://gitee.com/username/LWKBCore'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Your Name' => 'email@example.com' }

  s.source           = { :git => 'https://gitee.com/username/LWKBCore.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'

  # 静态库
  s.ios.vendored_libraries = 'ios/libLWKBCore.a'

  # 公开头文件
  s.source_files = 'Headers/**/*.h'
  s.public_header_files = 'Headers/**/*.h'

  # 资源
  # s.resources = 'Assets/**/*'

  s.frameworks = 'UIKit', 'Foundation'
end
```

### 3.3 Example 项目组织

```
Example/
├── LWLibraryName/           # Example应用代码
│   ├── AppDelegate.h/m
│   ├── ViewController.h/m
│   └── Info.plist
├── LWLibraryName.xcodeproj  # Xcode项目
├── LWLibraryName.xcworkspace # Workspace（pod install后生成）
├── Podfile                  # CocoaPods依赖文件
├── Podfile.lock             # 锁定依赖版本
└── Pods/                    # 依赖库（pod install后生成）
```

**Podfile示例**:

```ruby
platform :ios, '9.0'

# 修复Xcode 11+的Assets.car冲突问题
install! 'cocoapods', :disable_input_output_paths => true

target 'LWKBCore_Example' do
  # use_frameworks!  # 静态库不需要此行

  # 开发时使用本地路径
  pod 'LWKBCore', :path => '../'

  # 或从私有仓库安装
  # pod 'LWKBCore', '~> 1.0.0'

  target 'LWKBCore_Tests' do
    inherit! :search_paths
    # 测试依赖
    # pod 'Specta'
  end
end
```

### 3.4 Assets 资源管理

```
LWLibraryName/Assets/
├── Images/
│   ├── icon@2x.png
│   └── icon@3x.png
├── LWLibraryName.bundle/    # Bundle资源
│   ├── images/
│   └── config.plist
└── other_resources.*
```

在Podspec中配置：

```ruby
s.resource_bundles = {
  'LWLibraryName' => ['LWLibraryName/Assets/**/*']
}
# 或
s.resources = 'LWLibraryName/Assets/**/*'
```

### 3.5 源代码组织 (Classes目录)

```
LWLibraryName/Classes/
├── Core/                    # 核心功能
│   ├── LWCore.h
│   └── LWCore.m
├── Models/                  # 数据模型
│   └── LWModel.h/m
├── Views/                   # 视图组件
│   └── LWView.h/m
├── Controllers/             # 控制器
│   └── LWController.h/m
├── Utilities/               # 工具类
│   └── LWUtility.h/m
└── LWLibraryName.h          # 主头文件（导入所有公开头文件）
```

---

## 4. 开发工作流

### 4.1 本地开发

#### 步骤1: 克隆项目

```bash
cd /Users/luowei/projects/libs
git clone https://gitlab.com/username/LWKBCore.git
cd LWKBCore
```

#### 步骤2: 安装依赖

```bash
cd Example
pod install
```

#### 步骤3: 打开Workspace开发

```bash
open LWKBCore.xcworkspace
```

#### 步骤4: 运行Example项目

在Xcode中:
1. 选择 `LWKBCore-Example` scheme
2. 选择iOS模拟器
3. 按 `Cmd+R` 运行

或使用命令行：

```bash
# 使用自动化脚本运行
/Users/luowei/bin/ck_giteelib_runstatus.sh LWKBCore

# 选择菜单选项4: 运行库Example项目
```

### 4.2 版本管理

#### 语义化版本规范

采用 `MAJOR.MINOR.PATCH` 格式：

- **MAJOR**: 不兼容的API修改
- **MINOR**: 向后兼容的功能新增
- **PATCH**: 向后兼容的问题修正

**示例**:
- `1.0.0` - 首个稳定版本
- `1.1.0` - 新增功能
- `1.1.1` - Bug修复
- `2.0.0` - 重大变更

#### Git标签管理

```bash
# 创建标签（与podspec版本一致）
git tag 1.0.0

# 推送标签到远程
git push origin 1.0.0

# 删除本地标签
git tag --delete 1.0.0

# 删除远程标签
git push origin :1.0.0
```

**使用自动化脚本重新创建标签**:

脚本 `/Users/luowei/bin/ck_giteelib_runstatus.sh` 中的 `recreate_tag()` 函数会：
1. 从podspec中读取版本号
2. 删除本地和远程的同名标签
3. 创建新标签
4. 推送到远程

#### Podspec版本同步

**关键**: Podspec中的版本必须与Git标签匹配！

```ruby
# LWKBCore.podspec
s.version = '1.0.0'
s.source  = { :git => 'https://gitlab.com/...', :tag => s.version.to_s }
```

发布前检查清单：
- [ ] Podspec的 `s.version` 已更新
- [ ] Git标签已创建并推送
- [ ] Git标签名称与 `s.version` 完全一致

---

## 5. 构建与校验

### 5.1 Podspec校验

#### 方法1: 使用shell脚本模块

```bash
# 导入模块
source /Users/luowei/bin/moudle/package_alib.sh

# GitLab源码校验
speclint_gitlab LWKBCore

# Gitee二进制校验
speclint_gitee LWKBCore
```

#### 方法2: 直接使用pod命令

```bash
# 基础校验
pod spec lint LWKBCore.podspec

# 允许警告
pod spec lint LWKBCore.podspec --allow-warnings

# 详细输出
pod spec lint LWKBCore.podspec --verbose --allow-warnings

# 指定spec源（用于有依赖的库）
pod spec lint LWKBCore.podspec \
  --sources='https://gitlab.com/ioslibraries1/mygitlabrepo.git,https://github.com/CocoaPods/Specs.git' \
  --allow-warnings
```

#### 方法3: 使用Python工具

```bash
cd /Users/luowei/projects/libs/LWKBCore
python /Users/luowei/bin/py/modules/ios_pod/pod_manager.py

# 选择菜单选项2: 校验Podspec
```

#### 校验标志说明

| 标志 | 说明 |
|------|------|
| `--allow-warnings` | 允许警告（推荐） |
| `--verbose` | 详细输出，显示详细错误信息 |
| `--skip-import-validation` | 跳过导入验证 |
| `--use-libraries` | 使用静态库而非frameworks |
| `--sources` | 指定额外的spec源 |

### 5.2 静态库打包

#### 方法1: 使用shell脚本

```bash
cd /Users/luowei/projects/libs/LWKBCore

# 导入打包模块
source /Users/luowei/bin/moudle/package_alib.sh

# 打包为静态库
package_alib LWKBCore

# 针对有依赖的库（如LWPusher, LWWordEngine）
package_alib LWKBCore --no-mangle
```

脚本执行的命令：

```bash
pod package LWKBCore.podspec \
  --force \
  --library \
  --configuration=Release
```

对于有依赖的库：

```bash
pod package LWKBCore.podspec \
  --force \
  --library \
  --configuration=Release \
  --no-mangle \
  --spec-sources='https://gitlab.com/ioslibraries1/mygitlabrepo.git,https://github.com/CocoaPods/Specs.git'
```

#### 方法2: 使用Python工具构建通用静态库

```bash
python /Users/luowei/bin/py/modules/ios_pod/pod_manager.py

# 选择菜单选项3: 构建静态库
```

Python工具会构建**通用静态库** (Universal Binary):
1. 构建ARM64架构（设备）
2. 构建x86_64架构（模拟器）
3. 使用 `lipo` 合并为通用库

```bash
# Python内部执行的命令
xcodebuild -target LWKBCore -configuration Release -arch arm64 -sdk iphoneos
xcodebuild -target LWKBCore -configuration Release -arch x86_64 -sdk iphonesimulator
lipo -create libLWKBCore-arm64.a libLWKBCore-x86_64.a -output libLWKBCore.a
```

#### 打包输出结构

```
LWKBCore-{version}/
├── ios/
│   └── LWKBCore.framework/  # 或 libLWKBCore.a
└── LWKBCore.podspec
```

### 5.3 Example项目运行测试

#### 方法1: 使用自动化脚本（推荐）

```bash
/Users/luowei/bin/ck_giteelib_runstatus.sh LWKBCore
```

**交互菜单**:
```
请选择：
1) 打包源码并复制库文件
2) 复制pod示例和.a文件并修改Podfile
3) 校验库podspec
4) 运行库Example项目
5) 打包、复制并验证库Example运行
```

选择选项4或5，脚本将：
1. 进入Example目录
2. 执行 `pod install`
3. 确定正确的scheme名称
4. 构建并在模拟器中运行

#### 方法2: 手动命令

```bash
# 进入Example目录
cd /Users/luowei/projects/libs/LWKBCore/Example

# 安装依赖
pod install

# 构建Example
xcodebuild clean build \
  -workspace LWKBCore.xcworkspace \
  -scheme LWKBCore-Example \
  -sdk iphonesimulator \
  -configuration Debug

# 运行测试
xcodebuild test \
  -workspace LWKBCore.xcworkspace \
  -scheme LWKBCore-Example \
  -sdk iphonesimulator \
  -destination 'platform=iOS Simulator,name=iPhone 14'
```

#### 方法3: 使用模拟器安装运行脚本

```bash
source /Users/luowei/bin/moudle/installrun_iosapp.sh

cd /Users/luowei/projects/libs/LWKBCore/Example
installrun_iosapp LWKBCore
```

脚本会：
1. 构建应用
2. 启动或检测已运行的模拟器
3. 安装应用到模拟器
4. 启动应用

---

## 6. 发布流程

### 6.1 GitLab源码发布（推荐用于内部开发）

#### 特点
- 发布源代码到GitLab
- 用户通过pod安装时会编译源码
- 适合团队内部使用，便于调试

#### 使用方法

**发布所有库**:

```bash
cd /Users/luowei/projects/libs
/Users/luowei/bin/wf_gitlablibs_publish.sh
```

**发布单个库**:

```bash
/Users/luowei/bin/wf_gitlablibs_publish.sh -n LWKBCore -p /Users/luowei/projects/libs
```

#### 流程说明

脚本自动执行以下步骤：

1. **Git提交并推送代码**
   ```bash
   git add .
   git commit -am "修改 2025-01-15-1230abcd"
   git push origin master
   ```

2. **发布Podspec到mygitlabrepo**
   ```bash
   pod repo push mygitlabrepo LWKBCore.podspec \
     --verbose \
     --allow-warnings \
     --use-libraries \
     --skip-import-validation \
     --sources='https://gitlab.com/ioslibraries1/mygitlabrepo.git,https://github.com/CocoaPods/Specs.git'
   ```

3. **更新本地Spec仓库**
   ```bash
   pod repo update mygitlabrepo
   ```

4. **清理Pod缓存**（如果有修改）
   ```bash
   pod cache clean LWKBCore --all
   ```

#### 使用已发布的库

```ruby
# Podfile
source 'https://gitlab.com/ioslibraries1/mygitlabrepo.git'
source 'https://github.com/CocoaPods/Specs.git'

target 'MyApp' do
  pod 'LWKBCore', '~> 1.0.0'
end
```

### 6.2 Gitee二进制发布（推荐用于外部分发）

#### 特点
- 发布编译后的静态库(.a文件)到Gitee
- 用户通过pod安装时无需编译，速度快
- 保护源代码，适合外部分发
- 文件体积较小

#### 使用方法

**发布所有库**:

```bash
cd /Users/luowei/projects/libs
/Users/luowei/bin/wf_giteelibs_publish.sh
```

**发布单个库**:

```bash
/Users/luowei/bin/wf_giteelibs_publish.sh -n LWKBCore -p /Users/luowei/projects/libs
```

#### 流程说明

脚本自动执行以下步骤：

1. **打包源码为.a静态库**
   ```bash
   pod package LWKBCore.podspec --force --library --configuration=Release
   ```

2. **复制文件到Gitee仓库目录**
   - .a库文件 → `ios/` 目录
   - 头文件 → `Headers/` 目录
   - Example项目 → `Example/` 目录
   - Assets资源 → `Assets/` 目录

3. **修改Podspec为二进制配置**
   - 更新 `s.homepage` 为Gitee地址
   - 更新 `s.source` 为Gitee仓库
   - 更改 `s.source_files` 指向 `Headers/`
   - 添加 `s.ios.vendored_libraries` 指向 `.a` 文件

4. **在Gitee仓库执行pod install**
   ```bash
   cd Gitee仓库/Example
   pod install
   ```

5. **提交并推送到Gitee**
   ```bash
   git add .
   git commit -am "修改 2025-01-15-1230abcd"
   git push origin master
   ```

6. **重新创建Git标签**
   ```bash
   # 从podspec读取版本号
   version=$(grep "s\.version\s*=\s*" "LWKBCore.podspec" | awk -F "\"|'" '{print $2}')

   # 删除旧标签
   git tag --delete "$version"
   git push origin :"$version"

   # 创建并推送新标签
   git tag "$version"
   git push origin "$version"
   ```

7. **发布到mygiteerepo Spec仓库**
   ```bash
   pod repo push mygiteerepo LWKBCore.podspec \
     --skip-import-validation \
     --allow-warnings \
     --use-libraries \
     --sources='https://gitee.com/lw_ios_project/mylibrepo.git,https://github.com/CocoaPods/Specs.git'
   ```

8. **更新本地mygiteerepo**
   ```bash
   pod repo update mygiteerepo
   ```

9. **清理Pod缓存**
   ```bash
   pod cache clean LWKBCore --all
   ```

#### 使用已发布的库

```ruby
# Podfile
source 'https://gitee.com/lw_ios_project/mylibrepo.git'
source 'https://github.com/CocoaPods/Specs.git'

target 'MyApp' do
  pod 'LWKBCore', '~> 1.0.0'
end
```

### 6.3 首次Gitee仓库初始化

如果是第一次为库创建Gitee二进制发布仓库：

```bash
/Users/luowei/bin/wf_giteelibs_initpush.sh -n LWKBCore -p /Users/luowei/projects/libs
```

脚本会：
1. 打包GitLab库源码为.a库
2. 创建本地Gitee仓库目录
3. 复制podspec和.gitignore
4. 初始化git仓库
5. 推送到Gitee远程仓库

**前提条件**:
- 在Gitee上已创建对应的空仓库
- 配置好Gitee的SSH密钥或凭据

### 6.4 使用Python工具发布

```bash
cd /Users/luowei/projects/libs/LWKBCore
python /Users/luowei/bin/py/modules/ios_pod/pod_manager.py

# 选择菜单选项5: 发布到Gitee
```

Python工具提供完整的发布流程：
1. 校验pod目录
2. 初始化Git（如需要）
3. 添加远程仓库
4. 安装依赖
5. 提交修改
6. 推送到远程
7. 发布podspec
8. 更新spec仓库

---

## 7. 批量操作工具

### 7.1 批量任务处理

#### 脚本: loopdo_tasks.sh

**位置**: `/Users/luowei/bin/loopdo_tasks.sh`

#### 使用场景

- 批量提交推送多个库的Git修改
- 批量修改文件（如.gitignore）
- 批量文件操作（重命名、删除、压缩）

#### 使用方法

**交互式菜单模式**:

```bash
cd /Users/luowei/projects/libs
/Users/luowei/bin/loopdo_tasks.sh
```

菜单选项：
```
请选择：
1) git仓库commit并push
2) PNG添加@3x后缀
```

**命令行参数模式**:

```bash
# 处理所有LW*库
/Users/luowei/bin/loopdo_tasks.sh

# 处理特定库
/Users/luowei/bin/loopdo_tasks.sh -n LWKBCore --path /Users/luowei/projects/libs
```

#### 内置任务函数

**1. task_git_commitAndPush**
- 检查是否有修改
- 自动提交并推送
- 支持多远程仓库

**2. task_append_text**
- 向.gitignore追加忽略规则
- 默认添加: `build/`, `product/`, `$item-*/`

**3. task_override_podspec**
- 从源目录复制podspec到mygitlabrepo

**4. task_rmfile**
- 删除指定文件

**5. rename_png_appen_3x**
- 批量为PNG文件添加@3x后缀

#### 自定义任务

在脚本中添加自定义任务函数：

```bash
# 在loopdo_tasks.sh中定义
my_custom_task() {
    echo "执行自定义任务: $1"
    # 你的逻辑
}

# 在excuteTask中调用
excuteTask() {
    local itemName=$1
    surround_cd "$itemName" my_custom_task "$itemName"
}
```

### 7.2 批量状态检查

#### 使用Python工具批量检查

```python
# 自定义Python脚本
from pathlib import Path
import sys
sys.path.append('/Users/luowei/bin/py/modules')

from ios_pod.pod_manager import PodManager

libs_dir = Path('/Users/luowei/projects/libs')
pm = PodManager(libs_dir)

# 查找所有podspec
for podspec in libs_dir.glob('LW*/*.podspec'):
    lib_name = podspec.stem
    status = pm.check_pod_status(str(podspec.parent))
    print(f"{lib_name}: {status}")
```

输出示例：
```
LWKBCore: {'path_exists': True, 'has_podspec': True, 'has_example': True, 'has_git': True, 'podspec_valid': True, 'dependencies_installed': True}
```

---

## 8. Python自动化工具

### 8.1 pod_manager.py 概述

**位置**: `/Users/luowei/bin/py/modules/ios_pod/pod_manager.py`

**目的**: 使用Python替代Shell脚本，提供更易维护和扩展的Pod管理解决方案

**主要类**: `PodManager`

### 8.2 启动交互式菜单

```bash
cd /Users/luowei/projects/libs/LWKBCore
python /Users/luowei/bin/py/modules/ios_pod/pod_manager.py
```

**菜单选项**:
```
=== iOS Pod Manager ===
1. Check Pod Status
2. Validate Podspec
3. Build Static Library
4. Package Pod Library
5. Publish to Gitee
6. Install Pod Dependencies
0. Exit
```

### 8.3 主要功能详解

#### 功能1: Check Pod Status (检查Pod状态)

**方法**: `check_pod_status(pod_path)`

**返回信息**:
```python
{
    'path_exists': True/False,           # 路径是否存在
    'has_podspec': True/False,           # 是否有podspec文件
    'has_example': True/False,           # 是否有Example目录
    'has_git': True/False,               # 是否是Git仓库
    'podspec_valid': True/False,         # Podspec是否有效
    'dependencies_installed': True/False # 依赖是否已安装
}
```

**使用场景**:
- 发布前检查
- 批量验证多个库的状态
- 诊断问题

#### 功能2: Validate Podspec (校验Podspec)

**方法**: `validate_podspec(podspec_path)`

**执行命令**:
```bash
pod spec lint {podspec_path} --allow-warnings
```

**返回**: `True` (成功) 或 `False` (失败)

**特点**:
- 捕获并显示详细错误信息
- 自动使用 `--allow-warnings` 标志
- 彩色输出（成功/失败）

#### 功能3: Build Static Library (构建静态库)

**方法**: `build_static_library(project_path, target_name)`

**构建流程**:

1. **构建ARM64架构** (真机)
   ```bash
   xcodebuild -target {target_name} \
     -configuration Release \
     -arch arm64 \
     -sdk iphoneos \
     BUILD_DIR={build_dir}
   ```

2. **构建x86_64架构** (模拟器)
   ```bash
   xcodebuild -target {target_name} \
     -configuration Release \
     -arch x86_64 \
     -sdk iphonesimulator \
     BUILD_DIR={build_dir}
   ```

3. **创建通用库**
   ```bash
   lipo -create \
     {build_dir}/Release-iphoneos/lib{target_name}.a \
     {build_dir}/Release-iphonesimulator/lib{target_name}.a \
     -output {build_dir}/lib{target_name}.a
   ```

**返回**: 通用库的路径或 `None` (失败)

**优势**:
- 一步生成同时支持真机和模拟器的通用库
- 自动处理构建目录
- 详细的错误报告

#### 功能4: Package Pod Library (打包Pod库)

**方法**: `package_pod_library(source_project_path, target_pod_path, library_name)`

**创建的Pod结构**:
```
{target_pod_path}/
├── lib/
│   └── lib{library_name}.a         # 通用静态库
├── {library_name}/                 # 公开头文件
│   └── *.h
├── Example/                        # Example项目（复制）
│   ├── {library_name}.xcodeproj
│   ├── {library_name}.xcworkspace
│   └── Podfile
├── Assets/                         # 资源文件（如果存在）
├── {library_name}.podspec          # Pod规范
└── Example/Podfile                 # 修改后的Podfile
```

**执行步骤**:
1. 构建通用静态库
2. 创建Pod目录结构
3. 复制静态库到 `lib/` 目录
4. 递归复制所有头文件到库目录
5. 复制Example项目（如果存在）
6. 复制Assets资源（如果存在）
7. 创建或复制podspec文件
8. 生成Example Podfile

**自动生成的Podspec**:
```ruby
Pod::Spec.new do |s|
  s.name             = '{library_name}'
  s.version          = '1.0.0'
  s.summary          = 'A short description of {library_name}.'
  s.description      = 'A longer description of {library_name}.'

  s.homepage         = 'https://github.com/username/{library_name}'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Your Name' => 'email@example.com' }
  s.source           = { :git => 'https://github.com/username/{library_name}.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'

  s.vendored_libraries = 'lib/lib{library_name}.a'
  s.source_files = '{library_name}/**/*.h'
  s.public_header_files = '{library_name}/**/*.h'

  s.frameworks = 'UIKit', 'Foundation'
end
```

**自动生成的Podfile**:
```ruby
platform :ios, '9.0'

target '{library_name}_Example' do
  use_frameworks!

  pod '{library_name}', :path => '../'

  target '{library_name}_Tests' do
    inherit! :search_paths
  end
end
```

#### 功能5: Publish to Gitee (发布到Gitee)

**方法**: `publish_to_gitee(pod_path, gitee_repo_url, spec_repo='mygiteerepo')`

**完整发布流程**:

1. **校验pod目录存在**
2. **初始化Git仓库**（如果未初始化）
   ```bash
   git init
   ```
3. **添加远程仓库**
   ```bash
   git remote add origin {gitee_repo_url}
   ```
4. **安装Pod依赖**（如果有Example/Podfile）
   ```bash
   cd Example && pod install
   ```
5. **提交修改**
   ```bash
   git add .
   git commit -m "Update library"
   ```
6. **推送到远程**
   ```bash
   git push origin master
   ```
7. **发布Podspec到Spec仓库**
   ```bash
   pod repo push {spec_repo} {podspec_path} --allow-warnings
   ```
8. **更新本地Spec仓库**
   ```bash
   pod repo update {spec_repo}
   ```

**参数说明**:
- `pod_path`: 本地Pod库路径
- `gitee_repo_url`: Gitee远程仓库URL（如 `https://gitee.com/username/LWKBCore.git`）
- `spec_repo`: Spec仓库名称（默认 `mygiteerepo`）

**返回**: `True` (成功) 或 `False` (失败)

#### 功能6: Install Pod Dependencies (安装Pod依赖)

**方法**: `install_pod_dependencies(pod_path)`

**执行步骤**:
1. 检查 `Example/` 目录是否存在
2. 检查 `Example/Podfile` 是否存在
3. 执行 `pod install`
4. 捕获并显示输出

**执行命令**:
```bash
cd {pod_path}/Example
pod install
```

**特点**:
- 自动检测Podfile位置
- 优雅处理缺失的Example或Podfile
- 实时输出安装进度

### 8.4 编程式使用

除了交互式菜单，也可以在Python脚本中直接调用：

```python
#!/usr/bin/env python3
from pathlib import Path
import sys

# 添加模块路径
sys.path.append('/Users/luowei/bin/py/modules')

from ios_pod.pod_manager import PodManager

# 初始化管理器
pm = PodManager('/Users/luowei/projects/libs')

# 校验podspec
pod_path = '/Users/luowei/projects/libs/LWKBCore'
podspec = f'{pod_path}/LWKBCore.podspec'
if pm.validate_podspec(podspec):
    print("✓ Podspec有效")
else:
    print("✗ Podspec无效")

# 检查状态
status = pm.check_pod_status(pod_path)
print(f"状态: {status}")

# 构建静态库
lib_path = pm.build_static_library(
    project_path=f'{pod_path}/LWKBCore.xcodeproj',
    target_name='LWKBCore'
)
print(f"静态库路径: {lib_path}")

# 打包Pod库
pm.package_pod_library(
    source_project_path=f'{pod_path}/LWKBCore.xcodeproj',
    target_pod_path='/path/to/output/LWKBCore',
    library_name='LWKBCore'
)

# 发布到Gitee
pm.publish_to_gitee(
    pod_path='/path/to/packaged/LWKBCore',
    gitee_repo_url='https://gitee.com/username/LWKBCore.git',
    spec_repo='mygiteerepo'
)
```

### 8.5 批量处理示例

```python
#!/usr/bin/env python3
from pathlib import Path
import sys

sys.path.append('/Users/luowei/bin/py/modules')
from ios_pod.pod_manager import PodManager

libs_dir = Path('/Users/luowei/projects/libs')
pm = PodManager(libs_dir)

# 查找所有LW*库
for lib_dir in sorted(libs_dir.glob('LW*')):
    if not lib_dir.is_dir():
        continue

    lib_name = lib_dir.name
    print(f"\n=== Processing {lib_name} ===")

    # 检查状态
    status = pm.check_pod_status(str(lib_dir))

    if not status['has_podspec']:
        print(f"  ⚠ No podspec found, skipping")
        continue

    # 校验podspec
    podspec_files = list(lib_dir.glob('*.podspec'))
    if podspec_files:
        podspec = str(podspec_files[0])
        if pm.validate_podspec(podspec):
            print(f"  ✓ Podspec valid")
        else:
            print(f"  ✗ Podspec invalid")

    # 安装依赖（如果Example存在）
    if status['has_example']:
        pm.install_pod_dependencies(str(lib_dir))
        print(f"  ✓ Dependencies installed")

print("\n=== All libraries processed ===")
```

---

## 9. GitHub Actions CI/CD

### 9.1 概述

所有33个LW*库现已配置GitHub Actions自动化工作流，位于各库的 `.github/workflows/ci.yml`

### 9.2 工作流触发条件

- **Push事件**: 推送到 `main` 或 `master` 分支
- **Pull Request**: 针对 `main` 或 `master` 分支的PR
- **手动触发**: 通过GitHub UI手动运行

```yaml
on:
  push:
    branches: [ main, master ]
  pull_request:
    branches: [ main, master ]
  workflow_dispatch:
```

### 9.3 工作流Job详解

#### Job 1: validate-podspec (校验Podspec)

**目的**: 验证Podspec配置正确性

**运行环境**: `macos-latest`

**步骤**:
1. Checkout代码
2. 设置Ruby 3.0环境
3. 安装CocoaPods
4. 执行 `pod lib lint --allow-warnings`

```yaml
validate-podspec:
  name: Validate Podspec
  runs-on: macos-latest
  steps:
    - name: Checkout
      uses: actions/checkout@v4

    - name: Setup Ruby
      uses: ruby/setup-ruby@v1
      with:
        ruby-version: '3.0'
        bundler-cache: true

    - name: Install CocoaPods
      run: gem install cocoapods

    - name: Validate Podspec
      run: pod lib lint --allow-warnings
```

#### Job 2: build-example (构建Example)

**目的**: 构建并测试Example项目

**运行环境**: `macos-latest`

**矩阵策略**: 多Xcode版本测试
- Xcode 14.3.1
- Xcode 15.0

**步骤**:
1. Checkout代码
2. 选择Xcode版本
3. 设置Ruby环境
4. **缓存CocoaPods依赖**（加速构建）
5. 安装Pod依赖
6. 构建并测试Example项目

```yaml
build-example:
  name: Build Example
  runs-on: macos-latest
  strategy:
    fail-fast: false
    matrix:
      xcode: ['14.3.1', '15.0']
  steps:
    - name: Checkout
      uses: actions/checkout@v4

    - name: Select Xcode
      run: sudo xcode-select -s /Applications/Xcode_${{ matrix.xcode }}.app

    - name: Setup Ruby
      uses: ruby/setup-ruby@v1
      with:
        ruby-version: '3.0'

    - name: Cache CocoaPods
      uses: actions/cache@v3
      with:
        path: Example/Pods
        key: ${{ runner.os }}-pods-${{ hashFiles('Example/Podfile.lock') }}
        restore-keys: |
          ${{ runner.os }}-pods-

    - name: Install Dependencies
      run: |
        cd Example
        pod install

    - name: Build Example
      run: |
        cd Example
        xcodebuild build test \
          -workspace {LibraryName}.xcworkspace \
          -scheme {LibraryName}-Example \
          -sdk iphonesimulator \
          -destination 'platform=iOS Simulator,name=iPhone 14' \
          -enableCodeCoverage YES \
          | xcpretty
```

**关键特性**:
- `fail-fast: false`: 一个Xcode版本失败不影响其他版本
- CocoaPods缓存: 使用 `Podfile.lock` 作为缓存key
- 代码覆盖率: `-enableCodeCoverage YES`
- 格式化输出: `| xcpretty`

#### Job 3: validate-carthage (Carthage校验)

**目的**: 验证Carthage构建兼容性

**仅适用于**: 10个支持Carthage的库
- LWAspectsHook
- LWAudioPlayer
- LWContactManager
- LWDrawboard
- LWEncryptor
- LWLogger
- LWPhotoPicker
- LWProgressView
- LWPurchase
- LWWebUI

**运行环境**: `macos-latest`

**步骤**:
1. Checkout代码
2. 安装Carthage
3. 构建XCFramework

```yaml
validate-carthage:
  name: Validate Carthage
  runs-on: macos-latest
  steps:
    - name: Checkout
      uses: actions/checkout@v4

    - name: Install Carthage
      run: brew install carthage

    - name: Build with Carthage
      run: carthage build --no-skip-current --use-xcframeworks
```

### 9.4 查看工作流状态

#### 在GitHub上查看

1. 进入库的GitHub仓库页面
2. 点击 "Actions" 标签
3. 查看所有工作流运行历史
4. 点击特定运行查看详细日志

#### 在README中添加Badge

```markdown
![CI Status](https://github.com/username/LWKBCore/workflows/CI/badge.svg)
```

显示效果: ![CI Status](https://github.com/username/LWKBCore/workflows/CI/badge.svg)

### 9.5 本地测试工作流

使用 [act](https://github.com/nektos/act) 工具在本地运行GitHub Actions：

```bash
# 安装act
brew install act

# 运行所有jobs
cd /Users/luowei/projects/libs/LWKBCore
act

# 运行特定job
act -j validate-podspec
act -j build-example

# 列出所有工作流
act -l
```

### 9.6 自定义工作流

如果需要修改工作流，编辑 `.github/workflows/ci.yml`:

**添加Slack通知**:

```yaml
- name: Notify Slack
  if: failure()
  uses: 8398a7/action-slack@v3
  with:
    status: ${{ job.status }}
    text: 'Build failed!'
    webhook_url: ${{ secrets.SLACK_WEBHOOK }}
```

**添加发布自动化**:

```yaml
publish:
  name: Publish to Spec Repo
  runs-on: macos-latest
  if: github.ref == 'refs/heads/master' && github.event_name == 'push'
  needs: [validate-podspec, build-example]
  steps:
    - name: Checkout
      uses: actions/checkout@v4

    - name: Setup Ruby
      uses: ruby/setup-ruby@v1
      with:
        ruby-version: '3.0'

    - name: Install CocoaPods
      run: gem install cocoapods

    - name: Publish to Spec Repo
      env:
        COCOAPODS_TRUNK_TOKEN: ${{ secrets.COCOAPODS_TRUNK_TOKEN }}
      run: |
        pod repo add mygitlabrepo https://gitlab.com/ioslibraries1/mygitlabrepo.git
        pod repo push mygitlabrepo *.podspec --allow-warnings
```

---

## 10. 常见问题与解决方案

### 10.1 Xcode 11+ "Multiple commands produce Assets.car"

#### 问题描述

在Xcode 11及更高版本中，使用CocoaPods安装依赖后构建项目时，会出现以下错误：

```
error: Multiple commands produce '.../Assets.car'
```

#### 原因

Xcode 11改变了构建系统的行为，导致CocoaPods生成的项目产生Assets冲突。

#### 解决方案

在 `Podfile` 的**第2行**插入以下配置：

```ruby
platform :ios, '9.0'
install! 'cocoapods', :disable_input_output_paths => true

target 'MyApp' do
  # ...
end
```

#### 自动修复

脚本 `/Users/luowei/bin/ck_giteelib_runstatus.sh` 中的 `copy_podexample_and_update_podfile()` 函数会自动执行此修复：

```bash
sed -i "" "2i\\
install! 'cocoapods', :disable_input_output_paths => true\\
" "$targetPath/Example/Podfile"
```

### 10.2 Pod依赖冲突

#### 问题描述

```
[!] Unable to find a specification for `LWKBCore (~> 1.0.0)`
```

或

```
[!] CocoaPods could not find compatible versions for pod "LWKBCore"
```

#### 解决方案

**步骤1: 清理CocoaPods缓存**

```bash
# 清理特定库
pod cache clean LWKBCore --all

# 清理所有缓存
pod cache clean --all
```

**步骤2: 删除Pods目录和重新安装**

```bash
cd Example
rm -rf Pods
rm Podfile.lock
pod deintegrate
pod install
```

**步骤3: 更新Spec仓库**

```bash
pod repo update
pod repo update mygitlabrepo
pod repo update mygiteerepo
```

**步骤4: 检查Spec源配置**

确保Podfile中包含所有必要的源：

```ruby
source 'https://github.com/CocoaPods/Specs.git'
source 'https://gitlab.com/ioslibraries1/mygitlabrepo.git'
source 'https://gitee.com/lw_ios_project/mylibrepo.git'

target 'MyApp' do
  pod 'LWKBCore', '~> 1.0.0'
end
```

### 10.3 Podspec校验失败

#### 问题描述

```bash
$ pod spec lint LWKBCore.podspec

-> LWKBCore (1.0.0)
    - ERROR | [iOS] unknown: Encountered an unknown error (...) during validation.
```

#### 常见原因和解决方案

**原因1: Git标签不存在或不匹配**

```ruby
# Podspec中
s.version = '1.0.0'
s.source  = { :git => 'https://gitlab.com/...', :tag => s.version.to_s }
```

解决方案：
```bash
# 创建并推送标签
git tag 1.0.0
git push origin 1.0.0
```

**原因2: 源文件路径错误**

```ruby
s.source_files = 'LWKBCore/Classes/**/*'  # 确保路径正确
```

解决方案：检查目录结构是否匹配

**原因3: 依赖的Spec源未指定**

解决方案：
```bash
pod spec lint LWKBCore.podspec \
  --sources='https://gitlab.com/ioslibraries1/mygitlabrepo.git,https://github.com/CocoaPods/Specs.git' \
  --allow-warnings
```

**原因4: 有警告**

解决方案：使用 `--allow-warnings` 标志
```bash
pod spec lint LWKBCore.podspec --allow-warnings
```

**原因5: 导入验证失败**

解决方案：跳过导入验证
```bash
pod spec lint LWKBCore.podspec --skip-import-validation --allow-warnings
```

#### 查看详细错误信息

```bash
pod spec lint LWKBCore.podspec --verbose --allow-warnings
```

### 10.4 静态库依赖问题

#### 问题描述

打包有依赖的库（如LWPusher, LWWordEngine）时出错：

```
[!] Unable to find a specification for dependency `AFNetworking`
```

#### 解决方案

**方法1: 使用 `--no-mangle` 标志**

```bash
pod package LWPusher.podspec \
  --force \
  --library \
  --configuration=Release \
  --no-mangle \
  --spec-sources='https://gitlab.com/ioslibraries1/mygitlabrepo.git,https://github.com/CocoaPods/Specs.git'
```

**方法2: 在脚本中指定**

在 `/Users/luowei/bin/moudle/package_alib.sh` 中，有特殊库的处理逻辑：

```bash
if [ "$itemName" == "LWPusher" ] || [ "$itemName" == "LWWordEngine" ]; then
    flags="--no-mangle"
else
    flags=""
fi

pod package "${itemName}.podspec" $flags --force --library --configuration=Release
```

### 10.5 模拟器安装失败

#### 问题描述

```
Unable to install app: Error Domain=...
```

#### 解决方案

**步骤1: 重启模拟器**

```bash
# 关闭所有模拟器
killall Simulator

# 重新启动
open -a Simulator
```

**步骤2: 删除旧应用**

```bash
# 列出已安装的应用
xcrun simctl listapps booted

# 卸载应用
xcrun simctl uninstall booted com.example.LWKBCore-Example

# 重新安装
xcrun simctl install booted /path/to/LWKBCore-Example.app
```

**步骤3: 重置模拟器**

```bash
# 列出所有模拟器
xcrun simctl list devices

# 擦除特定模拟器
xcrun simctl erase <device-uuid>

# 或在Simulator菜单中: Device → Erase All Content and Settings
```

### 10.6 Git推送失败

#### 问题描述

```
! [rejected]        master -> master (fetch first)
error: failed to push some refs to 'https://gitlab.com/...'
```

#### 解决方案

**情况1: 远程有新提交**

```bash
# 拉取并rebase
git pull --rebase origin master

# 解决冲突（如果有）
git add .
git rebase --continue

# 推送
git push origin master
```

**情况2: 本地和远程分叉**

```bash
# 查看状态
git status

# 强制推送（谨慎使用！）
git push -f origin master

# 或重置到远程状态
git fetch origin
git reset --hard origin/master
```

脚本 `/Users/luowei/bin/moudle/git_update.sh` 中的 `git_commitAndPush()` 函数已实现智能同步：

```bash
LOCAL=$(git rev-parse $BRANCH)
REMOTE_HEAD=$(git rev-parse $REMOTE/$BRANCH)
BASE=$(git merge-base $BRANCH $REMOTE/$BRANCH)

if [ $LOCAL = $REMOTE_HEAD ]; then
    echo "Up-to-date"
elif [ $LOCAL = $BASE ]; then
    git pull --rebase $REMOTE $BRANCH
elif [ $REMOTE_HEAD = $BASE ]; then
    git push $REMOTE $BRANCH
else
    echo "Diverged"
fi
```

### 10.7 Xcode版本兼容性问题

#### 问题描述

```
The run destination iPhone 14 is not valid for Running the scheme 'LWKBCore-Example'
```

#### 解决方案

**步骤1: 检查可用的模拟器**

```bash
xcrun simctl list devices available
```

**步骤2: 使用可用的模拟器**

```bash
xcodebuild test \
  -workspace LWKBCore.xcworkspace \
  -scheme LWKBCore-Example \
  -destination 'platform=iOS Simulator,name=iPhone 13'
```

**步骤3: 创建所需的模拟器**

```bash
# 列出可用的设备类型
xcrun simctl list devicetypes

# 创建新模拟器
xcrun simctl create "iPhone 14" "com.apple.CoreSimulator.SimDeviceType.iPhone-14" "com.apple.CoreSimulator.SimRuntime.iOS-16-0"
```

### 10.8 资源文件未包含

#### 问题描述

运行时找不到bundle中的资源文件

#### 解决方案

**步骤1: 检查Podspec配置**

```ruby
# 方法1: resource_bundles（推荐）
s.resource_bundles = {
  'LWKBCore' => ['LWKBCore/Assets/**/*']
}

# 方法2: resources
s.resources = 'LWKBCore/Assets/**/*'
```

**步骤2: 在代码中正确加载资源**

```objc
// 使用resource_bundles
NSBundle *bundle = [NSBundle bundleForClass:[self class]];
NSURL *bundleURL = [bundle URLForResource:@"LWKBCore" withExtension:@"bundle"];
NSBundle *resourceBundle = [NSBundle bundleWithURL:bundleURL];
UIImage *image = [UIImage imageNamed:@"icon" inBundle:resourceBundle compatibleWithTraitCollection:nil];

// 使用resources
NSBundle *bundle = [NSBundle bundleForClass:[self class]];
UIImage *image = [UIImage imageNamed:@"icon" inBundle:bundle compatibleWithTraitCollection:nil];
```

---

## 11. 脚本工具索引

### 11.1 主工作流脚本

| 脚本名称 | 路径 | 用途 | 使用场景 |
|---------|------|------|----------|
| **wf_gitlablibs_publish.sh** | `/Users/luowei/bin/` | GitLab源码发布 | 发布源代码到GitLab私有Spec仓库 |
| **wf_giteelibs_publish.sh** | `/Users/luowei/bin/` | Gitee二进制发布 | 发布静态库到Gitee私有Spec仓库 |
| **wf_giteelibs_initpush.sh** | `/Users/luowei/bin/` | Gitee仓库初始化 | 首次创建Gitee库仓库 |
| **ck_giteelib_runstatus.sh** | `/Users/luowei/bin/` | 库状态检查与测试 | 校验库配置、运行Example测试 |
| **loopdo_tasks.sh** | `/Users/luowei/bin/` | 批量任务处理 | 批量执行Git操作、文件处理 |
| **git_push.sh** | `/Users/luowei/bin/` | 快速Git提交推送 | 简单的提交推送操作 |

### 11.2 核心模块脚本

| 脚本名称 | 路径 | 主要函数 | 用途 |
|---------|------|---------|------|
| **package_alib.sh** | `/Users/luowei/bin/moudle/` | `package_alib()`, `speclint_gitlab()`, `publish_specrepo()` | 静态库打包、Podspec校验、发布 |
| **git_update.sh** | `/Users/luowei/bin/moudle/` | `git_initpushup()`, `git_commitAndPush()` | Git初始化、智能提交推送 |
| **copy_topodtarget.sh** | `/Users/luowei/bin/moudle/` | `copy_topodtarget()` | 复制库文件到目标Pod项目 |
| **update_podspec.sh** | `/Users/luowei/bin/moudle/` | `update_podspec()` | 修改Podspec为二进制配置 |
| **copy_podspec.sh** | `/Users/luowei/bin/moudle/` | `copy_podspec()` | 复制Podspec文件 |
| **installrun_iosapp.sh** | `/Users/luowei/bin/moudle/` | `installrun_iosapp()` | 安装并运行应用到模拟器 |
| **build_iosapp.sh** | `/Users/luowei/bin/moudle/` | `build_iosapp()` | 构建iOS应用 |
| **excute_frame.sh** | `/Users/luowei/bin/moudle/` | 执行框架 | 批量操作框架 |
| **loop_pattern.sh** | `/Users/luowei/bin/moudle/` | `loop_pattern()` | 循环迭代模式 |
| **surround_cd.sh** | `/Users/luowei/bin/moudle/` | `surround_cd()` | 目录上下文切换 |

### 11.3 Python工具

| 脚本名称 | 路径 | 主要类/方法 | 用途 |
|---------|------|------------|------|
| **pod_manager.py** | `/Users/luowei/bin/py/modules/ios_pod/` | `PodManager` 类 | 完整的Pod管理和发布解决方案 |

**PodManager 主要方法**:
- `validate_podspec(podspec_path)` - Podspec校验
- `build_static_library(project_path, target_name)` - 构建通用静态库
- `package_pod_library(source_project_path, target_pod_path, library_name)` - 打包为标准Pod结构
- `publish_to_gitee(pod_path, gitee_repo_url, spec_repo)` - 完整Gitee发布流程
- `install_pod_dependencies(pod_path)` - 安装Pod依赖
- `check_pod_status(pod_path)` - 检查Pod状态
- `find_podspec_files(directory)` - 查找Podspec文件

### 11.4 实用工具脚本

| 脚本名称 | 路径 | 用途 |
|---------|------|------|
| **my_tools.sh** | `/Users/luowei/bin/` | 通用工具（截图、录屏、媒体处理、SQLite操作） |
| **batch_execute.sh** | `/Users/luowei/bin/` | 批量文件操作（解压、重命名、清理） |
| **create_shell_moudle.sh** | `/Users/luowei/bin/` | 创建Shell模块脚本模板 |

### 11.5 模块导入模式

所有主工作流脚本使用统一的模块导入模式：

```bash
# 导入函数定义
import() {
    source "$1" --import
}

# 导入所需模块
import "$(dirname $0)/moudle/package_alib.sh"
import "$(dirname $0)/moudle/git_update.sh"
import "$(dirname $0)/moudle/copy_topodtarget.sh"

# 使用导入的函数
package_alib "LWKBCore"
git_commitAndPush
copy_topodtarget
```

### 11.6 常用命令速查

#### CocoaPods命令

```bash
# 安装/更新依赖
pod install
pod update

# 校验Podspec
pod spec lint MyLib.podspec --allow-warnings

# 发布到Spec仓库
pod repo push mygitlabrepo MyLib.podspec --allow-warnings

# 打包静态库
pod package MyLib.podspec --force --library

# 缓存管理
pod cache clean --all
pod cache clean MyLib --all

# Spec仓库管理
pod repo add mygitlabrepo https://gitlab.com/.../mygitlabrepo.git
pod repo update mygitlabrepo
pod repo list
```

#### Xcodebuild命令

```bash
# 构建
xcodebuild build -workspace MyLib.xcworkspace -scheme MyLib-Example

# 测试
xcodebuild test -workspace MyLib.xcworkspace -scheme MyLib-Example -destination 'platform=iOS Simulator,name=iPhone 14'

# 清理
xcodebuild clean -workspace MyLib.xcworkspace -scheme MyLib-Example

# 查看构建设置
xcodebuild -showBuildSettings -workspace MyLib.xcworkspace -scheme MyLib-Example
```

#### iOS模拟器命令

```bash
# 列出所有模拟器
xcrun simctl list devices

# 启动模拟器
xcrun simctl boot <device-uuid>

# 安装应用
xcrun simctl install booted /path/to/MyApp.app

# 启动应用
xcrun simctl launch booted com.example.MyApp

# 卸载应用
xcrun simctl uninstall booted com.example.MyApp

# 截图
xcrun simctl io booted screenshot screenshot.png

# 录屏
xcrun simctl io booted recordVideo video.mp4
```

#### Git命令

```bash
# 创建并推送标签
git tag 1.0.0
git push origin 1.0.0

# 删除标签
git tag --delete 1.0.0
git push origin :1.0.0

# 多远程仓库管理
git remote add origin_github https://github.com/username/MyLib.git
git remote add origin_gitlab https://gitlab.com/username/MyLib.git
git push origin_github master
git push origin_gitlab master

# 智能同步
git pull --rebase origin master
git push origin master
```

---

## 12. 项目列表

当前workspace `/Users/luowei/projects/libs` 包含以下**33个iOS CocoaPods库**:

| # | 库名称 | 描述 | Podspec | Git | CI/CD | Carthage |
|---|--------|------|---------|-----|-------|----------|
| 1 | **LWAspectsHook** | AOP方法拦截库 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 2 | **LWAudioPlayer** | 音频播放器组件 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 3 | **LWColorPicker** | 颜色选择器 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 4 | **LWContactManager** | 通讯录管理 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 5 | **LWDrawboard** | 绘图板组件 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 6 | **LWDynamicFont** | 动态字体管理 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 7 | **LWEncryptor** | 加密工具库 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 8 | **LWFileDownload** | 文件下载管理 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 9 | **LWHeroOC** | 视图转场动画 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 10 | **LWHUD** | HUD提示组件 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 11 | **LWKBaseExtensions** | 基础扩展库 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 12 | **LWKBCommonLib** | 通用库 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 13 | **LWKBCommonUtils** | 通用工具库 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 14 | **LWKBCore** | 核心库 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 15 | **LWKBExtensions** | 扩展库 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 16 | **LWLogger** | 日志系统 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 17 | **LWPhotoPicker** | 图片选择器 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 18 | **LWPrettyText** | 富文本处理 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 19 | **LWProgressView** | 进度条组件 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 20 | **LWPurchase** | 应用内购买 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 21 | **LWPusher** | 推送通知管理 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 22 | **LWReachabilityManager** | 网络状态监测 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 23 | **LWSDWebImage** | 图片加载缓存 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 24 | **LWSnapshot** | 截图工具 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 25 | **LWSQLCipherDB** | 加密数据库 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 26 | **LWThemeManager** | 主题管理 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 27 | **LWWebContainer** | Web容器 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 28 | **LWWebLoader** | Web加载器 | ✓ | ✓ | GitHub Actions | ✗ |
| 29 | **LWWebSocket** | WebSocket客户端 | ✓ | ✓ | GitHub Actions | ✗ |
| 30 | **LWWebUI** | Web UI组件 | ✓ | ✓ | GitHub Actions, Travis | ✓ |
| 31 | **LWWordConverter** | 文字转换工具 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 32 | **LWWubiEngine** | 五笔输入引擎 | ✓ | ✓ | GitHub Actions, Travis | ✗ |
| 33 | **LWZipArchive** | 压缩解压工具 | ✓ | ✓ | GitHub Actions, Travis | ✗ |

### 统计信息

- **总库数量**: 33
- **所有库都有**: Podspec, Git仓库, README.md, GitHub Actions工作流
- **Travis CI**: 31个（LWWebLoader和LWWebSocket除外）
- **Carthage支持**: 10个
- **标准源码结构**: `{LibraryName}/Classes/`
- **Example项目**: 所有库都包含

### 库分类

#### 核心基础库 (5个)
- LWKBCore
- LWKBCommonLib
- LWKBCommonUtils
- LWKBaseExtensions
- LWKBExtensions

#### UI组件库 (9个)
- LWHUD
- LWColorPicker
- LWDrawboard
- LWProgressView
- LWPhotoPicker
- LWWebUI
- LWPrettyText
- LWSnapshot
- LWThemeManager

#### 网络与Web库 (5个)
- LWWebContainer
- LWWebLoader
- LWWebSocket
- LWFileDownload
- LWSDWebImage

#### 系统功能库 (8个)
- LWContactManager
- LWReachabilityManager
- LWPusher
- LWPurchase
- LWDynamicFont
- LWAspectsHook
- LWLogger
- LWHeroOC

#### 数据与安全库 (3个)
- LWEncryptor
- LWSQLCipherDB
- LWZipArchive

#### 输入法与转换库 (3个)
- LWWubiEngine
- LWWordConverter
- LWAudioPlayer

---

## 13. 最佳实践

### 13.1 版本发布流程

#### 标准发布清单

**步骤1: 代码准备**
- [ ] 完成所有功能开发和Bug修复
- [ ] 更新API文档和注释
- [ ] 运行所有单元测试确保通过
- [ ] 在Example项目中测试所有功能

**步骤2: 版本号管理**
- [ ] 根据语义化版本规范确定新版本号
- [ ] 更新Podspec中的 `s.version`
- [ ] 更新CHANGELOG.md（如果有）
- [ ] 更新README.md中的版本引用

**步骤3: 本地校验**
```bash
# 校验Podspec
pod spec lint LWKBCore.podspec --allow-warnings --verbose

# 构建静态库（如果是二进制发布）
/Users/luowei/bin/moudle/package_alib.sh
source /Users/luowei/bin/moudle/package_alib.sh
package_alib LWKBCore

# 测试Example项目
cd Example
pod install
xcodebuild test -workspace LWKBCore.xcworkspace -scheme LWKBCore-Example
```

**步骤4: 提交代码**
```bash
git add .
git commit -m "Release version 1.0.0"
```

**步骤5: 创建Git标签**
```bash
# 确保标签与Podspec版本一致
git tag 1.0.0
git push origin master
git push origin 1.0.0
```

**步骤6: 发布到Spec仓库**

GitLab源码发布：
```bash
/Users/luowei/bin/wf_gitlablibs_publish.sh -n LWKBCore -p /Users/luowei/projects/libs
```

Gitee二进制发布：
```bash
/Users/luowei/bin/wf_giteelibs_publish.sh -n LWKBCore -p /Users/luowei/projects/libs
```

**步骤7: 验证发布**
```bash
# 更新本地Spec仓库
pod repo update mygitlabrepo
pod repo update mygiteerepo

# 搜索库
pod search LWKBCore

# 在测试项目中安装
pod 'LWKBCore', '~> 1.0.0'
pod install
```

**步骤8: 更新文档和通知**
- [ ] 更新GitHub Releases页面
- [ ] 发布Release Notes
- [ ] 通知团队成员
- [ ] 更新相关文档

### 13.2 代码质量保证

#### API文档规范

**Objective-C注释**:

```objc
/**
 * @brief 简短描述方法功能
 *
 * @discussion 详细说明方法的使用场景、注意事项等
 *
 * @param paramName 参数说明
 * @return 返回值说明
 *
 * @warning 警告信息（如果有）
 * @see 相关方法引用
 *
 * @code
 * // 使用示例
 * LWKBCore *core = [[LWKBCore alloc] init];
 * [core performAction:YES];
 * @endcode
 */
- (void)performAction:(BOOL)paramName;
```

**Swift注释**:

```swift
/**
 简短描述方法功能

 详细说明方法的使用场景、注意事项等

 - Parameters:
   - paramName: 参数说明

 - Returns: 返回值说明

 - Warning: 警告信息（如果有）

 - SeeAlso: 相关方法引用

 # Example
 ```
 let core = LWKBCore()
 core.performAction(true)
 ```
 */
func performAction(_ paramName: Bool)
```

#### 单元测试规范

```objc
// LWKBCoreTests.m
#import <XCTest/XCTest.h>
#import <LWKBCore/LWKBCore.h>

@interface LWKBCoreTests : XCTestCase
@end

@implementation LWKBCoreTests

- (void)setUp {
    [super setUp];
    // 测试前准备
}

- (void)tearDown {
    // 测试后清理
    [super tearDown];
}

- (void)testExample {
    // Given
    LWKBCore *core = [[LWKBCore alloc] init];

    // When
    BOOL result = [core performAction:YES];

    // Then
    XCTAssertTrue(result, @"Action should succeed");
}

- (void)testPerformanceExample {
    [self measureBlock:^{
        // 性能测试代码
    }];
}

@end
```

#### 代码审查清单

**提交PR前检查**:
- [ ] 代码符合项目编码规范
- [ ] 所有新增API都有文档注释
- [ ] 添加了必要的单元测试
- [ ] 所有测试通过
- [ ] 没有编译警告
- [ ] 没有内存泄漏（使用Instruments检测）
- [ ] Example项目中添加了新功能演示
- [ ] 更新了CHANGELOG

### 13.3 向后兼容性

#### 废弃API处理

**Objective-C**:

```objc
// 标记废弃方法
- (void)oldMethod __attribute__((deprecated("Use newMethod instead")));

// iOS版本特定废弃
- (void)oldMethod API_DEPRECATED("Use newMethod instead", ios(8.0, 12.0));

// 带替代方法的废弃
- (void)oldMethod API_DEPRECATED_WITH_REPLACEMENT("newMethod", ios(8.0, API_TO_BE_DEPRECATED));
```

**Swift**:

```swift
@available(iOS, deprecated: 12.0, renamed: "newMethod")
func oldMethod() {
    // 实现
}
```

#### 版本迁移指南

在README.md或单独的MIGRATION.md中提供：

```markdown
# Migration Guide

## Upgrading from 1.x to 2.0

### Breaking Changes

#### 1. API名称变更

**Before (1.x)**:
```objc
[core oldMethod];
```

**After (2.0)**:
```objc
[core newMethod];
```

#### 2. 初始化方法变更

**Before (1.x)**:
```objc
LWKBCore *core = [[LWKBCore alloc] init];
```

**After (2.0)**:
```objc
LWKBCore *core = [LWKBCore sharedInstance];
```

### Deprecation Timeline

- **1.5.0**: oldMethod标记为废弃
- **2.0.0**: oldMethod移除
```

### 13.4 持续集成最佳实践

#### 提交前本地检查

创建 `pre-commit` Git钩子：

```bash
#!/bin/bash
# .git/hooks/pre-commit

echo "Running pre-commit checks..."

# 检查Podspec语法
if ! pod spec lint *.podspec --allow-warnings --quick; then
    echo "❌ Podspec validation failed"
    exit 1
fi

# 运行测试
cd Example
if ! xcodebuild test -workspace *.xcworkspace -scheme *-Example -destination 'platform=iOS Simulator,name=iPhone 14' -quiet; then
    echo "❌ Tests failed"
    exit 1
fi

echo "✅ All checks passed"
exit 0
```

使其可执行：
```bash
chmod +x .git/hooks/pre-commit
```

#### GitHub Actions优化

**缓存策略**:

```yaml
- name: Cache CocoaPods
  uses: actions/cache@v3
  with:
    path: |
      Example/Pods
      ~/.cocoapods
    key: ${{ runner.os }}-pods-${{ hashFiles('Example/Podfile.lock') }}
    restore-keys: |
      ${{ runner.os }}-pods-

- name: Cache Derived Data
  uses: actions/cache@v3
  with:
    path: ~/Library/Developer/Xcode/DerivedData
    key: ${{ runner.os }}-derived-data-${{ hashFiles('**/*.swift', '**/*.m', '**/*.h') }}
```

**并行测试**:

```yaml
strategy:
  fail-fast: false
  matrix:
    xcode: ['14.3.1', '15.0']
    destination:
      - 'platform=iOS Simulator,name=iPhone 14'
      - 'platform=iOS Simulator,name=iPhone 14 Pro Max'
```

### 13.5 文档维护

#### README.md结构

```markdown
# LWKBCore

[![CI Status](https://github.com/username/LWKBCore/workflows/CI/badge.svg)](https://github.com/username/LWKBCore/actions)
[![Version](https://img.shields.io/cocoapods/v/LWKBCore.svg)](https://cocoapods.org/pods/LWKBCore)
[![License](https://img.shields.io/cocoapods/l/LWKBCore.svg)](https://cocoapods.org/pods/LWKBCore)
[![Platform](https://img.shields.io/cocoapods/p/LWKBCore.svg)](https://cocoapods.org/pods/LWKBCore)

## 简介

一句话描述库的功能

## 功能特性

- 特性1
- 特性2
- 特性3

## 系统要求

- iOS 9.0+
- Xcode 12.0+
- Swift 5.0+ / Objective-C

## 安装

### CocoaPods

```ruby
pod 'LWKBCore', '~> 1.0.0'
```

### Carthage

```
github "username/LWKBCore" ~> 1.0.0
```

## 快速开始

```objc
#import <LWKBCore/LWKBCore.h>

LWKBCore *core = [[LWKBCore alloc] init];
[core performAction];
```

## 文档

[完整API文档](https://docs.example.com/LWKBCore)

## 示例项目

下载代码后运行 `pod install`，然后打开 `LWKBCore.xcworkspace`

## 作者

Your Name, email@example.com

## 许可协议

LWKBCore is available under the MIT license. See the LICENSE file for more info.
```

#### CHANGELOG.md

```markdown
# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- 待发布的新功能

## [1.0.0] - 2025-01-15

### Added
- 初始版本发布
- 核心功能实现
- Example项目

### Changed
- 无

### Deprecated
- 无

### Removed
- 无

### Fixed
- 无

### Security
- 无
```

### 13.6 依赖管理策略

#### Podspec依赖声明

```ruby
# 基础依赖
s.dependency 'AFNetworking', '~> 4.0'

# 可选子模块依赖
s.subspec 'Core' do |core|
  core.source_files = 'LWKBCore/Classes/Core/**/*'
end

s.subspec 'UI' do |ui|
  ui.source_files = 'LWKBCore/Classes/UI/**/*'
  ui.dependency 'LWKBCore/Core'
  ui.dependency 'Masonry', '~> 1.1'
end

# 开发依赖（仅在Example中）
# 在Podfile中声明，不在podspec中
```

#### 依赖版本策略

| 符号 | 含义 | 示例 | 说明 |
|------|------|------|------|
| `=` | 精确版本 | `= 1.0.0` | 仅1.0.0 |
| `>` | 大于 | `> 1.0` | 1.0.1, 2.0等 |
| `>=` | 大于等于 | `>= 1.0` | 1.0, 1.0.1, 2.0等 |
| `<` | 小于 | `< 2.0` | 1.x.x |
| `<=` | 小于等于 | `<= 2.0` | 1.x.x, 2.0 |
| `~>` | 兼容版本 | `~> 1.2.0` | >= 1.2.0 且 < 1.3.0 |

**推荐使用 `~>` 运算符**:
```ruby
s.dependency 'AFNetworking', '~> 4.0'  # 允许4.x，但不包括5.0
```

### 13.7 安全与隐私

#### 敏感信息处理

**不要在代码或Podspec中硬编码**:
- API密钥
- 访问令牌
- 密码
- 证书

**推荐做法**:

```objc
// 使用环境变量或配置文件
NSString *apiKey = [[NSProcessInfo processInfo] environment][@"API_KEY"];

// 或从安全存储读取
NSString *apiKey = [KeychainHelper retrieveApiKey];
```

**在Git中忽略敏感文件**:

```gitignore
# .gitignore
*.pem
*.p12
*.mobileprovision
Config.plist
Secrets.h
.env
```

---

## 附录

### A. 术语表

| 术语 | 解释 |
|------|------|
| **CocoaPods** | iOS/macOS依赖管理工具 |
| **Podspec** | Pod规范文件，描述库的元数据 |
| **Spec仓库** | 存储Podspec文件的Git仓库 |
| **静态库** | 编译后的二进制文件(.a) |
| **Framework** | 包含二进制、头文件和资源的包 |
| **XCFramework** | 支持多平台的新Framework格式 |
| **lipo** | 创建或拆分通用二进制文件的工具 |
| **xcpretty** | 格式化xcodebuild输出的工具 |
| **语义化版本** | MAJOR.MINOR.PATCH版本号规范 |

### B. 快速命令参考卡

```bash
# ========== CocoaPods ==========
pod install                                    # 安装依赖
pod update                                     # 更新依赖
pod spec lint --allow-warnings                 # 校验Podspec
pod repo push mygitlabrepo *.podspec           # 发布Podspec
pod cache clean --all                          # 清理缓存

# ========== 脚本工具 ==========
/Users/luowei/bin/wf_gitlablibs_publish.sh     # GitLab发布
/Users/luowei/bin/wf_giteelibs_publish.sh      # Gitee发布
/Users/luowei/bin/ck_giteelib_runstatus.sh     # 状态检查
/Users/luowei/bin/loopdo_tasks.sh              # 批量任务

# ========== Git ==========
git tag 1.0.0 && git push origin 1.0.0         # 创建并推送标签
git tag --delete 1.0.0                         # 删除本地标签
git push origin :1.0.0                         # 删除远程标签

# ========== Xcode ==========
xcodebuild test -workspace *.xcworkspace       # 运行测试
xcrun simctl list devices                      # 列出模拟器

# ========== Python工具 ==========
python /Users/luowei/bin/py/modules/ios_pod/pod_manager.py  # Pod管理器
```

### C. 相关资源

- **CocoaPods官方文档**: https://guides.cocoapods.org/
- **Semantic Versioning**: https://semver.org/
- **GitHub Actions文档**: https://docs.github.com/en/actions
- **Xcode Build Settings参考**: https://xcodebuildsettings.com/
- **iOS开发最佳实践**: https://github.com/futurice/ios-good-practices

---

**文档版本**: 1.0.0
**最后更新**: 2025年1月
**维护者**: luowei
**反馈**: 如有问题或建议，请提交Issue或PR
