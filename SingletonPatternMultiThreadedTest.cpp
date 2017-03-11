/*
 * SingletonPatternMultiThreadedTest.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: Robert Larson
 */

#include "Singleton.h"

#include <iostream>
#include <thread>
#include <mutex>

std::mutex g_mutex;

void useSingleton()
{
	Singleton * singleton = Singleton::GetInstance();

	std::lock_guard<std::mutex> guard(g_mutex);
	std::cout << "Singleton address : " << singleton << "\n";
}

int main()
{
	std::thread thread1(useSingleton);
	std::thread thread2(useSingleton);

	thread1.join();
	thread2.join();

	return 0;
}

