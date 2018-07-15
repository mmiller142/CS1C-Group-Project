/*********************************************************
* AUTHOR   : Jonathan Brubaker
* Project  : The big Kahoona
* CLASS    : CS1C
* SECTION  : MTWTh 4:30-7:30
* Due Date : ?
*********************************************************/
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>

#include "vector.h"
#include "Shape.h"

//The parsing function
void parser(myShapes::vector<myShapes::Shape*> *shapeStorage);

//reads in points from file
void pointVectorReadIn(myShapes::vector<int>& pointVector, int l, std::ifstream &fin);

//reads penInfo and brushInfor from file
void penInfo  (std::ifstream &fin, std::string& c, int& w, std::string& s, std::string& cS, std::string& jS);
void brushInfo(std::ifstream &fin, std::string& c, std::string& s);

void setPenInfo  (myShapes::Shape *dummy, std::string c, int w, std::string s, std::string cS, std::string jS);
void setBrushInfo(myShapes::Shape *dummy, std::string c, std::string s);

#endif //!PARSER_H
