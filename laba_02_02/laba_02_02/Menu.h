#pragma once
#include"STUDENT.h"
#include<string>
#include<iostream>
class Menu
{

	STUDENT* arrStudents;
	int size;

public:
	Menu();
	~Menu();
	void print();
	int getSize();
	void quickSort(STUDENT* arr, int size);
	void goodStudents();
	void add(STUDENT obj);
	void del();
	void correct(int& index);
	void init(string& fio, string& group, int* scores);


};

