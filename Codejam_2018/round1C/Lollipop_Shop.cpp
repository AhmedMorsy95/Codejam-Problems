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

void output(int a){
  cout<<a<<endl;
  fflush(stdout);
}
int main()
{
    //freopen("test.in","r",stdin);
    //ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      int n;
      cin>>n;
      map<int,int>cnt;
      vector<bool>taken(n+1,false);
      for(int j=0;j<n;j++){
           int k;
           cin>>k;
           if(!k){
             output(-1);
             continue;
           }
           vector<int>like(k);
           int mn = n;
           for(int l=0;l<k;l++){
              cin>>like[l];
              if(taken[like[l]]) continue;
              if(cnt.count(like[l])){
                  mn = min(mn,cnt[like[l]]);
              }
              else
                  mn = 0 , cnt[like[l]] = 0;
           }
           vector<int>lowest;
           for(int l=0;l<k;l++){
               if(taken[like[l]]) continue;
               if(cnt[like[l]] == mn){
                 lowest.push_back(like[l]);
               }
           }
           if(lowest.size() == 0) output(-1);
           else{
              random_shuffle(lowest.begin(),lowest.end());
              output(lowest.back());
              taken[lowest.back()] = true;
           }

           for(int x : like){
             cnt[x]++;
           }
      }

    }

    return 0;
}
