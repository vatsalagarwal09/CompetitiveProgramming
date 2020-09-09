#include <iostream>
using namespace std;
#include<vector>
class PriorityQueue {
    vector<int> pq;
    
    public:
    PriorityQueue(){
        
    }
    
    int getSize(){
        return pq.size();
    }
    
    bool isEmpty(){
        return pq.size() == 0;
    }
    
    int getMax(){
        if(pq.size() == 0){
            return -1;
        }
        return pq[0];
    }
    
    void insert(int data){
        pq.push_back(data);
        
        int childIndex = pq.size() - 1;
        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;        
            if(pq[parentIndex] < pq[childIndex]){
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            
            childIndex = parentIndex;
        }
    
    }
    
    int removeMax(){
        if(pq.size() == 0){
            return -1;
        }
        
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        
        int parentIndex = 0;
        int child1 = 2 * parentIndex + 1;
        int child2 = 2 * parentIndex + 2;
        
        while(child2 <= pq.size() - 1){
            int larger;
            if(pq[child2] > pq[child1]){
                larger = child2;
            } else {
                larger = child1;
            }
            
            if(pq[larger] > pq[parentIndex]){
                int temp1 = pq[larger];
                pq[larger] = pq[parentIndex];
                pq[parentIndex] = temp1;
            }
            
            parentIndex = larger;
            child1 = 2 * parentIndex + 1;
            child2 = 2 * parentIndex + 2;
        }
        
        if(child1 <= pq.size() - 1){
            if(pq[parentIndex] < pq[child1]){
                int temp1 = pq[child1];
                pq[child1] = pq[parentIndex];
                pq[parentIndex] = temp1;            
            }   
            parentIndex = child1;
            child1 = 2 * parentIndex + 1;
            child2 = 2 * parentIndex + 2;            
        }
        return ans;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}

