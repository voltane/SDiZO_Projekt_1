#ifndef LISTA_HEADER
#define LISTA_HEADER
class lista{
private:
	struct _lista{
		int poprzednik;
		int wartosc;
		int nastepnik;
	};
	_lista *l;
	int ilosc_elementow, ilosc_list;
public:
	// metody potrzebne do testów
	int podaj_wartosc(int i);
	int podaj_poprzednika(int i);
	int podaj_nastepnika(int i);
	int podaj_ilosc_elementow();
	void nowa_lista(int ilosc,int min, int max, int seed);
	void skasuj_liste();
	void dodaj_element(int poprzednik, int nastepnik, int wartosc);
	void usun_element();
	void wyszukaj_element();
	lista(void);
	~lista(void);
};

#endif