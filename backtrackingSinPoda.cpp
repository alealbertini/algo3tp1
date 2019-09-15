#include <iostream>
#include <utility>
using namespace std;


int beneficioMaximoSinPoda = 0;

pair<int, int> backtrackingSinPoda(int *arrayPesos, int *arrayBeneficios, int ij, int n, int w, pair<int, int> solucionParcial){

    if(ij == n - 1){   // ES EL ULTIMO NODO POR LO TANTO ES UNA HOJA 

        if(arrayPesos[ij] + solucionParcial.first <= w){
            
            solucionParcial.first += arrayPesos[ij];
            solucionParcial.second += arrayBeneficios[ij];
            
            //cout << "IF2 ij" << ij << " peso " << arrayPesos[ij] << " peso acum " << solucionParcial.first << " ben acum " << solucionParcial.second << /*" w " << w <<*/ endl;
            //cout << "SOL PARCIAL " << solucionParcial.second << endl;

            if(solucionParcial.second > beneficioMaximoSinPoda){
                beneficioMaximoSinPoda = solucionParcial.second;
            }
        }

        return solucionParcial;

    } else {

        for(int i = ij; i < n; i++){

            if(arrayPesos[i] + solucionParcial.first <= w){

                solucionParcial.first += arrayPesos[i];
                solucionParcial.second += arrayBeneficios[i];

                if(solucionParcial.second > beneficioMaximoSinPoda){
                    beneficioMaximoSinPoda = solucionParcial.second;
                }

                //cout << "IF " << ij << " peso " << arrayPesos[i] << " peso acum " << solucionParcial.first << " ben acum " << solucionParcial.second /*<< " w " << w*/ << endl;

                backtrackingSinPoda(arrayPesos, arrayBeneficios, i + 1, n, w, solucionParcial);

                solucionParcial.first -= arrayPesos[i];
                solucionParcial.second -= arrayBeneficios[i];

            } else {
                backtrackingSinPoda(arrayPesos, arrayBeneficios, i + 1, n, w, solucionParcial);
            }
        }
    }
}

/*
int main ()
{
  //cin >> n >> w;
  int n = 5; 
  int w = 25;
  int beneficioMaximo2 = 0;

  //int *pesos = new int[n];
  //int *beneficios = new int[n];

  //for(int i = 0; i < n; i++){
    //cin >> pesos[i] >> beneficios[i];
  //}

  int pesos [5] = { 5, 10, 10, 15, 5 };
  int beneficios [5] = { 13, 5, 8, 4, 8 };

  pair<int, int> solucion = make_pair(0, 0);  
  pair<int, int> solucionFinal = make_pair(0, 0);  

  solucionFinal = backtracking(pesos, beneficios, 0, n, w, solucion);

  if(solucionFinal.second > beneficioMaximo2){
    beneficioMaximo2 = solucionFinal.second;
  }

  cout << beneficioMaximo << endl;
  cout << beneficioMaximo2 << endl;
  cout << solucion.second << endl;
  cout << solucionFinal.second << endl;

  return beneficioMaximo;
}*/

