#include "kopiec.h"
#include <math.h>
#include <sstream>
#include <stdlib.h>

kopiec::kopiec(void)
{
	ktab=0;
	ilosc_elementow = 0;
	ilosc_kopcow = 0;
}
kopiec::~kopiec(void)
{
}
int inline kopiec::podajRodzica(double i){ return floor(i/2);}
int inline kopiec::podajPotomka_L(int i){ return 2*i;}
int inline kopiec::podajPotomka_R(int i){ return (2*i)+1;}
int kopiec::zwrocKorzen(){ return ktab[0];}
int kopiec::zwrocIloscElementow(){ return (ilosc_elementow-1);}
void kopiec::dodajElement(int i){
	int *pktab = new int[ilosc_elementow+1];
	for(int a=0;a<=(ilosc_elementow-1);a++){
		pktab[a]=ktab[a];}
	pktab[ilosc_elementow]=i;
	ktab=pktab;
	ilosc_elementow++;
	przywrocWlasnoscKopca(ilosc_elementow-1);
}
void kopiec::nowyKopiec(int ilosc,int min, int max, int seed){
	if(ktab!=0){ usunKopiec();}
	ktab = new int[ilosc];
	for(int i=0;i<=(ilosc-1);i++){
		ktab[i]=(rand()% + (max-min)) + min;
	}
	ilosc_elementow=ilosc;
	ilosc_kopcow++;
	przywrocWlasnoscKopca(ilosc-1);
}
void kopiec::usunKopiec(){
	for(int i=0;i<=(ilosc_elementow-1);i++){
		ktab[i]=NULL;
	};
	delete ktab;
};

// przywracanie wlasnosci kopca tylko w elemencie ktory ma potomków!
void kopiec::przywrocWlasnoscKopca(int i){
	/* przywracamy wartosc calego kopca
	   zaczynamy od pierwszego, dolnego rodzica i idziemy w góre
	   parametrem jest index pierwszego rodzica!!
	   */
	int a=i; // index ostatnie elemetu, nie rodzica!
	a = podajRodzica(a); // idziemy do rodzica ostatniego elementu
	while(a){ // az do 0
		przywrocWlasnosc(a);
		a--;
	}
	if(a==0){ //kiedy rodzicem jest korzen
		przywrocWlasnoscKorzenia();
	}
}
// przywracanie wlasnosci kopca od rodzica podanego elementu
void kopiec::przywrocWlasnoscKorzenia(){
	// pracujemy na korzeniu
	int lewy = 1;// index lewego potomka
	int prawy = 2;// index prawego potomka
	int max;
	if(prawy<=ilosc_elementow && ktab[prawy]>ktab[0]){
		max=prawy;
	}else { max=0;}
	if(lewy<=ilosc_elementow && ktab[lewy]>ktab[max]){ max=lewy;}
	// ewentualna zamiana miejscami z wartoscia max
	if(max!=0){ 
		int a=ktab[0];
		int b=ktab[max];
		ktab[0]=b;
		ktab[max]=a;
		przywrocWlasnosc(max); // rekurencyjne wywolanie funkcji dla zmienionej wartosci
	}
};
void kopiec::przywrocWlasnosc(int i){
	// parametr to index rodzica!
	// prawdzanie wlasnosci kopca dla rodzica i jego potomkow
	int lewy = podajPotomka_L(i);
	int prawy = podajPotomka_R(i);
		int max;
		if(prawy<=ilosc_elementow && ktab[prawy]>ktab[i]){
			max=prawy;
		}else { max=i;}
		if(lewy<=ilosc_elementow && ktab[lewy]>ktab[max]){ max=lewy;}
	// ewentualna zamiana miejscami z wartoscia max
		if(max!=i){ 
			int a=ktab[i];
			int b=ktab[max];
			ktab[i]=b;
			ktab[max]=a;
			przywrocWlasnosc(max); // rekurencyjne wywolanie funkcji dla zmienionej wartosci
		}
}
std::string kopiec::wyswietlKopiec(){
	std::string kopiec;
	for(int i=0;i<=(ilosc_elementow-1);i++){
		  std::ostringstream strumien;
		  strumien << ktab[i];
		  kopiec = kopiec + strumien.str() + " ";
		  strumien.clear();
		}
		return kopiec;
}
std::string kopiec::sprawdzKopcowanie(){
	int max = zwrocKorzen();
	std::string tak,nie;
	tak="Kopiec jest MAX.";
	nie="Kopiec nie jest MAX.";
	for(int i=1;i<=(ilosc_elementow-1);i++){
		if(ktab[i]>max){ return nie;}
	}
	return tak;
};
