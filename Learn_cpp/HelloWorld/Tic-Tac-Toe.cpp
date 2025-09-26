#include <iostream>
using namespace std;
char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };
void displayBoard() {
    cout << "\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
bool checkWin(char p) {
    for(int i=0;i<3;i++)
        if(board[i][0]==p && board[i][1]==p && board[i][2]==p) return true;
    for(int j=0;j<3;j++)
        if(board[0][j]==p && board[1][j]==p && board[2][j]==p) return true;
    if(board[0][0]==p && board[1][1]==p && board[2][2]==p) return true;
    if(board[0][2]==p && board[1][1]==p && board[2][0]==p) return true;
    return false;
}
int main() {
    int move, turn=0;
    char player;
    while(turn < 9) {
        displayBoard();
        player = (turn % 2 == 0) ? 'X' : 'O';
        cout << "Player " << player << " enter move: ";
        cin >> move;
        int r = (move-1)/3, c = (move-1)%3;
        if(board[r][c]=='X' || board[r][c]=='O') {
            cout << "Invalid move!\n";
            continue;
        }
        board[r][c] = player;
        if(checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }
        turn++;
    }
    if(turn==9) cout << "It's a draw!\n";
    return 0;
}
