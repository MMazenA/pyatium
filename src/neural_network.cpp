#include "neural_network.h"
#include <sstream>
#include <string_view>
#include <iostream>

//TODO: delete this later, temp implementation for testing purposes

NeuralNetwork::NeuralNetwork() {
    weights_ = {0.5,0.3}; 
}

void NeuralNetwork::train(const std::vector<double>& data) {
    std::cout << "Training on data of size: " << data.size() << std::endl;
}

double NeuralNetwork::predict(double input) {
    double output = weights_[0] * input;
    std::cout << "Predicting for input: " << input << ", output: " << output << std::endl;
    return output;
}

std::string NeuralNetwork::getWeights() const {
    std::stringstream result;
    std::copy(weights_.begin(), weights_.end(), std::ostream_iterator<double>(result, ","));
    std::string str = result.str().c_str();
    return str.substr(0,str.length()-1);
}

void NeuralNetwork::multiply(Eigen::Matrix4f& mat){
    std::cout << mat << std::endl;
}