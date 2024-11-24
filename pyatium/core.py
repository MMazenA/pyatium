from pyatium._backend import NeuralNetwork as _NeuralNetwork


class NeuralNetwork:
    def __init__(self):
        self._nn = _NeuralNetwork()

    def train(self, data):
        """
        Train the neural network with the provided data.
        :param data: List or numpy array of training data.
        """
        # Convert data to list if it's a numpy array
        if hasattr(data, "tolist"):
            data = data.tolist()
        self._nn.train(data)

    def predict(self, input_value):
        """
        Predict the output for a given input.
        :param input_value: Input value for prediction.
        :return: Predicted output.
        """
        return self._nn.predict(input_value)

    def __str__(self):
        return self._nn.__str__()
