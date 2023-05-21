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

int parent[1000000 + 1];
int sz[1000000 + 1];
vector<int> ans;
vector<int> vis(1000000 + 1, 0);
int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void union_set(int u, int v) {
    int a = find(u);
    int b = find(v);
    if(a==b)return;
    if (b < a) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    map<string, int> x;
    int cnt=0,cnt2=0;
    vector<string>v(n);
    for(auto &i:v)cin>>i;
    for(int i=0;i<n;i++){
        string str;cin>>str;
        if(x[str]){
            cnt++;
            cnt2--;
        }
        else{
            x[str]++;
            cnt2++;
        }
        if(x[v[i]]){
            cnt++;
            cnt2--;
        }
        else{
            x[v[i]]++;
            cnt2++;
        }
        if(!cnt2){
            ans.push_back(cnt);
            cnt=0;
        }
    }
    for(auto i:ans)cout<<i<<" ";cout<<endl;
    ans.clear();
}

int main() {
     
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