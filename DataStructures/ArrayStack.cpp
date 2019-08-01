#include "ArrayStack.h"

int main() {
	ArrayStack A;
	A.push(0); A.push(1); A.push(2);
	std::cout << A.isEmpty()<<std::endl;
	std::cout << A.isFull() << std::endl;
	A.display();
}
