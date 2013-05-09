#ifndef DRZEWO_BINARNE_H
#define DRZEWO_BINARNE_H

#include <string>

class drzewo_binarne
{
public:
	struct ElementDrzewa{
		int wartosc;
		ElementDrzewa *potomek_l,*potomek_p,*ojciec;
	};
	ElementDrzewa *wskaznik;
	void noweDrzewo(int n, int min, int max, unsigned seed);
	ElementDrzewa *podajRodzica(ElementDrzewa *p);
	ElementDrzewa *podajPrawegoPotomka(ElementDrzewa *p);
	ElementDrzewa *podajLewegoPotomka(ElementDrzewa *p);
	void dodajElement(int wartosc);
	ElementDrzewa *utworzKorzen(int wartosc);
	ElementDrzewa *wyszukajElement(int wartosc);
	ElementDrzewa *podajKorzen();
	int podajIloscElementow();
	std::string wyswietlDrzewoInOrder();
	std::string wyswietlElement(ElementDrzewa *p);
	drzewo_binarne(void);
	~drzewo_binarne(void);
private:
	int ilosc_drzew, ilosc_elementow;
	ElementDrzewa *korzen,*ostatni_element;
	ElementDrzewa *wyszukajElement(ElementDrzewa *aktualny, int wartosc);
	void dodajElement(ElementDrzewa *nowy);
	std::string wyswietlDrzewoInOrder(std::string wynik, ElementDrzewa *p);
};
#endif
