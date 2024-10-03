#include <queue>
#include <vector>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
   int s=edges.size();
   priority_queue<int,vector<int>,greater<int>> q;
   vector<int> dist(s,INT_MAX);
   dist[start]=0;
   q.push(start);

   while (!q.empty()) {
      start=q.top();
      q.pop();

      int k=edges[start].size();

      for (int i=0;i<k;i++) {
         if (dist[edges[start][i][0]]>dist[start]+edges[start][i][1]) {
            dist[edges[start][i][0]] = dist[start]+edges[start][i][1];
            q.push(edges[start][i][0]);
         }
      }
   }

   return dist;
}
