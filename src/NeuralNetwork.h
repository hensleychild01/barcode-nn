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
        vector<MatrixXd> layers; // each matrix contains both weights and biases
        double learningRate;

        Network(int inputs, const int hiddenShape[2], double learningRate = 0.0001);
        [[nodiscard]] double forward(const LayerValues &input) const;
    };

    [[nodiscard]] double loss(double yhat, double y); // since an nnue only has one input, that's what I'll support here
}

#endif //NNUE_NEURALNETWORK_H