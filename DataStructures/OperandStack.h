#include <cstdio>
#include <cstdlib>

#define MAX_STACK_SIZE 100

inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
}

class OperandStack {
private:
	double data[MAX_STACK_SIZE];
	int top;
public:
	OperandStack() { top = -1; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	void push(double e) {
		if (isFull()) error("스택 포화 에러");
		data[++top] = e;
	}
	double pop() {
		if (isEmpty())error("스택 공백 에러");
		return data[top--];
	}
};