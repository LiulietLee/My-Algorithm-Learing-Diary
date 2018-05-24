/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-28 14:55:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-30 10:01:08
*/

//链式前向星+spfa的实现
//

#include <iostream>
#include <queue>
using namespace std;

const int N = 100;
const long long INF = 99999999;

//标准的链式前向星实现
struct Node
{
	int to;
	int next;
	int w;
}edge[N];

int vertexs;
int edges;

int dis[N];
int head[N];
int vis[N];
int cnt;

void add(int u, int v, int w)//存一条以u为起点,v为终点,w为边权值的有向边。
{
	edge[cnt].w = w;
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
	cnt++;
}

void init()
{
	cnt = 0;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
}

int spfa(int beginX, int endX)
{
	queue <int> Q;
	int u;

	for(int i=1;i<=vertexs;i++){
		dis[i] = INF;
		vis[i] = 0;
	}
	vis[beginX] = 1;
	dis[beginX] = 0;
	
	Q.push(beginX);
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		vis[u] = 0;

		for(int i=head[u];~i;i=edge[i].next){
			int v = edge[i].to;
			if(dis[v] > dis[u] + edge[i].w){
				dis[v] = dis[u] + edge[i].w;
				if(!vis[v]){
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
	return dis[endX];
}