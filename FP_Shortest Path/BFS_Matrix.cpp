#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

class Graph{
	int V;
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}

	void addVertex(string str, int u, int v){
	    adjM[u][v] = v;
	    places[v] = str;
	}

	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	        for(int j = 1; j<=V;j++){
	            if(adjM[i][j] == 0) cout << ".  ";
	            else if (adjM[i][j] < 10) cout << adjM[i][j] << "  ";
	            else cout << adjM[i][j] << " ";
	        }
	        cout <<  endl;
	    }
	}

	bool shortest_path(int src, int dest, int pred[], int dist[]){
	queue<int> q;
	bool visited[V] = {false};
	dist[21] = {0};
	pred[21] = {-1};
	visited[src] = true;
	dist[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1; i<=V; i++){
			if(visited[i] == false && adjM[u][i] != 0){
				visited[i] = true;
				dist[i] = dist[u] + 1;
				pred[i] = u;
				cout << u << " " << i << endl;
				q.push(i);
				if(i == dest) return true;
			}
		}
	}
	return false;
    }

    void shortestDistance(int src, int dest){
		int pred[V], dist[V];
		shortest_path(src, dest, pred, dist);
		vector<int> path;
		int c = dest;
		path.push_back(c);
		while(pred[c] != 0){
			path.push_back(pred[c]);
			c = pred[c];
		}
		for(int i = path.size() - 1; i >= 0; i--){
			cout << path[i] << " " << places[path[i]] << endl;
		}
}
};
int main(){
	Graph graph(20);
	graph.addVertex("rumah", 1, 1);
	graph.addVertex("al kindi", 1, 2);
	graph.addVertex("lobster", 1, 4);
	graph.addVertex("sd al kindi", 2, 2);
	graph.addVertex("smp al kindi", 2, 3);
	graph.addVertex("smp al kindi", 3, 3);
	graph.addVertex("lobster farm", 4, 4);
	graph.addVertex("siomay", 4, 5);
	graph.addVertex("kolam zahra", 4, 8);
	graph.addVertex("saung sobet", 4, 12);
	graph.addVertex("siomay", 5, 5);
	graph.addVertex("ayam geprek", 5, 6);
	graph.addVertex("homemade chicken", 5, 7);
	graph.addVertex("ayam geprek", 6, 6);
	graph.addVertex("homemade chicken", 7, 7);
	graph.addVertex("kolam zahra", 8, 8);
	graph.addVertex("kedai kopi", 8, 9);
	graph.addVertex("chicie putri", 8, 11);
	graph.addVertex("kedai kopi", 9, 9);
	graph.addVertex("kedai kopi", 9, 10);
	graph.addVertex("madu hutan", 10, 10);
	graph.addVertex("dealer motor", 10, 16);
	graph.addVertex("chicie putri", 11, 11);
	graph.addVertex("saung sobet", 12, 12);
	graph.addVertex("vape store", 12, 13);
	graph.addVertex("vape store", 13, 13);
	graph.addVertex("galaxy swalayan", 13, 14);
	graph.addVertex("galaxy swalayan", 14, 14);
	graph.addVertex("toko pas jaya", 14, 15);
	graph.addVertex("toko pas jaya", 15, 15);
	graph.addVertex("dealer motor", 15, 16);
	graph.addVertex("dealer motor", 16, 16);
	graph.addVertex("de klapper", 16, 17);
	graph.addVertex("de klapper", 17, 17);
	graph.addVertex("kredit plus", 17, 18);
	graph.addVertex("kredit plus", 18, 18);
	graph.addVertex("ratu palugada", 18, 19);
	graph.addVertex("ratu palugada", 19, 19);
	graph.addVertex("rit barbershop", 19, 20);
	graph.addVertex("rit barbershop", 20, 20);

	graph.showAllVertex();
	int source, dest;
	cin >> source >> dest;
    graph.shortestDistance(source,dest);
}
