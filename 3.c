#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int m[500][500];		// map
int snum[500] = {0}; 	// 各个城市的救援队数目
int mnum[500];			// 最短距离
int pnum[500] = {0};	// 最短距离路径数
int visit[500]={0};		// 是否到达过
int senum[500];		// 到该城市的路径上可调用的救援队数目
int cnum,rnum,sc,ec;

int main()
{
	for (int i = 0; i < 500; ++i)
		for (int j = 0; j < 500; ++j)
			m[i][j] = INT_MAX;
	for (int i = 0; i < 500; ++i)
		mnum[i] = INT_MAX;

	scanf("%d%d%d%d", &cnum, &rnum, &sc, &ec);
	for (int i = 0; i < cnum; ++i)
		scanf("%d", &snum[i]);
	memcpy(senum, snum, sizeof(int)*cnum);
	for (int i = 0; i < rnum; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		m[a][b] = m[b][a] = c;
	}
	mnum[sc] = 0;
	pnum[sc] = 1;
	for (int i = 0; i < cnum; ++i)
	{
		int min = INT_MAX, cc = -1;
		for (int j = 0; j < cnum; ++j)
			if (visit[j] == 0 && mnum[j] < min) {
				min = mnum[j];
				cc = j;
			}
		if (cc == -1 || cc == ec) break;
		visit[cc] = 1;

		for (int k = 0; k < cnum; ++k) {
			if (visit[k] == 0 && m[cc][k] != INT_MAX) {
				if (mnum[k] == mnum[cc] + m[cc][k]) {
					pnum[k] += pnum[cc];
					if (senum[k] < senum[cc] + snum[k]) {
						senum[k] = senum[cc] + snum[k];
					}
				}

				if (mnum[k] > mnum[cc] + m[cc][k]) {
					mnum[k] = mnum[cc] + m[cc][k];
					pnum[k] = pnum[cc];
					senum[k] = senum[cc] + snum[k];
				}
			}
		}
	}

	printf("%d %d\n", pnum[ec], senum[ec]);

	return 0;
}
