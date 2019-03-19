#include <iostream>
#include <vector>
#include <string>

#include "Process.h"
#include "CPU.h"
#include "Core.h"
#include "Thread.h"

#define COMMAND 0
#define ADD_CORE "add_core"
#define SHOW_CORES_STAT "show_cores_stat"
#define RUN_CORES "run_cores"
#define FINISH_TASKS "finish_tasks"
#define ADD_PROCESS "add_process"

using namespace std;

vector<string> tokenize(string line);
vector<int> createTimeSliceVector(vector<string> input);

int main() {
	CPU cpu;
	string input;
	int lastProcessID = 0;
	while (getline(cin, input)) {
		vector<string> tokenizedInput = tokenize(input);
		if (tokenizedInput[COMMAND] == ADD_CORE)
			cpu.addCore();
		else if (tokenizedInput[COMMAND] == SHOW_CORES_STAT)
			cpu.showCoresStat();
		else if (tokenizedInput[COMMAND] == RUN_CORES)
			cpu.runCores();
		else if (tokenizedInput[COMMAND] == FINISH_TASKS)
			cpu.finishTasks();
		else if (tokenizedInput[COMMAND] == ADD_PROCESS) 
			cpu.addProcess(createTimeSliceVector(tokenizedInput));
	}
	return 0;
}

vector<int> createTimeSliceVector(vector<string> input) {
	vector<int> timeSlices;
	for (int i = 2; i < input.size(); i++)
		timeSlices.push_back(stoi(input[i]));
	return timeSlices;
}

vector<string> tokenize(string line) {
	vector<string> sliced;
	int spaceIndex = 0;
	int currIndex = 0;
	while (line.find(' ', currIndex) != string::npos) {
		spaceIndex = line.find(' ', spaceIndex + 1);
		sliced.push_back(line.substr(currIndex, spaceIndex - currIndex));
		currIndex = spaceIndex + 1;
	}
	sliced.push_back(line.substr(currIndex));
	return sliced;
}