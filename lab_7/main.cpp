#include "functions.hpp"

using namespace std;

int main() {
    int n;
    cout << "Enter n ";
    cin >> n;

    res result = DataProcessing::readData(n);
    vector<vector<int>> matrix = DataProcessing::processData(result.max, result.min, result.matrix);
    DataProcessing::writeData(matrix, n);

    return 0;
}
