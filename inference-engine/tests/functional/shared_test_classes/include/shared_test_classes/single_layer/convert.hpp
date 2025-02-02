// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <tuple>
#include <string>
#include <vector>
#include <memory>

#include "shared_test_classes/base/layer_test_utils.hpp"
#include "ngraph_functions/builders.hpp"
#include "ngraph_functions/utils/ngraph_helpers.hpp"

namespace LayerTestsDefinitions {

using ConvertParamsTuple = typename std::tuple<
        std::vector<std::vector<size_t>>,  // Input shapes
        InferenceEngine::Precision,        // Source precision
        InferenceEngine::Precision,        // Target precision
        InferenceEngine::Layout,           // Input layout
        InferenceEngine::Layout,           // Output layout
        std::string>;                      // Device name

class INFERENCE_ENGINE_DEPRECATED("This class is deprecated and will be removed soon. "
                                  "Please use new ConversionLayerTest class.") ConvertLayerTest :
        public testing::WithParamInterface<ConvertParamsTuple>,
        virtual public LayerTestsUtils::LayerTestsCommon {
public:
    static std::string getTestCaseName(const testing::TestParamInfo<ConvertParamsTuple> &obj);

protected:
    void SetUp() override;
};

}  // namespace LayerTestsDefinitions
