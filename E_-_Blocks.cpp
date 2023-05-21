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
ll dp[250][250][250];
vector<int>v(250,0),vv(200);
ll maxScore(int l,int r,int cnt){
    //cout<<l<<" "<<r<<" "<<cnt<<endl;
   if(l>r)return 0;
   if(dp[l][r][cnt]!=-1)return dp[l][r][cnt];
   //cout<<cnt<<endl;
   ll ans1=((cnt+1)*(cnt+1))+maxScore(l+1,r,0);
   ll ans2=0;
   int nxt=l;
   while (true){
    if(vv[nxt]==nxt||vv[nxt]>r)break;
    ans2=max(ans2,maxScore(l+1,vv[nxt]-1,0)+maxScore(vv[nxt],r,cnt+1));
    //cout<<ans2<<endl;
    nxt=vv[nxt];
   }
   //cout<<ans1<<" "<<ans2<<endl;
   return dp[l][r][cnt]=max(ans1,ans2);
}
void solve() {
   int n;cin>>n;
   //for(int i=0;i<=n;i++)v[i].clear();
   memset(dp,-1,sizeof dp);
   for(int i=0;i<=n;i++)vv[i]=i;
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(v[j]==v[i]){
            vv[i]=j;
            break;
        }
    }
   }
    cout<<maxScore(0,n-1,0)<<endl;
   //cout<<"The minimum cutting is "<<minCost(0,m-1,1,n,v)<<".\n";
}

int main() {

    int t = 1;

    Fast_io;

    cin >> t;
    int c = 1;
    int n;
    while (t--) {
        cout << "Case " << c++ << ": ";
        //if(n==0)break;
        solve();
    }
    return 0;
}
