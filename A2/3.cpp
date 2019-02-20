#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> createBoard() {
    vector<vector<char>> board;
    vector<char> empty;
    int h,w;
    cin >> h >> w;
    string input;

    board.push_back(empty);
    for (int i = 0; i < w + 2; i++)
        board[0].push_back('-');

    for(int i = 1; i < h + 1; i++){
        board.push_back(empty);
        board[i].push_back('-');
        cin >> input;
        for (int j = 0; j < w ; j++)
            board[i].push_back(input[j]);
        board[i].push_back('-');
    }

    board.push_back(empty);
    for (int i = 0; i < w + 2; i++)
        board[board.size() - 1].push_back('-');
    return board;
}

bool checkWin(vector<vector<char>> board){
    int players_count = 0;
    for(int i = 1; i < board.size() - 1; i++){
        for(int j = 1; j < board[i].size() - 1; j++)
            if(board[i][j] == 'o')
                players_count++;
    }
    if(players_count == 1)
        return true;
    return false;
}

void makeMove(vector<vector<char>>& board, int direction, int i, int j){
    switch (direction){
        case 0:
            board[i][j] = '#';
            board[i][j + 1] = '#';
            board[i][j + 2] = 'o';
            break;
        case 1:
            board[i][j] = '#';
            board[i + 1][j] = '#';
            board[i + 2][j] = 'o';
        case 2:
            board[i][j] = '#';
            board[i][j - 1] = '#';
            board[i][j - 2] = 'o';
        case 3:
            board[i][j] = '#';
            board[i - 1][j] = '#';
            board[i - 2][j] = 'o';
        default:
            break;
    }
}

bool checkGame(vector<vector<char>> board){ // returns true when won, false when no move left
                                            // after for loops return false
                                            // we can use a vector for moves and copy it to temp and pass it on, if win print it all then return true. by ref?
    if (che)
    vector<vector<char>> temp = board;
    for(int i = 1; i < board.size() - 1; i++) {
        for(int j = 1; j < board[i].size() - 1; j++){
            if(board[i][j] == 'o'){
                if(board[i + 1][j] == 'o'){
                    if(board[i + 2][j] == '#'){
                        makeMove(temp, 1, i, j);
                        if(checkWin(temp)){
                            return true;
                        }
                    }
                }
            }
        }
    }
}

void print(vector<vector<char>> board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++)
            cout << board[i][j];
        cout << endl;
        }
}

int main(){
    vector<vector<char>> board;
    board = createBoard();
    print(board);
    return 0;
}
