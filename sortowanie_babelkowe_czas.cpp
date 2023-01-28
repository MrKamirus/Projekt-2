#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

const int N = 20; // Liczebnoœæ zbioru.

// Program g³ówny
//---------------

int main()
{


    ofstream do_pliku("czas.txt");
    srand((unsigned)time(NULL));
    for (int N = 2; N <= 1000; N++) {
		int d[N], i, s, smin, smax; // Deklarujemy dane
        for (int i = 0; i < N; i++) d[i] = rand() % 100;
        //for(i = 0; i < N; i++) cout << setw(4) << d[i];
        //cout << endl;
        int a = 0;
        auto start = chrono::steady_clock::now();
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
        auto end = chrono::steady_clock::now();
        //auto czas = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        //double czas = czas.count() * 1e-9;
        do_pliku << N << "  ";
        do_pliku << a << endl;
    }
    //cout << "Po sortowaniu:\n\n";
    //for(i = 0; i < N; i++) cout << setw(4) << d[i];
    //cout << endl;
    return 0;
}
