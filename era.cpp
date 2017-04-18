#include <bits/stdc++.h>
using namespace std;


void eratosthenes(int N, int* arr){
  for(int i=0; i < N; i++){
    arr[i] = 1;
  }
  for(int i=2; i < sqrt(N); i++){
    if(arr[i]){
      for(int j=0; i * (j + 2) < N; j++){
        arr[i*(j+2)] = 0;
      }
    }
  }
  for(int i=2; i < N; i++){
    if(arr[i]){
      cout << i << endl;
    }
  }
}

int main(void){
  int arr[200];
eratosthenes(100, arr);
return 0;
}
