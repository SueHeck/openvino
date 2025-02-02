// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <gmock/gmock.h>

#include <string>
#include <memory>
#include <vector>

#include "ie_icnn_network.hpp"

namespace InferenceEngine {

IE_SUPPRESS_DEPRECATED_START

class MockNotEmptyICNNNetwork final : public ICNNNetwork {
public:
    static constexpr const char* INPUT_BLOB_NAME = "first_input";
    const SizeVector INPUT_DIMENSIONS = { 1, 3, 299, 299 };
    static constexpr const char* OUTPUT_BLOB_NAME = "first_output";
    const SizeVector OUTPUT_DIMENSIONS = { 1, 3, 299, 299 };
    const std::string name = "test";
    const std::string& getName() const noexcept override {
        return name;
    }
    void getOutputsInfo(OutputsDataMap& out) const noexcept override;
    void getInputsInfo(InputsDataMap &inputs) const noexcept override;
    std::shared_ptr<ngraph::Function> getFunction() noexcept override {
        ngraph::ParameterVector parameters;
        parameters.push_back(std::make_shared<ngraph::op::v0::Parameter>(
            ov::element::f32, std::vector<ov::Dimension>{INPUT_DIMENSIONS.begin(), INPUT_DIMENSIONS.end()}));
        parameters.back()->set_friendly_name(INPUT_BLOB_NAME);
        ngraph::ResultVector results;
        results.push_back(std::make_shared<ngraph::op::v0::Result>(parameters.back()->output(0)));
        results.back()->set_friendly_name(OUTPUT_BLOB_NAME);
        return std::make_shared<ov::Function>(results, parameters, "empty_function");
    }
    std::shared_ptr<const ngraph::Function> getFunction() const noexcept override {
        ngraph::ParameterVector parameters;
        parameters.push_back(std::make_shared<ngraph::op::v0::Parameter>(
            ov::element::f32, std::vector<ov::Dimension>{INPUT_DIMENSIONS.begin(), INPUT_DIMENSIONS.end()}));
        parameters.back()->set_friendly_name(INPUT_BLOB_NAME);
        ngraph::ResultVector results;
        results.push_back(std::make_shared<ngraph::op::v0::Result>(parameters.back()->output(0)));
        results.back()->set_friendly_name(OUTPUT_BLOB_NAME);
        return std::make_shared<const ov::Function>(results, parameters, "empty_function");
    }
    MOCK_METHOD(InputInfo::Ptr, getInput, (const std::string &inputName), (const, noexcept));
    MOCK_METHOD(size_t, layerCount, (), (const, noexcept));
    MOCK_METHOD(StatusCode, addOutput, (const std::string &, size_t , ResponseDesc*), (noexcept));
    MOCK_METHOD(StatusCode, setBatchSize, (const size_t size, ResponseDesc*), (noexcept));
    MOCK_METHOD(size_t, getBatchSize, (), (const, noexcept));
    MOCK_METHOD(void, getInputShapes, (ICNNNetwork::InputShapes &), (const, noexcept));
    MOCK_METHOD(StatusCode, reshape, (const ICNNNetwork::InputShapes &, ResponseDesc *), (noexcept));
    MOCK_METHOD(StatusCode, serialize,
        (const std::string &, const std::string &, InferenceEngine::ResponseDesc*), (const, noexcept));
    MOCK_METHOD(StatusCode, serialize,
        (std::ostream &, std::ostream &, InferenceEngine::ResponseDesc*), (const, noexcept));
    MOCK_METHOD(StatusCode, serialize,
        (std::ostream &, Blob::Ptr &, InferenceEngine::ResponseDesc*), (const, noexcept));
};

IE_SUPPRESS_DEPRECATED_END

}  // namespace InferenceEngine
