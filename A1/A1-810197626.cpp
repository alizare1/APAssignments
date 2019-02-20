#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<string> getInput();
vector<string> compile(vector<string> program);
vector<string> splitLine(string line);
int eval(vector<string> exp, map<string, int> vars);
vector<string> createEvalVec(vector<string> vector);
void throwSyntaxErr(int i_line);
void printOutput(vector<string> output);
bool checkVarName(string var_name);
bool isInt(string str);


int main() {
	vector<string> program;
	vector<string> output;
	program = getInput();
	output = compile(program);
	printOutput(output);
	return 0;
}

vector<string> getInput() {
	vector<string> program;
	string input;
	while (getline(cin, input)) {
		if (input == "run") {
			program.push_back("__RUN__");
			continue;
		}
		program.push_back(input);
	}
	return program;
}

vector<string> compile(vector<string> program) {
	map<string, int> vars;
	vector<string> output;
	int input_index = distance(program.begin(), find(program.begin(), program.end(), "__RUN__")) + 1;
	for (int i = 0; program[i] != "__RUN__"; i++) {
		vector<string> split_line = splitLine(program[i]);
		if (split_line.empty())
			continue;
		else if (program[i][0] == '?') {
			if (!checkVarName(split_line[0]))
				throwSyntaxErr(i);
			if (input_index == program.size()) {
				output.push_back("Unexpected end of input");
				return output;
			}
			else 
				vars.insert(pair<string, int>(split_line[0], stoi(program[input_index++])));
		}
		else if (program[i][0] == '!') {
			if (!checkVarName(split_line[0]))
				throwSyntaxErr(i);
			if (vars.find(split_line[0]) != vars.end())
				output.push_back(to_string(vars.find(split_line[0])->second));
			else
				output.push_back("0");
		}
		else if (split_line.size() > 2 && split_line[1] == "=") {
			if (!checkVarName(split_line[0]))
				throwSyntaxErr(i);
			int evaled_value = eval(createEvalVec(split_line), vars);
			if (evaled_value == -99)
				throwSyntaxErr(i);
			else if (vars.find(split_line[0]) != vars.end())
				vars.find(split_line[0])->second = evaled_value;
			else
				vars.insert(pair<string, int>(split_line[0], evaled_value));
		}
		else
			throwSyntaxErr(i);
	}
	return output;
}

vector<string> splitLine(string line) {
	vector<string> split;
	string part = "";
	for (int i = 0; i < line.length(); i++) {
		if (line[i] != ' ' && !(i == 0 && (line[i] == '!' || line[i] == '?')))
			part += line[i];
		if (part != "" && (line[i] == ' ' || i == line.length() - 1)) {
			split.push_back(part);
			part = "";
		}
	}
	return split;
}

int eval(vector<string> exp, map<string, int> vars) {
	int result = 0;
	string op_code = "+";
	int value = 0;
	if (exp.size() != 1 && exp.size() % 2 == 0)
		return -99;
	for (int i = 0; i < exp.size(); i += 2) {
		if (checkVarName(exp[i])) {
			if (vars.find(exp[i]) != vars.end())
				value = vars.find(exp[i])->second;
			else 
				value = 0;
		}
		else if (isInt(exp[i]))
				value = stoi(exp[i]);
		else
			return -99;
		if (value < 0)
			return -99;
		if (op_code == "+")
			result += value;
		else if (op_code == "-")
			result -= value;
		else
			return -99;
		if (i < exp.size() - 1)
			op_code = exp[i + 1];
	}
	return result;
}

vector<string> createEvalVec(vector<string> line_of_code) {
	int i = 0;
	while (line_of_code[i++] != "=");
	vector<string> eval_vector;
	for (i; i < line_of_code.size(); i++)
		eval_vector.push_back(line_of_code[i]);
	return eval_vector;
}

void throwSyntaxErr(int i_line) {
	cout << "Syntax error at line " << i_line + 1 << endl;
	exit(0);
}

void printOutput(vector<string> output) {
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << endl;
}

bool checkVarName(string var_name) {
	if (!isalpha(var_name[0]))
		return false;
	for(int i = 1; i < var_name.length(); i++){
		if (!isalnum(var_name[i]))
			return false;
	}
	return true;
}

bool isInt(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}