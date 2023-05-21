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
int s,e;
int maxSubArraySum(vector<int>&a, int size){
    int max_so_far = INT_MIN, max_ending_here = 0;
  int s1=0;
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here){
            max_so_far = max_ending_here;
            s=s1,e=i;
        }
        if (max_ending_here < 0){
            max_ending_here = 0;
            s=i+1;
        }
    }
    return max_so_far;
}

void solve() {
    int n,k;cin>>n>>k;
    string str,st;
    cin>>str>>st;
    vector<int> arr1(30,0),arr2(30,0);
    for(int i=0;i<n;i++){
        int a=str[i]-'a',b=st[i]-'a';
        arr1[a]++;
        arr2[b]++;
    }
    int flag=true;
    for(int i=0;i<30;i++){
        if((arr1[i]!=arr2[i])){
            //cout<<
            flag=false;break;
        }
    }
    if(!flag){
        cout<<"NO\n";
    }
    else if(n>=k*2||str==st){
        cout<<"YES\n";
    }
    else if(n==(k*2)-1){
        if(str[k-1]==st[k-1]){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    else if(n==k+1){
        flag=true;
        for(int i=1;i<n-1;i++){
            if(str[i]!=st[i]){
                flag=false;
                break;
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    else if(n<=k) cout<<"NO\n";
    else{
        int j=max(0,k-(k-(n-k)));
        flag=true;
        for(int i=k-1;i>=j;i--){
            if(str[i]!=st[i]){
                flag=false;
                break;
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    
}

int main() {

    int t = 1;

    Fast_io;

    cin >> t;
    int c = 1;
    //int n;
    while (t--) {
        //cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}