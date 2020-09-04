
#include <bits/stdc++.h>
#include<unordered_map>
#include<algorithm>
using namespace std;
void PairSum(int *input, int n){
    unordered_map<int,int> m;
    for(int i = 0; i<n; i++){
        if(m.count(-input[i]) > 0){
            int k1 = input[i];
            int k2 = -k1;
            int kmin = min(k1, k2);
            int kmax = max(k1, k2);
            int k = m[k2];
            while(k!=0){
                cout << kmin << " " << kmax << endl;
                k--;
            }            
        }
        if(m.count(input[i]) == 0){
            m[input[i]] = 1;
            continue;
        }
        
        m[input[i]]++;        
    }
}


int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	pairSum(arr, n);

	delete[] arr;

	return 0;
}
