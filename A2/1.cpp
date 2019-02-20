#include <iostream>

using namespace std;

void queue(string str, char last, int i){
    if (i == str.length())
        return;
    if (str[i] != last)
        cout << str[i];
    queue(str, str[i], i + 1);
}

int main(){
    string input;
    while(cin >> input){
        queue(input, '0', 0);
        cout << endl;
    }
    return 0;
}
