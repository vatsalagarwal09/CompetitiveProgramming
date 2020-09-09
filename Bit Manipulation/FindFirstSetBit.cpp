#include <iostream>
using namespace std;
int returnFirstSetBit(int n){    
    int count = 0;
    int z = 1;
    while(count != 7){
        int a = n & z;
 //       cout << z << endl;
        if(a!=0){
            break;
        }
        z = z << 1;
        
        count++;
    }
    
    return 1 << count;
}

int main() {
	int n;

	cin >> n;
	
	cout<< returnFirstSetBit(n) <<endl;
		
	return 0;
}


