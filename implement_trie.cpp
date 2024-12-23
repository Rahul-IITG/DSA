#include <string>

using namespace std;

class Trie {
public:
    Trie* children[26]={nullptr};
    bool isEnd=false;

    Trie() {

    }

    void insert(string word) {
        Trie* root=this;
        int s=word.size();

        for (int i=0;i<s;i++) {
            if (root->children[word[i]-'a']==nullptr) {
                Trie* node=new Trie();
                root->children[word[i]-'a']=node;
            }

            root=root->children[word[i]-'a'];
        }

        root->isEnd=true;
    }

    bool search(string word) {
        Trie* root=this;
        int s=word.size();

        for (int i=0;i<s;i++) {
            if (root->children[word[i]-'a']==nullptr) {
                return false;
            }

            root=root->children[word[i]-'a'];
        }

        return root->isEnd;
    }

    bool startsWith(string word) {
        Trie* root=this;
        int s=word.size();

        for (int i=0;i<s;i++) {
            if (root->children[word[i]-'a']==nullptr) {
                return false;
            }

            root=root->children[word[i]-'a'];
        }

        return true;
    }
};
