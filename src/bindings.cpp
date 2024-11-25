#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>
#include "neural_network.h"

namespace py = pybind11;

PYBIND11_MODULE(_backend, m) {
    m.doc() = "pybind11 example module!";

    py::class_<NeuralNetwork>(m, "NeuralNetwork")
        .def(py::init<>())
        .def("train", &NeuralNetwork::train)
        .def("predict", &NeuralNetwork::predict)
        .def("getWeights", &NeuralNetwork::getWeights)
        .def("multiply", &NeuralNetwork::multiply)
        .def("__str__",
        [](const NeuralNetwork &a) {
            return "<NeuralNetwork C++ implementation '" + a.getWeights() + "'>";
        });
}