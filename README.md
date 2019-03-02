# Практическая работа №2
## Варианты и задания
**Вариант 3. Сумма последовательности.**

На вход подаётся число 𝑛 ∈ N : 𝑛 ≤ 2147483647, а также 𝑛 чисел 𝑥𝑖 ∈ Z : |𝑥𝑖 | ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение ∑︁𝑛 𝑖=1 𝑥𝑖 .

**Вариант 17. Разность сумм чётных и нечётных квадратов.**

На вход подаётся число 𝑛 ∈ N : 𝑛 ≤ 2147483647, а также 𝑛 чисел 𝑥𝑖 ∈ Z : |𝑥𝑖 | ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение ∑︁𝑛 𝑖=1 (−1)𝑖 · 𝑥 2 𝑖 .

## Ход работы
Для каждого из заданий был написан код на языке С. Для этого в терминале была использована следующая команда:

 - "nano "название файла"".

Далее написанные программы были скомпилированы и запущены с помощью следующих команд:

 - gcc 03_coolhacker.c -o 07_coolhacker
 - ./07_coolhacker
 - gcc 17_coolhacker2.c -o 17_coolhacker2 -lm
 - ./17_coolhacker

После этого файлы были загружены на репозиторий pr2 с использованием следующих команд:

 - git add .
 - git commit
 - git push -u origin pr2

## Результат работы
Результат работы программ представлен ниже.

**Программа 1. Вариант 3**

![enter image description here](https://pp.userapi.com/c850032/v850032857/143565/94n4eFzxSPo.jpg)

Было введено 5 чисел: 3, 5, 8, 10, 2. В результате программа вывела число 28.


**Программа 2. Вариант 17**

![enter image description here](https://pp.userapi.com/c850032/v850032103/141b43/ZiXEJnv1zX8.jpg)

Было введено 5 чисел: 13, 26, 43, 65, 4. В результате программа вывела число 2867.

| Использованные ресурсы          | Ссылка                                                           |
| ------------    | -----------------------------------------------------------------|
| Статья markdown | https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet |
