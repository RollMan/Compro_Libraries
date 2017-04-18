#include <string>
#include <vector>

std::vector<std::string> split(std::string str, std::string sep){
  std::vector<std::string> res;
  size_t begin = 0;
  while(1){
    size_t pos = str.find(sep, begin);
    if(pos == std::string::npos) break;
    res.push_back( str.substr(begin, pos-begin) );
    begin = pos + sep.size();
  }
  res.push_back( str.substr(begin, str.length() - begin) );
  return res;
}

#ifdef  EBUG
#include <iostream>
using namespace std;

int main(void){
  string str = "abc def ghi jkl";
  vector<string> v = split(str, "bc");
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }
  return 0;
}
#endif
