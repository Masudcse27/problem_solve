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
vector<ll>v1;
map<ll,bool>mp;
vector<int>v(20);
void Sum(int s,int e,ll sum,bool fl){
    if(s>=e){
        if(fl)
        v1.push_back(sum);
        else mp[sum]=true;
        return;
    }
    Sum(s+1,e,sum,fl);
    Sum(s+1,e,sum+v[s],fl);
    Sum(s+1,e,sum+v[s]*2,fl);
}
void solve() {
   int n,k;cin>>n>>k;
   vector<pair<int,int>>pos,nag;
   for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    if(a<0)nag.push_back({-a,b});
    else pos.push_back({a,b});
   }
   sortall(pos);
   sortall(nag);
   ll ans=0,re=0;
   for(int i=pos.size()-1;i>=0;i--){
    if(re+pos[i].second<k&&re){
        re+=pos[i].second;
        //cout<<re<<endl;
        continue;
    }
    ll need=pos[i].second;
    if(re)need-=(k-re);
     ll mov=need/k;
     ans+=(pos[i].first*mov)*2;
     re=need%k;
     if(re)ans+=pos[i].first*2;
     //cout<<re<<" "<<mov<<" "<<need<<endl;;
   }
   //cout<<ans<<endl;
   re=0;
   for(int i=nag.size()-1;i>=0;i--){
    if(re+nag[i].second<k&&re){
        re+=nag[i].second;
        continue;
    }
    ll need=nag[i].second;
    if(re)need-=(k-re);
     ll mov=need/k;
     ans+=(nag[i].first*mov)*2;
     re=need%k;
     if(re)ans+=nag[i].first*2;
   }
   cout<<ans<<endl;
}

int main() {

    int t = 1;

    Fast_io;

    //cin >> t;
    int c = 1;
    //int n;
    while (t--) {
        //cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}
