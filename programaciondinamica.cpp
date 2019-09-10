#include <iostream>
#include <algorithm>
using namespace std;

int programacion_dinamica(int *pesos, int *beneficios, int n, int w){
    
    int values[n][w];

    for(int c = 0; c < w; c++){
        values[0][c] = 0;
    }

    for(int j= 1; j < n; j++){
        values[j][0] = 0;
    }

    for(int i = 1; i < n; i++){

        for(int j = 0; j < w; j++){

          if(j < pesos[i]){

            values[i][j] = values[i-1][j];
          } else{

            values[i][j] = max(values[i-1][j], values[i-1][j-pesos[i]] + beneficios[i]);
          }
        }
    }

    /*for(int i = 1; i < n; i++){
        for(int j = 0; j < w; j++){
          cout << "i: " << i << " j: " << j << " value: " << values[i][j] << endl;
        }
    }*/          

    //cout << values[n - 1][w - 1] << endl;
    return values[n - 1][w - 1];
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

  int result = programacion_dinamica(pesos, beneficios, n, w);

  cout << "EL RESULTADO ES: " << result << endl;
}
*/