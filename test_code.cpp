#include <iostream>
#include <string>
#include <windows.h>
#include "CircularContainer.h"

HANDLE hCon;
enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };
void SetColor(Color c){
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}

void ClearColor(){
	SetColor(WHITE);
}

void __PASS_UNPASS_TEXT(std::string test_name, bool is_passed){
	if (is_passed){
		SetColor(GREEN);
		std::cout << "[PASS]   :" << test_name << std::endl;
	}
	else{
		SetColor(RED);
		std::cout << "[UNPASS] :" << test_name << std::endl;
	}
}

void EXPECT_TRUE(std::string test_name, bool condition){
	__PASS_UNPASS_TEXT(test_name, condition == true);
	ClearColor();
}

void EXPECT_FALSE(std::string test_name, bool condition){
	__PASS_UNPASS_TEXT(test_name, condition == false);
	ClearColor();
}

template <typename T>
void EXPECT(std::string test_name, T expected, T actual){
	__PASS_UNPASS_TEXT(test_name, expected == actual);
	ClearColor();
	if (expected != actual){
		std::cout << "\t\t" << "Expected : " << expected << std::endl;
		std::cout << "\t\t" << "Actual : " << actual << std::endl;
	}
}

int main()
{
	CircularContainer<int, 5> container;
	/////////////////////////////////////////////////////
	EXPECT_TRUE("empty() test" ,container.empty());
	/////////////////////////////////////////////////////
	container.push_back(1);
	EXPECT_FALSE("not empty() test", container.empty());
	/////////////////////////////////////////////////////
	container.push_back(2);
	container.clear();
	EXPECT_TRUE("clear() test", container.empty());
	/////////////////////////////////////////////////////
	size_t cap = container.capacity();
	for (size_t i = 0; i < cap; i++){
		EXPECT<size_t>("size() test", container.size(), i);
		container.push_back(static_cast<int>(i));
	}
	/////////////////////////////////////////////////////
	for (size_t i = 0; i < container.size(); i++){
		EXPECT<int>("at() test", static_cast<int>(i), container.at(i));
	}
	/////////////////////////////////////////////////////
	container.resize(3);
	EXPECT<size_t>("resize(3) test", 3, container.size());
	for (size_t i = 0; i < container.size(); i++){
		EXPECT<int>("at() test", static_cast<int>(i), container.at(i));
	}

	container.resize(5);
	EXPECT<size_t>("resize(5) test", 5, container.size());
	for (size_t i = 0; i < 3; i++){
		EXPECT<int>("at() test", static_cast<int>(i), container.at(i));
	}

	container.resize(0);
	EXPECT_TRUE("resize(0) test", container.empty());
	/////////////////////////////////////////////////////
	container.resize(4);
	EXPECT_TRUE("front() text", container.front() == container.at(0));
	EXPECT_TRUE("back() text", container.back() == container.at(container.size()-1));
	/////////////////////////////////////////////////////
	container.clear();
	for (size_t i = 1; i <= 3; i++){
		container.push_back(10*i);
		EXPECT<int>("push_back() test", 10 * i, container.back());
	}
	for (size_t i = 1; i <= 2; i++){
		container.push_front(100 * i);
		EXPECT<int>("push_front() test", 100 * i, container.front());
	}
	/////////////////////////////////////////////////////
	container.clear();
	cap = container.capacity();
	for (size_t i = 0; i < cap; i++){
		container.push_back(i);
	}
	container.erase(2);
	EXPECT<size_t>("erase(size_t) test", 4, container.size());
	EXPECT<int>("erase(size_t) test", 0, container.at(0));
	EXPECT<int>("erase(size_t) test", 1, container.at(1));
	EXPECT<int>("erase(size_t) test", 3, container.at(2));
	EXPECT<int>("erase(size_t) test", 4, container.at(3));
	container.erase(0);
	EXPECT<size_t>("erase(size_t) test", 3, container.size());
	EXPECT<int>("erase(size_t) test", 1, container.at(0));
	EXPECT<int>("erase(size_t) test", 3, container.at(1));
	EXPECT<int>("erase(size_t) test", 4, container.at(2));
	container.erase(2);
	EXPECT<size_t>("erase(size_t) test", 2, container.size());
	EXPECT<int>("erase(size_t) test", 1, container.at(0));
	EXPECT<int>("erase(size_t) test", 3, container.at(1));
	/////////////////////////////////////////////////////
	container.clear();
	cap = container.capacity();
	for (size_t i = 0; i < cap; i++){
		container.push_back(i);
	}
	container.erase(1, 3);
	EXPECT<size_t>("erase(size_t,size_t) test", 2, container.size());
	EXPECT<int>("erase(size_t,size_t) test", 0, container.at(0));
	EXPECT<int>("erase(size_t,size_t) test", 4, container.at(1));
	container.erase(0, 1);
	EXPECT_TRUE("erase(size_t,size_t) test", container.empty());
	return 0;
}