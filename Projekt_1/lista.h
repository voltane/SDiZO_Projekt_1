#ifndef LISTA_HEADER
#define LISTA_HEADER
#include <sstream>
class lista{
public:
	struct ElementListy{
		int wartosc;
		struct ElementListy *poprzedni, *nastepny;
	};
	lista(void);
	~lista(void);
	void nowaLista(int ilosc, int seed);
	void dodajNaPoczatek(ElementListy *p); // dodajemy na poczatek
	void dodajNaKoniec(ElementListy *p); // dodajemy na koniec
	void dodajWSrodku(ElementListy *element,ElementListy *poprzednik);

	ElementListy *NowyElement(int wartosc); // nowy element listy
	void UsunElement(ElementListy *element);
	ElementListy *WyszukajElement(int index);
	// interfejs
	unsigned long podajIloscElementow();
	std::string WyswietlListe();
private:
	ElementListy *glowa, *ogon, *element;
	unsigned long ilosc_elementow, ilosc_list;
};

#endif