#include <iostream>
#include <vector>
#include <algorithm>

#include "Process.h"
#include "CPU.h"
#include "Thread.h"

using namespace std;

Process::Process(int _id, vector<int> timeslices, CPU* _cpu)
	: id(_id), cpu(_cpu) {
	if (cpu->getCoresCount() == 0) {
		cout << "Error: No Cores" << endl;
		abort();
	}
	for (int i = 0; i < timeslices.size(); i++) {
		if (timeslices[i] == 0)
			continue;
		Thread* newThread = new Thread(timeslices[i], this, i + 1);
		threads.push_back(newThread);
		cpu->addThread(newThread);
	}
	cout << "Process with pid = " << id << " added!" << endl;
}

void Process::removeThread(Thread* thread) {
	threads.erase(remove(threads.begin(), threads.end(), thread), threads.end());
	if (threads.size() == 0) {
		cpu->removeProcess(this);
		delete this;
	}
}