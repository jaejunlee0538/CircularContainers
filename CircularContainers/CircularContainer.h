#ifndef CIRCULAR_CONTAINER_H_
#define CIRCULAR_CONTAINER_H_
#if defined(WIN32)
#include <stdint.h>
#else
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#endif
template <typename T, int Capacity>
class CircularContainer{
public:
	CircularContainer(){
		clear();
	}

	~CircularContainer(){

	}

	bool empty() const{
		return size() == 0;
	}

	void clear(){
		tail = -1;
		head = 0;
	}

	/*
	number of active elements.
	*/
	size_t size() const{
		if (tail < 0)			return 0;//empty
		else if (head > tail)	return head - tail;
		else					return Capacity - tail + head;
	}

	/*
	number of space available.
	*/
	size_t capacity() const{
		return Capacity - size();
	}

	/*
	total capacity.
	*/
	size_t max_length() const{
		return Capacity;
	}

	/*
	add or remove active elements.
	newly activated elements are not initialized.
	*/
	void resize(const size_t& new_len) {
		if (new_len == 0){
			clear();
			return;
		}
		size_t sz = size();
		if (new_len > Capacity){
			//new_len is greater than Capacity.
			//do nothing.
			return;
		}
		if (tail < 0)//when this is empty.
			tail = 0;
		head = tail + new_len;
		if (head >= Capacity)
			head %= Capacity;
	}

	/*
	make sure this is not empty.
	*/
	const T& front() const{
		return buffer[tail];
	}

	/*
	make sure this is not empty.
	*/
	T& front(){
		return buffer[tail];
	}

	/*
	make sure this is not empty.
	*/
	const T& back() const{
		int idx = head - 1;
		if (idx < 0)	idx = Capacity - 1;
		return buffer[idx];
	}

	/*
	make sure this is not empty.
	*/
	T& back(){
		int idx = head - 1;
		if (idx < 0)	idx = Capacity - 1;
		return buffer[idx];
	}

	void pop_front(){
		if (empty())//if empty, do nothing.
			return;
		if (++tail >= Capacity)
			tail %= Capacity;
		if (tail == head)
			clear();
	}

	void pop_back(){
		if (empty())//if empty, do nothing.
			return;
		if (--head < 0)
			head = Capacity - 1;
		if (head == tail) //now buffer is empty
			clear();
	}

	void push_back(const T& val){
		//if container is full, do nothing.
		if (capacity()){
			buffer[head] = val;
			if (empty())
				tail = head;
			if (++head >= Capacity)
				head %= Capacity;
		}
	}

	void push_front(const T& val){
		//if container is full, do nothing.
		if (capacity()){
			if (--tail < 0)
				tail = Capacity - 1;
			buffer[tail] = val;
		}
	}

	/*
	erase 'idx'-th element.
	*/
	void erase(const size_t& idx){
		if (idx >= size())//out-of-range!
			return;//do nothing.
		for (size_t i = idx; i < size() - 1; i++){
			at(i) = at(i + 1);
		}
		pop_back();
	}

	/*
	erase 'idx_begin'-th and 'idx_end'-th elements and other elements between them.
	*/
	void erase(const size_t& idx_begin, const size_t& idx_end){
		if (idx_begin > idx_end //invalid arguments
			|| idx_begin >= size())//out-of-range 
			return; //do nothing.
		size_t tgt = idx_begin;
		for (size_t i = idx_end + 1; i < size(); i++){
			at(tgt++) = at(i);
		}
		for (size_t i = idx_begin; i <= idx_end; i++){
			pop_back();
		}
	}

	/*
	Accessing 'idx'-th element counting from the 'tail'.
	calling with 'idx' greater than size() is undefined.
	*/
	T& at(const size_t& idx){
		size_t i = tail + idx;
		if (i >= Capacity)
			i %= Capacity;
		return buffer[i];
	}

	/*
	Accessing 'idx'-th element counting from the 'tail'.
	calling with 'idx' greater than size() is undefined.
	*/
	const T& at(const size_t& idx) const{
		size_t i = tail + idx;
		if (i >= Capacity)
			i %= Capacity;
		return buffer[i];
	}
private:
	T buffer[Capacity];
	int head;
	int tail;
};
#endif