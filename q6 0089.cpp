#include <iostream>
using namespace std;

void kahn(int adj[6][6]) {
    int indeg[6] = {0};
    int q[6], front = 0, rear = 0, count = 0;

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (adj[i][j]) indeg[j]++;

    cout << "Indegrees: ";
    for (int i = 0; i < 6; i++) cout << indeg[i] << " ";
    cout << endl;

    for (int i = 0; i < 6; i++)
        if (indeg[i] == 0) q[rear++] = i;

    cout << "Order: ";
    while (front < rear) {
        int u = q[front++];
        cout << "C" << u << " ";
        count++;
        for (int v = 0; v < 6; v++) {
            if (adj[u][v]) {
                indeg[v]--;
                if (indeg[v] == 0) q[rear++] = v;
            }
        }
    }
    cout << endl;

    if (count < 6) cout << "Cycle detected, no valid order" << endl;
    cout << endl;
}

int main() {
    int adj[6][6] = {0};
    adj[0][1] = adj[0][2] = adj[1][3] = adj[2][4] = adj[2][5] = adj[3][5] = 1;
    kahn(adj);

    adj[5][2] = 1;
    kahn(adj);
    return 0;
}
