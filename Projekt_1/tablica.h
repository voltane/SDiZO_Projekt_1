#ifndef TABLICA_HEADER
#define TABLICA_HEADER
class tablica{
private:
	int *tab, ilosc_tablic, ilosc_elementow;	 //wszystkie potrzebne statystyki
public:
	// metody potrzebne do pomiarów
	void dodaj_element(int i);					 
	void usun_element(int i);	
	void wyszukaj_element(int i);
	// metody pozwalajace pracowac na jednym obiekcie (mniej kodu)
	void nowa_tablica(int ilosc,int min, int max, int seed);				 
	void skasuj_tablice();					
	// metody do statystyk
	int podaj_ilosc_elementow();				
	int podaj_ilosc_tablic();
	// konstruktory itd
	tablica(void);
	~tablica(void);
};
#endif
