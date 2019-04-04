#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(std::vector<int> v){
  vector<int>x[2];
  for(int i=0;i<v.size();i++)
      x[i%2].push_back(v[i]);

  sort(x[0].begin(),x[0].end());
  sort(x[1].begin(),x[1].end());

  int a = 0, b = 0;
  vector<int>sorted;
  for(int i=0;i<v.size();i++){
       if(i&1)sorted.push_back(x[1][b++]);
       else sorted.push_back(x[0][a++]);
  }

  int error = -1;
  for(int i=0;i<(int)sorted.size()-1;i++){
      if(sorted[i] > sorted[i+1] && error == -1)
            error = i;
  }
  if(error == -1)printf("OK\n");
  else printf("%d\n",error);
}
int main()
{
  //  freopen("test.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
      printf("Case #%d: ",i);
      int n;
      scanf("%d",&n);
      vector<int>v(n);
      for(int j=0;j<n;j++)
        scanf("%d",&v[j]);

      solve(v);
    }
    return 0;
}
