/*********************************************************
* AUTHOR   : Jonathan Brubaker
* Project  : The big Kahoona
* CLASS    : CS1C
* SECTION  : MTWTh 4:30-7:30
* Due Date : ?
*********************************************************/
#include "parser.h"
#include "Text.h"
#include "Polygon.h"
#include "Line.h"
#include "Polyline.h"
#include "Ellipse.h"
#include "Rectangle.h"

using namespace std;

/**********************************************************
* Parser.cpp
*_________________________________________________________
* WHAT THE CODE ACTUALLY DOES
* 	1. begins reading in from shapes file
* 	2. gets id and name
* 	3. once acquires name, will use name in if else if
* 	   Statement to find its proper shape
* 	4. using cookie cutter functions will get all relevant
* 	   data for each shape (except text, text upcasts)
* 	4. will read in vector of points to shape then reset
* 	   vector of points for next pass
* 	5. passes dummy (shape object) into shapeStorage vector
* 	6. repeats until eof
*_________________________________________________________
* cosnt
***********************************************************/
void parser(myShapes::vector<myShapes::Shape*> *shapeStorage)
{
	ifstream fin;

	int    shapeId;
	string shapeName;

	string penColor;
	int    penWidth;
	string penStyle;
	string penCap;
	string penJoin;

	string brushColor;
	string brushStyle;

	string textString;
	string textColor;
	string textAlignment;
	int    textPointSize;
	string textFontFamily;
	string textFontStyle;
	string textFontWeight;

	myShapes::Shape *dummy; //where new objects are stored

	myShapes::Text *pText;  //placeholder to downcast shape into text

    //moved inside the while loop vector<int> pointVector; //where points are stored
    //vector<int> resetVector; //temp fix until clean vector moved to public.

	fin.open("shapes.txt");

    if(!fin.good())
        return;

	while(!(fin.eof()))
	{
		fin.ignore(1, '\n');  //skips whitespace
		fin.ignore(100, ':'); // ShapeId:
		fin >> shapeId;
		fin.ignore(100, ':'); //ShapeType:
		fin >> shapeName;

		//ShapeDimensions:
        myShapes::vector<int> pointVector; //where points are stored
		if     (shapeName == "Line"){
			pointVectorReadIn(pointVector, 4, fin);
			penInfo(fin, penColor, penWidth, penStyle, penCap, penJoin);
			dummy = new myShapes::Line(shapeId);
			setPenInfo(dummy, penColor, penWidth, penStyle, penCap, penJoin);
		}
		else if(shapeName == "Polyline"){
			pointVectorReadIn(pointVector, 8, fin);
			penInfo(fin, penColor, penWidth, penStyle, penCap, penJoin);
            dummy = new myShapes::Polyline(shapeId);
			setPenInfo(dummy, penColor, penWidth, penStyle, penCap, penJoin);
		}
		else if(shapeName == "Polygon"){
			pointVectorReadIn(pointVector, 8, fin);
			penInfo(fin, penColor, penWidth, penStyle, penCap, penJoin);
			brushInfo(fin, brushColor, brushStyle);
			dummy = new myShapes::Polygon(shapeId);
			setPenInfo(dummy, penColor, penWidth, penStyle, penCap, penJoin);
			setBrushInfo(dummy, brushColor, brushStyle);
		}
		else if(shapeName == "Rectangle"){
			pointVectorReadIn(pointVector, 4, fin);
			penInfo(fin, penColor, penWidth, penStyle, penCap, penJoin);
			brushInfo(fin, brushColor, brushStyle);
			dummy = new myShapes::Rectangle(shapeId);
			setPenInfo(dummy, penColor, penWidth, penStyle, penCap, penJoin);
			setBrushInfo(dummy, brushColor, brushStyle);
		}
		else if(shapeName == "Square"){
			pointVectorReadIn(pointVector, 3, fin);
			penInfo(fin, penColor, penWidth, penStyle, penCap, penJoin);
			brushInfo(fin, brushColor, brushStyle);
            dummy = new myShapes::Rectangle(shapeId, true);
			setPenInfo(dummy, penColor, penWidth, penStyle, penCap, penJoin);
			setBrushInfo(dummy, brushColor, brushStyle);
		}
		else if(shapeName == "Ellipse"){
			pointVectorReadIn(pointVector, 4, fin);
			penInfo(fin, penColor, penWidth, penStyle, penCap, penJoin);
			brushInfo(fin, brushColor, brushStyle);
			dummy = new myShapes::Ellipse(shapeId);
			setPenInfo(dummy, penColor, penWidth, penStyle, penCap, penJoin);
			setBrushInfo(dummy, brushColor, brushStyle);
		}
		else if(shapeName == "Circle"){
			pointVectorReadIn(pointVector, 3, fin);
			penInfo(fin, penColor, penWidth, penStyle, penCap, penJoin);
			brushInfo(fin, brushColor, brushStyle);
			dummy = new myShapes::Ellipse(shapeId, true);
			setPenInfo(dummy, penColor, penWidth, penStyle, penCap, penJoin);
			setBrushInfo(dummy, brushColor, brushStyle);
		}
		else{//this case is TEXT
			pointVectorReadIn(pointVector, 4, fin);
			fin.ignore(100, ':');
            getline(fin, textString);
			fin.ignore(100, ':');
            fin >> textColor;
			fin.ignore(100, ':');
            fin >> textAlignment;
			fin.ignore(100, ':');
            fin >> textPointSize;
			fin.ignore(100, ':');
            getline(fin, textFontFamily);
			fin.ignore(100, ':');
            fin >> textFontStyle;
			fin.ignore(100, ':');
            fin >> textFontWeight;
			pText = new myShapes::Text(shapeId);//Because i need shapes set func

			pText->setTextString(textString);
			pText->setPenColor(textColor);
			pText->setAlignment(textAlignment);
			pText->setPointSize(textPointSize);
			pText->setFontFamily(textFontFamily);
			pText->setfontStyle(textFontStyle);
			pText->setFontWeight(textFontWeight);

			dummy = pText; //upcasts so program doesn't flip
		}//end esleifs

		dummy->updateDimensions(pointVector); //reads points into dimensions
        //pointVector = resetVector; // resets array for next pass

		shapeStorage->push_back(dummy); // adds new element to shape vector
	}

	fin.close();
}

/*pointVectorReadIn - reads in points for shape
 * preconditions:
 * 		a vector of type int to store points
 * 		int l, number of points
 * 		and a infile stream
 * postconditions:
 * 		will fill up vector with the shapes points read in form file
 */
void pointVectorReadIn(myShapes::vector<int>& pointVector, int l, ifstream &fin)
{
	int dummy;

	fin.ignore(100, ':');//ignores points text

	for(int i = 0; i < l; i++)
	{
		fin >> dummy;
		pointVector.push_back(dummy);
		fin.ignore(1, ','); //goes through commas
	}
}

/*penInfo - reads in penInfo for for shape
 * preconditions:
 * 		a crud ton of variables
 * 		and a infile stream
 * postconditions:
 * 		will save information about penInfo for object
 */
void penInfo(ifstream &fin, string& c, int& w, string& s, string& cS, string& jS)
{
    fin.ignore(100, ':'); //PenColor:
	fin >> c;
	fin.ignore(100, ':');//PenWidth:
	fin >> w;
	fin.clear();
	fin.ignore(100, ':');//PenStyle:
	fin >> s;
	fin.ignore(100, ':');//PenCapStyle:
	fin >> cS;
	fin.ignore(100, ':');//PenJoinStyle:
	fin >> jS;
}

/*brushInfo - reads in brushInfo for for shape
 * preconditions:
 * 		a fair amount of variables
 * 		and a infile stream
 * postconditions:
 * 		will save information about brushInfo for object
 */
void brushInfo(ifstream &fin, string& c, string& s)
{
	fin.ignore(100, ':');//BrushColor:
	fin >> c;
	fin.ignore(100, ':');//BrushStyle:
	fin >> s;
}

/*setPenInfo - saves PenInfo to shape
 * preconditions:
 * 		a fair amount of variables
 * 		and a shape pointer
 * postconditions:
 * 		will store information about shape into dummy
 */
void setPenInfo(myShapes::Shape *dummy, string c, int w, string s, string cS, string jS)
{
	dummy->setPenColor(c);
	dummy->setPenWidth(w);
	dummy->setPenStyle(s);
	dummy->setPenCapStyle(cS);
	dummy->setPenJoinStyle(jS);
}

/*setBrushInfo - saves brushInfo to shape
 * preconditions:
 * 		a fair amount of variables
 * 		and a shape pointer
 * postconditions:
 * 		will store information about shape into dummy
 */
void setBrushInfo(myShapes::Shape *dummy, string c, string s)
{
	dummy->setBrushColor(c);
	dummy->setBrushStyle(s);
}
