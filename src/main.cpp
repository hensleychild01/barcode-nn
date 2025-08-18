#include <iostream>
#include "NeuralNetwork.h"

using namespace NeuralNetwork;
using namespace std;

int main() {
    int hiddenShape[2] = {256, 2};
    const Network net(1, hiddenShape);

    LayerValues inputs(1, 1);
    inputs << 345;

    cout << inputs << "\n";
    double output = net.forward(inputs);
    cout << output << "\n";
    cout << loss(output, 1) << "\n";

    return 0;
}