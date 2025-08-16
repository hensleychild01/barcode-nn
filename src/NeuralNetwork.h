#ifndef NNUE_NEURALNETWORK_H
#define NNUE_NEURALNETWORK_H

#include <Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

namespace NeuralNetwork {
    class Network {
    public:
        Vector2<double> inputs;
        vector<Vector2<double>> hiddens;
        Vector2<double> outputs;
        double learningRate;

        Network(int inputs, int hiddenShape[2], int outputs, double learningRate);
    };
}

#endif //NNUE_NEURALNETWORK_H