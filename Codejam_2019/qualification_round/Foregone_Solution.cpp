#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

void solve_small(string s){
    int a = s[0]-'0';
    for(int i=1;i<a;i++){
        if(i!=4 && a-i!=4){
          cout<<i<<' '<<a-i<<endl;
          break;
        }
    }
}
void solve_large_four(string s){
    int first_four = 0;
    for(int i=0;i<s.length();i++){
      if(s[i] == '4'){
        first_four = i;
        break;
      }
    }
    string a = s;
    string b = s.substr(first_four,s.length());
    for(int i=0;i<a.length();i++){
        if(a[i] == '4')
            a[i] = '2';
    }
    for(int i=0;i<b.length();i++){
        if(b[i] == '4'){
          b[i] = '2';
        }
        else{
          b[i] = '0';
        }
    }
    cout<<a<<' '<<b<<endl;
}
void solve_one_non_zero(string s){
  int x = s[0]-'0';
  if(x == 1){
      cout<<5;
      for(int i=2;i<s.length();i++){
        cout<<0;
      }
      cout<<' ';
      cout<<5;
      for(int i=2;i<s.length();i++){
        cout<<0;
      }
      cout<<endl;
      return;
  }
  string a = s, b = s;
  for(int i=1;i<x;i++){
    if(i!=4 && x-i!=4){
       a[0] = '0'+i;
       b[0] = '0'+x-i;
    }
  }
  cout<<a<<' '<<b<<endl;
}
void solve_large_no_four(string s){
    int non_zeros = 0;
    for(char c : s){
       non_zeros += (c!='0');
    }
    if(non_zeros == 1){
      solve_one_non_zero(s);
      return;
    }
    int start = 0;
    for(int i=1;i<s.length();i++){
         if(s[i] != '0'){
           start = i;
           break;
         }
    }
    string a = s;
    string b = s.substr(start,s.length());
    for(int i=1;i<a.length();i++)
        a[i] = '0';

    cout<<a<<' '<<b<<endl;
}
int main()
{
    //freopen("test.in","r",stdin);
    string a = "ahmed";
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      cout<<"Case #"<<i<<": ";
      string s;
      cin>>s;
      if((int)s.length() == 1) solve_small(s);
      else{
        bool four = false;
        for(char c : s){
            four |= c == '4';
        }
        if(four){
          solve_large_four(s);
        }
        else{
          solve_large_no_four(s);
        }
      }

  }
    return 0;
}
