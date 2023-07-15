#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';   // Player is the X
const char COMPUTER = 'O'; // Computer is the O

void resetBoard();     // resets the board
void printBoard();     // print the 2D char array
int checkFreeSpaces(); // check free spaces if game is over will return 0
void playerMove();     // When its time for the player to make its move
void computerMove();   // when its the computers turn to make its move
char checkWinner();    //
void printWinner(char winner);

int main(int argc, char **argv)
{

    char winner = ' ';
    char response;

    do // play again loop
    {
        char winner = ' ';
        char response = ' ';

        resetBoard();
        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();

            if (winner != ' ' || checkWinner() == 0)
            { // checks to see if theres a winner
                break;
            }

            computerMove();
            winner = checkWinner();

            if (winner != ' ' || checkWinner() == 0)
            { // checks to see if theres a winner
                break;
            }
        } // End of while loop

        printBoard();
        printWinner(winner);

        printf("\nDo you want to play again? (Y/N): ");
        scanf("%c");
        scanf(" %c", &response);
        response = toupper(response);

    } while (response == 'Y'); // End of do While
    /*
        For some reason the Y input isn't working. 
        It keeps going to the "Thanks for Playing!" statement
        terminating the project.
    */
    printf("Thanks for Playing!");

    return 0;
} // End of Main

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        } // end of inner loop

    } // end of outer loop
    return freeSpaces;
}

void playerMove()
{

    int x;
    int y;

    do
    {

        printf("Enter row number #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column number #(1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ') // check to see if spot is occupied by a character
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' '); // the index of x and y doesn't == empty space
}

void computerMove()
{
    // creates a seed based on current time
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;

        } while (board[x][y] != ' '); // check to see if theres an open space to place the 'O'

        board[x][y] = COMPUTER;
    } // end of if statement
    else
    {
        printWinner(' '); // No winner, its a draw
    }
}

char checkWinner()
{

    // check rows

    for (int i = 0; i < 3; i++) // checks all win conditions for each row
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    } // end of for loop

    // check columns
    for (int i = 0; i < 3; i++) // checks all win conditions for each columns
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    } // end of for loop

    // check diagonal
    for (int i = 0; i < 3; i++) // checks all win conditions for each columns
    {
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }
    } // end of for loop

    // check second diagonal
    for (int i = 0; i < 3; i++) // checks all win conditions for each columns
    {
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return board[0][2];
        }
    } // end of for loop

    return ' ';
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("YOU WIN!!!");
    }
    else if (winner = COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("IT'S A TIE!!!!!");
    }
}
