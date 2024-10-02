#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);  
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int countVowelPairs(const string& word) {
    int count = 0;  
    for (size_t i = 0; i < word.length() - 1; i++) {
        if (isVowel(word[i]) && isVowel(word[i + 1])) {
            count++; 
        }
    }
    return count;
}
bool toLower (string a , string b) {
    if (a.length() != b.length()) {
        return false;
    }
    for (int i = 0; i < a.length(); i++) {
        if (tolower(a[i]) != tolower(b[i])) {
            return false;
        }
    }
    return true;
}

bool elemExist (vector<string> arr, string elem) {
    for (int i = 0; i < arr.size(); i++) {
        if (toLower(elem, arr[i])) {
            return true;
        }
    }
    return false;
}

bool compare (string a, string b) {
    return countVowelPairs(a) > countVowelPairs(b);
}
int main() {
    string line;
    vector<string> list;

    ifstream in("../1.txt");
    
    if (!in) {
        cout << "Cannot open file" << endl;
        return 1;
    }
    
    while (getline(in, line)) {
        string S = "";
        line += " ";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                if ((countVowelPairs(S) > 0) && !elemExist(list, S)) {
                    list.push_back(S);
                }
                S = "";
            } else {
                S += (line[i] == ',' || line[i] == '.') ?  "" : string(1, line[i]);
            }
        }
    }

    sort(list.begin(), list.end(), compare);

    string res = "";
    for (int i = 0; (i < list.size()) && (i < 2000); i++) {
        res += list[i] + ": " + to_string(countVowelPairs(list[i])) + "\n";
    }
    
    ofstream outFile("../output.txt");        
        
    if (outFile.is_open())
    {
        outFile << res;
    }
    outFile.close(); 
    return 0;
}