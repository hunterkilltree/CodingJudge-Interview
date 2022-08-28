#include "bits/stdc++.h"

using namespace std;

#define MAXSIZE 652025

int n; // row
int m;// col
int image[255][255];
int arr[MAXSIZE];
int numberOfSlick;

int visited[255][255];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
vector<pair<int, int> > s;



void plt_show() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void preprocesss() {
    memset(visited, 0, sizeof visited);
    memset(arr, 0, MAXSIZE);
    numberOfSlick = 0;
    s.clear();
}

bool isSafe(pair<int, int> s) {
    return (s.first >= 0) && (s.first < n) && (s.second >= 0) && (s.second < m);
}

void bfs() {

    for(int i = 0;  i < s.size(); i++) {
        int size = 0;

        if ( visited[s[i].first][s[i].second] == 0) {
            numberOfSlick++;
            visited[s[i].first][s[i].second] = 1;
            queue<pair<int, int> >  q;
            pair<int, int> t;
            q.push(s[i]);

            while(!q.empty()) {
                t = q.front();
                q.pop();
                size++;
                for(int k = 0; k < 4; k++) {
                    pair<int, int> t1;
                    t1.first = dx[k] + t.first;
                    t1.second = dy[k] + t.second;

                    if (isSafe(t1) && image[t1.first][t1.second] != 0 && visited[t1.first][t1.second] == 0) {
                        visited[t1.first][t1.second] = 1;

                        q.push(t1);
                    }
                }
            }
            arr[size]++;
            //cout << size <<  endl;
        }
    }
    cout << numberOfSlick << '\n';
    for (int i = 0; i < MAXSIZE; i++) {
        if (arr[i] != 0) {
            cout << i << ' ' << arr[i] << '\n';
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("image.txt", "r", stdin);

    cin >> n >> m;

    while (n != 0 && m != 0) {
        preprocesss();
        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < m; j++) {
                cin >> image[i][j];

                if (image[i][j] == 1) {
                    s.push_back(make_pair(i, j));
                }
            }
        }

        bfs();
        //plt_show();
        cin >> n >> m;
    }
    return 0;
}