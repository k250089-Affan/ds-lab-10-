#include <iostream>
using namespace std;

int n;
char base;
int w[10][10];

void setup(char b, int count) {
    base = b;
    n = count;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            w[i][j] = 0;
}

void edge(char u, char v, int weight) {
    w[u - base][v - base] = weight;
    w[v - base][u - base] = weight;
}

void prim(char start) {
    bool used[10] = {false};
    int key[10], parent[10];
    int total = 0;
    for (int i = 0; i < n; i++) {
        key[i] = 9999;
        parent[i] = -1;
    }
    key[start - base] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || key[i] < key[u]))
                u = i;
        used[u] = true;
        if (parent[u] != -1) {
            cout << (char)(base + parent[u]) << " - " << (char)(base + u)
                 << " (" << key[u] << ")" << endl;
            total += key[u];
        }
        for (int v = 0; v < n; v++) {
            if (w[u][v] && !used[v] && w[u][v] < key[v]) {
                key[v] = w[u][v];
                parent[v] = u;
            }
        }
    }
    cout << "Total = " << total << endl << endl;
}

int main() {
    setup('0', 5);
    edge('0','1',3); edge('1','2',1); edge('0','3',7); edge('1','3',4);
    edge('3','2',2); edge('0','4',8); edge('4','3',3);
    cout << "Graph (a)" << endl;
    prim('0');

    setup('A', 7);
    edge('A','B',1); edge('A','D',5); edge('B','D',3); edge('B','C',4);
    edge('D','G',4); edge('D','E',1); edge('C','E',7); edge('E','G',2);
    edge('G','F',10); edge('E','F',1);
    cout << "Graph (b)" << endl;
    prim('A');
    return 0;
}
