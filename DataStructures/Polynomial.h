#include <cstdio>
#define MAX_DEGREE 80

class Polynomial {
private:
	int degree;				//최고 차수를 저장하는 변수
	float coef[MAX_DEGREE];	//각 항에 대한 계수
public:
	Polynomial() { degree = 0; }
	~Polynomial() {}
	
	bool isZero(){return degree == 0;	}	//최고차수가 0인지를 검사하여 0이면 true를 반환한다.
	void negate()
	{
		for (int i = 0; i < degree; i++)
			coef[i] = -coef[i];
	}
	//다항식 a와 b를 더하는 함수, a와 b를 더해 자신의 다항식 설정
	void add(Polynomial a, Polynomial b)
	{
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}
	void mult(Polynomial p1,Polynomial p2);
	//다항식의 내용을 입력받는 멤버함수
	void read() 
	{
		printf("다항식의 최고 차수를 입력하시오: ");
		scanf_s("%d", &degree);
		printf("각 항의 계수를 입력하시오(총 %d개): ", degree + 1);
		for (int i = 0; i <= degree; i++)
			scanf_s("%f", coef + i);
	}
	//다항식의 내용을 화면에 출력하는 함수
	void display(const char* str = "Poly = ") {
		printf("\t%s", str);
		for (int i = 0; i < degree; i++)
			printf("%5.1f x^%d + ", coef[i], degree - i);
		printf("%4.1f\n", coef[degree]);
	}
};