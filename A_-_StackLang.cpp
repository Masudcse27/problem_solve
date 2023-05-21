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
ll sumGc(int n,int i,int j){
    if(j==n)return __gcd(i,j);
    return __gcd(i,j)+sumGc(n,i,j+1);
}
ll sumG(int n,int i){
    //cout<<i<<endl;
    if(i==n)return 0;
    return sumGc(n,i,i+1)+sumG(n,i+1);
}
const int mx = 1e6;
int rev=0;
ll sum=0;
deque<ll>stak;
void PUSH(int a){
    if(rev){
        if(stak.size()>=mx){
            sum-=stak.front();
            stak.pop_front();
        }
        stak.push_back(a);
        sum+=a;
        
    }
    else{
        if(stak.size()>=mx){
            sum-=stak.back();
            stak.pop_back();
        }
        stak.push_front(a);
        sum+=a;
        
    }
}
void POP(){
    if(stak.size()){
        if(rev){
            sum-=stak.back();
            stak.pop_back();
        }
        else{
           sum-=stak.front();
           stak.pop_front();
        }
    }
}
void PRINT(){
    if(stak.size()){
        if(rev)cout<<stak.back()<<endl;
        else cout<<stak.front()<<endl;
    }
    else cout<<'-'<<endl;
}
void revRepeat(int a){
    int sz=stak.size();
    while(a--&&stak.size()<mx){
        int i=0;
         while(i<sz&&stak.size()<mx){
            stak.push_front(stak[stak.size()-1-i]);
            i++;
         }
    }
}
void fRepeat(int a){
    int sz=stak.size();
    while(a--&&stak.size()<mx){
        int i=0;
     while(i<sz&&stak.size()<mx){
        stak.push_back(stak[i]);
        i++;
     }
    }
}
void solve() {
    string str;
    while(cin>>str){
        if(str=="PUSH"){
            int a;cin>>a;
            PUSH(a);
        }
        else if(str=="POP"){
            POP();
        }
        else if(str=="PRINT"){
            PRINT();
        }
        else if(str=="SIZE"){
            cout<<stak.size()<<endl;
        }
        else if(str=="SUM"){
            cout<<sum<<endl;
        }
        else if(str=="REPEAT"){
            int a;cin>>a;
            if(stak.size()){
            if(rev){
                revRepeat(a);
            }
            else fRepeat(a);
            }
        }
        else{
           rev^=1;
        }
    }
}

int main() {

    int t = 1;

    //Fast_io;

    //cin >> t;
    int c = 1;
    //int n;
    while (t--) {
        //cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}

/*
PUSH 1
PUSH 3
PUSH 7
PRINT
REVERSE
REPEAT 1
PRINT
SIZE
POP
SUM
*/
