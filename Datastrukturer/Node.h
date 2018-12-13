#pragma once
template<typename...> class Node;
template<typename T, typename K>
class Node<T, K>
{
protected:
	T data;
	K key;
public:
	Node(T data, K key);
	T getData();
	K getKey();
	virtual ~Node() {};
};

template<typename T, typename K>
Node<T, K>::Node(T data, K key) {
	this->data = data;
	this->key = key;
}
template<typename T, typename K>
T Node<T, K>::getData() {
	return this->data;
}
template<typename T, typename K>
K Node<T, K>::getKey() {
	return this->key;
}
