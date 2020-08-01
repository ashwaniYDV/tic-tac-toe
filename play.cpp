#include <iostream>
using namespace std;

char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player = 'X';
int noOfPlays = 0;
string playerX, playerO;

void Intro() {
    cout << "Tic Tac Toe v1.0" << endl;
    cout << "Enter player X's name: ";
    cin >> playerX;
    cout << "Enter player O's name: ";
    cin >> playerO;
}

void Draw() {
    system("clear");
    if(player == 'X'){
        cout << playerX << "'s turn." << endl;
    } else {
        cout << playerO << "'s turn." << endl;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void PrintErrorMsg(string s) {
    cout << "Error: " << s << endl;
}

bool Input() {
    cout << "Press the number of the field: ";
    int a;
    cin >> a;
    if(a < 1 || a > 9) {
        PrintErrorMsg("Enter valid position between 1 and 9!");
        return false;
    }
    a--;
    int i = a / 3, j = a % 3;
    if(matrix[i][j] == 'X' || matrix[i][j] == 'O'){
        PrintErrorMsg("This field is already marked!");
        return false;
    }
    matrix[i][j] = player;
    return true;
}

void TogglePlayer() {
    if (player == 'X') 
        player = 'O';
    else 
        player = 'X';
}

bool CheckWin(char player) {
    if(
        (matrix[0][0] == player && matrix[0][1] == player && matrix[0][2] == player) ||
        (matrix[1][0] == player && matrix[1][1] == player && matrix[1][2] == player) ||
        (matrix[2][0] == player && matrix[2][1] == player && matrix[2][2] == player) ||

        (matrix[0][0] == player && matrix[1][0] == player && matrix[2][0] == player) ||
        (matrix[0][1] == player && matrix[1][1] == player && matrix[2][1] == player) ||
        (matrix[0][2] == player && matrix[1][2] == player && matrix[2][2] == player) ||

        (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) ||
        (matrix[2][0] == player && matrix[1][1] == player && matrix[0][2] == player)
    ) {
        return true;
    }
    return false;
}

int main() {
    system("clear");
    Intro();
    Draw();
    while (1) {
        if(!Input()) {
            continue;
        }
        noOfPlays++;
        TogglePlayer();
        Draw();
        if (CheckWin('X')) {
            cout << "\n" <<playerX << " (X) wins!" << endl;
            break;
        } else if (CheckWin('O')) {
            cout << "\n" <<playerO << " (O) wins!" << endl;
            break;
        }
        if(noOfPlays == 9) {
            cout << "\nMatch Draw!" << endl;
            break;
        }
    }
    // system("pause");
    return 0;
}
