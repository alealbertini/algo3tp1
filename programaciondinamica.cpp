#include <iostream>
using namespace std;

int main ()
{
  int n, w;
  cin >> n >> w;
 
  int *tamanios = new int[n];
  int *beneficios = new int[n];

  for(int i = 0; i < n; i++){
  cin >> tamanios[i] >> beneficios[i];
  }

  // Input:

  // Values (stored in array v)

  // Weights (stored in array w)

  // Number of distinct items (n)

  // Knapsack capacity (W)

  // NOTE: The array "v" and array "w" are assumed to store all relevant values starting at index 1.


  for(int j = 0; j < w; j++){
      m[0, j] = 0;
  }

  for(int i = 1; i < n; i++){

      for(int j = 0; j < w; j++){

          if(w[i] > j){

              m[i, j] = m[i-1, j];
          } else{

              m[i, j] = max(m[i-1, j], m[i-1, j-pesos[i]] + beneficios[i]);
          }
      }
  }        

  return 0;
}