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
map<pair<int,int>,int>mp;
void solve() {
    int a,b,c,d;cin>>a>>b>>c>>d;
    cout<<min(mp[{a,c}]+mp[{b,d}],mp[{a,d}]+mp[{b,c}])<<endl;
}

int main() {
    mp[{1,2}]=1;
    mp[{1,3}]=1;
    mp[{1,4}]=2;
    mp[{1,5}]=3;
    mp[{1,6}]=3;
    mp[{1,7}]=4;
    mp[{2,1}]=1;
    mp[{2,3}]=2;
    mp[{2,4}]=1;
    mp[{2,5}]=2;
    mp[{2,6}]=2;
    mp[{2,7}]=3;
    mp[{3,2}]=2;
    mp[{3,1}]=1;
    mp[{3,4}]=1;
    mp[{3,5}]=2;
    mp[{3,6}]=2;
    mp[{3,7}]=3;
    mp[{4,2}]=1;
    mp[{4,3}]=1;
    mp[{4,1}]=2;
    mp[{4,5}]=1;
    mp[{4,6}]=1;
    mp[{4,7}]=2;
    mp[{5,2}]=2;
    mp[{5,3}]=2;
    mp[{5,4}]=1;
    mp[{5,1}]=3;
    mp[{5,6}]=2;
    mp[{5,7}]=1;
    mp[{6,2}]=2;
    mp[{6,3}]=2;
    mp[{6,4}]=1;
    mp[{6,5}]=2;
    mp[{6,1}]=3;
    mp[{6,7}]=1;
    mp[{7,2}]=3;
    mp[{7,3}]=3;
    mp[{7,4}]=2;
    mp[{7,5}]=1;
    mp[{7,6}]=1;
    mp[{7,1}]=4;
    mp[{1,1}]=0;
    mp[{3,3}]=0;
    mp[{4,4}]=0;
    mp[{5,5}]=0;
    mp[{6,6}]=0;
    mp[{7,7}]=0;
    mp[{2,2}]=0;
    int t = 1;

    Fast_io;

    cin >> t;
    int c = 1;
    //int n;
    while (t--) {
       
        solve();
    }
    return 0;
}
