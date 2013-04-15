#include "drzewo_binarne.h"
#include <stdlib.h>
#include <sstream>

drzewo_binarne::drzewo_binarne(void)
{
	ilosc_drzew=0;
	ilosc_elementow=0;
	wskaznik=NULL;
}


drzewo_binarne::~drzewo_binarne(void)
{
}

void drzewo_binarne::noweDrzewo(int n, int min, int max, unsigned seed){
	*wskaznik=utworzKorzen(rand()% + (max-min) + min);
	for(int i=1;i<=n;i++){
		dodajElement(rand()% + (max-min) + min);
	};
	
};
drzewo_binarne::ElementDrzewa drzewo_binarne::dodajElement(int wartosc){
	/* zaczynamy od korzenia i porownojemy wartos korzenia z wartoscia nowego elementu
		Jesli wartosc jest wieksza i korzen nie posiada prawego potomka = nowy element to prawy potomek
			Jesli posiada potomka idziemy to niego i sprawdzamy ponownie az nie dojdziemy do ostatniego
		Jesli natomiast wartosc jest mniejsza to sprawdzamy czy posiada lewego potomka, jak tak to idziemy do niego
			Jesli nie posiada to lewym potomkiem jest nowy element
	*/
	ElementDrzewa *nowy;
	nowy->wartosc=wartosc;
	if(wartosc<=wskaznik->wartosc){
		if(podajLewegoPotomka){ 
			wskaznik=podajLewegoPotomka(wskaznik);
			dodajElement(wartosc);
		}else{
			nowy->ojciec=wskaznik;
			wskaznik->potomek_l=nowy;
			nowy->potomek_l=NULL;
			nowy->potomek_p=NULL;
			ilosc_elementow++;}
	}
	if(wartosc>=wskaznik->wartosc){
		if(podajPrawegoPotomka){
			wskaznik=podajPrawegoPotomka(wskaznik);
			dodajElement(wartosc);
		}else{
			nowy->ojciec=wskaznik;
			wskaznik->potomek_p=nowy;
			nowy->potomek_l=NULL;
			nowy->potomek_p=NULL;
		    ilosc_elementow++;}
	}
};
drzewo_binarne::ElementDrzewa drzewo_binarne::utworzKorzen(int wartosc){
	korzen->wartosc=wartosc;
	korzen->ojciec=NULL;
	korzen->potomek_l=NULL;
	korzen->potomek_p=NULL;
	ilosc_elementow++;
	return *korzen;
};
drzewo_binarne::ElementDrzewa *drzewo_binarne::podajRodzica(ElementDrzewa *p){return p->ojciec;};
drzewo_binarne::ElementDrzewa *drzewo_binarne::podajLewegoPotomka(ElementDrzewa *p){ return p->potomek_l;}
drzewo_binarne::ElementDrzewa *drzewo_binarne::podajPrawegoPotomka(ElementDrzewa *p){ return p->potomek_p;}
std::string drzewo_binarne::wyswietlDrzewo(){
	std::string drzewo="";
	ElementDrzewa *wyswietlany_element;
	wyswietlany_element=korzen;
	
	return drzewo;
};