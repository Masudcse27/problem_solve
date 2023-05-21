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
const int m = 1e9 + 9;
vector<ll>f_hesh(1000005),r_hesh(1000005),power(1000005);
void fow_hash(string const& s) {
    const int p = 31;
    long long p_pow = 31;
    power[0]=1;
    f_hesh[0]=((s[0]-'a' + 1)) % m;
    int n=s.size();
    for (int i=1;i<n;i++) {
        f_hesh[i] = (f_hesh[i-1] + (s[i]-'a' + 1) * p_pow) % m;
        power[i]=p_pow;
        p_pow = (p_pow * p) % m;
    }
}
void rev_hash(string const& s) {
    const int p = 31;
    
    long long p_pow = 31;
    int n=s.size();
    //cout<<n<<endl;
    r_hesh[n-1]=((s[n-1]-'a' + 1)) % m;
    for (int i=n-2,j=1;i>=0;i--,j++) {
        r_hesh[i] = (r_hesh[i+1] + (s[i]-'a' + 1) * power[j]) % m;
    }
}
void solve(string str) {
    fow_hash(str);
    rev_hash(str);
    int n=str.size();
    int mid=n/2;
    if(n%2&&r_hesh[mid+1]==f_hesh[mid-1]){
        cout<<str<<endl;
        return;
    }
    else if(n%2==0){
        if(r_hesh[mid]==f_hesh[mid-1]){
        cout<<str<<endl;
        return;
        }
        else if(((((r_hesh[mid+1]*31)%m)+f_hesh[0])%m)==f_hesh[mid-1]){
            cout<<str<<str[0]<<endl;
             return;
        }
    }
    mid++;
    int j,flag=false;
    for(int i=mid;i<n;i++){
        j=i-(n-i);
        ll val=(((r_hesh[i]*power[j])%m)+f_hesh[j-1])%m;
        if(val==f_hesh[i-1]){
            flag=true;
            break;
        }
        j++;
         val=(((r_hesh[i+1]*power[j])%m)+f_hesh[j-1])%m;
        if(val==f_hesh[i-1]){
            flag=true;
            break;
        }
    }
    if(!flag)j=n-1;
    cout<<str;
    for(int i=j-1;i>=0;i--)cout<<str[i];
    cout<<endl;
        
}

int main() {

    int t = 1;

    Fast_io;

    //cin >> t;
    int c = 1;
string str;
    while (cin>>str) {
        //cout << "Case " << c++ << ": ";
        solve(str);
    }
    return 0;
}