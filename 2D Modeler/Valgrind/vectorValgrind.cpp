/*****************************************************************************
* AUTHOR     	    : C+++++
* Class Project 	: 1
* CLASS	     	    : CS1C
* SECTION    	    : MW 4:30-7:25pm
* DUE DATE   	    : 07/26/2018
*******************************************************************************/
#include<iostream>
#include<string>
#include "vector.h"

using namespace std;
/******************************************************************************
* vector.h Valgrind Test
*-----------------------------------------------------------------------------
* This Program test the templated vector class implemented for our class project.
* It uses valgrind to test whether there are any memory leaks on our implementation
* of the vector class. This vector class is used in our class project to
* hold all our shape objects.
*-----------------------------------------------------------------------------
* INPUT
* The Following will be used for input
*   Nothing: Each method request the required input if any.
* OUTPUT:
*   Prints the deck content of the vector and the ouput of valgrinds memoy
*     leak results.
*****************************************************************************/
int main()
{
  myShapes::vector<int> intVector1;
  myShapes::vector<int> intVector2;
  myShapes::vector<string> stringVector;

  //pushing 8 ints into intVector1
  for (int i = 1; i <= 5; i++)
        intVector1.push_back(i);

    cout << "Size : " << intVector1.size();
    cout << "\nCapacity : " << intVector1.capacity();

    // resizes the vector size to 4
    intVector1.resize(4);

    // prints the vector size after resize()
    cout << "\nSize : " << intVector1.size();

    // checks if the vector is empty or not
    if (intVector1.size() == 0)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    //print vector elements
    cout << "\nVector1 elements are: ";
    for (auto it = intVector1.begin(); it != intVector1.end(); it++)
        cout << *it << " ";
    cout << endl;

    //using overloaded copy operator
    cout << "\nUsing Overloaded copy operator to copy Vector1 into Vector2\n";
    intVector2 = intVector1;
    cout << "\nVector2 elements are: ";
    for (auto it = intVector2.begin(); it != intVector2.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "\nDeleting all the elements of vector1.\n";
    for (auto it = intVector1.begin(); it != intVector1.end(); it++)
        intVector1.erase(it);
    cout << endl;

    // checks if the vector is empty or not
    cout << "\nChecking to see if intVector1 is empty?\n";
    if (intVector1.size() == 0)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    //pushing elements into string vector
    stringVector.push_back("one");
    stringVector.push_back("two");
    stringVector.push_back("three");
    stringVector.push_back("four");
    stringVector.push_back("five");
    stringVector.push_back("six");
    stringVector.push_back("seven");
    cout << "Size : " << intVector1.size();
    cout << "\nCapacity : " << intVector1.capacity();
    //print vector3 elements
    cout << "\nVector3 elements are: ";
    for (auto it = stringVector.begin(); it != stringVector.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "\nVector3 Size : " << stringVector.size();
    cout << "\nVector3 Capacity : " << stringVector.capacity();
    cout << endl;

    cout << "\nAdding two more element on Vector3, to check if the capacity gets doubled..\n";
    stringVector.push_back("eight");
    stringVector.push_back("nine");
    cout << "\nVector3 Size : " << stringVector.size();
    cout << "\nVector3 Capacity : " << stringVector.capacity();
    cout << "\nVector3 elements are: ";
    for (auto it = stringVector.begin(); it != stringVector.end(); it++)
        cout << *it << " ";
    cout << endl;

}
