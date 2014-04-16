class computer
{
public:
string pix;
string block;
string processor;
string keyboard;
string OS;
virtual void _monitor(); virtual void _block(); virtual void _processor(); virtual void _keyboard(); void _OS();
virtual void show();
void save_pix(string pix1); void save_block(string block1); void save_processor(string processor1); void save_keyboard(string keyboard1); void save_OS(string OS1);
};

void computer::save_pix(string pix1)
{
pix=pix1;

}

void computer::save_block(string block1)
{
block=block1;
}

void computer::save_processor(string processor1)
{
processor=processor1;
}

void computer::save_keyboard(string keyboard1)
{
keyboard=keyboard1;
}

void computer::save_OS(string OS1)
{
OS=OS1;
}

void computer::show()
{
cout<<"Разрешение экрана: "<<pix<<endl;
cout<<"Информация о системном блоке: "<<block<<endl;
cout<<"Информация о процессоре: "<<processor<<endl;
cout<<"Информация о клавиатуре: "<<keyboard<<endl;
cout<<"Информация об операционной системе:"<<OS<<endl<<endl;
}

void computer::_monitor()
{
save_pix(pix);
}

void computer::_block()
{
cout<<"Введите информацию о системном блоке(yes/no): "<<endl; cin>>block;
save_block(block);
}

void computer::_processor()
{
cout<<"Введите информацию о процессоре: "<<endl; cin>>processor;
save_processor(processor);
}

void computer::_keyboard()
{
cout<<"Введите информацию о клавиатуре(yes/no): "<<endl; cin>>keyboard;
save_keyboard(keyboard);
}

void computer::_OS()
{
cout<<"Введите информацию об операционной системе: "<<endl; cin>>OS; cout<<"\n\n";
save_OS(OS);
}

class pc:public computer
{
public:
vector<pc>p;
void _monitor()
{
pc pc;
int i;
cout<<"У Вас есть монитор? 1 - да, 0 - нет"<<endl; cin>>i;
if(i==1)
{
cout<<"\nВведите разрешение экрана в формате (1920x1080): "<<endl; cin>>pix;
pc.save_pix(pix);
p.push_back(pc); 
}
else
pix="no";
}
};

class server:public pc
{

};

class tablet:public pc
{
public:
void _monitor()
{
cout<<"Введите разрешение экрана в формате (1920x1080):"<<endl; cin>>pix; 
};
void _block()
{
cout<<"Системного блока нет."<<endl; block="no";
};
void _processor()
{
cout<<"Процессор интегрирован в устройство."<<endl; processor="no";
};
void _keyboard()
{
cout<<"Клавиатура аппаратно интегрирована."<<endl; keyboard="no";
};
};

class smartphone:public tablet
{

};

void show_all(computer &r) 
{
r._monitor();
r._block();
r._keyboard();
r._processor();
r._OS();

}

int main() 
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
pc pc;
server serv;
tablet tabl;
smartphone smart;
cout<<"\nВведите данные для персонального компьютера: \n"<<endl;
show_all(pc);
cout<<"\nВведите данные для серверного компьютера: \n"<<endl;
show_all(serv); 
cout<<"\nВведите данные для планшетного компьютера: \n"<<endl;
show_all(tabl);
cout<<"\nВведите данные для смартфона: \n"<<endl;
show_all(smart);
cout<<"Информация о персональном компьютере: \n"<<endl;
pc.show();
cout<<"Информация о серверном компьютере: \n"<<endl;
serv.show();
cout<<"Информация о планшетном компьютере: \n"<<endl;
tabl.show();
cout<<"Информация о смартфоне: \n"<<endl;
smart.show();
system("pause");
return 0;
}
