#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    // Create an adjacency list with probabilities
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i][0], v = edges[i][1];
        double prob = succProb[i];
        graph[u].emplace_back(v, prob);
        graph[v].emplace_back(u, prob);
    }

    // Priority queue to store the node and the current maximum probability to reach it
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start});

    // Distance array to store the maximum probability to reach each node
    vector<double> maxProb(n, 0.0);
    maxProb[start] = 1.0;

    while (!pq.empty()) {
        auto [prob, node] = pq.top();
        pq.pop();

        if (node == end) return prob;

        for (auto& [neighbor, edgeProb] : graph[node]) {
            double newProb = prob * edgeProb;
            if (newProb > maxProb[neighbor]) {
                maxProb[neighbor] = newProb;
                pq.push({newProb, neighbor});
            }
        }
    }

    return 0.0;
}

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0, end = 2;

    double result = maxProbability(n, edges, succProb, start, end);
    cout << "The maximum probability of the path is: " << result << endl;

    return 0;
}
