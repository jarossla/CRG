#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int pocetSamohlasek = 0;
	int pocetSouhlasek = 0;
	int pocetCisel = 0;

	string veta = "Nemam silu robit taketo veci 125 krat";
	string samohlasky = "aeiouyAEIOUY";
	string souhlasky = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	string cisla = "0123456789";

	cout << "Zakladna veta: " << veta << endl;
	for (int i = 0; i < veta.length(); i++)
	{
		if (samohlasky.find(veta[i]) < samohlasky.length())
			pocetSamohlasek++;
		else if (souhlasky.find(veta[i]) < souhlasky.length())
			pocetSouhlasek++;
		else if (cisla.find(veta[i]) < cisla.length())
			pocetCisel++;
		
	}
	cout << "Pocet ostatnych znakov: " <<veta.length() - pocetSamohlasek - pocetSouhlasek - pocetCisel << endl;
	cout << "Pocet samohlasek: " << pocetSamohlasek << endl;
	cout << "Pocet souhlasek: " << pocetSouhlasek << endl;
	cout << "Pocet cisiel: " << pocetCisel << endl;
	
		

}
	



