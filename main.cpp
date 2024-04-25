// Main file for Cheating Hangman
// Authors: Alex Kuang, Mason Cormany

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <list>
#include <string.h>
#include <string>

using namespace std;

int main() {
    list <string> textList;
    string text;
    ifstream MyReadFile("words.txt");

    // Reading in file
    while(getline (MyReadFile, text)) {
        textList.push_front(text);
    }
    MyReadFile.close();

    for (auto w:textList) {
        cout << w << endl;
    }

    return 0;
}