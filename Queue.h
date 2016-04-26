//Darsh Lin
//April 20, 2016
//Cspc 2430
//Version 1

/* There will only be one version of this which I will tweak around
   depending on the error messages I get on compile and I will also use
   Stack.h from lab 3 as a model for this.
*/

#include <iostream>
#include <string>
using namespace std;

#ifndef QUEUE
#define QUEUE

typedef int QElement;

class Queue
{
 public:

  Queue();

  Queue(const Queue & original);
  /*
	Copy Constructor
	 Precondition: original is the queue to be copied and is received as
	 a const reference parameter. Rear is set to front;
	 Postcondition: A copy of the original has been constructed.
  */

  ~Queue();
  /*
	Destructor
	 Precondition: Rear pointer is set to front;
	 Postcondition: The linked list in the queue has been deallocated
  */

  Queue & operator = (const Queue & original);
  /*
	Assignment Operator
	Precondition: original is the queue to be assigned and is received as a
	const reference parameter.
	Postcondition: The current queue becomes a copy of original and a
	reference to it is returned.
  */

  bool empty() const;
  /*
	empty function checks if Queue is empty.
	Precondition: put the rear pointer to the same position as the front
	pointer.
	Postcondition: Returns true if queue is empty and false otherwise.
  */

  void Enqueue(const QElement & data);
  /*
	Enqueue function adds a value to the queue.
	Precondition: the four values are added to the queue
	Postcondition: values are added to the rear of the queue while the rear
	node moves back into the next node. The node should be pointed to the front
	if nothing else is there.
  */

  void printQ(ostream & out) const;
  /*
	printQ displays the values in the queue.
	Precondition: ostream out is open. Rear pointer is set to front.
	Postcondition: Queue's contents, from front to rear, have been output to
	out. Every string has to be printed too.
  */

  QElement Front() const;
  /*
	Front function retrieves the value at the front of the queue provided it
	isn't empty.
	Precondition: Queue is not empty.
	Postcondition: Value at the front of the queue is returned, unless the
	queue is empty. In case of empty, an error message is displayed along with
	a garbage value being returned. Might change the name if this becomes too
	confusing
  */
  QElement Rear() const;
  /*
	Rear function retrieves the value at the rear of the queue provided it
	isn't empty.
	Precondition: Queue is not empty.
	Postcondition: Value at the rear of the queue is returned, unless the
	queue is empty. In case of empty, an error message is displayed along with
	a garbage value being returned. Might change name for less confusion.
  */
  void Dequeue();
  /*
	The Dequeue function is used to remove the value at the front of the queue
	provided that it's not empty.
	Precondition: Queue is not empty.
	Postcondition: Front value has been removed, unless the queue is empty.
	If empty, display an error message.
  */

 private:
  //Node Class
  class Node
  {
  public:
	QElement data; //filename, userID,printTime;
	//QElement printJob[4]{jobID, filename, userID, printTime};
	Node * next;

	Node(QElement value, Node* link) // not sure on the 0 here, might come back to this
	  /*
		Precondition: the four values are received
		Postcondition: A Node is constructed with the values in its
		four data parts and it's next part is set to link which is
		defaulted to 0
	  */
	  {
		data = value;
		next = link;
		//filename = printJobVal[1];
		//userID = printJobVal[2];
		//printTime = printJobVal[3];
	  }
  };

  typedef Node * NodePointer; /* this is to make node pointers without having
								 to use the confusing asterisks */
  //Data members
  NodePointer tail;
};//End of Queue class declaration

#endif
