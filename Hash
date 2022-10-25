#include<string>
#include<vector>
#include<iostream>
#include<list>
using namespace std;
class Book;
void add_two(vector<Book*>& table, int capacity, long long ISBN, string author,
string title); //МЕТОД, ИСПОЛЬЗУЕМЫЙ ДЛЯ ДОБАВЛЕНИЯ ЭЛ-ТА ПРИ
РЕХЕШИРОВАНИИ
class Book
{
 long long ISBN;
 string author; //КЛАСС, ОПИСЫВАЮЩИЙ КНИГУ
 string title;
 Book* next;
public:
 Book(long long ISBN, string author, string title)
 {
 this->author = author;
 this->ISBN = ISBN;
 this->title = title;
 }
 long long getKey()
 {
 return ISBN;
 }
 string getAuthor()
 {
 return this->author;
 }
 string getTitle()
 {
 return this->title;
 }
 Book* getNext()
 {
 return next;
 }
 void setValue(string author, string title)
 {
 this->author = author;
 this->title = title;
 }
 void setNext(Book* another_book)
 {
 this->next = another_book;
 }
};
class HashMap
{
private:
 /*
 ДАННЫЕ ХЕШ-ТАБЛИЦЫ. ФАКТОР ПЕРЕГРУЗКИ ПОКАЗЫВАЕТ
МОМЕНТ, КОГДА ТАБЛИЦА ДОЛЖНА РЕХЕШИРОВАТЬСЯ.
НАЧАЛЬНЫЕ ЁМКОСТЬ, ЗАПОЛНЕННОСТЬ.
 + МАССИВ ХРАНИМЫХ ЭЛ-ОВ
 */
 static const int START_CAPACITY = 16;
 double loadFactor = 0.75;
 int size = 0;
 int capacity = 16;
 vector<Book*> table;
public:
 HashMap(int capacity)
 {
 table.resize(capacity);
 this->capacity = capacity;
 add(123456789456, "Test1", "Number1");
 add(746585674363, "Test2", "Number2"); //ПРЕДВАРИТЕЛЬНОЕ
ЗАПОЛНЕНИЕ 6 ЗАПИСЕЙ В ТАБЛИЦЕ И 2 ВИДА КОНСТРУКТОРА
 add(938574847582, "Test3", "Number3");
 add(589496858549, "Test4", "Number4");
 add(493768932384, "Test5", "Number5");
 add(457237534891, "Test6", "Number6");
 this->size = 6;
 }
 HashMap()
 {
 table.resize(capacity);
 add(123456789456, "Test1", "Number1");
 add(746585674363, "Test2", "Number2");
 add(938574847582, "Test3", "Number3");
 add(589496858549, "Test4", "Number4");
 add(493768932384, "Test5", "Number5");
 add(457237534891, "Test6", "Number6");
 this->size = 6;
 }
 int Hash(long long a)
 {
 return a % capacity; //ХЕШ-ФУНКЦИЯ
 }
 void add(long long ISBN, string author, string title) {
 double coef = (double)size / (double)capacity; //ОПРЕДЕЛЯЕМ ФАКТОР
ПЕРЕГРУЗКИ
 if (coef > loadFactor)
 {
 cout << "Произошло рехеширование!" << endl; //СООБЩАЕМ О
РЕХЕШИРОВАНИИ
 vector<Book*> new_table(capacity * 2);
 for (int i = 0; i < capacity; i++) {
 /*
 ДЛЯ ВСЕХ ЭЛЕМЕНТОВ ПРОВОДИМ ПЕРЕКОПИРОВАНИЕ
В ДРУГОЙ МАССИВ БОЛЬШЕЙ ЁМКОСТИ ПО НОВОЙ ФОРМУЛЕ
 */
 if (table[i] != nullptr) {
 Book* entry = table[i];
 do {
 add_two(new_table, capacity * 2, entry->getKey(), entry-
>getAuthor(), entry->getTitle());
 entry = entry->getNext();
 } while (entry != nullptr);
 }
 }
 //ОБНОВЛЯЕМ ДАННЫЕ ТАБЛИЦЫ
 capacity = capacity * 2;
 table.clear();
 table.resize(capacity);
 table.assign(new_table.begin(), new_table.end());
 }
 const long long key = ISBN;
 const int hash = Hash(key);
 /*
 * ЕСЛИ ЯЧЕЙКА ПУСТАЯ - ЕЁ ЗАПОЛНЕНИЕ
 */
 if (table[hash] == nullptr) {
 table[hash] = new Book(ISBN, author, title);
 size++;
 }
 else {
 /*
 ЕСЛИ НЕ ПУСТАЯ - СЛЕДУЕМ ДО КОНЦА ПО СПИСКУ В
ЯЧЕЙКЕ И:
 А) ПЕРЕЗАПИСЫВАЕМ, ЕСЛИ КОДЫ ЗАПИСЕЙ СОВПАДАЮТ
 Б) ДОБАВЛЯЕМ НОВУЮ ЗАПИСЬ В КОНЕЦ СПИСКА
ОБНОВЛЯЕМ РАЗМЕР ТАБЛИЦЫ
 */
 Book* entry = table[hash];
 while (entry->getNext() != nullptr && entry->getKey() != key) {
 entry = entry->getNext();
 }
 if (entry->getKey() == key) {
 entry->setValue(author, title);
 }
 else {
 entry->setNext(new Book(ISBN, author, title));
 size++;
 }
 }
 }

 int sizeT() { return size; }
 int capacityT() { return capacity; }
 void pop(long long ISBN) {
 /*
 ЕСЛИ ТАБЛИЦА ПУСТАЯ - ПРЕДУПРЕЖДАЕМ И ВЫХОДИМ ИЗ
МЕТОДА
 */
 if (isEmpty())
 {
 cout << "Нечего удалять в таблице!" << endl;
 cout << endl << endl;
 return;
 }
 const long long key = ISBN;
 const int hash = Hash(key);
 if (table[hash] != nullptr) {
 Book* prevEntry = nullptr;
 Book* entry = table[hash];
 while (entry->getNext() != nullptr && entry->getKey() != key) {
 prevEntry = entry; //СЛЕДУЕМ ПО СПИСКУ В ЯЧЕЙКЕ ДО
КОНЦА. ОДНОВРЕМЕННО ЗАПОМИНАЕМ ПРЕДЫДУЩИЙ ЭЛЕМЕНТ.
 entry = entry->getNext();
 }
 if (entry->getKey() == key) {
 if (prevEntry == nullptr) {
 table[hash] = entry->getNext(); //ЕСЛИ ПРЕДЫДУЩЕГО НЕТ
(ОБЪЕКТ ОДИН) - ДЕЛАЕМ ЕГО NULLPTR (ИСПОЛЬЗУЕМ
ОТСУТСТВИЕ СЛЕДУЮЩЕГО)
 }
 else {
 prevEntry->setNext(entry->getNext()); //ЕСЛИ ПРЕДЫДУЩИЙ
ЕСТЬ, УДАЛЯЕМ ЭЛЕМЕНТ ИЗ СПИСКА
 }
 }
 }
 }
 Book* search(long long ISBN) {
 const long long key = ISBN;
 const int hash = Hash(key);
 if (table[hash] == nullptr) //ЕСЛИ В ЯЧЕЙКЕ ВООБЩЕ НИЧЕГО НЕТ
(НИ ЭЛ-ТА, НИ СПИСКА) - ВОЗВРАЩАЕМ NULLPTR
 return nullptr;
 else {
 /*

 ИНАЧЕ СЛЕДУЕМ:
 А) ДО ИСКОМОГО ЭЛЕМЕНТА, ВОЗВРАЩАЕМ УКАЗАТЕЛЬ
НА НЕГО
 Б) ДО КОНЦА, ЭЛЕМЕНТ НЕ НАЙДЕН - ВОЗВРАЩАЕМ
NULLPTR

 */
 Book* entry = table[hash];
 while (entry != nullptr && entry->getKey() != key) {
 entry = entry->getNext();
 }
 if (entry == nullptr) {
 return nullptr;
 }
 else {
 return entry;
 }
 }
 }
 bool isEmpty() {
 /*

 ЕСЛИ ВСЕ ЯЧЕЙКИ ТАБЛИЦЫ NULLPTR - ТАБЛИЦА ПУСТА
 */
 for (int i = 0; i < capacity; ++i) {
 const Book* entry = table[i];
 if (entry != nullptr) {
 return false;
 }
 }
 return true;
 }
 void print() {
 cout << "Все данные таблицы: " << endl;
 for (int i = 0; i < capacity; i++) {
 if (table[i] != nullptr) {
 Book* entry = table[i];
 do {
 cout << entry->getKey() << " " << entry->getAuthor() << " " <<
entry->getTitle() << endl; //ВЫВОД ВСЕХ ЭЛ-ОВ ТАБЛИЦЫ
 entry = entry->getNext();
 } while (entry != nullptr);
 }
 }
 cout << endl << endl;
 }
};
void add_two(vector<Book*>& table, int capacity, long long ISBN, string author,
string title)
{
 long long key = ISBN;
 const int hash = key % capacity;
 if (table[hash] == nullptr) {
 table[hash] = new Book(ISBN, author, title);
 }
 else {
 Book* entry = table[hash];
 while (entry->getNext() != nullptr && entry->getKey() != key) {
 entry = entry->getNext();
 }
 if (entry->getKey() == key) {
 entry->setValue(author, title);
 }
 else {
 entry->setNext(new Book(ISBN, author, title));
 }
 }
}
int main()
{
 setlocale(LC_ALL, "RUS");
 HashMap* hashmap = new HashMap();
 long long k_key;
 string author;
 string title;
 bool flag = true;
 Book* book;
 cout << "Вы можете заполнить хеш-таблицу со значениями: ISBN-номер,
автор, название. Таблица уже заполнена на 5 значений. Что вы хотите?" <<
endl;
 int choice;
 while (flag)
 {
 cout << "1. Добавить запись в таблицу." << endl;
 cout << "2. Удалить запись из таблицы." << endl;
 cout << "3. Распечатать таблицу с имеющимися данными." << endl;
 cout << "4. Поиск в таблице по ключу." << endl;
 cout << endl << endl;
 cin >> choice;
 switch (choice)
 {
 case 1:
 cout << "Введите ISBN: " << endl;
 cin >> k_key;
 cout << "Введите автора книги: " << endl;
 cin >> author;
 cout << "Введите название книги: " << endl;
 cin >> title;
 cout << endl << endl;
 hashmap->add(k_key, author, title);
 break;
 case 2:
 cout << "Введите ISBN удаляемой записи: " << endl;
 cin >> k_key;
 cout << endl << endl;
 hashmap->pop(k_key);
 break;
 case 3:
 hashmap->print();
 break;
 case 4:
 cout << "Введите ISBN искомой записи: " << endl;
 cin >> k_key;
 book = hashmap->search(k_key);
 if (book != nullptr)
 {
 cout << "Данные найденной записи: " << endl;
 cout << "Код: " << book->getKey() << endl;
 cout << "Автор: " << book->getAuthor() << endl;
 cout << "Название: " << book->getTitle() << endl;
 }
 else
 cout << "Данная запись не найдена! " << endl;
 cout << endl << endl;
 break;
 default:
 cout << "Вы ввели некорректный вариант ответа. " << endl;
 break;
 }
 cout << "Что-нибудь ещё? " << endl;
 cout << "1. Да " << endl;
 cout << "2. Нет " << endl;
 cout << endl << endl;
 cin >> choice;
 switch (choice)
 {
 case 1:
 break;
 case 2:
 flag = false;
 break;
 default:
 cout << "Вы ввели некорректный вариант ответа. " << endl;
 cout << endl << endl;
 system("pause");
 return 0;
 break;
 }

 }
}
