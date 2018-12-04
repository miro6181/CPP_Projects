#include <iostream>
#include <list>

using namespace std;

class Graph {
  //Number of Vertecies
  int V;
  //List of adjacent vertecies
  list<int> *adj;

public:
  //Constructor
  Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
  }
  //Add edges to graph
  void addEdge(int v, int w) {
    //Add W to v's adjacent vertecies
    adj[v].push_back(w);
  }
  void reverseEdges() {
    //Itterate through all the vertecies in the graph and switch the order of each edge in the list
    for(int i = 0, i < v, i++) {
      adj[i] 
    }
  }
};
int main() {
  Graph g(6);
  g.addEdge(1,2);
  g.addEdge(2,5);
  g.addEdge(5,2);
  g.addEdge(5,4);
  g.addEdge(3,2);
  g.addEdge(3,5);

  g.reverseEdges();
}
