#include <iostream>
#include "NeuralNetwork.h"

using namespace NeuralNetwork;
using namespace std;

int main() {
    int hiddenShape[2] {4, 2};
    Network net(1, hiddenShape, 1);

    VectorXd inputs(1);
    inputs << 2;

    cout << net.forward(inputs) << "\n";

    return 0;
}