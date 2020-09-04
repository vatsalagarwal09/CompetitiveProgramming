#include <iostream>
using namespace std;

void PushZeroesEnd(int arr[], int n){

    int j = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] != 0){
            arr[j] = arr[i];
            j++;
        }
    }
    
    for(int i = j; i<n; i++){
        arr[i] = 0;
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
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}
