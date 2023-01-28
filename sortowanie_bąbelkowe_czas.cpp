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
 for(int N=2; N<=1000; N++){
  int d[N];
  for(int i = 0; i < N; i++) d[i] = rand() %100;
  //for(i = 0; i < N; i++) cout << setw(4) << d[i];
  //cout << endl;

  int a=0;
  auto start = chrono::steady_clock::now();
  int pos = 0;
  int ost_pos = 0;
  while (pos < N) {
    a++;
    if (pos == 0 || d[pos] >= d[pos - 1]) {
      pos = ost_pos + 1;
      ost_pos = pos;
    } else {
      swap(d[pos], d[pos - 1]);
      pos = pos - 1;
    }
  }
  auto end = chrono::steady_clock::now();
  //auto czas = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  //double czas = czas.count() * 1e-9;
  do_pliku << N << "  ";
  do_pliku << a<<endl;
 }
  //cout << "Po sortowaniu:\n\n";
  //for(i = 0; i < N; i++) cout << setw(4) << d[i];
  //cout << endl;
  return 0;
}
