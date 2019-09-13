package algo;

import java.util.Scanner;

@SuppressWarnings("WeakerAccess")
public class UnionFind {
	public final int[] parent;

	public UnionFind(int size) {
		parent = new int[size];

		for (int i = 0; i < parent.length; ++ i) {
			parent[i] = i;
		}
	}

	public int find(int target) {
		if (target == parent[target]) return target;
		else return find(parent[target]);
	}

	public void add(int parent, int value) {
		this.parent[find(value)] = find(parent);
	}

	public static void printArr(int[] arr) {
		for (int value : arr) System.out.print(value + " ");
		System.out.println();
	}

	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);

		int itemCount = stdin.nextInt(), relativeCount = stdin.nextInt(), reqCount = stdin.nextInt();

		UnionFind uf = new UnionFind(itemCount + 1);

		for (int i = 0; i < relativeCount; ++ i) {
			int x = stdin.nextInt(), y = stdin.nextInt();

			uf.add(x, y);
		}

		for (int i = 0; i < reqCount; ++ i) {
			int x = stdin.nextInt(), y = stdin.nextInt();

			System.out.println(uf.find(x) == uf.find(y) ? "Yes" : "No");
		}
	}
}
