#include "lista.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>

lista::lista(void)
{
	ilosc_elementow=0;
	ilosc_list=0;
	glowa = ogon = element = NULL;
}
lista::~lista(void)
{	  
	  element = new ElementListy;
      while(glowa)
      {
        element = glowa->nastepny;
        delete glowa;
        glowa = element;
      }     
}
void lista::nowaLista(int ilosc, int seed){
	for(int i=0;i<=(ilosc-1);i++){
		element = NowyElement(i);
		dodajNaPoczatek(element);
		element = element->nastepny;
	}
};
//operacje na liscie
lista::ElementListy *lista::NowyElement(int wartosc){
	element = new ElementListy;
	element->wartosc = wartosc;
	return element;
}; 
void lista::dodajNaPoczatek(ElementListy *element){
	element->nastepny = glowa; 
	element->poprzedni = NULL;
      
	if(glowa){
		  glowa->poprzedni = element;
	}
    glowa = element;
    if(!ogon){
		  ogon = glowa;
	}
    ilosc_elementow++;
};
void lista::dodajNaKoniec(ElementListy *element){
	element->nastepny = NULL; 
	element->poprzedni = ogon;
	if(ogon){ 
		ogon->nastepny = element;
	}
    ogon = element;
	if(!glowa){
		glowa = ogon;
	}
    ilosc_elementow++;
};
void lista::dodajWSrodku(ElementListy *element, ElementListy *nastepnik){
	element->nastepny = nastepnik->nastepny; 
	element->poprzedni = nastepnik;
    nastepnik->nastepny = element;
    if(element->nastepny) element->nastepny->poprzedni = element;
    else ogon = element;
    ilosc_elementow++;
};
void lista::UsunElement(){

}
lista::ElementListy *lista::WyszukajElement(int index){
	element = new ElementListy;
	if((!index) || (index > ilosc_elementow)) return glowa;
      else if(index == ilosc_elementow) return ogon;
      else if(index < ilosc_elementow / 2)
      {
        element = glowa;
        while(--index) element = element->nastepny;
        return element;
      }
      else
      {
        element = ogon;
        while(ilosc_elementow > index++) element = element->poprzedni;
        return element;
      }  
};
// metody interfejsu
unsigned long lista::podajIloscElementow(){
	return ilosc_elementow;
};
std::string lista::WyswietlListe(){
	  std::string lista;
      ElementListy * element;
      if(glowa){
        element = glowa;
        while(element){
		  std::ostringstream strumien;
		  strumien << element->wartosc;
		  lista = lista + strumien.str() + " ";
			  element = element->nastepny;
		  strumien.clear();
		}
		return lista;
	  }
	return "Co kurwa nie dziala";
};