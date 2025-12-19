/* 
* 
*Tick Tack Toe Game 
*December 14, 2025
*Author: Adam Nasrallah
*/

#include <iostream>
#include <vector>

using namespace std;


void DisplayBoard(vector<char>& board) {

    for (int i = 0; i < 3; ++i) {
        cout << "   -------" << endl;
        cout << "   |";
        for (int j = 0; j < 3; ++j) {
            cout << board[i * 3 + j] << "|";
        }
        cout << endl;
    }
    cout << "   -------" << endl;
    
}

void MakeMove(vector<char>& board, char& playerTurn) {
    cout << "Make your move (enter position a-i): ";
    char move;
    cin >> move;
    for (unsigned int i = 0; i < board.size(); ++i) {
        if (board[i] == move) {
            if (playerTurn == 'X') {
                board[i] = 'X';
                playerTurn = 'O';
                DisplayBoard(board);
                break;
            } 
            else if (playerTurn == 'O') {
                board[i] = 'O';
                playerTurn = 'X';
                DisplayBoard(board);
                break;
            }
        }
    }
}

bool CheckWinOrDraw(vector<char>& board, char& playerTurn) {
    if ((board[0] == board[1] && board[1] == board[2]) ||
        (board[3] == board[4] && board[4] == board[5]) ||
        (board[6] == board[7] && board[7] == board[8]) ||
        (board[0] == board[3] && board[3] == board[6]) ||
        (board[1] == board[4] && board[4] == board[7]) ||
        (board[2] == board[5] && board[5] == board[8]) ||
        (board[0] == board[4] && board[4] == board[8]) ||
        (board[2] == board[4] && board[4] == board[6])) {
        cout << "Player " << (playerTurn == 'X' ? 'O' : 'X') << " wins!" << endl;
        return true;
    }
    return false;
}


int main() {
    char newGame;

    do {
        cout << " Welcome to Tick Tack Toe!" << endl;
        cout << "----------------------------" << endl;
        cout << "Player 1 is X and Player 2 is O" << endl;
        cout << "Start New Game? (y/n): ";
        cin >> newGame;

        if (newGame == 'y' || newGame == 'Y') {


            bool gameOver = false;
            int counter = 0;
            vector <char> board;
            char playerTurn = 'X';
            while (!gameOver) {

                for (char i = 'a'; i < 'j'; ++i) {
                    board.push_back(i);
                }

                if (counter == 0) {
                    DisplayBoard(board);
                }

                MakeMove(board, playerTurn);
                gameOver = CheckWinOrDraw(board, playerTurn);
                counter++;
            }

            cout << "Game Over!" << endl;
        } 
        else {
            cout << "Exiting the game. Goodbye!" << endl;
        }

    } while (newGame == 'y' || newGame == 'Y');
    
    return 0;
}