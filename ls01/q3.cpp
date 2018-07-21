#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  pid_t pid = fork();
  if(pid >0){
    cout<<"This is a parent "<<getpid()<<endl;
  }
  else {
    cout<<"This is a child "<<getpid()<<endl;
  }
  return 0;
}
