#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctime>
#include "backtracking.cpp"
#include "backtrackingSinPoda.cpp"

using namespace std;


int main ()
{
  int n = 25;
  int w = 150;
  extern int beneficioMaximo;
  extern int beneficioMaximoSinPoda;
 
  int *pesos = new int[n];
  int *beneficios = new int[n];

  srand(time(NULL));

  for(int i = 0; i < n; i++){
    pesos[i] = rand() % 30;
    beneficios[i] = rand() % 30;
  }

  /*for(int i = 0; i < n; i++){
    cout << "p: " << pesos[i] << " b: " << beneficios[i] << endl;
  }*/

  clock_t inicioBTSinPoda, finBacktrackingSinPoda;
  clock_t inicioBT, finBT;              
 
  // BACKTRACKING SIN PODA
  inicioBTSinPoda = clock();
  pair<int, int> solucionSinPoda = make_pair(0, 0);
  backtrackingSinPoda(pesos, beneficios, 0, n, w, solucionSinPoda);
  finBacktrackingSinPoda = clock();  
  cout << "RESULTADO BACKTRACKING SIN PODA: " << beneficioMaximoSinPoda << endl;

  // BACKTRACKING 
  inicioBT = clock();
  pair<int, int> solucion = make_pair(0, 0);
  backtracking(pesos, beneficios, 0, n, w, solucion);
  finBT = clock();
  cout << "RESULTADO BACKTRACKING: " << beneficioMaximo << endl;

      
  double ms_totales_BT_Sin_Poda = double(finBacktrackingSinPoda - inicioBTSinPoda) / CLOCKS_PER_SEC; 
  double ms_totales_BT = double(finBT - inicioBT) / CLOCKS_PER_SEC; 

  cout << "TIEMPO BACKTRACKING SIN PODA: " << ms_totales_BT_Sin_Poda << endl;
  cout << "TIEMPO BACKTRACKING: " << ms_totales_BT << endl;

  return 0;
}

