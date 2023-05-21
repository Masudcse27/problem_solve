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
#define ll                  long long
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
    ll n;cin>>n;
    stack<string>stco,stsw;
    stack<int>stci,stsi;
    cin.clear();
    string c;
    getline(cin,c);
    for(int i=0;i<n;i++){
        string str;
        getline(cin,str);
        //cout<<str<<endl;
        if(str.substr(0,3)=="put"){
            //cin>>str;
            //cout<<"pas\n";
            if(str.substr(4,str.size())=="snowcoat")stsw.push("snowcoat"),stsi.push(i);
              
            else stco.push(str.substr(4,str.size())),stci.push(i);
        }
        else if(str.substr(0,3)=="get"){
            if(stco.size()||stsw.size()){
                int a=-1,b=-1;
                if(stco.size())a=stci.top();
                if(stsw.size())b=stsi.top();
                if(a>b){
                    cout<<stco.top()<<endl;
                    stco.pop(),stci.pop();
                }
                else{
                    cout<<stsw.top()<<endl;
                    stsw.pop(),stsi.pop();
                }
                //stco.pop();
            }
            else cout<<"empty\n";
            
        }
        else{
            if(stsw.size()){
                cout<<"winner winner chicken dinner :)\n";
                stsw.pop();
            }
            else cout<<"oopsimcold :(\n";
        }
    }
}
int main() {
    int t = 1;

    //Fast_io;

    //cin >> t;
    int c = 1;
    int n;
    while (t--) {
       // cout << "Case " << c++ << ": ";
        //if(n==0)break;
        solve();
    }
    return 0;
}