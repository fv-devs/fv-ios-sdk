Pod::Spec.new do |spec|

  spec.name         = "FullyVerifiedSDK"
  spec.version      = "0.9.1"
  spec.summary      = "Fully-Verified iOS SDK 0.9.1"

  spec.description  = <<-DESC
  Fully-Verified iOS SDK Version 0.9.1
                   DESC

  spec.homepage     = "https://github.com/fv-devs/fv-ios-sdk.git"

  spec.license      = "MIT"

  spec.author             = { "FV Devs" => "it@fully-verified.com" }
  spec.ios.deployment_target = "9.3"

  spec.source       = { :git => "https://github.com/fv-devs/fv-ios-sdk.git", :tag => "#{spec.version}" }


  spec.source_files  = 'src/*.{h,m}'
  spec.vendored_libraries = 'src/libFullyVerifiedSDK.a'
  spec.preserve_paths = 'src/libFullyVerifiedSDK.a'
  spec.libraries = 'FullyVerifiedSDK'
  spec.resource_bundles = {
    'FullyVerifiedSDK' => ['resources/**/*.png', 'resources/**/*.json', 'resources/**/*.storyboard', 'resources/**/*.strings', 'resources/**/*.caf']
  }

  spec.frameworks = 'UIKit'

  spec.requires_arc = true

  spec.dependency "JSONModel", "~> 1.7"
  spec.dependency "TwilioVideo", "~> 2.6.0"
  spec.dependency "FCAlertView", "~> 1.4"
  spec.dependency "HCSStarRatingView", "~> 1.5"
  spec.dependency "SAMKeychain", "~> 1.5.3"

end
