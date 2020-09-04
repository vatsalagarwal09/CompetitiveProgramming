#include <iostream>
using namespace std;
#include<algorithm>

long numDuplicate(long *input, long n, long *freq, long *fact){
	if(n==0 || n==1){
		return 0;
	}
    
	long count = 0;
	long fac_deno = 1;
	
	for(long i = 0; i<10; i++){
		if(freq[i] != 0){
			fac_deno = fac_deno * fact[freq[i]];
		}
	}
	
	for(long i = input[0]; i<9; i++){
		if(freq[i+1] > 0){
			count += freq[i+1];
		}
	}
	
	long ans = (count * fact[n-1])/fac_deno ;
	freq[input[0]]--;
	long smallAns = numDuplicate(input+1, n-1, freq, fact);
	
	return ans + smallAns;
}


long numberOfNumbersWithDuplicates(long num){
	// Write your code here
    long count = 0;
    long a = num;    
    for(long i = 0; a != 0; i++){
        a = a/10;
        count++;
        
    }    
    
	long *input = new long[count];
	long *fact = new long[count+1];
	long freq[10] = {0};
	fact[0] = 1;


    
    a = num;    
    for(long i = count-1; i>=0; i--){
        input[i] = a%10;
        a = a/10;
        freq[input[i]]++;
    }
    
	for(long i = 0; i<count; i++){
		fact[i+1] = (i+1) * fact[i];
	}
	
	
	long final_ans = numDuplicate(input, count, freq, fact);
    return final_ans;
}
int main() {
    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;
}

