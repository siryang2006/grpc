// Copyright 2022 The gRPC Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "src/core/lib/event_engine/default_event_engine_factory.h"

#include <grpc/event_engine/event_engine.h>
#include <grpc/support/port_platform.h>

#include <memory>

#if defined(GPR_WINDOWS)
#include "src/core/lib/event_engine/windows/windows_engine.h"

namespace grpc_event_engine::experimental {

std::shared_ptr<EventEngine> DefaultEventEngineFactory() {
  return std::make_shared<WindowsEventEngine>();
}

}  // namespace grpc_event_engine::experimental
#elif defined(GRPC_CFSTREAM)
#include "src/core/lib/event_engine/cf_engine/cf_engine.h"

namespace grpc_event_engine::experimental {

std::shared_ptr<EventEngine> DefaultEventEngineFactory() {
  return std::make_shared<CFEventEngine>();
}

}  // namespace grpc_event_engine::experimental
#else
#include "src/core/lib/event_engine/posix_engine/posix_engine.h"

namespace grpc_event_engine::experimental {

std::shared_ptr<EventEngine> DefaultEventEngineFactory() {
  return PosixEventEngine::MakePosixEventEngine();
}

}  // namespace grpc_event_engine::experimental

#endif
