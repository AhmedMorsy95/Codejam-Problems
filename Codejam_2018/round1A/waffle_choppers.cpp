#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,r,c;
int getSum(string &s){
  int ret = 0;
  for(char c: s)
      ret += c == '@';
  return ret;
}
int getColSum(std::vector<string> &v,int j){
  int sum = 0;
  for(int i=0;i<n;i++)
        sum += v[i][j] == '@';
  return sum;
}
void solve(vector<std::string> &v,int cakes){
    int people = (r+1)*(c+1);
    int cur = 0;
    vector<int>cuts;
    cuts.push_back(-1);
    int row_cuts = 0;
    for(int i=0;i<n;i++){
        cur += getSum(v[i]);
        if(cur*(r+1) == cakes && row_cuts < r){
            cur = 0;
            row_cuts++;
            cuts.push_back(i);
        }
    }
    if(cur*(r+1) != cakes || row_cuts != r){
      printf("IMPOSSIBLE\n");
      return;
    }
    cuts.push_back(n-1);

    cur = 0;
    int prv_col = -1 , col_cuts = 0;
    for(int i=0;i<m;i++){
        cur += getColSum(v,i);
        if(cur*(c+1) == cakes){
           bool ok = true;
           for(int k=1;k<cuts.size() && ok;k++){
              int sum = 0;
              for(int row = cuts[k-1]+1;row<=cuts[k];row++){
                for(int a=prv_col+1;a<=i;a++){
                      sum += v[row][a] == '@';
                }
              }
              if(sum*(r+1)*(c+1) != cakes)
                      ok = 0;
           }
           if(!ok){
             printf("IMPOSSIBLE\n");
             return;
           }
           else if(col_cuts < c){
             cur = 0;
             prv_col = i;
             col_cuts++;
           }
        }
    }
    if(col_cuts != c || cur*(c+1)!= cakes)printf("IMPOSSIBLE\n");
    else printf("POSSIBLE\n");
}
int main()
{
    //freopen("test.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
      printf("Case #%d: ",i);
      scanf("%d %d %d %d",&n,&m,&r,&c);
      vector<string>v(n);
      int sum = 0;
      for(int j=0;j<n;j++){
          cin>>v[j];
          for(char c : v[j])
              sum += c == '@';
      }
      int people = (r+1)*(c+1);
      if(sum == 0){
          printf("POSSIBLE\n");
      }
      else if(sum%people){
          printf("IMPOSSIBLE\n");
      }
      else{
          solve(v,sum);
      }


    }
    return 0;
}
