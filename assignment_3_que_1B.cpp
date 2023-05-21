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
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
vector<int>arr;
int dp[1000][1000];

int subset_sum(int i,int k){
    if(k==0)return 1;
    if(i<0)return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    return dp[i][k]=subset_sum(i-1,k-arr[i])||subset_sum(i-1,k);
}
int main() {
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr.push_back(a);
    }
    int k;cin>>k;
    if(subset_sum(n-1,k))cout<<k<<" is a subset sum\n";
    else cout<<k<<" is not a subset sum\n";
    return 0;
}
