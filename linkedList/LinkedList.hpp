/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	if (m_front == nullptr){
		return(0);
	}
	else{
		Node<T>* temp = m_front;
		int size = 1;
		while(temp->getNext() != nullptr){
			temp = temp->getNext();
			size = size+1;
		}
		return(size);
	}
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	if (temp == nullptr){
		return(false);
	}
	else{
		for(int i = 1; i <= m_size; i++){
			if (temp->getValue() == value){
			return(true);
			}
			temp = temp->getNext();
		}
	}

	return(false);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* temp = m_front;
	Node<T>* lastNode = nullptr;

	if (temp == nullptr){
		return(false);
	}
	if(m_size == 1)
	{
		delete m_front;
		m_front = nullptr;
		m_size = 0;
	}
	else{
		while(temp->getNext() != nullptr){
			lastNode = temp;
			temp = temp->getNext();
		}
		delete temp;
		lastNode->setNext(nullptr);
		m_size--;
		return(true);
	}
	return(true);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
