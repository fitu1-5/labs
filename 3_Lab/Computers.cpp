// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

class Computer
	{
	public:
	void store(string itsTitle, string itsSystemUnit, string itsCPU, string  itsOS); 
	void show(); 

	protected:
		string itsTitle;
		string itsSystemUnit; 
		string itsCPU; 
		string itsOS; 
	} ;


void Computer::store(string computerTitle, string computerSystemUnit, string computerCPU, string  computerOS)
	{
	itsTitle=computerTitle;
	itsSystemUnit=computerSystemUnit;
	itsCPU=computerCPU;
	itsOS=computerOS;
	}

void Computer::show()
	{
	cout<<"Показать название: "<<itsTitle<<endl<<"Системный блок: "<<itsSystemUnit<<endl<<"CPU: "<<itsCPU<<endl<<"Операционная система: "<<itsOS<<endl;
	}

class PC : public Computer
	{
	public:
		void pcStore(string itsMonitor,string itsVideoCard); 
		void pcShow(); 

	protected:
		string itsMonitor;
		string itsVideoCard;
	};

void PC::pcStore(string computerMonitor, string computerVideo)
	{
	itsMonitor=computerMonitor;
	itsVideoCard=computerVideo;
	}

void PC::pcShow()
	{
	cout<<"Монитор: "<<itsMonitor<<endl<<"Видеокарта: "<<itsVideoCard<<endl;
	}


class Server : public Computer
	{};

class Tablet : public Computer
	{
	public:
		void tbStore(string itsSensor, string itsBattery); 
		void tbShow(); 

	protected:
		string itsSensor;
		string itsBattery; 
	};

void Tablet::tbStore(string computerSensor, string computerBattery)
	{
	itsSensor=computerSensor;
	itsBattery=computerBattery;
	}

void Tablet::tbShow()
	{
		cout<<"Сенсор: "<<itsSensor<<endl<<"Батарея: "<<itsBattery<<endl;
	}

class Phone : public Tablet
	{
	public:
		void phStore(string itsCall); 
		void phShow(); 

	protected:
		string itsCall;
	};

void Phone::phShow()
	{
		cout<<"Возможность звонить: "<<itsCall<<endl;
	}

void Phone::phStore(string computerCall)
	{
	itsCall=computerCall;
	}


int _tmain(int argc, _TCHAR* argv[])
{
	//Включаем отображение русских символов
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Создаем массивы
	PC pcArray;
	Server serArray;
	Tablet tbArray;
	Phone phArray;

	pcArray.store("ПК", "имеется", "Intel", "Windows");
	pcArray.pcStore("Samsung", "Nvidia");
	serArray.store("Meijin", "имеется", "Intel", "Linux");
	tbArray.store("Samsung" , "моноблок", "Snapgon", "Android");
	tbArray.tbStore("multitouch", "2000_мА");
	phArray.store("Iphone", "моноблок", "Apple_A6", "IOS");
	phArray.phStore("оно_звонит!");

	pcArray.show();
	pcArray.pcShow();
	cout<<"------------------------"<<endl;
	serArray.show();
	cout<<"------------------------"<<endl;
	tbArray.show();
	tbArray.tbShow();
	cout<<"------------------------"<<endl;
	phArray.show();
	phArray.phShow();
	cout<<"------------------------"<<endl;

	system("PAUSE");
	return 0;
}
