#ifndef __PRIORITYQUEUEADT_H
#define __PRIORITYQUEUEADT_H

using namespace std;

class PriorityQueueADT{
	public:
		virtual bool empty() = 0;
		virtual int size() = 0;
		virtual int top() = 0;
		virtual void push(int) = 0;
		virtual void solucion() = 0;
};

#endif
