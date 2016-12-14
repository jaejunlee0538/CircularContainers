#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_
#include "CircularContainer.h"

template <typename T, int Capacity>
class CircularQueue{
public:
	void push(const T& val){
		_buffer.push_back(val);
	}

	void pop(){
		_buffer.pop_front();
	}

	void clear(){
		_buffer.clear();
	}

	bool empty() const{
		return _buffer.empty();
	}

	size_t size() const{
		return _buffer.size();
	}

	size_t capacity() const{
		return _buffer.capacity();
	}

	T& front(){
		return _buffer.front();
	}

	const T& front() const{
		return _buffer.front();
	}

	T& back(){
		return _buffer.back();
	}

	const T& back() const{
		return _buffer.back();
	}
private:
	CircularContainer<T, Capacity> _buffer;
};


#endif