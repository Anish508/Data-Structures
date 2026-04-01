#include <iostream>
#include <climits>
using namespace std;

int main()
{
      int V;
      cout << "Enter the number of vertices:";
      cin >> V;
      int graph[20][20];

      cout << "Enter the adjecency matrix:\n";
      for (int i = 0; i < V; i++)
      {
            for (int j = 0; j < V; j++)
            {
                  cin >> graph[i][j];
            }
      }

      int key[20], parent[20];
      bool mst[20];

      for (int i = 0; i < V; i++)
      {
            key[i] = INT_MAX;
            mst[i] = false;
      }

      parent[0] = -1;
      key[0] = 0;

      for (int i = 0; i < V - 1; i++)
      {
            int u = -1;
            for (int j = 0; j < V; j++)
            {
                  if (!mst[j] && (u == -1 || key[j] < key[u]))
                  {
                        u = j;
                  }

                  mst[u] = true;

                  for (int v = 0; v < V; v++)
                  {
                        if (graph[u][v] && !mst[v] && graph[u][v] < key[v])
                        {
                              key[v] = graph[u][v];
                              parent[v] = u;
                        }
                  }
            }
      }

      int total = 0;
      cout << "\nEdge \t weight \n";
      for (int i = 1; i < V; i++)
      {
            cout << parent[i] << "-" << i << "\t " << graph[i][parent[i]] << endl;
            total += graph[i][parent[i]];
      }

      cout << "Total Weight=" << " " << total;

      return 0;
}