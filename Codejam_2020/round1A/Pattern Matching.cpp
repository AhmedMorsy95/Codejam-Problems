#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <bitset>

using namespace std;


#define pb push_back
#define rd(a) scanf("%d",&a)
#define lp(i,a,n) for(int i=(a); i<=(n) ; ++i)

const int N = 255 + 5;

bool is_prefix(string a,string b){
    /// returns if a is a prefix of b
    b = b.substr(0, a.length());
    return a == b;
}

bool is_suffix(string a,string b){
    b = b.substr((int)b.length()-(int)a.length(), a.length());
    return a == b;
}

void split_string(string t, deque<string> &v){
     string cur = "";
     lp(i,0,(int)t.length()-1){
        if(t[i] == '*'){
            v.pb(cur);
            cur = "";
        }
        else
            cur += t[i];
     }
     v.pb(cur);
}
int main(){

   // freopen("test.in","r",stdin);
   // ios_base::sync_with_stdio(false);
    int t;
    rd(t);
    lp(x,1,t){
        printf("Case #%d: ",x);
         int n;
         rd(n);
         vector<string>s(n);
         lp(i,0,n-1) cin>>s[i];

         vector<deque<string> > split;
         lp(i,0,n-1){
            deque<string>v;
            split_string(s[i],v);
            split.pb(v);
         }

         string start = "", finish = "";
         lp(i,0,n-1){
            if(start.length() < split[i].front().length())
                start = split[i].front();

            if(finish.length() < split[i].back().length())
                finish = split[i].back();
         }

         bool impossible = false;
         lp(i,0,n-1){
            if(!is_prefix(split[i].front(),start))
                impossible = true;
            if(!is_suffix(split[i].back(),finish))
                impossible = true;
         }

         if(impossible) printf("*\n");
         else{
            int rounds = 0;
            lp(i,0,n-1){
                split[i].pop_back();
                split[i].pop_front();
                rounds = max(rounds, (int)split[i].size());
            }
            lp(j,0,rounds-1){
                lp(i,0,n-1){
                    if(split[i].empty())continue;
                    start += split[i].front();
                    split[i].pop_front();
                }
            }
            cout<<start<<finish<<endl;
         }
    }
    return 0;
}

