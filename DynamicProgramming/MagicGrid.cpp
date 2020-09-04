#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int k = 0; k<n; k++){
        int r, c;
        cin >> r >> c;
        int **input = new int*[r];
        for(int i = 0; i<r; i++){
            input[i] = new int[c];
            for(int j = 0; j<c; j++){
                cin >> input[i][j];
            }
        }
        
        int **output = new int *[r];
        for(int i = 0; i<r; i++){
            output[i] = new int[c];
            for(int j = 0; j<c; j++){
                output[i][j] = 0;
            }
        }
        
        output[r-1][c-1] = 1;
        
        for(int j = c-2; j>=0; j--){
            output[r-1][j] = output[r-1][j+1] - input[r-1][j];
            if(output[r-1][j] <= 0){
                output[r-1][j] = 1;
            }
        }
        
        for(int i = r-2; i>=0; i--){
            output[i][c-1] = output[i+1][c-1] - input[i][c-1];
            if(output[i][c-1] <= 0){
                output[i][c-1] = 1;
            }            
        }
        
        for(int i = r-2; i>=0; i--){
            for(int j = c-2; j>=0; j--){
                output[i][j] = min(output[i+1][j], output[i][j+1]) - input[i][j];
                if(output[i][j] <= 0){
                    output[i][j] = 1;
                }
            }
        }
        
        cout << output[0][0] << endl;

    }
    
    
    return 0;
}

