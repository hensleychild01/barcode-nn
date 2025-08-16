#include "NeuralNetwork.h"
#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

namespace NeuralNetwork {
    Network::Network(const int inputs, int hiddenShape[2], const int outputs, const double learningRate) :
    inputs(inputs), outputNum(outputs), learningRate(learningRate) {
        // hiddenShape depicts the hidden layers as they appear graphically, so
        // hiddenShape[0] is the number of nodes per layer (rows), and
        // hiddenShape[1] is the number of layers (columns)

        // weights
        for (int i = 0; i < hiddenShape[1]; i++) {
            MatrixXd m = MatrixXd::Random(hiddenShape[0], i == 0 ? inputs : hiddenShape[0]);
            this->hiddenWeights.emplace_back(m);
        }

        // to simplify math later on, biases for each layer will be a 1-row vector
        // in other words, this will have inverse dimensions of the hidden layers ??
        this->hiddenBiases = MatrixXd::Zero(hiddenShape[1], hiddenShape[0]);

        this->outputWeights = MatrixXd::Zero(this->outputNum, hiddenShape[0]);
        this->outputBiases = VectorXd::Zero(this->outputNum);
    }

    VectorXd Network::forward(const VectorXd &input) {
        VectorXd lastLayer = input;
        for (int i = 0; i < this->hiddenWeights.size(); i++) {
            lastLayer *= this->hiddenWeights[i].transpose();
            lastLayer += this->hiddenBiases.row(i);
        }

        lastLayer *= this->outputWeights.transpose();
        lastLayer += this->outputBiases;

        return lastLayer;
    }
}
