#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;
const int N = 20; // Liczebność zbioru.
// Program główny
//---------------
int main()
{
int d[N], i, s, smin, smax; // Deklarujemy dane
// Najpierw wypełniamy tablicę d[] liczbami pseudolosowymi
// a następnie wyświetlamy jej zawartość
srand((unsigned)time(NULL));
for (i = 0; i < N; i++) d[i] = rand() % 100;
for (i = 0; i < N; i++) cout << setw(4) << d[i];
cout << endl;
// Sortujemy
smin = 0; smax = N - 1;
do
{
s = -1;
for (i = smin; i < smax; i++) {
if (d[i] > d[i + 1])
{
swap(d[i], d[i + 1]); // Zamieniamy elementy ze sobą
if (s < 0) smin = i; // Ustalamy dolną granicę
sortowanych elementów
s = i;
}
}
smin--;
smax = s;
} while (s >= 0);
// Wyświetlamy wynik sortowania
cout << "Po sortowaniu:\n\n";
for (i = 0; i < N; i++) cout << setw(4) << d[i];
cout << endl;
return 0;
}
