/*
* Problem: 1111. Online Map (30)
* Author: HQ
* Time: 2018-03-10
* State: Done
* Memo: Dijkstra
*/
#include "iostream"
#include "string"
#include "vector"
#include "climits"
#include "stack"
using namespace std;

struct NodeRoute {
	int pre;
	int dis;
	int time;
};

struct Node {
	int data;
	int dis;
	int time;
};

vector<NodeRoute> dis, tim;
vector<vector<Node>> map;
vector<bool> visit;
int N, M;
int s, d;

void init() {
	cin >> N >> M;
	map.resize(N);
	int v1, v2, one, length, time;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> one >> length >> time;
		Node temp;
		temp.data = v2;
		temp.dis = length;
		temp.time = time;
		map[v1].push_back(temp);
		if (!one) {
			temp.data = v1;
			map[v2].push_back(temp);
		}
	}
	cin >> s >> d;
}

bool isgooder(int x, NodeRoute *gooder, bool DOrT) { // D:1 T:0
	if (DOrT) {
		if (dis[x].dis != gooder->dis)
			return dis[x].dis < gooder->dis;
		return dis[x].time < gooder->time;
	}
	else {
		if (tim[x].time != gooder->time)
			return tim[x].time < gooder->time;
		return tim[x].dis < gooder->dis;
	}
}

void dijD() {
	int k = s;
	dis.resize(N, { -1, INT_MAX,INT_MAX });
	dis[s] = { s,0,0 };
	visit[s] = true;
	NodeRoute *gooder;
	NodeRoute temp = { -1, INT_MAX,INT_MAX };
	for (int i = 0; i < N; i++) {
		gooder = &temp;
		for (int j = 0; j < N; j++)
			if (!visit[j] && isgooder(j, gooder, true)) {
				k = j;
				gooder = &dis[k];
			}
		visit[k] = true;
		for (int j = 0; j < map[k].size(); j++) {
			if (dis[k].dis + map[k][j].dis < dis[map[k][j].data].dis) {
				dis[map[k][j].data].pre = k;
				dis[map[k][j].data].dis = dis[k].dis + map[k][j].dis;
				dis[map[k][j].data].time = dis[k].time + map[k][j].time;
			}
			else if (dis[k].dis + map[k][j].dis == dis[map[k][j].data].dis) {
				if (dis[k].time + map[k][j].time < dis[map[k][j].data].time) {
					dis[map[k][j].data].pre = k;
					dis[map[k][j].data].dis = dis[k].dis + map[k][j].dis;
					dis[map[k][j].data].time = dis[k].time + map[k][j].time;
				}
			}
		}
	}
}
void dijT() {
	int k = s;
	tim.resize(N, { -1, INT_MAX,INT_MAX });
	tim[s] = { s,0,0 };
	visit[s] = true;
	NodeRoute *gooder;
	NodeRoute temp = { -1, INT_MAX,INT_MAX };
	for (int i = 0; i < N; i++) {
		gooder = &temp;
		for (int j = 0; j < N; j++)
			if (j != s && !visit[j] && isgooder(j, gooder, false)) {
				k = j;
				gooder = &tim[k];
			}
		visit[k] = true;
		for (int j = 0; j < map[k].size(); j++) {
			if (tim[k].time + map[k][j].time < tim[map[k][j].data].time) {
				tim[map[k][j].data].pre = k;
				tim[map[k][j].data].dis = tim[k].dis + 1;
				tim[map[k][j].data].time = tim[k].time + map[k][j].time;
			}
			else if (tim[k].time + map[k][j].time == tim[map[k][j].data].time) {
				if (tim[k].dis + 1 < tim[map[k][j].data].dis) {
					tim[map[k][j].data].pre = k;
					tim[map[k][j].data].dis = tim[k].dis + 1;
					tim[map[k][j].data].time = tim[k].time + map[k][j].time;
				}
			}
		}
	}

}

bool isOne() {
	int i = d, j = d;
	while (i != s || j != s) {
		if(dis[i].pre == tim[i].pre){
			i = dis[i].pre;
			j = tim[j].pre;
		}
		else
			return false;
	}
	if (i != j)
		return false;
	else
		return true;
}

void printAns(bool one) {
	stack<int> ans;
	if (one) {
		for (int i = d; i != s; ) {
			ans.push(i);
			i = dis[i].pre;
		}
		printf("Distance = %d; Time = %d: %d", dis[d].dis, tim[d].time,s);
		while (!ans.empty()) {
			printf(" -> %d", ans.top());
			ans.pop();
		}
	}
	else {
		for (int i = d; i != s; ) {
			ans.push(i);
			i = dis[i].pre;
		}
		printf("Distance = %d: %d", dis[d].dis, s);
		while (!ans.empty()) {
			printf(" -> %d", ans.top());
			ans.pop();
		}
		for (int i = d; i != s; ) {
			ans.push(i);
			i = tim[i].pre;
		}
		printf("\nTime = %d: %d", tim[d].time, s);
		while (!ans.empty()) {
			printf(" -> %d", ans.top());
			ans.pop();
		}
	}
}

int main() {
	init();
	visit.resize(N, false);
	dijD();
	visit.clear();
	visit.resize(N, false);
	dijT();
	printAns(isOne());
	system("pause");
}
