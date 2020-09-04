#include <iostream>
using namespace std;
#include<string.h>
void interleaving(char* first, char* second, string s){
    
    if(first[0] == '\0' && second[0] == '\0'){
        cout << s << endl;
        return;
    }
    
    if(first[0] != '\0'){
        interleaving(first+1, second, s+first[0]);
    }
    
    if(second[0] != '\0'){
        interleaving(first, second+1, s+second[0]);
    }
    return;
    
}


void interleaving(char* first, char* second) {
    string s;
    interleaving(first, second, s);
}

int main() {
    char *a = new char[1000];
    char *b = new char[1000];
    cin >> a;
    cin >> b;
    interleaving(a, b);
}

