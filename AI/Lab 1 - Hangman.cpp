#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int main() {

    vector<string> words = {"nepalgunj", "pokhara", "kathmandu", "dharan", "chitwan"};
    string word = words[rand() % words.size()];
    cout<< "Guess the characters:" << endl;

    string guessed_word = "";

    int chances = 5;

    while (chances > 0) {
        int failed = 0;

        for (char c : word) {
            if (guessed_word.find(c) != string::npos) {
                cout << c;
            }
            else {
                cout << "_";
                failed++;
            }
        }

        if (failed == 0) {
            cout << endl;
            cout << "You Win." << endl;
            cout << "The word is: " << word << "." << endl;
            break;
        }

        cout << endl;
        string guess;
        cin >> guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
        guessed_word += guess;

        if (word.find(guess) == string::npos) {
            chances--;
            cout << "Wrong" << endl;
            cout << "You have " << chances << " more guesses." << endl;

            if (chances == 0) {
                cout << "You Lose." << endl;
            }
        }
    }

    return 0;
}
