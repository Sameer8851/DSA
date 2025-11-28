#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n)
{
    if(board[row][col]  == '*') return false;
    for (int j = 0; j < col; j++)
        if (board[row][j] == 'Q')
            return false;

    // upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // lower left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

int solve(int col, vector<string> &board, int n)
{
    if (col == n)
    {
        return 1;
    }
    int result = 0;

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            result = result + solve(col + 1, board, n);
            board[row][col] = '.';
        }
    }
    return result;
}
int main()
{


    vector<string> board(8);
    for (int i = 0; i < 8; ++i)
    {
        cin >> board[i];
    }
    int ans = solve(0, board, 8);
    cout << ans << endl;

    return 0;
}
