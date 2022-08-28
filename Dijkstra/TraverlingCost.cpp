#include <iostream>
#include <queue> // for priority queue
#include <vector>
#include <cmath>

using namespace std;
/*
7 number of road
0 1 4 mean o connect with 1 and the w is 4
0 3 8
1 4 1
1 2 2
4 2 3
2 5 3
3 4 2
0 init_pos
4 number of target_des
1
4
5
7
*/

/*
Output:
4
5
9
NO PATH
*/

#define MAX 600
const int INF = 1e9;
vector<vector<pair<int, int> > > graph; // setup graph store dinh.push(pair(dinhke, w))
vector<int> dist(MAX, INF); // store cost value
int path[MAX]; // store path

struct option {
    bool operator() (const pair<int, int> &a, pair<int, int> &b) const {
        return a.second > b.second;
    }
};

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, option > pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        // cout << u << " " << w << '\n';

        for (int i = 0; i < graph[u].size(); i++) {
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
                path[neighbor.first] = u;
            }
        }
    }
}

int main() {
    // freopen("travelling.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; // number of Nodes
    int nTarget; // number of target nodes
    int init_pos;

    graph = vector<vector<pair<int, int> > >(MAX + 5, vector<pair<int, int> >() );
    dist = vector<int>(MAX, INF);

    cin >> n;

    int a, b, w;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> w;
        graph[a].push_back(pair<int, int>(b, w));
        graph[b].push_back(pair<int, int>(a, w));

    }

    cin >> init_pos;
    dijkstra(init_pos);
    cin >> nTarget;

    int target;
    for (int i = 0; i < nTarget; i++) {
        cin >> target;
        // cout << target << " ";
        if (dist[target] != INF)
            cout << dist[target] << '\n';
        else
            cout << "NO PATH\n";
    }

    return 0;
}
