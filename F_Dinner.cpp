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
ll dp[300][300][300];
ll maxScore(int l,int r,string &str,int cnt,int k){
    
    if(l>r)return 0;
    if(dp[l][r][cnt]!=-1)return dp[l][r][cnt];
    //cout<<l<<" "<<r<<endl;
    ll ans=INT_MAX;
    if(cnt>=k)ans=1+maxScore(l+1,r,str,1,k);
    for(int i=l+1;i<=r;i++){
        if(str[i]==str[l]){
            ans=min(ans,maxScore(l+1,i-1,str,1,k)+maxScore(i,r,str,cnt+1,k));
        }
    }
    return dp[l][r][cnt]=ans;

}
void solve() {
   int n,k;cin>>n>>k;
   memset(dp,-1,sizeof dp);
   string str;cin>>str;
   //cout<<n<<" "<<k<<"\n"<<str<<endl;
   ll ans=maxScore(0,n-1,str,1,k);
   cout<<(ans==INT_MAX?-1:ans)<<endl;

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
