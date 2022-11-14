#pragma once
#ifndef DEREVYA_SHAPKA
#define DEREVYA_SHAPKA
#include<vector>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct Leaf //структура "листа" дерева
{
double value; //величина
int height; //высота дерева
Leaf* left;
/*Указатели на листы узла*/
Leaf* right;
Leaf(double another) //конструктор листа
{
value = another;
left = right = 0;
height = 1;
}
};
int height(Leaf* leaf) //получение высоты поддерева для данного корня
{
if (leaf != nullptr)
return leaf->height;
else
return 0;
}
/*Определение сбалансированного дерева. (Критерий сбалансированности.)
Дерево является сбалансированным тогда и только тогда, когда для каждого
узла
высота его двух поддеревьев различается не более, чем на 1. */
int balance_factor(Leaf* leaf)
{
return height(leaf->right) - height(leaf->left); //вычисления фактора
балансировки для определения момента балансировки
}
void calcul_height(Leaf* leaf) //определение величины высоты поддерева
{
int h_left = height(leaf->left);
int h_right = height(leaf->right);
leaf->height = (h_left > h_right ? h_left : h_right) + 1; //наибольшая длина
поддерева
}
Leaf* rotate_right(Leaf* y) // правый поворот
{
Leaf* x = y->left;
y->left = x->right;
x->right = y;
calcul_height(y);
calcul_height(x);
return x;
}
Leaf* rotate_left(Leaf* x) // левый поворот
{
Leaf* y = x->right;
x->right = y->left;
y->left = x;
calcul_height(x);
calcul_height(y);
return y;
}
Leaf* balance(Leaf* p) //балансировка
{
calcul_height(p);
if (balance_factor(p) == 2) //если проблема справа
{
if (balance_factor(p->right) < 0)
p->right = rotate_right(p->right);
return rotate_left(p);
}
if (balance_factor(p) == -2) //если проблема слева
{
if (balance_factor(p->left) > 0)
p->left = rotate_left(p->left);
return rotate_right(p);
}
return p; //балансировка не произошла, возврат текущего узла
}
Leaf* insert(Leaf* p, double k) // вставка ключа k в дерево с корнем p
{
if (!p) return new Leaf(k);
/*Вставка нового листа в дерево по принципу -
если новое значение больше узла-корня -
вставка вправо,
иначе - влево. Функция является рекурсивной и в конце всегда
происходит балансировка (один из минусов АВЛ-дерева)*/
if (k < p->value)
p->left = insert(p->left, k);
else
p->right = insert(p->right, k);
return balance(p);
}
void postorder(Leaf* root)
{ //процесс обратного обхода
setlocale(LC_ALL, "RUS");
vector<Leaf*> stack; /*вектор для стека значений, информацию
которых надо показать (необходим из-за
условия обратного обхода)*/
Leaf* deleted = nullptr; //переменная для вывода правой части поддерева
Leaf* last_element = nullptr; //переменная для обработки стека значений с
конца
while ((!stack.empty()) || root != NULL)
{
if (root)
{
stack.push_back(root); /*пока не дойдём до конца
 данной ветки - следуем вниз,
сохраняя значения в стек
 */
root = root->left;
}
else
{
last_element = stack.back();
if ((last_element->right) && (deleted != last_element->right))
/*если у корня есть правый элемент и он
 не совпадает с уже рассмотренным значением
 (сначала обходится левая ветка)*/
{
root = last_element->right;
}
else
{
cout << "Значение посещено: " << last_element->value
<< endl; //вывод информации листа
stack.pop_back(); //удаление его из стека
рассматриваемых
deleted = last_element;
}
}
}
}
void inorder(Leaf* root)
{ //процесс симметричного обхода
setlocale(LC_ALL, "RUS");
vector<Leaf*> stack;
while ((!stack.empty()) || root != NULL)
{
if (root)
{
stack.push_back(root); /*пока не дойдём до конца
 данной ветки - следуем вниз,
сохраняя значения в стек
 */
root = root->left;
}
else
{
root = stack.back();
cout << "Значение посещено: " << root->value << endl;
stack.pop_back();
root = root->right; //обеспечивает вывод корня
}
}
}
double sum(Leaf* root)
{
vector<Leaf*> stack;
double sum = 0;
while ((!stack.empty()) || root != NULL)
{
if (root)
{
stack.push_back(root); /*пока не дойдём до конца
 данной ветки - следуем вниз,
сохраняя значения в стек
 */
root = root->left;
}
else
{
root = stack.back();
sum += root->value;
stack.pop_back();
root = root->right;
}
}
return sum;
}
int content(Leaf* root)
{
vector<Leaf*> stack;
double content = 0;
while ((!stack.empty()) || root != NULL)
{
if (root)
{
stack.push_back(root); /*пока не дойдём до конца
 данной ветки - следуем вниз,
сохраняя значения в стек
 */
root = root->left;
}
else
{
root = stack.back();
content++;
stack.pop_back();
root = root->right;
}
}
return content;
}
double average(Leaf* root)
{
return sum(root) / (double)(content(root));
}
Leaf* createTree(vector<double> vecctor)
{
vector<Leaf*> vec;
if (!vecctor.empty())
{
Leaf* leaf = new Leaf(vecctor[0]);
for (int i = 1; i < vecctor.size(); i++)
{
vec.push_back(insert(leaf, vecctor[i]));
}
return leaf;
}
}
#endif
