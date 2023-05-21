#include <bits/stdc++.h>
using namespace std;
/// Typedef
typedef long long           LL;
typedef vector<int>         vi;
typedef pair<int,int>       pii;
#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
#define pb                  push_back
#define ppb                 pop_back
#define MP                  make_pair
#define ff                  first
#define ss                  second
#define sf                  scanf
#define pf                  printf
#define SQR(x)              ((x)*(x))
#define loop(i, y)          for(int i=0; i<int(y); i++)
#define FOR(i, x, y)        for(int i=int(x); i<=int(y); i++)
#define ROF(i, x, y)        for(int i=int(x); i>=int(y); i--)
#define all(c)              c.begin(), c.end()
#define sz(c)               int(c.size())
#define clr(x, y)           memset(x, y, sizeof(x))
#define si(x)               scanf("%d", &x)
#define sii(x, y)           scanf("%d %d", &x, &y)
#define siii(x, y, z)       scanf("%d %d %d", &x, &y, &z)
#define sl(x)               scanf("%lld", &x)
#define sll(x, y)           scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       scanf("%lld %lld %lld", &x, &y, &z)
 
#ifdef VAMP
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cout << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cout.write(names, comma - names) << " = " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
 
// mt19937_64                  rng(chrono::steady_clock::now().time_since_epoch().count());
// #define new_ran(a, b)       uniform_int_distribution<LL> (a, b)(rng)
// #define ran_shuffle(x)      shuffle(x.begin(), x.end(), rng)
template <class T, class L> inline T bigMod(T p,T e,L M){ LL ret = 1%M; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = ((LL)p * p) % M; } return (L) ret;}
 
/// Constants
#define MAX                 200005
#define MOD                 1000000007
#define eps                 1e-9
#define INF                 0x3f3f3f3f3f3f3f3f // 4,557,430,888,798,830,399
#define inf                 0x3f3f3f3f // 1,061,109,567
#define PI                  acos(-1.0)  // 3.1415926535897932


void solve(){
    int n;cin>>n;
    n=(n*2)-2;
    vector<pair<int,string>>v;
    for(int i=0;i<n;i++){
        string str;cin>>str;
        v.push_back({str.size(),str});
    }
    sort(v.begin(),v.end());
    string st1=v[n-1].second,st2=v[n-2].second;
    if(st1.substr(0,v[n-1].first-1)==st2.substr(1,v[n-2].first)){
        string str=st2+st1[st1.size()-1];
        string str2=str;
        reverse(str2.begin(),str2.end());
        if(str==str2){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    else if(st2.substr(0,v[n-1].first-1)==st1.substr(1,v[n-2].first)){
        string str=st1[0]+st2;
        string str2=str;
        reverse(str2.begin(),str2.end());
        if(str==str2){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    else cout<<"NO\n";
}
int main() {
    int t = 1;

    Fast_io;

    cin >> t;
    int c = 1;
    int n;
    while (t--) {
        //cout << "Case " << c++ << ": ";
        //if(n==0)break;
        solve();
    }
    return 0;
}