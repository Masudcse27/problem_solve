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

void solve() {
   int n;cin>>n;
   int arr[n+1][n+1];
   for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
        cin>>arr[i][j];
    }
   }
   int f;
   for(int i=0;i<1;i++){
    vector<int>v;
    map<int,int>mp;
    for(int j=0;j<n;j++){
        int a=arr[j][i];
        if(mp[a]==0)
        v.push_back(a);
        mp[a]++;
    }
    int s=-1;
   for(auto x:v){
    if(mp[x]>s){
        s=mp[x];
        f=x;
    }
   }
   }
   map<pair<int,int>,int>mp;
   vector<int>tr[n+5];
   for(int i=0;i<n;i++){
    for(int j=0;j<n-2;j++){
        int a=arr[i][j];
        int b=arr[i][j+1];
        if(!mp[{a,b}])tr[a].push_back(b);
        mp[{a,b}]++;
    }
   }
   cout<<f<<" ";
   for(int i=0;i<n-1;i++){
    int s=-1,a;
        for(auto x:tr[f]){
            if(mp[{f,x}]>s){
                a=x;
                s=mp[{f,x}];
            }
            else if(mp[{f,x}]==s){
                if(mp[{x,a}]>0){
                    a=x;
                }
            }
        }
        cout<<a<<" ";
        f=a;
   }
   cout<<endl;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;

    Fast_io;

     cin >> t;
    int c = 1;
    while (t--) {
        // cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}