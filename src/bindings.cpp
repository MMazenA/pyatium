#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "neural_network.h"

namespace py = pybind11;

PYBIND11_MODULE(_backend, m) {
    m.doc() = "pybind11 example module!";

    py::class_<NeuralNetwork>(m, "NeuralNetwork")
        .def(py::init<>())
        .def("train", &NeuralNetwork::train)
        .def("predict", &NeuralNetwork::predict);
}