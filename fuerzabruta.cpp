#include <iostream>
#include <utility>
using namespace std;

int fuerza_bruta(int *pesos, int *beneficios, int n, int w){
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

          if(beneficioActual > beneficioMaximo){
              beneficioMaximo = beneficioActual;
          }

          for(int j = i + 1; j < n; j++){
             
             if(paquetesEnLaMochila >= cantElementos){
                break;
             } else {
                pesoAcumulado += pesos[j];    // TODO: REVISAR ESTO, NO DEBERIA HACER LAS OPERACIONES DE PESO Y BENEFICIO JUNTAS?

                if(pesoAcumulado <= w){  // SI EL PAQUETE ENTRA EN LA MOCHILA, LO AGREGO

                    beneficioActual += beneficios[j];
                    paquetesEnLaMochila++;

                    if(beneficioActual > beneficioMaximo){
                       beneficioMaximo = beneficioActual;
                    }
                }else{
                  pesoAcumulado -= pesos[j];  // SI EL PAQUETE NO ENTRA EN LA MOCHILA, NO LO AGREGO Y ME FIJO SI ENTRA EL SIGUIENTE PAQUETE
                }
             }

             pesoAcumulado -= pesos[j];
             beneficioActual -= beneficios[j];
             paquetesEnLaMochila--;
             //cout << paquetesEnLaMochila << " " << cantElementos << endl;
             //cout << "El beneficio de " << i << " " << j << " es: " << beneficioActual << endl;
          }
        }
      }  
    }

    //cout << beneficioMaximo << endl;
    return beneficioMaximo;
}

/*
int main ()
{
  int n, w;
  cin >> n >> w;
 
  int *pesos = new int[n];
  int *beneficios = new int[n];

  for(int i = 0; i < n; i++){
    cin >> pesos[i] >> beneficios[i];
  }

  int result = fuerza_bruta(pesos, beneficios, n, w);

  cout << "EL RESULTADO ES: " << result << endl;
}
*/


