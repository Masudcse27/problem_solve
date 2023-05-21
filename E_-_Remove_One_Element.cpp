#include <bits/stdc++.h>
using namespace std;
#define READ  freopen("in.txt", "r", stdin);
#define WRITE  freopen("out.txt", "w", stdout);
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
ll mod=1000000007;

void solve() {
    int n;cin>>n;
    vector<ll>v(n),ser(n,0),pre(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    pre[0]=1;
    ll ans=1;
    for(int i=1;i<n;i++){
        if(v[i]>v[i-1])pre[i]=pre[i-1]+1;
        else pre[i]=1;
        ans=max(ans,pre[i]);
    }
    ser[n-1]=1;
    for(int i=n-2;i>0;i--){
        if(v[i]<v[i+1])ser[i]=ser[i+1]+1;
        else ser[i]=1;
    }
    
    for(int i=1;i<n-1;i++){
        if(pre[i]==1&&v[i-2]<v[i]){
            ans=max(ans,pre[i-2]+ser[i]);
        }
        if(pre[i]==1&&v[i-1]<v[i+1]){
            ans=max(ans,pre[i-1]+ser[i+1]);
        }
    }
    cout<<ans<<endl;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;

    // Fast_io;

    //scanf("%d\n", &t);
    int c = 1;
    while (t--) {
        //printf("Case %d: ", c++);
        solve();
    }
    return 0;
}