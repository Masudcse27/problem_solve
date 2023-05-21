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
#define pb push_back
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
vector<int>g[6],val(5,0),pos(5);
int tsort(){
    int st=0;
    for(int i=0;i<5;i++){
        if(val[i]==0)pos[st++]=i;
    }
        int s=0;
    while (s<st){
        int u=pos[s++];
        for(auto v:g[u]){
            val[v]--;
            if(val[v]==0)pos[st++]=v;
        }
    }
    return st;
}
void solve() {
  int n,m;cin>>n>>m;
  vector<int>a(n+5,1),b(n+5,1);
  cout<<"pass\n";
  for(int i=0;i<m;i++){
    char c,l,r,h;cin>>c>>l>>r>>h;
    if(c=='a'){
        if(l>r){
            a[1]+=h;
            a[r+1]-=h;
            a[l]+=h;
        }
        else{
            a[l]+=h;
            a[r+1]-=h;
        }
    }
    else{
        if(l>r){
            b[1]+=h;
            b[r+1]-=h;
            b[l]+=h;
        }
        else{
            b[l]+=h;
            b[r+1]-=h;
        }
    }
  }
  ll suma=0,sumb=0,ans=0;
  cout<<"PASS\n";
  for(int i=1;i<=n;i++){
    suma+=a[i];
    sumb=(sumb+b[i]);
    int bb=sumb%7;
    if(suma>bb){
        ans+=(suma*bb)-((bb*(bb+1))/2);
    }
  } 

  cout<<ans<<endl; 
}

int main() {

    int t = 1;

    //Fast_io;

    //cin >> t;
    int c = 1;
    int n,q;
    while (t--) {   
        solve();
    }
    return 0;
}
