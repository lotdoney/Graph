//һ���ھӾ������ڽӱ�
/*
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int INF=INT_MAX;

struct Edge {
	int v;
	int w;
	Edge(int a, int b) :v(a), w(b) {}
};

int main(){
	//�ڽӱ���������1000����
	vector<Edge> Adj[100];
	Adj[1].push_back(Edge(3, 4));//1����ʼ���㣬3����ֹ���㣬4��Ȩֵ��
	//�ڽӾ���
	int G[100][100];
	fill(G[0],G[0]+100*100,INF);
	G[0][3] = 4;
}
*/
//�����Ͻܿ�˹���㷨��ʵ��
/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = INT_MAX;

int G[500][500];
int dis[100];//��㵽�����������·���ĳ���
bool vis[100];

void Dijkstra(int s,int n) {
	fill(dis, dis + 100, INF);
	dis[s] = 0;
	for (int i=0;i<n;i++){
		int u = -1;
		int min = INF;
		for (int j=0;j<n;j++){
			if (vis[j]==false&&dis[j]<min){
				u = j;
				min = dis[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v=0;v<n;v++){
			if (vis[v]==false&&G[u][v]!=INF&&dis[u]+G[u][v]<dis[v]){
				dis[v] = dis[u] + G[u][v];
			}
		}

	}

}


int main() {
	int n;
	while (scanf_s("%d",&n)!=EOF){
		memset(vis, false, sizeof(vis));
	//	bool vis[100] = { false };//����ֱ����������Ϊ�������100��Ԫ��
		int n, m, s;//nΪ��������mΪ������sΪ��㣬gΪ�洢ͼ�ľ���
		scanf_s("%d%d%d", &n, &m, &s);
		fill(G[0], G[0] + 500 * 500, INF); //��ʼ����ͼ��û��һ���ڵ�ʱ������
		int u, v, w;
		for (int i = 0; i < m;i++) {
			scanf_s("%d%d%d", &u, &v, &w);
			G[u][v] = w;
		}
		Dijkstra(s,n);
		for (int i = 0; i < n; i++) {
			cout << dis[i] << endl;
		}

	}
	

	return 0;
}
*/

//�������������㷨
/*
#include <iostream>
#include <cstdio>

using namespace  std;

const int INF = INT_MAX;
const int MAXV = 200;
int n, m;//nΪ��������mΪ����
int dis[MAXV][MAXV];//i��j����̾���


void Floyd() {
	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}


}



int main() {
	int n;
	while (scanf_s("%d",&n)!=EOF){
		while (n--) {
			fill(dis[0], dis[0] + MAXV * MAXV, INF);
			scanf_s("%d%d", &n, &m);
			int u, v;
			for (int i = 0; i < n; i++) {
				dis[i][i] = 0;
			}
			for (int i = 0; i < m; i++) {
				scanf_s("%d%d", &u, &v);
				dis[u-1][v-1] = 1;
				dis[v-1][u-1] = 1;
			}
			Floyd();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf_s("%d ", dis[i][j]);
				}
				printf_s("\n");
			}
			int sum = 0;
			int min = INF;
			int flag = 1;
			for (int i=0;i<n;i++){
				sum = 0;
				for (int j = 0; j < n; j++) {
					sum += dis[i][j];
				}
				if (sum<min) {
					min = sum;
					flag = i + 1;
				}
			}
			cout << flag << endl;
		}
	}
	return 0;
}
*/

//�ġ���������
/*
#include <iostream>
#include <cstdio>
#include <queue>

using namespace  std;


//�������������򣬲���ҪȨֵ�����ֱ�ӽ���һ��int����������
//struct Edge {
//	int v;
//	int w;
//	Edge(int a, int b) :v(a), w(b) {}
//};

int n, m, inDegree[500];
vector<int> G[500];


void topoSort(int n) {
	priority_queue<int, vector<int>, greater<int> > myq;	
	int num = 0;//ͳ�Ƽ�����������Ķ�����
	for (int i=0;i<n;i++){
		if (inDegree[i] == 0) myq.push(i);
	}
	while (!myq.empty()) {
		int u = myq.top();
		myq.pop();
		num++;
		if (num == n) cout << u+1 << endl;
		else cout << u+1 << " ";
		for (int i=0;i<G[u].size();i++){
			int v = G[u][i];
			inDegree[v]--;
			if (inDegree[v]==0){
				myq.push(v);
			}
		}
		G[u].clear();
	}

}


int main() {
	int n;
	while (scanf_s("%d", &n) != EOF) {
		while (n--) {
			scanf_s("%d%d", &n, &m);
			//��������ѭ������
			for (int i = 0; i < n; i++) {
				G[i].clear();
				inDegree[i] = 0;
			}
			for (int i = 0; i < m; i++) {
				int u, v;
				scanf_s("%d%d", &u, &v);
				inDegree[v - 1]++;
				G[u - 1].push_back(v - 1);
			}
			topoSort(n);
		}

	}

	return 0;
}
*/