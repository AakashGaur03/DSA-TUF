#include <bits/stdc++.h>
using namespace std;

int findCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
  vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

  for (auto it : edges) {
    // Bidirectional
    dist[it[0]][it[1]] = it[2];
    dist[it[1]][it[0]] = it[2];
  }

  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
          continue;
        }
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int cntCity = n;
  int cityNo = 0;
  for (int city = 0; city < n; city++) {
    int cnt = 0;
    for (int adjCity = 0; adjCity < n; adjCity++) {
      if (dist[city][adjCity] <= distanceThreshold) {
        cnt++;
      }
    }
    if (cnt <= cntCity) {
      cntCity = cnt;
      cityNo = city;
    }
  }
  return cityNo;
}

int main() {
  cout << "41 G 43 Find the City With the Smallest Number of Neighbours at a "
          "Threshold Distance"
       << endl;

  //        roblem Statement: There are n cities numbered from 0 to n-1. Given
  //        the array edges where edges[i] = [fromi, toi,weighti] represents a
  //        bidirectional and weighted edge between cities fromi and toi, and
  //        given the integer distance Threshold. You need to find out a city
  //        with the smallest number of cities that are reachable through some
  //        path and whose distance is at most Threshold Distance, If there are
  //        multiple such cities, our answer will be the city with the greatest
  //        number.

  // Note: that the distance of a path, connecting cities i and j are equal to
  // the sum of the edges' weights along that path.

  // So question is asking that a country that can have minimum neighbours under
  // the threshold and also if there are multiple of them then we need to give
  // grestest one
  // Simply apply Floyd Warshall then iterate over keeping the track of cities
  // travelled by each node and acc to it return the answer
  int n = 4;

  vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};

  int distanceThreshold = 4;

  int ans = findCity(n, edges, distanceThreshold);

  cout << "City with the smallest number of neighbours: " << ans << endl;
  return 0;
}