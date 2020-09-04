#include<iostream>
#include<algorithm>
using namespace std;


int platformsNeeded(int arrival[], int departure[], int n) {

    sort(arrival, arrival+n);
    sort(departure, departure+n);
    
    int plat = 1, result = 1, i = 1, j = 0;
    while(i<n && j<n){
        if(arrival[i] <= departure[j]){
            plat++;
            i++;
            
            result = max(result, plat);
        } else {
            plat--;
            j++;
        }
    }
    return result;
}

int main()
{
	int n;
	cin>>n;
    int* arr=new int[n];
    int* dep=new int[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	for(int i=0;i<n;i++)
    {
    	cin>>dep[i];
	}
    cout<< platformsNeeded(arr, dep, n);
}

