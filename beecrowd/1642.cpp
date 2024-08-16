#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int maxLengthWithMaxMChars(int m, const string& text) {
    unordered_map<char, int> freq;
    int left = 0, right = 0;
    int max_length = 0;

    while (right < text.length()) {
        freq[text[right]]++;

        while (freq.size() > m) {
            freq[text[left]]--;
            if (freq[text[left]] == 0) {
                freq.erase(text[left]);
            }
            left++;
        }

        max_length = max(max_length, right - left + 1);
        right++;
    }

    return max_length;
}

int main() {
    int m;
    while (true) {
        cin >> m;
        if (m == 0) {
            break;
        }

        string text;
        getline(cin >> ws, text); // Ignorar a quebra de linha após m e ler o texto

        int max_length = maxLengthWithMaxMChars(m, text);
        cout << max_length << endl;
    }

    return 0;
}
