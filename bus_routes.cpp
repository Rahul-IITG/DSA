#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    int s=routes.size();
    unordered_map<int,vector<int>> buses;

    for (int i=0;i<s;i++) {
        int k=routes[i].size();

        for (int j=0;j<k;j++) {
            buses[routes[i][j]].push_back(i);
        }
    }

    queue<pair<int,int>> q;
    unordered_set<int> vis_stops;
    unordered_set<int> vis_buses;
    q.push({source,0});

    while (!q.empty()) {
        pair<int,int> curr=q.front();
        q.pop();
        int curr_stop=curr.first;
        int curr_bus=curr.second;

        if (curr_stop==target) {
            return curr_bus;
        }

        for (auto bus : buses[curr_stop]) {
            if (vis_buses.count(bus)) {
                continue;
            }

            vis_buses.insert(bus);

            for (auto stop : routes[bus]) {
                if (vis_stops.count(stop)) {
                    continue;
                }

                vis_stops.insert(stop);

                q.push({stop,curr_bus+1});
            }
        }
    }

    return -1;
}