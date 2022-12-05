1. **Задача** Да се състави програма, която прочита от клавиатурата латинска буква голяма и извежда поредния й номер в латинската азбука.

	**Пример**:<br>
	Вход:
    ```text
	A
	```
	Изход:
	```text
	1
	```
	---

<br>

2. **Задача** Да се състави програма, която прочита от клавиатурата две цифри (**като знаци** от таблицата ASCII), преобразува ги в числа и извежда тяхното произведение.

	**Пример**:<br>
	Вход:
    ```text
	5 6
	```
	Изход:
	```text
	30
	```
	---

<br>

3. Щастлив номер
    - http://www.math.bas.bg/infos/files/2008-12-02-E3.pdf 

4. Напишете функция, която намира дължината на даден стринг?
```size_t strlen(char str[]) {...}```
5. Напишете функция, която копира стринг?
```void copy_str(char destination[], char source[]) {...}```
6. Напишете функция, която проверява дали даден символен низ, започва с друг символен низ.
```bool starts_with(char str[], char pattern[]) {...}```
7. Напишете програмата, която сортира символен низ състваен само от ASCI символи
    - Input: ```sda```
    - Output: ```ads``
    - Input: ```nasko01IT#DEV```
    - Output: ```#01DEITVaknos```
8. Напишете функция, която сплитва даден стринг по-даден символ със следната сигнатура
    ```split(char[] str, char delimiter, vector<char[]> parts)```
    <br>
    Sample code: 
    ```c++
    #include<iostream>
    #include<vector>

    using namespace std;

    const int MAX_WORD_LENGTH = 100;
    void split(char* str, char delimiter, vector<char[MAX_WORD_LENGTH]>& parts) {

    }
    int main() {
        vector<char[MAX_WORD_LENGTH]> container;
        split("My name is Nasko", ' ', container);
        for (int i = 0; i < container.size(); ++i) {
            cout << i << ". " << container[i] << endl;
        }
    }
```