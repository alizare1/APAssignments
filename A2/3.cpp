#include <iostream>
#include <vector>


#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

#define EMPTY '#'
#define PLAYER 'o'
#define BLOCK '-'

using namespace std;

vector<vector<char>> createBoard();
bool checkWin(const vector<vector<char>>& board);
void makeMove(vector<vector<char>>& board, int direction, int row_num, int col_num);
bool checkMove(const vector<vector<char>>& board, int direction, int row_num, int col_num);
void storeMoves(int direction, int row_num, int col_num, vector<string>& moves);
void printBoard(vector<vector<char>> board);
bool checkGame(vector<vector<char>> board, vector<string>& moves);
void solve(const vector<vector<char>>& board);
void printMoves(const vector<string>& moves);

int main(){
    vector<vector<char>> board;
    board = createBoard();
	solve(board);
    return 0;
}

void solve(const vector<vector<char>>& board) {
	vector<string> moves;
	if (!checkGame(board, moves)) {
		cout << "Bad map configuration!" << endl;
		return;
	}
	printMoves(moves);
}

bool checkGame(vector<vector<char>> board, vector<string>& moves) {
	if (checkWin(board)) {
		cout << "Insane!" << endl;
		return true;
	}

	vector<vector<char>> temp = board;
	for (int row_num = 1; row_num < board.size() - 1; row_num++) {
		for (int col_num = 1; col_num < board[row_num].size() - 1; col_num++) {
			if (board[row_num][col_num] == PLAYER) {
				for (int direction = RIGHT; direction <= UP; direction++) {
					if (checkMove(board, direction, row_num, col_num)) {
						makeMove(temp, direction, row_num, col_num);
						if (checkGame(temp, moves)) {
							storeMoves(direction, row_num, col_num, moves);
							return true;
						}
					}
				}
			}
		}
	}

	return false;

}

void printMoves(const vector<string>& moves) {
	for (int i = moves.size() - 1; i >= 0 ; i--) 
		cout << moves[i] << endl;
}

vector<vector<char>> createBoard() {
	vector<vector<char>> board;
	vector<char> empty;
	int h, w;
	cin >> h >> w;
	string input;

	board.push_back(empty);
	for (int row_num = 0; row_num < w + 2; row_num++)
		board[0].push_back(BLOCK);

	for (int row_num = 1; row_num < h + 1; row_num++) {
		board.push_back(empty);
		board[row_num].push_back(BLOCK);
		cin >> input;
		for (int col_num = 0; col_num < w; col_num++)
			board[row_num].push_back(input[col_num]);
		board[row_num].push_back(BLOCK);
	}

	board.push_back(empty);
	for (int row_num = 0; row_num < w + 2; row_num++)
		board[board.size() - 1].push_back(BLOCK);
	return board;
}

bool checkWin(const vector<vector<char>>& board) {
	int players_count = 0;
	for (int row_num = 1; row_num < board.size() - 1; row_num++) {
		for (int col_num = 1; col_num < board[row_num].size() - 1; col_num++)
			if (board[row_num][col_num] == PLAYER)
				players_count++;
	}
	if (players_count == 1)
		return true;
	return false;
}

void makeMove(vector<vector<char>>& board, int direction, int row_num, int col_num) {
	switch (direction) {
	case RIGHT:
		board[row_num][col_num] = EMPTY;
		board[row_num][col_num + 1] = EMPTY;
		board[row_num][col_num + 2] = PLAYER;
		break;
	case DOWN:
		board[row_num + 2][col_num] = PLAYER;
		board[row_num][col_num] = EMPTY;
		board[row_num + 1][col_num] = EMPTY;
		break;
	case LEFT:
		board[row_num][col_num] = EMPTY;
		board[row_num][col_num - 1] = EMPTY;
		board[row_num][col_num - 2] = PLAYER;
		break;
	case UP:
		board[row_num][col_num] = EMPTY;
		board[row_num - 1][col_num] = EMPTY;
		board[row_num - 2][col_num] = PLAYER;
		break;
	default:
		break;
	}
}

bool checkMove(const vector<vector<char>>& board, int direction, int row_num, int col_num) {
	switch (direction) {
	case RIGHT:
		if (board[row_num][col_num + 1] == PLAYER)
			if (board[row_num][col_num + 2] == EMPTY)
				return true;
		break;
	case DOWN:
		if (board[row_num + 1][col_num] == PLAYER)
			if (board[row_num + 2][col_num] == EMPTY)
				return true;
		break;
	case LEFT:
		if (board[row_num][col_num - 1] == PLAYER)
			if (board[row_num][col_num - 2] == EMPTY)
				return true;
		break;
	case UP:
		if (board[row_num - 1][col_num] == PLAYER)
			if (board[row_num - 2][col_num] == EMPTY)
				return true;
		break;
	default:
		break;
	}
	return false;
}

void storeMoves(int direction, int row_num, int col_num, vector<string>& moves) {
	string move;
	switch (direction) {
	case RIGHT:
		move = to_string(row_num) + " " + to_string(col_num) + " R";
		moves.push_back(move);
		break;
	case DOWN:
		move = to_string(row_num) + " " + to_string(col_num) + " D";
		moves.push_back(move);
		break;
	case LEFT:
		move = to_string(row_num) + " " + to_string(col_num) + " L";
		moves.push_back(move);
		break;
	case UP:
		move = to_string(row_num) + " " + to_string(col_num) + " U";
		moves.push_back(move);
	default:
		break;
	}
}

void printBoard(vector<vector<char>> board) {
	for (int row_num = 0; row_num < board.size(); row_num++) {
		for (int col_num = 0; col_num < board[row_num].size(); col_num++)
			cout << board[row_num][col_num];
		cout << endl;
	}
}
