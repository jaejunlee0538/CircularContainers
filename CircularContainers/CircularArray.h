#ifndef CIRCULAR_ARRAY_H_
#define CIRCULAR_ARRAY_H_
#include "CircularContainer.h"
template <typename T, int Capacity>
class CircularArray{
public:
	CircularArray(){
		_buffer.resize(Capacity);
	}

	size_t size() const{
		return _buffer.size();
	}

	void fill(const T& val){
		for(size_t i=0;i<Capacity;i++){
			at(i) = val;
		}
	}

	/*
	make sure index 'i' is in range of [0,this->size()) .
	*/
	T& at(const size_t& i){
		return _buffer.at(i);
	}
	
	/*
	make sure index 'i' is in range of [0,this->size()) .
	*/
	const T& at(const size_t& i) const{
		return _buffer.at(i);
	}

	/*
	make sure index 'i' is in range of [0,this->size()) .
	*/
	T& operator[](const size_t& i){
		return _buffer.at(i);
	}

	/*
	make sure index 'i' is in range of [0,this->size()) .
	*/
	const T& operator[](const size_t& i) const{
		return _buffer.at(i);
	}

	T& front(){
		return _buffer.front();
	}

	const T& front() const{
		return _buffer.front();
	}

	T& back() {
		return _buffer.back();
	}

	const T& back() const{
		return _buffer.back();
	}
private:
	CircularContainer<T, Capacity> _buffer;
};
#endif
