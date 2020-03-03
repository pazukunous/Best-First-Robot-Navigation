#ifndef AI_CALC_H
#define AI_CALC_H

#include <list>
#include "Node.h"
#include "GridMap.h"

class Calc{
	public:

		Calc(GridMap *gridMap){
			this->gridMap = gridMap;
		}

		Calc(){}

		virtual void insertPath(Node* toIns, Node* parent) = 0;
		virtual Node* popNode() = 0;
		virtual void calcDist() = 0;
		virtual void move(Node* node) = 0;

	protected:
		GridMap *gridMap;
		std::list<Node*> listNodes;
		int steps;
		int totalNodes;

};

#endif