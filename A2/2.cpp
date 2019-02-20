#include <iostream>
#include <vector>
#include <fstream>

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

vector<string> sh(string str, string word, int i, vector<string> vec){  // it is shit, doesnt work.
    if(i == str.length())
        return vec;
    word += str[i];
    if(checkWord(word)){
        vec.push_back(word);
        word = "";
    }
    return sh(str, word, i + 1, vec);
}

int main(){
    vector<string> a;
    sh("iwanticecream", "", 0, a);
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}
