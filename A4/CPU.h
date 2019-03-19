#ifndef CPU_H
#define CPU_H

#include <vector>

#include "Process.h"

using namespace std;

class Core;
class Thread;

class CPU {
public:
	int getLastCoreID() { return cores.size(); }
	void addCore();
	void addProcess(vector<int> timeSlices);
	int getLastProcessID();
	void addThread(Thread* thread);
	Core* whichCoreToAdd();
	int getCoresCount() { return cores.size(); }
	void showCoresStat();
	void runCores();
	bool areTasksFinished();
	void finishTasks();
	void removeProcess(Process* process);
private:
	vector<Core*> cores;
	vector<Process*> processes;
};

#endif 