#include "struktury.h"
#include <iostream>
using namespace std;
int main(){
	char w;
	do{
	cout << "\nTu testujemy struktury.\n [T] Tablica.\n [L] Lista.\n [K] Kopiec binarny.\n [D] Drzewo Binarne\n [Q] Koniec."<<endl;
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
			unsigned long ilosc;
			system("cls");
			cout << "\nLista. Wybierz co chcesz zrobic:\nA. Nowa lista.\nB.Wyswietl liste.\nC.Dodaj element.\nD. Usunac element.\nQ.Wroc do menu glownego.\n";
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
					break;
						 }
				case 'D':{
					   int numer;
					   cout << "Podaj index elementu ktory chcesz usunac: "; cin >> numer;
					   l.UsunElement(l.WyszukajElement(numer));
					   break;}
				default: break;
			}
			}while(Q!='Q');
		}
	case 'K':
		{
			kopiec k;
			char Q;
			do{
				unsigned long ilosc;
				int max, min;
				system("cls");
				cout << "\nKopiec. Wybierz co chcesz zrobic:\nA. Nowy kopiec.\nB.Wyswietl kopiec.\nC.Dodaj element.\nD. Usunac element.\nE. Przywroc wlasnosc kopca\nQ.Wroc do menu glownego.\n";
				cin >> Q;
			switch(Q){
				case 'A':{
					cout << "Podaj ilosc, element max i min: ";cin >> ilosc;cin >> max;cin >> min;
					k.nowyKopiec(ilosc,max,min,time(NULL));
					break;
				}
				case 'B':{
					char w;
					cout << k.wyswietlKopiec() <<endl;
					cout << k.zwrocKorzen();
					cin >> w;
						 break;}
				case 'C':{
					int w;
					cout << "Podaj wartosc elementu: ";cin >> w;
					k.dodajElement(w);
					break;
						 }
				case 'D':{
					   break;}
				case 'E':{
					char a;
					cout << "Kopiec przed przywarcaniem wlasnosci:"<<endl;
					cout << k.wyswietlKopiec()<<endl;
					k.przywrocWlasnoscKopca(k.zwrocIloscElementow());
					cout << "Kopiec po przywroceniu wlasnosci:"<<endl;
					cout << k.wyswietlKopiec()<<endl;
					cout << "Sprawdzenie kopcowania: "<<k.sprawdzKopcowanie()<<endl;
					cin >> a;
					break;}
				default: break;
			}
			}while(Q!='Q');
			break;
		}
	case 'D':{
		drzewo_binarne b;
		int x;
		system("cls");
		cout << "Drzewo binarne. Wybierz co chcesz zrobic:\n[1]. Nowe drzewo.\n[2]. Dodaj element.\n[3] Usun element.\n[4]. Wyszukaj element.\n [5]. Wyswietl drzewo.";
		cin >> x;
		switch(x){
		case 1:{
			int ilosc, min, max;
			cout << "Podaj ilosc: "; cin >> ilosc;
			cout << "\n Podaj wartosc min: "; cin >> min;
			cout << "\n Podaj wartosc max: "; cin >> max;
			b.noweDrzewo(ilosc, min, max, time(NULL));
			std:;string wynik;
			cout << b.wyswietlDrzewoInOrder(wynik,b.podajKorzen());
			   break;}
		case 2:{

			   break;}
		case 3:{

			break;}
		case 4:{
			int k;
			cout << "Wpisz wartosc: "; cin >> k;
			cout << b.wyswietlElement(b.wyszukajElement(k));
			break;}
		default:
			cout << "Spierdalaj";
			break;}
			 }
	default:
		{
			cout << "...";
				break;}
	}
	}while(w!='Q');
	system("pause");
}