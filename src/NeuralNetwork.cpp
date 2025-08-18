#include "NeuralNetwork.h"
#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

namespace NeuralNetwork {
    Network::Network(const int inputs, const int outputs, int hiddenShape[2], const double learningRate) : inputNum(inputs), outputNum(outputs), learningRate(learningRate) {
        const int hiddenLayerSize = hiddenShape[0];
        const int hiddenLayerNum = hiddenShape[1];

        for (int i = 0; i < hiddenLayerNum; i++) {
            const int inputsForThisLayer = i == 0 ? this->inputNum : hiddenLayerSize;
            const MatrixXd m = MatrixXd::Random(hiddenLayerSize, inputsForThisLayer + 1); // +1 for biases :)
            this->layers.push_back(m);
        }

        // the output layer is calculated exactly the same as the hiddens, so I'm gonna try just including it in that list
        this->layers.push_back(MatrixXd::Random(this->outputNum, hiddenLayerSize + 1));
    }

    LayerValues Network::forward(const LayerValues &input) const {
        assert(input.rows() == this->inputNum);
        // OKAY!
        // so for each layer, we need to append a 1 to the bottom of the ?x1 input vector
        LayerValues lastLayer = input;
        for (MatrixXd layer : this->layers) {
            LayerValues toForward;
            toForward.resize(lastLayer.rows() + 1, 1);
            toForward(toForward.rows() - 1, 0) = 1; // this should add in that pesky little 1 needed to add biases
            lastLayer = layer * toForward;
        }
        return lastLayer;
    }
}
