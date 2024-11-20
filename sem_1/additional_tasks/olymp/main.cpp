#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


// int main() {
//     int n, a, count1 = 0, count0 = 0;

//     cin >> n;
     
//     vector<int> arr;

//     for (int i = 0; i < n; i++) {
//         cin >> a;
//         if (a == 1) {
//             count1++;
//             arr.push_back(count0);
//             count0 = 0;
//         } else {
//             count0++;
//         }

//     }

//     if (count1 == 1) {
//         cout << 1;
//     } else {
//         int answ = 1;
//         for (int i = 1; i < arr.size(); i++)
//             answ *= arr[i] + 1; 
//         cout << answ;
//     }
//     return 0;
// }

int main() {
    int t, n, a, count1 = 0, count0 = 0;
    cin >> t;

    for (int j = 0; j < t; j++) {
        count1 = 0, count0 = 0;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a % 2 != i % 2) {
                if (a % 2 == 0)
                    count0++;
                else
                    count1++;
            }
        }
        if (count0 == count1) 
            cout << count0 << endl;
        else
            cout << -1 << endl;
        }
    return 0;
}