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
struct nod{
    int a,b;
};
bool comp(nod x,nod y){
    if(x.a==y.a)return x.b>y.b;
    return x.b<y.b;
}
void solve() {
    //cout<<"pass ";
   int n;cin>>n;
   //cout<<n<<" \n";
   vector<int>v(n),pos(n+5);
   for(int i=0;i<n;i++)cin>>v[i];
   int cnt=0,p=-1,flag=false;
   for(int i=0;i<n;i++){
        int k=v[i];
        pos[k]=i;
        if(!flag&&k==i+2&&v[i+1]==i+1){
            flag=true;
            p=i;
        }
   }
   //cout<<flag<<" "<<p<<" ";
   for(int i=0;i<n;i++){
    //cout<<i<<" ";
    if(flag&&p==i){
        i++;
        continue;
    }
    int k=v[i];
    if(k==i+1)continue;
    //cout<<k;
    // if(!flag&&k==i+2&&v[i+1]==i+1){
    //     flag=true;
    //     i++;
    //     continue;
    // }
    if(!flag&&k==i+2){
        int cp=v[i+1];
        swap(v[i+1],v[pos[i+1]]);
        pos[cp]=pos[i+1];
        flag=true;
        i++;
    }
    else if(!flag&&pos[i+1]==i+1){
        int cp=k;
        swap(v[i],v[pos[i+2]]);
        pos[cp]=pos[i+2];
        flag=true;
        i++;
    }
    else{
        int cp=v[i];
        swap(v[i],v[pos[i+1]]);
        pos[cp]=pos[i+1];
    }
    cout<<k<<v[i]<<i<<" ";
    cnt++;
   }
   if(!flag)cnt++;
   cout<<cnt<<endl;
}

int main() {

    int t = 1;

    //Fast_io;

    cin >> t;
    int c = 1;
    //int n;
    while (t--) {
        //cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}
