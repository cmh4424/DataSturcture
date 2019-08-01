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
		if (isFull()) error("스택 포화 에러");
		else data[++top] = e;
	}

	Student pop() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}

	Student peek() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top];
	}

	void display() {
		printf("[전체 학생의 수 = %2d]\n", top + 1);
		for (auto i : data) i.display();
		printf("\n");
	}
};
