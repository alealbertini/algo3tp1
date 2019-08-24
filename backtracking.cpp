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

  /*cout << "n: " << n << "w: " << w << endl;

  for(int i = 0; i < n; i++){
  cout << tamanios[i] << beneficios[i] << endl;
  }*/

  return 0;
}