#include <queue>
using namespace std;

class List {
public:
    int key;
    int val;
    List* next=nullptr;
    List* prev=nullptr;

    List(int key,int val) {
        this->key=key;
        this->val=val;
    }
};

class LRUCache {
public:
    List* head;
    List* tail;
    unordered_map<int,List*> umap;
    int size=0;
    int capacity=0;

    LRUCache(int capacity) {
        head=new List(0,0);
        tail=new List(0,0);
        head->next=tail;
        tail->prev=head;
        this->capacity=capacity;
    }

    int get(int key) {
        if (umap.find(key)!=umap.end()) {
            List* node=umap[key];
            removeNode(node);
            addToHead(node);
            return node->val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (umap.find(key)!=umap.end()) {
            List* node=umap[key];
            removeNode(node);
            node->val=value;
            addToHead(node);
            return;
        }

        if (size<capacity) {
            List* node=new List(key,value);
            umap[key]=node;
            addToHead(node);
            size++;
        }
        else {
            List* node=new List(key,value);
            umap[key]=node;
            addToHead(node);
            List* last=removeTail();
            umap.erase(last->key);
        }
    }

    void addToHead(List* node) {
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
    }

    List* removeNode(List* node) {
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->next=nullptr;
        node->prev=nullptr;
        return node;
    }

    List* removeTail() {
        List* last=removeNode(tail->prev);
        return last;
    }
};
