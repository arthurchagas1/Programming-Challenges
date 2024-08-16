#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int contarTiposDeJoias(const vector<string>& joias) {
    unordered_set<string> tiposDeJoias;
    for (const string& joia : joias) {
        tiposDeJoias.insert(joia);
    }
    return tiposDeJoias.size();
}

int main() {
    vector<string> joias;
    string joia;
    while (getline(cin, joia)) {
        if (joia.empty()) break;
        joias.push_back(joia);
    }
    cout << contarTiposDeJoias(joias) << endl;
    return 0;
}
