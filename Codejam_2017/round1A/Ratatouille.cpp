#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <bitset>

using namespace std;


#define pb push_back
#define ll long long
#define F first
#define S second
#define EPS 1e-9
#define INF 1e15
#define rd(a) scanf("%d",&a)
#define rd2(a,b) scanf("%d %d",&a,&b)
#define rd3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define rdll(a) scanf("%I64d",&a)
#define lp(i,a,n) for(int i=(a); i<=(n) ; ++i)
#define lpd(i,n,a) for(int i=(n); i>=(a) ; --i)

typedef pair<int,int>ii;
typedef pair<double,double>point;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;



ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll extended_euclidean(ll a,ll b,ll &x,ll &y){if(b==0){x=1;y=0;return a;}ll g = extended_euclidean(b,a%b,y,x);y -= (a/b)*x;return g;}
ll power(ll base,ll p,ll mod){if(p==1)return base;if(!p)return 1ll;ll ret=power(base,p/2,mod);ret*=ret;ret%=mod;if(p&1)ret*=base;return ret%mod;}
ii operator + (ii a,ii b){ii ret = a;ret.F += b.F;ret.S += b.S;return ret;}

const int N = 100005;

ll get_left_bound(int package_weight,int grams_for_recipe){
    ll x = package_weight * 10;
    ll y = grams_for_recipe * 11;


    ll z = x/y;
    if(x%y)z++;
    return z;
}
ll get_right_bound(int package_weight,int grams_for_recipe){
  ll x = package_weight*10;
  ll y = grams_for_recipe*9;

  ll z = x/y;
  return z;
}
struct Event{
  ll package_type,start,finish,index;
  bool isStart;
  Event(){;}
  Event(int a,int x,int b,int d,bool c){
    package_type = a;
    index = x;
    start = b;
    finish = d;
    isStart = c;
  }
};
bool operator < (Event a,Event b){
   if(a.index != b.index){
     return a.index < b.index;
   }
   if(a.isStart != b.isStart){
     return a.isStart;
   }
   return 0;
}
int A[10][10];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      cout<<"Case #"<<i<<": ";
      int n,p;
      cin>>n>>p;
      vector<ll>need(n);
      vector<Event>sweep;
      for(int j=0;j<n;j++)cin>>need[j];
      for(int j=0;j<n;j++){
        for(int k=0;k<p;k++){
            int x;
            cin>>x;
            ll lft = get_left_bound(x,need[j]);
            ll rgt = get_right_bound(x,need[j]);
            if(lft > rgt || rgt == 0)continue;
            sweep.pb(Event(j,lft,lft,rgt+1,true));
            sweep.pb(Event(j,rgt+1,lft,rgt+1,false));
        }
      }
      /// stress test
     //  vector<int>z;
     //  for(int j=0;j<p;j++){
     //    z.pb(j);
     //  }
     //  int mx = 0;
     //  if(i == 98){
     //    continue;
     //  }
     //  if(n == 2){
     //  do{
     //      int sum = 0;
     //      for(int j=0;j<p;j++){
     //          ll a = A[0][j];
     //          ll b = A[1][z[j]];
     //          for(ll k=1;k<=1000000;k++){
     //              if(a*10<=need[0]*11*k && a*10>=need[0]*9*k && b*10<=need[1]*11*k && b*10 >= need[1]*9*k){
     //                sum ++;
     //                break;
     //              }
     //              if(a*10 < need[0]*9*k)break;
     //              if(b*10 < need[1]*9*k)break;
     //          }
     //      }
     //      mx = max(mx,sum);
     //  }
     //  while(next_permutation(z.begin(),z.end()));
     // }
     // else{
     //   for(int j=0;j<p;j++){
     //     for(ll k=1;k<=1000000;k++){
     //        ll a = A[0][j];
     //         if(a*10<=need[0]*11*k && a*10>=need[0]*9*k){
     //           mx ++;
     //           break;
     //         }
     //       }
     //   }
     // }
     // cout<<mx<<endl;
      int sol = 0;

      sort(sweep.begin(),sweep.end());
      multiset<ll>st[n+1];

      for(int j=0;j<sweep.size();){
         int cur = sweep[j].index;
         while(cur == sweep[j].index){
           Event a = sweep[j];
           if(a.isStart){
             st[a.package_type].insert(a.finish);
           }
           else{
             if(st[a.package_type].count(a.finish)){
               st[a.package_type].erase(st[a.package_type].find(a.finish));
             }
           }
           j++;
         }
         int mn = 10000;
         for(int k=0;k<n;k++){
           mn = min(mn,(int)st[k].size());
         }

         if(mn){
             sol += mn;
             for(int k=0;k<n;k++){
                 for(int l=0;l<mn;l++){
                     st[k].erase(st[k].find(*st[k].begin()));
                 }
             }
         }
      }
      cout<<sol<<endl;
    }
    return 0;
}
