#include <iostream>

using namespace std;

double abc(double x, double y) {
	return x + y;
}
double def(double x, double y) {
	return x - y;
}
double ghi(double x, double y) {
	return x * y;
}
double jkl(double x, double y) {
	return x / y;
}

double spocitaj(float x, float y) {
	cout << "1. funkcia" << endl;
	return x + y;
}
double spocitaj(int x, float y) {
	cout << "2. funkcia" << endl;
	return x + y;
}
double spocitaj(float x) {
	cout << "3. funkcia" << endl;
	return x + x;
}


double odcitaj(float x, float y) {
	cout << "4. funkcia" << endl;
	return x - y;
}
double odcitaj(int x, float y) {
	cout << "5. funkcia" << endl;
	return x - y;
}
double odcitaj(float x) {
	cout << "6. funkcia" << endl;
	return x - x;
}


double vynasob(float x, float y) {
	cout << "7. funkcia" << endl;
	return x * y;
}
double vynasob(int x, float y) {
	cout << "8. funkcia" << endl;
	return x * y;
}
double vynasob(float x) {
	cout << "9. funkcia" << endl;
	return x * x;
}


double vydel(float x, float y) {
	cout << "10. funkcia" << endl;
	return x / y;
}
double vydel(int x, float y) {
	cout << "11.funkcia" << endl;
	return x / y;
}
double vydel(float x) {
	cout << "12. funkcia" << endl;
	return x / x;
}

int main()
{
	char a, b;
	float x, y;

	do {
		cout << "zadaj prve cislo" << endl;
		cin >> x;
		cout << "vyber funkciu" << endl;
		cin >> a;
		cout << "zadaj druhe cislo" << endl;
		cin >> y;

		if (a == '+')
		{
			cout << "vysledok je " << abc(x, y) << endl;
			cout << spocitaj(x, y) << endl;
		}

		if (a == '-')
		{
			cout << "vysledok je " << def(x, y) << endl;
			cout << odcitaj(x, y) << endl;
		}

		if (a == '*')
		{
			cout << "vysledok je " << ghi(x, y) << endl;
			cout << vynasob(x, y) << endl;
		}

		if (a == '/')
		{
			cout << "vysledok je " << jkl(x, y) << endl;
			cout << vydel(x, y) << endl;
		}
		cout << "Stlac p ak chces skoncit" << endl;
		cin >> b;
	}
	while (b != 'p');
		;
}