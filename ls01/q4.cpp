#include <iostream>
#include <unistd.h>
using namespace std;
int main(int argc, char const *argv[]) {
  cout<<"This is parent "<<getpid()<<endl;
  pid_t pidOne = fork();
  if(pidOne ==0){
    cout<<"This is child one "<<getpid()<<endl;
    pid_t grandChildOne = fork();
    if(grandChildOne==0){
      cout<<"This is grandchild one "<<getpid()<<endl;
    }
    else {
      pid_t granndChildTwo = fork();
      if(granndChildTwo==0){
        cout<<"This is grandchild two "<<getpid()<<endl;
      }
    }

  }
  else {
    pid_t pidTwo = fork();
    if(pidTwo ==0){
      cout<<"This is child two "<<getpid()<<endl;
      pid_t grandChildOne = fork();
      if(grandChildOne==0){
        cout<<"This is grandchild three "<<getpid()<<endl;
      }
      else {
        pid_t granndChildTwo = fork();
        if(granndChildTwo==0){
          cout<<"This is grandchild four "<<getpid()<<endl;
        }
      }
  }
}
  return 0;
}
