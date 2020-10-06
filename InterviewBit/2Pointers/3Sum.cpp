int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int newTarget = B;
    int finalI = -1;
    int finalJ = -1;
    int finalK = -1;
    int minDiff = INT_MAX;
    for(int i = 0; i<A.size()-2; i++){
        newTarget = B - A[i];
        int j = i+1;
        int k = A.size()-1;
        while(j<k){
            if(A[j] + A[k] == newTarget){
                return A[i] + A[j] + A[k];
            } else if(A[j]+A[k] < newTarget){
                j++;
                if(j==k){
                    j--;
                    break;
                }
            } else {
                k--;
                if(j==k){
                    k++;
                    break;
                }
            }
        }
        
        if(abs(minDiff) > abs(B - A[i] - A[j] - A[k])){
            minDiff = B - A[i] - A[j] - A[k];
            finalI = i;
            finalJ = j;
            finalK = k;
        }
    }
    
    return A[finalI] + A[finalJ] + A[finalK];
}

