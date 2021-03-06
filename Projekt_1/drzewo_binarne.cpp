#include "drzewo_binarne.h"
#include <stdlib.h>
#include <sstream>
#include <iostream>

drzewo_binarne::drzewo_binarne(void)
{
	ilosc_drzew=0;
	ilosc_elementow=0;
	wskaznik=NULL;
	korzen=NULL;
}
drzewo_binarne::~drzewo_binarne(void)
{
}
void drzewo_binarne::noweDrzewo(int n, int min, int max, unsigned seed){
	wskaznik = new ElementDrzewa;
	korzen = new ElementDrzewa;
	wskaznik=korzen=utworzKorzen(rand()% + (max-min) + min);
	for(int i=1;(ilosc_elementow+1)<=n;i++){
		dodajElement(rand()% + (max-min) + min);
	};
	
};
int drzewo_binarne::podajIloscElementow(){
	return ilosc_elementow;
};
drzewo_binarne::ElementDrzewa *drzewo_binarne::podajKorzen(){ return korzen;}
void drzewo_binarne::dodajElement(ElementDrzewa *nowy){
	/* zaczynamy od korzenia i porownojemy wartos korzenia z wartoscia nowego elementu
		Jesli wartosc jest wieksza i korzen nie posiada prawego potomka = nowy element to prawy potomek
			Jesli posiada potomka idziemy do niego i sprawdzamy ponownie az nie dojdziemy do ostatniego
		Jesli natomiast wartosc jest mniejsza to sprawdzamy czy posiada lewego potomka, jak tak to idziemy do niego
			Jesli nie posiada to lewym potomkiem jest nowy element
	*/
	wskaznik = new ElementDrzewa;
	ElementDrzewa *ojciec = new ElementDrzewa;
	ojciec=NULL;
	wskaznik=korzen;
	while(wskaznik){
		ojciec=wskaznik;
		if(nowy->wartosc<wskaznik->wartosc){ wskaznik=wskaznik->potomek_l;}else wskaznik=wskaznik->potomek_p;
	}
	nowy->ojciec=ojciec;
	if(ojciec==NULL){ korzen=nowy;}else{
		if(nowy->wartosc<ojciec->wartosc){
			ojciec->potomek_l=nowy;}else ojciec->potomek_p=nowy;
	}
};
void drzewo_binarne::dodajElement(int wartosc){
	ElementDrzewa *nowy = new ElementDrzewa;
	nowy->wartosc=wartosc;
	nowy->potomek_l=NULL;
	nowy->potomek_p=NULL;
	dodajElement(nowy);
	ilosc_elementow++;
};
drzewo_binarne::ElementDrzewa *drzewo_binarne::utworzKorzen(int wartosc){
	korzen->wartosc=wartosc;
	korzen->ojciec=NULL;
	korzen->potomek_l=NULL;
	korzen->potomek_p=NULL;
	ilosc_elementow++;
	return korzen;
};
drzewo_binarne::ElementDrzewa *drzewo_binarne::podajRodzica(ElementDrzewa *p){return p->ojciec;};
drzewo_binarne::ElementDrzewa *drzewo_binarne::podajLewegoPotomka(ElementDrzewa *p){ return p->potomek_l;}
drzewo_binarne::ElementDrzewa *drzewo_binarne::podajPrawegoPotomka(ElementDrzewa *p){ return p->potomek_p;}
drzewo_binarne::ElementDrzewa *drzewo_binarne::wyszukajElement(int wartosc){
	wskaznik=korzen;
	return wyszukajElement(wskaznik,wartosc);
};
drzewo_binarne::ElementDrzewa *drzewo_binarne::wyszukajElement(ElementDrzewa *aktualny, int wartosc){
	if(aktualny==NULL||wartosc==aktualny->wartosc){ return aktualny;}
	if(wartosc<aktualny->wartosc){
		return wyszukajElement(aktualny->potomek_l,wartosc);}
	else return wyszukajElement(aktualny->potomek_p,wartosc);
	return NULL;
};
std::string drzewo_binarne::wyswietlDrzewoInOrder(std::string wynik,ElementDrzewa *p){
	std::stringstream strumien;
	if(p){
		wynik=wyswietlDrzewoInOrder(wynik,p->potomek_l);
		strumien << p->wartosc;
		wynik=wynik+" "+strumien.str();
		wynik=wyswietlDrzewoInOrder(wynik,p->potomek_p);
	}
	return wynik;
};
std::string drzewo_binarne::wyswietlElement(ElementDrzewa *p){
	std::string brak="Nie ma takiego elementu";
	if(p){
	std::stringstream strumien;
	strumien << p->wartosc;
	return strumien.str();}
	else return brak;
};
std::string drzewo_binarne::wyswietlDrzewoInOrder(){
	std::string wynik;
	wynik=wynik+wyswietlDrzewoInOrder(wynik,korzen);
	return wynik;
};