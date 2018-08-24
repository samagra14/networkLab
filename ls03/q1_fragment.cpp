#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[]) {
  std::string s(std::istreambuf_iterator<char>(cin), {});
  ofstream myfile;
  myfile.open ("fragmentedFile");
  int fragmentNum = 0;
  int size = s.length();
  int mtu = stoi(argv[1],NULL,10);
  while(s.length()>0){
     string temp = s.substr(0,mtu);
     myfile<<endl<<"#"<<temp.length()<<"&"<<fragmentNum<<endl;
     myfile<<temp;
     fragmentNum++;
     s.erase(0,mtu);
   }
   myfile.close();
  return 0;
}
