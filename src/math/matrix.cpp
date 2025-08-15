#include "matrix.h"
#include <cstdlib>
#include <vector>
#include <limits>
#include <iostream>
#include <ctime>
#include <stdint.h>
#include <string>

using namespace std;

namespace Math
{
    Matrix::Matrix(int rows, int columns, vector<vector<double>> values)
    {
        if (values.size() == 0 || values[0].size() == 0)
        {
            int upperLimit{numeric_limits<int>::max()};

            for (int i = 0; i < rows; i++)
            {
                primary.push_back({});
                for (int j = 0; j < columns; j++)
                {
                    transposed.push_back({});
                    double cell{rand() % upperLimit};
                    primary[i].push_back(cell);
                    transposed[j].push_back(cell);
                }
            }
        }
        else
        {
            primary = values; 
            for (int i = 0; i < columns; i++)
            {
                transposed.push_back({});
                for (int j = 0; j < rows; j++) {
                    transposed[i].push_back(primary[j][i]);
                }
            }
        }
    }

    void printMatrix(vector<vector<double>> array)
    {
        string s{""};
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = 0; j < array[0].size(); j++)
            {
                s += to_string(array[i][j]) + " ";
            }
            s += "\n";
        }
        cout << s << "\n";
    }

    double dotProduct(vector<double> vec1, vector<double> vec2)
    {
        double sum{0};
        for (int i = 0; i < vec1.size(); i++)
        {
            sum += vec1[i] * vec2[i];
        }
        return sum;
    }

    Matrix matMult(Matrix mat1, Matrix mat2)
    {
        // todo: matrix multiplication
        return; 
    }
}