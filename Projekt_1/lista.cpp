#include "lista.h"
#include <stdlib.h>

lista::lista(void)
{
	l=0;
	ilosc_elementow=0;
	ilosc_list=0;
}


lista::~lista(void)
{
}
int lista::podaj_ilosc_elementow(){
	return ilosc_elementow;
};
int lista::podaj_wartosc(int i){
	return l[i].wartosc;
}
int lista::podaj_poprzednika(int i){
	return l[i].poprzednik;
}
int lista::podaj_nastepnika(int i){
	return l[i].nastepnik;
}
void lista::nowa_lista(int ilosc,int min, int max, int seed){
	srand(seed);
	if(l==0){
		l=new _lista[ilosc];
		ilosc_elementow=ilosc;
		// najpierw wypelnimi elementy wartosciami z przedzialu
		for(int a=0;a<=(ilosc-1);a++){
			l[a].wartosc=(rand()%(max-min)) + min;
		}
		// kazdemu elementowi dalemy poprzednika i nastepnika
		for(int a=0;a<=(ilosc-1);a++){
			int n=(rand()%ilosc);
			if(l[n].poprzednik!=0 && n!=a){ ,
				l[a].nastepnik=n;
				l[n].poprzednik=a;
			}
		}
		ilosc_list++;
	}
}
void lista::skasuj_liste(){
	l=0;
	ilosc_elementow=0;
}
void lista::dodaj_element(int poprzednik, int nastepnik, int wartosc){
	_lista *lp = new _lista[ilosc_elementow+1];
	for(int a=0;a<=ilosc_elementow;a++){
		lp[a].poprzednik=l[a].poprzednik;
		lp[a].wartosc=l[a].wartosc;
		lp[a].nastepnik=l[a].nastepnik;
	}
	lp[ilosc_elementow+1].poprzednik=poprzednik;
	lp[ilosc_elementow+1].wartosc=wartosc;
	lp[ilosc_elementow+1].nastepnik=nastepnik;
}
void lista::usun_element(){

}
void lista::wyszukaj_element(){

};