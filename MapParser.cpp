#include <iostream>
#include <fstream>
#include "MapParser.h"

using namespace std;

MapParser::MapParser(){
  cout << "MapParser created" << endl;

};

GridMap* MapParser::parse(std::string fileName)
{
  Node*** gridMap;
  Node* goal;
  Node* start;
  int dim;

  ifstream textFile;
  textFile.open(fileName.c_str());

  int lineCount = 0;
  string currLine;
  if(textFile.is_open())
  {
    while(getline(textFile, currLine))
    {
      if (lineCount == 0)
      {
        dim = atoi(currLine.c_str());
        this->dim = dim;
        gridMap = new Node** [dim];

      }
      else
      {
        gridMap[lineCount-1] = new Node*[dim];
        for(int i = 0; i<dim; i++)
        {
          char currChar = currLine[i];
          Node * currNode = new Node();
          currNode->col = i;
          currNode->row = lineCount - 1;
          currNode->oChar = currChar;

          gridMap[lineCount-1][i] = currNode;
          currNode->visited = false;

          if(currNode->oChar == 'g'){
            goal = currNode;
          }

          else if(currNode->oChar == 'i'){
            currNode->visited = true;
            start = currNode;
          }
        }
      }

      lineCount++;
    }
  }

  return new GridMap(gridMap, goal, start, dim);
}

int MapParser::getDim()
{
  return this->dim;
}

MapParser::~MapParser(){
  cout << "Map Parser Destroyed" << endl;
}
