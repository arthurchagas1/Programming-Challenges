#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Para ignorar a nova linha após o número de casos

    // Mapeamento da quantidade de LEDs para cada dígito
    int leds_per_digit[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    for (int i = 0; i < N; ++i) {
        string number;
        getline(cin, number);

        int total_leds = 0;
        for (char digit : number) {
            total_leds += leds_per_digit[digit - '0'];
        }

        cout << total_leds << " leds" << endl;
    }

    return 0;
}
