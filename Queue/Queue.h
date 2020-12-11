#pragma once
#include<iostream>
template <class T>
class TQueue
{
private:
	int MaxSize, Size, head, tail;
	T* mas;
public:
	TQueue (int s=10);
	TQueue(const TQueue<T>& qu);
	~TQueue();
	TQueue<T>& operator = (const TQueue<T>& qu);
	bool operator == (const TQueue<T>& qu) const;
    bool operator != (const TQueue<T>& qu) const;
	int GetSize() { return Size; }
	int GetMaxSize() { return MaxSize; }
	bool Empty() const;
	bool Full() const;
	void Push(const T elem);
	T SeeHead() const;
	T GetHead();
	T GetNumberHead() { return head; }
};
template<class T>
TQueue<T>::TQueue(int s)
{
	if (s <= 0)
		throw s;
	MaxSize = s;
	Size = 0;
	head = 0;
	tail = MaxSize - 1;
	mas = new T [MaxSize];
	for (int i = 0; i < s; i++)
		mas[i] = 0;
}
template <class T>
TQueue<T>::TQueue(const TQueue<T>& qu)
{
		MaxSize = qu.MaxSize;
		mas = new T[MaxSize];
		Size = qu.Size;
		head = qu.head;
		tail = qu.tail;
		int tmp = head, tmp_size=0;
		while (tmp_size != Size)
		{
			mas[tmp] = qu.mas[tmp];
			tmp = (tmp+1) % MaxSize;
			tmp_size++;
		}
}
template <class T>
TQueue<T>::~TQueue()
{
	delete[]mas;
}
template <class T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T>& qu)
{
	if (this != &qu)
	{
		if (MaxSize != qu.MaxSize)
		{
			MaxSize = qu.MaxSize;
			delete[]mas;
			mas = new T[MaxSize];
		}
		Size = qu.Size;
		head = qu.head;
		tail = qu.tail;
		int tmp = head, tmp_size = 0;
		while (tmp_size != Size)
		{
			mas[tmp] = qu.mas[tmp];
			tmp = (tmp+1) % MaxSize;
			tmp_size++;
		}
	}
	return (*this);
}
template<class T>
bool TQueue<T>::operator==(const TQueue<T>& qu) const
{
	if (this != &qu)
	{
		if (MaxSize != qu.MaxSize || Size!= qu.Size)
		{
			return false;
		}
		int tmp = head, qtmp=qu.head, tmp_size = 0;
		while (tmp_size != Size)
		{
			if (mas[tmp] != qu.mas[qtmp])
			{
				return false;
			}
			tmp = (tmp + 1) % MaxSize;
			qtmp = (qtmp + 1) % MaxSize;
			tmp_size++;
		}
	}
	return true;
} 
template<class T>
bool TQueue<T>::operator!=(const TQueue<T>& qu) const
{
	return (!(*this == qu));
}
template<class T>
bool TQueue<T>::Empty() const
{
	if (Size == 0)
		return true;
	return false;
}
template<class T>
bool TQueue<T>::Full() const
{
	if (Size == MaxSize)
		return true;
	return false;
}
template <class T>
void TQueue<T>::Push(const T elem)
{
	if (Size==MaxSize)
		throw Size;
	Size++;
	tail = (tail + 1) % MaxSize;
	mas[tail] = elem;
}
template<class T>
T TQueue<T>::SeeHead() const
{
	if (Size==0)
		throw Size;
	return mas[head];
}
template<class T>
T TQueue<T>::GetHead() 
{
	if (Size == 0)
		throw Size;
	Size--;
	head = (head + 1) % MaxSize;
	if (head == 0)
		return mas[MaxSize - 1];
	return mas[head - 1];
}
