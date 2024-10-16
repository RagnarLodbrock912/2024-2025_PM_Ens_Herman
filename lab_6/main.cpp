#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

bool prime (int n) {
    if (n < 2) {
        return false;  
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

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

int multNumbers (int n) {
    int S = 1;
    int a;
    while (n > 0) {
        a = n % 10;
        S *= a;
        n /= 10;
    }
    return S;
}

bool compare (int a, int b) {
    if (sumNumbers(b) == sumNumbers(a)) {
        if(multNumbers(b) == multNumbers(a)) {
            return b < a;
        }
        return multNumbers(b) < multNumbers(a);
    }
    return sumNumbers(b) < sumNumbers(a);
}

bool compare2 (int a, int b) {
    return a > b;
}

bool isPerfectCube(int num) {
    int root = round(cbrt(num));
    return (root * root * root == num);
}

void sortArr(vector<int>& arr, bool comparator(int a, int b)) {
    int count = 1;
    while (count != 0) {
        count = 0;
        for (int i = 0; i + 1 < arr.size(); ++i) {
            if(comparator(arr[i], arr[i + 1])) {
                int s = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = s;
                count++;
            }
        }
    }


}
int main() {
    int max;
    cout << "Enter amount of numbers ";
    cin >> max;
    vector<int> sequence1(max);
    int amountPrime = 0;

    for (int i = 0; i < max; i++) {
        cin >> sequence1[i];
        if (prime(sequence1[i])) {
            amountPrime++;
        }
    }

    if (amountPrime == 0) {
        sortArr(sequence1, compare2);
    }

    for (int i = 0; i < max; i++) {
        cout << sequence1[i] << " ";
    }
    
    int max2;
    cout << "\nEnter amount of numbers ";
    cin >> max2;
    vector<int> sequence2(max2);

    for (int i = 0; i < max2; i++) {
        cin >> sequence2[i];
    }

    sortArr(sequence2, compare);
    
    for (int i = 0; i < max2; i++) {
        cout << sequence2[i] << " ";
    }

    int n, m;
    cout << "\nEnter m and n ";
    cin >> m >> n;
    vector<vector<int>> matrix (m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    long long mMax = LLONG_MIN;
    int maxIndex = 0;
    for (int i = 0; i < m; i++) {
        int S = 1;
        for (int j = 0; j < n; j++) {
            S *= matrix[i][j];
        }
        maxIndex = (S > mMax) ? i : maxIndex;
        mMax = (S > mMax) ? S : mMax;
    }
    for (int j = 0; j < n; j++) {
        matrix[maxIndex][j] = mMax;
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    int max3;
    cout << "Enter amount of numbers ";
    cin >> max3;
    int arr[2*max3];
    for (int i = 0; i < max3; i++) {
        cin >> arr[i];
    }
    
    int ji = 0;
    for (int i = 0; i < max3; i++) {
        if (!prime(arr[i])) {
            arr[ji++] = arr[i];
        }
    }
    max3 = ji;
    

    for (int i = 0; i < max3; i++) {
        if (isPerfectCube(arr[i])) {
            max3++;
            for (int j = max3 - 1; j > i; j--) {
                arr[j] =  arr[j - 1];
            }
            i++;
        }
    }
    for (int i = 0; i < max3; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
