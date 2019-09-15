#include <iostream>
#include <algorithm>
using namespace std;

int programacion_dinamica(int *pesos, int *beneficios, int n, int w){
    
    int values[n+1][w+1];

    for(int c = 0; c <= w; c++){
        values[0][c] = 0;
    }

    for(int j = 1; j <= n; j++){
        values[j][0] = 0;
    }

    for(int j = 1; j <= n; j++){

        for(int c = 1; c <= w; c++){

          if(c < pesos[j-1]){

            values[j][c] = values[j-1][c];
          } else{

            values[j][c] = max(values[j-1][c], values[j-1][c-pesos[j-1]] + beneficios[j-1]);
          }
        }
    }

    /*for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
          cout << values[i][j] << " ";
        }
        cout << endl;
    } */       

    //cout << values[n - 1][w - 1] << endl;
    return values[n][w];
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