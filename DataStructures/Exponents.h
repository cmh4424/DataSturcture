#pragma once
#include <cstdio>

class Exponents {
private:
	int two[10] = { 1 };	//ũ�Ⱑ 10�� �迭
	int number = 2;
public:
	Exponents() {};	//�⺻������
	~Exponents() {};
	
	void storeNumber() {
		for (int i = 1; i < 10; i++) { two[i] = two[i - 1] * 2; }
	}
	void printNumber() {		//�迭 ��ü ����� ���� ����ϴ� �Լ�
		for (int i = 0; i < 10; i++) { printf("%d ", two[i]); }
	}
};