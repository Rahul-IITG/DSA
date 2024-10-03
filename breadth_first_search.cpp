#include <queue>
#include <vector>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
    string name;
    vector<Node*> children;

    Node(string str) { name = str; }

    vector<string> traverse(Node* root) {
        queue<Node*> q;
        q.push(root);

        vector<string> sol;

        while (!q.empty()) {
            Node* curr=q.front();
            q.pop();
            sol.push_back(curr->name);

            int s=curr->children.size();

            for (int i=0;i<s;i++) {
                q.push(curr->children[i]);
            }
        }

        return sol;
    }

    vector<string> breadthFirstSearch(vector<string>* array) {
        return traverse(this);
    }

    Node* addChild(string name) {
        Node* child = new Node(name);
        children.push_back(child);
        return this;
    }
};
