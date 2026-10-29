#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, cost;
};

class DisjointSet {
private:
    vector<int> parent, rankValue;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rankValue.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (rankValue[x] < rankValue[y]) parent[x] = y;
        else if (rankValue[x] > rankValue[y]) parent[y] = x;
        else { parent[y] = x; rankValue[x]++; }
        return true;
    }
};

int main() {
    int n, m;
    cout << "Enter number of road junctions: ";
    if (!(cin >> n) || n <= 0) { cout << "Invalid number.\n"; return 1; }

    vector<string> names(n);
    cout << "Enter unique names (one word each):\n";
    for (int i = 0; i < n; i++) {
        cout << "Name " << i + 1 << ": ";
        cin >> names[i];
        for (int j = 0; j < i; j++) {
            if (names[i] == names[j]) { cout << "Names must be unique.\n"; return 1; }
        }
    }

    cout << "Enter number of possible roads: ";
    if (!(cin >> m) || m < 0) { cout << "Invalid number of roads.\n"; return 1; }

    vector<Edge> edges;
    cout << "Enter each road as: name1 name2 cost\n";
    for (int i = 0; i < m; i++) {
        string a, b;
        int cost, u = -1, v = -1;
        cout << "Road " << i + 1 << ": ";
        cin >> a >> b >> cost;
        for (int j = 0; j < n; j++) {
            if (names[j] == a) u = j;
            if (names[j] == b) v = j;
        }
        if (u == -1 || v == -1) { cout << "Unknown name.\n"; return 1; }
        if (cost < 0) { cout << "Cost cannot be negative.\n"; return 1; }
        Edge e; e.u = u; e.v = v; e.cost = cost;
        edges.push_back(e);
    }

    // Manual sort keeps this program compatible with older Dev-C++ compilers.
    for (int i = 0; i < (int)edges.size() - 1; i++) {
        for (int j = 0; j < (int)edges.size() - 1 - i; j++) {
            if (edges[j].cost > edges[j + 1].cost) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    DisjointSet ds(n);
    vector<Edge> chosen;
    long long total = 0;
    for (int i = 0; i < (int)edges.size(); i++) {
        if (ds.unite(edges[i].u, edges[i].v)) {
            chosen.push_back(edges[i]);
            total += edges[i].cost;
            if ((int)chosen.size() == n - 1) break;
        }
    }

    cout << "\nSelected minimum-cost roads:\n";
    cout << "From\tTo\tCost\n";
    for (int i = 0; i < (int)chosen.size(); i++)
        cout << names[chosen[i].u] << "\t" << names[chosen[i].v]
             << "\t" << chosen[i].cost << endl;

    if ((int)chosen.size() != n - 1)
        cout << "Cannot connect all locations: network is disconnected.\n";
    else
        cout << "Minimum total cost: " << total << endl;
    return 0;
}
