#include <string>
#ifndef KRET_H
#define KTER_H

using namespace std;

class NumberAsString
{
public:
    NumberAsString();
    NumberAsString(string str);
    ~NumberAsString();
    void Set(string str);
    void Sklon(int index, int currentTrio);
    void MakeString(string str, int digitCount, int index, int currentTrio);
    void ToString();
    void PrintString();
    void PrintInt();

    string GetString();

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
};

int main();

#endif