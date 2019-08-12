#include <queue>
#include <string>
#include <iostream>
using namespace std;

struct Customer {
	string name;
	char gend;
};

class meetingSupport {
private:
	Customer people;
	queue<Customer> queMale;
	queue<Customer> queFemale;
public:
	meetingSupport() {}
	//meetingSupport(string n, char g) { people.name = n; people.gend = g; }

	void get(){
		people.name = " "; people.gend = ' ';
		cout << "�����̸�:";
		cin >> people.name;
		cout << "������ �Է��ϼ���(f or m)";
		while (people.gend != 'm' && people.gend != 'f') cin >> people.gend;
	}

	void set() {
		cout << "����� �̸� :" << people.name << endl << "����� ����: " << people.gend << endl;	//�Է� Ȯ�ο�
		if (people.gend == 'm') queMale.push(people);
		else queFemale.push(people);
	}

	void isMatched() {
		if (!queMale.empty() && !queFemale.empty()) {			//�� ���ÿ� �ּ� 1���̻� ������ �Ѵ� �� �ϰ� "����Ǿ����ϴ�"
			cout << "Ŀ���� ź���߽��ϴ�!" << queMale.front().name << "�� " << queFemale.front().name << endl;
			queMale.pop();
			queFemale.pop();
		}
		else { cout << "���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�."<<endl; }		//���� �ϳ��� ������ ������� "���"
	}
/*
	void display() {	//get() �Է� Ȯ�ο� �Լ�
		cout << "����� �̸� :" << name << endl << "����� ����: " << gend << endl;
	}
*/
};