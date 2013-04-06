#include "tablica.h"


tablica::tablica(void)
{
	tab=0;
	ilosc_elementow=0;
	ilosc_tablic=0;
}
tablica::~tablica(void)
{
}
void tablica::usun_element(int i){
	int *tab2 = new int[ilosc_elementow-1];
	for(int a=0;a<=ilosc_elementow;a++){
		if(a!=i){
			tab2[a]=tab[a];
		}
	}
	tab=tab2;
	ilosc_elementow--;
};
void tablica::dodaj_element(int i){
	int *tab_pomocnicza = new int[ilosc_elementow+1];
	for(int a=0;a<=ilosc_elementow;a++){
		tab_pomocnicza[a]=tab[a];}
	tab_pomocnicza[ilosc_elementow+1]=i;
	tab=tab_pomocnicza;
	ilosc_elementow++;
};
void tablica::wyszukaj_element(int i){
	for(int a=0;a<=ilosc_elementow;a++){
		if(tab[a]=i){break;}
	}
};
void tablica::skasuj_tablice(){
	tab=0;
	ilosc_elementow=0;
};
void tablica::nowa_tablica(int ilosc){
	if(tab!=0){
		ilosc_elementow=ilosc;
		tab=new int[ilosc];
		ilosc_tablic++;
	}
};
int tablica::podaj_ilosc_elementow(){return ilosc_elementow;};
int tablica::podaj_ilosc_tablic(){return ilosc_tablic;};