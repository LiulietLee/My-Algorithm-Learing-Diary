/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-19 13:24:51
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-06 17:47:54
*/

//即经过队列优化的Bellman-ford算法

#include <queue>
using namespace std;

const int N = 100;
const int INF = 99999999;

int vertexs;
int edges;

int iMap[N][N];
int vis[N];
int dis[N];

//用于解决从一个起点到一个终点的最短路问题
int spfa(int beginX, int endX)
{	
	queue<int> Q;
	int temp;

	//初始化
	for(int i=1;i<=vertexs;i++){
		dis[i] = INF;
		vis[i] = 0;
	}

	dis[beginX] = 0;
	vis[beginX] = 1;
	Q.push(beginX);
	while(!Q.empty()){
		temp = Q.front();
		Q.pop();
		vis[temp] = 0;//这里正是和广搜不一样的地方
		for(int i=1;i<=vertexs;i++){
			if(dis[i] > dis[temp] + iMap[temp][i]){
				dis[i] = dis[temp] + iMap[temp][i];
				if(!vis[i]){
					vis[i] = 1;
					Q.push(i);
				}
			}
		}
	}
	return dis[endX];
}