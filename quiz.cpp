// Quiz o c++ pobierajacy pytania i odpowiedzi z pliku txt, wyswiela na biezaco czy odp jest prawidlowa,
// pytajacy uzytkownika czy chce powtorzyc,//
// liczacy wynik w procentach, zapisujacy imie i wynik do pliku txt, pytajacy o wyswietlenie poprawnych odpowiedzi //
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;



int main()
{
	
	string imie;
	cout << "Jak masz na imi\251?\n";
	cin >> imie;
	cout << "\nPowodzenia, " << imie<<"!\n\n";
	char kontynuacja;
	int NrLinii = 1, NrPytania = 0;
	string temat, odpowiedz, tresc[8], odpA[8], odpB[8], odpC[8], prawidlowa[8], linia;
	fstream plik;
	plik.open("plik.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Wyst\245pi\210 b\210\245d.\n";
		exit(0);
	}

	while (getline(plik, linia))
	{
		switch (NrLinii)
		{
		case 1: temat = linia; break;
		case 2: tresc[NrPytania] = linia; break;
		case 3: odpA[NrPytania] = linia; break;
		case 4: odpB[NrPytania] = linia; break;
		case 5: odpC[NrPytania] = linia; break;
		case 6: prawidlowa[NrPytania] = linia; break;
		}
		if (NrLinii == 6)
		{
			NrLinii = 1; NrPytania++;
		}
		NrLinii++;
	}
	plik.close();
	while (true) 
	{
		double punkty = 0.0;
		cout << temat << "\n";
		for (int i = 0; i <= 7; i++)
		{
			cout << tresc[i] << "\n";
			cout << odpA[i] << "\n";
			cout << odpB[i] << "\n";
			cout << odpC[i] << "\n";
			cout << "Twoja odpowiedz: ";
			cin >> odpowiedz;
			transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);
			if (odpowiedz == prawidlowa[i])
			{
				cout << "\nBrawo! Odpowied\253 prawid\210owa.\n\n";
				punkty++;
				
			}
			else cout << "\nZ\210a odpowied\253.\n\n";
		
		}
		double procent = (punkty / 8.0) * 100;
		cout << "Koniec quizu, " << imie << "! Zdobyte punkty:" << punkty << " Procentowo: " << procent << "%.\n";

		ofstream plik2("wyniki.txt", ios::app);
		plik2 << imie <<" " <<punkty<<"/8\n";
		plik2.close();

		cout << "Czy chcesz powt\242rzy\206? \n['t' - tak, 'n' - nie]: ";
		cin >> kontynuacja;
		if (kontynuacja == 'n')
			break;
	}
	char ujawnienie;
	cout << "Czy chcesz pozna\206 prawid\210owe odpowiedzi? \n['t' - tak, 'n' - nie]: ";
	cin >> ujawnienie;
	if (ujawnienie == 't')
	{
		cout << "Prawid\210owe odpowiedzi: \n";
		for (int j = 0, x=1; j <= 7, x<=8; j++, x++)
		{
			cout << x << "." << prawidlowa[j] << "\n";
		}
	}
	
	
	
		
	system("pause");
}


