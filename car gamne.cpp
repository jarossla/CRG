#include<iostream>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = { ' ','±','±',' ',
					'±','±','±','±',
					' ','±','±',' ',
					'±','±','±','±' };
int CarPos = WIN_WIDTH / 2;
int score = 0;

void gotoxy(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size)
{
	if (size == 0) {
		size = 20;

		CONSOLE_CURSOR_INFO lpCursor;
		lpCursor.bVisible = visible;
		lpCursor.dwSize = size;
		SetConsoleCursorInfo(console, &lpCursor);
	}
}
void drawBorder(int x, int y) {
	for (int i = 0; i < SCREEN_HEIGHT; i++) { // OPRAVIT NIEKEDY
		for (int j = 0; j < 17; j++) {
			gotoxy(0 + j, i);
			cout << "±" << endl;
			gotoxy(WIN_WIDTH - j, i);
			cout << "±" << endl;
		}
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		gotoxy(SCREEN_WIDTH, i);        //NEVIEM CO TOMU JE K TOMU SA VRATIM NESKOR
		cout << "±";
	}


void genenemy(int x, int y)
{
	enemyX[int] = 17 + srand(time()) & (32);
}
void drawEnemy(int ) {
	if (enemyFlag[int] == true) {
		gotoxy(enemyX[int], enemyY[int]);
		cout << "ooooo";
		gotoxy(enemyX[int], enemyY[int] + 1);
		cout << "ooo";
		gotoxy(enemyX[int], enemyY[int] + 2);
		cout << "o";
		gotoxy(enemyX[int], enemyY[int] + 3);
		cout << "o";

	}
}
void eraseEnemy(bool ) {
	if (enemyFlag[ind] == true) {
		gotoxy(enemyX[int], enemyY[int]);
		cout << "     ";
		gotoxy(enemyX[int], enemyY[int] + 1);
		cout << "   ";
		gotoxy(enemyX[int], enemyY[int] + 2);
		cout << " ";
		gotoxy(enemyX[int], enemyY[int] + 3);
		cout << " ";

	}
}
void resetEnemy(int) {
	eraseEnemy(int);
	enemyY[int] = 1;
	genEnemy(int);
}
void drawCar() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			gotoxy(j + carPos, i + 22);
			cout << car[i][j];
		}
	}
}
int eraseCar() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			gotoxy(j + carPos, i + 22);
			cout << " ";
		}

	}
}
int collision() {
	if (enemyY[0] + 4 >= 23) {
		if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9) {
		}
	}
	return 0;
	}
void gameover() {
				system("cls");
				cout << endl;
				cout << "/t/t----------------------------------------------" << endl;
				cout << "/t/t---------------Game over----------------------" << endl;
				cout << "/t/t----------------------------------------------" << endl;
				cout << "/t/t-------stlac kluc ak chces ist do menu--------";
				getch();
				}
void nejakeskore() {
	system("cls");
	cout << "Instrukcie" << endl;
	cout << "/n---------------" << endl;
	cout << "/n Pohybovanie auta dolava a doprava" << endl;
	cout << "/n/n Stlac 'a' na pohutie do lava" << endl;
	cout << "/n Stlac 'd' na pohutie do prava" << endl;
	cout << "/n Stlac 'escape' na ukoncenie" << endl;
	cout << "/n/n Stlac kluc ak chces ist do menu" << endl;
	getch();
}
void play() {
	carPos = -1 + WIN_WIDTH / 2;
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
	enemyY[0] = enemyY[1] = 1;

	system("cls");
	drawBorder();
	updateScore();
	genEnemy(0);
	genEnemy(1);

	gotoxy(WIN_WIDTH + 7, 2);
	cout << "Autová hra";
	gotoxy(WIN_WIDTH + 6, 4);
	cout << "---------------";
	gotoxy(WIN_WIDTH + 6, 6);
	cout << "---------------";
	gotoxy(WIN_WIDTH + 7, 12);
	cout << "Control"
	gotoxy(WIN_WIDTH + 7, 13);
	cout << "---------------";
	gotoxy(WIN_WIDTH + 2, 14);
	cout << " A Key - Left";
	gotoxy(WIN_WIDTH + 2, 15);
	cout << "D Key - Right";

	gotoxy(18, 5); cout << "Stlac  kluc na zacatie";
	getch();
	gotoxy(18, 5); cout << "                      " << endl;

	while (1) {
		if (kbhit()) {
			char ch = getch();
			if (ch == 'a' || ch == 'A') {
				if (CarPos > 18)
					CarPos -= 4;
			}
			if (ch == 'd' || ch == 'D') {
				if (CarPos < 50)
					CarPos += 4;
			}
			if (ch == 27) {
				break;
			}
		}
		int collision();
		int drawCar();
		int drawEnemy(0);
		int drawEnemy(1);

		if ( collision() == 1) {
			int gameover();
			return;
		}

		int Sleep(50);
		int eraseCar();
		int eraseEnemy(0);
		int eraseEnemy(1);

		if (enemyY[0] == 10)
			if (enemyFlag[1] == 0)
				enemyFlag[1] = 1;

		if (enemyFlag[0] == 1)
			enemyY[0] += 1;

		if (enemyFlag[1] == 1)
			enemyY[1] += 1;

		if (enemyY[0] > SCREEN_HEIGHT - 4) {
			int resetEnemy(0);
			score++;
			 int updateScore();
		}
		if (enemyY[1] > SCREEN_HEIGHT - 4) {
			int resetEnemy(1);
			score++;
			int updateScore();
		}
	}
}

int main()
{
	setcursor(0, 0);
	srand((unsigned)time(NULL));

	do {
		system("cls");
		gotoxy(10, 5); 
		cout << " -------------------------- ";
		gotoxy(10, 6); 
		cout << " |        Car Game        | ";
		gotoxy(10, 7); 
		cout << " --------------------------";
		gotoxy(10, 9); 
		cout << "1. Start Game";
		gotoxy(10, 10); 
		cout << "2. Instructions";
		gotoxy(10, 11); 
		cout << "3. Quit";
		gotoxy(10, 13); 
		cout << "Select option: ";
		char op = getche();

		if (op == '1') 
			int play();
		else if (op == '2') 
			int instructions();
		else if (op == '3') 
			exit(0);

	} while (1);
	return 0;
}