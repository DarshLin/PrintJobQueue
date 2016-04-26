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
  v2 result: Got too complicated, going to simplify to one variable for data
  before juggling four pieces of data
*/

using namespace std;

#include "Queue.h"

//Constructor Definition
Queue::Queue()
  : tail(0)
{}

//Copy Constructor Definition
Queue::Queue(const Queue &original) {
  cout << "This is the copy Constructor" << endl;
  if (empty()) {
	cerr << "Empty, nothing to copy." << endl;
  }
  // else {
  // 	head = 0;
  // 	head = new Queue::Node(original.Front(), head);
  // 	cout << "Head pointer: " <<head->data << endl;
  // 	Queue::NodePointer starter = original.head->next;
  // 	cout << "Starter: " << starter->data << endl;
  // }

	
}//End of copy constructor

//Queue Destructor
Queue::~Queue() {
  cout << "This is the destructor" << endl;
}//End of Destructor

//Overloaded Assignment Operator
Queue & Queue::operator= (const Queue & original) {
  cout<< "This is the overloaded assignment operator" << endl;;

  *this = original;

  return *this;

}//End of Overloaded Assignment Operator

//Empty check function
bool Queue::empty() const {
  return (tail == 0);
}

//Enqueue function
void Queue::Enqueue(const QElement & data) {
  cout << "This is the Enqueue function" << endl;

  Queue::Node * temp;
  
  if(empty()) {
	tail = new Queue::Node(data,tail);
	temp = new Queue::Node(tail->data, tail);
  }
  else{
	tail->next = new Queue::Node(data, tail->next);
	tail = tail->next;
	tail->next = tail->next;
  }
  if(tail->next == 0){
	tail->next = temp;
	tail = tail->next;
	tail->next = tail->next->next;
  }
  //cout << "Tail: " << tail->data << endl;
  //cout << "Tail->next: " << tail->next->data << endl;
  cout << "tail: " << tail->data << endl;
  
}//End of Enqueue

//Dequeue function
void Queue::Dequeue() {
  if(empty()){
	cerr << "Queue is empty, nothing to delete!" << endl;
  }
  else {
	
	Queue::NodePointer ptr;
	ptr = tail->next;
	tail->next = tail->next->next;
	cout << "The Pointer in deq: " <<ptr->data << endl;
	delete ptr;
  }
}//End of Dequeue

//Print Queue function
void Queue::printQ(ostream & out) const {
  cout << "This is the printQ function" << endl;

  Queue::NodePointer ptr;

  for(ptr = tail; ptr != 0; ptr = ptr->next)
	out<<ptr->data<<endl;

  
}//End of printQ
QElement Queue::Rear() const {
  if(!empty())
	return(tail->data);

  else {
	cerr << "********Queue is empty*******";

	return*(new QElement);
  }
}
