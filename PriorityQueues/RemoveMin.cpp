#include <iostream>
using namespace std;
#include <climits>
#include <vector>

class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        // Complete this function
            if(pq.size() == 0){
                return 0;
            }
            int ans = pq[0];
			pq[0] = pq[pq.size() - 1];	
			pq.pop_back();
			
			int parentIndex = 0;
			int child1 = 2 * parentIndex + 1;
			int child2 = 2 * parentIndex + 2;
			while(child2 <= pq.size() - 1){
				int smaller;
				if(pq[child2] < pq[child1]){
					smaller = child2;
				} else {
					smaller = child1;
				}
				
				if(pq[parentIndex] > pq[smaller]){
					int temp1 = pq[parentIndex];
					pq[parentIndex] = pq[smaller];
					pq[smaller] = temp1;
				}
				
				parentIndex = smaller;
				child1 = 2 * parentIndex + 1;
				child2 = 2 * parentIndex + 2;					
			}
			
			if(child1 <= pq.size()-1){
				if(pq[parentIndex] > pq[child1]){
					int temp1 = pq[parentIndex];
					pq[parentIndex] = pq[child1];
					pq[child1] = temp1;
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
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMin() << endl;
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

