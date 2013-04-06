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
public:
	void nowa_lista(int i);
	void skasuj_liste();
	void dodaj_element();
	void usun_element();
	void wyszukaj_element();
	lista(void);
	~lista(void);
};

#endif