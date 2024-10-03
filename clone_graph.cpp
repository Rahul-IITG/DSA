#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* explore(Node* node, Node* head, vector<int> &vis, unordered_map<int,Node*> &umap) {
    int s=node->neighbors.size();

    for (int i=0;i<s;i++) {
        if (vis[node->neighbors[i]->val]==-1) {
            vis[node->neighbors[i]->val]=1;
            Node* curr=new Node(node->neighbors[i]->val);
            umap[node->neighbors[i]->val]=curr;
            curr=explore(node->neighbors[i],curr,vis,umap);
            head->neighbors.push_back(curr);
        }
        else {
            head->neighbors.push_back(umap[node->neighbors[i]->val]);
        }
    }

    return head;
}

Node* cloneGraph(Node* node) {
    if (node==nullptr) {
        return nullptr;
    }

    Node* head;
    head=new Node(node->val);
    vector<int> vis(1000,-1);
    vis[head->val]=1;
    int s=node->neighbors.size();
    unordered_map<int,Node*> umap;
    umap[head->val]=head;

    for (int i=0;i<s;i++) {
        if (vis[node->neighbors[i]->val]==-1) {
            vis[node->neighbors[i]->val]=1;
            Node* curr=new Node(node->neighbors[i]->val);
            umap[node->neighbors[i]->val]=curr;
            curr=explore(node->neighbors[i],curr,vis,umap);
            head->neighbors.push_back(curr);
        }
        else {
            head->neighbors.push_back(umap[node->neighbors[i]->val]);
        }
    }

    return head;
}