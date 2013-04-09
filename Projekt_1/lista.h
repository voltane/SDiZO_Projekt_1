#ifndef LISTA_HEADER
#define LISTA_HEADER
class lista{
private:
	struct _lista{
		unsigned long *p;
		int wartosc;
		unsigned long *n;
		unsigned long index;
	};
	_lista *l;
	unsigned long ilosc_elementow, ilosc_list;
	unsigned long *start,*koniec;
	
public:
	// metody potrzebne do testów
	void wyswietl_liste();
	int podaj_wartosc(unsigned long i);
	unsigned long podaj_poprzednika(int i);
	unsigned long podaj_nastepnika(int i);
	unsigned long podaj_ilosc_elementow();
	//glowne metody
	void nowa_lista(int ilosc,int min, int max, int seed);
	void skasuj_liste();
	void dodaj_element(int poprzednik, int nastepnik, int wartosc);
	void usun_element();
	void wyszukaj_element();
	lista(void);
	~lista(void);
};

#endif