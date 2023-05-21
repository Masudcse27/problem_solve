#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                              \
    tree<long long, null_type, less<long long>, rb_tree_tag, \
         tree_order_statistics_node_update>

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
    long long n, e;
    cin >> n >> e;
    set<long long> a;
    a.insert(1);
    a.insert(n);

    ordered_set ans;
    ans.insert(n);

    // for (auto it : a) {
    //     cout << it << " ";
    // }
    // cout << "\n\n";

    while(e--) {
        char f;
        cin >> f;
        if (f == 'F') {
            int k;
            cin >> k;
            cout << *ans.find_by_order(k - 1) << "\n";
        } else {
            int k;
            cin >> k;
            auto h = (a.lower_bound(k));
            if (*h == k) {
                continue;
            }
            h--;
            int l = *h;
            auto r = *a.upper_bound(k);
            // cout << l << " " << r << "\n";
            ans.erase(r - l + 1);
            ans.insert(k - l + 1);
            ans.insert(r - k);
            a.insert(k);
        }

        // for (auto it: a) {
        //     cout << it << " ";
        // }
        // cout << "h\n";
        // for (auto it: ans) {
        //     cout << it << " ";
        // }
        // cout << "\n\n";
    }
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
        cout << "Case " << c++ << ":\n";
        solve();
    }
    return 0;
}
