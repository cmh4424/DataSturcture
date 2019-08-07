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
		cout << "고객이름:";
		cin >> people.name;
		cout << "성별을 입력하세요(f or m)";
		while (people.gend != 'm' && people.gend != 'f') cin >> people.gend;
	}

	void set() {
		cout << "당신의 이름 :" << people.name << endl << "당신의 성별: " << people.gend << endl;	//입력 확인용
		if (people.gend == 'm') queMale.push(people);
		else queFemale.push(people);
	}

/*
	void display() {	//get() 입력 확인용 함수
		cout << "당신의 이름 :" << name << endl << "당신의 성별: " << gend << endl;
	}
*/
};