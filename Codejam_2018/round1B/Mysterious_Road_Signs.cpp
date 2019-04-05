#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define ll long long
#define ii pair<int,int>
using namespace std;

const int N = 100005;

int n,d[N],a[N],b[N],mx;

set<ii>exists;
void maximize(int length,int start){

   if(length > mx){
     exists.clear();
     mx = length;
     exists.insert(ii(start,length));
   }
   else if(length == mx){
    exists.insert(ii(start,length));
  }
}

void divide_and_conquer(int s,int e){
  if(s==e){
    maximize(1,s);
    return;
  }
  int mid = (s+e)/2;
  divide_and_conquer(s,mid);
  divide_and_conquer(mid+1,e);

  int x = a[mid]+d[mid], y = d[mid]-b[mid];

  // part 1
  int lft,rgt;
  lft = rgt = mid;

  while(lft>=s && a[lft]+d[lft] == x) lft--;
  lft++;
  while(rgt<=e && a[rgt]+d[rgt] == x) rgt++;
  rgt--;

  int option1 = 0 ,option2 = 0, start1 = lft, start2 = lft;

  for(int j=lft-1;j>=s;j--){
      if(d[lft-1]-b[lft-1] == d[j]-b[j] || a[j]+d[j] == x)option1++,start1--;
      else{
        break;
      }
  }
  for(int j=rgt+1;j<=e && lft-1 >= 0;j++){
      if(d[lft-1]-b[lft-1] == d[j]-b[j] || a[j]+d[j] == x)option1++;
      else{
        break;
      }
  }

  for(int j=lft-1;j>=s && rgt+1 <= e;j--){
      if(d[rgt+1]-b[rgt+1] == d[j]-b[j] || a[j]+d[j] == x)option2++,start2--;
      else{
        break;
      }
  }
  for(int j=rgt+1;j<=e;j++){
      if(d[rgt+1]-b[rgt+1] == d[j]-b[j] || a[j]+d[j] == x)option2++;
      else{
        break;
      }
  }

  maximize(rgt-lft+1+option1,start1);
  maximize(rgt-lft+1+option2,start2);

  // part 2
  lft = rgt = mid;
  option1 = option2 = 0;

  while(lft>=s && d[lft]-b[lft] == y) lft--;
  lft++;
  while(rgt<=e && d[rgt]-b[rgt] == y) rgt++;
  rgt--;

  start1=start2=lft;

  for(int j=lft-1;j>=s;j--){
      if(d[lft-1]+a[lft-1] == d[j]+a[j] || d[j]-b[j] == y)option1++,start1--;
      else{
        break;
      }
  }
  for(int j=rgt+1;j<=e && lft-1 >= 0;j++){
      if(d[lft-1]+a[lft-1] == d[j]+a[j] || d[j]-b[j] == y)option1++;
      else{
        break;
      }
  }

  for(int j=lft-1;j>=s && rgt+1 <= e;j--){
      if(d[rgt+1]+a[rgt+1] == d[j]+a[j] || d[j]-b[j] == y)option2++,start2--;
      else{
        break;
      }
  }
  for(int j=rgt+1;j<=e;j++){
      if(d[rgt+1]+a[rgt+1] == d[j]+a[j] || d[j]-b[j] == y)option2++;
      else{
        break;
      }
  }
  maximize(rgt-lft+1+option1,start1);
  maximize(rgt-lft+1+option2,start2);
}
int main()
{
    // freopen("test.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
      printf("Case #%d: ",i);
      scanf("%d",&n);
      mx = 0;
      for(int j=0;j<n;j++){
          scanf("%d%d%d",&d[j],&a[j],&b[j]);
      }

      divide_and_conquer(0,n-1);
      printf("%d %d\n",mx,(int)exists.size());
      exists.clear();


    }
    return 0;
}
