int Solution::removeDuplicates(vector<int> &A) {
    int count = 0;
    int j = 0;
    int k = 0;
    for(int i = 0;i<A.size(); i++){
            j = i+1;
            int count = 0;

        while(j < A.size() && A[j]==A[i]){
                count++;
                j++;
            }
            A[k] = A[i];
            k++;
            i += count;
        }
    return k;
}
