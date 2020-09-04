#include <bits/stdc++.h>
using namespace std;

int count(string input,int size){
    int *output = new int[size+1];
    output[0] = 1;
    output[1] = 1;
    
    long long int a = pow(10, 9) + 7;
    
    for(int i = 2; i<=size; i++){
        if(input[i] != '0'){
            output[i] = output[i-1];
        }
        
        int b = (input[i-2]-'0') * 10 + (input[i-1]-'0');
        if(b <= 26 && b>=10){
            output[i] = (output[i] + output[i-2]) % a;
        }
    }
    
    int ans = output[size];
    delete []output;
    return ans;
    
}

int main()
{
    string s;
    cin >> s;
    while(s!="0"){
        int ans=count(s,s.size());
        cout << ans << endl;
        cin >> s;
    }
    return 0;
}

