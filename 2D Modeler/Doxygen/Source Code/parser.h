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

//! Method parser(myShapes::vector<myShapes::Shape*> *shapeStorage)
/*!
 * \brief This methods reads the Shapes data from an input file.
 * \param shapeStorage
 */
void parser(myShapes::vector<myShapes::Shape*> *shapeStorage);

//! Method pointVectorReadIn(myShapes::vector<int>&,int, std::ifstream &)
/*!
 * \brief This methods reads the point vector input.
 * \param spointVector
 * \param l
 * \fin
 */
void pointVectorReadIn(myShapes::vector<int>& pointVector, int l, std::ifstream &fin);

//! Method penInfo  (std::ifstream &, std::string&, int&, std::string&,
//!    std::string& , std::string&);
/*!
 * \brief This method reads penInfo and brushInfor from file
 * \param std::ifstream &fin
 * \param std::string& c
 * \param int& w
 * \param std::string& s
 * \param std::string& cS
 * \param std::string& jS)
 */
void penInfo  (std::ifstream &fin, std::string& c, int& w, std::string& s, std::string& cS, std::string& jS);

//! Method brushInfo(std::ifstream &fin, std::string& c, std::string& s)
/*!
 * \brief This method reads brushInfo from file
 * \param std::ifstream &fin
 * \param std::string& c
 * \param std::string& s
 */
void brushInfo(std::ifstream &fin, std::string& c, std::string& s);

//! Method setPenInfo  (myShapes::Shape *dummy, std::string c, int w, std::string s,
//!     std::string cS, std::string jS);
/*!
 * \brief This method sets Pen Information from supplied arguments.
 * \param myShapes::Shape *dummy
 * \param std::string& c
 * \param int& w
 * \param std::string& s
 * \param std::string& cS
 * \param std::string& jS)
 */
void setPenInfo  (myShapes::Shape *dummy, std::string c, int w, std::string s, std::string cS, std::string jS);

//! Mwthod setBrushInfo(myShapes::Shape *dummy, std::string c, std::string s)
/*!
 * \brief This method reads brushInfo from file
 * \param myShapes::Shape *dummy
 * \param std::string& c
 * \param std::string& s
 */
void setBrushInfo(myShapes::Shape *dummy, std::string c, std::string s);

#endif //!PARSER_H
