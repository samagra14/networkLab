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

string encodeData(string data, string key){
  int l_key = key.length();
  string tempStr = "";
  for(int j=0;j<l_key-1;j++){
    tempStr+="0";
  }
  string appended_data = data+tempStr;
  string remainderStr = modToDiv(appended_data,key);
  string codeword = data + remainderStr;
  return codeword;
}


int main(int argc, char const *argv[]){
  /* code */
  string s;
  cin>>s;
  string b;
  cin>>b;
  cout<<encodeData(s,b)<<endl;
  cout<<b<<endl;
  return 0;
}
