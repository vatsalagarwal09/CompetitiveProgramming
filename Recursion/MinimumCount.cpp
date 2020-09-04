#include<iostream>
using namespace std;
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h> 
int minCount(int n){
   
    int *dp = new int[n+1];
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i = 4; i<=n; i++){
        dp[i] = i;
        for(int x = 1; x<i; x++){
            if(pow(x,2) > i){
                break;
            } else {
                dp[i] = min(dp[i], 1 + dp[i-x*x]);
            }
        }
    }
    int result = dp[n];
    delete []dp;
    return result;
}

int main(){

  int num;
  cin >> num;
  cout << minCount(num);

}



