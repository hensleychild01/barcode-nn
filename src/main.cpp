#include "math/matrix.h"
#include <vector>
#include <ctime>
#include <iostream>
#include <stdint.h>
#include <string>

using namespace std;
using namespace Math;

int main()
{
    srand(time(0));

    vector<vector<double>> vec1 = {{2, 3}};
    vector<vector<double>> vec2 = {{4, 5}};

    Matrix m1(1, 2, vec1);
    Matrix m2(1, 2, vec2);
    print_matrix(m1.primary);
    print_matrix(m2.primary);

    cout << dot_product(m1.primary[0], m2.primary[0]) << "\n";

    return 0;
}