#include <iostream>
using namespace std;

string xorFun(string a , string b){
  string answer = "";
  for (size_t i = 1; i < b.length(); i++) {
    /* code */
    if(a[i]==b[i]){
      answer +="0";
    }
    else
      answer+="1";
  }
  return answer;
}

string modToDiv(string dividend, string divisor){
  int pick = divisor.length();
  string temp = dividend.substr(0,pick);
  while(pick<dividend.length()){
    if(temp[0] == '1'){
      temp = xorFun(divisor,temp) + dividend[pick];
    }
    else {
      string tempStr = "";
      for(int j=0;j<pick;j++){
        tempStr+="0";
      }
      temp = xorFun(tempStr,temp) + dividend[pick];
    }
    pick+=1;
  }
  if (temp[0] == '1')
        temp = xorFun(divisor, temp);
    else{
      string tempStrTwo = "";
      for(int j=0;j<pick;j++){
        tempStrTwo+="0";
      }
        temp = xorFun(tempStrTwo, temp);
      }
  string checkWord = temp;
  return checkWord;
}


int main(int argc, char const *argv[]) {
  /* code */
  string data, key;
  cin>>data;
  cin>>key;
  cout<<"The remainder is "<<modToDiv(data,key)<<endl;
  return 0;
}
