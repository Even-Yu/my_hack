#include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>

#define USER_NAME "even"//��¼�û���
#define PASSWORD "shirley722815"//��¼����

using namespace std;

void login(void)//��¼
{
	string user_name;//�û���
	string password{};//����

	while (1)
	{
		system("cls");
		
		cout << "�������û�����";
		cin >> user_name;
		cout << "���������룺";
		
		int i = 0;
		while (1)
		{
			password += _getch();
			if (i>=20 && password[i]!=8 && password[i]!=13)//������������20���ַ�
			{
				cout << "";
				password.erase(i);
				i--;
			}
			else if (password[i] == 8)//�������˸��
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
			else if (password[i] == 13)//�����˻س���
			{
				password.erase(i);
				break;
			}
			else cout << "*";//������*���������ַ�
			i++;
		}

		if (user_name != USER_NAME || password != PASSWORD)//�˺��������ʱ
		{
			cout << "����������������룡" << endl;
			system("pause");
			continue;
		}
		else//�˺�������ȷʱ
		{
			system("cls");
			return;
		}
	}
}

void printMenu(void)//��ӡ���ܲ˵�
{
	system("cls");
	cout << "1����վ404����" << endl;
	cout << "2����վ�۸Ĺ���" << endl;
	cout << "3��DNS����" << endl;
	cout << "4����������������" << endl;
	cout << "5����վ������¼" << endl;
	cout << "6���˳�" << endl;
}

int funcChoose(void)//ѡ����
{
	float n;
	while (1)
	{
		cout << "�����빦����ţ�";
		cin >> n;
		if (cin.fail() || n < 1 || n>6 || n!=(int)n)
		{
			cin.clear();
			cin.ignore(255,'\n');
			cout << "����������������룡" << endl;
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
	cout << "404������..." << endl;
	system("pause");
}

void siteEdit(void)
{
	system("cls");
	cout << "�۸Ĺ�����..." << endl;
	system("pause");
}

void attackDNS(void)
{
	system("cls");
	cout << "DNS������..." << endl;
	system("pause");
}

void siteRestart(void)
{
	system("cls");
	cout << "����������..." << endl;
	system("pause");
}

void attackRecord(void)
{
	system("cls");
	cout << "��¼��ѯ��..." << endl;
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