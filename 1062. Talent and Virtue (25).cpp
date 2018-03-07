/*
* Problem: 1062. Talent and Virtue (25)
* Author: HQ
* Time: 2018-03-07
* State: Done
* Memo:
*/
#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

struct Person {
	string num;
	int virtue;
	int talent;
	int total;
	int level;
};
int N, L, H;
vector<Person> person;
vector<Person> sage;
vector<Person> nobleman;
vector<Person> foolman;
vector<Person> others;

int cmp(const Person &a, const Person &b) {
	if (a.level != b.level)
		return a.level > b.level;
	if (a.total != b.total)
		return a.total > b.total;
	if (a.virtue != b.virtue)
		return a.virtue > b.virtue;
	return a.num < b.num;
}

int main() {
	cin >> N >> L >> H;
	for (int i = 0; i < N; i++) {
		Person temp;
		cin >> temp.num >> temp.virtue >> temp.talent;
		if (temp.virtue < L || temp.talent < L)
			continue;
		else {
			temp.total = temp.virtue + temp.talent;
			if (temp.virtue >= H && temp.talent >= H)
				temp.level = 4;
			else if (temp.virtue >= H && temp.talent < H)
				temp.level = 3;
			else if (temp.virtue < H && temp.talent < H && temp.virtue >= temp.talent)
				temp.level = 2;
			else
				temp.level = 1;
			person.push_back(temp);
		}
	}
	//cout << person.begin() << person.end();

	sort(person.begin(), person.end(), cmp);
	cout << person.size() << endl;
	for (int i = 0; i < person.size(); i++) {
		cout << person[i].num << " " << person[i].virtue << " " << person[i].talent << endl;
	}
	system("pause");
}