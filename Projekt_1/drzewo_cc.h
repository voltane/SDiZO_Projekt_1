#ifndef DRZEWO_CZERWONO_CZARNE_HEADER
#define DRZEWO_CZERWONO_CZARNE_HEADER

class drzewo_cc{
public:
	struct ElementDrzewa{
		int kolor;
		int wartosc;
		ElementDrzewa *potomek_l,*potomek_p;
	};
	drzewo_cc(void);
	~drzewo_cc(void);
};
#endif