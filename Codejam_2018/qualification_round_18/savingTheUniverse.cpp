#include <iostream>
#include <vector>

using namespace std;

int get_damage(vector<char>v){
    int cur_damage = 0,power = 1;
    for(char c : v){
        if(c == 'C')power*=2;
        else cur_damage+=power;
    }
    return cur_damage;
}
int solve(int d,string s){
    vector<char>v;
    for(char i : s){
        v.push_back(i);
    }
    int sum = 0;
    for(int i=0;i<30*30+10;i++){
        if(get_damage(v) <= d) return sum;
        bool shot = false;
        for(int j=(int)v.size()-1;j>=0;j--){
            if(v[j] == 'S')shot = 1;
            else if (v[j] == 'C' && shot){
                swap(v[j],v[j+1]);
                sum++;
                break;
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        int d;
        string s;
        cin>>d>>s;
        int x = solve(d,s);
        if(x == -1)printf("IMPOSSIBLE\n");
        else printf("%d\n",x);
    }
    return 0;
}
