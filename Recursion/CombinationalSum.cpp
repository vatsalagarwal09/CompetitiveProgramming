
#include <cmath>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

void combinationSum(vector<int> ar, int i, int n, int sum, vector<vector<int> > &output, vector<int> smallOutput){

    if(sum < 0){
        smallOutput.pop_back();
        return;
    }
    
    if(i == n){
        if(sum == 0){
            output.push_back(smallOutput);   
            smallOutput.pop_back();
            return;
        } else {
            smallOutput.pop_back();
            return;
        }
        
    }
    
    combinationSum(ar, i + 1, n, sum, output, smallOutput);
    smallOutput.push_back(ar[i]);
    combinationSum(ar, i, n, sum-ar[i], output, smallOutput);
    
    
}

vector<vector<int> > combinationSum(vector<int>& ar, int sum){
    sort(ar.begin(), ar.end());
    vector<int>::iterator it;
    it = std::unique(ar.begin(), ar.end());
    ar.resize(std::distance(ar.begin(), it));
    int n = ar.size();
    vector<vector<int> > output;
    vector<int> smallOutput;
    
    
    combinationSum(ar, 0, n, sum, output, smallOutput);    
    
    return output;
}


int main() {
    int n;
    cin >> n;
    int x;
	vector<int> ar;
    for(int i = 0; i < n; i++){
        cin >> x;
    	ar.push_back(x);
    }
    int sum;
    cin >> sum;
	vector<vector<int> > res = combinationSum(ar, sum);
	if (res.size() == 0) {
		cout << "Empty";
		return 0;
	}
	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}
	}
}

