#include <iostream>
#include <utility>
using namespace std;


int beneficioMaximo = 0;

pair<int, int> backtracking(int *arrayPesos, int *arrayBeneficios, int ij, int n, int w, pair<int, int> solucionParcial){

    if(ij == n - 1){   // ES EL ULTIMO NODO POR LO TANTO ES UNA HOJA 

        if(arrayPesos[ij] + solucionParcial.first <= w){
            
            solucionParcial.first += arrayPesos[ij];
            solucionParcial.second += arrayBeneficios[ij];
            
            //cout << "IF2 ij" << ij << " peso " << arrayPesos[ij] << " peso acum " << solucionParcial.first << " ben acum " << solucionParcial.second << /*" w " << w <<*/ endl;
            //cout << "SOL PARCIAL " << solucionParcial.second << endl;

            if(solucionParcial.second > beneficioMaximo){
                beneficioMaximo = solucionParcial.second;
            }
        }

        return solucionParcial;

    } else {

        for(int i = ij; i < n; i++){
            
            // PODA POR FACTIBILIDAD: SI YA NO HAY MAS ESPACIO EN LA MOCHILA Y EL BENEFICIO ACUMULADO ES MENOR QUE EL BENEFICIO MAXIMO
            // NO TIENE SENTIDO SEGUIR PROBANDO CON ESTA COMBINACION YA QUE NO HAY ESPACIO Y NO SE VA A SUPERAR EL BENEFICIO MAXIMO.
            if(w - solucionParcial.first == 0){
                if(solucionParcial.second > beneficioMaximo){
                    beneficioMaximo = solucionParcial.second;
                }
                break;
            }
            // FIN DE PODA POR FACTIBILIDAD

            // PODA POR OPTIMALIDAD: ME FIJO SI SIGO ITERANDO VOY A LLEGAR A ACUMULAR UN BENEFICIO MAYOR DEL BENEFICIO MAXIMO.
            // SI EL BENEFICIO TOTAL QUE VOY A ACUMULAR ES MENOR QUE EL BENEFICIO MAXIMO, NO TIENE SENTIDO SEGUIR HASTA EL FINAL.
            int sumaBeneficioFuturo = solucionParcial.second;
            for(int j = ij; j < n; j++){
                sumaBeneficioFuturo += arrayBeneficios[j];
            }

            if(sumaBeneficioFuturo < beneficioMaximo){
                break;
            }
            // FIN PODA POR OPTIMALIDAD

            if(arrayPesos[i] + solucionParcial.first <= w){

                solucionParcial.first += arrayPesos[i];
                solucionParcial.second += arrayBeneficios[i];

                if(solucionParcial.second > beneficioMaximo){
                    beneficioMaximo = solucionParcial.second;
                }

                //cout << "IF " << ij << " peso " << arrayPesos[i] << " peso acum " << solucionParcial.first << " ben acum " << solucionParcial.second /*<< " w " << w*/ << endl;

                backtracking(arrayPesos, arrayBeneficios, i + 1, n, w, solucionParcial);

                solucionParcial.first -= arrayPesos[i];
                solucionParcial.second -= arrayBeneficios[i];

            } else {
                backtracking(arrayPesos, arrayBeneficios, i + 1, n, w, solucionParcial);
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

