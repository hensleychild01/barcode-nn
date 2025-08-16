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
        vector<MatrixXd> hiddens;
        VectorXd outputs;
        int outputNum;
        double learningRate;

        Network(int inputs, int hiddenShape[2], int outputs, double learningRate=0.0001);
    };
}

#endif //NNUE_NEURALNETWORK_H