#ifndef CORE_H
#define CORE_H
#include <vector>
#include <iostream>
#include "Thread.h"
using namespace std;

class CPU;
class Thread;

class Core {
public:
	Core(int _id, CPU* _cpu);
	int getThreadsCount() { return threads.size(); }
	void addThread(Thread* thread) { threads.push_back(thread); }
	int getID() { return id; }
	void printThreadsInfo();
	void run();
	bool isCoreDone();
private:
	int id;
	vector<Thread*> threads;
	CPU* cpu;
};

#endif 