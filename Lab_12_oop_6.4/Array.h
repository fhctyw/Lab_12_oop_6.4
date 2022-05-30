#include <iostream>
#include <string>
using namespace std;

template<class T>
struct elem
{
	string key;
	T value;
};

template <class T>
class Array
{
	elem<T>* arr;
	int size;
public:
	Array();
	Array(Array&);
	~Array();
	int Size() const { return size; };

	T& push_back(elem<T> v);
	T& operator [] (string key);
	Array& operator = (const Array&);
	friend ostream& operator << <>(ostream&, Array&);
	friend istream& operator >> <>(istream&, Array&);
};
template <class T>
Array<T>::Array()
{
	arr = new elem<T>[size = 0]();
}
template <class T>
Array<T>::Array(Array<T>& x) // конструктор копіювання
{
	arr = new elem<T>[size = x.size]; // новий розмір, виділення пам'яті для елементів
	for (int i = 0; i < size; i++) // присвоєння значень елементам
		arr[i] = x.arr[i];
}
template <class T>
Array<T>::~Array()
{
	delete[] arr; // звільнення пам'яті
}
template <class T>
Array<T>& Array<T>::operator = (const Array<T>& x)
{
	if (this != &x)
	{
		delete[] arr;
		arr = new elem<T>[size = x.size];
		for (int i = 0; i < size; i++)
			arr[i] = x.arr[i];
	}
	return *this;
}
template <class T>
istream& operator >> (istream& is, Array<T>& x)
{
	int s;
	cout << "Enter size: "; cin >> s;
	is.get();
	for (int i = 0; i < s; i++) {
		string key;
		cout << "key: "; getline(is, key);
		T v;
		cout << "value: "; is >> v;
		is.get();
		x.push_back({ key, v });
	}
	return is;
}
template <class T>
ostream& operator << (ostream& os, Array<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.arr[i].key << ": " << x.arr[i].value << endl;
	os << endl;
	return os;
}
template<class T>
T& Array<T>::push_back(elem<T> v)
{
	elem<T>* tmp = new elem<T>[size + 1];
	for (size_t i = 0; i < size; i++)
		tmp[i] = arr[i];
	tmp[size++] = v;
	delete[] arr;
	arr = tmp;
	return arr[size - 1].value;
}
template <class T>
T& Array<T>::operator [] (string key)
{
	for (size_t i = 0; i < size; i++)
	{
		if (key == arr[i].key)
			return arr[i].value;
		else
			return push_back({ key, T() });
	}
}