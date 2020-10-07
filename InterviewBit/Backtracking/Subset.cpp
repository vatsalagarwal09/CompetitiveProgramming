int subsetHelper(vector<int> &A, vector<vector<int>> &output, int i){
    if(A.size() == i){
        vector<int> x;
        output.push_back(x);
        return 1;
    }
    

    int smallOutput = subsetHelper(A, output, i+1);
    for(int j = 0; j<smallOutput; j++){
        vector<int> smallSubset;
        smallSubset.push_back(A[i]);
        for(int k = 0; k<output[j].size(); k++){
            smallSubset.push_back(output[j][k]);
        }
        
        output.push_back(smallSubset);
    }
    
    return 2 * smallOutput;
    
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> output;
    int result = subsetHelper(A, output, 0);
    for(int i = 0; i<output.size(); i++){
        sort(output[i].begin(), output[i].end());
    }
    sort(output.begin(), output.end());
    return output;
    
}

