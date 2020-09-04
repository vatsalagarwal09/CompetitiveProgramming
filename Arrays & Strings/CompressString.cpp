#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>

using namespace std;
void stringCompression(char input[]) {
    // Write your code here
    int size = strlen(input);
    char ans[size] = {0};
    int count = 0;
    int j = 0;
    char check = input[0];
    for(int i = 0; i<size+1; i++){
        while(check == input[i]){
            count++;
            check = input[i];
            i++;
        }
        ans[j] = check;
        
        if(count!=1){
            ans[j+1] = count+48;
            j++;
        }
        j++;
        check = input[i];
        count = 1;
    }
    
    int k = 0;
    for(int i = 0; i<j; i++){
        input[k] = ans[i];
        k++;
    }
    
    
    input[k] = '\0';
}

int main()
{
    string str;
    cin >> str;
    cout << stringCompression(str);
}
