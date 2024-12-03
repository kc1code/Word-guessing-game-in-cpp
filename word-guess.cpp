#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

void playGame() {
    // Predefined list of words
    vector<string> words = {"apple", "banana", "grapes", "orange", "mango", "peach", "cherry", "papaya"};

    // Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    // Select a random word from the list
    string wordToGuess = words[rand() % words.size()];
    string guessedWord(wordToGuess.length(), '_'); // Initialize the guessed word with underscores
    int lives = 6;                                 // Number of incorrect guesses allowed
    char guessedLetter;
    bool won = false;

    cout << "Welcome to the Word Guessing Game!\n";
    cout << "I have chosen a word. Can you guess it letter by letter?\n";
    cout << "You have " << lives << " lives. Good luck!\n";

    // Game loop
    while (lives > 0 && !won) {
        cout << "\nWord: " << guessedWord << "\n";
        cout << "Enter a letter: ";
        cin >> guessedLetter;

        // Check if the guessed letter is in the word
        bool correctGuess = false;
        for (size_t i = 0; i < wordToGuess.length(); i++) {
            if (wordToGuess[i] == guessedLetter && guessedWord[i] != guessedLetter) {
                guessedWord[i] = guessedLetter; // Reveal the letter in the guessed word
                correctGuess = true;
            }
        }

        if (correctGuess) {
            cout << "Good job! '" << guessedLetter << "' is in the word.\n";
        } else {
            lives--;
            cout << "Wrong guess! '" << guessedLetter << "' is not in the word.\n";
            cout << "You have " << lives << " lives left.\n";
        }

        // Check if the player has guessed the entire word
        if (guessedWord == wordToGuess) {
            won = true;
        }
    }

    // End of the game
    if (won) {
        cout << "\nCongratulations! You guessed the word: " << wordToGuess << "\n";
    } else {
        cout << "\nGame over! The word was: " << wordToGuess << "\n";
    }
}

int main() {
    char playAgain;

    do {
        playGame(); // Start the game
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing! Goodbye!\n";
    return 0;
}
