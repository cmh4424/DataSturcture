
#include "../Common/CommonSettings.h"

class CircularQueue {
private:
	int front;
	int rear;
	int data[MAX_SIZE];
public:
	CircularQueue() {}
	~CircularQueue() {}

	void enqueue(int item);

	int dequeue();

	int peek();

	bool isEmpty();

	bool isFull();

	void display();
};