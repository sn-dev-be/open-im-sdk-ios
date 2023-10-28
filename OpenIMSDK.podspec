#
# Be sure to run `pod lib lint OpenIMSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'OpenIMSDK'
  s.version          = '3.3.0'
  s.summary          = 'Open-IM-SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  An OpenIM SDK in Objective-C for iOS
                       DESC

  s.homepage         = 'https://github.com/OpenIMSDK/Open-IM-SDK-iOS'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'OpenIM' => 'https://github.com/OpenIMSDK/Open-IM-SDK-iOS' }
  s.source           = { :git => 'git@github.com:sn-dev-be/open-im-sdk-ios.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'    
  
  s.source_files = 'OpenIMSDK/OpenIMSDK.{h,m}'


  s.subspec 'Utils' do |ss|
    ss.source_files = 'OpenIMSDK/Utils/*.{h,m}'
  end

  s.subspec 'XCFrameworkPod' do |xcframework|
    xcframework.vendored_frameworks = 'OpenIMSDK/OpenIMCore.xcframework'
  end
  
  s.subspec 'MJExtension' do |ss|
#    ss.dependency 'OpenIMSDK/Utils'

    ss.source_files = 'OpenIMSDK/MJExtension/*.{h,m}'
    
  end
  
  

  s.subspec 'CallbackProxy' do |ss|
    ss.dependency 'OpenIMSDK/Utils'

    ss.source_files = 'OpenIMSDK/CallbackProxy/*.{h,m}'
  end

  s.subspec 'Model' do |ss|
    ss.dependency 'OpenIMSDK/Utils'

    ss.source_files = 'OpenIMSDK/Model/*.{h,m}'
  end

  s.subspec 'Interface' do |ss|
    ss.dependency 'OpenIMSDK/Model'
    ss.dependency 'OpenIMSDK/CallbackProxy'
    ss.dependency 'OpenIMSDK/Callbacker'
    ss.dependency 'OpenIMSDK/MJExtension'

    ss.source_files = 'OpenIMSDK/Interface/*.{h,m}'
  end

  s.subspec 'Callbacker' do |ss|
    ss.dependency 'OpenIMSDK/Model'
    ss.dependency 'OpenIMSDK/Utils'
    ss.dependency 'OpenIMSDK/MJExtension'
    
    ss.source_files = 'OpenIMSDK/Callbacker/*.{h,m}'
  end

  valid_archs = ['armv7s','arm64','x86_64']
  s.xcconfig = {
    'VALID_ARCHS' =>  valid_archs.join(' '),
  }

  s.pod_target_xcconfig = {
      'ARCHS[sdk=iphonesimulator*]' => '$(ARCHS_STANDARD_64_BIT)', 'DEFINES_MODULE' => 'YES'
  }

  s.frameworks = 'SystemConfiguration'
  
  s.static_framework = true

  #s.dependency 'OpenIMSDKCore', :git => 'https://github.com/sn-dev-be/openim-sdk-core-ios.git'
  #s.dependency 'OpenIMSDKCore', '3.3.0'
  #s.dependency 'MJExtension'
end
