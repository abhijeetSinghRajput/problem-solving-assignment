#include <iostream>
#include <vector>

using namespace std;
class Sudoku
{
    vector<vector<int>> game;

    bool isValid(int row, int col, int val)
    {
        // check is there any value in row and col
        for (int i = 0; i < 9; ++i)
        {
            if (game[i][col] == val)
                return false;
            if (game[row][i] == val)
                return false;
        }

        int x = row / 3 * 3;
        int y = col / 3 * 3;
        // check is there any value in sub-grid
        for (int i = x; i < x + 3; ++i)
        {
            for (int j = y; j < y + 3; ++j)
            {
                if (game[i][j] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    Sudoku() : game(9, vector<int>(9, 0)) {}
    Sudoku(vector<vector<int>> newGame)
    {
        game = newGame;
    }
    bool solve()
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (game[i][j] == 0)
                {
                    for (int val = 1; val <= 9; ++val)
                    {
                        if (isValid(i, j, val))
                        {
                            game[i][j] = val;
                            if (solve())
                                return true;
                            game[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void print()
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if(game[i][j]){
                    printf("\033[34m%d  \033[0m", game[i][j]);
                }
                else{
                    printf("\033[30m%d  \033[0m", game[i][j]);
                }
                if((j+1) % 3 == 0){
                    cout<<"  ";
                }
            }
            if((i+1) % 3 == 0){
                cout<<endl;
            }
            cout << endl;
        }
    }
};
int main()
{
    // Sudoku *sudoku = new Sudoku(
    //     {
    //         {9, 3, 6,   8, 2, 4,    0, 0, 0},
    //         {0, 0, 0,   0, 7, 0,    8, 6, 2},
    //         {2, 7, 8,   0, 1, 0,    0, 0, 0},

    //         {0, 0, 0,   0, 0, 0,    0, 5, 0},
    //         {7, 2, 0,   4, 0, 0,    6, 9, 0},
    //         {8, 0, 4,   0, 0, 9,    0, 0, 0},

    //         {4, 8, 0,   6, 9, 0,    3, 7, 0},
    //         {5, 9, 0,   0, 0, 0,    0, 0, 0},
    //         {3, 6, 7,   0, 4, 0,    2, 8, 9}
    //     }
    // );

    Sudoku *sudoku = new Sudoku(
        {
            {8, 0, 9,   0, 0, 0,    6, 0, 0},
            {0, 0, 0,   7, 0, 0,    0, 5, 0},
            {0, 0, 0,   0, 0, 0,    0, 0, 0},

            {6, 0, 0,   0, 0, 0,    3, 0, 0},
            {0, 4, 0,   0, 0, 0,    0, 7, 0},
            {0, 0, 0,   0, 9, 0,    0, 0, 0},

            {0, 7, 2,   5, 0, 0,    0, 0, 0},
            {3, 0, 0,   0, 0, 0,    9, 0, 8},
            {0, 0, 0,   4, 0, 0,    0, 0, 0}
        }
    );
    printf("INPUT\n");
    sudoku->print();
    sudoku->solve();

    printf("OUTPUT\n");
    sudoku->print();
    return 0;
}