#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <array>
#include <fstream>

#define COURSES_CSV "courses.csv"

using namespace std;

typedef vector<string> TimeTable;
typedef vector<TimeTable> Day;
typedef vector<Day> Week;

enum DAYS {SAT, SUN, MON, TUE, WED, THU, FRI};

struct courseInfo {
	string id;
	string group;
	vector<int> days;
	vector<pair<int, int>> times;
};


pair<string, string> seperateIDnAlias(string str);
map<string, string> createCourseList();
void addCoursesToWeek(const map<string, string>& coursesNames, const map<string, int>& days_of_week, Week& week);
pair<int, int> whichTimeRange(string time);
courseInfo createCourse(string line, const map<string, int>& days_of_week);
vector<string> tokenize(string line);
void addCourseToDay(Day& day, const pair<int, int>& timeRange, string courseName);
void addNewTableToDay(Day& day);
bool canCourseBeAdded(const TimeTable& table, int start, int end);
void addCourseToTable(TimeTable& table, int start, int end, string courseName);


int main() {
	map<string, int> days_of_week = {{"SAT", SAT}, {"SUN", SUN}, {"MON", MON}, {"TUE", TUE}, {"WED", WED}, {"THU", THU}, {"FRI", FRI}};
	map<string, string> coursesNames = createCourseList();
	Week week(7);
	addCoursesToWeek(coursesNames, days_of_week, week);
	cout << week[SUN][1][7] << endl;
	return 0;
}

pair<string, string> seperateIDnAlias(string str) {
	int comma_index = str.find(',');
	string id = str.substr(0, comma_index);
	string alias = str.substr(comma_index + 1, str.length() - 1);
	return{ id, alias };
}

map<string, string> createCourseList() {
	map<string, string> courses;
	ifstream file;
	file.open(COURSES_CSV);
	if (!file.good())
		return{};
	string line;
	getline(file, line);
	while (getline(file, line))
		courses.insert(seperateIDnAlias(line));
	file.close();
	return courses;
}

courseInfo createCourse(string line, const map<string, int>& days_of_week) {
	vector<string> tokenizedLine = tokenize(line);
	courseInfo newCourse;
	int numOfDays = (tokenizedLine.size() - 1) / 2;
	newCourse.id = tokenizedLine[0].substr(0, 7);
	newCourse.group = tokenizedLine[0].substr(9, 1);
	int lineIndex = 1;
	for (int i = 0; i < numOfDays; i++) {
		newCourse.days.push_back(days_of_week.at(tokenizedLine[lineIndex++]));
		newCourse.times.push_back(whichTimeRange(tokenizedLine[lineIndex++]));
	}
	return newCourse;
}

void addCoursesToWeek(const map<string, string>& coursesNames, const map<string, int>& days_of_week, Week& week) {
	string input;
	while (getline(cin, input)) {
		courseInfo newCourse = createCourse(input, days_of_week);
		string courseName = coursesNames.at(newCourse.id) + " (" + newCourse.group + ")";
		for (int dayNO = 0; dayNO < newCourse.days.size(); dayNO++)
			addCourseToDay(week[newCourse.days[dayNO]], newCourse.times[dayNO], courseName);
	}
}

void addCourseToDay(Day& day, const pair<int, int>& timeRange, string courseName) {
	if (day.empty()) 
		addNewTableToDay(day);
	for (int tableNO = day.size() - 1; tableNO >= 0; tableNO--) {
		if (canCourseBeAdded(day[tableNO], timeRange.first, timeRange.second)) {
			addCourseToTable(day[tableNO], timeRange.first, timeRange.second, courseName);
			return;
		}
	}
	addNewTableToDay(day);
	addCourseToTable(day[day.size() - 1], timeRange.first, timeRange.second, courseName);
}

void addCourseToTable(TimeTable& table, int start, int end, string courseName) {
	for (int dayPiece = start; dayPiece <= end; dayPiece++) {
		table[dayPiece] = courseName;
	}
}

bool canCourseBeAdded(const TimeTable& table, int start, int end) {
	for (int dayPiece = start; dayPiece <= end; dayPiece++) {
		if (table[dayPiece] != "")
			return false;
	}
	return true;
}

void addNewTableToDay(Day& day) {
	TimeTable newTable(27);
	day.push_back(newTable);
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

pair<int, int> whichTimeRange(string time) {
	int start = (stoi(time.substr(0, 2)) - 7) * 2;
	if (time[3] == '3')
		start++;
	int end = (stoi(time.substr(6, 2)) - 7) * 2 - 1;
	if (time[9] == '3')
		end++;
	return{ start, end };
}


