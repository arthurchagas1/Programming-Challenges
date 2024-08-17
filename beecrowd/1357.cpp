#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, vector<string>> brailleMap = {
    {'1', {"*.", "..", ".."}},
    {'2', {"*.", "*.", ".."}},
    {'3', {"**", "..", ".."}},
    {'4', {"**", ".*", ".."}},
    {'5', {"*.", ".*", ".."}},
    {'6', {"**", "*.", ".."}},
    {'7', {"**", "**", ".."}},
    {'8', {"*.", "**", ".."}},
    {'9', {".*", "*.", ".."}},
    {'0', {".*", "**", ".."}}
};

map<vector<string>, char> digitMap;

void initializeDigitMap() {
    for (auto &pair : brailleMap) {
        digitMap[pair.second] = pair.first;
    }
}

int main() {
    initializeDigitMap();
    
    int D;
    while (cin >> D && D != 0) {
        char type;
        cin >> type;
        
        if (type == 'S') {
            string digits;
            cin >> digits;

            vector<string> line1, line2, line3;

            for (char digit : digits) {
                line1.push_back(brailleMap[digit][0]);
                line2.push_back(brailleMap[digit][1]);
                line3.push_back(brailleMap[digit][2]);
            }

            // Imprime as três linhas do Braille
            for (int i = 0; i < D; ++i) {
                if (i > 0) cout << " ";
                cout << line1[i];
            }
            cout << endl;
            for (int i = 0; i < D; ++i) {
                if (i > 0) cout << " ";
                cout << line2[i];
            }
            cout << endl;
            for (int i = 0; i < D; ++i) {
                if (i > 0) cout << " ";
                cout << line3[i];
            }
            cout << endl;
        } else if (type == 'B') {
            vector<string> line1(D), line2(D), line3(D);

            for (int i = 0; i < D; ++i) {
                cin >> line1[i];
            }
            for (int i = 0; i < D; ++i) {
                cin >> line2[i];
            }
            for (int i = 0; i < D; ++i) {
                cin >> line3[i];
            }

            for (int i = 0; i < D; ++i) {
                vector<string> brailleChar = {line1[i], line2[i], line3[i]};
                cout << digitMap[brailleChar];
            }
            cout << endl;
        }
    }
    
    return 0;
}
