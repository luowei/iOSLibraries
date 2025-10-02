# iOS CocoaPods 库集合

[![Platform](https://img.shields.io/badge/platform-iOS-lightgrey.svg)](https://developer.apple.com/ios/)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![CocoaPods](https://img.shields.io/badge/CocoaPods-compatible-green.svg)](https://cocoapods.org)

**中文文档 | [English](README.md)**

包含34个高质量iOS库的综合集合，使用Objective-C构建，涵盖UI组件、网络通信、数据管理、安全加密、输入法等多个领域。

---

## 📋 目录

- [概述](#概述)
- [库列表](#库列表)
  - [核心与基础](#核心与基础)
  - [UI组件](#ui组件)
  - [网络与Web](#网络与web)
  - [系统与集成](#系统与集成)
  - [数据与安全](#数据与安全)
  - [输入法与转换器](#输入法与转换器)
- [安装](#安装)
- [系统要求](#系统要求)
- [仓库结构](#仓库结构)
- [开发](#开发)
- [文档](#文档)
- [贡献](#贡献)
- [许可协议](#许可协议)

---

## 概述

这个单一仓库包含34个iOS库，采用Git子模块方式组织。每个库都独立维护，拥有自己的仓库、podspec文件、示例项目和CI/CD流程。

### 核心特性

- **34个生产就绪的库**: 在实际应用中经过充分测试
- **CocoaPods支持**: 所有库都可通过CocoaPods安装
- **Carthage兼容**: 10个库支持Carthage构建
- **GitHub Actions CI/CD**: 自动化测试和验证
- **iOS 8.0+支持**: 广泛的iOS版本兼容性
- **完整示例**: 每个库都包含可运行的示例项目
- **持续维护**: 定期更新和Bug修复

### 统计数据

| 指标 | 数量 |
|------|------|
| 总库数 | 34 |
| GitHub仓库 | 27 |
| GitLab仓库 | 7 |
| Carthage支持 | 10 |
| 最低iOS版本 | 8.0+ |
| CI/CD流水线 | 34 (GitHub Actions) |

---

## 库列表

### 核心与基础

#### LWKBCore
**iOS键盘核心框架**
键盘应用的基础框架。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitLab](https://gitlab.com/ioslibraries1/lwkbcore.git)

#### LWKBCommonLib
**键盘通用库**
键盘开发的通用工具和组件。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitLab](https://gitlab.com/ioslibraries1/lwkbcommonlib.git)

#### LWKBCommonUtils
**键盘通用工具**
键盘应用的实用工具函数。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitLab](https://gitlab.com/ioslibraries1/lwkbcommonutils.git)

#### LWKBaseExtensions
**键盘基础扩展**
万能输入法的键盘基础扩展库。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWKBaseExtensions.git)

#### LWKBExtensions
**键盘扩展**
万能输入法键盘使用到的类的扩展。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWKBExtensions.git)

---

### UI组件

#### LWHUD
**HUD组件**
可自定义的平视显示组件，MBProgressHUD的山寨版。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWHUD.git)

#### LWColorPicker
**颜色选择器**
支持色相、饱和度、透明度选取的颜色选择器，支持圆形和矩形HSB颜色模式图。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWColorPicker.git)

#### LWDrawboard
**画板**
可自定义笔触大小和颜色的绘图板和涂鸦板。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWDrawboard.git)

#### LWProgressView
**饼状进度条**
饼状形进度指示器组件。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWProgressView.git)

#### LWPhotoPicker
**照片选择器**
支持保留宽高比与固定宽高比两种类型的照片选择器。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWPhotoPicker.git)

#### LWPrettyText
**富文本组件**
OC版富文本Category组件包，快速构造复杂的NSAttributedString。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitHub](https://github.com/luowei/LWPrettyText.git)

#### LWSnapshot
**截图工具**
可自定义选取截取范围的截图组件。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitHub](https://github.com/luowei/LWSnapshot.git)

#### LWThemeManager
**主题管理器**
万能输入法的主题管理组件。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWThemeManager.git)

#### LWHeroOC
**Hero动画框架**
用于创建类似Keynote神奇移动效果的动画框架。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWHeroOC.git)

---

### 网络与Web

#### LWWebContainer
**Web容器**
基于WKWebView的Web容器组件。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWWebContainer.git)

#### LWWebLoader
**Web加载器**
基于WKWebView的数据加载器。

- **版本**: 1.0.0
- **iOS**: 9.0+
- **仓库**: [GitHub](https://github.com/luowei/LWWebLoader.git)

#### LWWebSocket
**WebSocket服务器**
用于APP内轻量级的WebSocket数据传输服务器。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitHub](https://github.com/luowei/LWWebSocket.git)

#### LWWebUI
**Web UI组件**
基于Web的UI组件和工具。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWWebUI.git)

#### LWFileDownload
**文件下载管理器**
支持单文件与多文件下载的文件下载管理器。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWFileDownload.git)

#### LWSDWebImage
**图片加载与缓存**
图片加载和缓存库。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitLab](https://gitlab.com/ioslibraries1/lwsdwebimage.git)

---

### 系统与集成

#### LWContactManager
**通讯录管理**
系统通讯录管理库。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWContactManager.git)

#### LWReachabilityManager
**网络状态监测**
网络可达性监测组件，ReachabilityManager山寨版。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWReachabilityManager.git)

#### LWPusher
**推送通知管理**
推送通知管理组件。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitLab](https://gitlab.com/ioslibraries1/liblwpusher.git)

#### LWPurchase
**应用内购买**
App非消耗型内购组件，一行代码实现内购集成。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWPurchase.git)

#### LWDynamicFont
**动态字体加载器**
支持从服务器端动态下载和加载字体的字体加载器。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWDynamicFont.git)

#### LWAspectsHook
**AOP方法拦截**
面向切面编程的方法拦截库。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWAspectsHook.git)

#### LWLogger
**日志框架**
基于CocoaLumberjack封装的日志记录框架。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWLogger.git)

---

### 数据与安全

#### LWEncryptor
**加密框架**
加密解密框架，包含MD5、RSA和AES。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWEncryptor.git)

#### LWSQLCipherDB
**加密数据库**
封装于FMDB与SQLCipher的加密SQLite数据库组件。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitHub](https://github.com/luowei/LWSQLCipherDB.git)

#### LWZipArchive
**压缩解压工具**
压缩和解压缩实用工具。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitLab](https://gitlab.com/ioslibraries1/lwziparchive.git)

---

### 输入法与转换器

#### LWWubiEngine
**五笔输入引擎**
五笔输入法引擎。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitLab](https://gitlab.com/ioslibraries1/lwwubiengine.git)

#### LWWordEngine
**词语输入引擎**
词语处理和输入引擎。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitLab](https://gitlab.com/ioslibraries1/WordEngine.git)

#### LWWordConverter
**文字转换器**
文本转换实用工具。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **仓库**: [GitHub](https://github.com/luowei/LWWordConverter.git)

#### LWAudioPlayer
**双核心音频播放器**
包含前进、后退、循环等进度控制的双核心音频播放器，支持倍数播放。

- **版本**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **仓库**: [GitHub](https://github.com/luowei/LWAudioPlayer.git)

---

## 安装

### CocoaPods

所有库都可通过 [CocoaPods](https://cocoapods.org) 安装。在 `Podfile` 中添加所需的库：

```ruby
# 公共CocoaPods源
source 'https://github.com/CocoaPods/Specs.git'

# 私有Spec仓库（如需要）
source 'https://gitlab.com/ioslibraries1/mygitlabrepo.git'
source 'https://gitee.com/lw_ios_project/mylibrepo.git'

target 'YourApp' do
  # 示例：安装库
  pod 'LWKBCore', '~> 1.0.0'
  pod 'LWHUD', '~> 1.0.0'
  pod 'LWEncryptor', '~> 1.0.0'
end
```

然后运行：

```bash
pod install
```

### Carthage

10个库支持Carthage。在 `Cartfile` 中添加：

```
github "luowei/LWHUD" ~> 1.0.0
github "luowei/LWEncryptor" ~> 1.0.0
github "luowei/LWPhotoPicker" ~> 1.0.0
```

然后运行：

```bash
carthage update --use-xcframeworks
```

**支持Carthage的库：**
- LWAspectsHook
- LWAudioPlayer
- LWColorPicker
- LWContactManager
- LWDrawboard
- LWDynamicFont
- LWEncryptor
- LWFileDownload
- LWHeroOC
- LWHUD
- LWKBaseExtensions
- LWKBExtensions
- LWLogger
- LWPhotoPicker
- LWProgressView
- LWPurchase
- LWReachabilityManager
- LWThemeManager
- LWWebContainer
- LWWebUI

---

## 系统要求

- **iOS**: 8.0+（大部分库），9.0+（LWWebLoader）
- **Xcode**: 12.0+
- **Swift**: 不需要（所有库都是Objective-C）
- **CocoaPods**: 1.10.0+
- **Carthage**: 0.38.0+（可选，用于支持Carthage的库）

---

## 仓库结构

本仓库使用Git子模块管理所有库：

```
libs/
├── README.md                              # 英文文档
├── README_ZH.md                           # 本文件（中文文档）
├── iOS_CocoaPods_开发发布指南.md          # 开发与发布指南
├── .gitmodules                            # Git子模块配置
├── LWAspectsHook/                         # 子模块：AOP方法拦截
├── LWAudioPlayer/                         # 子模块：音频播放器
├── LWColorPicker/                         # 子模块：颜色选择器
├── LWContactManager/                      # 子模块：通讯录管理
├── LWDrawboard/                           # 子模块：画板
├── LWDynamicFont/                         # 子模块：动态字体加载器
├── LWEncryptor/                           # 子模块：加密框架
├── LWFileDownload/                        # 子模块：文件下载管理器
├── LWHeroOC/                              # 子模块：Hero动画
├── LWHUD/                                 # 子模块：HUD组件
├── LWKBaseExtensions/                     # 子模块：键盘基础扩展
├── LWKBCommonLib/                         # 子模块：键盘通用库
├── LWKBCommonUtils/                       # 子模块：键盘通用工具
├── LWKBCore/                              # 子模块：键盘核心框架
├── LWKBExtensions/                        # 子模块：键盘扩展
├── LWLogger/                              # 子模块：日志框架
├── LWPhotoPicker/                         # 子模块：照片选择器
├── LWPrettyText/                          # 子模块：富文本组件
├── LWProgressView/                        # 子模块：进度条
├── LWPurchase/                            # 子模块：应用内购买
├── LWPusher/                              # 子模块：推送通知管理
├── LWReachabilityManager/                 # 子模块：网络状态监测
├── LWSDWebImage/                          # 子模块：图片加载与缓存
├── LWSnapshot/                            # 子模块：截图工具
├── LWSQLCipherDB/                         # 子模块：加密数据库
├── LWThemeManager/                        # 子模块：主题管理器
├── LWWebContainer/                        # 子模块：Web容器
├── LWWebLoader/                           # 子模块：Web加载器
├── LWWebSocket/                           # 子模块：WebSocket服务器
├── LWWebUI/                               # 子模块：Web UI组件
├── LWWordConverter/                       # 子模块：文字转换器
├── LWWordEngine/                          # 子模块：词语输入引擎
├── LWWubiEngine/                          # 子模块：五笔输入引擎
└── LWZipArchive/                          # 子模块：压缩解压工具
```

### 使用子模块

```bash
# 克隆本仓库及所有子模块
git clone --recursive https://github.com/luowei/libs.git

# 如果已经克隆，初始化子模块
git submodule init
git submodule update --init --recursive

# 更新所有子模块到最新版本
git submodule update --remote

# 查看子模块状态
git submodule status
```

---

## 开发

### 环境准备

1. **安装Xcode**（推荐使用最新稳定版）
2. **安装CocoaPods**：
   ```bash
   sudo gem install cocoapods
   ```
3. **安装Carthage**（可选）：
   ```bash
   brew install carthage
   ```

### 构建库

每个库都包含一个Example项目用于开发和测试：

```bash
# 进入库目录
cd LWKBCore

# 安装依赖
cd Example
pod install

# 打开workspace
open LWKBCore.xcworkspace
```

### 运行测试

```bash
# 为库运行测试
cd LWKBCore/Example
xcodebuild test \
  -workspace LWKBCore.xcworkspace \
  -scheme LWKBCore-Example \
  -destination 'platform=iOS Simulator,name=iPhone 14'
```

### 验证Podspec

```bash
cd LWKBCore
pod lib lint LWKBCore.podspec --allow-warnings
```

### CI/CD

所有库都配置了GitHub Actions工作流（位于 `.github/workflows/ci.yml`）：

- **Podspec验证**：验证podspec语法
- **Example构建**：在多个Xcode版本上构建示例项目
- **Carthage构建**：验证Carthage兼容性（支持的库）

工作流自动运行于：
- 推送到 `main`/`master` 分支
- Pull Request
- 手动触发

---

## 文档

### 完整指南

- **[iOS CocoaPods 开发发布指南](iOS_CocoaPods_开发发布指南.md)**
  涵盖以下内容的完整指南：
  - 环境配置
  - 开发工作流
  - 构建与校验
  - 发布流程（GitLab源码发布 / Gitee二进制发布）
  - 批量操作
  - Python自动化工具
  - CI/CD最佳实践

### 脚本工具

位于 `/Users/luowei/bin/`：

#### 主工作流脚本
- `wf_gitlablibs_publish.sh` - 发布源码到GitLab
- `wf_giteelibs_publish.sh` - 发布二进制到Gitee
- `wf_giteelibs_initpush.sh` - 初始化Gitee仓库
- `ck_giteelib_runstatus.sh` - 检查库状态并运行测试
- `loopdo_tasks.sh` - 批量任务处理

#### 核心模块
- `moudle/package_alib.sh` - 构建静态库
- `moudle/git_update.sh` - Git操作
- `moudle/installrun_iosapp.sh` - 在模拟器上安装并运行

#### Python工具
- `py/modules/ios_pod/pod_manager.py` - 完整的Pod管理工具

详细使用方法请参考[开发指南](iOS_CocoaPods_开发发布指南.md)。

---

## 贡献

欢迎贡献！每个库都有自己的仓库。贡献步骤：

1. **Fork特定库的仓库**
2. **创建功能分支**：`git checkout -b feature/amazing-feature`
3. **进行修改**
4. **为新功能添加测试**
5. **确保所有测试通过**
6. **更新文档**
7. **提交修改**：`git commit -m 'Add amazing feature'`
8. **推送到分支**：`git push origin feature/amazing-feature`
9. **创建Pull Request**

### 贡献指南

- 遵循现有代码风格（Objective-C规范）
- 为新功能添加单元测试
- 如添加新功能请更新README
- 尽可能保持向后兼容
- 使用语义化版本进行发布

---

## 许可协议

每个库独立授权。大多数库使用MIT许可协议。请查看每个库仓库中的LICENSE文件了解具体条款。

---

## 作者

**luowei**
邮箱：luowei@wodedata.com

---

## 致谢

特别感谢所有这些库的贡献者和用户。您的反馈和贡献让这些项目变得更好。

---

## 联系与支持

- **问题反馈**：请在相应库的仓库中提交Issue
- **问题咨询**：在库仓库中开启讨论
- **邮箱**：luowei@wodedata.com

---

**用 ❤️ 为iOS开发者社区打造**
