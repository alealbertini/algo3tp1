#include <iostream>
#include <utility>
using namespace std;


pair<int, int> backtracking(int *arrayPesos, int *arrayBeneficios, int ij, int n, int w, pair<int, int> solucionParcial){

    if(ij == n - 1){   // ES EL ULTIMO NODO POR LO TANTO ES UNA HOJA 

        if(arrayPesos[ij] + solucionParcial.first <= w){
            solucionParcial.first += arrayPesos[ij];
            solucionParcial.second += arrayBeneficios[ij];
            return solucionParcial;
        }
    } else {

        if(arrayPesos[ij] + solucionParcial.first <= w){
            solucionParcial.first += arrayPesos[ij];
            solucionParcial.second += arrayBeneficios[ij];
        }   // PODA: SI ESTE NODO NO ENTRA NO SIRVE SEGUIR PROBANDO CON ESTA COMBINACION

        backtracking(arrayPesos, arrayBeneficios, ij + 1, n, w, solucionParcial);
    }
}


int main ()
{
  int n, w;
  //cin >> n >> w;
  n = 5; w = 25;
  /*int *pesos = new int[n];
  int *beneficios = new int[n];

  for(int i = 0; i < n; i++){
    cin >> pesos[i] >> beneficios[i];
  }*/

  int pesos [5] = { 10, 15, 5, 10, 5 };
  int beneficios [5] = { 5, 4, 13, 8, 8 };

  int beneficioMaximo = 0;
  pair<int, int> solucion = make_pair(0, 0);  

  for(int i = 0; i < n; i++){

      pair<int, int> sol = backtracking(pesos, beneficios, i, n, w, solucion);

      if(sol.second > beneficioMaximo){
          beneficioMaximo = sol.second;
      }
  } 

  cout << beneficioMaximo << endl;
  return beneficioMaximo;
}

