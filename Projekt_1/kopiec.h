#ifndef KOPIEC_HEADER
#define KOPIEC_HEADER
#include <sstream>
class kopiec{
 public:
	 // kopiec przedstawimy za pomoca tablicy
	 // bierzemy pod uwage tylko kopiex MAX
private:
     int *ktab, ilosc_elementow, ilosc_kopcow;
	 int inline podajRodzica(double i);
	 int inline podajPotomka_R(int i);
	 int inline podajPotomka_L(int i);
public:
	 kopiec();
	 ~kopiec();
	 // operacje na kopcu
	 int inline zwrocKorzen();
	 void dodajElement(int i);
	 int usunKorzen();
	 void przywrocWlasnoscKopca(int i);
	 // inne operacje
	 void nowyKopiec(int ilosc,int min, int max, int seed);
	 std::string wyswietlKopiec();


};

#endif