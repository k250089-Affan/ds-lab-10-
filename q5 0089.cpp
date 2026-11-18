#include <iostream>
using namespace std;

int adj[6][6];
int dist[6], par[6];
bool done[6];

void printPath(int v) {
    if (par[v] != -1) {
        printPath(par[v]);
        cout << " -> ";
    }
    cout << (char)('A' + v);
}

int main() {
    adj[0][1] = 4;  adj[0][2] = 2;  adj[1][2] = 5;  adj[1][3] = 10;
    adj[2][4] = 3;  adj[4][3] = 4;  adj[3][5] = 11;

    for (int i = 0; i < 6; i++) {
        dist[i] = 9999;
        par[i] = -1;
    }
    dist[0] = 0;

    for (int count = 0; count < 6; count++) {
        int u = -1;
        for (int i = 0; i < 6; i++)
            if (!done[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (dist[u] == 9999) break;
        done[u] = true;
        for (int v = 0; v < 6; v++) {
            if (adj[u][v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                par[v] = u;
            }
        }
    }

    for (int v = 1; v < 6; v++) {
        cout << "A to " << (char)('A' + v) << ": ";
        if (dist[v] == 9999) {
            cout << "unreachable" << endl;
        } else {
            printPath(v);
            cout << "  cost " << dist[v] << endl;
        }
    }
    return 0;
}
