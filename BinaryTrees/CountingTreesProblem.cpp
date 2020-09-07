#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;
ll anc[510][510] = {0};
    
int main() {    
    ll n, K;
    cin >> n >> K;
    
    ll a[1000];
    ll par[1000];
    
    for(ll i = 1; i<=n; i++){
        cin >> a[i];
    }
    
    
    for(ll i = 2; i<=n; i++){
        cin >> par[i];
    }
    
    for(ll i = 2; i<=n; i++){
        ll x = i;
        while(x != 1){
            x = par[x];
            anc[x][i] = 1;
        }
    }
    
    ll ans = 0;
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=n ; j++){
            for(ll l = 1; l<=n; l++){
                if(i==j || j==l || i==l){
                    continue;
                }
                
                if(anc[i][j] && anc[i][l] && a[i] + a[j] + a[l] >= K){
                    ans++;
                }
            }
        }
    }
    
    cout << ans/2 << endl;
    return 0;
}



