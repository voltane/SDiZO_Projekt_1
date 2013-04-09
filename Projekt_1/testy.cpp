#include "struktury.h"
#include <time.h>
#include <iostream>
using namespace std;
int main(){

	
	char w;
	do{
	cout << "\nTu testujemy struktury.\n [T] Tablica.\n [L] Lista.\n [Q] Koniec."<<endl;
	cin >> w;
	switch(w){
	case 'T':{
			unsigned long ilosc,min,max;
			cout << "Podaj ilosc, wartosc min i wartosc max: ";
			cin >> ilosc;
			cin >> min;
			cin >> max;
			tablica Tablica;
			Tablica.nowa_tablica(ilosc,min,max,time(NULL));
			unsigned long w=Tablica.podaj_ilosc_elementow();
			for(unsigned long i=0;i<=(w-1);i++){
				cout << Tablica.wyswietl_element(i)<<endl;
			}
			break;
		}
	case 'L':
		{
			lista l;
			char Q;
			do{
			unsigned long ilosc,kierunek;
			system("cls");
			cout << "\nLista. Wybierz co chcesz zrobic:\nA. Nowa lista.\nB.Wyswietl liste.\nC.Dodaj element.\nQ.Wroc do menu glownego.\n";
			cin >> Q;
			switch(Q){
				case 'A':{
					cout << "Podaj ilosc: ";cin >> ilosc;
					l.nowaLista(ilosc,time(NULL));
					break;
				}
				case 'B':{
					char w;
					cout << l.WyswietlListe();
					cin >> w;
						 break;}
				case 'C':{
					int w;
					cout << "\nWybierz jak dodac: \n 1. Na poczatku.\n 2. Na koncu.\n 3. W srodek.\n";
					cin >> w;
					switch(w){
						case 1:{
							int wartosc;
							cout << "Podaj wartosc elementu: "; cin >> wartosc;
							l.dodajNaPoczatek(l.NowyElement(wartosc));
							break;}
						case 2:{
							int wartosc;
							cout << "Podaj wartosc elementu: "; cin >> wartosc;
							l.dodajNaKoniec(l.NowyElement(wartosc));
							break;}
						case 3:{
							int numer,wartosc;
							cout << "Podaj wartosc elementu: "; cin >> wartosc;
							cout << "Podaj numer poprzednika: "; cin >> numer;
							l.dodajWSrodku(l.NowyElement(wartosc),l.WyszukajElement(numer));
							break;}
					}

					
					break;}
				default: break;
			}
			}while(Q!='Q');
		}
	default:
		{
			cout << "...";
				break;}
	}
	}while(w!='Q');
	system("pause");
}