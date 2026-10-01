# Основы C++

**Лабораторная работа 1**

---

**Тема:** Динамические структуры данных

**Вариант:** Линейные динамические массивы. Слияние двух отсортированных массивов

**Стандарт языка:** C++20  
**Система сборки:** CMake 3.16+  
**Тестирование:** Google Test

**Ограничения:**
Запрещены классы, конструкторы, семантика копирования/перемещения,
`std::string`, `std::vector`, `std::array` и умные указатели. 
Работа с памятью — только вручную (`new[]` / `delete[]`).

---

## Сборка и запуск

### Требования

* Компилятор C++20
* CMake 3.16+

### 1. Конфигурация проекта

Создание папки сборки `build` и установка зависимостей:

```Bash
cmake -B build
```

### 2. Компиляция

Собрать сразу весь проект (основная программа `lab` и тесты `lab_tests`):

```Bash
cmake --build build
```

- Только основную интерактивную программу:

```Bash
cmake --build build --target lab
```

- Только тесты:

```Bash
cmake --build build --target lab_tests
```

### 3. Запуск

#### Основная программа

- **Linux / macOS:**

```Bash
./build/lab
```
    
- **Windows (PowerShell / cmd):**

```PowerShell
.\build\lab.exe
# Или для конфигурации Visual Studio:
.\build\Debug\lab.exe
```

#### Запуск тестов Google Test

- **Linux / macOS:**

```Bash
./build/lab_tests
```

- **Windows:**

```PowerShell
.\build\lab_tests.exe
# Или для конфигурации Visual Studio:
.\build\Debug\lab_tests.exe
```

---

## Структура проекта

```text
cpp-lab-sort-develop/
├── CMakeLists.txt
├── README.md
├── include/
│   └── array_ops.h       # Объявления чистых функций работы с массивами
├── src/
│   ├── array_ops.cpp     # Реализация базовых операций и алгоритма слияния
│   └── main.cpp          # Интерактивное текстовое меню
└── tests/
    └── test_variant.cpp  # Google Tests
```
