#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<string> table(27);


void centered(string str, int timeNO){
    cout << '|';
    int space = ((timeNO * 10 - 2) - str.length()) / 2;
    if (str.length() % 2 != 0)
        cout << ' ';
    for (int i = 0; i < space; i++)
        cout << ' ';
    cout << setw(str.length() + space) << left << str;
    // for (int i = 0; i < space; i++)
        // cout << ' ';
    cout << '|';
}

void printCourse(){
    int timeNO = 4;
    cout << setw(3) << '+';
    for (int i = 0; i < 10 * timeNO - 2; i++)
        cout << '-';
    cout << '+' << endl;
    cout << setw(3) << '|';
    for (int i = 0; i < 10 * timeNO - 2; i++){

    }
}

void printTimeLine(){
    for(int h = 7; h <= 9; h++){
        cout << '0' << h << ":00     ";
        cout << '0' << h << ":30     ";
    }
    for (int h = 10; h <= 20; h++){
        cout << h << ":00     ";
        if(h == 20){
            cout << h << ":30";
            break;
        }
        cout << h << ":30     ";
    }
    cout << endl;
    for(int i = 0; i < 275; i++)
        cout << '_';
    cout << endl;
}

int getLastCourseInTable(){
    for (int dayPiece = table.size() - 1; dayPiece >= 0; dayPiece--){
        if (table[dayPiece] != "")
            return dayPiece;
    }
    return 0;
}

void printCourseBorder(){ // FIX THIS!
    cout << setw(2) << "";
    int dayPiece = 0;
    while (dayPiece < getLastCourseInTable()){
        int courseLength = 0;
        string prevDayPiece;
        if(table[dayPiece] != ""){
            prevDayPiece = table[dayPiece];
            while(table[dayPiece++] == prevDayPiece){
                courseLength++;
            }
            cout << setfill('-') << setw(10 * courseLength - 1) << left << '+' << right << '+';
        }
        else {
            cout << setfill(' ') << setw(10) << "";
            dayPiece++;
        }
    }
    // for (int dayPiece = 0; dayPiece <= getLastCourseInTable(); dayPiece++){
    //     if (table[dayPiece] != ""){
    //         if(table[dayPiece] != prevDayPiece)
    //             cout << setfill('-') << setw(10) << left << '+';
    //         else if(table[dayPiece + 1] != prevDayPiece)
    //             cout << setfill('-') << setw(10) << right << '+';
    //         else
    //             cout << setw(10) << setfill('-') << "";
    //     }
    //     else
    //         cout << setfill(' ') << setw(10) << "";
    //     prevDayPiece = table[dayPiece];
    // }
    cout << endl;
}

int main(){
    for(int i = 0; i <= 3; i++)
        table[i] = "logic (1)";
    table[7] = "KIR (3)";
    printTimeLine();
    printCourseBorder();
    // printCourse();
    // centered(table[1], 4);
    return 0;
}
