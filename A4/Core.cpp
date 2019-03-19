#include "Core.h"
#include <iostream>
using namespace std;

Core::Core(int _id, CPU* _cpu) : id(_id), cpu(_cpu) {
	cout << "Core with core ID = " << id << " successfully added!" << endl;
}

void Core::printThreadsInfo() {
	cout << "Core number : " << id << endl;
	for (int i = 0; i < threads.size(); i++) {
		threads[i]->printThreadInfo();
		threads[i]->printnumOfTimeSlices();
	}
}

void Core::run() {
	if (threads.size() == 0)
		return;
	cout << "Core number : " << id << endl;
	threads[0]->run();
	if (threads[0]->getTimeSlicesCount() == 0) {
		threads[0]->remove();
	}
	else 
		threads.push_back(threads[0]);
	threads.erase(threads.begin());
}

bool Core::isCoreDone() {
	if (threads.size() == 0)
		return true;
	return false;
}