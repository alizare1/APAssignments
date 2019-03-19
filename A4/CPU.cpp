#include <iostream>
#include <vector>
#include <algorithm>

#include "CPU.h"
#include "Core.h"
#include "Thread.h"

using namespace std;

void CPU::addCore() {
	Core* newCore = new Core(getLastCoreID() + 1, this);
	cores.push_back(newCore);
}

int CPU::getLastProcessID() {
	if (processes.size() == 0)
		return 0;
	return processes[processes.size() - 1]->getID();
}

void CPU::addProcess(vector<int> timeSlices) {
	Process* process = new Process(getLastProcessID() + 1, timeSlices, this);
	processes.push_back(process);
}

void CPU::addThread(Thread* thread) {
	Core* core = whichCoreToAdd();
	core->addThread(thread);
}

Core* CPU::whichCoreToAdd() {
	Core* minCore = cores[0];
	for (int i = 1; i < cores.size(); i++) {
		if (cores[i]->getThreadsCount() < minCore->getThreadsCount())
			minCore = cores[i];
	}
	return minCore;
}

void CPU::showCoresStat() {
	for (int i = 0; i < cores.size(); i++)
		cores[i]->printThreadsInfo();
}

void CPU::runCores() {
	for (int i = 0; i < cores.size(); i++) {
		cores[i]->run();
	}
}

bool CPU::areTasksFinished() {
	for (int i = 0; i < cores.size(); i++) {
		if (!cores[i]->isCoreDone())
			return false;
	}
	return true;
}

void CPU::finishTasks() {
	int i = 1;
	while (!areTasksFinished()) {
		cout << "Time Slice : " << i << endl;
		runCores();
		i++;
	}
}

void CPU::removeProcess(Process* process) {
	processes.erase(remove(processes.begin(), processes.end(), process), processes.end());
}

