#include <string>
#include <unordered_map>
using namespace std;

bool generateDocument(string characters, string document) {
    int s=characters.size();
    unordered_map<char,int> umap;

    for (int i=0;i<s;i++) {
        umap[characters[i]]++;
    }

    s=document.size();

    for (int i=0;i<s;i++) {
        if (umap[document[i]]==0) {
            return false;
        }

        umap[document[i]]--;
    }

    return true;
}