#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> intPair;

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

	void addVertex(string str, int u, int v, int w){
	    adjM[u][v] = w;
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

	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = 1000;
		}
		dist[src] = 1;

		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			for(int i = 1; i <= V; i++){
				int v = i;
				int w = adjM[u][i];
				if(dist[v] > dist[u] + w && w != 0){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		printf("Vertex Distance from Source\n");
    	for (int i = 1; i <= V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
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
	graph.showAllVertex();
	int src;
	cin >> src;
    graph.djikstra(src);
}
