#include<bits/stdc++.h>


using namespace std;

const int MAX = 155;
int numCols;
int numRows;
int res ;
char mp[MAX][MAX];
bool visited[MAX][MAX];

// const int dr[] = {0, 0, 1, -1, -1, -1,  1, 1 };
// const int dc[] = {1, -1, 0, 0, -1,  1, -1, 1 };

// Below arrays details all 8 possible movements
int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const char s[] = "ALLIZZWELL";

bool isSafe(int nr, int nc) {
    return nr >= 0 && nr < numRows && nc >= 0 && nc < numCols;
}

void DFSRecVisit(int r, int c, int current) {
    // if(r<0 || r>numRows || c<0 || c>numCols)return false ;
    // cout << mp[r][c];
    // cout << current << " ";
    // visited[r][c] = true;
    visited[r][c] = true;
    if (current == 9) {
        res = 1;
        // cout << "okie";
        return;
    }

    // cout << sub;
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (isSafe(nr, nc) && !visited[nr][nc] && mp[nr][nc] == s[current + 1]   ) {
            // cout << s[current];
            // visited[nr][nc] = true;
            DFSRecVisit(nr, nc, current + 1);
            // visited[nr][nr] = false;
            // cout << s[index];

        }
    }
    visited[r][c] = false;
}


void solve() {
    cin >> numRows >> numCols;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> mp[i][j];
        }
    }
    memset(visited, false, sizeof visited);
    // string sub;
    res = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (mp[i][j] == 'A') {
                // cout << i << " " << j << '\n';
                // visited[i][j] = true;
                DFSRecVisit(i, j, 0);
                // visited[i][j] = false;

                if (res) break;
            }
        }
    }

    if (res) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}