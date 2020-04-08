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

/// slow function for testing
ll solve2(int n,int k,vector<int>c,vector<int>d){
  ll sum = 0;
  lp(i,0,n-1){
    lp(j,i,n-1){
        int mx1 = 0 , mx2 = 0;
        lp(k,i,j) mx1 = max(mx1,c[k]),mx2 = max(mx2,d[k]);
        if(abs(mx1-mx2) <= k) sum++;
    }
  }
  return sum;
}

int main(){

    //freopen("test.in","r",stdin);
   // ios_base::sync_with_stdio(false);
    int t;
    rd(t);
    lp(x,1,t){
        printf("Case #%d: ",x);
        int n,k;
        rd2(n,k);
        vector<int>c(n),d(n),mx_lft(n), mx_rgt(n), start(n,-1), finish(n,-1);
        vector<ii> p,p2;
        lp(i,0,n-1) rd(c[i]) , p.pb(ii(c[i],i));
        lp(i,0,n-1) rd(d[i]) , p2.pb(ii(d[i],i));

        sort(p.begin(),p.end());
        sort(p2.begin(),p2.end());
        set<int>local;

        /// Find boundaries where ith element is the max
        lpd(i,n-1,0){
            ii val = ii(0, n-1);
            boundary(local,val,p[i].s);
            mx_lft[p[i].s] = val.f;
            mx_rgt[p[i].s] = val.s;
            local.insert(p[i].s);
        }

        local.clear();

        int cur = n-1;

        /// Validate the boundaries with the second array
        lpd(i,n-1,0){
            while(cur >=0 && p2[cur].f > p[i].f + k) local.insert(p2[cur--].s);
            if(local.empty()) continue;
            int idx = p[i].s;
            if(local.count(idx)) mx_lft[idx] = mx_rgt[idx] = -1;
            else{
                auto x = local.upper_bound(idx);
                if(x != local.end()) mx_rgt[idx] = min(*x - 1, mx_rgt[idx]);
                if(x != local.begin()) mx_lft[idx] = max(*(--x) + 1, mx_lft[idx]);
            }
        }

        local.clear();
        cur = 0;

        /// Find for each element the nearest element in the 2nd array which will form a solution in both sides
        int cur2 = 0;
        lp(i,0,n-1){
            while(cur < n && p[i].f + k >= p2[cur].f) local.insert(p2[cur++].s);
            while(cur2 <= cur && cur2 < n && p[i].f > p2[cur2].f + k) local.erase(local.find(p2[cur2++].s));

            if(local.empty()) continue;
            int idx = p[i].s;
            if(local.count(idx)) start[idx] = finish[idx] = idx;
            else{
                auto x = local.upper_bound(idx);
                if(x != local.end()) finish[idx] = *x;
                if(x != local.begin()) start[idx] = *(--x);
            }
        }
        ll ans = 0;
        lp(i,0,n-1){
            if(finish[i] > mx_rgt[i]) finish[i] = -1;
            if(start[i] < mx_lft[i]) start[i] = -1;
            if(mx_lft[i] == -1) continue;
            if(start[i] == -1 && finish[i] == -1) continue;
            if(start[i] == -1 && finish[i] != -1) ans += (mx_rgt[i] - finish[i] + 1) * 1LL * (i - mx_lft[i] + 1);
            else if(finish[i] == -1 && start[i] != -1) ans += (start[i] - mx_lft[i] + 1) *1LL * (mx_rgt[i] - i + 1);
            else{
                if(start[i] != finish[i]) ans += (mx_rgt[i] - finish[i] + 1) * 1LL * (i - start[i]) + (start[i] - mx_lft[i] + 1) *1LL* (finish[i] - i);
                ans += (mx_rgt[i] - finish[i] +1) *1LL * (start[i] - mx_lft[i] + 1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
