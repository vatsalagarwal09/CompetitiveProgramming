
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int smallestSuperSequenceHelper(char str1[], int len1, char str2[], int len2, int **output) { 
    if(len1 == 0 && len2 == 0){
        output[0][0] = 0;
        return 0;
    } else if (len1 == 0){
        output[0][len2] = len2;
        return len2;
    } else if(len2 == 0){
        output[len1][0] = len1;
        return len1;
    }
    
    if(output[len1][len2] != -1){
        return output[len1][len2];
    }
    
    if(str1[0] == str2[0]){
        output[len1][len2] = 1 + smallestSuperSequenceHelper(str1 + 1, len1 - 1, str2 + 1, len2-1,output);
    } else {
        int smallAns1 = 1 + smallestSuperSequenceHelper(str1 + 1, len1 - 1, str2, len2, output);
        int smallAns2 = 1 + smallestSuperSequenceHelper(str1, len1, str2 + 1, len2 - 1, output);
        output[len1][len2] = min(smallAns1, smallAns2);
    }    
    
    return output[len1][len2];
}
int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 

    int **output = new int*[len1+1];
    
    for(int i = 0; i<=len1; i++){
        output[i] = new int[len2+1];
        for(int j = 0; j<=len2; j++){
            output[i][j] = -1;
        }
    }

}

int main()
{
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}

