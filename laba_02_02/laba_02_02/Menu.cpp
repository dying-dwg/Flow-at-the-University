#include "Menu.h"

Menu::Menu() :arrStudents(nullptr), size(0) {
	bool live = true;
	int n = 0, arrScores[N];
	string fio = "", surname = "", initials = "", group = "";
	while (live) {
		try {

			std::cout << "Меню\n";
			std::cout << "1. Добавить студента в список\n";
			std::cout << "2. Удалить студента из списка\n";
			std::cout << "3. Изменить данные студента\n";
			std::cout << "4. Список студентов\n";
			std::cout << "5. Список хорошистов/отличников\n";
			std::cout << "6. Выход\n";
			std::cout << "-> ";
			cin >> n;


			switch (n)
			{
			case 1:
				init(fio, group, arrScores);
				add(STUDENT(fio, group, arrScores));
				break;
			case 2:
				print();
				cout << "\nВвод номера: ";
				cin >> n;
				correct(n);
				del();

				break;
			case 3:
				print();
				cout << "\nВвод номера: ";
				cin >> n;
				correct(n);
				init(fio, group, arrScores);
				arrStudents[n].setFIO(fio);
				arrStudents[n].setGroup(group);
				arrStudents[n].setScore(arrScores);
				quickSort(arrStudents, size);
				break;

			case 4:
				print();
				break;
			case 5:
				goodStudents();
				break;

			case 6:
				live = false;
				break;
			default:
				system("cls");
				cout << "Введите число от 1 до 6\n";
				break;
			}
		}
		catch (const int exec) {
			if (exec == 0)
				cout << "Массив пуст\n";
		}

	}
}

Menu::~Menu()
{
	if (size == 0)
		throw 0;
	size = 0;
	delete[] arrStudents;
}

void Menu::print()
{
	if (size == 0)
		throw 0;
	cout << "------------Студенты------------\n";
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "]:\n";
		cout << arrStudents[i];
	}
	cout << "--------------------------------\n";
}

int Menu::getSize()
{
	return size;
}

void Menu::quickSort(STUDENT* arr, int size)
{
	int i = 0, j = size - 1;
	STUDENT md = arr[size / 2];

	do {
		while (arr[i] < md) i++;
		while (arr[j] > md) j--;

		if (i <= j) {
			STUDENT tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;


		}
	} while (i <= j);

	if (j > 0)
		quickSort(arr, j + 1);
	if (i < size)
		quickSort(&arr[i], size - i);
}

void Menu::goodStudents()
{
	bool flag;
	int* arrScore, inc = 0;
	cout << "-----------Хорошисты/отличники------------\n";
	for (int i = 0; i < size; i++) {
		flag = true;
		arrScore = arrStudents[i].getScore();
		int j = 0;
		while (j < N)
		{
			if (arrScore[j] < 4) {
				flag = false;
				break;
			}
			j++;
		}

		if (flag) {
			cout << "[" << inc << "]\n";
			cout << arrStudents[i];
			inc++;
		}
	}
	if (inc == 0)
		cout << "Нет хорошистов/отличников\n";
	cout << "--------------------------------------\n";
}

void Menu::add(STUDENT obj)
{
	STUDENT* arr = new STUDENT[size + 1];

	if (size != 0) {
		for (int i = 0; i < size; i++)
			arr[i] = arrStudents[i];
		arr[size] = obj;
	}
	else
		arr[size] = obj;

	size++;
	STUDENT* bufptr = arrStudents;
	delete[] bufptr;
	arrStudents = arr;
	quickSort(arrStudents, size);
}

void Menu::del()
{
	if (size == 0)
		throw 0;


	STUDENT* bufptr = arrStudents;
	STUDENT* arr = new STUDENT[size - 1];//выделили память под новый массив
	if (size == 1) {
		delete[] arr;
		arr = nullptr;
		size--;
		return;
	}
	for (int i = 1; i < size; i++)//начиная со второго элемента заполняем новый массив
		arr[i - 1] = arrStudents[i];

	arrStudents = arr;
	delete[] bufptr;
	size--;
	quickSort(arrStudents, size);
	return;
}
void Menu::correct(int& index) {

	if (index >= size)
		index = size - 1;
	else if (index < 0)
		index = 0;
	int arr[N];
	for (int i = 0; i < N; i++)
		arr[i] = 0;
	arrStudents[index].setScore(arr);

}

void Menu::init(string& _fio, string& _group, int* _scores)
{
	string surname = "", initials = "", group = "";
	int n = 0;
	cout << "\nВведите фамилию: ";
	cin >> surname;
	cout << "\nВведите инициалы: ";
	cin >> initials;
	_fio = surname + " " + initials;

	cout << "\nВведите номер группы: ";
	cin >> _group;
	cout << "\nУспеваемость: ";
	for (int i = 0; i < N; i++) {
		cout << "Оценка[" << i + 1 << "]: ";
		cin >> _scores[i];
		cout << "\n";
	}

}
