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

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "ngraph/function.hpp"     // ngraph::Function
#include "ngraph/op/parameter.hpp" // ngraph::op::Parameter
#include "pyngraph/function.hpp"

namespace py = pybind11;

void regclass_pyngraph_Function(py::module m)
{
    py::class_<ngraph::Function, std::shared_ptr<ngraph::Function>> function(m, "Function");
    function.doc() = "ngraph.impl.Function wraps ngraph::Function";
    function.def(py::init<const std::vector<std::shared_ptr<ngraph::Node>>&,
                          const std::vector<std::shared_ptr<ngraph::op::Parameter>>&,
                          const std::string&>());
    function.def(py::init<const std::shared_ptr<ngraph::Node>&,
                          const std::vector<std::shared_ptr<ngraph::op::Parameter>>&,
                          const std::string&>());
    function.def("get_output_size", &ngraph::Function::get_output_size);
    function.def("get_output_op", &ngraph::Function::get_output_op);
    function.def("get_output_element_type", &ngraph::Function::get_output_element_type);
    function.def("get_output_shape", &ngraph::Function::get_output_shape);
    function.def("get_parameters", &ngraph::Function::get_parameters);
    function.def("get_results", &ngraph::Function::get_results);
    function.def("get_result", &ngraph::Function::get_result);
    function.def("get_unique_name", &ngraph::Function::get_name);
    function.def("get_name", &ngraph::Function::get_friendly_name);
    function.def("set_friendly_name", &ngraph::Function::set_friendly_name);
    function.def("__repr__", [](const ngraph::Function& self) {
        std::string class_name = py::cast(self).get_type().attr("__name__").cast<std::string>();
        std::string shape =
            py::cast(self.get_output_shape(0)).attr("__str__")().cast<std::string>();
        return "<" + class_name + ": '" + self.get_friendly_name() + "' (" + shape + ")>";
    });
}
