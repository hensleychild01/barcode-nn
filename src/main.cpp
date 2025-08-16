#include <iostream>
#include "NeuralNetwork.h"

using namespace NeuralNetwork;
using namespace std;

int main() {
    int hiddenShape[2] {4, 2};
    Network net(2, hiddenShape, 1);

    for (MatrixXd &hidden : net.hiddens) {
        cout << hidden << endl;
        cout << "---------\n";
    }

    return 0;
}