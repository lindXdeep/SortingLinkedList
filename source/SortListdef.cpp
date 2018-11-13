#include <iostream>
using namespace std;
#ifndef SORTLISTDEF_H
#define SORTLISTDEF_H
#include "../header/SortList.h"

template <class T>
List<T>::List()
{
	//cout<<"List Const"<<endl;
	Begin = NULL;
	End = NULL;
	Curr = NULL;
	Temp = NULL;
	countElem = 0;
	countMistake = 0;
}

template <class T>
List<T>::~List()
{ 
	cout<<"List Dictr"<<endl;
	delete Temp;
	delete[] MistakeArray;
}

template <class T>
void List<T>::PushBack( T const &add)
{ 
	countElem++;
	if(!End) 								//Если элемент не существует то создаем его
	{
		End = new Node<T>();				//создаем обнуленный временный элемент списка
		End -> prev = NULL;					//Обнуляем указатель на предыдущий
		Begin = End;
	}
	else											//Если существует то выделяем память на следующий
	{
		End -> next = new Node<T>();		//Выделим память для нового узла в указателе next
			
			Temp = End;					//Сохраним указатель на текущий во временный
			End = End -> next;		//переместим текущий на новый созданный
			End -> prev = Temp;				//а старый (т.е. 1ый) из временного присвоем к указателю prev
	}

	End -> key = new Data<T>();			//Внутри списка определим указателю key - массив
		End -> key -> Elem = new T[1];	//теперь внутри key определим указатель Elem на массив
			End -> key -> Elem[0] = add;	//теперь масив Elem внутри массива key можно инициализировать

	End -> next = NULL;					//пока что нет следующего элемента
}

template<class T>
void List<T>::PushBegin(T const &add)
{
	countElem++;
	if(!Begin) 								//Если элемент не существует то создаем его
	{
		Begin = new Node<T>();	
		End = Begin;	
	}
	else
	{
		Begin -> prev = new Node<T>();
		
			Temp = Begin;	
			Begin = Begin -> prev;
			Begin -> next = Temp;
	}
	
	 Begin -> key = new Data<T>();			//Внутри списка определим указателю key - массив
		 Begin -> key -> Elem = new T[1];	//теперь внутри key определим указатель Elem на массив
			 Begin -> key -> Elem[0] = add;	
	
	Begin -> prev = NULL;
}

template <class T>
void List<T>::PushBack(T const Arr[], int size) 
{
	int count=0;
		do{
			PushBack(Arr[count]);
		}while(count++ != size-1); 	
}

template <class T>
void List<T>::PushBegin(T const Arr[], int size) 
{
	int count=0;
		do{
			PushBegin(Arr[count]);
		}while(count++ != size-1); 	
}

template <class T>
void List<T>::PushSort(T const &ins)
{
	countElem++;
	//Вставляемый элемент списка
	Node<T>* Ins = new Node<T>();
		Ins -> key = new Data<T>();
			Ins -> key -> Elem = new T[1];
				Ins -> key -> Elem[0] = ins;
				Ins -> prev = NULL;
				Ins -> next = NULL;
				
	//Если нет ниодного элемента то вставляемый будет первым
	if(!Begin || Begin == NULL)
	{
		Ins -> next = NULL;
		Ins -> prev = NULL;
		Begin = Ins;	
		End = Ins;
	}
	//Сохраняем текущий указатель на начало списка что бы не потерять его
	Node<T>* t_b = new Node<T>();
	t_b = Begin;
	
	// Если в списке всего 1 элемент
	if(t_b -> key -> Elem[0] >= Ins -> key -> Elem[0] )
	{
		t_b -> prev = Ins;
		Ins -> next = t_b;
		Begin = Ins;
		return;
	}
	//Сделаем указатель на следующий элемент(Для удобства)
	Node<T>* t_b_nx = Begin -> next;
	
	//Проход по всем элементам и поиск соответсвия условия
	while(t_b_nx || t_b_nx != NULL)
	{
		if(t_b->key->Elem[0] < Ins->key->Elem[0] && Ins->key->Elem[0] <= t_b_nx->key->Elem[0] )
		{
			t_b -> next = Ins;
			Ins -> next = t_b_nx;
			Ins -> prev = t_b;
			t_b_nx -> prev = Ins;
			return;
		}
	t_b = t_b_nx;	//Перемещение указателей на следующий элемент
	t_b_nx = t_b_nx -> next;	
	}
	//Если ниодного соответвия не найдено добавим в конец списка
	t_b -> next = Ins;							//последнему элементу присваиваем в указатель next новый
	Ins -> next = NULL; 
	Ins -> prev = t_b;
	End = Ins;
}

template <class T>
void List<T>::PushSort(T const Arr[], int size) 
{
	int count=0;
		do{
			InsertSort(Arr[count]);
		}while(count++ != size-1); 	
}

template<class T>
void List<T>::InsertIn(T const &insert, int pos)
{
	countElem++;
	//Вставляемый элемент списка
	Node<T>* Ins = new Node<T>();
		Ins -> key = new Data<T>();
			Ins -> key -> Elem = new T[1];
				Ins -> key -> Elem[0] = insert;
				Ins -> prev = NULL;
				Ins -> next = NULL;

	int count = 0;
	Node<T>* b = Begin;
		
	while (b->next && count < pos)	//ищем элемент 
    {
    	b = b ->next;				// перемещаемся по спсику
		count++;								//счетчик
	}			
		
	if(b -> next || b -> next != NULL )							//Если этот элемент не последний
    {
		Ins -> next = b -> next; 	// то к указателю next нового элемента присоеденяем старый указетль next
		Ins -> prev = Ins -> next -> prev;
		Ins -> next -> prev = Ins;
	}   	
	else
	{
	 	Ins -> next = NULL;			    //то Следующего элемекнта нет
		Ins ->prev = b;					// а если последний  (ИНАЧЕ)
		End = Ins;
	}										
	b -> next = Ins;	
}

template<class T>
void List<T>::InsertIn(T const Arr[], int size, int pos)
{
int count=0;
	do{
		 InsertIn(Arr[count], pos++);
	}while(count++ != size-1); 		
}

template <class T>
T List<T>::PopBack()
{	
	countElem--;
	if(!End || End == NULL ){				//проверка на существование элемента 
		cout << "List is Empty" <<endl;
	exit(1);
	}	
	
	T *DelElem = new T[1];				//переменная для сохранения удаляемого значения и его возрата
	DelElem[0] = End -> key ->Elem[0];
		
	Node<T> *Nextd = new Node<T>();
	Nextd = End;
	
	End = End -> prev;
	
	if(End != NULL) 						//Если он существует  то удаляем старый ()послендний
	{
		delete Nextd;
		End ->next = NULL;
	}
	else									//Если элемент отсутсвует то удаляем и обнуляем все указатели
	{
		Begin = NULL;			//обнуляем указатели (ненльзя удалять так как потеряются основые указатели)
		End = NULL;
	}
	
	return DelElem[0];					//возврат удаленного значения
delete[] DelElem;
}

template <class T>
T List<T>::PopBegin()
{
	countElem--;
	if(!Begin || Begin == NULL){
		cout << "List is Empty" <<endl;
	exit(1);
	}
		
	T* DelElem = new T[1];
	DelElem[0] = Begin -> key -> Elem[0];
	
	Node<T> *Prevd = new Node<T>();
	Prevd = Begin;
	
	Begin = Begin -> next;
	
	if(Begin != NULL)
	{
		delete Prevd;
		Begin->prev = NULL;
	}
	else
	{
		Begin = NULL;			//обнуляем указатели (ненльзя удалять так как потеряются основые указатели)
		End = NULL;
	}
	return DelElem[0];
delete[] DelElem;
}

template <class T>
T List<T>::DeleteNth(int del)
{
	countElem--;
	if(del == 0)
	{
		return PopBegin();
	}
	else
	{
	    Data<T>* value = new Data<T>();
			value -> Elem = new T[1];			
				value -> Elem[0] = GetNth(del);
		
		if(Curr -> next == NULL)
		{
			delete value;
			return PopBack();
		}
			
		Node<T>* PreEle = Curr -> prev;
		Node<T>* PosEle = Curr -> next;
				
		PreEle -> next = Curr -> next;
		PosEle -> prev = PreEle; 
	
	return value -> Elem[0];
	}
	
}

template <class T>
void List<T>::DeleteVal(T const &del)
{
	if(Begin == NULL) return;				//Если список пуст то выходим из функции
	
	Node<T>* b = Begin;					// Создадим новый указатель что бы не потерять указатель на начало.

	//1-ый вариант: Если список не пустой удаляем первый элемент если он совпдает с del
	if(b -> key -> Elem[0] == del)		//Если первый элемент равен del
	{
		if(b -> next != NULL)
		{
			Begin = b -> next;		//Если мы удаляем НАЧАЛО то begin надо передвинуть вперед
			Begin -> prev = NULL;	
		}
			Begin = NULL;
	return;// Освобождаем память для первого элемента
	}

	//2-ый вариант: Если список не пустой и не равен началу то проходим весь список
	Node<T>* b_nx = b->next;		//Создадим указатель указывающий на следующий элнмнт
	
	while (b_nx)
    {
    	if (b_nx -> key -> Elem[0] == del)	//Находим совпадающий элемент
		{										// Что бы не удалить адрес списка по которому мы получаем к нему доступ	
			b -> next = b_nx -> next; 		//для этого надо найти два рядомстоящих элемента и их соеденить
			
			if(b -> next == NULL)             //Если следующий элемент NULL 
			{
				End = b;						//Тогда устанавливем его как последний  и выход из цикла
				return;
			}
					
			b_nx -> next -> prev = b;			// Если следующий элемент существует то связывем его с пред-предыцдущим
			delete b_nx;					    //и удаляем элемент указатель next  которого присоеденили к begin
		return;
		}
		
		b = b_nx;								// Перемещаем текущий указатель на последний элемент 
		b_nx = b_nx -> next; 		 
	}
}

template<class T>
int List<T>::Search(T const &srch)
{
	Data<T>* Search = new Data<T>();
		Search -> Elem = new T[1];
		     Search -> Elem[0] = srch;
			
	Node<T>* b = Begin;
	if(b || b != NULL)
	{
		int t=0;
		while(b)
		{
			if(b -> key -> Elem[0] == Search->Elem[0])
			{
				//Curr = b;
				return t;
			}
		t++;
		b = b -> next;
		};
	}
		delete []Search;
	delete b;
return 0;
}

template<class T>
T List<T>::GetNth(int g)
{
	Node<T>* b = Begin;
	if(b || b != NULL)
	{
		int t=0;
		while(b)
		{
			if(t == g)
			{
				Curr = b;
				return b -> key -> Elem[0];
			}	
				
		t++;
		b = b -> next;
		};
	}
	delete b;
return 0;
}

template <class T>
void List<T>::ShowAll(int Par)
{ 
	Node<T> *p;
	
	if(Par > 0){
		p = End;
		cout << "(End): ";
	} 
	else{
		p = Begin;
		cout << "(Begin): ";
	}

	if(p)
	{
		while(p != NULL)
		{
			cout << p -> key -> Elem[0] << "->";
			Par > 0	 ? 	p = p -> prev 	: 	p = p -> next;
		};
		Par > 0 ? cout << "NULL :(Begin)" << endl : cout << "NULL :(End)" << endl;
	}
	else
	{
		cout << "Element not found or Out of values" << endl;
			exit(1);
		return;
	}
	delete p;
}

template <typename X> 
ostream &operator<<(ostream &stream, List<X> &x)
{
	Node<X> *p = new Node<X>();
	p = x.Begin;
	if(p)
	{
		cout << "(Begin): ";
		while(p != NULL)
		{
			stream << p -> key -> Elem[0] << "->";
			p = p -> next;
		};
		stream << "NULL :(End)" << endl;
	}
	else
	{
		stream << "Element not found or Out of values" << endl;
			exit(1);
	}
	delete p;
    return stream; 
}

template <class T> 
void List<T>::Free()	//Освобождение памяти 
{
	if(Begin == 0) return; //если спсиок пуст то удалять нечего
	
	//Если не пуст
	Node<T>* p	= Begin;			// В *p мы сохраняем оригинальный указатель что бы не потерять доступ к списку
	Node<T>* DelTemp;					// Указатель в которым мы будем удалять элементы что бы не затиреть оригинальный(передвигающийся)

	while (p)
    {
    	DelTemp = p;						  //Присвоем к удаляемому указателю оригинальный для удаления элементов
		p  = p -> next;			 	 //Проходимся поэлементно удаляя каждый пока не достигним NULL
		delete DelTemp; 				 //temp достигнув конца удалится тоже, но мы указатель для доступа к списку сохранили в p
    }

	Begin = NULL;						//оставшуюмуся пустому begin присвоим NULL что бы show мог остановиться 
	delete Begin;
delete p;
}

#endif









