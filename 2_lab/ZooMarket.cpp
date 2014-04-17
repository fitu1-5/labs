// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
enum __gender{ male, female };

class animal {
public:
	animal::animal(string _animal, string _name, enum __gender _gender, int _price) {
		animalType = _animal;
		name = _name;
		gender = _gender;
		price = _price;
	}
	void animal::show() {
		if (!deleted) {
			cout << "Имя: \"" << name << "\" пол ";
			if (gender == male) { cout << " муж."; }
			else { cout << " жен."; }
			cout << ", цена " << price << "р.\n";
		}
	}
	void animal::del() {
		deleted = true;
	}
	bool animal::isdel() {
		if (deleted) return true;
		return false;
	}
private:
	enum __gender gender;
	string animalType, name;
	int price;
	bool deleted = false;
};

typedef struct zoo {
	string animalType;
	int count;
	vector<animal> animals;
} zoo;

void addAnimal(vector<zoo> &shop) {
	string animalType, name, buffer;
	char _price[100];
	zoo zooelem;
	__gender gender = male;
	bool hasAnimal = false;
	int posAnimal, price;
	cout << "Введите тип животного: ";
	cin >> animalType;
	cout << "Введите имя животного: ";
	cin >> name;
	while (true) {
		cout << "Пол животного:\n1. М\n2. Ж\n";
		cin >> buffer;
		if (buffer == "1") { break; }
		else if (buffer == "2") {
			gender = female;
			break;
		}
		else {
			cout << "Неверный ввод!\n";
		}
	}
	cout << "Введите цену животного: ";
	cin >> _price;
	price = atoi(_price);
	for (int i = 0; i < shop.size(); i++) {
		if (shop[i].animalType == animalType) {
			hasAnimal = true;
			posAnimal = i;
			break;
		}
	}
	if (hasAnimal) {
		shop[posAnimal].animals.push_back(animal(animalType, name, gender, price));
		shop[posAnimal].count++;
	}
	else {
		zooelem.animalType = animalType;
		zooelem.count = 1;
		zooelem.animals.push_back(animal(animalType, name, gender, price));
		shop.push_back(zooelem);
	}
}

void showAnimal(vector<zoo> shop) {
	for (int i = 0; i < shop.size(); i++) {
		cout << shop[i].animalType << "\n============================\n"; 
		for (int k = 0; k < shop[i].count; k++) {
			if (!shop[i].animals[k].isdel()) shop[i].animals[k].show();
		}
	}
}

void showAnimalTypes(vector<zoo> shop) {
	for (int i = 0; i < shop.size(); i++) {
		cout << i+1 << ". " << shop[i].animalType << endl;
	}
}

void showAnimalsInType(vector<zoo> shop, int el) {
	for (int k = 0; k < shop[el].count; k++) {
		cout << k + 1 << ". ";
		if (!shop[el].animals[k].isdel()) shop[el].animals[k].show();;
	}
}

void deleteAnimal(vector<zoo> &shop) {
	int el, subel;
	char buff[100];
	cout << "Выберите номер списка:" << endl;
	showAnimalTypes(shop);
	cin >> buff;
	el = atoi(buff);
	if (el <= 0 || el > shop.size()) {
		cout << "Нет такого элемента" << endl;
		return;
	}
	showAnimalsInType(shop, --el);
	cin >> buff;
	subel = atoi(buff);
	if (subel <= 0 || subel > shop[el].animals.size()) {
		cout << "Нет такого элемента" << endl;
		return;
	}
	shop[el].animals[subel - 1].del();
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<zoo> shop;
	int menu = 0;
	char simb[10];

	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do {
		cout << "Выберите пункт меню:" << endl;
		cout << "1. Добавть животное" << endl;
		cout << "2. Удлить животное" << endl;
		cout << "3. Вывести животных" << endl;
		cout << "4. Выход" << endl;
		cin >> simb;
		menu = atoi(simb);
		switch (menu) {
		case 1: { addAnimal(shop); break; }
		case 2: { deleteAnimal(shop); break; }
		case 3: { showAnimal(shop); break; }
		}
	} while (menu != 4);

	system("PAUSE");
	return 0;
}

