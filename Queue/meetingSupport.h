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

	void isMatched() {
		if (!queMale.empty() && !queFemale.empty()) {			//두 스택에 최소 1명이상 있으면 둘다 팝 하고 "연결되었습니다"
			cout << "커플이 탄생했습니다!" << queMale.front().name << "과 " << queFemale.front().name << endl;
			queMale.pop();
			queFemale.pop();
		}
		else { cout << "아직 대상자가 없습니다. 기다려주십시오."<<endl; }		//둘중 하나라도 스택이 비었으면 "대기"
	}
/*
	void display() {	//get() 입력 확인용 함수
		cout << "당신의 이름 :" << name << endl << "당신의 성별: " << gend << endl;
	}
*/
};