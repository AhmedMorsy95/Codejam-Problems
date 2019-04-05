#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define ll long long
#define ii pair<int,int>
using namespace std;

int n,l;
int get_rounding(int a,int b){
  int ret =(a*100)/b;
  int x = (a*1000)/b;
  ret += (x%10>4);
  return ret;
}
int main()
{
    // freopen("test.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
      printf("Case #%d: ",i);
      scanf("%d%d",&n,&l);
      vector<int>v(l);
      int extra = n,sum = 0;
      for(int j=0;j<l;j++){
         scanf("%d",&v[j]);
         extra -= v[j];
         sum += get_rounding(v[j],n);
      }
      vector<int>z,steps(n+1,-1);
      for(int j=0;j<n;j++){
          int rounding = (j*100)/n;
          int best = get_rounding(j,n);
          if(rounding < best) z.push_back(j);
          else z.push_back(-1);
      }

      int last = -1;
      for(int j=n-1;j>=0;j--){
          if(last != -1)
            steps[j] = last - j;
          if(z[j]!=-1){
             last = j;
          }
      }
      multiset<ii>st;
      for(int j=0;j<extra;j++)
          if(steps[0]!=-1)
            st.insert(ii(steps[0],0));

      for(int j=0;j<l;j++){
        // dont add a languge which already rounds up why ?
        // if x already rounds up and x+k round up too then we could have used the k to help another languge round up
         if(steps[v[j]] != -1 && z[v[j]] == -1)
            st.insert(ii(steps[v[j]],v[j]));
      }

      while(extra > 0 && st.size()){
          ii x = *st.begin();
          st.erase(st.begin());
          if(extra >= x.first){
              extra -= x.first;
              sum -= get_rounding(x.second,n);
              x.second += x.first;
              sum += get_rounding(x.second,n);
              x.first = steps[x.second];
              if(x.first != -1 && z[x.second] == -1)
                  st.insert(x);
          }
          else{
            sum -= get_rounding(x.second,n);
            x.second += extra;
            extra = 0;
            sum += get_rounding(x.second,n);
          }
      }
      printf("%d\n",sum+get_rounding(extra,n));

    }
    return 0;
}
