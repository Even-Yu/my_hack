#include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>

#define USER_NAME "even"//登录用户名
#define PASSWORD "shirley722815"//登录密码

using namespace std;

void login(void)//登录
{
	string user_name;//用户名
	string password{};//密码

	while (1)
	{
		system("cls");
		
		cout << "请输入用户名：";
		cin >> user_name;
		cout << "请输入密码：";
		
		int i = 0;
		while (1)
		{
			password += _getch();
			if (i>=20 && password[i]!=8 && password[i]!=13)//密码输入上限20个字符
			{
				cout << "";
				password.erase(i);
				i--;
			}
			else if (password[i] == 8)//输入了退格键
			{
				if (i ==0)
				{
					password.erase(i);
					continue;
				}
				else
				{
					cout << "\b \b";
					password.erase(--i);
					i--;
				}
			}
			else if (password[i] == 13)//输入了回车键
			{
				password.erase(i);
				break;
			}
			else cout << "*";//否则以*代替密码字符
			i++;
		}

		if (user_name != USER_NAME || password != PASSWORD)//账号密码错误时
		{
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			continue;
		}
		else//账号密码正确时
		{
			system("cls");
			return;
		}
	}
}

void printMenu(void)//打印功能菜单
{
	system("cls");
	cout << "1、网站404攻击" << endl;
	cout << "2、网站篡改攻击" << endl;
	cout << "3、DNS攻击" << endl;
	cout << "4、服务器重启攻击" << endl;
	cout << "5、网站攻击记录" << endl;
	cout << "6、退出" << endl;
}

int funcChoose(void)//选择功能
{
	float n;
	while (1)
	{
		cout << "请输入功能序号：";
		cin >> n;
		if (cin.fail() || n < 1 || n>6 || n!=(int)n)
		{
			cin.clear();
			cin.ignore(255,'\n');
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			printMenu();
		}
		else return (int)n;
	}
	
	return n;
}

void attack404(void)
{
	system("cls");
	cout << "404攻击中..." << endl;
	system("pause");
}

void siteEdit(void)
{
	system("cls");
	cout << "篡改攻击中..." << endl;
	system("pause");
}

void attackDNS(void)
{
	system("cls");
	cout << "DNS攻击中..." << endl;
	system("pause");
}

void siteRestart(void)
{
	system("cls");
	cout << "重启攻击中..." << endl;
	system("pause");
}

void attackRecord(void)
{
	system("cls");
	cout << "记录查询中..." << endl;
	system("pause");
}



int main()
{
	login();
	
	while (1)
	{
		int funcNum;
		
		printMenu();
		funcNum = funcChoose();

		switch (funcNum)
		{
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			attackDNS();
			break;
		case 4:
			siteRestart();
			break;
		case 5:
			attackRecord();
			break;
		default:
			return 0;
		}
	}

	system("pause");
	return 0;
}