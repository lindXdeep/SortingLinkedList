#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
#ifndef SORTALGORITM_H
#define SORTALGORITM_H
#include "../header/SortList.h"

template <class T>
void List<T>::NewData(char const *name)			//Данные 
{
	int size = strlen(name+1);
	NameSort = new char[size];
	strcpy(NameSort, name);
	
	WhatArr = true;
    t = clock();
    c = 0;
    e = 0;
    s = 0;
	stop = false;
}

template <class T>
void List<T>::EndData()
{
	t = clock() - t;
}

template <class T>
void List<T>::Swap(Node<T>** left, Node<T>** right) //Функция меняет местами два эленмента
{
	T Tmp = (*left) -> key -> Elem[0];
	(*left) -> key -> Elem[0] = (*right) -> key -> Elem[0];
	(*right) -> key -> Elem[0] = Tmp ;
}

template <class T>
void List<T>::SelectSort()		//Сортировка прямым выбором
{
NewData("Select Sort");
	Node<T>* b = Begin;
	while(b -> next)
	{ c++;
		Node<T>* b_nx = b -> next;
		while(b_nx)
		{ e++;
			if(b -> key -> Elem[0] > b_nx -> key -> Elem[0])
			{
				Swap(&b, &b_nx); s++;
			}
		b_nx = b_nx -> next;
		}
	b = b-> next;
	}
EndData();
}

template<class T>
void List<T>::BubbleSort()		 //Обычная оптимизированная сортировка пузырьком
{
NewData("Bubble Sort");
	Node<T> *b, *b_nx;
	Node<T> *b_out = Begin;
	Node<T> *end = End;
		
	while(b_out -> next != NULL )
	{ c++;
		b = Begin;
		b_nx = Begin -> next;
		while(b != end )
		{ e++;
			if(b -> key -> Elem[0] > b_nx -> key -> Elem[0] )
			{
				Swap(&b, &b_nx); s++;
				stop = true;
			}
			b = b -> next;
			b_nx = b_nx -> next;
		}
	if(!stop) break;
	end = end -> prev;	
	b_out = b_out -> next;	
	}
EndData();
}

template<class T>
void List<T>::SubBubbleSort()		 //Обычная оптимизированная сортировка пузырьком
{
NewData("Sub Bubble Sort");	
	Node<T> *b, *b_nx;
	Node<T> *b_out = Begin;
	Node<T> *end = End;
	bool stop = false;
	
	while(b_out -> next != NULL )
	{ c++;
		b = Begin;
		b_nx = Begin -> next;
		
		while(b_nx != NULL )
		{ e++;
			if(b -> key -> Elem[0] > b_nx -> key -> Elem[0])
			{
				Swap(&b, &b_nx); s++;
				stop = true;	 //Не останавливается пока есть перестановка
			}
			b = b -> next;
			b_nx = b_nx -> next;
		}
	if(!stop) break; // выход из цикла если не совершена перестановка
	end = end -> prev;	
	b_out = b_out -> next;	
	}
EndData();
}

template<class T>
void List<T>::ShakerSort()		//шейкорная сортировка
{
NewData("Shaker Sort");
	Node<T> *N, *lb = Begin, *rb = End;
	do{	c++;
		N = lb;
		while(N != rb )
		{ e++;
			if(N -> key -> Elem[0] > N->next -> key -> Elem[0] )
			{
				Swap(&N, &N->next); s++;
				stop = true;
			}	
			N = N -> next;
		}
		if(!stop) break;
	
		N = rb;
		while(N != lb)
		{ e++;
			if(N->prev -> key -> Elem[0] > N -> key -> Elem[0] )
			{
				Swap(&N->prev, &N); s++;
				stop = true;
			}	
			N = N -> prev;
		}
		if(!stop) break;	
	
		rb = rb -> prev;
		lb = lb ->next;

	if(lb->next == rb ) break;
	}while(lb && rb);
EndData();
}

template<class T>
void List<T>::InsertSort()		//шейкорная сортировка
{			  
NewData("Insert Sort");
	
	Node<T>* B = Begin;
	Node<T>* b = NULL;
	Node<T>* I;
			
	while(B != NULL)
	{ c++;
		b = B;			
		I = B->prev;
		if(I != NULL)		
		{
			while(I != NULL && I -> key -> Elem[0] > b-> key -> Elem[0])
			{ s++; 
				Swap(&I, &b);
				I = I -> prev;
				b = b -> prev;
			}
		}
		B = B -> next;
	}
EndData();
}

template<class T>
void List<T>::ShellSort()		//шейкорная сортировка
{			  
NewData("Shell Sort");

	Node<T>* B;
	Node<T>* b;	
	Node<T>* I;

	int d = countElem/2;
	GetNth(d);

	while(d > 0)
	{ c++;
		B = Begin;
		b = Curr;
		
		while(b != NULL)
		{ e++;
			if(B -> key -> Elem[0] > b -> key -> Elem[0])
			{ 
				Swap(&B, &b);	s++;
			}
			B = B -> next;
		b = b -> next;
		}
	d = d/2;
	GetNth(d);
	
	B = Begin;
		while(B != NULL && d < 1)
		{ c++;
			b = B;			
			I = B->prev;
			if(I != NULL)		
			{ e++;
				while(I != NULL && I -> key -> Elem[0] > b-> key -> Elem[0] )
				{
					Swap(&I, &b); s++; 
					I = I -> prev;
					b = b -> prev;
				}
			}
			B = B -> next;
		}	
	}
EndData();
}

template <class T>
void List<T>::HeapDown(int k, int size) 
{
	GetNth(k);
	Node<T>* Tree = Curr;
	Node<T>* Child = NULL;
	
	while(k <= size/2)
	{e++;
		GetNth(k*2);
		Child = Curr;

		if(Child -> key -> Elem[0] < Child-> next -> key -> Elem[0])
				Child = Child -> next;
			
		if(Tree -> key -> Elem[0] >= Child -> key -> Elem[0]) break;
		
		Swap(&Tree, &Child); s++;
	}
}

template <class T>
void List<T>::HeapSort() 
{
NewData("Heap Sort");	

	int size = countElem+1;  //для цикла while  (size--)

	while(size-- != 0)
	{ c++;
		int i = size/2;

			while (i-- >= 0 )
			{ c++;
				HeapDown(i, size-1);		// -1 уменьшаем количество сортируемух элементов на 1 
			}

			if(Begin -> key -> Elem[0] > End -> key -> Elem[0] )
			Swap(&Begin, &End);
			if(Begin-> next == End) break;
			End = End -> prev;
	}
EndData();	
}

template <class T>
void List<T>::CheckList() 
{
	countMistake = 0;
	Node<T>* b_pr = Begin;
	Node<T>* b = b_pr -> next;
	Node<T>* b_nx = b -> next;
	
	while(b_pr && b && b_nx)
	{
		if(b_pr -> key -> Elem[0] > b -> key -> Elem[0] || b_nx -> key -> Elem[0] < b -> key -> Elem[0] )
			countMistake++;
	
		b_pr = b_pr -> next;
		b_nx = b_nx -> next;
		b = b-> next;
	}
		
	if (!countMistake) return;
	
	MistakeArray = new T[countMistake];
	
	b_pr = Begin;
	b = b_pr -> next;
	b_nx = b -> next;
	
	int j = 0;
	while(b_pr && b && b_nx)
	{
		if(b_pr -> key -> Elem[0] > b -> key -> Elem[0] || b_nx -> key -> Elem[0] < b -> key -> Elem[0] )
		{
			MistakeArray[j] = b -> key -> Elem[0] ;
			j++;
		}
	b_pr = b_pr -> next;		
	b_nx = b_nx -> next;
	b = b-> next;
	}
}

template <class T>
void List<T>::sysinfo()
{ 
	for ( int i = 0; i < 78; ++i) cout << char(95);
	cout << "\nMethod: " << NameSort << "\n"\
	<<"Elems: " << countElem << endl;
		
	CheckList();
	
	cout << "Time: " << ((float)t) / CLOCKS_PER_SEC << " ms";
	
		cout << "\tIter: " << c ;
		cout << "\tEqil: " << e ;
		cout << "\tSwap: " << s ;
		cout << "\tSum Oper: " << c+e+s <<endl;
		
	/*	
	cout << "\n--Sizeof--" <<endl;
	cout << "*Begin:\t" << sizeof(*Begin) <<endl;
	cout << "*End:\t" << sizeof(*End) <<endl;
	cout << "*Temp:\t" << sizeof(*Temp) <<endl;
	cout << "*Curr:\t" << sizeof(*Curr) <<endl;
	*/
	if(Curr || Curr != NULL)
	cout << "temp " << Curr -> key -> Elem[0] <<endl;
	
	if( countMistake )
	{
	cout << "Mistakes: " << countMistake << " Elements: ";
	for ( int i = 0; i < countMistake; ++i)
		cout << MistakeArray[i] << "|" ;
	cout << endl;
	}
delete[]NameSort;
}

#endif
