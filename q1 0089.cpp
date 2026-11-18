#include <iostream>
using namespace std;

int n;
char base;
int adj[10][10];
bool vis[10];

void setup(char b, int count) {
    base = b;
    n = count;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            adj[i][j] = 0;
}

void edge(char u, char v) {
    adj[u - base][v - base] = 1;
}

void twoWay(char u, char v) {
    edge(u, v);
    edge(v, u);
}

void bfs(char start) {
    int q[20], front = 0, rear = 0;
    for (int i = 0; i < n; i++) vis[i] = false;
    q[rear++] = start - base;
    vis[start - base] = true;
    cout << "BFS: ";
    while (front < rear) {
        int u = q[front++];
        cout << (char)(base + u) << " ";
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !vis[v]) {
                vis[v] = true;
                q[rear++] = v;
            }
        }
    }
    cout << endl;
}

void dfs(int u) {
    vis[u] = true;
    cout << (char)(base + u) << " ";
    for (int v = 0; v < n; v++)
        if (adj[u][v] && !vis[v])
            dfs(v);
}

void run(const char *name, char start) {
    cout << name << " start " << start << endl;
    bfs(start);
    for (int i = 0; i < n; i++) vis[i] = false;
    cout << "DFS: ";
    dfs(start - base);
    cout << endl << endl;
}

int main() {
    setup('a', 5);
    edge('a','b'); edge('a','c'); edge('a','d'); edge('a','e');
    edge('b','d'); edge('c','d'); edge('c','e'); edge('d','e');
    run("(a)", 'a');

    setup('1', 7);
    edge('1','2'); edge('1','4'); edge('2','3'); edge('2','5'); edge('3','7');
    edge('4','6'); edge('5','7'); edge('6','5'); edge('6','7');
    run("(b)", '1');

    setup('A', 6);
    edge('A','B'); edge('A','C'); edge('C','B'); edge('C','D');
    edge('C','E'); edge('D','E'); edge('B','F'); edge('E','F');
    run("(c) and (d)", 'A');

    setup('A', 8);
    edge('H','A'); edge('C','H'); edge('G','H'); edge('A','B'); edge('B','C');
    edge('C','G'); edge('A','D'); edge('F','A'); edge('B','F'); edge('E','B');
    edge('C','E'); edge('G','E'); edge('E','F'); edge('D','F');
    run("(e) and (h)", 'A');

    setup('0', 8);
    edge('0','1'); edge('0','2'); edge('0','3'); edge('1','3'); edge('2','4');
    edge('4','5'); edge('5','2'); edge('3','5'); edge('3','6'); edge('4','7');
    run("(f)", '0');

    setup('0', 8);
    twoWay('0','1'); twoWay('0','3'); edge('0','7');
    edge('1','4'); edge('7','4'); edge('7','5'); edge('3','5');
    edge('4','6'); edge('5','6');
    run("(g)", '0');
    return 0;
}
