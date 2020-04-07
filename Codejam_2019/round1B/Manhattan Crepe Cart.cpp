#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <bitset>

using namespace std;


#define cosRule(a,b,c) (acos(((a)*(a)+(b)*(b)-(c)*(c))/(2*(a)*(b))))
#define pb push_back
#define ll long long
#define F first
#define S second
#define f first
#define s second
#define PI acos(-1)
#define EPS 1e-9
//#define ld long double
#define MAX 1000000000
#define NIL 0
#define INF 1e15
#define infi 1000000000
#define rd(a) scanf("%d",&a)
#define rd2(a,b) scanf("%d %d",&a,&b)
#define rd3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define rdll(a) scanf("%I64d",&a)
#define sz(a) (int) a.size()
#define lp(i,a,n) for(int i=(a); i<=(n) ; ++i)
#define lpd(i,n,a) for(int i=(n); i>=(a) ; --i)
#define pi acos(-1)
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define angle(a)                (atan2((a).imag(), (a).real()))
#define X real()
#define Y imag()
#define vec(a,b)                ((b)-(a))
#define vvi vector<vector<int>>
#define clr(a,b) memset(a,b,sizeof a)
#define all(a) a.begin(), a.end()
#define infll 1000000000000000000ll

#define mod1 1000500001ll
#define mod2 1000300001ll
#define base1 137ll
#define base2 31ll

typedef pair<int,int>ii;
typedef pair<ii,int> data;
typedef pair<ii,ii> line;
typedef pair<double,double>point;
typedef pair<ll, ll> pll;
typedef vector<int> vi;



ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
bool is_vowel(char c){if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return 1;return 0;}
ll extended_euclidean(ll a,ll b,ll &x,ll &y){if(b==0){x=1;y=0;return a;}ll g = extended_euclidean(b,a%b,y,x);y -= (a/b)*x;return g;}
ll power(ll base,ll p,ll mod){if(p==1)return base;if(!p)return 1ll;ll ret=power(base,p/2,mod);ret*=ret;ret%=mod;if(p&1)ret*=base;return ret%mod;}
float Trianglearea(int x1, int y1, int x2, int y2, int x3, int y3) {return abs((x1 * (y2 - y3) + x2 * (y3 - y1) +  x3 * (y1 - y2)) / 2.0);}
ii operator + (ii a,ii b){ii ret = a;ret.F += b.F;ret.S += b.S;return ret;}

const int N = 1e5 + 5;


ii lft[505], rgt[505];
int sum[2001][2001];

int main(){

   freopen("test.in","r",stdin);
   // ios_base::sync_with_stdio(false);
    int t;
    rd(t);
    lp(x,1,t){
        printf("Case #%d: ",x);
        int n,q;
        rd2(n,q);

        lp(i,1,n){
            int x,y;
            char c;
            scanf("%d %d %c\n",&x,&y,&c);
            if(c == 'N'){
                lft[i] = ii(0,y+1);
                rgt[i] = ii(q,q);
            }
            else if(c == 'S'){
                lft[i] = ii(0,0);
                rgt[i] = ii(q,y-1);
            }
            else if(c == 'E'){
                lft[i] = ii(x+1,0);
                rgt[i] = ii(q,q);
            }
            else{
                lft[i] = ii(0,0);
                rgt[i] = ii(x-1,q);
            }
        }
        set<int>st;
        lp(i,1,n){
            st.insert(lft[i].f);
            st.insert(lft[i].s);
            st.insert(rgt[i].f);
            st.insert(rgt[i].s);
            st.insert(rgt[i].f+1);
            st.insert(rgt[i].s+1);
        }
        st.insert(-1);

        map<int,int>rnk, rev;
        int cnt = 0;
        for(auto i : st) rev[cnt] = i, rnk[i] = cnt++;

        lp(i,0,cnt)lp(j,0,cnt) sum[i][j] = 0;

        lp(i,1,n){
                lft[i] = ii(rnk[lft[i].F], rnk[lft[i].S]);
                rgt[i] = ii(rnk[rgt[i].F], rnk[rgt[i].S]);
                lp(j,lft[i].F,rgt[i].F) sum[j][lft[i].s]++, sum[j][rgt[i].s+1]--;
        }

        int sol = 0;
        ii best;
        lp(i,1,cnt){
            lp(j,1,cnt){
                sum[i][j] += sum[i][j-1];
                if(sum[i][j] > sol){
                    sol = sum[i][j];
                    best = ii(rev[i],rev[j]);
                }
            }
        }

        printf("%d %d\n",best.F,best.S);
    }
    return 0;
}
