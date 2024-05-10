#pragma once

template <typename Type>
class List
{
private:
	struct Node
	{
		Type data;
		Node* prev;
		Node* next;
		Node(const Type& data = Type(), Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}
	};
	Node sentinel;
	int count;
public:
	class Iterator
	{
	private:
		friend class List;
		Node* current;
		Iterator(Node* current = nullptr) :current(current) {}
	public:
		Iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator copy(*this);
			++(*this);
			return copy;
		}
		Iterator& operator--()
		{
			current = current->prev;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator copy(*this);
			--(*this);
			return copy;
		}
		Type* operator->()
		{
			return &current->data;
		}
		Type& operator*()
		{
			return current->data;
		}
		Type& operator*() const
		{
			return current->data;
		}
		Type* operator->() const
		{
			return &current->data;
		}
		bool operator==(const Iterator& other) const
		{
			return current == other.current;
		}
		bool operator!=(const Iterator& other) const
		{
			return !(*this == other);
		}
	};

	class const_Iterator
	{
	private:
		friend class List;
		const Node* current;
		const_Iterator(const Node* current = nullptr) : current(current) {}
	public:
		const_Iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		const_Iterator operator++(int)
		{
			const_Iterator copy(*this);
			++(*this);
			return copy;
		}
		const_Iterator& operator--()
		{
			current = current->prev;
			return *this;
		}
		const_Iterator operator--(int)
		{
			const_Iterator copy(*this);
			--(*this);
			return copy;
		}
		const Type* operator->() const
		{
			return &current->data;
		}
		const Type& operator*() const
		{
			return current->data;
		}
		bool operator==(const const_Iterator& other) const
		{
			return current == other.current;
		}
		bool operator!=(const const_Iterator& other) const
		{
			return !(*this == other);
		}
	};

	List();
	List(const List<Type>& other);
	List<Type>& operator=(const List<Type>& other);
	~List();

	int size() const;
	bool empty() const;

	Iterator begin() { return Iterator(sentinel.next); }
	Iterator end() { return Iterator(&sentinel); }
	const_Iterator cbegin() const { return const_Iterator(sentinel.next); }
	const_Iterator cend() const { return const_Iterator(&sentinel); }

	void insert(Iterator it, const Type& el);
	Iterator erase(Iterator it)
	{
		it.current->prev->next = it.current->next;
		it.current->next->prev = it.current->prev;
		Iterator result(it.current->next);
		delete it.current;
		--count;
		return result;
	}
	void push_back(const Type& el);
	void push_front(const Type& el);
	void pop_back();
	void pop_front();
	void clear();
};


template<typename Type>
inline List<Type>::List()
{
	sentinel.prev = &sentinel;
	sentinel.next = &sentinel;
	count = 0;
}

template<typename Type>
inline List<Type>::List(const List<Type>& other) : List()
{
	for (const_Iterator it = other.cbegin(); it != other.cend(); ++it)
	{
		push_back(*it);
	}
}

template<typename Type>
inline List<Type>& List<Type>::operator=(const List<Type>& other)
{
	if (this != &other)
	{
		clear();
		for (const_Iterator it = other.cbegin(); it != other.cend(); ++it)
		{
			push_back(*it);
		}
	}
	return *this;
}

template<typename Type>
inline List<Type>::~List()
{
	clear();
}

template<typename Type>
inline int List<Type>::size() const
{
	return count;
}

template<typename Type>
inline bool List<Type>::empty() const
{
	return sentinel.prev == &sentinel;
}

template<typename Type>
inline void List<Type>::insert(Iterator it, const Type& el)
{
	Node* newNode = new Node(el, it.current->prev, it.current);
	newNode->prev->next = newNode;
	newNode->next->prev = newNode;
	++count;
}

template<typename Type>
inline void List<Type>::push_back(const Type& el)
{
	insert(end(), el);
}

template<typename Type>
inline void List<Type>::push_front(const Type& el)
{
	insert(begin(), el);
}

template<typename Type>
inline void List<Type>::pop_back()
{
	erase(sentinel.prev);
}

template<typename Type>
inline void List<Type>::pop_front()
{
	erase(begin());
}

template<typename Type>
inline void List<Type>::clear()
{
	while (!empty())
	{
		pop_back();
	}
}

