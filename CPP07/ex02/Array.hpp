#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
 public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	~Array();
	Array<T> &operator=(const Array &rhs);
	T &operator[](size_t idx);
	const T &operator[](size_t idx) const;
	unsigned int size() const;
 private:
	unsigned int size_;
	T *arr_;

};

template <typename T>
Array<T>::Array() : size_(0), arr_(NULL) {
	try {
		arr_ = new T[size_]();
	} catch (const std::bad_alloc &e) {
		throw;
	}
}

template <typename T>
Array<T>::Array(unsigned int n) : size_(0), arr_(NULL) {
	try {
		arr_ = new T[n]();
	} catch (const std::bad_alloc &e) {
		throw;
	}
	size_ = n;
}

template <typename T>
Array<T>::Array(const Array &other) : size_(0), arr_(NULL) {
	try {
		arr_ = new T[other.size()]();
	} catch (const std::bad_alloc &e) {
		throw;
	}
	size_ = other.size();
	for (size_t i = 0; i < size_; ++i) {
		arr_[i] = other.arr_[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] arr_;
	arr_ = NULL;
	size_ = 0;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
	if (this == &rhs) {
		return *this;
	}

	T *tmp;
	try {
		tmp = new T[rhs.size()]();
	} catch (const std::bad_alloc &e) {
		throw;
	}

	delete[] arr_;
	arr_ = tmp;
	size_ = rhs.size();
	for (size_t i = 0; i < size_; ++i) {
		arr_[i] = rhs.arr_[i];
	}
	return *this;
}

template<typename T>
const T &Array<T>::operator[](size_t idx) const {
	if (size() <= idx || !arr_) {
		throw std::out_of_range( "[Error] Index out of range" );
	}
	return arr_[idx];
}

template <typename T>
T &Array<T>::operator[](size_t idx){
	if (size() <= idx || !arr_) {
		throw std::out_of_range( "[Error] Index out of range" );
	}
	return arr_[idx];
}


template <typename T>
unsigned int Array<T>::size() const { return size_; }
#endif
 