#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main ()
{
  int n, w;
  cin >> n >> w;
 
  int *pesos = new int[n];
  int *beneficios = new int[n];

  for(int i = 0; i < n; i++){
    cin >> pesos[i] >> beneficios[i];
  }

  int pesoEnLaMochila = 0;
  set< pair<int, int> > paquetesEnLaMochila;

  for(int cantElementos = 1; cantElementos < n; cantElementos++){

    paquetesEnLaMochila.clear();    // LIMPIO LA MOCHILA

    for(int i = 0; i < n; i++){

      paquetesEnLaMochila.clear();    // LIMPIO LA MOCHILA

      for(int j = i + 1; j < n; j++){
         
         if(paquetesEnLaMochila.size() >= cantElementos){   
              break;
         } else {
            if(pesoDeLaMochila(paquetesEnLaMochila) + pesos[j] <= w){  // SI EL PAQUETE ENTRA EN LA MOCHILA, LO AGREGO
                pair<int, int> paquete = make_tuple(pesos[j], beneficios[j]);
                paquetesEnLaMochila.insert(paquete);
            }
            // SI EL PAQUETE NO ENTRA EN LA MOCHILA, NO LO AGREGO Y ME FIJO SI ENTRA EL SIGUIENTE PAQUETE
         }

      }
    }
  }  

  return 0;
}

int pesoDeLaMochila(set< pair<int, int> > mochila){
    int pesoAcumulado = 0;

    for(set< pair<int, int> >::iterator it=mochila.begin(); it!=myset.end(); ++it){
        pesoAcumulado += *it.first;
    }
    return pesoAcumulado;
}

int beneficioDeLaMochila(set< pair<int, int> > mochila){
    int beneficioAcumulado = 0;

    for(set< pair<int, int> >::iterator it=mochila.begin(); it!=myset.end(); ++it){
        beneficioAcumulado += *it.second;
    }
    return beneficioAcumulado;
}