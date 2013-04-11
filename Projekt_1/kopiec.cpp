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
int inline kopiec::podajRodzica(double i){ int a=floor(i/2); return ktab[a];}
int inline kopiec::podajPotomka_L(int  i){ return ktab[2*i];}
int inline kopiec::podajPotomka_R(int  i){ return ktab[(2*i)+1];}
int inline kopiec::zwrocKorzen(){ return ktab[0];}
void kopiec::dodajElement(int i){
	int *pktab = new int[ilosc_elementow+1];
	for(int a=0;a<=(ilosc_elementow-1);a++){
		pktab[a]=ktab[a];}
	pktab[ilosc_elementow]=i;
	ktab=pktab;
	ilosc_elementow++;
	przywrocWlasnoscKopca(0);
}
void kopiec::nowyKopiec(int ilosc,int min, int max, int seed){
	if(ktab==0){
	ktab = new int[ilosc];
	for(int i=0;i<=(ilosc-1);i++){
		ktab[i]=(rand()% + (max-min)) + min;
	}
	ilosc_elementow=ilosc;
	ilosc_kopcow++;
	}
	przywrocWlasnoscKopca(0);
}
void kopiec::przywrocWlasnoscKopca(int i){
	int lewy = podajPotomka_L(i);
	int prawy = podajPotomka_R(i);
	int max;
	if(lewy<=ilosc_elementow && ktab[lewy]>ktab[i]){
		max=lewy;
	}else { max=i;}
	if(prawy<=ilosc_elementow && ktab[prawy]>ktab[max]){ max=prawy;}

	if(max!=i){ 
		int a=ktab[i];
		int b=ktab[max];
		ktab[i]=b;
		ktab[max]=a;
		przywrocWlasnoscKopca(max);
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
