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
}
