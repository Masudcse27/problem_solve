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
#define READ  freopen("in.txt", "r", stdin);
#define WRITE  freopen("out.txt", "w", stdout);
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
void A(int n,int p){
    if(p>n)return;
    cout<<"sin("<<p;
    if(p<n){
    if(p%2){
        cout<<"-";
    }
    else cout<<"+";
    }
    A(n,p+1);
    cout<<")";
}
map<int,string>x;


void S(ll n,int i){
    //cout<<n<<endl;
      if(i==1&&n<10){
        cout<<" "<<n<<x[i];
        return;
      }
      else if(i!=1&&n<100){
        cout<<" "<<n<<x[i];
        return;
      }

      int a;
      if(i==1){
        a=n%10;
        S(n/10,i+1);
      }
      else{
        a=n%100;
        S(n/100,(i+1==5?1:i+1));
      }
      if(a>0)
        cout<<" "<<a<<x[i];
      else if(i==4){
        cout<<x[i];
      }
}
void solve() {
    x[4]=" kuti";
    x[1]=" shata";
    x[2]=" hajar";
    x[3]=" lakh";
    x[0]="";
    ll n,c=1;
    while (scanf("%lld",&n)!=EOF){
        printf("%4d.",c++);
        S(n,0);
        cout<<endl;
    }

}

int main() {
  READ;
  WRITE;
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
