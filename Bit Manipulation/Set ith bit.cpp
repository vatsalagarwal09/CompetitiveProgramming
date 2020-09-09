#include <iostream>
using namespace std;
int turnOnIthBit(int n, int i){
    int z = n | (1 << i);
    
    return z;
    
}

int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< turnOnIthBit(n, i) <<endl;
		
	return 0;
}


