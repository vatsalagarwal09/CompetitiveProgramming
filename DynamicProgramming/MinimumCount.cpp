#include <bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
int minCount(int n){
    int *dp = new int[n+1];
    
    for(int i = 0; i<=n; i++){
        dp[i] = 0;
    }
    
    for(int i = 1; i<=n; i++){
        int x = 1;
        dp[i] = dp[i-1] + 1;
        x++;
        while(pow(x,2) <= i){
            int a = pow(x,2);
            dp[i] = min(dp[i], dp[i-a] + 1);
            x++;
        }
    }
    
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}

