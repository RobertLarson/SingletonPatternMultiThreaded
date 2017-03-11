/*
 * Singleton.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: Robert Larson
 */

#include "Singleton.h"

Singleton * Singleton::instance = 0;
std::mutex Singleton::mutex;

Singleton::Singleton() {
}

Singleton::~Singleton() {
}

Singleton * Singleton::GetInstance()
{
	std::lock_guard<std::mutex> guard(mutex);
	if(instance == 0)
	{
		instance = new Singleton();
	}

	return instance;
}
