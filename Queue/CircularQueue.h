#pragma once
#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 100
inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
}
class CircularQueue {
protected:
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE] = { 0 };
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
	void enqueue(int val) {
		if (isFull())error("error:ť�� ��ȭ�����Դϴ�.\n");
		else { rear = (rear + 1) % MAX_QUEUE_SIZE; data[rear] = val; }
	}
	int dequeue() {
		if (isEmpty())error("error:ť�� ��������Դϴ�.\n");
		else { front = (front + 1) % MAX_QUEUE_SIZE; return data[front]; }
	}
	int peek() {
		if (isEmpty())error("error:ť�� ��������Դϴ�.\n");
		else return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	void display() {
		printf("ť ����: ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++)
			printf("[%2d]", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};