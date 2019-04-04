#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int r,c,b;
struct cachier{
  ll max_items,packing_items,scan_item_time;
  cachier(){;}
  cachier(int a,int b,int c){
          max_items = a*1ll;
          scan_item_time = b*1ll;
          packing_items = c*1ll;
  }
};

bool get_best(ll max_time,vector<cachier> &v){
    std::vector<ll>all;
    for(auto c : v){
        ll cur = max_time - c.packing_items;
        ll max_items = 0;
        if(cur > 0){
           max_items = min(c.max_items,cur/c.scan_item_time);
        }
        all.push_back(max_items);
    }
    sort(all.rbegin(),all.rend());
    ll sum = 0;
    for(int i=0;i<r && sum<b;i++){
         sum += all[i];
    }
    return (sum >= b);
}
int main()
{
   // freopen("test.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
      printf("Case #%d: ",i);
      scanf("%d%d%d",&r,&b,&c);
      vector<cachier>v;
      for(int j=0;j<c;j++){
          int a,b,c;
          scanf("%d%d%d",&a,&b,&c);
          v.push_back(cachier(a,b,c));
      }
      ll low = 1 , high = (1LL<<62);
      while(low+1<high){
        ll mid = (low+high)/2;
        if(get_best(mid,v)){
            high = mid;
        }
        else low = mid+1;
      }
      if(get_best(low,v))cout<<low<<endl;
      else cout<<high<<endl;
    }
    return 0;
}
