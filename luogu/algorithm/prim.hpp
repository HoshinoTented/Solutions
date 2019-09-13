//
// Created by hoshino on 18-12-15.
//

#ifndef LUOGU_PRIME_HPP
#define LUOGU_PRIME_HPP

#include <bits/stdc++.h>
#define INF 65535
#define MAX 9

using T = int;
using Graph = T **;

struct Edge {
	size_t begin;
	size_t end;
	T weight;
};

// 抄自 《大话数据结构》
auto miniSpanTree(Graph g) -> void {
	Edge edges[MAX];		// 暂存的边集合

	for (size_t i = 1; i < MAX; ++ i) {
		edges[i] = {0, i, g[0][i]};		// 向 边集合 存入 与 0 相关的边
	}

	for (int i = 1; i < MAX; ++ i) {
		int min = INF;	// 最小边的边长
		size_t k = 0;		// 最小边的顶点

		// 找到 edges 暂存的最小边
		for (size_t j = 1; j < MAX; ++ j) {

			// 如果 当前边的权 不为0 且 当前边长度 小于 min ( 当前记录的最小长度
			if (edges[j].weight != 0 && edges[j].weight < min) {

				// 更新最小长度 为 edges[j].weight
				min = edges[j].weight;

				// 更新最小长度边的一个顶点为 j
				k = j;
			}
		}

		std::cout << "(" << edges[k].begin << ", " << k << ")" << std::endl;		//输出最小边

		edges[k].weight = 0;		//将最小边设为 0 (标记为已找到

		// 寻找与当前顶点相连的所有边
		for (size_t j = 1; j < MAX; ++ j) {

			// 如果 j 顶点没有列入最小生成树 且 当前顶点到目标顶点的边长小于记录的边长
			if (edges[j].weight != 0 && g[k][j] < edges[j].weight) {
				edges[j] = {k, j, g[k][j]};
			}
		}
	}
}

auto main(int, char **) -> int {
	Graph graph = new int*[MAX] {
		new int[MAX] {   0,  10, INF, INF, INF,  11, INF, INF, INF },
		new int[MAX] {  10,   0,  18, INF, INF, INF,  16, INF,  12 },
		new int[MAX] { INF,  18,   0,  22, INF, INF, INF, INF,   8 },
		new int[MAX] { INF, INF,  22,   0,  20, INF, INF,  16,  21 },
		new int[MAX] { INF, INF, INF,  20,   0,  26, INF,   7, INF },
		new int[MAX] {  11, INF, INF, INF,  26,   0,  17, INF, INF },
		new int[MAX] { INF,  16, INF, INF, INF,  17,   0,  19, INF },
		new int[MAX] { INF, INF, INF,  16,   7, INF,  19,   0, INF },
		new int[MAX] { INF,  12,   8,  21, INF, INF, INF, INF,   0 },
	};

	miniSpanTree(graph);

	return 0;
}

#endif //LUOGU_PRIME_HPP
