#include <iostream>
#include <time.h>
using namespace std;
#ifndef SORTLIST_H
#define SORTLIST_H

/*----------------Global variables---------------*/
	
int const FromBegin = 0;
int const FromEnd = 1;

/*----------------Class Data--------------------*/

template <class T>
class Data{
public:	
	T *Elem;
};

/*----------------Class Node--------------------*/
template <class T>
class List;

template <class T>
class Node
{
protected:
	Data<T> *key;
	Node<T> *next;
	Node<T> *prev;
	Node(){ next = prev = NULL; /*cout<<"Node Const"<<endl;*/}
	~Node(){/*cout<<"Node Dictr"<< endl;*/ }
	friend class List<T>;
	template <class X>
	friend ostream& operator<<(ostream& stream, List<X>&);
};

/*----------------Class List--------------------*/
template <class T>
class List 
{
	Node<T> *Begin;			//Указатель на первый элемент списка
	Node<T> *End;				//Указатель на последний элемент списка
	Node<T> *Temp;				//Указатель на временный элемент списка
	Node<T> *Curr;				//Указатель на текущщий элемент 

	int countElem;				//счетчик количества элементов списка
	int countMistake;			//Счетчик  количества ошибок
	T* MistakeArray;			//Указатель на массив ошибочных элементов

	clock_t t;
    char *NameSort;
	int c;    //Итерации
    int e;    //сравнения
    int s;    //перестановки
	bool WhatArr;
	bool stop;
public:
   List(); 
	~List();
	
//- - - - - - - - - - - - - - - - ALGORITHMS WORK WITH LIST - - - - - - - - - - - - - - - - 	
	void PushBack(T const &add=0 );
	void PushBegin(T const &add=0 );
	void PushBack(T const Arr[], int size=0);
	void PushBegin(T const Arr[], int size=0);
		
	void PushSort(T const &add = 0);
	void PushSort(T const Arr[], int size=0);
	void InsertIn(T const &insert = 0 , int pos = 0);
	void InsertIn(T const Arr[], int size=0, int pos = 0);
		
	T PopBack();
	T PopBegin();
	T DeleteNth(int del = 0);
	void DeleteVal(T const &del);
		
	int Search(T const &srch=0);
	T GetNth(int g=0);
		
	void ShowAll(int Par = 0 );
	void CheckList();
	void sysinfo();
	void Free();

template <class X>
friend ostream& operator<<(ostream& stream, List<X>&);
//- - - - - - - - - - - - - - - - - OTHER ALGORITHMS - - - - - - - - - - - - - - - - -
	void NewData(char const *name = "undefined method sorting");
	void EndData();

//- - - - - - - - - - - - - - - -ALGORITHMS SORTING - - - - - - - - - - - - - - - - 
	void Swap(Node <T> **left, Node <T> **right);
	void BubbleSort();
	void SubBubbleSort();
	void SelectSort();
	void ShakerSort();
	void InsertSort();
	void ShellSort();
		void HeapDown(int k, int size);
		void HeapSort();
		
	
};

//-----------------------Процедуры -------------------------------
template<class T, int size> // определение шаблона функции min()
void PushBack(List<T> **ob, T (&Arr)[size]) //параметризованная функция для отыскания минимального значения в массиве
{
	if(! *ob)
	(*ob) = new List<T>();
	(*ob) -> PushBack(Arr, size);
}

template<class T, int size> // определение шаблона функции min()
void PushBegin(List<T> **ob, T (&Arr)[size]) //параметризованная функция для отыскания минимального значения в массиве
{
	if(! *ob)	
	(*ob) = new List<T>();
	(*ob) -> PushBegin(Arr, size);
}

template<class T, int size> 
void PushSort(List<T> **ob, T (&Arr)[size])
{
	if(! *ob)	
	(*ob) = new List<T>();
	(*ob) -> PushSort(Arr, size);
}

template<class T, int size> 
void InsertIn(List<T> **ob, T (&Arr)[size], int pos)
{
	if(! *ob)	
	(*ob) = new List<T>();
	(*ob) -> InsertIn(Arr,size, pos );
}

#include "../source/SortListdef.cpp"
#include "../source/SortAlgoritmdef.cpp"
#endif















