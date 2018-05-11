/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-19 13:24:33
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-28 10:03:45
*/

//DIJ 是用点松弛，Bell是用边松弛
//

const int N = 100;
const int INF = 99999999;

struct Node
{
	int u;
	int v;
	int w;
}edge[N];//如果是无向边的话，这里的空间要双倍

int dis[N];
int vertexs;
int edges;

int bellman(int beginX,int endX)
{
	bool allReady;

	for(int i=1;i<=vertexs;i++){
		dis[i] = INF;
	}
	dis[beginX] = 0;
	for(int k=1;k<=vertexs-1;k++){
		allReady = false;
		for(int i=1;i<=edges;i++){
			if(dis[edge[i].v] > dis[edge[i].u] + edge[i].w){
				dis[edge[i].v] = dis[edge[i].u] + edge[i].w;
				allReady = true;
			}
		}
		if(!allReady) break;//没有边被松弛的话，就及时的退出。
	}

	//检测负权回路
	bool haveNegativeCircle = false;
	for(int k=1;k<=edges;k++){
		if(dis[edge[k].v] > dis[edge[k].u] + edge[k].w) haveNegativeCircle = true;
	}

	return dis[endX];
}