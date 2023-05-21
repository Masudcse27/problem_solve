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
#define mod 1000000007
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
double dp[305][305][305];
double sushi(int one,int two,int three,int n){
    if(one+two+three==0)return 0.0;
    if(dp[three][two][one]!=-1)return dp[three][two][one];
    double ans=1.0;
    if(three>0)ans+=sushi(one,two+1,three-1,n)*((1.0*three)/n);
    if(two>0)ans+=sushi(one+1,two-1,three,n)*((1.0*two)/n);
    if(one>0)ans+=sushi(one-1,two,three,n)*((1.0*one)/n);
    int z=(n-one-two-three);
    ans=ans/(1-1.0*z/n);
    //cout<<ans<<endl;
    return dp[three][two][one]=ans;
}
void solve() {
    memset(dp,-1.0,sizeof(dp));
    int n,arr[4]={0};cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr[x]++;
    }
    for(int i=0;i<=arr[3];i++){
        for(int j=0;j<=arr[2]+arr[3];j++){
            for(int k=0;k<=arr[1]+arr[2]+arr[3];k++)dp[i][j][k]=-1.0;
        }
    }
    //cout<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;
    cout<<fixed<<setprecision(12)<<sushi(arr[1],arr[2],arr[3],n)<<endl;
}


int main() {

    int t = 1;

    //Fast_io;

    //cin >> t;
    int c = 1;
    //int n;
    while (t--) {
       // if(n==0)break;
        //cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}
