#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_
#include "CircularContainer.h"

/*

*/
template <typename T, int Capacity>
class CircularBuffer {
public:
	CircularBuffer() {
		clear();
	}

	/*
	return true, if the buffer does not have any data to be read.
	*/
	bool empty() const {
		return _buffer.empty();
	}

	/*
	return true, if the buffer cannot accommodate more data.
	*/
	bool full() const {
		return _buffer.capacity() == 0;
	}

	/*
	remove all data from the buffer.
	*/
	void clear() {
		_buffer.clear();
	}

	/*
	return the number of data which should be read from the buffer.
	*/
	size_t size() const {
		return _buffer.size();
	}

	/*
	return the number of data that the buffer can accommodate without loosing data.
	*/
	size_t capacity() const {
		return _buffer.capacity();
	}

	/*
	return the oldest data and remove it from the buffer.
	make sure the buffer is not empty.
	*/
	T read() {
		T ret = _buffer.front();
		_buffer.pop_front();
		return ret;
	}

	/*
	push back 'val' into buffer.
	If the buffer is full, the oldest one is replaced.
	*/
	void write(const T& val) {
		if (full())
			_buffer.pop_front();
		_buffer.push_back(val);
	}
private:
	CircularContainer<T, Capacity> _buffer;
};
#endif