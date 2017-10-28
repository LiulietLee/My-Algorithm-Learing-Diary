/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-21 12:41:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-21 14:08:15
*/
#include <queue>
using namespace std;

const int N = 500;
const int INF = 99999999;


int vis[N];
int dis[N];

int iMap[N][N];
int vertexs;
int edges;//这里有个玄学问题，如果edges 放在vis[N],之前的话程序无法运行。。
int u, v, w;

int dijkstraHeap(int beginX, int endX)
{	
	int minVertex;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > heap;//一个最小堆

	//初始化
	for(int i=1;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];//初始化所有点到开始点的最短距离
		heap.push(make_pair(dis[i], i));//初始的话先将所有的点入队
		vis[i] = 0;
	}
	vis[beginX] = 1;

	while(!heap.empty()){
		minVertex = heap.top().second;
		heap.pop();

		if(vis[minVertex]) continue;//如果这个点之前没有被访问过
		vis[minVertex] = 1;

		int u = minVertex;
		for(int v=1;v<=vertexs;v++){
			if(!vis[v] && iMap[u][v] < INF){//如果这个点未被访问，且中间有路径到达
				if(dis[v] > iMap[u][v] + dis[u]){
					dis[v] = iMap[u][v] + dis[u];
					heap.push(make_pair(dis[v], v));//将到更新后的到该点的距离入队
				}	
			}
		}
	}	
	return dis[endX];
}