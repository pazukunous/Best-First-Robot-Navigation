#ifndef AI_GRID_H
#define AI_GRID_H

#include "Node.h"

class GridMap{
public:
  GridMap(Node ***grid, Node *goal, Node *start, int dimension);

  ~GridMap();

  void printMap();
  Node ***getGrid();
  Node *getGoal();
  Node *getInitial();
  int getDim();

private:
  Node ***grid;
  Node *goal;
  Node *initial;
  int dim;

};

#endif