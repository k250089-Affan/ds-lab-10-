#include <iostream>
using namespace std;

int adj[6][6];

void display() {
    cout << "  A B C D E F" << endl;
    for (int i = 0; i < 6; i++) {
        cout << (char)('A' + i) << " ";
        for (int j = 0; j < 6; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

void showEdges() {
    for (int i = 0; i < 6; i++) {
        cout << (char)('A' + i) << " outgoing: ";
        for (int j = 0; j < 6; j++)
            if (adj[i][j])
                cout << (char)('A' + j) << "(" << adj[i][j] << ") ";
        cout << endl;
        cout << (char)('A' + i) << " incoming: ";
        for (int j = 0; j < 6; j++)
            if (adj[j][i])
                cout << (char)('A' + j) << "(" << adj[j][i] << ") ";
        cout << endl;
    }
}

int main() {
    adj[0][1] = 4;  adj[0][2] = 2;  adj[1][2] = 5;  adj[1][3] = 10;
    adj[2][4] = 3;  adj[4][3] = 4;  adj[3][5] = 11;

    int choice = 0;
    char a, b;
    int w;
    while (choice != 5) {
        cout << endl << "1.Insert 2.Delete 3.Display 4.In/Out edges 5.Exit: ";
        cin >> choice;
        if (choice == 1) {
            cout << "From To Weight: ";
            cin >> a >> b >> w;
            adj[a - 'A'][b - 'A'] = w;
        } else if (choice == 2) {
            cout << "From To: ";
            cin >> a >> b;
            adj[a - 'A'][b - 'A'] = 0;
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            showEdges();
        }
    }
    return 0;
}
