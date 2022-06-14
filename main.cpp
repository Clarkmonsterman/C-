#include <iostream>


using namespace std;
int chessboard[8][8];
int num_placed = 0;

bool placeQueen(int (&chessboard)[8][8]);
bool checkAcross(int (&chessboard)[8][8], int posX, int posY);
bool checkVertical(int (&chessboard)[8][8], int posX, int posY);
bool checkDiagonals(int (&chessboard)[8][8], int posX, int posY);
void printBoard(int (&chessboard)[8][8]);
void resetBoard(int (&chessboard)[8][8]);
//void returnDiagonals(int (&chessboard)[8][8], int posX, int posY, int &pivotX, int &pivotY);
//void emptyRowCol(int (&chessboard)[8][8], int &row, int &col);


int main() {
    bool failure = false;
    srand((unsigned) time(0));

    do {
        failure = placeQueen(chessboard);
//        cout << "Failure: " << failure << endl;

        if(failure == true) {
//            printBoard(chessboard);
            resetBoard(chessboard);
//            printBoard(chessboard);
            num_placed = 0;
            failure = false;
        }
    }
    while(num_placed < 8);


//    cout << "Failure: " << failure << endl;
//    cout << "Number_Placed: " << num_placed << endl;

    printBoard(chessboard);
    return 0;
}


bool placeQueen(int (&chessboard)[8][8]){

//    cout << "Placing the Queen" << endl;

    int posX = rand() % 8;
    int posY = rand() % 8;

    bool failure = false;

    int attempts = 0;
    int attempted[8][8];

    bool attacked = false;
    int attacked1 = 0;
    int attacked2 = 0;
    int attacked3 = 0;
//
//    if(num_placed == 7){
//        pivots(chessboard);
//
//    }


    do {
        int z = attempts + num_placed;
        while(chessboard[posX][posY] == 1 | attempted[posX][posY] == 1){
            z = z + 1;
            posX = rand() % 8;
            posY = rand() % 8;

//            cout << posX;
//            cout << posY;
//            cout << endl;
            if(z > 64)
                break;
        }

        attacked = false;
//        cout << posX << " " << posY << endl;
        attempts = attempts + 1;

        attacked1 = checkAcross(chessboard, posX, posY);
        attacked2 = checkVertical(chessboard, posX, posY);

        attacked3 = checkDiagonals(chessboard, posX, posY);

        attempted[posX][posY] = 1;

//        cout << "Attacked123: " << attacked1 << attacked2 << attacked3 << endl;

//        cout << "Attacked:" << attacked << endl;

        if(attacked1 + attacked2 + attacked3 > 0)
            attacked = true;

//        cout << "Attacked: " << attacked << endl;
        if((attempts + num_placed) == 64) {
//            printBoard(attempted);
            break;
        }
    }
    while(attacked == true);


    if(attacked == false & chessboard[posX][posY] != 1) {
//        cout << "Adding a New Queen at:" << endl;
//        cout << posX << " " << posY << endl;
//        cout << endl;



        chessboard[posX][posY] = 1;
        num_placed = num_placed + 1;
    }

    if(attempts + num_placed == 64) {
//        cout << "Attempts + Number Placed:" << endl;
//        cout << attempts + num_placed;
        failure = true;
    }

    return failure;

}

bool checkAcross(int (&chessboard)[8][8], int posX, int posY) {
    bool attacking = false;

//    cout << posX << " " << posY << endl;


    for (int i = posX + 1; i < 8; i++) {
        int tmp = 0;
        tmp = chessboard[i][posY];
//        cout << tmp << endl;
        if (tmp == 1) {
            attacking = true;
            break;
        }
    }

    for (int i = 0; i < posX; i++) {
        int tmp = 0;
        tmp = chessboard[i][posY];
//        cout << tmp << endl;
        if (tmp == 1) {
            attacking = true;
            break;
        }
    }
//    cout << "Attacking: " << attacking << endl;
    return attacking;
}

bool checkVertical(int (&chessboard)[8][8], int posX, int posY) {
    bool attacking = false;

    for (int i = posY + 1; i < 8; i++) {
         int tmp = 0;
         tmp = chessboard[posX][i];
            if (tmp == 1) {
                attacking = true;
                break;
            }
    }
    for (int i = 0; i < posY; i++) {
        int tmp = 0;
        tmp = chessboard[posX][i];
        if (tmp == 1) {
            attacking = true;
            break;
        }
    }
    return attacking;
}

void returnDiagonals(int (&chessboard)[8][8], int posX, int posY, int &pivotX, int &pivotY){
    bool attacking = false;

    int i = posX + 1;
    int j = posY + 1;
    while (i < 8 & j < 8) {
        int tmp = 0;
        tmp = chessboard[i][j];
        if (tmp == 1) {
            attacking = true;
            pivotX = i;
            pivotY = j;
            break;
        }
        i = i + 1;
        j = j + 1;
    }

    i = posX -1;
    j = posY -1;
    while (i >= 0  & j >= 0) {
        int tmp = 0;
        tmp = chessboard[i][j];
        if (tmp == 1) {
            attacking = true;
            pivotX = i;
            pivotY = j;
            break;
        }
        i = i - 1;
        j = j - 1;
    }

    i = posX - 1;
    j = posY + 1;

    while (i >= 0  & j < 8) {
        int tmp = 0;
        tmp = chessboard[i][j];
        if (tmp == 1) {
            attacking = true;
            pivotX = i;
            pivotY = j;
            break;
        }
        i = i - 1;
        j = j + 1;
    }

    i = posX + 1;
    j = posY - 1;

    while (i < 8  & j >= 0) {
        int tmp = 0;
        tmp = chessboard[i][j];
        if (tmp == 1) {
            attacking = true;
            pivotX = i;
            pivotY = j;
            break;
        }
        i = i + 1;
        j = j - 1;
    }
};


bool checkDiagonals(int (&chessboard)[8][8], int posX, int posY) {

    bool attacking = false;

    int i = posX + 1;
    int j = posY + 1;
    while (i < 8 & j < 8) {
        int tmp = 0;
        tmp = chessboard[i][j];
        if (tmp == 1) {
            attacking = true;
            break;
        }
        i = i + 1;
        j = j + 1;
    }

    i = posX -1;
    j = posY -1;
    while (i >= 0  & j >= 0) {
        int tmp = 0;
        tmp = chessboard[i][j];
        if (tmp == 1) {
            attacking = true;
            break;
        }
        i = i - 1;
        j = j - 1;
    }

    i = posX - 1;
    j = posY + 1;

    while (i >= 0  & j < 8) {
        int tmp = 0;
        tmp = chessboard[i][j];
        if (tmp == 1) {
            attacking = true;
            break;
        }
        i = i - 1;
        j = j + 1;
    }

    i = posX + 1;
    j = posY - 1;

    while (i < 8  & j >= 0) {
        int tmp = 0;
        tmp = chessboard[i][j];
        if (tmp == 1) {
            attacking = true;
            break;
        }
        i = i + 1;
        j = j - 1;
    }



    return attacking;
}

void printBoard(int (&chessboard)[8][8]){
    cout << "Printing the Board with 8 Non-Attacking Queens!!!" << endl;

    for(int i = 0; i < 8; i++){
        if(i > 0)
            cout << endl;
            cout << endl;
        for(int j = 0; j < 8; j++) {
            if(chessboard[i][j] == 1)
                cout << "X  ";
            else
                cout << chessboard[i][j] << "  ";
        }
    }
}


void resetBoard(int (&chessboard)[8][8]){
//    cout << "Resetting the Board" << endl;

    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++) {
            chessboard[i][j] = 0;
        }
    }
}