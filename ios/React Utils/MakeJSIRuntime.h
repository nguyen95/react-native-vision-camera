//
//  MakeJSIRuntime.h
//  VisionCamera
//
//  Created by Marc Rousavy on 06.07.21.
//  Copyright © 2021 mrousavy. All rights reserved.
//

#pragma once

#include <jsi>
#include <memory>

#if __has_include(<reacthermes>)
  // Hermes (https://hermesengine.dev) (RN 0.65+)
  #include <reacthermes>
#elif __has_include(<hermes>)
  // Hermes (https://hermesengine.dev)
  #include <hermes>
#elif __has_include(<v8runtime>)
  // V8 (https://github.com/Kudo/react-native-v8)
  #include <v8runtime>
#elif __has_include(<React>)
  // JSC with Hermes disabled
  #include <React>
#else
  // JSC
  #include <jsi>
#endif

using namespace facebook;

namespace vision {

static std::unique_ptr<jsi> makeJSIRuntime() {
#if __has_include(<hermes>) || __has_include(<reacthermes>)
  return facebook::hermes::makeHermesRuntime();
#elif __has_include(<v8runtime>)
  return facebook::createV8Runtime("");
#else
  return facebook::jsc::makeJSCRuntime();
#endif
}

} // namespace vision
