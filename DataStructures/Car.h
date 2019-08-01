#include <cstdio>
#include <cstring>

class Car {
protected:
	int speed = 0;
	char name[40] = "hello";
public:
	int gear;
	Car() {};	//기본 생성자
	~Car() {};	//소멸자
	Car(int s, char* n, int g)	//매개변수가 있는 생성자
		:speed(s), gear(g) {
		strcpy_s(name, n);
	}
	void changeGear(int g = 4) {	//기어 단수를 변경하는 멤버 함수
		gear = g;
	}

	void speedUp() {
		speed += 5;
	}

	void display() {
		printf("[%s] : 기어=%d단 속도=%dkmph\n", name, gear, speed);
	}
	void whereAmI() { printf("객체 주소 = %x\n", this); }
};