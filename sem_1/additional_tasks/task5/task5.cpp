#include <iostream>
#include <cmath>

using namespace std;

float distance (float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

float square (float r) {
    return 3.14 * r * r;
}

int main () 
{
    float x1, y1,  x2, y2, r1, r2;
    cin >> x1 >> y1 >> x2 >> y2 >> r1 >> r2;

    if (r2 > r1) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }

    float d = distance(x1, y1, x2, y2);

    if (r1 + r2 <= d) {
        cout << square(r1) + square(r2) << endl;
    } else if (r1 - r2 >= d) {
        cout << square(r1) << endl;
    } else if (d < r1) {

        float O2B = r1 - d;
        float x = (r1 * r1 - r2 * r2 - d * d) / (2 * d);

        float CD = 2 * sqrt(r2 * r2 - x * x);

        float sinO1 = CD / (2 * r1);
        float sinO2 = CD / (2 * r2);

        float O1 = asin(sinO1);
        float O2 = asin(sinO2);

        float S1 = (O1 / 3.14) * square(r1) - ((d + x) * CD) / 2;
        float S2 = ((6.28 - O2 * 2) / 6.28) * square(r2) + (x * CD) / 2;

        cout << square(r1) + square(r2) - S1 - S2;      
    } else {
        float O2B = d - r1;
        float O1A = d - r2;
        float AB = d - O1A - O2B;

        float x = ((O2B + AB) * (O2B + AB) - O1A * O1A + r1 * r1 - r2 * r2) / (2 * (O1A + O2B + AB));

        float CD = 2 * sqrt(r1 * r1 - (O1A + x) * (O1A + x));

        float sinO1 = CD / (2 * r1);
        float sinO2 = CD / (2 * r2);

        float O1 = asin(sinO1);
        float O2 = asin(sinO2);

        float S1 = (O1 / 3.14) * square(r1) - ((x + O1A) * CD) / 2;
        float S2 = (O2 / 3.14) * square(r2) - ((O2B + AB - x) * CD) / 2;

        cout << square(r1) + square(r2) - S1 - S2;
    }
    return 0;
}