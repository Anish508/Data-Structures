#include <iostream>
#include <vector>

using namespace std;

class NQueens
{
private:
      vector<vector<int>> board;
      int size;
      int count;

public:
      NQueens(int n) : size(n), count(0)
      {
            board.resize(n, vector<int>(n, 0));
      }

      bool isSafe(int row, int col)
      {
            for (int i = 0; i < row; i++)
            {
                  if (board[i][col] == 1)
                  {
                        return false;
                  }
            }

            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            {
                  if (board[i][j] == 1)
                  {
                        return false;
                  }
            }
            for (int i = row - 1, j = col + 1; i >= 0 && j < size; i--, j++)
            {
                  if (board[i][j] == 1)
                  {
                        return false;
                  }
            }
            return true;
      }

      void printBoard()
      {
            count++;
            cout << "\nSolution :" << count << "\n";

            for (int i = 0; i < size; i++)
            {
                  for (int j = 0; j < size; j++)
                  {
                        if (board[i][j] == 1)
                        {
                              cout << "Q" << "\t";
                        }
                        else
                        {
                              cout << "." << "\t";
                        }
                  }
                  cout << endl;
            }
            cout << endl;
      }
      void solve(int row)
      {
            if (row == size)
            {
                  printBoard();
                  return;
            }

            for (int col = 0; col < size; col++)
            {
                  if (isSafe(row, col))
                  {
                        board[row][col] = 1;
                        solve(row + 1);
                        board[row][col] = 0;
                  }
            }
      }

      int getCount()
      {
            return count;
      }
};

int main()
{
      int n;
      cout << "Enter number of queens:";
      cin >> n;

      if (n <= 1)
      {
            cout << "Please enter a positive value";
            return 0;
      }
      if (n == 2 || n == 3)
      {
            cout << "Plaese enter valid input!";
            return 0;
      }

      NQueens nq(n);

      cout << "\n Finding all possible solutions....\n";

      nq.solve(0);

      cout << "\nTotal number of solutions:" << nq.getCount() << "\n";

      return 0;
}