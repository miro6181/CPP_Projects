#include <iostream>
#include <vector>
#include <queue>
#include "Graph.hpp"

using namespace std;

Graph::Graph() {

}

Graph::~Graph() {

}

void Graph::addEdge(string v1, string v2, int distance) {
  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].name == v1) {
      for (int j = 0; j < vertices.size(); j++) {
        if (vertices[j].name == v2 && i != j) {
          Edge e;
          e.v = &vertices[j];
          e.distance = distance;
          vertices[i].Edges.push_back(e);
        }
      }
    }
  }
} //Done

void Graph::addVertex(string name) {
  bool found = false;

  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].name == name) {
      found = true;
      cout << vertices[i].name << " found."
           << "\n";
    }
  }

  if (found == false) {
    vertex t;
    t.name = name;
    t.district = -1;
    vertices.push_back(t);
  }
} //Done

void Graph::displayEdges() {
  // Iterate through vertices and their neighbors
  for (int i = 0; i < vertices.size(); i++) {
    cout << vertices[i].district << ":" << vertices[i].name << "-->";
    for (int j = 0; j < vertices[i].Edges.size(); j++) {
      cout << vertices[i].Edges[j].v->name;

      if (j != vertices[i].Edges.size() - 1) {
        cout << "***";
      }
    }
    cout << "\n";
  }
} //Done

void Graph::assignDistricts() {
  int district = 1;

  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].district == -1) {
     BFTraversalLabel(vertices[i].name, district);
     district++;
    }
  }
} //Done

void Graph::printDFS() {
  for (int i = 0; i < vertices.size(); i++) {
    cout << vertices[i].district << ":" << vertices[i].name << "-->";
    for (int j = 0; j < vertices[i].Edges.size(); j++) {
      cout << vertices[i].Edges[j].v->name;
      if (j != vertices[i].Edges.size() - 1) cout << "***";
      else cout << endl;
    }
  }
} //Not sure if correct

void Graph::setAllVerticesUnvisited() {
  for (int i = 0; i < vertices.size(); i++) {
    vertices[i].visited = false;
  }
} //Done

vertex *Graph::findVertex(string name) {
  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].name == name) {
      return vertices[i];
    }
  }
} //Done

void Graph::BFTraversalLabel(string startingCity, int distID) {
  queue<vertex *> t;

  for (int i = 0; i < vertices.size(); i++) {
    vertices[i].visited = false;
  }

  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].name == startingCity) {
      vertices[i].visited = true;
      t.push(&vertices[i]);
      vertices[i].district = distID;
      break;
    }
  }

  while (t.empty() != true) {
    vertex *front = t.front();
    t.pop();
    for (int i = 0; i < front->Edges.size(); i++) {
      if (front->Edges[i].v->visited == false) {
        front->Edges[i].v->visited = true;
        front->Edges[i].v->district = distID;
        t.push(front->Edges[i].v);
      }
    }
  }
} //Not sure

void Graph::DFTraversal(vertex *v) {

} //????
