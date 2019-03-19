#include <vector>

#ifndef PROCESS_H
#define PROCESS_H


class CPU;
class Thread;

using namespace std;


class Process {
public:
	Process(int _id, vector<int> timeslices, CPU* _cpu);
	int getID() { return id; }
	void removeThread(Thread* thread);
private:
	int id;
	CPU* cpu;
	vector<Thread*> threads;
};

#endif 