#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <fstream>

#define DAY_PIECES 28
#define WEEK_DAYS 7
#define NOWHERE -1

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
map<string, string> createCourseList(string);
void addCoursesToWeek(const vector<string>& input, const map<string, string>& coursesNames, Week& week);
pair<int, int> whichTimeRange(string time);
courseInfo createCourse(string line, const map<string, int>& daysOfWeek);
vector<string> tokenize(string line);
void addCourseToDay(Day& day, const pair<int, int>& timeRange, string courseName);
void addNewTableToDay(Day& day);
bool canCourseBeAdded(const TimeTable& table, int start, int end);
void addCourseToTable(TimeTable& table, int start, int end, string courseName);
void printProgram(const Week&, string);
void printTimeLine();
int getLastCourseInTable(const TimeTable& table);
void printCoursesBorder(const TimeTable& table);
void printCentered(string str, int courseLength);
void printCoursesNames(const TimeTable& table);
vector<string> getInput();

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cout << "Not enough arguments!" << endl;
		exit(EXIT_FAILURE);
	}
	map<string, string> coursesNames = createCourseList(argv[1]);
	Week week(WEEK_DAYS);
	vector<string> input = getInput();
	addCoursesToWeek(input, coursesNames, week);
	printProgram(week, argv[2]);
	return 0;
}

vector<string> getInput() {
	vector<string> input;
	string inputLine;
	while (getline(cin, inputLine))
		input.push_back(inputLine);
	return input;
}

void printProgram(const Week& week, string progName){
	map<int, string> daysFullName = {
		{SAT, "Saturday"}, {SUN, "Sunday"}, {MON, "Monday"}, {TUE, "Tuesday"}, {WED, "Wednesday"}, {THU, "Thursday"}, {FRI, "Friday"}
	};
	cout << "# " << progName << endl << endl;
	for (int day = SAT; day <= FRI; day++) {
		cout << "## " << daysFullName[day] << endl << endl;
		printTimeLine();
		for (int table = 0; table < week[day].size(); table++) {
			printCoursesBorder(week[day][table]);
			printCoursesNames(week[day][table]);
			printCoursesBorder(week[day][table]);
		}
		cout << endl;
	}
}

void printTimeLine() {
	for (int h = 7; h <= 9; h++) {
		cout << '0' << h << setfill(' ') << setw(8) << left << ":00";
		cout << '0' << h << setfill(' ') << setw(8) << left << ":30";
	}
	for (int h = 10; h <= 20; h++) {
		cout << h << setfill(' ') << setw(8) << left << ":00";
		if (h == 20) {
			cout << h << ":30";
			break;
		}
		cout << h << setfill(' ') << setw(8) << left << ":30";
	}
	cout << endl;
	for (int i = 0; i < 275; i++)
		cout << '_';
	cout << endl;
}

int getLastCourseInTable(const TimeTable& table) {
	for (int dayPiece = table.size() - 1; dayPiece >= 0; dayPiece--) {
		if (table[dayPiece] != "")
			return dayPiece;
	}
	return 0;
}

void printCoursesBorder(const TimeTable& table) {
cout << setfill(' ') << setw(2) << "";
int dayPiece = 0;
while (dayPiece <= getLastCourseInTable(table)) {
	int courseLength = 0;
	string prevDayPiece;
	if (table[dayPiece] != "") {
		prevDayPiece = table[dayPiece];
		while (table[dayPiece] == prevDayPiece) {
			courseLength++;
			dayPiece++;
		}
		cout << setfill('-') << setw(10 * courseLength - 1) << left << '+' << right << '+';
	}
	else {
		cout << setfill(' ') << setw(10) << "";
		dayPiece++;
	}
}
cout << endl;
}

void printCoursesNames(const TimeTable& table) {
	cout << setfill(' ') << setw(2) << "";
	int dayPiece = 0;
	while (dayPiece <= getLastCourseInTable(table)) {
		int courseLength = 0;
		string prevDayPiece;
		if (table[dayPiece] != "") {
			prevDayPiece = table[dayPiece];
			while (table[dayPiece] == prevDayPiece) {
				courseLength++;
				dayPiece++;
			}
			printCentered(prevDayPiece, courseLength);
		}
		else {
			cout << setfill(' ') << setw(10) << "";
			dayPiece++;
		}
	}
	cout << endl;

}

void printCentered(string str, int courseLength) {
	cout << '|';
	int space = ((courseLength * 10 - 2) - str.length()) / 2;
	if (str.length() % 2 != 0)
		cout << ' ';
	cout << setw(space) << "";
	cout << setw(str.length() + space) << left << str;
	cout << '|';
}

pair<string, string> seperateIDnAlias(string str) {
	int comma_index = str.find(',');
	string id = str.substr(0, comma_index);
	string alias = str.substr(comma_index + 1);
	return{ id, alias };
}

map<string, string> createCourseList(string fileAddress) {
	map<string, string> courses;
	ifstream file;
	file.open(fileAddress);
	if (!file.good())
		return{};
	string line;
	getline(file, line);
	while (getline(file, line))
		courses.insert(seperateIDnAlias(line));
	file.close();
	return courses;
}

courseInfo createCourse(string line, const map<string, int>& daysOfWeek) {
	vector<string> tokenizedLine = tokenize(line);
	courseInfo newCourse;
	int numOfDays = (tokenizedLine.size() - 1) / 2;
	newCourse.id = tokenizedLine[0].substr(0, 7);
	if(tokenizedLine[0][8] == '0')
		newCourse.group = tokenizedLine[0].substr(9, 1);
	else
		newCourse.group = tokenizedLine[0].substr(8, 2);
	int lineIndex = 1;
	for (int i = 0; i < numOfDays; i++) {
		newCourse.days.push_back(daysOfWeek.at(tokenizedLine[lineIndex++]));
		newCourse.times.push_back(whichTimeRange(tokenizedLine[lineIndex++]));
	}
	return newCourse;
}

void addCoursesToWeek(const vector<string>& input, const map<string, string>& coursesNames, Week& week) {
	map<string, int> daysOfWeek = { { "SAT", SAT },{ "SUN", SUN },{ "MON", MON },{ "TUE", TUE },{ "WED", WED },{ "THU", THU },{ "FRI", FRI } };
	for (int line = 0; line < input.size(); line++) {
		courseInfo newCourse = createCourse(input[line], daysOfWeek);
		string courseName = coursesNames.at(newCourse.id) + " (" + newCourse.group + ")";
		for (int dayNO = 0; dayNO < newCourse.days.size(); dayNO++)
			addCourseToDay(week[newCourse.days[dayNO]], newCourse.times[dayNO], courseName);
	}
}

int findCoursePlace(const Day& day, const pair<int, int>& timeRange) {
	int table = day.size() - 1;
	while (table > 0) {
		if (canCourseBeAdded(day[table], timeRange.first, timeRange.second)) {
			if (!canCourseBeAdded(day[table - 1], timeRange.first, timeRange.second))
				return table;
		}
		else
			return NOWHERE;
		table--;
	}
	if (canCourseBeAdded(day[table], timeRange.first, timeRange.second))
		return table;
	return NOWHERE;
}

void addCourseToDay(Day& day, const pair<int, int>& timeRange, string courseName) {
	if (day.empty())
		addNewTableToDay(day);
	int table = findCoursePlace(day, timeRange);
	if(table != NOWHERE)
		addCourseToTable(day[table], timeRange.first, timeRange.second, courseName);
	else {
		addNewTableToDay(day);
		addCourseToTable(day[day.size() - 1], timeRange.first, timeRange.second, courseName);
	}
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
	TimeTable newTable(DAY_PIECES);
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
