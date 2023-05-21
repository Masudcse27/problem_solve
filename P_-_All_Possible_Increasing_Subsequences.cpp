#include<bits/stdc++.h>
#define maxre 150005
#define ll long long
#define mod 1000000007
#define endl '\n'
#define READ freopen("in.txt", "r", stdin);
#define WRITE  freopen("out.txt", "w", stdout);
#define Fast_io     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
ll tree[maxre*4];
ll arr[maxre];
void init(ll n,ll s,ll e){
    
    if(s==e){
        tree[n]=1;
        //cout<<e<<"pass"<<n<<endl;
        return;
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid=(s+e)/2;
    init(left,s,mid);
    init(right,mid+1,e);
    tree[n]=tree[left]+tree[right];
}
ll query(ll n,ll s,ll e,ll i,ll j){
    if(s>j||e<i)return 0;
    if(s>=i&&e<=j)return tree[n];
    ll left=n*2;
    ll right=n*2+1;
    ll mid=(s+e)/2;
    ll p1=query(left,s,mid,i,j);
    ll p2=query(right,mid+1,e,i,j);
    //cout<<p1<<" "<<p2<<endl;
    return ((p1+p2)%mod+mod)%mod;
}
void update(ll n,ll s,ll e,ll i,ll j){
     if (i>e||i<s)
        return;
    if (s==i&&e==i) {
        tree[n]=j;
        //cout<<tree[n]<<"p \n";
        return;
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid=(s+e)/2;
    update(left,s,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[n]=tree[left]+tree[right];
    //cout<<tree[n]<<"p"<<endl;
}
int main(){
Fast_io;
READ;
WRITE;
ll t,cas=1;cin>>t;
while(t--){
    ll n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    ll nn=n;
    cout<<"Case "<<cas++<<": \n";
    memset(tree,0,sizeof tree);
    
    vector<char>vc(q+5);
    vector<ll>vin(q);
    for(int i=0;i<q;i++){
        cin>>vc[i]>>vin[i];
        if(vc[i]=='a'){
            nn++;
            arr[nn]=vin[i];
        }
    }
    init(1,1,nn);
    //for(int i=0;i<n*3;i++)cout<<tree[i]<<" ";cout<<endl;
    for(int i=0;i<q;i++){
       
        if(vc[i]=='a'){
            n++;
            //update(1,1,n,n,1);
            //arr[n]=p;
            //for(int i=1;i<n*3;i++)cout<<tree[i]<<" ";cout<<endl;
        }
        else{
            ll l=1,h=n;
            ll ans=0;
            while (l<=h){
                ll mid=(l+h)/2;
                ll reans=query(1,1,nn,1,mid);
                if(reans==vin[i]){
                    ans=mid;
                    break;
                }
                else if(reans<vin[i])l=mid+1;
                else h=mid-1;
            }
            if(ans==0)cout<<"none\n";
            else{
                cout<<arr[ans]<<endl;
                update(1,1,nn,ans,0);
                //for(int i=0;i<n*3;i++)cout<<tree[i]<<" ";cout<<endl;
            }
        }
    }
    

}
return 0;
}
