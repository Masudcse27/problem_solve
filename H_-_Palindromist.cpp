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
const ll m = 1e9 + 9;
const ll p = 97;
const ll p2=1000003;

long long p_pow = 1;
long long p_pow2 = 1;
long long pp_pow = 1;
long long pp_pow2 = 1;
//vector<ll>f_hesh(1000005),r_hesh(1000005),power(1000005);
pair<ll,ll> fow_hash(char s,ll h_value,ll h_value2,int t) {
    if(t==1){
        h_value = (h_value +( (s-'a' + 1) * p_pow)%m) % m;
        h_value2 = (h_value2 +( (s-'a' + 1) * pp_pow)%m) % m;
    }
    else{
        h_value=((s-'a'+1)+(h_value*97)%m)%m;
        h_value2=((s-'a'+1)+(h_value2*1000003)%m)%m;
    }
    p_pow = (p_pow * p) % m;
    pp_pow=(pp_pow*p2)%m;
    
    return {h_value,h_value2};
}
pair<ll,ll> rev_hash(char s,ll h_value,ll h_value2,int t) {
    if(t==0){
        h_value = (h_value +( (s-'a' + 1) * p_pow2)%m) % m;
        h_value2 = (h_value2 +( (s-'a' + 1) * pp_pow2)%m) % m;
    }
    else{
        h_value=((s-'a'+1)+(h_value*97)%m)%m;
        h_value2=((s-'a'+1)+(h_value2*1000003)%m)%m;
    }
    p_pow2 = (p_pow2 * p) % m;
    pp_pow2=(pp_pow2*p2)%m;
    
    return {h_value,h_value2};
}
void solve() {
    string str;cin>>str;
    string st=str;
    reverse(st.begin(),st.end());
    int q;cin>>q;
    int n=str.size();
    ll h11=0,h12=0,h21=0,h22=0;
    for(int i=0;i<n;i++){
        pair<ll,ll>pll=fow_hash(str[i],h11,h12,1);
        h11=pll.first;
        h12=pll.second;
        //cout<<h11<<" "<<h12<<endl;
    }
    //cout<<st<<endl;
    for(int i=0;i<n;i++){
         pair<ll,ll>pll=rev_hash(st[i],h21,h22,0);
        h21=pll.first;
        h22=pll.second;
        //cout<<h21<<" "<<h22<<endl;
    }
    //cout<<h11<<" "<<h21<<endl<<h12<<" "<<h22<<endl;;
    while (q--){
        char a,b;
        int p;
        cin>>a>>b>>p;
        //cout<<a<<" "<<b<<" "<<p<<"\n";
        int t=1;
        if(a=='L')t=0;
        for(int i=0;i<p;i++){
            pair<ll,ll>pll=fow_hash(b,h11,h12,t);
            h11=pll.first;
            h12=pll.second;
            //cout<<h11<<" "<<h12<<endl;
        }
        for(int i=0;i<p;i++){
             pair<ll,ll>pll=rev_hash(b,h21,h22,t);
            h21=pll.first;
            h22=pll.second;
        }
        //cout<<h11<<" "<<h21<<"\n"<<h12<<" "<<h22<<endl;
        if(h11==h21&&h12==h22)cout<<"Yes\n";
        else cout<<"No\n";
    }
    
        
}

int main() {

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