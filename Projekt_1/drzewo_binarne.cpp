#include "drzewo_binarne.h"
#include <stdlib.h>
#include <sstream>

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
	for(int i=1;i<=n;i++){
		wskaznik=korzen;
		dodajElement(rand()% + (max-min) + min);
	};
	
};
drzewo_binarne::ElementDrzewa *drzewo_binarne::podajKorzen(){ return korzen;}
drzewo_binarne::ElementDrzewa drzewo_binarne::dodajElement(int wartosc){
	/* zaczynamy od korzenia i porownojemy wartos korzenia z wartoscia nowego elementu
		Jesli wartosc jest wieksza i korzen nie posiada prawego potomka = nowy element to prawy potomek
			Jesli posiada potomka idziemy do niego i sprawdzamy ponownie az nie dojdziemy do ostatniego
		Jesli natomiast wartosc jest mniejsza to sprawdzamy czy posiada lewego potomka, jak tak to idziemy do niego
			Jesli nie posiada to lewym potomkiem jest nowy element
	*/
	ElementDrzewa *nowy = new ElementDrzewa;
	nowy->wartosc=wartosc;
	if(wartosc<=wskaznik->wartosc){
		if(podajLewegoPotomka(wskaznik)){ 
			wskaznik=podajLewegoPotomka(wskaznik);
			dodajElement(wartosc);
		}else{
			nowy->ojciec=wskaznik;
			wskaznik->potomek_l=nowy;
			nowy->potomek_l=NULL;
			nowy->potomek_p=NULL;
			ilosc_elementow++;
			return *nowy;}
	}
	if(wartosc>=wskaznik->wartosc){
		if(podajPrawegoPotomka(wskaznik)){
			wskaznik=podajPrawegoPotomka(wskaznik);
			dodajElement(wartosc);
		}else{
			nowy->ojciec=wskaznik;
			wskaznik->potomek_p=nowy;
			nowy->potomek_l=NULL;
			nowy->potomek_p=NULL;
		    ilosc_elementow++;
			return *nowy;}
	}
	return *nowy;
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
	ElementDrzewa *szukany = new ElementDrzewa;
	wskaznik=korzen;
	while(wskaznik){
		if(wskaznik->wartosc==wartosc){ return wskaznik;}
		if(wskaznik->wartosc<wartosc){ wskaznik=wskaznik->potomek_p;}
		if(wskaznik->wartosc>wartosc){ wskaznik=wskaznik->potomek_l;}
	}
	return wskaznik;
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
