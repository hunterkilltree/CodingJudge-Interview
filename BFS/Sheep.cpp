#include "bits/stdc++.h"
using namespace std;

int visited[255][255];
vector<pair<int, int> > s;

int n; // rows
int m; // colums
char backyard[255][255];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void input() {
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> backyard[i][j];

            if (backyard[i][j] == 'v' || backyard[i][j] == 'k') {
                s.push_back(make_pair(i,j));
            }
        }
    }
}

bool isSafe(pair<int, int> s) {
    //need to check
    return (s.first >= 0) && (s.first < n) && (s.second >= 0) && (s.second < m);
}

void processing() {
    memset(visited, 0, sizeof visited);
    int numberOfS = 0;
    int numberOfW = 0;


    for(int i = 0;  i < s.size(); i++) {
        int t_numberOfS = 0;
        int t_numberOfW = 0;

        if ( visited[s[i].first][s[i].second] == 0) {
            queue<pair<int, int> >  q;
            pair<int, int> t;
            q.push(s[i]);

            if (backyard[s[i].first][s[i].second] == 'v' ) {
                t_numberOfW++;
                visited[s[i].first][s[i].second] = 2;
            }
            else if (backyard[s[i].first][s[i].second] == 'k' ) {
                t_numberOfS++;
                visited[s[i].first][s[i].second] = 3;
            }

            while(!q.empty()) {
                t = q.front();
                q.pop();
                for(int k = 0; k < 4; k++) {
                    pair<int, int> t1;
                    t1.first = dx[k] + t.first;
                    t1.second = dy[k] + t.second;

                    if (backyard[t1.first][t1.second] != '#' && visited[t1.first][t1.second] == 0) {

                        if (backyard[t1.first][t1.second] == 'v') {
                            t_numberOfW++;
                            visited[t1.first][t1.second] = 2;
                        }
                        else if (backyard[t1.first][t1.second] == 'k') {
                            t_numberOfS++;
                            visited[t1.first][t1.second] = 3;
                        }
                        else {
                            visited[t1.first][t1.second] = 1;
                        }
                        q.push(t1);
                    }
                }
            }
            //cout << t_numberOfS  << " " << t_numberOfW << endl;

            if (t_numberOfS > t_numberOfW) {
                numberOfS = numberOfS + t_numberOfS;
            }
            else {
                numberOfW = numberOfW + t_numberOfW;
            }
        }
    }
    cout << numberOfS << " " << numberOfW << endl;
}


void plt_show() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("backyard.txt", "r", stdin);
    input();
    processing();
    //plt_show();

    return 0;
}
