# CircularContainers
Circular Queue/Stack/Deque/Array Template Implementation for Arduino.

# Brief Overview
CircularArray/CircularDeque/CircularQueue/CircularStack are all implemented based on `CircularContainer` class.

There are 2 visual studio projects, CircularContainers and DevelCircularContainers.

**CircularContainers** project is providing simple example of how-to-use each class.

**DevelCircularContainers** project is not an Arduino project, but Windows Console Application.
It contains **testing code** for important base-class `CircularContainer`.

# Example Code
`CircularXXX<int, 10> container;` declares a container which can contains maximally **10** of `int` type data.

``` c++
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
```
