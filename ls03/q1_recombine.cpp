#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  std::string s(std::istreambuf_iterator<char>(cin), {});
  ofstream myfile;
  myfile.open ("recombinedFile");
  string delimiter = "#";
  string token;
  while(s.length()>0){
    size_t pos = s.find(delimiter);
    token = s.substr(0, pos);
    myfile<<token;
    s.erase(0,pos);
    pos = s.find("\n");
    s.erase(0,pos);
  }
  myfile.close();
  return 0;
}
