// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <cstdio>
#include <numeric>
#include <vector>

#include "ngraph/attribute_adapter.hpp"
#include "ngraph/axis_set.hpp"
#include "ngraph/ngraph_visibility.hpp"
#include "ngraph/strides.hpp"
#include "openvino/core/static_shape.hpp"

namespace ngraph {
using Shape = ov::StaticShape;
using ov::is_scalar;
using ov::is_vector;
using ov::row_major_stride;
using ov::row_major_strides;
using ov::shape_size;
}  // namespace ngraph
