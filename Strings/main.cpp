#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<ctype.h>

using namespace std;
int StringLength(const char str[]);
char* to_upper(char str[]);
char* to_lower(char str[]);
char* shrink(char str[]);
bool is_palindrome(const char str[]);
bool is_int_number(const char str[]);
int to_int_number(char* str);
bool is_bin_number(char* str);
int bin_to_dec(const char str[]);
bool is_hex_number(char* str[]);



void main()
{
	setlocale(LC_ALL, "");
	cout << 'Ё' - 'ё' << endl;
	'\0';
	/*char std[] = { 'H', 'e', 'l', 'l', 'o' };
	char str1[] = "Hello";
	str1[1] = 'o';
	cout << str1 << endl;

	const char* str2 = "Wrold";
	str2[3] = '1';
	cout << str2 << endl;*/

	const int SIZE = 256;
	char str[SIZE] = "   Хорошо     живет     на    свете    Винни     Пух";
	//cout << "Введите строку:";cin >> str;
	///*SetConsoleCP(1251);
	//wcin.getline(str, SIZE);
	//SetConsoleCP(866);*/
	//cout << str << endl;
	/*cout << " Размер введенной строки: " << StringLength(str) << endl;*/
	//cout << to_upper(str) << endl;
	//cout << to_lower(str) << endl;*/
	cout << typeid(str).name() << endl;
	cout << shrink(str) << endl;
	is_palindrome(str);
	cout << "Строка " << (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	cout << str << endl;
	cout << "Строка " << (is_bin_number(str) ? "" : "НЕ ") << "является двоичным числом" << endl;
	cout << str << "(bin)=" << bin_to_dec(str) << "dec;\n";

}
int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

char* to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
		if (str[i] >= 'а' && str[i] <= 'я') str[i] -= 32;
		if (str[i] == 'ё')str[i] -= 16;*/
		str[i] = toupper(str[i]);
	}
	return str;
}

char* to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
		if (str[i] >= 'А' && str[i] <= 'Я') str[i] += 32;
		if (str[i] == 'Ё')str[i] -= 16;*/
		str[i] = tolower(str[i]);
	}
	return str;
}

char* shrink(char str[])
{
	cout << typeid(str).name() << endl;
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	while (str[0] == ' ')for (int i = 0; str[i]; i++)str[i] = str[i + 1];
	return str;
}

char* remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
			for (int j = 0; str[j]; j++)str[j] = str[j + 1];
	}
	return str;
}

bool is_palindrome(const char str[])
{
	cout << typeid(str).name() << endl;
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - i - 1])return false;
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}

bool is_int_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < 0 && str[i] <= 10)
		{
			return false;
		}
	}
	return true;
}

int to_int_number(char* str)
{
	int num = 0;
	for (int i = 0; str[i]; i++)
	{
		num += 10;
		num *= 10;
	}
	return num;
}

bool is_bin_number(char* str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' + str[i] != '1')
		{
			return false;
		}
	}
	return true;
}

int bin_to_dec(const char str[])
{
	/*if (!is_bin_number(str))return 0;*/
	int n = strlen(str);
	int decimal = 0;
	int weight = 1;
	for (int i = n - 1; i > 0; i--)
	{
		decimal += (str[i] - 48) * weight;
		weight *= 2;
	}
	return decimal;
}

bool is_hex_number(char* str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0x' + str[i] != '1')
		{
			return false;
		}
	}
	return true;
}

