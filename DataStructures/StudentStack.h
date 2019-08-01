#include "Student.h"
const int MAX_STACK_SIZE = 100;

inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
}

class StudentStack {
	int top;
	Student data[MAX_STACK_SIZE];
public:
	StudentStack() { top = -1; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(Student e) {
		if (isFull()) error("���� ��ȭ ����");
		else data[++top] = e;
	}

	Student pop() {
		if (isEmpty()) error("���� ���� ����");
		return data[top--];
	}

	Student peek() {
		if (isEmpty()) error("���� ���� ����");
		return data[top];
	}

	void display() {
		printf("[��ü �л��� �� = %2d]\n", top + 1);
		for (auto i : data) i.display();
		printf("\n");
	}
};
