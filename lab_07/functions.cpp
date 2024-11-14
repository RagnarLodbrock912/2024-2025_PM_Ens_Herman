#include "functions.hpp"

using namespace std;

int sumNumbers (int n) {
    int S = 0;
    int a;
    while (n > 0) {
        a = n % 10;
        S += a;
        n /= 10;
    }
    return S;  
}

int sumArr (vector<int> arr) {
    int S = 0;
    for (int i = 0; i < arr.size(); i++) {
        S += arr[i];
    }
    return S;
}

bool compare (vector<int> arr1, vector<int> arr2) {
    return sumArr(arr1) < sumArr(arr2);
}


namespace DataProcessing {
    res readData(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        int max = INT_MIN;
        int min = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> matrix[j][i];
                max = (max > matrix[j][i]) ? max : matrix[j][i];
                min = (min < matrix[j][i]) ? min : matrix[j][i];
            }
        }
        return {max, min, matrix};
    }

    std::vector<std::vector<int>> processData(int max, int min, std::vector<std::vector<int>> matrix) {
        if ((max - min) <= 2) {
            sort(matrix.begin(), matrix.end(), compare);

        }
        return matrix;
    }

    int writeData(std::vector<std::vector<int>> matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[j][i] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
}