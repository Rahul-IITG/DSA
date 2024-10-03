#include <vector>
using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
    int m=array.size();
    int n=array[0].size();

    bool right=true;
    bool left=false;
    bool up=false;
    bool down=false;
    vector<vector<int>> vis(m,vector<int>(n,0));
    int i=0;
    int j=0;
    vector<int> sol;
    int count=0;

    while (true) {
        if (count==m*n) {
            break;
        }
        if (right) {
            sol.push_back(array[i][j]);
            count++;
            vis[i][j]=1;

            if (j+1==n) {
                i++;
                down=true;
                right=false;
                continue;
            }
            if (j+1<n&&vis[i][j+1]==1) {
                i++;
                down=true;
                right=false;
                continue;
            }

            j++;
            continue;
        }
        if (left) {
            sol.push_back(array[i][j]);
            count++;
            vis[i][j]=1;

            if (j-1<0) {
                i--;
                up=true;
                left=false;
                continue;
            }
            if (j-1>=0&&vis[i][j-1]==1) {
                i--;
                up=true;
                left=false;
                continue;
            }

            j--;
            continue;
        }
        if (up) {
            sol.push_back(array[i][j]);
            count++;
            vis[i][j]=1;

            if (i-1<0) {
                j++;
                right=true;
                up=false;
                continue;
            }
            if (i-1<0&&vis[i-1][j]==1) {
                j++;
                right=true;
                up=false;
                continue;
            }

            i--;
            continue;
        }
        if (down) {
            sol.push_back(array[i][j]);
            count++;
            vis[i][j]=1;

            if (i+1==m) {
                j--;
                left=true;
                down=false;
                continue;
            }
            if (i+1<n&&vis[i+1][j]==1) {
                j--;
                left=true;
                down=false;
                continue;
            }

            i++;
            continue;
        }
    }

    return sol;
}