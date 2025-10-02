# iOS CocoaPods Libraries Collection

[![Platform](https://img.shields.io/badge/platform-iOS-lightgrey.svg)](https://developer.apple.com/ios/)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![CocoaPods](https://img.shields.io/badge/CocoaPods-compatible-green.svg)](https://cocoapods.org)

**[中文文档](README_ZH.md) | English**

A comprehensive collection of 34 high-quality iOS libraries built with Objective-C, covering UI components, networking, data management, security, input methods, and more.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Libraries](#libraries)
  - [Core & Foundation](#core--foundation)
  - [UI Components](#ui-components)
  - [Networking & Web](#networking--web)
  - [System & Integration](#system--integration)
  - [Data & Security](#data--security)
  - [Input Methods & Converters](#input-methods--converters)
- [Installation](#installation)
- [Requirements](#requirements)
- [Repository Structure](#repository-structure)
- [Development](#development)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

This monorepo contains 34 iOS libraries organized as Git submodules. Each library is independently maintained with its own repository, podspec, example project, and CI/CD pipeline.

### Key Features

- **34 Production-Ready Libraries**: Battle-tested in real-world applications
- **CocoaPods Support**: All libraries are available via CocoaPods
- **Carthage Compatible**: 10 libraries support Carthage build
- **GitHub Actions CI/CD**: Automated testing and validation
- **iOS 8.0+ Support**: Wide compatibility across iOS versions
- **Comprehensive Examples**: Each library includes working example projects
- **Active Maintenance**: Regular updates and bug fixes

### Statistics

| Metric | Count |
|--------|-------|
| Total Libraries | 34 |
| GitHub Repositories | 27 |
| GitLab Repositories | 7 |
| Carthage Support | 10 |
| Minimum iOS Version | 8.0+ |
| CI/CD Pipelines | 34 (GitHub Actions) |

---

## Libraries

### Core & Foundation

#### LWKBCore
**iOS Keyboard Core Framework**
A foundational framework for keyboard applications.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitLab](https://gitlab.com/ioslibraries1/lwkbcore.git)

#### LWKBCommonLib
**Keyboard Common Library**
Common utilities and components for keyboard development.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitLab](https://gitlab.com/ioslibraries1/lwkbcommonlib.git)

#### LWKBCommonUtils
**Keyboard Common Utilities**
Utility functions for keyboard applications.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitLab](https://gitlab.com/ioslibraries1/lwkbcommonutils.git)

#### LWKBaseExtensions
**Keyboard Base Extensions**
Base extensions for universal input method keyboard.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWKBaseExtensions.git)

#### LWKBExtensions
**Keyboard Extensions**
Extensions for classes used in universal input method keyboard.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWKBExtensions.git)

---

### UI Components

#### LWHUD
**HUD Component**
A customizable heads-up display component inspired by MBProgressHUD.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWHUD.git)

#### LWColorPicker
**Color Picker**
A color picker supporting hue, saturation, transparency selection with circular and rectangular HSB color mode.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWColorPicker.git)

#### LWDrawboard
**Drawing Board**
A customizable drawing and doodling board with adjustable brush size and color.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWDrawboard.git)

#### LWProgressView
**Pie Progress View**
A pie-shaped progress indicator component.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWProgressView.git)

#### LWPhotoPicker
**Photo Picker**
A photo picker supporting both aspect ratio preservation and fixed aspect ratio selection.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWPhotoPicker.git)

#### LWPrettyText
**Rich Text Component**
An Objective-C category package for quickly constructing complex NSAttributedString.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitHub](https://github.com/luowei/LWPrettyText.git)

#### LWSnapshot
**Screenshot Tool**
A screenshot component with customizable capture area selection.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitHub](https://github.com/luowei/LWSnapshot.git)

#### LWThemeManager
**Theme Manager**
Theme management component for universal input method.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWThemeManager.git)

#### LWHeroOC
**Hero Animation Framework**
An animation framework for creating Keynote-style Magic Move effects.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWHeroOC.git)

---

### Networking & Web

#### LWWebContainer
**Web Container**
A WKWebView-based web container component.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWWebContainer.git)

#### LWWebLoader
**Web Loader**
A WKWebView-based data loader.

- **Version**: 1.0.0
- **iOS**: 9.0+
- **Repository**: [GitHub](https://github.com/luowei/LWWebLoader.git)

#### LWWebSocket
**WebSocket Server**
A lightweight WebSocket data transfer server for in-app communication.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitHub](https://github.com/luowei/LWWebSocket.git)

#### LWWebUI
**Web UI Components**
Web-based UI components and utilities.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWWebUI.git)

#### LWFileDownload
**File Download Manager**
A file download manager supporting single and multiple file downloads.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWFileDownload.git)

#### LWSDWebImage
**Image Loading & Caching**
Image loading and caching library.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitLab](https://gitlab.com/ioslibraries1/lwsdwebimage.git)

---

### System & Integration

#### LWContactManager
**Contact Manager**
System contacts management library.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWContactManager.git)

#### LWReachabilityManager
**Network Reachability**
Network status monitoring component.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWReachabilityManager.git)

#### LWPusher
**Push Notification Manager**
Push notification management component.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitLab](https://gitlab.com/ioslibraries1/liblwpusher.git)

#### LWPurchase
**In-App Purchase**
One-line integration for non-consumable in-app purchases.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWPurchase.git)

#### LWDynamicFont
**Dynamic Font Loader**
A font loader supporting dynamic font downloading from server.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWDynamicFont.git)

#### LWAspectsHook
**AOP Method Interception**
Aspect-oriented programming method interception library.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWAspectsHook.git)

#### LWLogger
**Logging Framework**
A logging framework based on CocoaLumberjack wrapper.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWLogger.git)

---

### Data & Security

#### LWEncryptor
**Encryption Framework**
An encryption/decryption framework including MD5, RSA, and AES.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWEncryptor.git)

#### LWSQLCipherDB
**Encrypted Database**
An encrypted SQLite database component built on FMDB and SQLCipher.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitHub](https://github.com/luowei/LWSQLCipherDB.git)

#### LWZipArchive
**Archive Utility**
Compression and decompression utility.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitLab](https://gitlab.com/ioslibraries1/lwziparchive.git)

---

### Input Methods & Converters

#### LWWubiEngine
**Wubi Input Engine**
Wubi (五笔) input method engine.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitLab](https://gitlab.com/ioslibraries1/lwwubiengine.git)

#### LWWordEngine
**Word Input Engine**
Word processing and input engine.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitLab](https://gitlab.com/ioslibraries1/WordEngine.git)

#### LWWordConverter
**Word Converter**
Text conversion utility.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Repository**: [GitHub](https://github.com/luowei/LWWordConverter.git)

#### LWAudioPlayer
**Dual-Core Audio Player**
A dual-core audio player with forward, backward, loop controls and variable playback speed.

- **Version**: 1.0.0
- **iOS**: 8.0+
- **Carthage**: ✓
- **Repository**: [GitHub](https://github.com/luowei/LWAudioPlayer.git)

---

## Installation

### CocoaPods

All libraries are available through [CocoaPods](https://cocoapods.org). To install any library, add it to your `Podfile`:

```ruby
# Public CocoaPods
source 'https://github.com/CocoaPods/Specs.git'

# Private spec repositories (if needed)
source 'https://gitlab.com/ioslibraries1/mygitlabrepo.git'
source 'https://gitee.com/lw_ios_project/mylibrepo.git'

target 'YourApp' do
  # Example: Install a library
  pod 'LWKBCore', '~> 1.0.0'
  pod 'LWHUD', '~> 1.0.0'
  pod 'LWEncryptor', '~> 1.0.0'
end
```

Then run:

```bash
pod install
```

### Carthage

10 libraries support Carthage. Add to your `Cartfile`:

```
github "luowei/LWHUD" ~> 1.0.0
github "luowei/LWEncryptor" ~> 1.0.0
github "luowei/LWPhotoPicker" ~> 1.0.0
```

Then run:

```bash
carthage update --use-xcframeworks
```

**Carthage-Compatible Libraries:**
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

## Requirements

- **iOS**: 8.0+ (most libraries), 9.0+ (LWWebLoader)
- **Xcode**: 12.0+
- **Swift**: Not required (all libraries are Objective-C)
- **CocoaPods**: 1.10.0+
- **Carthage**: 0.38.0+ (optional, for Carthage-compatible libraries)

---

## Repository Structure

This repository uses Git submodules to manage all libraries:

```
libs/
├── README.md                              # This file
├── README_ZH.md                           # Chinese documentation
├── iOS_CocoaPods_开发发布指南.md          # Development & publishing guide (Chinese)
├── .gitmodules                            # Git submodules configuration
├── LWAspectsHook/                         # Submodule: AOP method interception
├── LWAudioPlayer/                         # Submodule: Audio player
├── LWColorPicker/                         # Submodule: Color picker
├── LWContactManager/                      # Submodule: Contact manager
├── LWDrawboard/                           # Submodule: Drawing board
├── LWDynamicFont/                         # Submodule: Dynamic font loader
├── LWEncryptor/                           # Submodule: Encryption framework
├── LWFileDownload/                        # Submodule: File download manager
├── LWHeroOC/                              # Submodule: Hero animation
├── LWHUD/                                 # Submodule: HUD component
├── LWKBaseExtensions/                     # Submodule: Keyboard base extensions
├── LWKBCommonLib/                         # Submodule: Keyboard common library
├── LWKBCommonUtils/                       # Submodule: Keyboard common utilities
├── LWKBCore/                              # Submodule: Keyboard core framework
├── LWKBExtensions/                        # Submodule: Keyboard extensions
├── LWLogger/                              # Submodule: Logging framework
├── LWPhotoPicker/                         # Submodule: Photo picker
├── LWPrettyText/                          # Submodule: Rich text component
├── LWProgressView/                        # Submodule: Progress view
├── LWPurchase/                            # Submodule: In-app purchase
├── LWPusher/                              # Submodule: Push notification manager
├── LWReachabilityManager/                 # Submodule: Reachability manager
├── LWSDWebImage/                          # Submodule: Image loading & caching
├── LWSnapshot/                            # Submodule: Screenshot tool
├── LWSQLCipherDB/                         # Submodule: Encrypted database
├── LWThemeManager/                        # Submodule: Theme manager
├── LWWebContainer/                        # Submodule: Web container
├── LWWebLoader/                           # Submodule: Web loader
├── LWWebSocket/                           # Submodule: WebSocket server
├── LWWebUI/                               # Submodule: Web UI components
├── LWWordConverter/                       # Submodule: Word converter
├── LWWordEngine/                          # Submodule: Word input engine
├── LWWubiEngine/                          # Submodule: Wubi input engine
└── LWZipArchive/                          # Submodule: Archive utility
```

### Working with Submodules

```bash
# Clone this repository with all submodules
git clone --recursive https://github.com/luowei/libs.git

# If already cloned, initialize submodules
git submodule init
git submodule update --init --recursive

# Update all submodules to latest
git submodule update --remote

# Check submodule status
git submodule status
```

---

## Development

### Prerequisites

1. **Install Xcode** (latest stable version recommended)
2. **Install CocoaPods**:
   ```bash
   sudo gem install cocoapods
   ```
3. **Install Carthage** (optional):
   ```bash
   brew install carthage
   ```

### Building a Library

Each library contains an Example project for development and testing:

```bash
# Navigate to a library
cd LWKBCore

# Install dependencies
cd Example
pod install

# Open workspace
open LWKBCore.xcworkspace
```

### Running Tests

```bash
# Run tests for a library
cd LWKBCore/Example
xcodebuild test \
  -workspace LWKBCore.xcworkspace \
  -scheme LWKBCore-Example \
  -destination 'platform=iOS Simulator,name=iPhone 14'
```

### Validating Podspec

```bash
cd LWKBCore
pod lib lint LWKBCore.podspec --allow-warnings
```

### CI/CD

All libraries have GitHub Actions workflows at `.github/workflows/ci.yml`:

- **Podspec Validation**: Validates podspec syntax
- **Example Build**: Builds example project on multiple Xcode versions
- **Carthage Build**: Validates Carthage compatibility (for supported libraries)

Workflows run automatically on:
- Push to `main`/`master` branch
- Pull requests
- Manual trigger

---

## Documentation

### Comprehensive Guides

- **[iOS CocoaPods Development & Publishing Guide](iOS_CocoaPods_开发发布指南.md)** (Chinese)
  Complete guide covering:
  - Environment setup
  - Development workflow
  - Build & validation
  - Publishing process (GitLab source / Gitee binary)
  - Batch operations
  - Python automation tools
  - CI/CD best practices

### Script Tools

Located in `/Users/luowei/bin/`:

#### Main Workflow Scripts
- `wf_gitlablibs_publish.sh` - Publish source code to GitLab
- `wf_giteelibs_publish.sh` - Publish binary to Gitee
- `wf_giteelibs_initpush.sh` - Initialize Gitee repository
- `ck_giteelib_runstatus.sh` - Check library status & run tests
- `loopdo_tasks.sh` - Batch task processing

#### Core Modules
- `moudle/package_alib.sh` - Build static libraries
- `moudle/git_update.sh` - Git operations
- `moudle/installrun_iosapp.sh` - Install & run on simulator

#### Python Tools
- `py/modules/ios_pod/pod_manager.py` - Comprehensive Pod management

Refer to the [development guide](iOS_CocoaPods_开发发布指南.md) for detailed usage.

---

## Contributing

Contributions are welcome! Each library has its own repository. To contribute:

1. **Fork the specific library repository**
2. **Create a feature branch**: `git checkout -b feature/amazing-feature`
3. **Make your changes**
4. **Add tests** for new functionality
5. **Ensure all tests pass**
6. **Update documentation**
7. **Commit changes**: `git commit -m 'Add amazing feature'`
8. **Push to branch**: `git push origin feature/amazing-feature`
9. **Open a Pull Request**

### Contribution Guidelines

- Follow existing code style (Objective-C conventions)
- Add unit tests for new features
- Update README if adding new functionality
- Keep backward compatibility when possible
- Use semantic versioning for releases

---

## License

Each library is independently licensed. Most libraries use the MIT License. Please check the LICENSE file in each library's repository for specific terms.

---

## Author

**luowei**
Email: luowei@wodedata.com

---

## Acknowledgments

Special thanks to all contributors and users of these libraries. Your feedback and contributions make these projects better.

---

## Contact & Support

- **Issues**: Please report issues in the respective library repository
- **Questions**: Open a discussion in the library repository
- **Email**: luowei@wodedata.com

---

**Made with ❤️ for the iOS developer community**
