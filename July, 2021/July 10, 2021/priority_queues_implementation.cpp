#include <iostream>
#include <vector>
using namespace std;

// Priority Queue is implemented using vector.
class PriorityQueues
{
public:
    vector<int> pq;

    PriorityQueues()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }
    int getMin(){
        if(pq.empty()){
            return -1;
        }
        return pq[0];
    }
    void insert(int elem){
        pq.push_back(elem);
        int childIndex = pq.size() - 1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;
            if(pq[parentIndex] > pq[childIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }
};

int main(){
    PriorityQueues pq;
    pq.insert(20);
    pq.insert(10);
    pq.insert(40);
    pq.insert(5);
    cout << pq.getMin()<< endl;
    cout << pq.getSize()<< endl;
    cout << pq.isEmpty()<< endl;
}