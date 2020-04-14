
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <bitset>

using namespace std;


#define pb push_back
#define ll long long
#define f first
#define s second
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

set<int>col[N], row[N], visited[N];
vector<vector<int> > arr;

vector<ii> get_neighbours(int i, int j){
    vector<ii>neighbours;

    set<int>::iterator lft = row[i].lower_bound(j);
    if(lft != row[i].begin()){
        lft--;
        neighbours.pb(ii(i,*lft));
    }

    set<int>::iterator rgt = row[i].upper_bound(j);
        if(rgt != row[i].end())
            neighbours.pb(ii(i,*rgt));


    set<int>::iterator up = col[j].lower_bound(i);
    if(up != col[j].begin()){
        up--;
        neighbours.pb(ii(*up,j));
    }

    set<int>::iterator down = col[j].upper_bound(i);

    if(down != col[j].end())
        neighbours.pb(ii(*down,j));

    return neighbours;
}
bool is_dead(int i, int j){
    vector<ii>neighbours = get_neighbours(i,j);
    int neighbours_count = (int)neighbours.size(),sum = 0;

    for(auto i : neighbours)
        sum += arr[i.f][i.s];

    return sum > arr[i][j] * neighbours_count;
}
int main()
{
   // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    int t;
    rd(t);
    for(int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        int n,m;
        rd2(n,m);
        lp(i,0,n-1) row[i].clear(), visited[i].clear();
        lp(j,0,m-1) col[j].clear();
        arr.clear();


        vector<ii>dead;
        ll sol = 0, sum_now = 0;

        lp(i,0,n-1){
            arr.pb(vector<int>(m));
            lp(j,0,m-1){
                rd(arr[i][j]);
                row[i].insert(j);
                col[j].insert(i);
                sum_now += arr[i][j];
            }
        }


        lp(i,0,n-1){
            lp(j,0,m-1)
                if(is_dead(i,j))
                    dead.pb(ii(i,j));
        }

        sol = sum_now;
        while(!dead.empty()){
            /// remove dead
            for(auto i : dead){
                row[i.f].erase(i.s);
                col[i.s].erase(i.f);
                sum_now -= arr[i.f][i.s];
            }

            sol += sum_now;
            vector<ii>new_dead;

            for(auto i : dead){
                vector<ii>neighbours = get_neighbours(i.f, i.s);
                for(auto j : neighbours){
                    if(is_dead(j.f, j.s) && !visited[j.f].count(j.s)){
                        new_dead.pb(j);
                        visited[j.f].insert(j.s);
                    }
                }
            }

            dead = new_dead;
        }
        cout<<sol<<endl;
    }

    return 0;
}
