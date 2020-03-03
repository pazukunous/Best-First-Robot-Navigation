#ifndef AI_NODE_H
#define AI_NODE_H

struct Node {
  int row;
  int col;
  char oChar;
  double weight;
  double pathCost;
  bool visited;
  Node* parent;


};

#endif