#ifndef AI_EUC_H
#define AI_EUC_H

#include "Calc.h"

class EucCalc: Calc{
public:
	EucCalc(GridMap *gridMap);
	void insertPath(Node* toIns, Node* parent);
	Node *popNode();
	void calcDist();
	void printGridWeights();
	void move(Node *node);
	Node* findPath();
	void printPath(Node *node);

	void AinsertPath(Node* toIns, Node* parent);
	void Amove(Node *node);
	Node* AfindPath();


};

#endif