#include "GridMap.h"
#include <iostream>

using namespace std;

Node ***GridMap::getGrid(){
  return grid;
}

Node* GridMap::getGoal(){
  return goal;
}

Node* GridMap::getInitial(){
  return initial;
}

int GridMap::getDim(){
  return dim;
}

void GridMap::printMap(){
	Node* currNode;
	for (int i = 0; i<dim; i++)
	{
		for(int j = 0; j<dim; j++)
		{
			currNode = grid[i][j];
			if (j==dim-1)
				cout<<currNode->oChar<<endl;
			else
				cout<<currNode->oChar<<" ";
		}
	}
}

GridMap::GridMap(Node ***grid, Node* goal, Node* start, int dim)
{
  this->grid = grid;
  this->goal = goal;
  this->initial = start;
  this->dim = dim;
}



GridMap::~GridMap(){
  delete grid;
}
