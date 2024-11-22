#include "neural_network.h"
#include <iostream>

//TODO: delete this later, temp implementation for testing purposes

NeuralNetwork::NeuralNetwork() {
    weights_ = {0.5}; 
}

void NeuralNetwork::train(const std::vector<double>& data) {
    std::cout << "Training on data of size: " << data.size() << std::endl;
}

double NeuralNetwork::predict(double input) {
    double output = weights_[0] * input;
    std::cout << "Predicting for input: " << input << ", output: " << output << std::endl;
    return output;
}