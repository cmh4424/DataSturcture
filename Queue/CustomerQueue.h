#pragma once
#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 100
inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
}

struct Customer {
	int id;
	int tArrival;
	int tService;
	Customer(int i = 0, int tArr = 0, int tServ = 0)
		:id(i), tArrival(tArr), tService(tServ) {}
};

class CustomerQueue {
protected:
	int front;
	int rear;
	Customer data[MAX_QUEUE_SIZE];
public:
	CustomerQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
	void enqueue(Customer val) {
		if (isFull())error("error:ť�� ��ȭ�����Դϴ�.\n");
		else { rear = (rear + 1) % MAX_QUEUE_SIZE; data[rear] = val; }
	}
	Customer dequeue() {
		if (isEmpty())error("error:ť�� ��������Դϴ�.\n");
		else { front = (front + 1) % MAX_QUEUE_SIZE; return data[front]; }
	}
	Customer peek() {
		if (isEmpty())error("error:ť�� ��������Դϴ�.\n");
		else return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	void display() {
		printf("ť ����: ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++)
			//printf("[%2d]", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};