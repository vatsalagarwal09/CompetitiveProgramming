#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool subArrayZeroSum(int input[], int n) {
		
    int maxSize = -1;
    int leftsum[n];
    for(int i = 0; i<n; i++){
        leftsum[i] = -1;
    }
    
    leftsum[0] = input[0];
    
    for(int i = 1; i<n ; i++){
        leftsum[i] = leftsum[i-1] + input[i];
    }
    
    unordered_map<int, int> m;
    
    for(int i = 0; i<n ;i++){
        if(m.count(leftsum[i]) == 0){
            m[leftsum[i]] = 1;
        } else {
            return true;
        }
    }
    
    return false;
}

int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    bool val = subArrayZeroSum(input, n);
    if(val)
    {
        cout<<"true";
    }
    else
    {
            cout<<"false";
    }
    return 0;
}


