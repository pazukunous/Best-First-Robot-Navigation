#include <iostream>
#include "MapParser.h"
#include "EucCalc.h"
#include "ManCalc.h"

using namespace std;

int main(int argc, char **argv){

  string fileName;
  if (argc > 1){
    fileName = argv[1];
  }
  else{
    cout << "No filename selected" << endl;
    return 0;
  }

  MapParser *mp = new MapParser();


  GridMap *eucMap = mp->parse(fileName);

  cout<<endl;
  
  cout<<"STRATEGY 1: EUCLIDEAN"<<endl;
  EucCalc *eucCalc = new EucCalc(eucMap);
  eucCalc->calcDist();
  Node* eucNodePath = eucCalc->findPath();
  eucCalc->printPath(eucNodePath);
  
  GridMap *manMap = mp->parse(fileName);

  cout<<endl;

  cout<< "STRATEGY 2: MANHANTTAN"<<endl;
  ManCalc *manCalc = new ManCalc(manMap);
  manCalc->calcDist();
  Node* manNodePath = manCalc->findPath();
  manCalc->printPath(manNodePath);

  GridMap *aEucMap = mp->parse(fileName);

  cout<<endl;

  cout<< "STRATEGY 3: A* EUCLIDEAN "<<endl;
  EucCalc *aEucCalc = new EucCalc(aEucMap);
  aEucCalc->calcDist();
  Node *aEucNodePath = aEucCalc->AfindPath();
  aEucCalc->printPath(aEucNodePath);

  GridMap *aManMap = mp->parse(fileName);

  cout<<endl;
  
  cout<< "STRATEGY 4: A* MANHATTAN "<<endl;
  ManCalc *aManCalc = new ManCalc(aManMap);
  aManCalc->calcDist();
  Node *aManNodePath = aManCalc->AfindPath();
  aManCalc->printPath(aManNodePath);


  return 0;

  /*GridMap *test = mp->parse(fileName);

  test->printMap();

  return 0;*/
}
