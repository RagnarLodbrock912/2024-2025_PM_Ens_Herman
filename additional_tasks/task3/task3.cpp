#include <iostream>
#include <cmath>
using namespace std;

bool count0And1 (int a) 
{
    int count1 = 0;
    int count0 = 0;
    while (a > 0) 
    {
        int n = a % 10;
        count1 += (n == 1) ? 1 : 0;
        count0 += (n == 0) ? 1 : 0;
        a /= 10;
    }
    return ((count0 > 0) && (count1 == 0));
}

bool isPerfectSquare (int a)
{
    int root = round(sqrt(a));
    return (root * root == a);
}
int main () 
{
    int max;
    cout << "Enter amount of numbers ";
    cin >> max;
    int arr[2*max];
    for (int i = 0; i < max; ++i) {
        cin >> arr[i];
    }
    
    int ji = 0;
    for (int i = 0; i < max; ++i) {
        if (!count0And1(arr[i])) {
            arr[ji++] = arr[i];
        }
    }
    max = ji;
    

    for (int i = 0; i < max; ++i) {
        if (isPerfectSquare(arr[i])) {
            max++;
            for (int j = max - 1; j > i; --j) {
                arr[j] =  arr[j - 1];
            }
            i++;
        }
    }
    for (int i = 0; i < max; ++i) {
        cout << arr[i] << " ";
    }
}