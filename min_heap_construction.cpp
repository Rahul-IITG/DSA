#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
    vector<int> heap;

    MinHeap(vector<int> vector) { heap = buildHeap(vector); }

    vector<int> buildHeap(vector<int>& vector) {
        int s=vector.size();

        for (int i=0;i<s;i++) {
            this->insert(vector[i]);
        }

        return this->heap;
    }

    void siftDown(int currentIdx, int endIdx, vector<int>& heap) {
        int left=2*currentIdx+1;
        int right=2*currentIdx+2;

        if (left<=endIdx&&right<=endIdx) {
            if (heap[left]<heap[right]&&heap[currentIdx]>heap[left]) {
                int temp=heap[currentIdx];
                heap[currentIdx]=heap[left];
                heap[left]=temp;
                siftDown(left,endIdx,heap);
                return;
            }
            if (heap[left]>=heap[right]&&heap[currentIdx]>heap[right]) {
                int temp=heap[currentIdx];
                heap[currentIdx]=heap[right];
                heap[right]=temp;
                siftDown(right,endIdx,heap);
                return;
            }
        }
        if (left<=endIdx) {
            if (heap[currentIdx]>heap[left]) {
                int temp=heap[currentIdx];
                heap[currentIdx]=heap[left];
                heap[left]=temp;
                siftDown(left,endIdx,heap);
                return;
            }
        }

        return;
    }

    void siftUp(int currentIdx, vector<int>& heap) {
        int parent=(currentIdx-1)/2;

        if (heap[parent]>heap[currentIdx]) {
            int temp=heap[parent];
            heap[parent]=heap[currentIdx];
            heap[currentIdx]=temp;
            siftUp(parent,heap);
        }

        return;
    }

    int peek() {
        if (heap.empty()) {
            return -1;
        }

        return heap[0];
    }

    int remove() {
        if (heap.empty()) {
            return -1;
        }
        int s=heap.size();
        int temp=heap[0];
        heap[0]=heap[s-1];
        heap.pop_back();
        siftDown(0,s-2,heap);
        return temp;
    }

    void insert(int value) {
        heap.push_back(value);
        int s=heap.size();
        siftUp(s-1,heap);
    }
};
