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
vector<ll>v1,v2;
vector<int>v(30);
ll n,k;
void Sum(int s,int e,ll sum,bool fl){
    if(s>=e){
        //cout<<sum<<endl;
        if(sum<=k){
        if(fl)
        v1.push_back(sum);
        else v2.push_back(sum);
        }
        return;
    }
    Sum(s+1,e,sum,fl);
    Sum(s+1,e,sum+v[s],fl);
}
void solve() {
    cin>>n>>k;
    //vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    if(n==1){
        cout<<(v[0]>k?1:2)<<endl;
        return;
    }
    Sum(0,n/2,0,1);
    Sum(n/2,n,0,0);
    sortall(v2);
    // for(auto x:v1)cout<<x<<" ";
    // //cout<<endl;
    // for(auto x:v2)cout<<x<<" ";
    // cout<<endl;
    
    ll ans=v1.size()+v2.size()-1;
    for(int i=1;i<v1.size();i++){
        int X=k-v1[i];
        int com=upper_bound(v2.begin(),v2.end(),X)-v2.begin();
        if(com==v2.size()||v2[com]>X)com--;
        //cout<<com<<endl;
        ans+=com;
    }
    //ans+=v2.size();
    cout<<ans<<endl;
    v1.clear();
    v2.clear();
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
