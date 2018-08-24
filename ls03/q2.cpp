#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  string arr[4];
  for(int i = 1;i<argc;i++){
    string temp = argv[i];
    int x = std::stoi(temp,NULL,10);
    stringstream s;
    s<<hex<<x;
    arr[i-1] = s.str();
    if(arr[i-1].length() == 1){
      arr[i-1] = "0"+arr[i-1];
    }
  }
  cout<<2002<<":"<<arr[0]<<arr[1]<<":"<<arr[2]<<arr[3]<<"::"<<"1/64"<<endl;
  return 0;
}
