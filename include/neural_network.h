#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>

//TODO: delete this later, temp implementation for testing purposes
// only shared header files go in include!!!

class NeuralNetwork {
public:
    NeuralNetwork();
    void train(const std::vector<double>& data);
    double predict(double input);
    std::string getWeights() const;
private:
    std::vector<double> weights_;
};

#endif 