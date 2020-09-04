#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
vector<int> longestSubsequence(int *arr, int n){
    unordered_map<int, bool> m;
    vector<int> v;
    
    for(int i = 0; i<n ;i++){
        m[arr[i]] = true;
    }
    
    int max_length = 0, length = 0;
    int max_start = 0, start = 0;    
    int start_index = 0, max_start_index;
    
    for(int i = 0; i<n; i++){
        if(m[arr[i]] == true){
            length = 1;
            int k = arr[i];
            start = k;
            start_index = i;
            m[k] = false;
            while(m.count(k+1) > 0){
                length++;
                k++;
                m[k] = false;
                
            }
        
            k = arr[i];
            while(m.count(k-1) > 0){
                length++;
                k--;
                start = k;
                m[k] = false;
                int j = i;
                while(j<n){
                    if(arr[j] == k){
                        start_index = j;
                        break;
                    }
                    j++;
                }   
            
            }

            if(length > max_length){
                max_length = length;
                max_start = start;
                max_start_index = start_index;
            } 
            

            if(length == max_length && start_index < max_start_index){
                max_length = length;
                max_start = start;
                max_start_index = start_index;

            }    
        }        
    }
    
    for(int j = max_start; j<max_start+max_length; j++){
        v.push_back(j);
    }
    
    return v;
}

int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}
