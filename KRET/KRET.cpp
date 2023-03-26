/*

Добавить комментарии и сделать бесконченое меню в main()

мб: оптимизировать int -> byte, избавться от перевода строки в int и обратно, оптимизироват подключенные библиотеки

*/
#include "KRET.h"
#include <string>
#include <iostream>
#include <sstream>
//#include <Windows.h>

using namespace std;

class NumberAsString
{
public:

	NumberAsString()
	{

	}

	NumberAsString(unsigned int n)
	{
		number = n;
	}

	NumberAsString(string str)
	{
		stringIn = str;
		number = stoi(stringIn);
		ToString();
	}

	~NumberAsString()
	{
		
	}

	void Set(string str)
	{
		stringIn = str;
		number = stoi(stringIn);
		ToString();
	}

	void Set_Old()
	{
		bool b = true;

		while (b)
		{
			cout << "Введите положительное число, Выход - Q" << endl;

			cin >> stringIn;

			if (stringIn == "q" || stringIn == "Q")
			{
				b = false;
			}
			

			try
			{
				throw number = stoi(stringIn);
			}
			catch (const std::invalid_argument& e)
			{
				b =! b;
			}
			catch (const std::out_of_range& e)
			{
				b =! b;
			}
			catch (...)
			{
				
			}

			number = abs(number);
			b =! b;
			system("cls");
		}

		ToString();
	}

	void Sklon(int index, int currentTrio)
	{
		switch (currentTrio)
		{
		case 1:
		{
			switch (index)
			{
			case 1:
			{
				//cout << "рубль ";
				stringOut.append("рубль ");
				break;
			}
			case 2:
			case 3:
			case 4:
			{
				//cout << "рубля ";
				stringOut.append("рубля ");
				break;
			}
			default:
			{
				//cout << "рублей ";
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
				//cout << "тысяча ";
				stringOut.append("тысяча ");
				break;
			}
			case 2:
			case 3:
			case 4:
			{
				//cout << "тысячи ";
				stringOut.append("тысячи ");
				break;
			}
			default:
			{
				//cout << "тысяч ";
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
				//cout << "тысяча ";
				stringOut.append("миллион ");
				break;
			}
			case 2:
			case 3:
			case 4:
			{
				//cout << "тысячи ";
				stringOut.append("миллиона ");
				break;
			}
			default:
			{
				//cout << "тысяч ";
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

	void MakeString(string str, int digitsCount,int index,  int currentTrio)
	{
		switch (digitsCount)
		{
		case 1:
		{
			//cout << edin[str[0] - '0'] << " ";
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

				//cout << dcat[str[1] - '0'] << " ";
				stringOut.append(dcat[str[1] - '0']);
				Sklon(0, currentTrio);
			}
			else
			{
				//cout << des[str[0] - '0'] << " ";
				//cout << edin[str[1] - '0'] << " ";
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

				//cout << sot[str[0] - '0'] << " ";
				//cout << dcat[str[2] - '0'] << " ";
				stringOut.append(sot[str[0] - '0']);
				stringOut.append(dcat[str[2] - '0']);
				Sklon(0, currentTrio);

			}
			else
			{
				//cout << sot[str[0] - '0'] << " ";
				//cout << des[str[1] - '0'] << " ";
				//cout << edin[str[2] - '0'] << " ";
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

	void ToString()
	{
		string str = to_string(number);

		int digitsInFirstTrio = str.length() % 3;
		int trios = (str.length() - 1) / 3 + 1;
		if (digitsInFirstTrio == 0) digitsInFirstTrio = 3;


		//cout << "скольо троек = " << trios << endl;
		//cout << "цифр в первой тройке = " << digitsInFirstTrio  << endl;

		
		for (int i = 0; i < trios; i++)
		{
			
			if (i == 0)
			{
				MakeString(str.substr(0, digitsInFirstTrio), digitsInFirstTrio,i, trios - i);
				str.erase(0, digitsInFirstTrio);
			}
			else
			{
				MakeString(str.substr(0, 3), 3,i,trios - i);
				str.erase(0, 3);
			}
			
		}
	}

	void PrintString()
	{
		cout << stringOut << '\n' << '\n';
	}

	void PrintInt()
	{
		cout << number;
	}

private:

	int number = 0;
	string stringIn = "";
	string stringOut = "";
	const char edin[10][16] // единицы
	{
		"","один ","два ","три ","четыре ","пять ","шесть ","семь ","восемь ","девять "
	}; 
	const char edinF[10][16] // единицы женский род
	{
		"","одина ","две ","три ","четыре ","пять ","шесть ","семь ","восемь ","девять "
	};
	const char des[10][24] // десятки
	{
		"","десять ","двадцать ","тридцать ","сорок ","пятьдесят ","шестьдесят ","семьдесят ","восемьдесят ","девяносто "
	};
	const char dcat[10][32] // дцатки
	{
		"десять ","одиннадцать ","двенадцать ","тринадцать ","четырнадцать ","пятнадцать ","шестнадцать ","семнадцать ","восемнадцать ","девятнадцать "
	};
	const char sot[10][24] // сотни
	{
		"","сто ","двести ","триста ","четыреста ","пятьсот ","шестьсот ","семьсот ","восемьсот ","девятьсот "
	};

};



int main()
{
	setlocale(LC_ALL, "Russian");

	bool b = true;
	string str;
	int number = 0;
	NumberAsString X;
	while (b)
	{
		cout << "Введите положительное число, Выход - Q" << endl;

		cin >> str;

		if (str == "q" || str == "Q")
		{
			b = false;
			return 0;
		}
		else
		{
			try
			{
				throw number = stoi(str);
				
			}
			catch (const std::invalid_argument& e)
			{
				b = !b;
			}
			catch (const std::out_of_range& e)
			{
				b = !b;
			}
			catch (...){}
		}

		X.Set(str);
		number = abs(number);
		X.PrintString();
		//number = abs(number);
		b = !b;
		//system("clear");
	}

	
	

	
	cin.get();
	return 0;
}
