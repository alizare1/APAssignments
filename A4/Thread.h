#ifndef THREAD_H
#define THREAD_H
#include "Process.h"

class Thread {
public:
	Thread(int timeslicesNO, Process* _process, int _id)
		:numOfTimeSlices(timeslicesNO), process(_process), id(_id) {}
	void printThreadInfo();
	void printnumOfTimeSlices();
	void run();
	int getTimeSlicesCount() { return numOfTimeSlices; }
	void remove();
private:
	int id;
	int numOfTimeSlices;
	Process* process;
};

#endif