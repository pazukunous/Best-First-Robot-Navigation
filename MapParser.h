#ifndef AI_PARSER_H
#define AI_PARSER_H

#include "Node.h"
#include "GridMap.h"

class MapParser{
public:
  char **gridMap;
  int dim;

  MapParser();
  ~MapParser();
  GridMap* parse(std::string fileName);

  int getDim();

  
};

#endif