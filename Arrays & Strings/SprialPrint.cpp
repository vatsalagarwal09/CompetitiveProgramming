#include <iostream>
using namespace std;

void spiralPrint(int input[][1000], int row, int col){

    int a = min(row, col);
    int i = 0, j= 0, k = 0;
    for(i = 0; i<(a+1)/2; i++){
        for(j = i; j<col-i; j++){
            cout << input[i][j] << " ";
        }    
        
        j--;
        for(k = i+1; k<row-i; k++){
            cout << input[k][j] << " ";
        }
        j--, k--;
        for(j;j>i; j--){
            cout << input[k][j] << " ";
        }
        for(k; k>j; k--){
            cout << input[k][j] << " ";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}
