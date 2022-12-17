#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

class Graph {
    protected:
        int v;
        vector<string> place;
        vector<vector<int>> adj;
        vector<int> dfsResult;
        vector<int> dijkstraRes;
        int dfsWeight;

    public:
        Graph(int len) {
            v = len;
            place.assign(v+1, "");
            vector<int> l (v+1, -1);
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }

        void addVertex(string i, int u, int v, int w){
            adj[u][v] = w;
           place[v] = i;
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                for ( int j = 1; j <= v; j++)
                {
                    if(adj[i][j] == -1) cout << ".  ";
                    else if (adj[i][j] < 10) cout << adj[i][j] << "  ";
                    else cout << adj[i][j] << " ";

                }
                cout << endl;
            }
        }

        void DFS(int start, int end){
            cout << endl;
            cout << "## Shortest path using DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );

            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[start] = true;
            path.push_back(start);
            for ( int it = 1; it <= v; it++)
            {
                if(!visited[it] && adj[start][it] != -1){
                    int wtemp = currWeight;
                    wtemp += adj[start][it];
                    solveDFS(it, end, path, visited, wtemp);
                }
            }
        }
};

int main(){
    Graph graph(20);
	graph.addVertex("rumah", 1, 1, 1);
	graph.addVertex("sd al kindi", 1, 2, 2);
	graph.addVertex("lobster", 1, 4, 4);
	graph.addVertex("sd al kindi", 2, 2, 2);
	graph.addVertex("smp al kindi", 2, 3, 3);
	graph.addVertex("smp al kindi", 3, 3, 3);
	graph.addVertex("lobster farm", 4, 4, 4);
	graph.addVertex("siomay", 4, 5, 5);
	graph.addVertex("kolam zahra", 4, 8, 8);
	graph.addVertex("saung sobet", 4, 12, 12);
	graph.addVertex("siomay", 5, 5, 5);
	graph.addVertex("ayam geprek", 5, 6, 6);
	graph.addVertex("homemade chicken", 5, 7, 7);
	graph.addVertex("ayam geprek", 6, 6, 6);
	graph.addVertex("homemade chicken", 7, 7, 7);
	graph.addVertex("kolam zahra", 8, 8, 8);
	graph.addVertex("kedai kopi", 8, 9, 9);
	graph.addVertex("chicie putri", 8, 11, 11);
	graph.addVertex("kedai kopi", 9, 9, 9);
	graph.addVertex("madu hutan", 9, 10, 9);
	graph.addVertex("madu hutan", 10, 10, 10);
	graph.addVertex("dealer motor", 10, 16, 16);
	graph.addVertex("chicie putri", 11, 11, 11);
	graph.addVertex("saung sobet", 12, 12, 12);
	graph.addVertex("vape store", 12, 13, 13);
	graph.addVertex("vape store", 13, 13, 13);
	graph.addVertex("galaxy swalayan", 13, 14, 14);
	graph.addVertex("galaxy swalayan", 14, 14, 14);
	graph.addVertex("toko pas jaya", 14, 15, 15);
	graph.addVertex("toko pas jaya", 15, 15, 15);
	graph.addVertex("dealer motor", 15, 16, 16);
	graph.addVertex("dealer motor", 16, 16, 16);
	graph.addVertex("de klapper", 16, 17, 17);
	graph.addVertex("de klapper", 17, 17, 17);
	graph.addVertex("kredit plus", 17, 18, 18);
	graph.addVertex("kredit plus", 18, 18, 18);
	graph.addVertex("ratu palugada", 18, 19, 19);
	graph.addVertex("ratu palugada", 19, 19, 19);
	graph.addVertex("rit barbershop", 19, 20, 20);
	graph.addVertex("rit barbershop", 20, 20, 20);
    graph.showGraph();
    int start, end;
    cin >> start >> end;
    graph.DFS(start, end);

}
