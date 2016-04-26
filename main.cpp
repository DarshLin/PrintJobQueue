/* Darsh Lin
   April 22, 2016
   CSPC 2430
   Version 1

   Version 1: The initial testing for this will be lifted right out from
   the lab3 main.cpp since that has all the testing needed, save for a
   few variations and maybe one or two more function tests, other than that,
   very similar.
   Version 2: In version 2, I will rewrite the entire main.cpp for this
   assignment to fit the needs for the printer queue after I know everything
   works.
*/




#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

void print(Queue q) {
  q.printQ(cout);
}

int main() {
  Queue q;
  cout << "Queue Created. Empty? " << boolalpha << q.empty() << endl;
  cout << "How many elements to add to the queue? ";
  int numItems;
  cin >> numItems;
  for(int i = 1; i <= numItems; i++){
	q.Enqueue(i);
  }
  

  cout <<"Let's do a dequeue" <<endl;
  for (int j = 0; j < numItems - 2;j++) {
	q.Dequeue();
  }
  cout <<"What is the tail? " << endl;
  cout <<q.Rear() << endl;
  
  return 0;
}
