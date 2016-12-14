#ifndef CIRCULAR_STACK_H_
#define CIRCULAR_STACK_H_
#include "CircularContainer.h"

template <typename T, int Capacity>
class CircularStack{
public:
	bool empty() const{
		return _buffer.empty();
	}

	size_t size() const{
		return _buffer.size();
	}

	size_t capacity() const{
		return _buffer.capacity();
	}

	T& top(){
		return _buffer.front();
	}

	const T& top() const{
		return _buffer.front();
	}

	void push(const T& val){
		return _buffer.push_front(val);
	}

	void pop(){
		_buffer.pop_front();
	}
private:
	CircularContainer<T, Capacity> _buffer;
};
#endif