#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
void printPairs(int *input, int n, int k) {
	// Write your code here
    unordered_map<int, int> m;
    
    for(int i = 0; i<n ; i++){
        int sec_num = input[i] - k;
        int third_num = input[i] + k;
        
        if(m.count(sec_num)>0){
            int count = m[sec_num];
            while(count > 0){
                int kmin = min(sec_num, input[i]);
                int kmax = max(sec_num, input[i]);
                cout << kmin << " " << kmax << endl;                
                count--;
            }

        }
    if(k!=0){
        if(m.count(third_num)>0){
            int count = m[third_num];
            while(count > 0){
                int kmin = min(third_num, input[i]);
                int kmax = max(third_num, input[i]);
                cout << kmin << " " << kmax << endl;       
                count--;
            }

        }
    }
        
        
        if(m.count(input[i]) == 0){
            m[input[i]] = 1;
            continue;
        }
        
        m[input[i]]++;
    }
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}

