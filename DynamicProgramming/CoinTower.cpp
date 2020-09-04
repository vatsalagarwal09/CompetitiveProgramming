#include<iostream>
#include<string>
using namespace std;
string solve(int n, int x, int y)
{
 
    int *dp = new int[n+1];
    
    dp[0] = 0;
    dp[1] = 1;
    dp[x] = 1;
    dp[y] = 1;
    
    for(int i = 2; i<=n; i++){
        if(i==x || i==y){
            continue;
        }
        int smallAns1 = dp[i-1] ^ 1;
        
        int smallAns2 = 0;
        if(i-x > 0){
            smallAns2 = dp[i-x] ^ 1;
        }
        
        int smallAns3 = 0;
        if(i-y > 0){
            smallAns3 = dp[i-y] ^ 1;
        }
         
        dp[i] = max(smallAns1, max(smallAns2, smallAns3));
    }
    
    if(dp[n] == 0){
        return "Whis";
    } else {
        return "Beerus";
    }
}
int n,x,y;
int main()
{
	cin>>n>>x>>y;
	cout<<solve(n,x,y)<<endl;
}
