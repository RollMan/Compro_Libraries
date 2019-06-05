/*
 * reference: https://qiita.com/b1ueskydragon/items/0b8e0c382d782423c6d3
 */

template <typename T>
T pow_int(T x, T n){
  if(n == 0) return 1;

  T k = 1;
  while(n > 1){
    if(n%2 != 0){
      k *= x;
    }
    x *= x;
    n /= 2;
  }
  return k*x;
}
