import pyatium
import numpy as np


def test_neural_network():
    nn = pyatium.NeuralNetwork()
    data = [1.0, 2.0, 3.0, 4.0]
    print(nn)
    nn.train(data)
    result = nn.predict(5.0)
    print(f"Predicted result: {result}")
    nn.multiply(np.array([[0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1]]))


if __name__ == "__main__":
    test_neural_network()
