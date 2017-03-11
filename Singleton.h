/*
 * Singleton.h
 *
 *  Created on: Mar 10, 2017
 *      Author: Robert Larson
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <mutex>

class Singleton {
public:
	static Singleton * GetInstance();

private:
	Singleton();
	virtual ~Singleton();

    static Singleton * instance;

    static std::mutex mutex;
};

#endif /* SINGLETON_H_ */
