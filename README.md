SDiZO_Projekt_1
===============

Repozytorium pierwszego projektu z SDiZO
===============
Tresc zalozen projektu:
===============
1. Badanie efektywności operacji dodawania, usuwania oraz wyszukiwania elementów w 
różnych strukturach danych.
Należy zaimplementować oraz dokonać pomiaru czasu działania operacji: dodawania elementu, 
usunięcia elementu, wyszukania elementu, w następujących strukturach danych:
a. Tablica,
b. Lista,
c. Kopiec binarny,
d. Drzewo czerwono-czarne,
e. Drzewo AVL1
.
Należy przyjąć, że powyższe struktury danych przechowują liczby całkowite (np. typu int). Tablica 
powinna być alokowana dynamicznie i w każdym momencie czasu zajmować jak najmniejszą ilość 
pamięci (realokacja przy dodawaniu i usuwaniu elementów). Pozostałe struktury też powinny być 
dynamiczne. Po zaimplementowaniu struktur, należy dokonać pomiaru czasu wykonywania 
operacji dodawania, usuwania i wyszukiwania elementów, w zależności od rozmiaru struktury 
(liczby elementów w niej przechowywanych). Jako, że pojedynczy pomiar jest niemiarodajny,należy pomiary wykonywać kilkakrotnie (np. 10 razy) i wyniki uśredniać. Należy też zwrócić 
uwagę na to, że czas wykonywania powyższych operacji może zależeć od wartości 
przechowywanych elementów, co też należy uwzględnić w pomiarach. Zakres wielkości struktur 
(ilość przechowywanych elementów) należy dobrać eksperymentalnie ze względu na różną 
wydajność komputerów.
Pomiaru czasu można dokonać na wiele różnych sposobów. Począwszy od prostych 
korzystających z biblioteki time.h (funkcja Clock()), a skończywszy na bardziej zaawansowanych 
związanych z pomiarem czasu w danym systemie operacyjnym (np. GetThreadTimes w systemie 
Widnows).
Dopuszczalnymi językami programowania są języki kompilowane do kodu natywnego (np. C, 
C++), a nie interpretowane lub uruchamiane na maszynach wirtualnych (np. JAVA, języki .NET, 
Python). Nie wolno używać bibliotek typu STL, Boost, itp. Można natomiast przeprowadzić 
porównanie efektywności waszych implementacji z tymi z dostępnych bibliotek.
Sprawozdanie powinno zawierać:
 plan eksperymentu - jakie przyjęto założenia co do wielkości struktur, sposobie 
generowania elementów tych struktur, sposobie pomiaru czasu, itp.
 wyniki pomiarów w zestawieniach tabelarycznych/wykresach osobno dla 
poszczególnych operacji,
 wnioski dotyczące efektywności poszczególnych struktur w zależności od zastosowań, 
wielkości struktury itp.,
 Załączony kod źródłowy w formie elektronicznej (płyta CD) - nie drukować kodu w 
sprawozdaniu, dopuszczalne są tylko istotne dla sprawozdania fragmenty kodu.
==========================
Podjete decyzje:
1. Biblioteka uzywana do pomiaru czasu to <time.h>
2. 
