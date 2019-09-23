#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctime>
#include "backtracking.cpp"
#include "programaciondinamica.cpp"

using namespace std;


int main ()
{
  int n = 20;
  int w = 15;
  extern int beneficioMaximoBT;

  int pesos[n] = { 9, 6, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20 };
  int beneficios[n] = { 38, 40, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

  clock_t inicioDinamica, finDinamica;
  clock_t inicioBT, finBT;              
 
  // DINAMICA
  inicioDinamica = clock();
  pair<int, int> solucionDinamica = make_pair(0, 0);
  int resultDinamica = programacion_dinamica(pesos, beneficios, n, w);
  finDinamica = clock();  
  //cout << "RESULTADO DINAMICA: " << resultDinamica << endl;

  // BACKTRACKING 
  inicioBT = clock();
  pair<int, int> solucion = make_pair(0, 0);
  backtracking(pesos, beneficios, 0, n, w, solucion);
  finBT = clock();
  //cout << "RESULTADO BACKTRACING: " << beneficioMaximo << endl;

      
  double ms_totales_Dinamica= double(finDinamica - inicioDinamica) / CLOCKS_PER_SEC; 
  double ms_totales_BT = double(finBT - inicioBT) / CLOCKS_PER_SEC; 

  cout << "TIEMPO DINAMICA: " << ms_totales_Dinamica << endl;
  cout << "TIEMPO BACKTRACKING: " << ms_totales_BT << endl;
 
  return 0;
}

