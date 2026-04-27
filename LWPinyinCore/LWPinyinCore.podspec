Pod::Spec.new do |s|
  s.name             = 'LWPinyinCore'
  s.version          = '0.1.0'
  s.summary          = 'Lightweight pinyin input core for MyInputMethod.'
  s.description      = <<-DESC
Lightweight C++17 pinyin input core with an Objective-C++ wrapper for the
MyInputMethod keyboard extension.
                       DESC

  s.homepage         = 'https://wodedata.com'
  s.license          = { :type => 'Proprietary', :text => 'Copyright wodedata.com. All rights reserved.' }
  s.author           = { 'luowei' => 'luowei@wodedata.com' }
  s.source           = { :path => '.' }

  s.ios.deployment_target = '9.0'
  s.source_files = [
    'Sources/include/**/*.{h,hpp}',
    'Sources/core/**/*.{h,hpp,cc,cpp}',
    'Sources/objc/**/*.{h,m,mm}',
  ]
  s.public_header_files = [
    'Sources/include/**/*.h',
    'Sources/objc/**/*.h',
  ]
  s.resources = [
    'Resources/**/*'
  ]
  s.frameworks = 'Foundation'
  s.libraries = 'c++'
  s.pod_target_xcconfig = {
    'CLANG_CXX_LANGUAGE_STANDARD' => 'c++17',
    'CLANG_CXX_LIBRARY' => 'libc++',
  }
  s.static_framework = true
end
