#include <vector>
#include <cstdlib>

using namespace std;

namespace Math
{
    class Matrix
    {
    public:
        int rows;
        int columns;

        vector<vector<double>> primary;
        vector<vector<double>> transposed;

        Matrix(int rows, int columns, vector<vector<double>> values);
    };

    void printMatrix(vector<vector<double>> array);

    double dotProduct(vector<double> vec1, vector<double> vec2);

    Matrix matMult(Matrix mat1, Matrix mat2);
}