#include <iostream>
using namespace std;

// Function to Display the rules and availablePositions Format
void dispay_rules()
{
    cout << "HELLO GAMERS!\nWELCOME TO THIS TIC-TAC-TOE GAME!!\n\n";
    cout << "Lets go through the rules first:\n\n";
    cout << "1. The game board will be displayed in given form:\n\n";
    cout << "      1    2    3 \n";
    int availablePositions[3][3];
    for (int i = 1; i <= 3; ++i)
    {
        cout << "   " << i << " ";
        for (int j = 0; j < 3; ++j)
        {
            cout << " " << i << j;
            if (j < 3)
                cout << " |";
        }
        cout << "\n";
        if (i < 3)
            cout << "     ---------------\n";
    }
    cout << "\n";
    cout << "2. Each cell is represented by the double digit number \"ij\", where i is the row number, j is the column number.\n\n";
    cout << "   For example, the top-left cell is represented by '11', the bottom-right cell is represented by '33', and so on.\n";

    cout << "3. Players will take turns to make a move by entering the cell number where they want to place their symbol.\n";
    cout << "   X will represent the first player, and O will represent the second player.\n\n";

    cout << "4. The game ends when one player gets three of their symbols in a row (horizontally, vertically, or diagonally), or when the availablePositions is full, resulting in a draw.\n\n";

    cout << "LETS BEGIN THE GAME!!\n\n";

    cout << "    1   2   3 \n";
    for (int i = 1; i <= 3; ++i)
    {
        cout << i << " |";
        for (int j = 0; j < 3; ++j)
        {
            cout << "  ";
            if (j < 3)
                cout << " |";
        }
        cout << "\n";
        if (i < 3)
            cout << "  -------------\n";
    }

    cout << "\n";
}

// Function to check whether the input position is valid or not
// If -1 is present at the index, it is valid
bool is_position_valid(int position, int availablePositions[3][3])
{
    int row = position / 10 - 1;
    int column = position % 10 - 1;

    if (row >= 0 && row < 3 && column >= 0 && column < 3 && availablePositions[row][column] == -1)
    {
        return true;
    }
    return false;
}

// Function to display the availablePositions
// If 1 is present at the index, X has reserved the position
// If 0 is present at the index, Y has reserved the position
void display_table(int position, char player, int availablePositions[3][3])
{
    int row = position / 10 - 1;
    int column = position % 10 - 1;

    cout << "    1   2   3 \n";
    for (int i = 0; i < 3; ++i)
    {
        cout << i + 1 << " |";
        for (int j = 0; j < 3; ++j)
        {
            if (availablePositions[i][j] == 1)
            {
                cout << " X";
            }
            else if (availablePositions[i][j] == 0)
            {
                cout << " O";
            }
            else if (i == row && j == column)
            {
                cout << " " << player;
            }
            else
            {
                cout << "  ";
            }
            if (j < 3)
                cout << " |";
        }
        cout << "\n";
        if (i < 2)
            cout << "  -------------\n";
    }
}

// Function to check the winner
bool check_win(int availablePositions[3][3], char player)
{
    int check = player == 'X' ? 1 : 0;
    if ((availablePositions[0][0] == check && availablePositions[0][1] == check && availablePositions[0][2] == check) ||
        (availablePositions[1][0] == check && availablePositions[1][1] == check && availablePositions[1][2] == check) ||
        (availablePositions[2][0] == check && availablePositions[2][1] == check && availablePositions[2][2] == check))
    {
        return true;
    }

    if ((availablePositions[0][0] == check && availablePositions[1][0] == check && availablePositions[2][0] == check) ||
        (availablePositions[0][1] == check && availablePositions[1][1] == check && availablePositions[2][1] == check) ||
        (availablePositions[0][2] == check && availablePositions[1][2] == check && availablePositions[2][2] == check))
    {
        return true;
    }

    if ((availablePositions[0][0] == check && availablePositions[1][1] == check && availablePositions[2][2] == check) ||
        (availablePositions[0][2] == check && availablePositions[1][1] == check && availablePositions[2][0] == check))
    {
        return true;
    }

    return false;
}

// The main function
int main()
{
    // Display the rules
    dispay_rules();

    // Initialize the necessary variables
    int availablePositions[3][3] = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1}};

    bool gameOver = false;
    int turn = 0;
    char player;
    int position;

    // Game loop
    while (!gameOver && turn < 9)
    {
        if (turn % 2 == 0)
        {
            player = 'X';
        }
        else
        {
            player = 'O';
        }

        cout << "It's \"" << player << "\" 's turn. Choose the Position:\n";

        cin >> position;

        if (is_position_valid(position, availablePositions))
        {
            turn++;

            int row = position / 10 - 1;
            int column = position % 10 - 1;

            availablePositions[row][column] = player == 'X' ? 1 : 0;
            display_table(position, player, availablePositions);

            if (check_win(availablePositions, player))
            {
                cout << "Player " << player << " wins!\n\n";
                gameOver = true;
            }
            else if (turn == 9)
            {
                cout << "It's a draw!\n\n";
                gameOver = true;
            }
        }
        else
        {
            cout << "Invalid position. Try again.\n";
        }
    }
    return 0;
}
