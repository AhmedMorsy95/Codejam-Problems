#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define ll long long
using namespace std;

int main()
{
   //freopen("test.in","r",stdin);
   //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
      printf("Case #%d: ",i);
      int n,l;
      cin>>n>>l;
      vector<string>v(n);
      unordered_set<string>prefixes;
      vector<int>exist(l,0);
      for(int j=0;j<n;j++){
        cin>>v[j];
        prefixes.insert(v[j]);
        for(int k=0;k<l;k++){
             exist[k]|=1<<(v[j][k]-'A');
        }
      }
      string ans = "-";
      for(int j=0;j<n;j++){
         for(int k=0;k<l;k++){
            for(int x = 0; x<26; x++){
                if((exist[k]&(1<<x))==0)
                      continue;
                string cur = v[j];
                cur[k] = 'A' + x;
                if(!prefixes.count(cur)){
                    ans = cur;
                    break;
                }
            }
         }
      }
      cout<<ans<<endl;
    }
    return 0;
}
