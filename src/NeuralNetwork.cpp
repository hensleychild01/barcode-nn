#include "NeuralNetwork.h"
#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

namespace NeuralNetwork {
    Network::Network(const int inputs, const int hiddenLayerSize, const int hiddenLayerNum, const double learningRate) : inputNum(inputs), learningRate(learningRate) {
        for (int i = 0; i < hiddenLayerNum; i++) {
            const int inputsForThisLayer = i == 0 ? this->inputNum : hiddenLayerSize;
            const MatrixXd m = MatrixXd::Random(hiddenLayerSize, inputsForThisLayer + 1); // +1 for biases :)
            this->layers.push_back(m);
        }

        // the output layer is calculated exactly the same as the hiddens, so I'm gonna try just including it in that list
        // there will only be one output
        this->layers.emplace_back(MatrixXd::Random(1, hiddenLayerSize + 1));
    }

    double Network::forward(const LayerValues &input) const {
        assert(input.rows() == this->inputNum);
        // OKAY!
        // so for each layer, we need to append a 1 to the bottom of the ?x1 input vector
        LayerValues lastLayer = input;
        for (const MatrixXd& layer : this->layers) {
            LayerValues toForward(lastLayer.rows() + 1, 1);
            toForward << lastLayer, 1; // this should add in that pesky little 1 needed to add biases
            lastLayer = layer * toForward;
        }
        return lastLayer(0, 0);
    }

    double loss(const double yhat, const double y) {
        return pow((y-yhat), 2);
    }
}
