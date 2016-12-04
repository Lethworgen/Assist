//Hash Table with buckets

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>
#include "SinglyLinkedList.h"

using namespace std;

template<class Type>
class HashTable
{
private:
	const static int buckets;
	static int tableSize;
	Type ***table; // The Table
	SinglyLinkedList<Type> *overflow; // Overflow area

public:
	
	//Constructor
	HashTable()
	{
		setTable();
	}

	//Destructor
	~HashTable()
	{
		clearTable();
	}

	//Hash Operations
	bool insert(const Type&);//Insert
	bool remove(const Type&);//Remove
	Type* search(const Type&) const; //Searches with the Hash Table.

	//Other actions
	const double getLoadFactor() const
	{
		return (double)getFilled() / (double)tableSize;
	}

	const int getBuckets() const;
	const int getFilled() const;
	const int getEmpty() const;
	const int getOverflowfilled() const;

	void setTable();
	void clearTable();
	void destroyTable(Type***&, SinglyLinkedList<Type>*&);

private:
	const int hash(const Type&) const; //Hash Function

};

//Static const int for Buckets. Set to 3.
template<class Type>
const int HashTable<Type>::buckets = 3;

//Static const int for Hash Table
template<class Type>
int HashTable<Type>::tableSize = 91; //Test const

/*
Sets the Table
-Double array of pointers
-Initializes all nodes to nullptr
-Dynamically allocates the overflow
*/
template<class Type>
void HashTable<Type>::setTable()
{
	table = new Type**[tableSize]; //Set the table here

	for (int i = 0; i < tableSize; i++)
	{
		table[i] = new Type*[buckets]; //Allocating buckets
		for (int j = 0; j < buckets; j++)
		{
			table[i][j] = nullptr;
		}
	}

	overflow = new SinglyLinkedList<Type>; // Allocates the overflow for collision resolution
}

/*
Clears table and overflow
-Table goes back to one pointer to pointer to pointer
-Overflow goes back to one pointer
*/
template<class Type>
void HashTable<Type>::clearTable()
{
	if (!table) //If there is no table.
		return;

	for (int i = 0; i < tableSize && table[i]; i++)
	{
		for (int j = 0; j < buckets && table[i][j]; j++)
		{
			delete table[i][j];
			table[i][j] = nullptr;
		}
		delete table[i];
		table[i] = nullptr;
	}

	delete table; //Empties the garbage of the table
	table = nullptr;//Sets it to nullptr
	delete overflow;//Emptys garbage of overflow list
	overflow = nullptr; //Sets the overflow to nullptr
	
}

/*
Hashing function. 
-What this will do is cube the value and modules it by tableSize for a unique value.
*/

template<class Type>
const int HashTable<Type>::hash(const Type& val) const
{
	return (val*(val*val) % tableSize);
}

/*
Searches table for a value
-Returns pointer to value if found
-Returns nullptr otherwise
*/
template<class Type>
Type* HashTable<Type>::search(const Type& val) const
{
	//Searches the Hash Table and the overflow area
	//If value is fuond use &

	const int x = hash(val);

	for (int y = 0; y < buckets; y++)
	{
		if (table[x][y] && *table[x][y] == val)
		{
			return table[x][y];
		}
	}

	if (overflow->findNode(val))
		return overflow->findNode(val);

	return nullptr;
}

/*
Inserts the value into the table
-If designated colum is filled, it goes to the overflow.
*/

template<class Type>
bool HashTable<Type>::insert(const Type& val)
{
	if (search(val))
		return false;

	const int x = hash(val); // Hashes the value

	for (int y = 0; y < buckets; y++) {
		if (!table[x][y]) { //If the value is not at this location
			Type* newNode = new Type; //Allocate a new Node
			*newNode = val; //MThe new node will contain that value
			table[x][y] = newNode; //That node will be added to the hash table
			return true;
		}
	}

	overflow->addfirst(val); //If there are collisions, add it to the overflow list.
	return true;
}

/*
Attempts to remove a value from the table
-Goes to overflow if not found
-Returns true if value is deleted
-Otherwise, it will return false
*/

template<class Type>
bool HashTable <Type>::remove(const Type& val)
{
	//Find the value, and then remove it.

	const int x = hash(val); // Hashes the value
	for (int y = 0; y < buckets; y++) //Traversing the table (columns)
	{
		if (table[x][y] && *table[x][y] == val) //If the object is found
		{
			table[x][y] = nullptr; // Set it to nullptr

			for (int i = y; i < buckets - 1; i++)
			{
				table[x][i] = table[x][i + 1];
				table[x][i + 1] = nullptr;
			}

			return true; //Item is deleted
		}
	}
}


/*
Gets the amount of filled table nodes
*/

template<class Type>
const int HashTable<Type>::getFilled() const
{
	int filled = 0;
	for (int i = 0; i < tableSize; i++)
	{
		if (table[i][0])
		{
			filled++;
		}
	}
	return filled;
}

/*
Gets amount of empty table nodes
*/

template<class Type>
const int HashTable<Type>::getEmpty() const
{
	int empty = 0;
	for (int i = 0; i < tableSize; i++)
	{
		if (!table[i][0])
		{
			empty++
		}
	}
	return empty;
}

/*
Gets number of values in the overflow (collissions)
*/
template<class Type>
const int HashTable<Type>::getOverflowfilled() const
{
	return overflow->getNumberOfNodes();
}
#endif
