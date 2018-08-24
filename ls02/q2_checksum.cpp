#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, char const *argv[]) {
  int arr[argc-1] ;
  for (size_t i = 1; i < argc; i++) {
    /* code */
    string s = argv[i];
    stringstream str;
    str<<s;
    int val;
    str >> hex >>val;
    arr[i-1] = val;
  }
  int sum =0;
  for(int j =0;j<argc-1;j++){
    sum+=arr[j];
  }
  stringstream p;
  p<<hex<<sum;
  string finalSum(p.str());
  cout<<"finalSum is "<< finalSum << endl;
  if(finalSum.length()<=4){
    unsigned short answer = (short) sum;
    answer = ~answer;
    cout<<"The checksum is ";
    cout<<hex<<answer<<endl;
  }
  else {
    string carry ="";
    carry+=finalSum[0];
    string rest = finalSum.substr(1);
    int carryInt;
    int restInt;
    stringstream carryStr;
    stringstream restStr;
    carryStr<<carry;
    restStr<<rest;
    cout<<"carry "<<carry<<" rest "<< rest<<endl;
    carryStr>>hex>>carryInt;
    restStr>>hex>>restInt;
    int checkSumOne = carryInt+restInt;
    unsigned short answer = (short) checkSumOne;
    answer = ~answer;
    cout<<"The checksum is ";
    cout<<hex<<answer<<endl;
  }
  return 0;
}
