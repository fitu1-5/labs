#include <iostream>
#include <string>
#include <cstdlib>
//старые и новые курсы валют
#define USD_in_RUB_OLD 35,45
#define EUR_in_RUB_OLD 48,92
#define USD_in_RUB_NEW 35,75
#define EUR_in_RUB_NEW 49,29
//количество вкладов
#define deposite_count 4

using namespace std;
//массив строк с названием всех вкладов
string type_str[]={"Standart","Standart+","Profitable","Safe"};

class deposite
{
	string family;//имя гражданина, открывшего счет
	double cash_in;//изначальное пополение счета
	int deposite_type;//тип вклада
	double cash_out;//проценты
	int i_day,i_month,i_year,o_day,o_month,o_year;//сроки
	
	bool check_date (int days);//функция проверки срока вклада
	void standart();
	void standart_plus();
	void profitable();//прибыльный
	void safe();//беспроигрышный
	
public :
	void cash_input();
	void cash_output();
};

bool deposite::check_date (int days)
{
	//сколь дней прошло
	if (((o_year-i_year)*365-(o_month-i_month)*30-(o_day-i_day))>days)
	return 1; else return 0;
}

void deposite::cash_input()
{
	cout<<"Enter your family"<<endl;
	cin>>family;
	cout<<"Enter your cash"<<endl;
	cin>>cash_in;
	cout<<"Enter open date"<<endl;
	cin>>i_day>>i_month>>i_year;
	cout<<"Enter close date"<<endl;
	cin>>o_day>>o_month>>o_year;
	cash_out=0;
	int bit_mask=0;
	deposite_type=0;
	//прогонка по вкладам, которые в дальнейшем могут быть использованы
	if ((cash_in>30000)&&(cash_in<300000)) bit_mask+=2;
	if ((cash_in>=300000)&&(cash_in<3000000)) bit_mask+=4;
	if ((cash_in>=3000000)&&(cash_in<10000000)) bit_mask+=8;
	if ((cash_in>=1000000)&&(cash_in<5000000)) bit_mask+=16;

	if (bit_mask!=0)
	{
		cout<<"You can open this deposites:"<<endl;
	    for (int i=1,j=2;i<=deposite_count;i++,j*=2)
			if(bit_mask&j) cout <<i<<".Deposite "<<type_str[i]<<endl;//битовая маска
	}
	else cout<<"ERROR, DEPOSITES NOT FOUND"<<endl;
	
	while (!deposite_type)
	{	
		cout<<"Enter a type of deposite that you want use"<<endl;
		cin>>deposite_type;
		if ((bit_mask&((int)pow(2,deposite_type)))==0) 
		{
			deposite_type=0;
			cout<<"ERROR, THIS DEPOSITE UNAVAILABLE"<<endl;
		}
	}
}

void deposite::cash_output()
{ 
	switch (deposite_type)
	{
		case 1 : standart(); break;
		case 2 : standart_plus(); break;
		case 3 : profitable(); break;
		case 4 : safe(); break;
	}
	cout << family<<"\t";
	cout << cash_in<<"\t";
	cout << type_str[deposite_type-1]<<"\t";
	cout << cash_out<<"\t"<<endl;
}

//пошло описание функций-вкладов
void deposite::standart()
{ 
	if (check_date(90))
	cash_out=cash_in*0.05;
}

void deposite::standart_plus()
{ 
	if (check_date(180))
	cash_out=cash_in*0.1;
}

void deposite::profitable()
{ 
	if (check_date(360))
	cash_out=cash_in*0.12;
}

void deposite::safe()
{ 
	if (check_date(360))
	cash_out=cash_in/3.0*0.1+cash_in/3.0/USD_in_RUB_OLD*0.2*USD_in_RUB_NEW+cash_in/3.0/EUR_in_RUB_OLD*1.5*EUR_in_RUB_NEW;
}

int main()
{
		deposite bill[10];
		for (int i=0;i<10;i++)
		{
			bill[i].cash_input();
		}
		cout <<"======"<< endl;
		cout << "FAMILY\t"<<"IN\t"<<"DEPOSITE\t"<<"%\t"<<endl;
		for (int i=0;i<10;i++)
		{
			bill[i].cash_output();
		}
		system ("pause");
		return 0;
	}
