#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

struct res {
    int max;
    int min;
    std::vector<std::vector<int>> matrix;
};

namespace DataProcessing {
    res readData(int n);
    std::vector<std::vector<int>> processData(int max, int min, std::vector<std::vector<int>> matrix);
    int writeData(std::vector<std::vector<int>> matrix, int n);
}

#endif