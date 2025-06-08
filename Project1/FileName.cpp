#include <iostream>
using namespace std;

char Board[3][3] = {
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' }
};

void ViewBoard();

class Player {
    char charct;
    int points;

public:
    Player(char x, int y);
    void SetPlayer(char x);
    char GetPlayer();
    int GetPoints();
    void Points_increment();
    void Set_points();
};

Player::Player(char x, int y) {
    charct = x;
    points = y;
}

char Player::GetPlayer() {
    return charct;
}

int Player::GetPoints() {
    return points;
}

void Player::Points_increment() {
    points++;
}

void Player::Set_points() {
    points = 0;
}

void Player::SetPlayer(char x) {
    charct = x;
}

bool CheckError() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid! Just numbers please.\n";
        return true;
    }
    return false;
}


    void Put_Char(int x, int y, char z) {
        while (true) {
            if (x < 0 || x > 2 || y < 0 || y > 2) {
                cout << "Invalid position. Try again: ";
                cin >> x >> y;
              
                continue;
            }

            if (Board[x][y] != ' ') {
                cout << "The position is not free. Try again: ";
                cin >> x >> y;
               
                continue;
            }

            break; // Input is valid, break the loop
        }

        Board[x][y] = z;
    

}

void ViewBoard() {
    system("cls");
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| " << Board[i][0] << " | " << Board[i][1] << " | " << Board[i][2] << " |\n";
        cout << "-------------\n";
    }
}

void Clear_Board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Board[i][j] = ' ';
}

bool CheckWin(char& z) {
    for (int i = 0; i < 3; i++) {
        if (Board[0][i] != ' ' && Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i]) {
            z = Board[0][i];
            return true;
        }
        if (Board[i][0] != ' ' && Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2]) {
            z = Board[i][0];
            return true;
        }
    }

    if (Board[0][0] != ' ' && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2]) {
        z = Board[0][0];
        return true;
    }

    if (Board[0][2] != ' ' && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0]) {
        z = Board[0][2];
        return true;
    }

    return false;
}

bool CheckDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (Board[i][j] == ' ')
                return false;
    return true;
}

void valid(int& num) {
    if (num != 1 && num != 2) {
        cout << "Try with a valid number: ";
        cin >> num;
        valid(num);
    }
}

int main() {
    cout << "Welcome to X O Game\n";

    Player x('X', 0);
    Player y('O', 0);
    char z = ' ';
    bool again = false;

    do {
        ViewBoard();

        while (true) {
            int r, c;

            cout << "Enter the Row and Column of player " << x.GetPlayer() << " : ";
            cin >> r >> c;
            if (CheckError()) continue;
            Put_Char(r, c, x.GetPlayer());
            ViewBoard();

            if (CheckWin(z)) break;
            if (CheckDraw()) {
                cout << "Draw\n";
                break;
            }

            cout << "Enter the Row and Column of player " << y.GetPlayer() << " : ";
            cin >> r >> c;
            if (CheckError()) continue;
            Put_Char(r, c, y.GetPlayer());
            ViewBoard();

            if (CheckWin(z)) break;
            if (CheckDraw()) {
                cout << "Draw\n";
                break;
            }
        }

        if (z == x.GetPlayer()) {
            cout << "Player " << z << " is the Winner\n";
            x.Points_increment();
        }
        else if (z == y.GetPlayer()) {
            cout << "Player " << z << " is the Winner\n";
            y.Points_increment();
        }

        cout << "X : " << x.GetPoints() << "\n";
        cout << "O : " << y.GetPoints() << "\n";

        cout << "Do you want to play again?\n";
        cout << "Choose 1 if Yes\n";
        cout << "Choose 2 if No\n";

        int num;
        cin >> num;
        if (CheckError()) continue;
        valid(num);

        if (num == 2) {
            cout << "Goodbye!\n";
            return 0;
        }
        else {
            again = true;
            Clear_Board();
        }

    } while (again);

    return 0;
}
