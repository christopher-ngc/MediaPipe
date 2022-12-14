/* Copyright 2022 The MediaPipe Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef MEDIAPIPE_TASKS_CC_COMPONENTS_PROCESSORS_CLASSIFICATION_POSTPROCESSING_GRAPH_H_
#define MEDIAPIPE_TASKS_CC_COMPONENTS_PROCESSORS_CLASSIFICATION_POSTPROCESSING_GRAPH_H_

#include "absl/status/status.h"
#include "mediapipe/tasks/cc/components/processors/proto/classification_postprocessing_graph_options.pb.h"
#include "mediapipe/tasks/cc/components/processors/proto/classifier_options.pb.h"
#include "mediapipe/tasks/cc/core/model_resources.h"

namespace mediapipe {
namespace tasks {
namespace components {
namespace processors {

// Configures a ClassificationPostprocessingGraph using the provided model
// resources and ClassifierOptions.
// - Accepts CPU input tensors.
//
// Example usage:
//
//   auto& postprocessing =
//       graph.AddNode("mediapipe.tasks.components.processors.ClassificationPostprocessingGraph");
//   MP_RETURN_IF_ERROR(ConfigureClassificationPostprocessingGraph(
//       model_resources,
//       classifier_options,
//       &preprocessing.GetOptions<ClassificationPostprocessingGraphOptions>()));
//
// The resulting ClassificationPostprocessingGraph has the following I/O:
// Inputs:
//   TENSORS - std::vector<Tensor>
//     The output tensors of an InferenceCalculator.
//   TIMESTAMPS - std::vector<Timestamp> @Optional
//     The collection of timestamps that a single ClassificationResult should
//     aggregate. This is mostly useful for classifiers working on time series,
//     e.g. audio or video classification.
// Outputs:
//   CLASSIFICATION_RESULT - ClassificationResult
//     The output aggregated classification results.
absl::Status ConfigureClassificationPostprocessingGraph(
    const tasks::core::ModelResources& model_resources,
    const proto::ClassifierOptions& classifier_options,
    proto::ClassificationPostprocessingGraphOptions* options);

}  // namespace processors
}  // namespace components
}  // namespace tasks
}  // namespace mediapipe

#endif  // MEDIAPIPE_TASKS_CC_COMPONENTS_PROCESSORS_CLASSIFICATION_POSTPROCESSING_GRAPH_H_
