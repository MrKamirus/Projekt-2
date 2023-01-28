#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;
const int N = 20; // Liczebnoœæ zbioru.
// Program g³ówny
//---------------
int main()
{
	int d[N], i;
	// Najpierw wype³niamy tablicê d[] liczbami pseudolosowymi
	// a nastêpnie wyœwietlamy jej zawartoœæ
	srand((unsigned)time(NULL));
	for (i = 0; i < N; i++) d[i] = rand() % 100;
	for (i = 0; i < N; i++) cout << setw(4) << d[i];
	cout << endl;
	// Sortujemy
	int pos = 0;
	int ost_pos = 0;
	while (pos < N) {
		if (pos == 0 || d[pos] >= d[pos - 1]) {
			pos = ost_pos + 1;
			ost_pos = pos;
		}
		else {
			swap(d[pos], d[pos - 1]);
			pos = pos - 1;
		}
	}
	// Wyœwietlamy wynik sortowania
	cout << "Po sortowaniu:\n\n";
	for (i = 0; i < N; i++) cout << setw(4) << d[i];
	cout << endl;
	return 0;
}
