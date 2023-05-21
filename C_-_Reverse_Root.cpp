#include<bits/stdc++.h>
using namespace std;
int n,m;
void pre(){
    long long x;
    if(cin>>x){
        pre();
         cout<<fixed<<setprecision(4)<<sqrt(x)<<endl;
    }   
}
int main(){
 pre();
}
