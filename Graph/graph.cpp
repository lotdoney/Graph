//一、邻居矩阵与邻接表
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
	//邻接表，顶点数在1000以上
	vector<Edge> Adj[100];
	Adj[1].push_back(Edge(3, 4));//1是起始顶点，3是终止顶点，4是权值。
	//邻接矩阵
	int G[100][100];
	fill(G[0],G[0]+100*100,INF);
	G[0][3] = 4;
}
*/
//二、迪杰克斯拉算法的实现
/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = INT_MAX;

int G[500][500];
int dis[100];//起点到达各个点的最短路径的长度
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
	//	bool vis[100] = { false };//这里直接声明会以为是这个第100个元素
		int n, m, s;//n为顶点数，m为边数，s为起点，g为存储图的矩阵
		scanf_s("%d%d%d", &n, &m, &s);
		fill(G[0], G[0] + 500 * 500, INF); //初始化，图中没有一个节点时相连的
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

//三、佛洛依德算法
/*
#include <iostream>
#include <cstdio>

using namespace  std;

const int INF = INT_MAX;
const int MAXV = 200;
int n, m;//n为顶点数，m为边数
int dis[MAXV][MAXV];//i到j的最短距离


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

//四、拓扑排序
/*
#include <iostream>
#include <cstdio>
#include <queue>

using namespace  std;


//由于是拓扑排序，不需要权值，因此直接建立一个int的向量即可
//struct Edge {
//	int v;
//	int w;
//	Edge(int a, int b) :v(a), w(b) {}
//};

int n, m, inDegree[500];
vector<int> G[500];


void topoSort(int n) {
	priority_queue<int, vector<int>, greater<int> > myq;	
	int num = 0;//统计加入拓扑排序的顶点数
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
			//多组数据循环工作
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