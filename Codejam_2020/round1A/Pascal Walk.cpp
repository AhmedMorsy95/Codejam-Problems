
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

int main()
{
    //freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    int t;
    rd(t);
    for(int i=1;i<=t;i++){
        printf("Case #%d:\n",i);
        int n;
        rd(n);
        if(n < 500)
            lp(i,1,n) printf("%d 1\n",i);
        else{
            n -= 30;
            bool rgt = true;
            int depth = 0, sum = 0;
            while(n >= (1<<depth)){
                if(rgt)
                    printf("%d 1\n",depth+1);
                else
                    printf("%d %d\n",depth+1,depth+1);
                sum++;
                if(n & (1<<depth)){
                    sum += (1<<depth) - 1;

                    if(rgt)
                        lp(i,2,depth+1) printf("%d %d\n",depth+1,i);
                    else
                        lpd(i,depth,1) printf("%d %d\n",depth+1,i);
                    rgt = !rgt;
                }
                depth++;
            }
           n += 30;
           while(sum < n){
                sum++;
                if(rgt) printf("%d 1\n",depth+1,1);
                else printf("%d %d\n", depth+1, depth+1);
                depth++;
           }
        }

    }

    return 0;
}
