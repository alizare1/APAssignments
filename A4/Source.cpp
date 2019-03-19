#include <iostream>
#include <vector>
#include <string>

#include "Process.h"
#include "CPU.h"
#include "Core.h"
#include "Thread.h"

#define COMMAND 0

using namespace std;

vector<string> tokenize(string line);
void addProcess(const CPU& cpu, vector<string> input, int lastID);
vector<int> createTimeSliceVector(vector<string> input);

int main() {
	CPU cpu;
	string input;
	int lastProcessID = 0;
	while (getline(cin, input)) {
		vector<string> tokenizedInput = tokenize(input);
		if (tokenizedInput[COMMAND] == "add_core")
			cpu.addCore();
		else if (tokenizedInput[COMMAND] == "show_cores_stat")
			cpu.showCoresStat();
		else if (tokenizedInput[COMMAND] == "run_cores")
			cpu.runCores();
		else if (tokenizedInput[COMMAND] == "finish_tasks")
			cpu.finishTasks();
		else if (tokenizedInput[COMMAND] == "add_process") 
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