#include <iostream>
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

  int pesoAcumulado = 0;
  int beneficioMaximo = 0;
  int beneficioActual = 0;
  int paquetesEnLaMochila = 0;

  for(int l = 0; l < n; l++){

    pesoAcumulado = 0;
    beneficioActual = 0;
    paquetesEnLaMochila = 0;

    for(int cantElementos = 1; cantElementos <= n; cantElementos++){

      pesoAcumulado = 0;
      beneficioActual = 0;
      paquetesEnLaMochila = 0;

      for(int i = l; i < n; i++){

        paquetesEnLaMochila++;
        pesoAcumulado += pesos[i];
        beneficioActual += beneficios[i];

        for(int j = i + 1; j < n; j++){
           
           if(paquetesEnLaMochila >= cantElementos){   
                break;
           } else {
              pesoAcumulado += pesos[j];

              if(pesoAcumulado <= w){  // SI EL PAQUETE ENTRA EN LA MOCHILA, LO AGREGO

                  beneficioActual += beneficios[j];

                  if(beneficioActual > beneficioMaximo){
                     beneficioMaximo = beneficioActual;
                  }
              }
              // SI EL PAQUETE NO ENTRA EN LA MOCHILA, NO LO AGREGO Y ME FIJO SI ENTRA EL SIGUIENTE PAQUETE
           }

           pesoAcumulado -= pesos[j];
           beneficioActual -= beneficios[j];
           //cout << paquetesEnLaMochila << " " << cantElementos << endl;
           //cout << "El beneficio de " << i << " " << j << " es: " << beneficioActual << endl;
        }
      }
    }  
  }

  cout << beneficioMaximo << endl;
  return beneficioMaximo;
}

