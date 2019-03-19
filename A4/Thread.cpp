#include "Thread.h"
#include <iostream>

using namespace std;

void Thread::printThreadInfo() {
	cout << "Process ID : " << process->getID()
		<< " - Thread ID : " << id << endl;
}

void Thread::printnumOfTimeSlices() {
	cout << "Number of time slots : " << numOfTimeSlices << endl;
}

void Thread::run() {
	printThreadInfo();
	numOfTimeSlices--;
}

void Thread::remove() {
	process->removeThread(this);
	delete this;
}