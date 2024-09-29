#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
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

int main() {
    int n;
    cout << "Enter n ";
    cin >> n;
    vector<vector<int>> matrix (n);
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[j].resize(n);
            cin >> matrix[j][i];
            max = (max > matrix[j][i]) ? max : matrix[j][i];
            min = (min < matrix[j][i]) ? min : matrix[j][i];
        }
    }

    if ((max - min) <= 2) {
        sort(matrix.begin(), matrix.end(), compare);

    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
