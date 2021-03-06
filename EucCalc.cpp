#include "EucCalc.h"
#include <cmath>
#include <iostream>

using namespace std;

EucCalc::EucCalc(GridMap *gridMap){
	this->gridMap = gridMap;
}

void EucCalc::insertPath(Node* toIns, Node* parent){
	list<Node*>::iterator iterator;
	if (toIns->visited==true)
		return;
	toIns->parent = parent;
	for (iterator = this->listNodes.begin(); iterator != this->listNodes.end(); iterator++){
		Node* currNode = *iterator;
		if(toIns->weight < currNode->weight){
			toIns->visited = true;
			this->listNodes.insert(iterator, toIns);
			return;
		}
	}
	toIns->visited = true;
	this->listNodes.insert(iterator, toIns);
}

Node* EucCalc::popNode() {
	Node* poppedNode = *(this->listNodes.begin());
	if(poppedNode == nullptr){
		throw "No paths in list";
	}
	this->listNodes.pop_front();
	return poppedNode;
}

void EucCalc::calcDist(){
	GridMap *gridMap = this->gridMap;
	Node* goal = gridMap->getGoal();
	Node*** grid = gridMap->getGrid();
	Node *currNode;
	int dim = gridMap->getDim();

	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++)
		{
			currNode = grid[i][j];
			if(currNode->oChar != '+')
			{
				int x1 = goal->row;
				int y1 = goal->col;
				int x2 = currNode->row;
				int y2 = currNode->col;
				currNode->weight = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
			}
			else
				currNode->weight = -1;
		}
	}
}

void EucCalc::printGridWeights()
{
	cout<<"u need this?"<<endl;
}

void EucCalc::move(Node *node)
{
	int x = node->row;
	int y = node->col;

	Node*** grid = this->gridMap->getGrid();

	if ((y-1) >= 0 && grid[x][y-1]->oChar!='+')
	{
		Node* toIns = grid[x][y-1];
		this->insertPath(toIns, node);
	}
	if((y+1 < this->gridMap->getDim()) && grid[x][y+1]->oChar!='+')
	{
		Node* toIns = grid[x][y+1];
		this->insertPath(toIns, node);
	}
	if((x-1) >= 0 && grid[x-1][y]->oChar!='+')
	{
		Node* toIns = grid[x-1][y];
		this->insertPath(toIns, node);
	}
	if((x+1) < this->gridMap->getDim() && grid[x+1][y]->oChar!='+')
	{
		Node* toIns = grid[x+1][y];
		this->insertPath(toIns, node);
	}
}

Node* EucCalc::findPath()
{
	int sRow = this->gridMap->getInitial()->row;
	int sCol = this->gridMap->getInitial()->col;
	Node* currNode = this->gridMap->getGrid()[sRow][sCol];
	while(currNode->oChar!='g')
	{
		move(currNode);
		currNode = this->popNode();
	}
	return this->gridMap->getGrid()[currNode->row][currNode->col];
}

void EucCalc::printPath(Node *node){
	Node *currNode = node->parent;
	this->steps = 1;
	while(currNode->oChar!='i')
	{
		currNode->oChar = 'o';
		currNode = currNode->parent;
		++steps;
	}
	GridMap* gridMap = this->gridMap;
	int dim = gridMap -> getDim();

	Node*** grid= gridMap->getGrid();
	gridMap->printMap();
	cout<<"Steps Taken: "<<this->steps << endl;
	cout<<"Node Tree Count: "<<this->listNodes.size() << endl;
}

void EucCalc::AinsertPath(Node* toIns, Node* parent)
{
	list<Node*>::iterator iterator;
	if (toIns->visited==true)
		return;
	toIns->parent = parent;
	toIns->pathCost = parent->pathCost+1;
	for (iterator = this->listNodes.begin(); iterator != this->listNodes.end(); iterator++){
		Node* currNode = *iterator;
		if(toIns->pathCost < currNode->pathCost){
			toIns->visited = true;
			this->listNodes.insert(iterator, toIns);
			return;
		}
	}
	toIns->visited = true;
	this->listNodes.insert(iterator, toIns);
}

void EucCalc::Amove(Node *node)
{
	int x = node->row;
	int y = node->col;

	Node*** grid = this->gridMap->getGrid();

	if ((y-1) >= 0 && grid[x][y-1]->oChar!='+')
	{
		Node* toIns = grid[x][y-1];
		this->AinsertPath(toIns, node);
	}
	if((y+1 < this->gridMap->getDim()) && grid[x][y+1]->oChar!='+')
	{
		Node* toIns = grid[x][y+1];
		this->AinsertPath(toIns, node);
	}
	if((x-1) >= 0 && grid[x-1][y]->oChar!='+')
	{
		Node* toIns = grid[x-1][y];
		this->AinsertPath(toIns, node);
	}
	if((x+1) < this->gridMap->getDim() && grid[x+1][y]->oChar!='+')
	{
		Node* toIns = grid[x+1][y];
		this->AinsertPath(toIns, node);
	}
}

Node* EucCalc::AfindPath()
{
	int sRow = this->gridMap->getInitial()->row;
	int sCol = this->gridMap->getInitial()->col;
	Node* currNode = this->gridMap->getGrid()[sRow][sCol];
	while(currNode->oChar!='g')
	{
		Amove(currNode);
		currNode = this->popNode();
	}
	return this->gridMap->getGrid()[currNode->row][currNode->col];
}
