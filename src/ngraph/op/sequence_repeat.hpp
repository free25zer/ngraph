//*****************************************************************************
// Copyright 2017-2019 Intel Corporation
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
//*****************************************************************************

#pragma once

#include "ngraph/node.hpp"
#include "ngraph/op/op.hpp"

namespace ngraph
{
    namespace op
    {
        class SequenceRepeat : public Op
        {
        public:
            static const std::string type_name;
            const std::string& description() const override { return type_name; }
            /// \brief Constructs an empty SequenceRepeat operation
            SequenceRepeat() = default;

            /// \brief Creates a repeating sequence of an op
            /// \param value The value to be repeated
            SequenceRepeat(const Output<Node>& value);

            void validate_and_infer_types() override;
            std::shared_ptr<Node> copy_with_new_args(const NodeVector& new_args) const override;
        };
    }
}