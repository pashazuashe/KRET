/*

Добавить комментарии и сделать бесконченое меню в main()

 избавться от перевода строки в int и обратно, оптимизироват подключенные библиотеки

*/
#include "KRET.h"
#include <string>
#include <iostream>

using namespace std;

NumberAsString::NumberAsString() {}

NumberAsString::NumberAsString(string str)
{
	stringIn = str;
	number = stoi(stringIn);
	ToString(); // Запускаем преобразование в текст
}

NumberAsString::~NumberAsString()
{
}

void NumberAsString::Set(string str) // Устанваливаем входную строку
{
	stringIn = str;
	number = stoi(stringIn);
	ToString(); // Запускаем преобразование в текст
}

void NumberAsString::Sklon(int index, int currentTrio) // Дописывает разряды
{
	switch (currentTrio) // текущая тройка, 1: единицы, дестки, сотни
	{					 // 2: тысячи
	case 1:				 // 3: миллионы
	{
		switch (index) // Устанавливаем окончания в зависимости от полследних цифр
		{
		case 1:
		{
			// cout << "рубль ";
			stringOut.append("рубль ");
			break;
		}
		case 2:
		case 3:
		case 4:
		{
			// cout << "рубля ";
			stringOut.append("рубля ");
			break;
		}
		default:
		{
			// cout << "рублей ";
			stringOut.append("рублей ");
			break;
		}
		}
		break;
	}
	case 2:
	{
		switch (index)
		{
		case 1:
		{
			// cout << "тысяча ";
			stringOut.append("тысяча ");
			break;
		}
		case 2:
		case 3:
		case 4:
		{
			// cout << "тысячи ";
			stringOut.append("тысячи ");
			break;
		}
		default:
		{
			// cout << "тысяч ";
			stringOut.append("тысяч ");
			break;
		}
		}
		break;
	}
	case 3:
	{
		switch (index)
		{
		case 1:
		{
			// cout << "тысяча ";
			stringOut.append("миллион ");
			break;
		}
		case 2:
		case 3:
		case 4:
		{
			// cout << "тысячи ";
			stringOut.append("миллиона ");
			break;
		}
		default:
		{
			// cout << "тысяч ";
			stringOut.append("миллионов ");
			break;
		}
		}
		break;
	}
	default:
		break;
	}
}

void NumberAsString::MakeString(string str, int digitsCount, int index, int currentTrio) // Печатаем числительные
{
	switch (digitsCount) // Печатаем в зависимости от количства цифр в текущей тройке
	{
	case 1:
	{
		// cout << edin[str[0] - '0'] << " ";
		if (currentTrio == 2)
		{
			stringOut.append(edinF[str[0] - '0']);
		}
		else
		{
			stringOut.append(edin[str[0] - '0']);
		}
		Sklon(str[0] - '0', currentTrio);
		break;
	}
	case 2:
	{
		if ((str[0] - '0') == 1)
		{

			// cout << dcat[str[1] - '0'] << " ";
			stringOut.append(dcat[str[1] - '0']);
			Sklon(0, currentTrio);
		}
		else
		{
			// cout << des[str[0] - '0'] << " ";
			// cout << edin[str[1] - '0'] << " ";
			stringOut.append(des[str[0] - '0']);
			if (currentTrio == 2)
			{
				stringOut.append(edinF[str[1] - '0']);
			}
			else
			{
				stringOut.append(edin[str[1] - '0']);
			}

			Sklon(str[1] - '0', currentTrio);
		}
		break;
	}
	case 3:
	{
		if ((str[1] - '0') == 1)
		{

			// cout << sot[str[0] - '0'] << " ";
			// cout << dcat[str[2] - '0'] << " ";
			stringOut.append(sot[str[0] - '0']);
			stringOut.append(dcat[str[2] - '0']);
			Sklon(0, currentTrio);
		}
		else
		{
			// cout << sot[str[0] - '0'] << " ";
			// cout << des[str[1] - '0'] << " ";
			// cout << edin[str[2] - '0'] << " ";
			stringOut.append(sot[str[0] - '0']);
			stringOut.append(des[str[1] - '0']);
			if (currentTrio == 2)
			{
				stringOut.append(edinF[str[2] - '0']);
			}
			else
			{
				stringOut.append(edin[str[2] - '0']);
			}
			Sklon(str[2] - '0', currentTrio);
		}
		break;
	}
	default:
		break;
	}
}

void NumberAsString::ToString() // Вычисляем колчиество троек
{
	stringOut = "";

	string str = to_string(number);

	int digitsInFirstTrio = str.length() % 3; // Сколько цифр в первой тройке
	int trios = (str.length() - 1) / 3 + 1;	  // Скольо троек
	if (digitsInFirstTrio == 0)
		digitsInFirstTrio = 3;

	// cout << "скольо троек = " << trios << endl;
	// cout << "цифр в первой тройке = " << digitsInFirstTrio  << endl;

	for (int i = 0; i < trios; i++) // Перебираем тройки чисел
	{

		if (i == 0) // Первая тройка слева
		{
			MakeString(str.substr(0, digitsInFirstTrio), digitsInFirstTrio, i, trios - i);
			str.erase(0, digitsInFirstTrio);
		}
		else // Все остальные тройки
		{
			MakeString(str.substr(0, 3), 3, i, trios - i);
			str.erase(0, 3);
		}
	}
}

void NumberAsString::PrintString()
{
	cout << stringOut << '\n'
		 << '\n';
}

void NumberAsString::PrintInt()
{
	cout << number;
}

string NumberAsString::GetString()
{
	return stringOut;
}
/*
private:
int number = 0;
string stringIn = "";
string stringOut = "";
const char edin[10][16] // единицы
	{
		"", "один ", "два ", "три ", "четыре ", "пять ", "шесть ", "семь ", "восемь ", "девять "};
const char edinF[10][16] // единицы женский род
	{
		"", "одина ", "две ", "три ", "четыре ", "пять ", "шесть ", "семь ", "восемь ", "девять "};
const char des[10][24] // десятки
	{
		"", "десять ", "двадцать ", "тридцать ", "сорок ", "пятьдесят ", "шестьдесят ", "семьдесят ", "восемьдесят ", "девяносто "};
const char dcat[10][32] // 10, 11, 12 ... 19
	{
		"десять ", "одиннадцать ", "двенадцать ", "тринадцать ", "четырнадцать ", "пятнадцать ", "шестнадцать ", "семнадцать ", "восемнадцать ", "девятнадцать "};
const char sot[10][24] // сотни
	{
		"", "сто ", "двести ", "триста ", "четыреста ", "пятьсот ", "шестьсот ", "семьсот ", "восемьсот ", "девятьсот "};
}
;
*/

int main()
{
	setlocale(LC_ALL, "Russian");

	string str = "";
	int number = NULL;
	NumberAsString X;

	while (true)
	{
		cout << "Введите положительное число, Выход - Q" << endl;

		cin >> str;

		if (str == "q" || str == "Q")
		{
			return 0;
		}

		try
		{
			throw number = stoi(str);
			number = abs(number);
		}
		catch (const std::invalid_argument &e)
		{
		}
		catch (const std::out_of_range &e)
		{
		}
		catch (...)
		{
		}

		if (number != NULL)
		{
			X.Set(str);
			number = NULL;
			X.PrintString();

			cout << "Выход - Q, ввести число заново - R" << endl;
			cin >> str;
			system("cls");
		}

		if (str == "R" || str == "r")
		{
			system("cls");
		}
		if (str == "Q" || str == "q")
		{
			return 0;
		}
	}
	return 0;
}
