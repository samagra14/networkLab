#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

  string s;
  cin>>s;
  if(s[0] == '1'){
    string f = "0";
    f = f+ s.substr(1);
    cout<<f<<endl;
  }
  else {
    string f = "1";
    f = f+ s.substr(1);
    cout<<f<<endl;
  }
  cin>>s;
  cout<<s;
  return 0;
}
