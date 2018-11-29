// Code for practice coding midterm 2, question 2
// It's untested and unverified, so take it as you will

Node *temp = root;
while(temp != NULL) {
  cout << temp->key << endl;
  if(temp->right != NULL) {
    temp = temp->right;
  }
  else if(temp->left != NULL) {
    temp = temp->left;
  }
  else {
    break;
  }
}

temp = root->right;
while(temp != NULL) {
  cout << temp->key << endl;
  if(temp->left != NULL) {
    temp = temp->left;
  }
  else if(temp->right != NULL) {
    temp = temp->right;
  }
  else {
    break;
  }
}

// Code for practice coding midterm 1, question 3

struct Node {
  int key;
  vector<Edges> edges;

  bool visited;
  Node *previous; // Used to store the previous node in the path
};

void Graph::printShortestPath(Node *start, Node *end) {
  // Set all the vertices to an unvisited state
  for(int i = 0; i < vertices.size(); i++) {
    vertices[i].visited = false;
    vertices[i].previous = NULL;
  }

  // Set the 'previous' pointer of every node
  bfs(start);

  // If end->previous is still NULL, then it wasn't visited
  if(end->previous == NULL) {
    std::cout << "No path exists!" << std::endl;
  }
  else {
    // Vector to store the keys of the nodes from the end to the start
    vector<int> reversedPath;

    // Go backwards from the end to the start, adding each node to reversedPath
    Node *temp = end->previous;
    while(temp != NULL) {
      reversedPath.push(temp->key);
      temp = temp->previous;
    }

    // Print path from the start to the end by going over reversedPath backwards
    std::cout << "Path: ";
    for(int i = reversedPath.size()-1, i >= 0; i--) {
      std::cout << i << " ";
    }
    std::cout << endl;
  }
}

void Graph::bfs(Node *start) {
  queue<Node*> q;

  // Add the starting node to the queue
  start->visited = true;
  start->previous = NULL;
  q.push(start);

  while(!queue.empty()) {
    // Get current node from queue
    current = queue.front();
    queue.pop();

    // Add all the unvisited adjacent vertices to the queue
    for(int i = 0; i < current->edges.size(); i++) {
      Node *adjacent = current->edges[i];

      // Only visit if unvisited
      if(adjacent->visited == false) {
        // Visit the node, and store the address of the node it was visited from
        adjacent->visited = true;
        adjacent->previous = current;

        queue.push_back(adjacent);
      }
    }
  }
}
