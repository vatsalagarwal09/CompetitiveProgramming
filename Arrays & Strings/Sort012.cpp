#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int arr[], int n){
    int temp1 = 0, temp2 = 0, k = 0, l = n-1;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            temp1 = arr[k];
            arr[k] = arr[i];
            arr[i] = temp1;
            k++;
        } else if(arr[i] == 2 && i<=l){
            temp2 = arr[l];
            arr[l] = arr[i];
            arr[i] = temp2;
            l--;
            if(temp2 == 0 || temp2 == 2){
                i--;
            }     

        }
        
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}
