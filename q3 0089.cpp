#include <iostream>
using namespace std;

int n, m;
char base;
int eu[30], ev[30], ew[30];
int parent[10];

void setup(char b, int count) {
    base = b;
    n = count;
    m = 0;
}

void edge(char u, char v, int weight) {
    eu[m] = u - base;
    ev[m] = v - base;
    ew[m] = weight;
    m++;
}

int find(int x) {
    while (parent[x] != x) x = parent[x];
    return x;
}

void kruskal() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - 1 - i; j++) {
            if (ew[j] > ew[j + 1]) {
                int t;
                t = eu[j]; eu[j] = eu[j + 1]; eu[j + 1] = t;
                t = ev[j]; ev[j] = ev[j + 1]; ev[j + 1] = t;
                t = ew[j]; ew[j] = ew[j + 1]; ew[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n; i++) parent[i] = i;

    int total = 0;
    for (int i = 0; i < m; i++) {
        int a = find(eu[i]);
        int b = find(ev[i]);
        if (a != b) {
            parent[a] = b;
            total += ew[i];
            cout << (char)(base + eu[i]) << " - " << (char)(base + ev[i])
                 << " (" << ew[i] << ")" << endl;
        }
    }
    cout << "Total = " << total << endl << endl;
}

int main() {
    setup('a', 5);
    edge('a','c',10); edge('c','a',21); edge('a','d',22); edge('b','c',53);
    edge('b','e',45); edge('c','e',33); edge('e','d',19);
    cout << "Graph (a)" << endl;
    kruskal();

    setup('A', 6);
    edge('A','B',3); edge('A','C',5); edge('A','D',9); edge('B','D',4);
    edge('B','C',3); edge('B','E',7); edge('C','D',2); edge('D','E',2);
    edge('D','F',2); edge('C','E',6); edge('E','F',5); edge('C','F',8);
    cout << "Graph (b)" << endl;
    kruskal();
    return 0;
}
