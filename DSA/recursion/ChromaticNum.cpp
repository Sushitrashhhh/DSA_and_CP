#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(const vector<vector<int>>& graph, const vector<int>& color, int node, int c) {
    int n=graph.size();
    for (int i =0;i<n;i++) {
        if (graph[node][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int node) {
    int n = graph.size();
    if (node == n) {
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, node, c)) {
            color[node] = c;
            if (graphColoringUtil(graph, m, color, node + 1)) {
                return true;
            }
            color[node] = 0; // backtrack
        }
    }
    return false;
}

bool graphColoring(const vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> color(n, 0);
    return graphColoringUtil(graph, m, color, 0);
}

