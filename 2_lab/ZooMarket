#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

class ZooMarket
	{
	public:
		ZooMarket();
		~ZooMarket(){}

		void store(string itsTitle, string itsMale, string itsNickname, int itsPrice, int itsAmount); 
		void show(); 
		string showName(); 
		void changeAmount(); 
		int amount(); 

	private:
		string itsTitle;
		string itsMale; 
		string itsNickname; 
		int itsPrice; 
		int itsAmount; 
	} ;

//применение конструктора
ZooMarket::ZooMarket() {}

void ZooMarket::store(string animalTitle, string animalMale, string animalNickname, int animalPrice, int animalAmount)
{
	itsTitle=animalTitle;
	itsMale=animalMale;
	itsNickname=animalNickname;
	itsPrice=animalPrice;
	itsAmount=animalAmount;
}

void ZooMarket::show()
{
	cout<<"Показать название: "<<itsTitle<<endl<<"Пол: "<<itsMale<<endl<<"Кличка: "<<itsNickname<<endl<<"Цена: "<<itsPrice<<endl<<"Количество: "<<itsAmount<<endl;
}

string ZooMarket::showName()
{
	return itsTitle;
}

void ZooMarket::changeAmount()
{
	itsAmount=itsAmount-1;
}

int ZooMarket::amount()
{
	return itsAmount;
}

void CreationAnimal(int occupancy, ZooMarket AnimalArray[99]);
void ShowAnimal(int occupancy, ZooMarket AnimalArray[99]);
void ShowAllAnimal(int occupancy, ZooMarket AnimalArray[99]);
void SellAnimal(int occupancy, ZooMarket AnimalArray[99]);

int _tmain(int argc, _TCHAR* argv[])
{
	//Включаем отображение русских символов
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Создаем массив с животными
	ZooMarket AnimalArray[99];

	//текущий номер заполнения массива животных
	int occupancy=1;

	//меню
	int choice;
	do
	{
		system("cls");
		cout<<"Выберите пункт меню:"<<endl<<"1. Ввод нового животного"<<endl<<"2. Показать данные о каком-либо животном"<<endl;
		cout<<"3. Вывести всех животных на экран"<<endl<<"4. Продать животное"<<endl<<"5. Завершить работу программы"<<endl<<"Ваш выбор: ";
		cin>>choice;
		switch(choice)
		{
		case 1:	
			CreationAnimal(occupancy, AnimalArray);
			occupancy++;
			break;
		case 2:	
			ShowAnimal(occupancy, AnimalArray);
			break;
		case 3:	
			ShowAllAnimal(occupancy, AnimalArray);
			break;
		case 4:
			SellAnimal(occupancy, AnimalArray);
			break; //продать животное
		case 5:	
			cout<<"Вы покидаете матрицу и отправляетесь в реальную жизнь. Счастливого пути!"<<endl;
			break;
		default: 
				cout<<"Вы ввели неизвестную команду. Пожалуйста, перечитайте пункты меню"<<endl;
				system("PAUSE");
		}
	}
	while(choice!=5);
	system("PAUSE");
	return 0;
}

//Функция добавления нового животного в зоомагазина
void CreationAnimal(int occupancy, ZooMarket AnimalArray[99])
{
	string crTitle;
	string crMale;
	string crNickname;
	int crPrice;
	int crAmount;
	cout<<"Введите название животного: ";
	cin>>crTitle;
	cout<<"Введите пол: ";
	cin>>crMale;
	cout<<"Введите кличку: ";
	cin>>crNickname;
	cout<<"Введите цену: ";
	cin>>crPrice;
	cout<<"Введите количество: ";
	cin>>crAmount;
	AnimalArray[occupancy].store(crTitle, crMale, crNickname, crPrice, crAmount);
}

//Функция показа животного по номеру
void ShowAnimal(int occupancy, ZooMarket AnimalArray[99])
{
	int numberAnimal;
	cout<<"Введите номер животного: "<<endl;
	cin>>numberAnimal;
	if(numberAnimal<=0  || numberAnimal>=occupancy)
		cout<<"По введенному номеру животные не найдены"<<endl;
	else
		AnimalArray[numberAnimal].show();
	system("PAUSE");
}

//Функция для показа всех животных
void ShowAllAnimal(int occupancy, ZooMarket AnimalArray[99])
{
	int i;
	for(i=1; i<occupancy; i++)
	{
		AnimalArray[i].show();
		cout<<"--------------------------"<<endl;
	}
	system("PAUSE");
}

//Функция продажи животного
void SellAnimal(int occupancy, ZooMarket AnimalArray[99])
{
	string sellName;
	cout<<"Введите название животного для продажи: "<<endl;
	cin>>sellName;
	int i;
	for(i=1; i<(occupancy+1); i++)
	{
		if(sellName==AnimalArray[i].showName())
		{
			if((AnimalArray[i].amount())==0)
			{
				cout<<"Данного животного не в наличии!"<<endl;
				system("PAUSE");
				break;
			}
			cout<<"Животное найдено! Вы купили один экземпляр!"<<endl;
			AnimalArray[i].changeAmount();
			system("PAUSE");
			break;
		}
		else if(i==occupancy)
		{
			cout<<"Животные с таким именем не найдены!"<<endl;
			system("PAUSE");
		}
	}
}
