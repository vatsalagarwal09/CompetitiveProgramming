#include <iostream>
using namespace std;
int subsetHelper(int input[], int n, int output[][20]){
    if(n == 0){
        output[0][0] = 0;
        //output[0][1] = '\0';
        return 1;
    }    
    
    int smallAns = subsetHelper(input + 1, n-1, output);
    
    for(int i = 0; i<smallAns; i++){
        output[smallAns + i][0] = output[i][0]+1;
        output[smallAns + i][1] = input[0];
        int j = 2;
        
        for(int k = 0; k<output[i][0]; k++){
            output[smallAns+i][j] = output[i][j-1];
            j++;
        }
    }
    
    return smallAns * 2;
}


int subset(int input[], int n, int output[][20]) {
    // Write your code here
    int finalAns = subsetHelper(input, n, output);
    return finalAns;

}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

