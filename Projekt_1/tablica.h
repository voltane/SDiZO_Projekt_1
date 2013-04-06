#ifndef TABLICA_HEADER
#define TABLICA_HEADER
class tablica
{
public:
	int *tab;
	void dodaj_element();
	void usun_element();
	void nowa_tablica();
	void skasuj_tablice();
	tablica(void);
	~tablica(void);
};
#endif
