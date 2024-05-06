# Cheating_Hangman Design Document
## Authors: Alex Kuang, Mason Cormany

Creating a game of cheating hangman in C++. The goal of the game is the change the word to make the game difficult for the player.

Main Components

    HangMan Class: This class contains all the methods needed to play the Cheating Hangman game.
    main Function: This function sets up the game, reads a word list from a file, and executes the game loop where the player makes guesses.

Main Function

    Initializes a HangMan object.
    Opens a dictionary file and reads words into a list.
    Randomly selects a starting word.
    Initializes game state variables including lists for letters of the word, guessed letters, and a display version of the word using underscores.
    Enters a game loop where it:
        Takes player guesses and checks if they are repeats.
        Updates the word display if guesses are correct.
        Potentially changes the target word to a new one from the cheating list if advantageous.
        Checks for game win conditions.
        Breaks the loop and ends the game if the player successfully guesses the word.

Class Methods

    split(string str, list<char>& l): Converts a string into a list of its characters.
    ToStr(char c): Converts a character into a string.
    updateWord(string& playingWord, string& word, char guess): Updates the word being guessed by replacing underscores with the guessed character if correct. Outputs a message for a correct guess and returns a boolean indicating if the guess was correct.
    cheatingWords(list<string>& words, string& playingWord, set<char>& lettersGuessed): Generates a list of possible words that the game might switch to in order to continue challenging the player. This list excludes any words that cannot be formed given the letters already guessed and revealed.
    pickCheatWord(list<string>& cheatingWords): Selects a random word from the list of possible cheating words.

Improvements

    Use more efficient data structures to find cheating words.
    Think of a better algorithm to find cheating words.
        Current method is using for loops to iterate through every word in the list, which is very slow.








