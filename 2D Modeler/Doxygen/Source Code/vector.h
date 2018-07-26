// Vector.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef VECTOR_H
#define VECTOR_H

#include <exception>	//std::exceptio
#include <algorithm> 	// std::swap
#include <stdexcept>	// std::out_of_range

//! name spae myShapes.
namespace myShapes
{

//! The Vector class.
/*!
* a vector which approximates the stl vector ... text ...
*/
template<typename T> 	/*!< This an example of a templated class */
class vector
{
	const int INIT_SIZE = 8;
	int size_v; 		/*!< the size */
    T* elem; 	/*!< a pointer to the elements, this is an example of the pointer the copy constructor is overloaded on line 41 */
    int space; 	/*!< size+free_space */

public:
	/*!
	* default vector constructor
	*/
	vector()
	: size_v{ 0 }, space{ 0 }
	{
		elem = new T[INIT_SIZE];
		if (nullptr != elem)
		{
			space = INIT_SIZE;
        }
	}

	/*!
	*  alternate constructor
	*/
    explicit vector(int s)
	:size_v{ 0 }, space{ 0 }
	{
		elem = new T[s];
		if (nullptr != elem)
		{
			space = s;
		}
	}

	/*!
	*  copy constructor
	*/
    vector(const vector& otherV)
	{
		try
		{
			copyFrom(otherV);
		}
        catch (const std::exception&) /*!< Exmaple of an exception handler */
		{
			//! catch unlikely error if unable to allocate memory to elem
		}
	}

	/*!
	* copy assignment, first example of operator overloading
	*/
    vector<T>& operator=(const vector& otherV)
	{
        if (this != &otherV)
		{
			cleanUp();
			copyFrom(otherV);
		}

		return *this;
	}

	/*!
	* move constructor
	*/
    vector(const vector&& otherV)
	:size_v{ 0 }, space{ 0 }, elem{ nullptr }
	{
		size_v = otherV.size_v;
		space = otherV.space;
		elem = otherV.elem;

		otherV.cleanUp();
	}

	/*!
	* move assignment
	*/
    vector<T>& operator=(const vector&& otherV)
	{
		if (this != otherV)
		{
			size_v = otherV.size_v;
			space = otherV.space;
			elem = otherV.elem;

			otherV.cleanUp();
		}

		return *this;
	}

	/*!
	* destructor
	*/
    ~vector()
	{
		cleanUp();
	}

    T& operator[] (int n) // access: return reference, second example of operator overloading
	{
		return *(elem + n); //Return a reference to the nth element
	}

	const T& operator[] (int n) const // access: return reference
	{
		//Verify n is in the range of the array
		if (0 > n || !(n < size_v))
			throw new std::out_of_range{ "invalid index" };

		return *(elem + n); //Return a reference to the nth element
	}

	int size() const // the current size
	{
		return size_v;
	}

	int capacity() const // current available space
	{
		return space;
	}

	void resize(int newsize) // grow
	{
		//Call reserve if more space is required
		if (space < newsize)
			return reserve(newsize);

		//Make a smaller array
		T* tempElem = new T[newsize];
		if (nullptr == tempElem)
			throw new std::bad_alloc{};

		//Copy the pointers to the new array
		for (int index = 0; index < newsize; index++)
			*(tempElem + index) = *(elem + index);

		delete[] elem;

		//Switch elem to the new array and delete the old array
		elem = tempElem;

		//Set space to the new size allocation and adjust size_v if necessary
		space = newsize;
		if (size_v > space)
			size_v = space;
	}

    void push_back(T t) // add element
	{
		//Verify there is enough room to add to the end, grow if reqiured
		if (size_v == space)
			resize(space * 2);

		//Push the item onto the array and increment size_v
		elem[size_v++] = t;
	}

	void reserve(int newalloc) // get more space
	{
		if (space >= newalloc)
            return;//reserve is not allowed to shrink the vector

				   //Make a larger array
		T* tempElem = new T[newalloc];
		if (nullptr == tempElem)
			throw new std::bad_alloc{};

		//Copy the pointers from the old array
		for (int index = 0; index < size_v; index++)
			tempElem[index] = elem[index];

		delete[] elem;

		//Switch elem to the new array and delete the old array
		elem = tempElem;

		//Adjust space to new allocation (Note: size_v does not change when adding space).
		space = newalloc;
	}

	using iterator = T;
    using const_iterator = const T*;

    iterator* begin() // points to first element
	{
		return elem; //Return a pointer to the start of the array
	}

	const_iterator begin() const
	{
		return elem; //Return a pointer to the start of the array
	}

	iterator* end() // points to one beyond the last element
	{
		return (elem + size_v); //Return a pointer to the end of the array + 1
	}

	const_iterator end() const
	{
		return (elem + size_v); //Return a pointer to the end of the array + 1
	}

	iterator* insert(iterator* p, const T& v)// insert a new element v before p
	{
		//Increase space if needed
		T* elemOrg = elem; //Preserve original address of elem incase we resize
		if (space <= size_v)
			reserve(space * 2);

		p += elem - elemOrg;//Update iterator location if there was a resize

							//Shift pointers right of p over one to the right
		for (T* index = end() - 1; index >= p; index--)
			*(index + 1) = *index;

		//Add new item at location p
		*p = v;

		//Increment size
		size_v++;

		return p; //Return pointer to the inserted item
	}

	iterator* erase(iterator* p) // remove element pointed to by p
	{
		//Shift pointers right of p over one to the left
		for (T* index = p; index < end() - 1; index++)
			*index = *(index + 1);

		//Decrement size
		size_v--;

		return nullptr;
	}


private:
    void copyFrom(const vector& otherV)//Helper function to support copy constructors and assignment operators
	{
		elem = new T[otherV.space];
		if (nullptr == elem)
			throw new std::bad_alloc{};

		space = otherV.space;
		for (int index = 0; index < otherV.size_v; index++)
			push_back(otherV.elem[index]);
	}

	void cleanUp() //Helper function to support in the destruction of the elem array
	{
		delete[] elem;

		elem = nullptr;
		size_v = 0;
		space = 0;
	}

};
//! end name spae myShapes.
}

#endif //!VECTOR_H
