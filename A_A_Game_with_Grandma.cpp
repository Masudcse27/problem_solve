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
int dp[1000][1000];
string str[3];
bool iswin(int i,int j,vector<int>&v){
    if(j-i<1){
        return false;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    bool ans=true,flag=false;
    for(int k=i;k<=j;k++){
        if(str[0][k]&&str[1][k]&&str[0][k+1]&&str[1][k+1]||str[2][k]&&str[1][k]&&str[2][k+1]&&str[1][k+1]){
            //flag=true;
            ans=max(iswin(k+2,j,v),iswin(i,k-1,v));
        }
        if(!ans)break;;
    }
    // if(!flag){
    //     if(sec==0)ans=true;
    //     ans=false;
    // }
    return dp[i][j]=!ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<3;i++)
    cin>>str[i];
    
    if(iswin(0,n-1,v))cout<<"Jhinuk\n";
    else cout<<"Grandma\n";
}

int main() {

    int t = 1;

    Fast_io;

    cin >> t;
    int c = 1;
    //int n;
    while (t--) {
        cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}
