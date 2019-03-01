#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#define DICTIONARY "words.txt"

using namespace std;

bool checkWord(string word){
    ifstream file;
    file.open(DICTIONARY);
    string line;
    while(getline(file, line)){
        if(word == line){
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void findAnswers(string input, int length, string sentence) {
	for (int i = 1; i <= length; i++) {
		string word = input.substr(0, i);
		if (checkWord(word)) {
			if (i == length) {
				sentence += word;
				cout << sentence << endl;
				return;
			}
			findAnswers(input.substr(i, length - i), length - i, sentence + word + " ");
		}
	}
}

int main(){
	string input;
	while(cin >> input){
	       findAnswers(input, input.length(), "");
           cout << "***" << endl;
    }
    return 0;
}
