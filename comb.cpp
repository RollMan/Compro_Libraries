#include <vector>

#ifdef EBUG
  #include <iostream>
  using namespace std;
#endif

std::vector< std::vector<int> > comb(int idx, int num, int lower, int upper){
  if(idx == num-1){
    std::vector< std::vector<int> > res;
    for(int i = lower; i <= upper; i++){
      res.push_back( std::vector<int>(1, i) );
    }
    return res;
  }

  std::vector< std::vector<int> > prev = comb(idx+1, num, lower, upper);
  std::vector< std::vector<int> > res;
  for(int i = 0; i < prev.size(); i++){
    std::vector<int> elem = prev[i];
    elem.push_back(0);
    for(int j = lower; j <= upper; j++){
      *(elem.end()-1) = j;
      res.push_back(elem);
    }
  }
  return res;
}

#ifdef EBUG
int main(void){
  std::vector< std::vector<int> > v = comb(0, 4, 1, 4);
  cout << v.size() << endl;
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i].size(); j++){
      if(j == 0)
        cout << v[i][j];
      else
        cout << " " << v[i][j];
    }
    cout << endl;
  }
}
#endif
