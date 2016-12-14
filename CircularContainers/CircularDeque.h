#ifndef CIRCULAR_DEQUE_H_
#define CIRCULAR_DEQUE_H_
#include "CircularContainer.h"

template <typename T, int Capacity>
class CircularDeque {
public:
	CircularDeque(){
		clear();
	}

	bool empty() const{
		return _buffer.empty();
	}

	void clear(){
		_buffer.clear();
	}

	size_t size() const{
		return _buffer.size();
	}

	size_t capacity() const{
		return _buffer.capacity();
	}

	const T& front() const{
		return _buffer.front();
	}

	T& front(){
		return _buffer.front();
	}

	const T& back() const{
		return _buffer.back();
	}

	T& back(){
		return _buffer.back();
	}

	void pop_front(){
		_buffer.pop_front();
	}

	void pop_back(){
		_buffer.pop_back();
	}

	void push_back(const T& val){
		_buffer.push_back(val);
	}

	void push_front(const T& val){
		_buffer.push_front(val);
	}
private:
	CircularContainer<T, Capacity> _buffer;
};
#endif