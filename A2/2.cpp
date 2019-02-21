#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

bool checkWord(string word){
    ifstream file;
    file.open("words.txt");
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

bool divideWords(string str, int from, vector<string>& sentence){  
	string word = "";
	int index = from;
	if (from == str.length())
		return true;
	while (index < str.length()){
		word += str[index++];
		if (checkWord(word)) {
			if (divideWords(str, index, sentence)) {
				sentence.insert(sentence.begin(), word);
				return true;
			}
		}
	}
	return false;
}

void findAswers(string input, int length, string sentence) {
	for (int i = 1; i <= length; i++) {
		string word = input.substr(0, i);
		if (checkWord(word)) {
			if (i == length) {
				sentence += word;
				cout << sentence << endl;
				return;
			}
			findAswers(input.substr(i, length - i), length - i, sentence + word + " ");
		}
	}
}

int main(){
	vector<string> sentence;
	string input;
	cin >> input;
	divideWords(input, 0, sentence);
    for(int i = 0; i < sentence.size(); i++)
        cout << sentence[i] << endl;
	findAswers(input, input.length(), "");
    return 0;
}
