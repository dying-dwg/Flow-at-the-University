#include "STUDENT.h"

STUDENT::STUDENT() :fio(""), group("")
{
	for (int i = 0; i < N; i++)
		this->score[i] = 0;

}

STUDENT::STUDENT(const STUDENT& _copy)
{
	this->fio = _copy.fio;
	this->group = _copy.group;
	for (int i = 0; i < N; i++)
		this->score[i] = _copy.score[i];
}

STUDENT::STUDENT(string fio, string group, int* score)
{
	this->fio = fio;
	this->group = group;
	for (int i = 0; i < N; i++)
		this->score[i] = score[i];
}

int* STUDENT::getScore()
{
	return score;
}

string STUDENT::getFIO()
{
	return string(this->fio);
}

string STUDENT::getGroup()
{
	return string(this->group);
}

float STUDENT::getMiddleScore()
{

	float middleScore = 0;
	for (int i = 0; i < N; i++)
		middleScore += score[i];

	return middleScore / N;
}

void STUDENT::setScore(int* arr)
{
	for (int i = 0; i < N; i++)
		this->score[i] = arr[i];
}

void STUDENT::setFIO(string fio)
{
	this->fio = fio;
}

void STUDENT::setGroup(string group)
{
	this->group = group;
}


STUDENT& STUDENT::operator=(const STUDENT& _copy)
{

	this->fio = _copy.fio;
	this->group = _copy.group;
	for (int i = 0; i < N; i++)
		this->score[i] = _copy.score[i];

	return *this;
}

std::ostream& operator<<(std::ostream& out, const STUDENT& o)
{
	out << "FIO: " << o.fio << "\n";
	out << "Group: " << o.group << "\n";
	out << "Score: ";
	for (int i = 0; i < N; i++)
		out << o.score[i] << "\t";
	out << "\n";
	return out;
}

bool operator<(const STUDENT& o1, const STUDENT& o2)
{
	STUDENT S1(o1), S2(o2);
	return S1.getMiddleScore() < S2.getMiddleScore();
}

bool operator>(const STUDENT& o1, const STUDENT& o2)
{
	STUDENT S1(o1), S2(o2);
	return S1.getMiddleScore() > S2.getMiddleScore();
}

bool operator==(const STUDENT& o1, const STUDENT& o2)
{
	STUDENT S1(o1), S2(o2);
	return S1.getMiddleScore() == S2.getMiddleScore();
}

bool operator!=(const STUDENT& o1, const STUDENT& o2)
{
	STUDENT S1(o1), S2(o2);
	return S1.getMiddleScore() != S2.getMiddleScore();
}
