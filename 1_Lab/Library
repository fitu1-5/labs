#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

class card
	{
	public:
		//конструкторы
		card();
		~card(){}

		//функции
		void store(string aBookName, string aBookAuthor, int aInstances);
		void show();

	private:
		string itsBookName;
		string itsBookAuthor;
		int itsInstances;
	} ;

//применение конструктора
card::card() {}

void card::store(string bookName, string bookAuthor, int instances)
{
	itsBookName=bookName;
	itsBookAuthor=bookAuthor;
	itsInstances=instances;
}

void card::show()
{
	cout<<"Название книги: "<<itsBookName<<endl<<"Имя автора: "<<itsBookAuthor<<endl<<"Колличество экземпляров: "<<itsInstances<<endl;
}

void CreationBook(int occupancy, card BookArray[99]);
void ShowBook(int occupancy, card BookArray[99]);
void ShowAllBook(int occupancy, card BookArray[99]);

int _tmain(int argc, _TCHAR* argv[])
{
	//Включаем отображение русских символов
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Создаем массив с книгами
	card BookArray[99];

	//текущий номер заполнения массива книг
	int occupancy=1;

	//меню
	int choice;
	do
	{
		system("cls");
		cout<<"Выберите пункт меню:"<<endl<<"1. Ввод новой книги"<<endl<<"2. Показать данные о какой-либо книге"<<endl;
		cout<<"3. Вывести все книги на экран"<<endl<<"4. Завершить работу программы"<<endl<<"Ваш выбор: ";
		cin>>choice;
		switch(choice)
		{
		case 1:	
			CreationBook(occupancy, BookArray); 
			occupancy++;
			break;
		case 2:	
			ShowBook(occupancy, BookArray);
			break;
		case 3:	
			ShowAllBook(occupancy, BookArray);
			break;
		case 4:	
			cout<<"Вы покидаете матрицу и отправляетесь в реальную жизнь. Счастливого пути!"<<endl;
			break;
		default: 
				cout<<"Вы ввели неизвестную команду. Пожалуйста, перечитайте пункты меню"<<endl;
				system("PAUSE");
		}
	}
	while(choice!=4);
	system("PAUSE");
	return 0;
}

//Функция создания новой книги
void CreationBook(int occupancy, card BookArray[99])
{
	string crBookName;
	string crAuthorName;
	int crInstances;
	cout<<"Введите название книги: ";
	cin>>crBookName;
	cout<<"Введите имя автора: ";
	cin>>crAuthorName;
	cout<<"Введите колличество экземпляров: ";
	cin>>crInstances;
	BookArray[occupancy].store(crBookName, crAuthorName, crInstances);
}

//Функция показа книги по номеру
void ShowBook(int occupancy, card BookArray[99])
{
	int numberBook;
	cout<<"Введите номер книги: "<<endl;
	cin>>numberBook;
	if(numberBook<=0  || numberBook>=occupancy)
		cout<<"По введенному номеру книги не найдены"<<endl;
	else
		BookArray[numberBook].show();
	system("PAUSE");
}

//Функция для показа всех книг
void ShowAllBook(int occupancy, card BookArray[99])
{
	int i;
	for(i=1; i<occupancy; i++)
	{
		BookArray[i].show();
		cout<<"--------------------------"<<endl;
	}
	system("PAUSE");
}
