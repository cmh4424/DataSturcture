#pragma once

#include <iostream>
#define MAX_STACK_SIZE 20

inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
}

class ArrayStack {
private:
	int data[MAX_STACK_SIZE] = { 0 };
	int top;

public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}

	void push(int val) {
		if (!isFull())	{ data[++top] = val; }
		else			{ std::cout<<"OVERFLOW"; }
	}

	int pop() {
		if (!isEmpty()) { return data[top--]; }
		else			{ std::cout << "UNDERFLOW"; }
	}

	int peek() {
		if (!isEmpty()) { return data[top]; }
		else			{ std::cout << "UNDERFLOW"; }
	}

	void display()
	{
		std::cout << "스택 항목의 수: " << top + 1 << std::endl;
		for (auto i : data) { std::cout << '<' << i << '>'; }
	}

	bool isEmpty() { return top == -1 ? true : false; }
	bool isFull() { return top == MAX_STACK_SIZE - 1 ? true : false; }

};