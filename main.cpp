#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<int>> board, int row, int col, int i)
{
    for (int j = 0; j < 9; j++)
    {
        if (board[j][col] == i)
        {
            return false;
        }
        if (board[row][j] == i)
        {
            return false;
        }
        if (board[3 * (row / 3) + j / 3][3 * (col / 3) + j % 3] == i)
            return false;
    }
    return true;
}
bool solve(vector<vector<int>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {
                for (int i = 1; i <= 9; i++)
                {
                    if (isValid(board, row, col, i))
                    {
                        board[row][col] = i;

                        if (solve(board))
                            return true;
                        else
                            board[row][col] = 0;
                    }
                }
                if (board[row][col] == 0)
                    return false;
            }
        }
    }
    return true;
}
void print(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> board = {
        {5, 3, 0, 6, 7, 8, 9, 0, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {0, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 0, 4, 8, 5, 6},
        {9, 6, 0, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    bool ans = solve(board);
    if (ans)
    {
        print(board);
    }
    else
    {
        cout << "Not valid Soduku " << endl;
    }
    return 0;
}
