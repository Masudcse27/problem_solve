#include <bits/stdc++.h>
using namespace std;

#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define fo(i, j, n) for (i = j; i < n; i++)
#define cinn(x) \
    for (int i = 0; i < x.size(); i++) cin >> x[i];
#define printa(x) \
    for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
#define LL long long
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define sl2(x, y) scanf("%lld %lld", &x, &y)
#define sl3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define si2(x, y) scanf("%d %d", &x, &y);
#define si3(x, y, z) scanf("%d %d %d", &x, &y, &z);
#define ss(s) scanf("%s", s)
#define pis(x) printf("%d ", x)
#define pi(x) printf("%d", x)
#define pl(x) printf("%lld", x)
#define ps(s) printf("%s", s)
#define lb() printf("\n")
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define dbgA2(A, n, m)                    \
    {                                     \
        cout << "-->" << #A << "=\n";     \
        for (int i = 0; i < n; i++) {     \
            for (int j = 0; j < n; j++) { \
                cout << A[i][j] << " ";   \
            }                             \
            cout << "\n";                 \
        }                                 \
        cout << "\n";                     \
    }
#define dbgA(A, n)                                       \
    {                                                    \
        cout << "-->" << #A << "=(";                     \
        for (int i = 0; i < n; i++) cout << A[i] << " "; \
        cout << ")\n";                                   \
    }
#define dbg(args...)                                  \
    {                                                 \
        string sss(#args);                            \
        sss += ',';                                   \
        cout << "-->";                                \
        debugger::call(sss.begin(), sss.end(), args); \
        cout << "\n";                                 \
    }

struct debugger {
    typedef string::iterator si;

    static void call(si it, si ed) {}

    template <typename T, typename... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for (; *it != ','; ++it)
            if (*it != ' ') b += *it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
struct values{
    int a,b,c,d;
};
ll dp[150][150];
ll minCost(int l,int r,vector<int> &v){
    //cout<<l<<" "<<r<<endl;
   if(l>=r)return 0;
   //if(l==r)return v[l]-v[l-1];
   if(dp[l][r]!=-1)return dp[l][r];
   ll ans=LONG_LONG_MAX;
   for(int i=l;i<r;i++){
    //cout<<(v[i]-v[l-1])*(v[r]-v[i])<<endl;
    ans=min(ans,(((v[i]-v[l-1])%100)*((v[r]-v[i])%100))+minCost(l,i,v)+minCost(i+1,r,v));
    //cout<<ans<<endl;
   }
   return dp[l][r]=ans;
}
void solve() {
   int n;
   while(cin>>n){
   memset(dp,-1,sizeof dp);
   vector<int>v(n+1,0);
   for(int i=1;i<=n;i++){
    cin>>v[i];
    v[i]+=v[i-1];
   }
    cout<<minCost(1,n,v)<<endl;
   }
   //cout<<"The minimum cutting is "<<minCost(0,m-1,1,n,v)<<".\n";
}

int main() {

    int t = 1;

    Fast_io;

    //cin >> t;
    int c = 1;
    int n;
    while (t--) {
        //cout << "Case " << c++ << ": ";
        //if(n==0)break;
        solve();
    }
    return 0;
}
