#include <iostream>
#include <cmath>
using namespace std;

int main () 
{
    float q1, p1, q2, p2;
    int a, cost = 0;
    cin >> q1 >> p1 >> q2 >> p2 >> a;
    if ((q1 / p1) > (q2 / p2)) 
    {
        while (a  > q1)
        {
            a -= q1;
            cost += p1;
        }
        if (p1 > (ceil(a / q2) * p2))
        {
            cost += ceil(a/ q2) * p2;
        }
        else 
        {
            cost += p1;
        }
    }
    else 
    {
        while (a  > q2)
        {
            a -= q2;
            cost += p2;
        }
        if (p2 > (ceil(a / q1) * p1))
        {
            cost += ceil(a/ q1) * p1;
        }
        else 
        {
            cost += p2;
        }
    }

    cout << cost;
}