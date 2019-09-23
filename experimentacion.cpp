#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctime>
#include "backtracking.cpp"
#include "fuerzabruta.cpp"
#include "programaciondinamica.cpp"

using namespace std;


int main ()
{
  int n = 30;
  int w = 150;
  extern int beneficioMaximo;
 
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


  clock_t inicioFuerzaBruta, finFuerzaBruta;
  clock_t inicioBacktracking, finBacktracking;         
  clock_t inicioPD, finPD;                 
 
  // FUERZA BRUTA
  inicioFuerzaBruta = clock();
  int resultFuerzaBruta = fuerza_bruta(pesos, beneficios, n, w);
  finFuerzaBruta = clock();  
  //cout << "RESULTADO FUERZA BRUTA: " << resultFuerzaBruta << endl;

  // BACKTRACKING
  inicioBacktracking = clock();
  pair<int, int> solucion = make_pair(0, 0);
  backtracking(pesos, beneficios, 0, n, w, solucion);
  finBacktracking = clock();
  //cout << "RESULTADO BACKTRACING: " << beneficioMaximo << endl;

  // PROGRAMACION DINAMICA
  inicioPD = clock();
  int resultDinamica = programacion_dinamica(pesos, beneficios, n, w);
  finPD = clock();
  //cout << "RESULTADO PROGRAMACION DINAMICA: " << resultDinamica << endl;
      
  double ms_totales_FB = double(finFuerzaBruta - inicioFuerzaBruta) / CLOCKS_PER_SEC; 
  double ms_totales_BT = double(finBacktracking - inicioBacktracking) / CLOCKS_PER_SEC; 
  double ms_totales_PD = double(finPD - inicioPD) / CLOCKS_PER_SEC; 

  cout << "TIEMPO FUERZA BRUTA: " << ms_totales_FB << endl;
  cout << "TIEMPO BACKTRACKING: " << ms_totales_BT << endl;
  cout << "TIEMPO PROGRAMACION DINAMICA: " << ms_totales_PD << endl;

  
  return 0;
}

