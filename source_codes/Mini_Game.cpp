#include <iostream>
using namespace std;

//Mini Game

int main (){

int answer;
int score = 0;
int life = 3;

do {
srand(time(0));

int randomNum01 = rand() % 51;
int randomNum02 = rand() % 51;
int randomResult = randomNum01 + randomNum02;

cout << "\nMath Game: Mini Project" << endl;
cout << "Score: " << score << endl;
cout << " " << life << " Life" << endl;
cout << randomNum01 <<" + " << randomNum02 <<" = ";
cin >> answer;

if (randomResult == answer){
    cout << "Very good!" << endl;
    ++score;
    } else {
        cout << "Wrong answer, try again." << endl;
    --score;
    -- life;
        }
} while (life != 0);

cout << "\nYou have no more life" << endl;
cout << "Thank you for playing" << endl;
cout << "Total score: " << score << endl;

    return 0;
    }

