// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "ngraph/attribute_adapter.hpp"
#include "ngraph/dimension.hpp"
#include "ngraph/op/util/attr_types.hpp"
#include "ngraph/rank.hpp"
#include "ngraph/shape.hpp"
#include "openvino/core/shape.hpp"

namespace ngraph {
using PartialShape = ov::Shape;
}  // namespace ngraph
