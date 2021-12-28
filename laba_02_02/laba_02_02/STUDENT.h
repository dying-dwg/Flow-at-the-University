#pragma once
#include<iostream>
#include<string>
#define N 5
using namespace std;
class STUDENT
{
	string fio;
	string group;
	int score[N];

public:
	STUDENT();
	STUDENT(const STUDENT& _copy);
	STUDENT(string fio, string group, int* score);
	int* getScore();
	string getFIO();
	string getGroup();
	float getMiddleScore();//при сравннении использовать будем этот метод
	void setScore(int* arr);
	void setFIO(string fio);
	void setGroup(string group);
	STUDENT& operator=(const STUDENT& _copy);
	friend std::ostream& operator<<(std::ostream& out, const STUDENT& o);
	friend bool operator<(const STUDENT& o1, const STUDENT& o2);
	friend bool operator>(const STUDENT& o1, const STUDENT& o2);
	friend bool operator==(const STUDENT& o1, const STUDENT& o2);
	friend bool operator!=(const STUDENT& o1, const STUDENT& o2);

};

