#include <iostream>
using namespace std;

int main() {

        int S, h;
        cout << "Enter square and heigth of the piramid, separated with space ";
        cin >> S >> h;
        if(S > 100 || S <= 0 || h > 100 || h <= 0){
                cout << "S and h must be between 0 and 100";
        } else {
                float res = (float)S*(float)h/3;
                cout << "Volume of the pyramid " << res;
        }
        return 0;
}
