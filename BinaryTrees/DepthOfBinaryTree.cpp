#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#include<bits/stdc++.h>
int depthHelper(char str[], int n, int& index){
    if(index > n || str[index] == 'l'){
        return 0;
    }
    index++;
    int l = depthHelper(str, n, index);
    index++;
    int r = depthHelper(str, n, index);
    return max(l, r)  + 1;
}

int depth(char str[]) {
    int n = strlen(str);
    int index = 0;
    return depthHelper(str, n, index);
}


int main()
{
	char *str = new char[100000];
	cin>>str;
	cout<<depth(str);
	return 0;
}

