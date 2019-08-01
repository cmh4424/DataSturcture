#include <cstdio>
#include <cstring>

class Car {
protected:
	int speed = 0;
	char name[40] = "hello";
public:
	int gear;
	Car() {};	//�⺻ ������
	~Car() {};	//�Ҹ���
	Car(int s, char* n, int g)	//�Ű������� �ִ� ������
		:speed(s), gear(g) {
		strcpy_s(name, n);
	}
	void changeGear(int g = 4) {	//��� �ܼ��� �����ϴ� ��� �Լ�
		gear = g;
	}

	void speedUp() {
		speed += 5;
	}

	void display() {
		printf("[%s] : ���=%d�� �ӵ�=%dkmph\n", name, gear, speed);
	}
	void whereAmI() { printf("��ü �ּ� = %x\n", this); }
};