#include "lista.h"
#include <iostream>
#include <stdlib.h>

lista::lista(void)
{
	l=0;
	ilosc_elementow=0;
	ilosc_list=0;
	start=0;
	koniec=0;
}


lista::~lista(void)
{
}
// metody umozliwiajace dostep
unsigned long lista::podaj_ilosc_elementow(){
	return ilosc_elementow;
};
int lista::podaj_wartosc(unsigned long i){
	return l[i].wartosc;
}
unsigned long lista::podaj_poprzednika(int i){
	unsigned long zmienna = *l[i].p;
	zmienna=l[zmienna].index;
	return zmienna;
}
unsigned long lista::podaj_nastepnika(int i){
	unsigned long zmienna=*l[i].n;
	zmienna=l[zmienna].index;
	return zmienna;
}
// zarzadzanie listami
void lista::nowa_lista(int ilosc,int min, int max, int seed){
	srand(seed);
	if(l==0){
		l=new _lista[ilosc];
		ilosc_elementow=ilosc;
		// najpierw wypelnimi elementy wartosciami z przedzialu i uzupelniamy indexy
		for(unsigned long a=0,b=1;a<=(ilosc-1);a++,b++){
			l[a].p=0;
			l[a].n=0;
			l[a].wartosc=(rand()%(max-min)) + min; //nowe wartosci
			l[a].index=b; //indexy
		}
		// losowanie nastepnika
		l[0].p=start; // punkt startowy
		for(unsigned long i=0,a=0;i<=(ilosc-1);){ // szukamy w granicach listy
			unsigned long nastepny=rand()%(ilosc+1)+1; // losujemy index nastepnika
			if(l[nastepny].p==0){ // sprawdzamy czy przypadkiem nie wylosowalismy juz zrobionego elementu
				l[a].n=&l[nastepny].index;
				l[nastepny].p=&l[a].index;
				a=nastepny;
				i++;
			}
			if(i==(ilosc-1)){l[nastepny].n=koniec;}
		}
		ilosc_list++;
	}
}
void lista::skasuj_liste(){
	l=0;
	ilosc_elementow=0;
}
// funkcje do statystyki
void lista::dodaj_element(int poprzednik, int nastepnik, int wartosc){
	_lista *lp = new _lista[ilosc_elementow+1];
	for(int a=0;a<=ilosc_elementow;a++){
		lp[a].p=l[a].p;
		lp[a].wartosc=l[a].wartosc;
		lp[a].n=l[a].n;
	}
	*lp[ilosc_elementow+1].p=poprzednik;
	lp[ilosc_elementow+1].wartosc=wartosc;
	*lp[ilosc_elementow+1].n=nastepnik;
}
void lista::usun_element(){

}
void lista::wyszukaj_element(){

};
// inne
void lista::wyswietl_liste(){
	
};