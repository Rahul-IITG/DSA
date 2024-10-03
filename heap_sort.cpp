#include <vector>
using namespace std;

void insert(vector<int> &heap, int value, int &size) {
    heap.push_back(value);
    size++;
    int i=size-1;

    while (i!=0) {
        int parent=(i-1)/2;
        if (heap[i]<heap[parent]) {
            int temp=heap[i];
            heap[i]=heap[parent];
            heap[parent]=temp;
            i=parent;
            continue;
        }

        break;
    }

    return;
}

void minHeapify(vector<int> &heap, int i, int size) {
    int left=2*i+1;
    int right=2*i+2;

    if (left<size&&right<size) {
        if (heap[i]>heap[left]&&heap[i]>heap[right]) {
            if (heap[left]<heap[right]) {
                int temp=heap[i];
                heap[i]=heap[left];
                heap[left]=temp;
                i=left;
            }
            else {
                int temp=heap[i];
                heap[i]=heap[right];
                heap[right]=temp;
                i=right;
            }

            minHeapify(heap,i,size);
            return;
        }
        if (heap[i]>heap[left]) {
            int temp=heap[i];
            heap[i]=heap[left];
            heap[left]=heap[i];
            i=left;

            minHeapify(heap,i,size);
            return;
        }
        if (heap[i]>heap[right]) {
            int temp=heap[i];
            heap[i]=heap[right];
            heap[right]=temp;
            i=right;

            minHeapify(heap,i,size);
            return;
        }

        return;
    }
    if (left<size) {
        if (heap[i]>heap[left]) {
            int temp=heap[i];
            heap[i]=heap[left];
            heap[left]=heap[i];
            i=left;

            minHeapify(heap,i,size);
        }
    }

    return;
}

vector<int> heapSort(vector<int> array) {
    int s=array.size();
    vector<int> heap;
    int size=0;

    for (int i=0;i<s;i++) {
        insert(heap,array[i],size);
    }

    vector<int> sol;

    while (size) {
        sol.push_back(heap[0]);
        heap[0]=heap[size-1];
        size--;

        minHeapify(heap,0,size);
    }

    return sol;
}
