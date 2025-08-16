#ifndef NNUE_NEURALNETWORK_H
#define NNUE_NEURALNETWORK_H

#include <Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

namespace NeuralNetwork {
    class Network {
    public:
        int inputs;
        vector<MatrixXd> hiddenWeights;
        MatrixXd hiddenBiases;
        MatrixXd outputWeights;
        VectorXd outputBiases;
        int outputNum;
        double learningRate;

        Network(int inputs, int hiddenShape[2], int outputs, double learningRate=0.0001);
        VectorXd forward(const VectorXd &input);
    };
}

#endif //NNUE_NEURALNETWORK_H