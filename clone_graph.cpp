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

Node* explore(Node* node, Node* root, unordered_map<Node*,int> &vis, unordered_map<int,Node*> & nodes) {
    int s=node->neighbors.size();

    for (int i=0;i<s;i++) {
        if (vis[node->neighbors[i]]==0) {
            vis[node->neighbors[i]]=1;
            Node* neigh=new Node(node->neighbors[i]->val);
            nodes[neigh->val]=neigh;
            neigh=explore(node->neighbors[i],neigh, vis,nodes);
            root->neighbors.push_back(neigh);
        }
        else {
            root->neighbors.push_back(nodes[node->neighbors[i]->val]);
        }
    }

    return root;
}

Node* cloneGraph(Node* node) {
    if (node==nullptr) {
        return nullptr;
    }

    unordered_map<Node*,int> vis;
    unordered_map<int,Node*> nodes;
    vis[node]=1;
    nodes[node->val]=node;
    Node* root=new Node(node->val);
    int s=node->neighbors.size();

    for (int i=0;i<s;i++) {
        if (vis[node->neighbors[i]]==0) {
            vis[node->neighbors[i]]=1;
            Node* neigh=new Node(node->neighbors[i]->val);
            nodes[neigh->val]=neigh;
            neigh=explore(node->neighbors[i],neigh, vis,nodes);
            root->neighbors.push_back(neigh);
        }
        else {
            root->neighbors.push_back(nodes[node->neighbors[i]->val]);
        }
    }

    return root;
}