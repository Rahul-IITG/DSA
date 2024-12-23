#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
public:
    Trie* child[26]={nullptr};
    bool isEnd=false;
};

void dfs(int i, int j, int m, int n, vector<vector<char>> board, vector<vector<int>> &vis, Trie* root, string str, vector<string> &sol) {
    if (root->isEnd) {
        sol.push_back(str);
        return;
    }

    if (i-1>=0&&vis[i-1][j]==0&&root->child[board[i-1][j]-'a']!=nullptr) {
        vis[i-1][j]=1;

        dfs(i-1,j,m,n,board,vis,root->child[board[i-1][j]-'a'],str+board[i-1][j],sol);

        vis[i-1][j]=0;
    }
    if (i+1<m&&vis[i+1][j]==0&&root->child[board[i+1][j]-'a']!=nullptr) {
        vis[i+1][j]=1;

        dfs(i+1,j,m,n,board,vis,root->child[board[i+1][j]-'a'],str+board[i+1][j],sol);

        vis[i+1][j]=0;
    }

    if (j-1>=0&&vis[i][j-1]==0&&root->child[board[i][j-1]-'a']!=nullptr) {
        vis[i][j-1]=1;

        dfs(i,j-1,m,n,board,vis,root->child[board[i][j-1]-'a'],str+board[i][j-1],sol);

        vis[i][j-1]=0;
    }
    if (j+1<n&&vis[i][j+1]==-1&&root->child[board[i][j+1]-'a']!=nullptr) {
        vis[i][j+1]=1;

        dfs(i,j+1,m,n,board,vis,root->child[board[i][j+1]-'a'],str+board[i][j+1],sol);

        vis[i][j+1]=0;
    }

    return;
}

void insert(Trie* root, string str) {
    int s=str.size();
    Trie* temp;
    temp=root;

    for (int i=0;i<s;i++) {
        if (temp->child[str[i]-'a']==nullptr) {
            temp->child[str[i]-'a']=new Trie();
        }

        temp=temp->child[str[i]-'a'];
    }

    temp->isEnd=true;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m=board.size();
    int n=board[0].size();
    int s=words.size();

    vector<string> sol;
    Trie* root;

    for (int i=0;i<s;i++) {
        insert(root,words[i]);
    }

    vector<vector<int>> vis(m,vector<int>(n,0));

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (root->child[board[i][j]-'a']!=nullptr) {
                vis[i][j]=1;
                dfs(i,j,m,n,board,vis,root->child[board[i][j]-'a'],""+string(1,board[i][j]),sol);
            }
        }
    }

    return sol;
}