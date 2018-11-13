# Sorting the Doubly linked list with different types of data and working with it

Author       : MrLinder.

Version      : v1.0.

Date         : 16.04.2015/1:41 - 

License      : GNU.
 
Description  : 																	
Создаем Указатель классового типа			
Внутри класса создается список размерностью указанной пользователем
Каждый элемент списка списка должен быть масивом
Поддерживаемые типы данных int, double, char.

Инициализация Автоматическиая, Пользовательская, из массива, из файла


- - - - - - - - - - - - Функции для работы со списком- - - - - - - - - - - - 


//Создание списка

List<int> *Object = new List<int>();

//загрузка значений

Object->PushBegin(1);

Object->PushBack(2);

//Удаление элемента 

Object -> DeleteNth(Порядковый_номер_элемента);

//Вставка элемента в порядке возрастания

Object -> InsertSort(6);

Object -> InsertSort();


//Вставка элементов массива по возрастанию (2 способа)

Object -> PushSort(Arr, 6);

InsertSort(&Object, Arr);


//Вставка Значения в указанное место

Object -> InsertIn(Значение, место вставки);


//Вставка Массива в указанное место(2 способа)

Object -> InsertIn(Array, размер, место_вставки);

InsertIn(&Object, Arr2, Место_вставки);


//загрузка массивами 2 способа (int Arr[9] = {1,2,3,4,5,6,7,8,9};)

Object -> PushBack(Arr, 9);

Object -> PushBegin(Arr, 9);

PushBack(&Object, Arr);

PushBegin(&Object, Arr);


//Выталкивание из стека

cout << Object->PopBack() << endl; 

cout << Object->PopBegin() << endl;


//Показать все (2 способа)

Object -> ShowAll();	

cout << *Object << endl;


//Возвращает порядковый номер заданного элемента;

cout << Object -> Search(5) << endl;

//Возвращает значение элемента по указанному порядковому номеру;

cout<<  Object -> GetNth(1) <<endl;

//Полное освобождение памяти

Object -> Free();

delete Object;

//проверка списка элементов по возрастанию

Object -> CheckList();

//Системная информация

Object -> sysinfo();

- - - - - - - - - - - - - - - - ALGORITHMS SORTING - - - - - - - - - - - - - - - - 

Insert Sort , Bubble_Sort, 	Sub BubbleS Sort, 	Shaker_Sort, 	Select Sort, 	Shell Sort, 	Heap Sort
