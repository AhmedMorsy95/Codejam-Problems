#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <bitset>

using namespace std;


#define pb push_back
#define mp make_pair
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
///: N, R, O, Y, G, B, and V.
#define red 0
#define orange 1
#define yellow 2
#define green 3
#define blue 4
#define violet 5

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
string colors = "ROYGBV";

bool valid(string s){
    int n = (int)s.length();
    for(int i=0;i<n;i++){
      if(s[i] == s[(i+1)%n]) return false;
      if(s[i] == 'V' && s[(i+1)%n] != 'Y') return false;
      if(s[i] == 'O' && s[(i+1)%n] != 'B') return false;
      if(s[i] == 'G' && s[(i+1)%n] != 'R') return false;
      if(s[i] == 'V' && s[(i-1+n)%n] != 'Y') return false;
      if(s[i] == 'O' && s[(i-1+n)%n] != 'B') return false;
      if(s[i] == 'G' && s[(i-1+n)%n] != 'R') return false;
    }
    return true;
}
string solve(int a,int b,int c){
  vector<pair<int,char> >v;
  v.pb(mp(a,'R'));
  v.pb(mp(b,'Y'));
  v.pb(mp(c,'B'));
  sort(v.rbegin(),v.rend());

  if(v[0].F > v[1].F + v[2].F) {return "IMPOSSIBLE";}

  vector<char>ret;

  for(int i=0;i<v[1].first;i++){
    ret.pb(v[0].S);
    ret.pb(v[1].S);
  }
  v[0].F -= v[1].F;
  for(int i=0;i<min(v[0].F,v[2].F);i++){
    ret.pb(v[0].S);
    ret.pb(v[2].S);
  }

  v[2].F -= v[0].F;
  if(v[2].F){
     vector<char>ret2;
     for(int i=0;i<ret.size();i++){
       if(!i)
         ret2.pb(ret[i]);
       else{
         if(ret2.back() == v[0].S && v[2].F > 0){
           ret2.pb(v[2].S);
           v[2].F--;
         }
         ret2.pb(ret[i]);
       }
     }
     ret = ret2;
  }
  string s = "";
  for(char c : ret) s += c;
  if(!valid(s)) return "IMPOSSIBLE";
  return s;
}
/// : N, R, O, Y, G, B, and V.
int n;
string solveLarge(vector<int>v){
  int zeros = 0;
  for(int i : v) zeros += (i == 0);
  if(zeros == 5) return "IMPOSSIBLE";
  if(zeros == 4){
    if(n&1) {return "IMPOSSIBLE";}
    string in = "";
    int mn = 1e9, mx = 0;
    for(int i=0;i<6;i++){
        if(v[i]) in+=colors[i],mn = min(mn,v[i]) , mx = max(mx,v[i]);
    }
    string ret = "";
    for(int i=0;i<n/2;i++)ret+=in;
    if(!valid(ret) || ret.length()!=n || mn!=mx) return "IMPOSSIBLE";
    return ret;
  }
/// 3 or more different characters

  if((v[violet]>=v[yellow]&&v[violet]>0) || (v[orange]>=v[blue]&&v[orange]>0) || (v[green]>=v[red]&&v[green]>0))return "IMPOSSIBLE";
  string ret = solve(v[red]-v[green],v[yellow]-v[violet],v[blue]-v[orange]);
  if(ret=="IMPOSSIBLE") return ret;
  string a="",b="",c="";
  for(int i=0;i<v[green];i++) a+="GR";
  for(int i=0;i<v[violet];i++) b+="VY";
  for(int i=0;i<v[orange];i++) c+="OB";

  string x = "";
  for(char i:ret){
     x += i;
     if(i == 'R') x+=a,a="";
     else if(i == 'Y') x+=b,b="";
     else if(i == 'B') x+=c,c="";
  }
  if(!valid(x)) return "IMPOSSIBLE";
  else return x;
}
int main()
{

    freopen("test.in","r",stdin);
    freopen("test2.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      cout<<"Case #"<<i<<": ";
      vector<int>cnt(6);
      cin>>n;
      lp(i,0,5) cin>>cnt[i];
      cout<<solveLarge(cnt)<<endl;

    }

    return 0;
}
