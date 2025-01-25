#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPrime(int n, int i = 2) {
    if (n < 2) {
        return false;
    }
    if (i > ceil(sqrt(n)) || n == 2) {
        return true;
    }
    if (n % i == 0) {
        return false;
    }
    else {
        i++;
        return isPrime(n, i);
    }
}

int getI (string coord) {
    return stoi(coord.substr(0, coord.find(":")));
}

int getJ (string coord) {
    return stoi(coord.substr(coord.find(":") + 1, coord.length()));
}

vector<string> cellsToGo (string coord, int m, int n, vector<string> visit, vector<string> field) {
    vector<string> res;

    int i = getI(coord);
    int j = getJ(coord);

    if (i + 1 < m) {
        string S = "" + to_string(i + 1) + ":" + to_string(j);
        if (find(visit.begin(), visit.end(), S) == visit.end() && field[i + 1][j] != '#') {
            res.push_back(S);
        }

    }
    if (i - 1 >= 0) {
        string S = "" + to_string(i - 1) + ":" + to_string(j);
        if (find(visit.begin(), visit.end(), S) == visit.end() && field[i - 1][j] != '#') {
            res.push_back(S);
        }
    }
    if (j + 1 < n) {
        string S = "" + to_string(i) + ":" + to_string(j + 1);
        if (find(visit.begin(), visit.end(), S) == visit.end() && field[i][j + 1] != '#') {
            res.push_back(S);
        }
    }
    if (j - 1 >= 0) {
        string S = "" + to_string(i) + ":" + to_string(j -1);
        if (find(visit.begin(), visit.end(), S) == visit.end() && field[i][j - 1] != '#') {
            res.push_back(S);
        }
    }
    if (i + 1 < m && j + 1 < n) {
        string S = "" + to_string(i + 1) + ":" + to_string(j + 1);
        if (find(visit.begin(), visit.end(), S) == visit.end() && field[i + 1][j + 1] != '#') {
            res.push_back(S);
        }
    }
    if (i - 1 >= 0 && j - 1 >= 0) {
        string S = "" + to_string(i - 1) + ":" + to_string(j - 1);
        if (find(visit.begin(), visit.end(), S) == visit.end() && field[i - 1][j - 1] != '#') {
            res.push_back(S);
        }
    }
    if (i + 1 < m && j - 1 >= 0) {
        string S = "" + to_string(i + 1) + ":" + to_string(j - 1);
        if (find(visit.begin(), visit.end(), S) == visit.end() && field[i + 1][j - 1] != '#') {
            res.push_back(S);
        }
    }
    if (i - 1 >= 0 && j + 1 < n) {
        string S = "" + to_string(i - 1) + ":" + to_string(j + 1);
        if (find(visit.begin(), visit.end(), S) == visit.end() && field[i - 1][j + 1] != '#') {
            res.push_back(S);
        }
    }
    return res;
}




int main() {
    ifstream in("../input.txt");
    
    if (!in) {
        cout << "Cannot open file" << endl;
        return 1;
    }

    int m, n;
    in >> m >> n;

    vector<string> field;
    string line;

    while (getline(in, line)) {
        field.push_back(line);
    }

    field.erase(field.begin());

    vector<string> cells, res, visit;
    int count = 0, answ = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(field[i][j] == 'S') {
                string S = "" + to_string(i) + ":" + to_string(j);
                cells.push_back(S);
            }
        }
    }

    while (answ == 0) {
        for (int i = 0; cells.size() != 0; i++) {
            if (field[getI(cells[0])][getJ(cells[0])] == 'E') {
                cout << count;
                return 0;
            }

            if (find(visit.begin(), visit.end(), cells[0]) != visit.end()) {
                cells.erase(cells.begin());
                continue;
            }

            visit.push_back(cells[0]);

            vector<string> rres;
            rres =  cellsToGo(cells[0], m, n, visit, field);

            res.insert(res.end(), rres.begin(), rres.end());

            cells.erase(cells.begin());
        }
        if (res.size() == 0) {
            cout << -1;
            return 0;
        }
        cells = res;
        res.clear();
        count++;

    }
    return 0;
}