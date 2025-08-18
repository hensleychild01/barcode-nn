#ifndef NNUE_NEURALNETWORK_H
#define NNUE_NEURALNETWORK_H

#include <Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

namespace NeuralNetwork {
    typedef Matrix<double, Dynamic, 1> LayerValues;

    class Network {
    public:
        int inputNum;
        int outputNum;
        vector<MatrixXd> layers; // each matrix contains both weights and biases
        double learningRate;

        Network(int inputs, int outputs, int hiddenShape[2], double learningRate = 0.0001);
        LayerValues forward(const LayerValues &input) const;
    };
}

#endif //NNUE_NEURALNETWORK_H