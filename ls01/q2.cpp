#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char const *argv[]) {
  if(argc<=0){
    cout<<" No input detected "<<endl;
  }
  else {
    if(argc != 4){
      cout<<" Unsupported format  "<<endl;
    }
    int a = argv[1][0]-'0';
    char b = argv[2][0];
    int c = argv[3][0]-'0';
    int result;
    if(b=='+'){
      result = a+c;
      cout<<"The result is "<<result<<endl;
    }
    else if(b=='-'){
      result == a-c;
      cout<<"The result is "<<result<<endl;
    }
    else if(b=='*'){
      result == a*c;
      cout<<"The result is "<<result<<endl;
    }
    if(b=='/'){
      if(c==0){
        cout<<"Division by 0 not supported "<<endl;
        return 0;
      }
      result == a/c;
      cout<<"The result is "<<result;
    }
  }
  return 0;
}
