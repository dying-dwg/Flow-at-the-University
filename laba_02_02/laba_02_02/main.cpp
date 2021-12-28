// LabaAlexa.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"Menu.h"
#include"Text.h"
int main()
{
    setlocale(LC_ALL, "RUS");
    bool live = true;
    int n = 0;
    while (live) {
        cout << "Menu:\n";
        cout << "1.Students:\n";
        cout << "2.Text\n";
        cout << "3. Exit\n";
        cout << "You enter: ";
        cin >> n;
        if (n == 1)
            Menu s;
        else if (n == 2)
            //cout << "Nothing\n";
            Text t;
        else if (n == 3)
            live = false;
        else
            cout << "Unknnown command\n";

    }
}

