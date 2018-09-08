#include "PriorityQueueADT.h"


using namespace std;

class PQHeap: public PriorityQueueADT{
	private:
		int *a;
		int count;
		int index;
		int num;
	public:
		PQHeap();
		~PQHeap();
		bool empty();
		int size();
		int top();
		void push(int);
		void solucion();

};
