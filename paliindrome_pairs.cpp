#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
public:
    vector<int> palindromes;
    unordered_map<char,Trie*> children;
    int index=-1;
};

bool isPalindrome(string str, int left, int right) {
    while (left<right) {
        if (str[left]!=str[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

void insert(string word, Trie* root, int index) {
    int s=word.size();

    for (int i=s-1;i>=0;i--) {
        if (isPalindrome(word,0,i)) {
            root->palindromes.push_back(index);
        }

        if (!root->children.count(word[i])) {
            root->children[word[i]]=new Trie();
        }

        root=root->children[word[i]];
    }

    root->index=index;
}

void search(Trie* root, string word, vector<vector<int>> &sol, int index) {
    int s=word.size();

    for (int i=0;i<s;i++) {
        if (root->index!=-1 && root->index!=index && isPalindrome(word,i,s-1)) {
            sol.push_back({index,root->index});
        }

        if (!root->children.count(word[i])) {
            return;
        }

        root=root->children[word[i]];
    }

    for (int palIndex : root->palindromes) {
        if (palIndex!=index) {
            sol.push_back({index,palIndex});
        }
    }
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    int s=words.size();
    Trie* root=new Trie();

    for (int i=0;i<s;i++) {
        insert(words[i],root,i);
    }

    vector<vector<int>> sol;

    for (int i=0;i<s;i++) {
        search(root,words[i],sol,i);
    }

    return sol;
}