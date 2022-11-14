#include<iostream>
#include<string>
#include<vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void sufTable(vector<int>& arr, vector<int>& arr1, string word) { //заполнение
таблицы суффиксов
int i = word.length();
int j = word.length() + 1;
/*
* * Если кратко - логика такова, что для каждого символа запоминается такая
максимальная
длина с символами до него, для которой такая же длина суффикса и
символ с
символами до него равен этому суффиксу. За время вычисления
используется Z - функция.
*/
arr1[i] = j;
while (i > 0) {
while (j <= word.length() && word[i - 1] != word[j - 1]) {
if (arr[j] == 0) {
arr[j] = j - i;
}
j = arr1[j];
}
i--;
j--;
arr1[i] = j;
}
}
void prefix(vector<int>& arr, vector<int>& arr1, string word) {
int prefixBorder = arr1[0];
for (int i = 0; i <= word.length(); i++) {
if (arr[i] == 0) {
arr[i] = prefixBorder;
}
if (i == prefixBorder) {
prefixBorder = arr1[prefixBorder];
}
}
}
void goodSuffix(vector<int>& arr, string word) { //эвристика хорошего суффикса
vector<int> stopPos(word.length() + 1);
sufTable(arr, stopPos, word);
prefix(arr, stopPos, word);
}
void badsymbEvristic(vector<int>& arr, string word) //эвристика плохого символа
{
for (int i = 0; i < arr.size(); i++) //предварительное заполнение эл-ми с
несущ. индексами для массива (знак того, что символа нет)
{
arr[i] = word.length();
}
for (int i = 0; i < word.length() - 1; i++)
{
arr[(int)word[i]] = word.length() - i - 1; //запоминаем номер последней
позиции сущ-го эл-та
}
}
void turboBM(string word, string text)
{
int i = 0;
int lastsuffix = 0;
int shift = word.length();
vector<int> badsymbEvrist(256);
vector<int> goodsuffEvrist(word.length() + 1);
vector<int> answer;
int turboShift = 0;
badsymbEvristic(badsymbEvrist, word); //препроцессинг
goodSuffix(goodsuffEvrist, word);
while (i <= text.length() - word.length())
{
int j = word.length() - 1;
while ((j >= 0) and (word[j] == text[i + j]))
{
--j;
if ((lastsuffix != 0) and (j == word.length() - 1 - shift))
//сравниваем текущую ситуацию с прошлым сдвигом и прошлым суффиксом
j -= lastsuffix;
}
if (j < 0) //если слово найдено в строке
{
answer.push_back(i); //добавить рез-т
shift = goodsuffEvrist[0]; //макс. сдвиг
lastsuffix = word.length() - shift;
}
else
{
int nowsuffix = word.length() - 1 - j; //длина совпавшего
суффикса
int turboShift = lastsuffix - nowsuffix; //наименьший
возможный сдвиг
int badSymbShift = badsymbEvrist[text[i + j]] - word.length() + j
+ 1; //при несовпадении символа определяем сдвиг по таблице плохого
символа. Сравниваем с турбосдвигом.
shift = max(turboShift, badSymbShift); //выбираем максимум из
турбосдвига и сдвига по плохому символу
if (shift == goodsuffEvrist[j + 1])
lastsuffix = min(((int)word.length() - shift), nowsuffix);
else
{
if (turboShift < badSymbShift)
shift = min(shift, (lastsuffix + 1)); //если длина
сдвига плохого суффикса больше турбосдвига, то вывод - смещение не больше
ТС и не меньше, чем длина запомненного суффикса + 1
lastsuffix = 0;
}
}
i += shift; //сдвиг
cout << i << endl; //вывод индексов, на которые происходит сдвиг
}
for (int i = 0; i < answer.size(); i++)
{
cout << answer[i] << endl;
}
}
int Find(string text, string word) //алгоритм поиска методом "грубой силы"
{
int textlen = text.length();
int wordlen = word.length();
for (int i = 0; i <= textlen - wordlen; i++)
{
bool flag = true;
/*
Поиск происходит до длины текста минус длины строки (т.к
нужно, чтобы строка вмещалась целиком)
Для каждого эл-та текста отходим на длину, которая не
более длины искомой строки. Если успешно - возврат позиции входа.
*/
for (int j = 0; j < wordlen; j++)
{
if (text[i + j] != word[j]) //если символ отличается от шаблона
{
flag = false; //конец проверки, выход
break;
}
}
if (flag) return i; ///если найден шаблон - возврат позиции
}
return -1;
}
int main()
{
 setlocale(LC_ALL, "RUS");
 vector<string> arr;
 string text = "ВпрМеня? Зовут, ВпрРинВпра! ПривВпрет"; //текст для поиска
string separator = " ,.!&?;:@";
string word = "";
string word_search = "Впр";
for (int i = 0; i < text.length(); i++) { //разделение строки на вектор строк
if (separator.find(text[i]) == string::npos) { //пока значение символа не
равно символу-разделителю
word += text[i]; //собираем слово
}
else
{
if (word != "")
arr.push_back(word); //если встречаем символразделитель - добавляем новую строку в вектор, если она не пустая. Обнуляем
слово.
word = "";
}
if (i == text.length() - 1)
{
if (word != "")
arr.push_back(word); //аналогично для последнего эл-та
( костыль:( )
word = "";
}
}
vector <string> answer; //вектор для фильтрации
for (int k = 0; k < arr.size(); k++)
{
string temp = arr[k];
int position = Find(temp, word_search); //применяем алгоритм поиска
грубой силой
if (position == 0) //если вхождение в начале - формируем итоговый
вектор
answer.push_back(temp);
}
for (int k = 0; k < answer.size(); k++)
{
cout << answer[k] << endl;
}
turboBM("abcd", "badbbabcdacadbcdddacbdbbdabcdacadbccabbadadbc");
}
