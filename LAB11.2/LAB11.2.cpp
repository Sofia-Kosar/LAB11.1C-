#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateBIN(char* fname) // ��������� ����� ������� � �������� �����
{
	ofstream fout(fname, ios::binary); // ������� ���� ��� ������
	char ch; // ������� ����������� � �� ������������ ��������
	string s; // �������� ������������ �����
	do
	{
		cin.get(); // ������� ����� ��������� � ��� �� ���� �������
		cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
		cout << "enter line: "; getline(cin, s); // ����� �����
		for (unsigned i = 0; i < s.length(); i++) // ������� �������� �����
			fout.write((char*)&s[i], sizeof(s[i])); // �������� ������ � ����
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintBIN(char* fname) // ��������� ����� �� �����
{
	ifstream fin(fname, ios::binary); // ������� ���� ��� ����������
	char c; // ���������� ������
	while (fin.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
	{
		cout << c << endl; // �������� ���� �� �����
	}
	cout << endl;
}
void ProcessBIN1(char* fname, char* evenname, char* oddname) // ���������� �� ����� f
{ // � ���� g �������-�����
	ifstream f(fname, ios::binary); // ������� ���� ��� ����������
	ofstream e(evenname, ios::binary); // ������� ���� ��� ������
	ofstream o(oddname, ios::binary);
	char c; // ���������� ������
	while (f.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
	{
		if ((int)c % 2 == 0) // ���� ������ � ������
			e.write((char*)&c, sizeof(c)); // �������� ���� � ���� g
		else
			o.write((char*)&c, sizeof(c));
	}
}
int main()
{
	// binary files
	char fname[100]; // ��'� ������� �����
	cout << "enter file name 1: "; cin >> fname;
	CreateBIN(fname); // ����� ����� ����� � ���������
	PrintBIN(fname); // ������ ���� ������� ����� �� �����
	char evenname[100]; // ��'� ������� �����
	cout << "enter file name 2: "; cin >> evenname;
	char oddname[100]; // ��'� �������� �����
	cout << "enter file name 2: "; cin >> oddname;
	ProcessBIN1(fname, evenname, oddname);
	cout << "Even numbers : " << endl;
	PrintBIN(evenname); // ������ ���� ������� ����� �� �����
	cout << "Odd numbers : " << endl;
	PrintBIN(oddname); // ������ ���� ����� �� �����
	return 0;
}