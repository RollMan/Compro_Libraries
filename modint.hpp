#include <vector>

namespace modint {
  template <typename T, T MOD, T SIZE> class Modint {
    public:
      static void initialize(){
        fac.resize(SIZE);
        finv.resize(SIZE);
        inv.resize(SIZE);
        init();
      }
      Modint(): value(0){}
      Modint(T value) : value(value){}
      Modint operator+(const Modint& a){
        return (value + a.value) % MOD;
      }
      Modint operator-(const Modint& a){
        return ((value - a.value)+MOD) % MOD;
      }
      Modint operator*(const Modint& a){
        return (value * a.value) % MOD;
      }
      Modint operator/(const Modint& a){
        return value * inv[a.value];
      }

      T value;
    private:
      static std::vector<T> fac ;
      static std::vector<T> finv;
      static std::vector<T> inv ;

      static void init(){
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i < SIZE; i++){
          fac[i] = (fac[i-1] * i) % MOD;
          inv[i] = MOD - ((inv[MOD%i] * (MOD/i)) % MOD);
          finv[i] = (finv[i-1] * inv[i]) % MOD;
        }
      }
  };
  template <typename T, T MOD, T SIZE>
  Modint<T, MOD, SIZE> combination(const Modint<T, MOD, SIZE>& n, const Modint<T, MOD, SIZE>& k){
    if(n < k) return Modint<T, MOD, SIZE>(0);
    if(n < 0 || k < 0) return Modint<T, MOD, SIZE>(0);
    return n / k / (n-k);
  }
}
