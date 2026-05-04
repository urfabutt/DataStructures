// File: bfs.h

//#ifndef BFS_H
//#define BFS_H
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct Airport {
//    string id;
//    string name;
//    string city;
//    string country;
//    bool emergency;
//};
//
//class Graph {
//public:
//    Graph() : airports(nullptr), adj(nullptr), n(0) {}
//    ~Graph() { freeGraph(); }
//    void loadAirports(const string& filename) {
//        ifstream fin(filename);
//        if (!fin) return;
//        string line;
//        // first count lines
//        int count = 0;
//        streampos pos = fin.tellg();
//        while (getline(fin, line)) if (!line.empty()) count++;
//        fin.clear(); fin.seekg(0);
//        n = count;
//        airports = new Airport[n];
//        adj = new int* [n];
//        for (int i = 0; i < n; i++) { adj[i] = new int[n]; for (int j = 0; j < n; j++) adj[i][j] = 0; }
//        int idx = 0;
//        while (getline(fin, line)) {
//            if (line.empty()) continue;
//            // expected: ID;Name;City;Country;Emergency(0/1)
//            stringstream ss(line);
//            string tok;
//            getline(ss, airports[idx].id, ';');
//            getline(ss, airports[idx].name, ';');
//            getline(ss, airports[idx].city, ';');
//            getline(ss, airports[idx].country, ';');
//            getline(ss, tok, ';');
//            airports[idx].emergency = (tok == "1");
//            idx++;
//        }
//        fin.close();
//    }
//    void loadRoutes(const string& filename) {
//        ifstream fin(filename);
//        if (!fin) return;
//        string a, b;
//        while (fin >> a >> b) {
//            int u = indexOf(a);
//            int v = indexOf(b);
//            if (u != -1 && v != -1) adj[u][v] = adj[v][u] = 1;
//        }
//        fin.close();
//    }
//    void planTrip(const string& srcId, const string& dstId) {
//        int s = indexOf(srcId);
//        int d = indexOf(dstId);
//        if (s == -1 || d == -1) { cout << "Invalid airport IDs.\n"; return; }
//        int* dist = new int[n];
//        int* parent = new int[n];
//        for (int i = 0; i < n; i++) { dist[i] = -1; parent[i] = -1; }
//        queue<int> q; q.push(s); dist[s] = 0; parent[s] = -1;
//        while (!q.empty()) {
//            int u = q.front(); q.pop();
//            for (int v = 0; v < n; v++) if (adj[u][v] && dist[v] == -1) { dist[v] = dist[u] + 1; parent[v] = u; q.push(v); }
//        }
//        cout << "BFS Traversal Table:\n";
//        cout << "Airport\tDistance\tParent\n";
//        for (int i = 0; i < n; i++) {
//            cout << airports[i].name << "\t" << (dist[i] == -1 ? -1 : dist[i]) << "\t" << (parent[i] == -1 ? string("None") : airports[parent[i]].name) << "\n";
//        }
//        if (dist[d] == -1) cout << "No route from " << srcId << " to " << dstId << ".\n";
//        else {
//            cout << "Minimum stops from " << airports[s].name << " to " << airports[d].name << ": " << dist[d] << "\n";
//            // route
//            int cur = d; string route = "";
//            while (cur != -1) { if (route.empty()) route = airports[cur].name; else route = airports[cur].name + " -> " + route; cur = parent[cur]; }
//            cout << "Route: " << route << "\n";
//        }
//        delete[] dist; delete[] parent;
//    }
//    void printAirports() {
//        for (int i = 0; i < n; i++) cout << airports[i].id << ": " << airports[i].name << " (" << airports[i].city << ")\n";
//    }
//    void saveAirports(const string& filename) {
//        ofstream fout(filename);
//        if (!fout) return;
//        for (int i = 0; i < n; i++) {
//            fout << airports[i].id << ";" << airports[i].name << ";" << airports[i].city << ";" << airports[i].country << ";" << (airports[i].emergency ? "1" : "0") << "\n";
//        }
//        fout.close();
//    }
//private:
//    Airport* airports;
//    int** adj;
//    int n;
//    int indexOf(const string& id) {
//        for (int i = 0; i < n; i++) if (airports[i].id == id) return i;
//        return -1;
//    }
//    void freeGraph() {
//        if (airports) delete[] airports;
//        if (adj) { for (int i = 0; i < n; i++) delete[] adj[i]; delete[] adj; }
//    }
//};
//
//#endif#pragma once

//#ifndef BFS_H
//#define BFS_H
//#include <iostream>
//#include <queue>
//using namespace std;
//
//enum Color { WHITE, GREY, BLACK };
//
//class Graph
//{
//private:
//    int v;
//    int adj[20][20];
//    Color used[20];
//    int distance[20];
//    int parent[20];
//
//public:
//    Graph(int size) {
//        v = size;
//        for (int i = 0; i < v; i++)
//            for (int j = 0; j < v; j++)
//                adj[i][j] = 0;
//        for (int i = 0; i < v; i++) {
//            used[i] = WHITE;
//            distance[i] = -1;
//            parent[i] = -1;
//        }
//    }
//
//    void addEdge(int u, int w) {
//        adj[u][w] = 1;
//        adj[w][u] = 1;
//    }
//
//    void BFS(int s) {
//        for (int i = 0; i < v; i++) {
//            used[i] = WHITE; distance[i] = -1; parent[i] = -1;
//        }
//        queue<int> Q;
//        used[s] = GREY; distance[s] = 0; parent[s] = -1; Q.push(s);
//
//        while (!Q.empty()) {
//            int u = Q.front(); Q.pop();
//            for (int i = 0; i < v; i++) {
//                if (adj[u][i] == 1 && used[i] == WHITE) {
//                    used[i] = GREY;
//                    distance[i] = distance[u] + 1;
//                    parent[i] = u;
//                    Q.push(i);
//                }
//            }
//            used[u] = BLACK;
//        }
//
//        cout << "Node\tDistance\tParent\n";
//        for (int i = 0; i < v; i++)
//            cout << i << "\t" << distance[i] << "\t\t" << parent[i] << endl;
//    }
//
//    int getDistance(int dest) { return distance[dest]; }
//
//    void printRoute(int src, int dest, string airportNames[]) {
//        if (distance[dest] == -1) { cout << "No route exists.\n"; return; }
//        int path[20]; int count = 0; int current = dest;
//        while (current != -1) { path[count++] = current; current = parent[current]; }
//        cout << "Route: ";
//        for (int i = count - 1; i >= 0; i--) {
//            cout << airportNames[path[i]];
//            if (i > 0) cout << " -> ";
//        }
//        cout << endl;
//    }
//};
//
//#endif


#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_AIRPORTS 50

struct Airport {
    string ID;
    string Name;
    string City;
    string Country;
    string Emergency;
};

class Graph {
private:
    int V; // number of airports
    string ID[MAX_AIRPORTS];
    string Name[MAX_AIRPORTS];
    string City[MAX_AIRPORTS];
    string Country[MAX_AIRPORTS];
    string Emergency[MAX_AIRPORTS];

    int adj[MAX_AIRPORTS][MAX_AIRPORTS];

public:
    Graph() {
        V = 0;
        for (int i = 0; i < MAX_AIRPORTS; i++)
            for (int j = 0; j < MAX_AIRPORTS; j++) adj[i][j] = 0;
    }

    int findAirportIndex(string id) {
        for (int i = 0; i < V; i++)
            if (ID[i] == id) return i;
        return -1;
    }

    void loadAirports(string filename) {
        ifstream fin(filename);
        if (!fin) { cout << "Cannot open " << filename << endl; return; }
        string id, name, city, country, emergency;
        while (fin >> id >> name >> city >> country >> emergency) {
            if (V >= MAX_AIRPORTS) { cout << "Max airports reached\n"; break; }
            ID[V] = id; Name[V] = name; City[V] = city; Country[V] = country; Emergency[V] = emergency;
            V++;
        }
        fin.close();
    }

    void loadRoutes(string filename) {
        ifstream fin(filename);
        if (!fin) { cout << "Cannot open " << filename << endl; return; }
        string fromID, toID;
        while (fin >> fromID >> toID) {
            int u = findAirportIndex(fromID);
            int v = findAirportIndex(toID);
            if (u != -1 && v != -1) {
                adj[u][v] = 1;
                adj[v][u] = 1; // undirected
            }
        }
        fin.close();
    }

    void BFS(string srcID, int distance[MAX_AIRPORTS], int parent[MAX_AIRPORTS]) {
        int color[MAX_AIRPORTS]; // 0=WHITE,1=GREY,2=BLACK
        for (int i = 0; i < V; i++) { color[i] = 0; distance[i] = -1; parent[i] = -1; }

        int queue[MAX_AIRPORTS], front = 0, rear = 0;
        int s = findAirportIndex(srcID);
        if (s == -1) { cout << "Source airport not found.\n"; return; }

        queue[rear++] = s;
        color[s] = 1; distance[s] = 0; parent[s] = -1;

        while (front < rear) {
            int u = queue[front++];
            for (int i = 0; i < V; i++) {
                if (adj[u][i] == 1 && color[i] == 0) {
                    color[i] = 1;
                    distance[i] = distance[u] + 1;
                    parent[i] = u;
                    queue[rear++] = i;
                }
            }
            color[u] = 2;
        }
    }

    void printRoute(string srcID, string destID) {
        int distance[MAX_AIRPORTS], parent[MAX_AIRPORTS];
        BFS(srcID, distance, parent);
        int dest = findAirportIndex(destID);
        int src = findAirportIndex(srcID);
        if (src == -1 || dest == -1) { cout << "Invalid source or destination.\n"; return; }
        if (distance[dest] == -1) { cout << "No route exists between " << Name[src] << " and " << Name[dest] << endl; return; }

        cout << "Minimum stops from " << Name[src] << " to " << Name[dest] << ": " << distance[dest] << endl;
        cout << "Route: ";
        int path[MAX_AIRPORTS], count = 0;
        int current = dest;
        while (current != -1) { path[count++] = current; current = parent[current]; }
        for (int i = count - 1; i >= 0; i--) {
            cout << Name[path[i]];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }

    void printDistanceTable(string srcID) {
        int distance[MAX_AIRPORTS], parent[MAX_AIRPORTS];
        BFS(srcID, distance, parent);
        cout << "Airport\tDistance\tParent\n";
        for (int i = 0; i < V; i++) {
            string parentName = (parent[i] == -1 ? "None" : Name[parent[i]]);
            cout << Name[i] << "\t" << distance[i] << "\t\t" << parentName << endl;
        }
    }

    int getNumAirports() { return V; }
    string getAirportName(int idx) { return Name[idx]; }
    string getAirportID(int idx) { return ID[idx]; }
};

#endif
