/*
#include<iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "RUS");
unsigned char a = 0;
unsigned char maska = 1; //маска 00000001
a = a | (maska << 6); //побитовый сдвиг и активизация 7-го бита
cout << (int)a; //приведение а к целочисленному типу и вывод
*/






/*
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <bitset>
using namespace std;
int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
unsigned int x = 253;
const int n = sizeof(int) * 8;
unsigned maska = (1 << n - 1);
cout << "Начальный вид маски: " << bitset<n>(maska) << endl;
cout << "Результат: ";
for (int i = 1; i <= n; i++)
{
cout << ((x & maska) >> (n - i));
maska = maska >> 1;
}
cout << endl;
system("pause");
return 0;
}
*/






/*
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <bitset>
using namespace std;
int main()
{
unsigned char sort = 0;
unsigned maska = 128; //10000000 – двоичная посл-ть
int numbers[8]; //максимум принимаем 8 чисел
int colvo;
cin >> colvo;
for (int i = 0; i < colvo; i++)
{
cin >> numbers[i]; //заполняем массив чисел
}
for (int i = 0; i < colvo; i++)
{
sort = sort | (maska >> numbers[i]); /*включаем n позицию бита, если
такое число n есть в массиве*/
}
/*bitset<CHAR_BIT> bits(sort);
for (int i = 0; i < 8; i++)
{
if (bits[i] == 1)
cout << i << " ";
}*/
unsigned mask = 128; //новая маска 10000000
for (int j = 0; j < 8; j++)
{
if ( ((sort & mask) >> 7 - j) == 1) /*с помощью маски выводим позиции
активных битов*/
cout << j << " ";
mask = mask >> 1; //сдвиг маски для проверки всех раз-ов
}
}*/






/*
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <bitset>
using namespace std;
int main()
{
unsigned long long sort = 0; //нули для включения битов (если число есть)
unsigned long long mask = 1; //маска 0….1
mask = mask << 63; //побитовый сдвиг маски на 63 разряда
int numbers[sizeof(unsigned long long) * 8];
int colvo;
cin >> colvo;
for (int i = 0; i < colvo; i++)
{
cin >> numbers[i]; //ввод значений
}
for (int i = 0; i < colvo; i++)
{
sort = sort | (mask >> numbers[i]); /*включаем n позицию бита, если такое
число n есть в массиве*/
}
for (int j = 0; j < sizeof(unsigned long long) * 8; j++)
{
if (((sort & mask) >> 63 - j) == 1) /*с помощью маски выводим позиции
активных битов*/
cout << j << " "; //вывод значения в порядке сортировки
mask = mask >> 1; //сдвиг маски для проверки всех раз-ов
}
}
*/





/*
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <bitset>
using namespace std;
int main()
{
unsigned char sort[8] = { 0 }; //нулевой массив на 8 эл-ов
unsigned char mask = 128; //маска 10000000
int numbers[sizeof(unsigned long long) * 8];
int colvo;
cin >> colvo;
for (int i = 0; i < colvo; i++) //ввод значений
{
cin >> numbers[i];
}
for (int i = 0; i < colvo; i++)
{
int pos = numbers[i] / 8; //логика работы с учётом ячейки массива и бита
if (numbers[i] >= 8) //если число не принадлежит первой восьмёрке битов
16
{
int pos_1 = 8 * pos;
sort[pos] = sort[pos] | (mask >> numbers[i] - pos_1); //включаем биты
с помощью маски (те их позиции, числа которых есть в массиве чисел)
}
else
sort[pos] = sort[pos] | (mask >> numbers[i]); //тоже включаем, если
число от 0 до 7
}
/*for (int i = 0; i < 8; i++)
{
bitset <8> bits(sort[i]);
cout << bits << endl;
}*/
unsigned char mask1 = 128;
for (int i = 0; i < 8; i++)
{
for (int j = 0; j < 8; j++)
{
if (sort[i] & (mask >> j))
{
cout << 8 * i + j << " "; /*проходим по массиву и выводим
имеющиеся биты*/
}
}
}
}*/




#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include <bitset>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<vector>
#include <ctime>
using namespace std;
const long long N = 100000000; //максимальное числе эл-ов
void func1(unsigned int* bits)
{
ifstream file0("C:/Users/Рин/OneDrive/Рабочий стол/siaod1.txt");
//открытие текстового документа
unsigned int inp; //переменная для чтения
while (!file0.eof())
{
file0 >> inp;
unsigned int position = (int)(inp / (sizeof(unsigned int) * 8));
/*читаем очередное значение и ставим его в нужную позицию, учитывая
размер int в памяти*/
bits[position] = bits[position] | (1 << inp - position * sizeof(unsigned
int) * 8);
}
file0.close();
}
void func2(unsigned int* bits, unsigned int s_size)
{
ofstream file1;
file1.open("C:/Users/Рин/OneDrive/Рабочий стол/siaod1_2.txt");
//открываем файл для записи
for (unsigned int i = 0; i < s_size; i++)
{
for (unsigned int j = 0; j < sizeof(unsigned int) * 8; j++)
{
if (bits[i] & (1 << j))
{
file1 << j + i * sizeof(unsigned int) * 8 << endl;
/*если бит активен, выводим в новый файл его позицию с учётом размера int в
памяти*/
}
}
}
file1.close();
}
int main()
{
unsigned int s_size = N / (sizeof(unsigned int) * 8); //делим макс. число
значений на размер int
unsigned int* bits = new unsigned int[s_size]; //динамический массив для
НЕ переполнения стека
memset(bits, 0, s_size); //заполняем массив нулями
fstream file;
file.open("C:/Users/Рин/OneDrive/Рабочий стол/siaod1.txt");
long long colvo;
cin >> colvo;
for (long long i = 0; i < colvo; i++)
{
file << colvo - i << endl;
//записываем в файл значения в порядке убывания
}
file.close();
auto start_time = clock(); //засекаем время
func1(bits);
func2(bits, s_size);
auto end_time = clock(); //конец счёта времени
auto search_time = end_time - start_time;
unsigned int size_ = sizeof(unsigned int) * s_size;
//размер массива в памяти
} 
