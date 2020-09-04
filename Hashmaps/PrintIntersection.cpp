#include <iostream>
#include <algorithm>
#include <map>
#include<unordered_map>
using namespace std;
void intersection(int input1[], int input2[], int size1, int size2) {
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    
    for(int i = 0; i<size1; i++){
        if(m1.count(input1[i]) == 0){
            m1[input1[i]] = 1;
            continue;
        }
        
        m1[input1[i]] += 1;
    }
    
    for(int j = 0; j<size2; j++){
        if(m2.count(input2[j]) == 0){
            m2[input2[j]] = 1;
            continue;
        }
        
        m2[input2[j]] += 1;
    }
    
    
    for(int i = 0; i<size1; i++){
        if(m1.count(input1[i]) > 0 && m2.count(input1[i]) > 0){
            cout << input1[i] << endl;
            m1[input1[i]] -= 1;
            m2[input1[i]] -= 1;
            if(m1[input1[i]] == 0){
                m1.erase(input1[i]);
            }
            
            if(m2[input1[i]] == 0){
                m2.erase(input1[i]);
            }
            
        }
    }

}

int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	
	intersection(input1,input2,size1,size2);

		
	return 0;
}

