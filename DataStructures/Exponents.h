#pragma once
#include <cstdio>

class Exponents {
private:
	int two[10] = { 1 };	//크기가 10인 배열
	int number = 2;
public:
	Exponents() {};	//기본생성자
	~Exponents() {};
	
	void storeNumber() {
		for (int i = 1; i < 10; i++) { two[i] = two[i - 1] * 2; }
	}
	void printNumber() {		//배열 전체 요소의 값을 출력하는 함수
		for (int i = 0; i < 10; i++) { printf("%d ", two[i]); }
	}
};