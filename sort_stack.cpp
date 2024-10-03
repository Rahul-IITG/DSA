#include <stack>
#include <vector>
using namespace std;

void insert(vector<int> &stack, int top) {
    if (stack.empty()) {
        stack.push_back(top);
        return;
    }

    int currTop=stack[stack.size()-1];

    if (currTop>top) {
        stack.pop_back();
        insert(stack,top);
        stack.push_back(currTop);
    }
    else {
        stack.push_back(top);
    }
}

vector<int> sortStack(vector<int>& stack) {
    if (stack.empty()) {
        return stack;
    }

    int top=stack[stack.size()-1];
    stack.pop_back();
    sortStack(stack);
    insert(stack,top);
}
