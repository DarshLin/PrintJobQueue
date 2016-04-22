/*
  Darsh Lin
  April 20, 2016
  CSPC 2430
  Version 2

  Version 1:This version is going to be very similar to the Stack.cpp
  from lab3, the same goes for the header file as it is a good basis to
  test and see where things can be changed to look like a Queue.
  Version 2: This is where most modifications will come in and I will
  attempt to make the queue go from front to back and loop around again.
*/

using namespace std;

#include "Queue.h"

//Constructor Definition
Queue::Queue()
  : front(0), rear(0)
{}

//Copy Constructor Definition
Queue::Queue(const Queue &original) {
  cout << "This is the copy Constructor" << endl;
  front = 0;
  rear = 0;
  if(!original.empty()) { //not sure if the two initialized as 0
	front = new Queue::Node(original.Front()->jobID,
							original.Front()->filename,
							original.Front()->userID,
							original.Front()->printTime);
	//rear = new Queue::Node(original.Rear());

	cout << front << endl;
	cout << rear << endl;
	
	
  }//End of the if for processing
  	else {
  	  cerr << "Cannot copy an empty Queue" << endl;
  	}//End of empty check
}//End of copy constructor

//Queue Destructor
Queue::~Queue() {
  cout << "This is the destructor" << endl; 
  // Queue::Node rearPtr;
  // Queue::Node nextPtr;
  // Queue::Node frontPtr;
  // rearPtr = rear;
  // nextPtr = rear->next;
  // frontPtr = front;

  // while(rearPtr != frontPtr) {
  // 	rearPtr = nextPtr;
  // }//End of movement to front
  // frontPtr = 0;
  // delete frontPtr;

  // while(rearPtr != 0) {
  // 	delete rearPtr;
  // 	rearPtr = nextPtr;
  // }//End of while loop to delete
  // delete nextPtr; //might as well
}//End of Destructor

//Overloaded Assignment Operator
Queue & Queue::operator= (const Queue & original) {
  cout<< "This is the overloaded assignment operator" << endl;
  // front = 0;
  // rear = 0;

  // if(original.empty()) { return * this;}

  // if(this != &original) {
  // 	this.~Queue();
  // 	front = original.Front();
  // 	rear = original.Rear();
  // 	this->front = front;
  // 	this->rear = rear;
  // 	tRear = this->rear;

  // 	Queue::NodePointer originalPtr = rear;
  // 	Queue::NodePointer nextPtr = rear->next;

  // 	while(tRear != this->front) {
  // 	  tRear = nextPtr;
  // 	}//End of moving ot front
  // 	while(tRear != rear) {
  // 	  tRear->next = new Queue::Node(originalPtr->jobID,
  // 									originalPtr->filename,
  // 									originalPtr->userID,
  // 									originalPtr->printTime);
  // 	  tRear = nextPtr;
  // 	  originalPtr = originalPtr-next;
  // 	}//End of copy loop
  return *this;
  // }//End of first node copy and conditional to assignment op
}//End of Overloaded Assignment Operator

//Empty check function
bool Queue::empty() const {
  cout << "This is the empty function" << endl;
  return (front == 0);
}

//Enqueue function
void Queue::Enqueue(const QElement & jobID,
					const QElement & filename,
					const QElement & userID,
					const QElement & printTime) {
  cout << "This is the Enqueue function" << endl;
  if(empty()) {
	front = new Queue::Node(jobID, filename, userID, printTime, front);
	rear = front;
  }//End of checking to see if empty
  else {//If not empty
	rear = new Queue::Node(jobID, filename, userID, printTime, rear);
	//if (rear->next == NULL)
	  rear->next = front; //This is to loop to the front, not sure if I should change it
  }//End of enqueue on non empty
}//End of Enqueue

//Dequeue function
void Queue::Dequeue() {
  cout << "This is the Dequeue function" << endl;
  if(!empty()) {
	Queue::NodePointer fPtr = front;
	front = front->next;
	delete fPtr;
  }//End of non empty dequeue
  else {//empty
	cerr << "Cannot delete nothing" << endl;
  }//End of else (empty)
}//End of Dequeue

//Print Queue function
void Queue::printQ(ostream & out) const {
  cout << "This is the printQ function" << endl;
  Queue::NodePointer rearPtr;
  Queue::NodePointer nextPtr;
  Queue::NodePointer frontPtr;
  rearPtr = rear;
  nextPtr = rear->next;
  frontPtr = front;

  while(rearPtr != frontPtr) {
	rearPtr = nextPtr;
  }//End of moving to front

  NodePointer ptr;

  for (ptr = rearPtr; ptr != rear; ptr = ptr->next) {
	out << ptr->jobID << " | " << ptr->filename <<
	  " | " << ptr->userID << " | " << ptr->printTime << endl;
  }//End of for loop to move everything to out
  
}//End of printQ

//Front element
QElement Queue::Front() const {
  cout <<"This is the Front function" << endl;
  if(!empty()) {
	return (front->jobID);
  }
  else {
	cerr << "Queue is Empty, returning garbage!" << endl;
	  return *(new QElement);
  } 
}//End of Front()

//Rear element
QElement Queue::Rear() const {
  cout << "This is the Rear function" << endl;
  if(!empty()) { return (rear->printTime); }
  else {
	cerr << "Queue is Empty, returning garbage!" << endl;
	  return * (new QElement);
  }//End of rear on empty
}//End of Rear()
