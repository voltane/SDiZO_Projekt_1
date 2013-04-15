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
	 int zwrocKorzen();
	 int zwrocIloscElementow();
	 void dodajElement(int i);
	 int usunKorzen();
	 void przywrocWlasnoscKorzenia();
	 void przywrocWlasnoscKopca(int i); // przywracanie wlasnosci calego kopca, od ostatniego elementu
	 void przywrocWlasnosc(int i); // przywracanie wlasnosci od podanego rodzica
	 // inne operacje
	 void nowyKopiec(int ilosc,int min, int max, int seed);
	 void usunKopiec();
	 std::string wyswietlKopiec();
	 std::string sprawdzKopcowanie();


};

#endif