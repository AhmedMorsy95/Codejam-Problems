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

const int N = 26;

bool v[N][N][N][N];
bool state[N][N][N][N];
string s[N],tmp[N];

int getUnique(int a,int b,int c,int d){
    int x = 0;
    for(int i=a;i<=c;i++){
      for(int j=b;j<=d;j++){
          if(s[i][j] == '?')continue;
          int idx = s[i][j] - 'A';
          x |= (1<<idx);
      }
    }
    if(__builtin_popcount(x) !=1 )return 2;
    return x!=0;
}
char getCharUnique(int a,int b,int c,int d){
  for(int i=a;i<=c;i++){
    for(int j=b;j<=d;j++){
        if(s[i][j] == '?')continue;
        return s[i][j];
    }
  }
  return '?';
}
void color(int a,int b,int c,int d,char x){
   for(int i=a;i<=c;i++)
      for(int j=b;j<=d;j++)
            tmp[i][j] = x;
}
bool solve(int a,int b,int c,int d){

  if(a>c || b>d) return 1;
  if(v[a][b][c][d])
      return state[a][b][c][d];
  int cnt = getUnique(a,b,c,d);
  v[a][b][c][d] = 1;

  if(!cnt){
    return state[a][b][c][d] = 0;
  }
  if(cnt == 1){
      return state[a][b][c][d] = 1;
  }

  bool can = 0;
  for(int i=a;i<c;i++){
           if(solve(a,b,i,d) && solve(i+1,b,c,d)){
              can = 1;
              break;
           }
  }

  for(int i=b;i<d;i++){
           if(solve(a,b,c,i) && solve(a,i+1,c,d)){
              can = 1;
              break;
           }
  }
  return state[a][b][c][d] = can;

}

void go(int a,int b,int c,int d){
  if(a>c || b>d) return;
  int cnt = getUnique(a,b,c,d);
  if(cnt == 1){
      color(a,b,c,d,getCharUnique(a,b,c,d));
      return;
  }

  for(int i=a;i<c;i++){
           if(solve(a,b,i,d) && solve(i+1,b,c,d)){
              go(a,b,i,d);
              go(i+1,b,c,d);
              return;
           }

  }

  for(int i=b;i<d;i++){
           if(solve(a,b,c,i) && solve(a,i+1,c,d)){
              go(a,b,c,i);
              go(a,i+1,c,d);
              return;
           }
  }
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("A-small-practice.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      cout<<"Case #"<<i<<":\n";
      int n,m;
      cin>>n>>m;
      for(int j=0;j<n;j++)cin>>s[j],tmp[j]=s[j];

      for(int a=0;a<n;a++)for(int b=0;b<m;b++)for(int c=0;c<n;c++)for(int d=0;d<m;d++)state[a][b][c][d] = v[a][b][c][d] = 0;
      go(0,0,n-1,m-1);
      for(int j=0;j<n;j++)cout<<tmp[j]<<endl;

    }

    return 0;
}
