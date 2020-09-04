#include<iostream>
#include<vector>
using namespace std;
#include<bits/stdc++.h>
int solve(int n,vector<int>A){
    
    vector<int> dp(n,0);
    sort(A.begin(),A.end());
    vector<pair<int,int>> B;
    int i=0;
    while (i<n) {
        int a = A[i];
        int j = i+1;
        while (j<n && A[j] == a)
            j++;
        B.push_back(make_pair(a,j-i));
        i = j;
    }
    if (B.size() == 1) {
        return B[0].first*B[0].second;
    }
    dp[0] = B[0].first*B[0].second;
    if (B[1].first == B[0].first+1) {
        dp[1] = max(dp[0],B[1].first*B[1].second);
    }
    else {
        dp[1] = dp[0]+B[1].first*B[1].second;
    }
    for(int i = 2; i<B.size(); i++){
        if (B[i].first == B[i-1].first+1) {
            dp[i] = max(dp[i-1], dp[i-2]+B[i].first*B[i].second);
        }
        else {
            dp[i] = dp[i-1]+B[i].first*B[i].second;
        }
        
    }
    
    return dp[B.size()-1];
}

int n;
vector<int>A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
