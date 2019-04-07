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
int n;

void visualize(string a,string b){
   int area[n][n];
   memset(area,-1,sizeof(area));
   int x = 0, y = 0;
   for(char c : a){
     if(c == 'S')x++;
     else y++;
     area[x][y] = 1;
   }
   x=y=0;
   for(char c : b){
     if(c == 'S')x++;
     else y++;
     area[x][y] = 2;
   }
   for(int i=0;i<n;i++){
     for(int j=0;j<n;j++)cout<<area[i][j]<<' ';
     cout<<endl;
   }
}
int main()
{
    //freopen("test.in","r",stdin);
    //ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
      cout<<"Case #"<<i<<": ";
      string s;
      cin>>n>>s;
      int m = (int)s.length()-1;
      string ans = "";
      if(s[0]=='S'&&s[m]=='E'){
         for(int j=1;j<n;j++)ans+="E";
         for(int j=1;j<n;j++)ans+="S";
      }
      else if(s[0]=='E'&&s[m]=='S'){
         for(int j=1;j<n;j++)ans+="S";
         for(int j=1;j<n;j++)ans+="E";
      }
      else if(s[0]=='E'&&s[m]=='E'){
          vector<bool>column_move(n+1,false);
          int x = 0 , y = 0;
          for(char c: s){
              if(c == 'E'){
                  column_move[x] = true;
                  y++;
              }
              else
                  x++;
          }
          for(int i=1;i<n;i++){
            if(column_move[i] == false){
                for(int k=n-1;k>i;k--){
                    ans+="S";
                }
                for(int k=0;k<n-1;k++)ans += "E";
                for(int k=0;k<i;k++)ans += "S";
                reverse(ans.begin(),ans.end());
                break;
            }
          }
      }
      else if(s[0]=='S' && s[m] == 'S'){
          vector<bool>row_move(n+1,false);
          int x = 0 , y = 0;
          for(char c: s){
              if(c == 'S'){
                  row_move[y] = true;
                  x++;
              }
              else
                  y++;
          }
          for(int i=1;i<n;i++){
            if(row_move[i] == false){
                for(int k=n-1;k>i;k--){
                    ans+="E";
                }
                for(int k=0;k<n-1;k++)ans += "S";
                for(int k=0;k<i;k++)ans += "E";
                reverse(ans.begin(),ans.end());
                break;
            }
        }
      }
      cout<<ans<<endl;
      // visualize(ans,s);
    }

    return 0;
}
