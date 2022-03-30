#include<iostream>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<time.h>

//DEFINICIA VELKOSTI OBRAZOVKY , KTORU BUDEME POUZIVAT  NA VYTVORENIE HRY
#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 50
#define WIN_WIDTH 90

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

//DEFINUJE SA ENEMY A JEHO VELKOST
int enemyY[3];
int enemyX[3];
int enemyFlag[6];
//VYKRESLENIE AUTA POMOCOU ZNAKOV
char car[6][5] = { ' ',' ','8',' ',' ',
					'8','8','8','8','8',
					'8','8','8','8','8',
					' ','8','8','8',' ',
					'8','8','8','8','8',
					'8','8','8','8','8' };
//URCENIE ZACIATKU AUTA
int carPos = WIN_WIDTH / 2;
int score = 0;

void gotoxy(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void setcursor(bool visible, DWORD size) {
	if (size == 0)
		size = 20;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}
//NAKRESLI HRANICU ZA KTORU SA AUTOM NEMOZEME DOSTAT A ZA KTORU SA NEBUDU GENEROVAT ENEMY
void drawBorder() {
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j =0 ; j <10 ; j++) {
			gotoxy(0 + j, i); cout << "I";
			gotoxy(WIN_WIDTH - j, i); cout << "I";
		}
	}
	// ZNAKOVO URCUJE CELKOVU VELKOST DEFINOVANIE OBRAZOVKU
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		gotoxy(SCREEN_WIDTH, i); cout << "+";
		gotoxy(SCREEN_WIDTH + 1, i); cout << "+";

	}
}
// URCUJE KDE SA MAJU GENEROVAT ENEMY
void genEnemy(int ind) {
	enemyX[ind] = 25 + rand() % (33);	
}
//VYKRESLI ENEMY POMOCOU ZNAKOV A URCI ICH POLOHU OD SEBA
void drawEnemy(int ind) {

	if (enemyFlag[ind] = true) {     

		gotoxy(enemyX[ind], enemyY[ind]);     cout << "******";
		gotoxy(enemyX[ind], enemyY[ind] + 1); cout << " **** ";
		gotoxy(enemyX[ind], enemyY[ind] + 2); cout << "******";
		gotoxy(enemyX[ind], enemyY[ind] + 3); cout << " **** ";
	}
}
//VYMAZE ENEMY
void eraseEnemy(int ind) {

	if (enemyFlag[ind] = true) { 

		gotoxy(enemyX[ind],enemyY[ind]);      cout << "      ";
		gotoxy(enemyX[ind], enemyY[ind] + 1); cout << "    ";
		gotoxy(enemyX[ind], enemyY[ind] + 2); cout << "      ";
		gotoxy(enemyX[ind], enemyY[ind] + 3); cout << "    ";
	}
}
void resetEnemy(int ind) {

	eraseEnemy(ind);
	enemyY[ind] = 1;
	genEnemy(ind);
}
//NAKRESLI POMOCOU ZNAKOV AUTO KTORYM SA BUDEME POHYBOVAT
void drawCar() {

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {
			gotoxy(j + carPos, i + 40); cout << car[i][j];
		}
	}
}
// VYMAZE ZNAKY AUTA KED SA POHNEME NIM
void eraseCar() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gotoxy(j + carPos, i + 40); cout << " ";
		}
	}
}
// URCUJE PRESNOST KOLIZIE AUTA S ENEMY
int collision() {
	if (enemyY[0] + 5 >= 40) {
		if (enemyX[0] + 2 - carPos >= 0 && enemyX[0] + 2 - carPos < 5) {
			return 1;
		}
	}
	return 0;
}
// VYPISE PREHRAL SI NA OBRAZOVKU PO NARAZENI AUTA DO ENEMY
void gameover() {
	system("cls");

	gotoxy(90, 20); cout << "-------------------------------------------------" << endl;
	gotoxy(90, 22); cout << "------------------ Prehral si -------------------" << endl;
	gotoxy(90, 24); cout << "-------------------------------------------------" << endl;
	gotoxy(90, 26); cout << "Stlac hocico na klavesnici na vratenie sa do menu" << endl;
	_getch();
}
// PO KAZDOM PRECHODE ENEMY PO CELEJ PLOCHE SA SKORE RESETUJE O +2
void updateScore() {
	gotoxy(WIN_WIDTH + 7, 5); cout << "Score: " << score << endl;
}
// VYPISE INSTRUKCIE NA OBRAZOVKU PO SLACENI KLAVESNICE 2
void instrukcie() {

	system("cls");
	gotoxy(95, 15); cout << "Instrukcie";
	gotoxy(95, 17); cout << "------------------------------------";
	gotoxy(95, 19); cout << "Avoid Cars by moving left or right. ";
	gotoxy(95, 21); cout << "Stlac 'a' na pohnutie sa dolava";
	gotoxy(95, 23); cout << "Stlac 'd' na pohnutie sa doprava";
	gotoxy(95, 25); cout << "Stlac 'escape' na ukoncenie";
	gotoxy(95, 27); cout << "Stlac hocico na klavesnici na vratenie do menu";
	_getch();
}
//NASTAVIA SA FUNKCIE NA HRANIE HRY , KTORE SME SI PREDTYM VYTVORILI + SA VYPISE 
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


	gotoxy(WIN_WIDTH + 7, 2); cout << "Car Game";
	gotoxy(WIN_WIDTH + 6, 4); cout << "----------";
	gotoxy(WIN_WIDTH + 6, 6); cout << "----------";
	gotoxy(WIN_WIDTH + 7, 12); cout << "Control ";
	gotoxy(WIN_WIDTH + 7, 13); cout << "-------- ";
	gotoxy(WIN_WIDTH + 2, 14); cout << " A klavesnica - Dolava";
	gotoxy(WIN_WIDTH + 2, 15); cout << " D klavesnica - Doprava";
	gotoxy(18, 5); cout << "Stlac kocico na klavesnici na zacatie hry";
	_getch();
	gotoxy(18, 5); cout << "                                         ";


	// URCUJE AKO DALEKO SA PUDEME POHYBOVAT OD STREDU DEFINOVENEJ OBRAZOVKY A AKYMI KLAVESNICAMI SA AUTO BUDE POHYBOVAT
	char ch;
	while (1) {
		if (_kbhit()) {

			ch = _getch();
			if (ch == 'a' || ch == 'A') {
				if (carPos > 18)
					carPos -= 2;
			}
			if (ch == 'd' || ch == 'D') {
				if (carPos < 70)
					carPos += 2;
			}
			if (int(ch) == 27) {
				break;
			}
		}
		drawCar();
		drawEnemy(0);
		drawEnemy(1);
		if (collision() == 1) {
			gameover();
			return;
		}
		Sleep(50);
		eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);

		if (enemyY[0] == 10)
			if (enemyFlag[1] == 0)
				enemyFlag[1] = 1;

		if (enemyFlag[0] == 1)
			enemyY[0] += 1;

		if (enemyFlag[1] == 1)
			enemyY[1] += 1;

		if (enemyY[0] > SCREEN_HEIGHT - 4) {
			resetEnemy(0);
			score++;
			updateScore();
		}
		if (enemyY[1] > SCREEN_HEIGHT - 4) {
			resetEnemy(1);
			score++;
			updateScore();
		}
	}
}

int main()
{
	setcursor(0, 0);
	srand((unsigned)time(NULL));

	do {
		system("cls");

		//VYPISE SA MENU HRY
		gotoxy(95, 14); cout << "000000000000000000000000000000";
		gotoxy(95, 15); cout << "000000000000000000000000000000";
		gotoxy(95, 17); cout << "00<<<<<<< CAR GAME >>>>>>>>>00";
		gotoxy(95, 19); cout << "000000000000000000000000000000";
		gotoxy(95, 20); cout << "000000000000000000000000000000";
		gotoxy(95, 22); cout << "Vyber jednu vec:			   ";
		gotoxy(95, 24); cout << "1. Zacatie hry                ";
		gotoxy(95, 26); cout << "2. Instrukcie				   ";
		gotoxy(95, 28); cout << "3. Koniec					   ";


		char op = _getch();
		// URCUJE AKYMI KLAVESNICAMI SI MOZEME ZAPNUT OBSAH MENU
		if (op == '1') play();
		else if (op == '2') instrukcie();
		else if (op == '3') exit(0);

	} while (1);

	return 0;
}
