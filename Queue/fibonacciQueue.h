#include <queue>
#include <iostream>
using namespace std;

int fibonacciQueue(int val) {
	queue<int> fibQueue;
	int a = 1;
	fibQueue.push(0);
	fibQueue.push(1);
	for(int i = 2; i<=val;i++){
		a = fibQueue.front() + fibQueue.back();
		fibQueue.pop();
		fibQueue.push(a);
	}
	return a;
}