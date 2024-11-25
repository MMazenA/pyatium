#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>
#include <eigen/core>

//TODO: delete this later, temp implementation for testing purposes
// only shared header files go in include!!!

class NeuralNetwork {
public:
    NeuralNetwork();
    void train(const std::vector<double>& data);
    double predict(double input);
    std::string getWeights() const;
    void multiply(Eigen::Matrix4f& mat);
private:
    std::vector<double> weights_;
};

#endif 