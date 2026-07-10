// Name: Mohammed Asad Abdullah
// Student Number: 200493004
// Date: 28/03/25

// Filename: LinkedList.cpp

// Note: This implementation of LinkedList is based on
// Chapter 4 of Bruno R. Preiss's Textbook:
// "Data Structures and Algorithms with Object-Oriented Design Patterns in C++"

#include "LinkedList.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

//---------------------------------------------------
//List Element Members
//---------------------------------------------------
ListElement::ListElement(int _datum, ListElement *_next) : datum(_datum), next(_next)
{
}

int ListElement::getDatum() const
{
  return datum;
}

ListElement const *ListElement::getNext() const
{
  return next;
}

//---------------------------------------------------
//LinkedList Members
//---------------------------------------------------
LinkedList::LinkedList() : head(0)
{
}

void LinkedList::insertItem(int item)
{
  ListElement *currPtr = head;
  ListElement *prevPtr = NULL;
  ListElement *newNodePtr;

  while (currPtr != NULL && item > currPtr->datum)
  {
    prevPtr = currPtr;
    currPtr = currPtr->next;
  }

  newNodePtr = new ListElement(item, currPtr);

  if (prevPtr == NULL)
    head = newNodePtr;
  else
    prevPtr->next = newNodePtr;
}

void LinkedList::makeList()
{
  int number;
  ListElement *currPtr;
  ListElement *newNodePtr;

  cout << "Enter values for a linked list, one per line." << endl;
  cout << "Enter 999 to end the list." << endl;

  cin >> number;
  newNodePtr = new ListElement(number, NULL);
  head = newNodePtr;
  currPtr = head;
  cin >> number;

  while (number != 999)
  {
    newNodePtr = new ListElement(number, NULL);
    currPtr->next = newNodePtr;
    currPtr = newNodePtr;
    cin >> number;
  }
}

void LinkedList::appendItem(int item)
{
  ListElement *currPtr = head;
  
  if (currPtr == NULL)
  {
    head = new ListElement(item, NULL);
    return;
  }

  while (currPtr->next != NULL)
  {
    currPtr = currPtr->next;
  }

  currPtr->next = new ListElement(item, NULL);
}

void LinkedList::deleteItem(int item)
{
  if (head == NULL)
  {
    cout << "List is empty." << endl;
    return;
  }

  if (head->datum == item)
  {
    ListElement *deletePtr = head;
    head = head->next;
    delete deletePtr;
    return;
  }

  ListElement *prevPtr = head;
  while (prevPtr->next != NULL && prevPtr->next->datum != item)
  {
    prevPtr = prevPtr->next;
  }

  if (prevPtr->next == NULL)
  {
    cout << "Item not found." << endl;
    return;
  }

  ListElement *deletePtr = prevPtr->next;
  prevPtr->next = deletePtr->next;
  delete deletePtr;
}

void LinkedList::printList()
{
  ListElement *currPtr = head;
  while (currPtr != NULL)
  {
    cout << currPtr->datum << " ";
    currPtr = currPtr->next;
  }
  cout << endl;
}
