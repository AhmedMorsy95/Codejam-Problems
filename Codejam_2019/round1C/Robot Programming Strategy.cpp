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
#define EPS 1e-9
#define rd(a) scanf("%d",&a)
#define rd2(a,b) scanf("%d %d",&a,&b)
#define rd3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define rdll(a) scanf("%I64d",&a)
#define sz(a) (int) a.size()
#define lp(i,a,n) for(int i=(a); i<=(n) ; ++i)
#define lpd(i,n,a) for(int i=(n); i>=(a) ; --i)
#define pi acos(-1)
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

const int N = 255 + 5;
string s[N];
int lose[N];

char win(char a, char b){
    if(a > b) swap(a,b);
    if(a == 'P' && b == 'R') return a;
    if(a == 'P' && b == 'S') return b;
    if(a == 'R' && b == 'S') return a;
}

char getChar(const string& s , int idx){
  idx %= (int)s.length();
  return s[idx];
}

int main(){

    freopen("test.in","r",stdin);
   // ios_base::sync_with_stdio(false);
    int t;
    rd(t);
    lp(x,1,t){
        printf("Case #%d: ",x);
        int n;
        rd(n);
        vector<int>cur;
        lp(i,1,n)
            cin>>s[i], cur.pb(i);

        int idx = 0;
        string sol = "";
        while(cur.size()){
            set<char>st;
            for(auto i : cur)
                st.insert(getChar(s[i],idx));

            if(st.size() == 3){
                sol = "IMPOSSIBLE";
                break;
            }

            if(st.size() == 1){
                char c = *st.begin();
                if(c == 'P') sol+= 'S';
                if(c == 'R') sol += 'P';
                if(c == 'S') sol += 'R';
                break;
            }

            char a = *st.begin();
            st.erase(st.begin());
            char b = *st.begin();
            char c = win(a,b);
            sol += c;

            vector<int>new_cur;
            for(auto i : cur)
                if(getChar(s[i],idx) == c)
                    new_cur.pb(i);

            cur = new_cur;
            idx++;
        }
        cout<<sol<<endl;

    }
    return 0;
}
