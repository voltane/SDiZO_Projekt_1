#include "struktury.h"
#include <time.h>
#include <iostream>
using namespace std;
int main(){

	
	char w;
	do{
	cout << "Tu testujemy struktury.\n [T] Tablica.\n [L] Lista.\n [Q] Koniec."<<endl;
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
			unsigned long ilosc,min,max;
			lista Lista;
			cout << "Podaj ilosc, wartosc min i wartosc max: ";
			cin >> ilosc;
			cin >> min;
			cin >> max;
			Lista.nowa_lista(ilosc,min,max,time(NULL));
			int h=Lista.podaj_ilosc_elementow();
			for(unsigned long i=0;i<=(h-1);i++){
				cout << Lista.podaj_wartosc(i)<<endl;
			}	
			break;
		}
	default:
		{
			cout << "...";
				break;}
	}
	}while(w!='Q');
	system("pause");
}