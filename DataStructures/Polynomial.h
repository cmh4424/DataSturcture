#include <cstdio>
#define MAX_DEGREE 80

class Polynomial {
private:
	int degree;				//�ְ� ������ �����ϴ� ����
	float coef[MAX_DEGREE];	//�� �׿� ���� ���
public:
	Polynomial() { degree = 0; }
	~Polynomial() {}
	
	bool isZero(){return degree == 0;	}	//�ְ������� 0������ �˻��Ͽ� 0�̸� true�� ��ȯ�Ѵ�.
	void negate()
	{
		for (int i = 0; i < degree; i++)
			coef[i] = -coef[i];
	}
	//���׽� a�� b�� ���ϴ� �Լ�, a�� b�� ���� �ڽ��� ���׽� ����
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
	//���׽��� ������ �Է¹޴� ����Լ�
	void read() 
	{
		printf("���׽��� �ְ� ������ �Է��Ͻÿ�: ");
		scanf_s("%d", &degree);
		printf("�� ���� ����� �Է��Ͻÿ�(�� %d��): ", degree + 1);
		for (int i = 0; i <= degree; i++)
			scanf_s("%f", coef + i);
	}
	//���׽��� ������ ȭ�鿡 ����ϴ� �Լ�
	void display(const char* str = "Poly = ") {
		printf("\t%s", str);
		for (int i = 0; i < degree; i++)
			printf("%5.1f x^%d + ", coef[i], degree - i);
		printf("%4.1f\n", coef[degree]);
	}
};