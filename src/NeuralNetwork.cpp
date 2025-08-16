#include "NeuralNetwork.h"
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

namespace NeuralNetwork {
    Network::Network(const int inputs, int hiddenShape[2], const int outputs, const double learningRate) :
    inputs(inputs), outputNum(outputs), learningRate(learningRate) {
        // hiddenShape depicts the hidden layers as they appear graphically, so
        // hiddenShape[0] is the number of nodes per layer (rows), and
        // hiddenShape[1] is the number of layers (columns)

        for (int i = 0; i < hiddenShape[1]; i++) {
            MatrixXd temp {MatrixXd::Random(hiddenShape[0], inputs)};
            this->hiddens.emplace_back(temp);
        }
    }
}