#include<iostream>
#include<cstring>

#define MAX 107
#define null -1

using namespace std;

int heap[MAX];

int insertionPostion = 0;

void initHeap()
{
    memset(heap, null, sizeof(heap));
    return;
}

int isEmpty()
{
    return heap[0]==null;
}

int parent(int nodeIndex)
{
    if(nodeIndex==0) return 0;
    else return (nodeIndex&1) ? (nodeIndex-1)/2 : (nodeIndex-2)/2;
}

int leftChild(int nodeIndex)
{
    return (2*nodeIndex) + 1;
}

int rightChild(int nodeIndex)
{
    return (2*nodeIndex) + 2;
}

void Insert(int data)
{
    heap[insertionPostion] = data;
    int currentPosition = insertionPostion;

    while(parent(currentPosition)!=currentPosition && heap[parent(currentPosition)]<heap[currentPosition])
    {
        swap(heap[parent(currentPosition)], heap[currentPosition]);
        currentPosition = parent(currentPosition);
    }
    insertionPostion++;
}

int Top()
{
    return heap[0];
}

void heapify(int nodeIndex)
{
    if(leftChild(nodeIndex)==null && rightChild(nodeIndex)==null)
        return;

    /// left child only
    if(leftChild(nodeIndex)!=null && rightChild(nodeIndex)==null)
    {
        if(heap[nodeIndex]<heap[leftChild(nodeIndex)])
        {
            swap(heap[nodeIndex], heap[leftChild(nodeIndex)]);
            heapify(leftChild(nodeIndex));
        }
    }
    /// right child only, not possible to have only right child
    /*else if(leftChild(nodeIndex)==null && rightChild(nodeIndex)!=null)
    {
        if(heap[nodeIndex]<heap[rightChild(nodeIndex)])
        {
            swap(heap[nodeIndex], heap[rightChild(nodeIndex)]);
            heapify(rightChild(nodeIndex));
        }
    }*/
    /// left and right child
    else
    {
        if(heap[nodeIndex]>=heap[leftChild(nodeIndex)] && heap[nodeIndex]>=heap[rightChild(nodeIndex)])
            return;

        if(heap[leftChild(nodeIndex)]>heap[rightChild(nodeIndex)])
        {
            swap(heap[nodeIndex], heap[leftChild(nodeIndex)]);
            heapify(leftChild(nodeIndex));
        }
        else
        {
            swap(heap[nodeIndex], heap[rightChild(nodeIndex)]);
            heapify(rightChild(nodeIndex));
        }
    }
}

void DeleteTop()
{
    if(insertionPostion==0) return;

    insertionPostion--;

    if(insertionPostion==0)
    {
        heap[insertionPostion] = null;
        return;
    }

    heap[0] = heap[insertionPostion];
    heap[insertionPostion] = null;

    heapify(0);

}

int main()
{
    initHeap();
    Insert(10);
    Insert(15);
    Insert(25);
    Insert(13);
    Insert(11);
    Insert(7);
    Insert(30);

    while(!isEmpty())
    {
        cout << Top() << " ";
        DeleteTop();
    }
    cout << "\n";

    Insert(12);
    Insert(19);
    Insert(89);

    cout << Top() << "\n";
    DeleteTop();

    Insert(13);
    Insert(18);

    while(!isEmpty())
    {
        cout << Top() << " ";
        DeleteTop();
    }
    cout << "\n";

    return 0;
}
