#include<iostream>
#include<string.h>
using namespace std;

void breakWords(char* S)
{
    int j = 0;
    int count = 0;
    int i = 0;
    int n = strlen(S);
    while(i<=n){
        n = strlen(S);
        j = i;
        while(S[i] != ' ' || S[i] != '\0'){
            i++;
        }
        count = i-j;
        if(count%2 == 0){
            int space = j + (count)/2;    
            for(int z = n; z>=space; z--){
                S[z+1] = S[z];
            }
            S[space] = ' '; 
            i++;
     
        }
        
        i++;
    }
    
}

int main()
{
	char str[100000];
	cin.getline(str,100000);
	breakWords(str);
	cout<<str;
}

