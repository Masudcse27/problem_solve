

/*
Name : Masud Bhuiyan
Id : 011183071
*/


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
struct Item{
    string name;
    double w, v;
};

bool comp(Item i1, Item i2){
    return (double)i1.v/i1.w > (double)i2.v/i2.w;
}

double frac_knapsack(double W,vector<Item> &items){
    double cap_left=W,profit=0.0,co_w=0.0;
    int i=0,n=items.size();

    while(cap_left > 0.0 && i<n){
        if(items[i].w<=0.0){
            i++;
            continue;
        }
        if(W<=co_w)break;
        double frac=min(1.0,cap_left/items[i].w);
        profit+=(frac*items[i].v);
        cap_left-=frac*items[i].w;
        //cout<<cap_left<<endl;
        co_w+=frac*items[i].w;
        cout<< fixed<<setprecision(1);
        //Taking gold-dust: 8.0 kg 2000.0 taka
        //if(profit>0.0)
        cout<<"Taking "<<items[i].name<<": "<<frac*items[i].w<<" kg "<<(frac*items[i].v)<<" taka\n";
        items[i].w-=frac*items[i].w;
        items[i].v-=(frac*items[i].v);
        i++;
    }
return profit;
}
int main() {
    Fast_io;
    int n;cin>>n;
    vector<Item> items(n);
    for(int i=0;i<n;i++){
        cin>>items[i].name>>items[i].v>>items[i].w;
    }
    sort(items.begin(), items.end(), comp);
    int m,s=0;
    cin>>m;
    int i=1;
    while(i<=m){
        double w;cin>>w;
        double ans=frac_knapsack(w,items);
        cout<< fixed<<setprecision(1);
        cout<<"Thief "<<i++<<" profit: "<<ans<<" taka"<<endl;
    }
    cout<<"Total "<<m<<" thieves stole from the warehouse.\n";
    int flag=true;
    //for(int i=0;i<1;i++){
        for(int i=0;i<n;i++){
            if(items[i].v>0.0&&flag){
                cout<<"Still following items are left\n";
                flag=false;
            }
            if(!flag)
            cout<<items[i].name<<" "<<items[i].w<<" kg "<<items[i].v<<" taka.\n";
        }
    //}

    return 0;
}