#include <iostream>
#include "NeuralNetwork.h"

using namespace NeuralNetwork;
using namespace std;

int main() {
    int hiddenShape[2] = {256, 2};
    const Network net(1, 1, hiddenShape);

    LayerValues inputs(1, 1);
    inputs << 1;

    cout << inputs << "\n";
    cout << net.forward(inputs) << "\n";

    return 0;
}