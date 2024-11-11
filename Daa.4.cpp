//n Queens Problems
//Name:Sumit Naganwar
//Roll no:TIA34

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int N = board.size();
    for (int i = 0; i < col; ++i)
        if (board[row][i] == 1)
            return false;

    for (int i = 0; i < row; ++i)
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i < N && j >= 0; ++i, --j)
        if (board[i][j] == 1)
            return false;

    return true;
}

void printBoard(const vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col) {
    int N = board.size();
    if (col >= N)
        return true;

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    cout << "Enter the number of queens: ";
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueensUtil(board, 0)) {
        printBoard(board);
    } else {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}

