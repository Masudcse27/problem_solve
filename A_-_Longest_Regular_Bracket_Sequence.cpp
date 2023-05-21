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
const int mod= 1000003;

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
map<char,string>mp;
void solve() {
    string str;
    cin>>str;
    int n=str.size();
    map<int,int>mp,mp2;
    int cnt=0,mxlen=0,len=0;
    //cout<<n<<endl;
    for(int i=0;i<n;i++){
        if(str[i]=='('){
            cnt++;
            len++;
        }
        else{
            cnt--;
            len++;
            if(cnt<0){
                //cout<<i<<endl;
                len--;
                mp[len]++;
                mxlen=max(mxlen,len);
                len=0;
                cnt=0;
            }
        }        
    }
    if(cnt==0){
        mp[len]++;
        mxlen=max(mxlen,len);
    }
    reverse(str.begin(),str.end());
    cnt=0,len=0;
    for(int i=0;i<n;i++){
        if(str[i]==')'){
            cnt++;
            len++;
        }
        else{
            cnt--;
            len++;
            if(cnt<0){
                //cout<<i<<endl;
                len--;
                mp2[len]++;
                mxlen=max(mxlen,len);
                len=0;
                cnt=0;
            }
        }
    }
    if(cnt==0){
        mp2[len]++;
        mxlen=max(mxlen,len);
    }
    if(mxlen==0){
        cout<<"0 1\n";
    }
    else cout<<mxlen<<" "<<max(mp[mxlen],mp2[mxlen])<<endl;
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
