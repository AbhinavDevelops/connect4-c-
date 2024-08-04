#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define print(x) cout << x << endl

void printBoard(string board[6][7])
{

    for (int i = 0; i < 7; i++)
    {

        for (int j = 0; j < 6; j++)
        {

            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{

    string board[6][7] = {

        {"", "", "", "", "blue", "", ""},
        {"", "", "", "", "", "blue", ""},
        {"", "", "", "red", "", "", ""},
        {"", "", "", "", "", "blue", ""},
        {"", "", "", "", "", "blue", ""},
        {"", "", "blue", "blue", "", "blue", ""},
    };

    printBoard(board);
}
