#include <iostream>
#include <vector>

#define gone_here std::cout << "qwq" << std::endl;

using id = int;

enum status {
	unknown,
	unaccept,
	accept
};

struct song {
	int dlc_id;
	std::vector<id> depends;
	status st;
};

int n, k, q;

song songs[100001];
bool bought_dlc[1000];

auto eval(const int &x) -> status {
	song &cur = songs[x];

	if (cur.st != unknown) return cur.st;       // 如果已经有状态了，则直接返回

	if (cur.depends.empty()) cur.st = accept;       // 如果依赖是空的，就是可以直接玩的了
	else {
		for (id identity : cur.depends) {               // 如果依赖非空，遍历每个依赖
			if (eval(identity) != accept) {             // 对每个依赖求值，并判断依赖是否已经通过
				cur.st = unaccept;                  // 如果未通过，则这条曲子也玩不了
				return cur.st;                      // 直接返回状态
			}
		}

		cur.st = accept;                            // 如果每个依赖都能玩，则这条曲子已经通关了（数据中的未通关都已经在第一个 if 拦下了）
	}

	return cur.st;                                  // 返回状态
}

auto main(int, char **) -> int {
	std::cin >> n >> k;

	bought_dlc[0] = true;       // 默认曲目是已经购买的了
	for (int i = 1; i <= n; ++ i) {
		int dlc_id, m;
		std::cin >> dlc_id >> m;

		songs[i].st = unknown;      // 刚读入时是未知的
		songs[i].dlc_id = dlc_id;

		for (int j = 0; j < m; ++ j) {      // 读入依赖
			int depend;
			std::cin >> depend;
			songs[i].depends.push_back(depend);
		}
	}

	std::cin >> q;

	for (int i = 0; i < q; ++ i) {
		int cur;
		std::cin >> cur;

		songs[cur].st = unaccept;       // 表示未完成

		bought_dlc[songs[cur].dlc_id] = true;       // 如果状态为 未完成，则是已经购买
	}

	for (int i = 1; i <= n; ++ i) {
		eval(i);        // 对每个歌曲进行求值
	}


	int min = 0, max = 0;

	for (int i = 1; i <= n; ++ i) {
		song &cur = songs[i];

		if (cur.st == accept) {         // 如果状态为通过
			if (bought_dlc[cur.dlc_id]) ++ min;     // 如果为 已经确定是购买过的dlc，则最小值 ++
			++ max;     // 最大值 ++
		}
	}

	std::cout << min << " " << max << std::endl;

	return 0;
}