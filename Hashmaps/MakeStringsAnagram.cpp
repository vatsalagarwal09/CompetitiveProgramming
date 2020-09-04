#include <cmath>
#include <iostream>
#include<unordered_map>
#include<string.h>
using namespace std;
int makeAnagram(char str1[], char str2[]){
    int deletion = 0;
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
    
    for(int i = 0; i<n1; i++){
        if(m1.count(str1[i]) == 0){
            m1[str1[i]] = 1;
            continue;
        }
        
        m1[str1[i]]++;
    }
    
    for(int i = 0; i<n2; i++){
        if(m2.count(str2[i]) == 0){
            m2[str2[i]] = 1;
            continue;
        }
        
        m2[str2[i]]++;
    }    
    
    for(int i = 0; i<n1; i++){
        while(m1[str1[i]] != m2[str1[i]]){
            if(m1[str1[i]] > m2[str1[i]]){
                m1[str1[i]]--;
                deletion++;
            } else {
                m2[str1[i]]--;
                deletion++;
            }
        }
    }
    
    for(int i = 0; i<n2; i++){
        while(m1[str2[i]] != m2[str2[i]]){
            if(m1[str2[i]] > m2[str2[i]]){
                m1[str2[i]]--;
                deletion++;
            } else {
                m2[str2[i]]--;
                deletion++;
            }
        }        
    }
    
    return deletion;
}

int main() {
    char str1[10010], str2[10010];
    cin>>str1;
    cin>>str2;
    
    cout << makeAnagram(str1,str2) << endl;
	
}


