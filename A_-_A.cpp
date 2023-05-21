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

void solve() {
  map<int,string>mp;
  string str,st;
  getline(cin,str);
  int cnt=0;
  stringstream s(str);
  while (s>>st) {
    cnt++;
  }
  int n;cin>>n;
  for(int i=0;i<n;i++){
    cin>>st;
    mp[i+1]=st;
  }
  vector<int>v(n),fst,sec;
  for(int i=0;i<n;i++)v[i]=i;
  int cnt2=0;
  auto i=v[0];
  cnt--;
  while (cnt2<n){
    //cout<<cnt<<endl;
    i+=cnt;
    i%=v.size();
    if(cnt2%2==0){
        fst.push_back(v[i]);
        v.erase(v.begin()+i);
    }
    else{
        sec.push_back(v[i]);
        v.erase(v.begin()+i);
    }
    cnt2++;
  }
  cout<<fst.size()<<endl;
  for(auto x:fst){
    cout<<mp[x+1]<<endl;
  }
  cout<<sec.size()<<endl;
  for(auto x:sec){
    cout<<mp[x+1]<<endl;
  }
  
  
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
