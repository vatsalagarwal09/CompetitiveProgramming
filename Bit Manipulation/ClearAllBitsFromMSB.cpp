#include <iostream>
using namespace std;

int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< clearAllBits(n, i) <<endl;
		
	return 0;
}


int clearAllBits(int n, int i){
    int a = 1 << i;
    int b = a-1;
    return n & b;
    
}


