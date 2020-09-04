#include<iostream>
#include<climits>
using namespace std;

void Leaders(int* arr,int len)
{
    int n = len;
    int j = n-1;
    bool ans[n];
    for(int i = 0; i<n; i++){
        ans[i] = false;
    }
    
    ans[n-1] = true;
    
    for(int i = n-1; i>0; i--){
        if(arr[i-1] >= arr[i] && arr[i-1] >= arr[j]){
            ans[i-1] = true;
            j=i-1;
        }
    }
    
    for(int i = 0; i<n; i++){
        if(ans[i] == true){
            cout << arr[i] << " ";
        }
    }
    
}


int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}

