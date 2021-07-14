#include <iostream>
#include <queue>
using namespace std;

#include <queue>

void printRunningMedian(int *arr, int n)
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;

    if (n == 0)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (maxheap.empty() || maxheap.top() > arr[i])
        {
            maxheap.push(arr[i]);
        }
        else
        {
            minheap.push(arr[i]);
        }
        //checking size to adjust both heaps
        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        //printing
        if (maxheap.size() == minheap.size())
        {
            cout << (maxheap.top() + minheap.top()) / 2 << " ";
        }
        else if (maxheap.size() > minheap.size())
        {
            cout << maxheap.top() << " ";
        }
        else
        {
            cout << minheap.top() << " ";
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------
int main()
{
    int n;

    int arr[] = {6, 2, 1, 3, 7, 5};

    printRunningMedian(arr, 6);
}
