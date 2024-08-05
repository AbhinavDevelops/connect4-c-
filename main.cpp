#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define print(x) cout << x << endl

void printBoard(string board[6][7])
{
    print("\n\n");

    for (int i = 0; i < 6; i++)
    {

        for (int j = 0; j < 7; j++)
        {

            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    print("\n\n");
}

bool checkDirection(string board[6][7], int r, int c, int rowAdd, int columnAdd, string userCoin)
{
    int count = 0;
    while (r < 6 && c < 7)
    {

        // print(board[r][c]);

        if (board[r][c] == userCoin)
            count += 1;

        else
            return (count >= 4);

        r += rowAdd;

        c += columnAdd;

        if (count == 4)
            return true;
    }

    return (count >= 4);
}

bool checkWinners(string board[6][7], string userCoin)
{

    for (int i = 0; i < 6; i++)
    {

        for (int j = 0; j < 7; j++)
        {

            // horizontal

            if (checkDirection(board, i, j, 0, 1, userCoin))
                return true;

            // verctical

            if (checkDirection(board, i, j, 1, 0, userCoin))
                return true;

            if (checkDirection(board, i, j, -1, -1, userCoin))
                return true;
        }
    }

    return false;
}

void playerTurn(int pickedRow, string board[6][7], string userCoin)
{

    int row = pickedRow - 1;

    print(row);

    if (board[-1][row] == "e")
    {
        board[-1][row] = userCoin;
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        if (board[i + 1][row] != "e")
        {
            board[i][row] = userCoin;
        }

        // print(board[i][row]);
    }
}

int main()
{

    bool play = true;

    string board[6][7] = {

        {"e", "e", "e", "e", "e", "e", "e"},
        {"e", "e", "e", "e", "e", "e", "e"},
        {"e", "e", "e", "e", "e", "e", "e"},
        {"e", "e", "e", "e", "e", "e", "e"},
        {"e", "e", "e", "e", "e", "e", "e"},
        {"e", "e", "e", "e", "e", "e", "e"},
    };
    printBoard(board);

    string userCoin1 = "X";
    string userCoin2 = "O";

    print("Player 1 you are X, Player 2 you are O\n\n\n");

    while (play)
    {

        print("Player 1 Pick a row between 1-7 to drop your coin\n");

        int pickedRow1;

        cin >> pickedRow1;

        playerTurn(pickedRow1, board, userCoin1);

        printBoard(board);

        if (checkWinners(board, userCoin1))
        {
            print("Player 1 has won good job !!!!");

            return 0;
        }
        print("Player 2 Pick a row between 1-7 to drop your coin\n");

        int pickedRow2;

        cin >> pickedRow2;

        playerTurn(pickedRow2, board, userCoin2);

        printBoard(board);

        if (checkWinners(board, userCoin2))
        {
            print("Player 2 has won good job !!!! ");

            return 0;
        }

        print("Do you want to keep playing. y:yes n:no");

        string input;

        cin >> input;

        if (input == "y" or input == "yes")
            play = 1;

        else
            play = 0;
    }
}
