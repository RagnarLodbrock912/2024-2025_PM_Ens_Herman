#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int sumOfDigits(int n) 
{
    int S = 0;
    while (n > 0)
    {
        S += n % 10;
        n /= 10;
    }
    return S;
}

int main () 
{
    int S = 0;
    map<int, int> list;

    for (int i = 0; i < 1000; ++i)
    {
        if (list.find(sumOfDigits(i)) == list.end())
        {
            list[sumOfDigits(i)] = 1;
        }
        else 
        {
            list[sumOfDigits(i)] += 1;
        }
    }
    for (int i = 0; i < 28; ++i)
    {
        S += list[i] * list[i];
    }
    cout << S;
}