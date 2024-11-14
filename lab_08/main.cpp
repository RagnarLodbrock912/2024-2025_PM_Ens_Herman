#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

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

bool isVoiceless(char ch) {
    ch = tolower(ch);
    return (ch == 'p' || ch == 't' || ch == 'k' || 
            ch == 's' || ch == 'f' || ch == 'c' ||
            ch == 'h' || ch == 'x' || ch == 'q'); 
}

string duplicateVowels(string word) {
    int originalSize = word.size();
    int newSize = originalSize;

    for (int i = 0; i < originalSize; ++i) {
        if (isVowel(word[i])) {
            newSize++;
        }
    }

    word.resize(newSize);
    int j = newSize - 1;

    for (int i = originalSize - 1; i >= 0; --i) {
        word[j--] = word[i];
        if (isVowel(word[i])) {
            word[j--] = word[i];
        }
    }
    return word;
}
void addWord (string& longWords, string word) {
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] != '.' && word[i] != ',' && longWords.find(tolower(word[i])) == string::npos) {
            longWords += word[i];
        }
    }
}

int main() {
    string line;
    vector<string> list;
    int amount;
    cin >> amount;

    ifstream in("../input.txt");
    
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
                S += (ispunct(line[i]) != 0) ?  "" : string(1, line[i]);
            }
        }
    }

    sort(list.begin(), list.end(), compare);

    string res = "";
    for (int i = 0; (i < list.size()) && (i < amount); i++) {
        res += list[i] + ": " + to_string(countVowelPairs(list[i])) + "\n";
    }
    
    ofstream outFile("../output1.txt");        
        
    if (outFile.is_open())
    {
        outFile << res;
    }
    outFile.close(); 

    string line2;
    cout << "Enter the string\n";
    getline(cin, line2);

    string word = "";
    vector<string> output;
    line2 += " ";
    int countA = 0, countE = 0, countU = 0, countI = 0, countO = 0;

    for (int i = 0; i < line2.length(); i++) {
        if (line2[i] == ' ') {
                if ((countA >= 2)  || (countE >= 2) || (countI >= 2) || (countO >= 2) ||(countU >= 2)) {
                    output.clear();
                    word = "";
                    for (int i = 0; i < line2.length(); i++) {
                        if (line2[i] == ' ') {
                            output.push_back(word);
                            word = "";
                        } else {
                            word += isVoiceless(line2[i]) ? "" : string(1, line2[i]);
                        }

                    }
                    break;
                }
                if ((countA + countE + countI + countO + countU) >= 3) {
                    output.push_back(duplicateVowels(word));
                } else {
                    output.push_back(word);
                }
                countA = 0, countE = 0, countU = 0, countI = 0, countO = 0;
                word = "";
            } else {
                switch (line2[i]) {
                    case 'a': 
                        countA++;
                        break;
                    case 'e':
                        countE++;
                        break;
                    case 'u':
                        countU++;
                        break;
                    case 'i':
                        countI++;
                        break;
                    case 'o':
                        countO++;
                        break;
                    default:
                        break;
                }
                word += line2[i];
             }
    }
    
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << " ";
    }

    string line3;
    vector<string> text;
    string longWords = "";
    int maxLen = 0;

    ifstream inner("../input.txt");
    
    if (!inner) {
        cout << "Cannot open file" << endl;
        return 1;
    }
    
    while (getline(inner, line3)) {
        string wrd = "";
        line3 += " ";
        for (int i = 0; i < line3.length(); i++) {
            if (line3[i] == ' ') {
                if (maxLen < ((ispunct(line3[i]) != 0) ? wrd.length() - 1 : wrd.length())) {
                    longWords = "";
                    addWord(longWords, wrd);
                    maxLen = wrd.length();
                } else if (maxLen == ((ispunct(line3[i]) != 0) ? wrd.length() - 1 : wrd.length())) {
                    addWord(longWords, wrd);
                }
                text.push_back(wrd);
                wrd = "";
            } else {
                wrd += line3[i];
            }
        }
    }
    
    string x, answ = "";
    string find = "(";
    for (int i = 0; i < text.size(); ++i) {
        for (int j = 0; j < text[i].length(); ++j) {
            if (longWords.find(tolower(text[i][j])) == string::npos && text[i][j] != '.' && text[i][j] != ',') {
                find += tolower(text[i][j]);
            }
            if (find.length() != 1) {
                x = text[i];
                transform(x.begin(), x.end(), x.begin(),[](unsigned char c) {
                    return toupper(c);
                });
                text[i] = x;
            }
        }
        answ += text[i] + " ";
        answ += (find.length() != 1) ? (find+ ")" + " ") : "";
        find = "(";
    }


    ofstream outFile2("../output3.txt");        
        
    if (outFile2.is_open())
    {
        outFile2 << answ;
    }
    outFile2.close(); 
    return 0;
}