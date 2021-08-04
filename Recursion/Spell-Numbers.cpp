#include<bits/stdc++.h>
using namespace std;

void printSpell(int n,string s[]){
    if(n == 0)
      return;

      printSpell(n/10,s);
      cout<<s[n%10]<<" ";
}

int main(){
  string s[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
  printSpell(210,s);
}
