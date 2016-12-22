/*
 Name:		CircularContainers.ino
 Created:	12/15/2016 3:49:08 AM
 Author:	jaejunlee
*/
#include "CircularQueue.h"
#include "CircularStack.h"
#include "CircularDeque.h"
#include "CircularArray.h"
#include "CircularBuffer.h"
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	ExampleQueue();
	ExampleStack();
	ExampleDeque();
	ExampleArray();
	ExampleBuffer();
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}

void ExampleBuffer(){
	Serial.println("-------Buffer-------");
	CircularBuffer<int, 5> Buffer5;
	for(int i=0;i<5;i++){
		Serial.print("write : ");
		Serial.println(i);
		Buffer5.write(i);
	}
	Serial.print("Data : ");
	while(!Buffer5.empty()){
		Serial.print(Buffer5.read());
		Serial.print(" ");
	}
	Serial.println("");

	Serial.println("Writing data more than the capacity(5)");
	for (int i = 0; i<8; i++) {
		Serial.print("write : ");
		Serial.println(i);
		Buffer5.write(i);
	}
	Serial.print("Data : ");
	while (!Buffer5.empty()) {
		Serial.print(Buffer5.read());
		Serial.print(" ");
	}
	Serial.println("");
}

void ExampleQueue(){
	Serial.println("-------Queue-------");
	CircularQueue<int, 3> Q3;
	for (int i = 0; i < 3; i++){
		Serial.print("push : ");
		Serial.println(i);
		Q3.push(i);
	}
	while (Q3.size()){
		Serial.print("pop : ");
		Serial.println(Q3.front());
		Q3.pop();
	}
}

void ExampleStack(){
	Serial.println("-------Stack-------");
	CircularStack<int, 3> Stack3;
	for (int i = 0; i < 3; i++){
		Serial.print("push : ");
		Serial.println(i);
		Stack3.push(i);
	}
	while (Stack3.size()){
		Serial.print("pop : ");
		Serial.println(Stack3.top());
		Stack3.pop();
	}
}

void ExampleDeque(){
	Serial.println("-------Deque-------");
	CircularDeque<int, 6> Deque6;
	for (int i = 0; i < 6; i++){
		if (i % 2){
			Serial.print("push_back : ");
			Serial.println(i);
			Deque6.push_back(i);
		}
		else{
			Serial.print("push_front : ");
			Serial.println(i);
			Deque6.push_front(i);
		}
	}

	for (int i = 5; i >=0; i--){
		if (i % 2){
			Serial.print("pop_back : ");
			Serial.println(Deque6.back());
			Deque6.pop_back();
		}
		else{
			Serial.print("pop_front : ");
			Serial.println(Deque6.front());
			Deque6.pop_front();
		}
	}
}

void ExampleArray(){
	Serial.println("-------Array-------");
	CircularArray<double, 6> Array6;
	for (size_t i = 0; i < Array6.size(); i++){
		Array6[i] = i * 10.0;
	}
	for (size_t i = 0; i < Array6.size(); i++){
		Serial.print(i);
		Serial.print(" : ");
		Serial.println(Array6[i]);
	}
}