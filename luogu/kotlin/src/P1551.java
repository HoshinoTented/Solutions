import java.util.Scanner;

public class P1551 {
	@SuppressWarnings("WeakerAccess")
	private static class UnionFind {
		private int[] set;

		public UnionFind(int size) {
			set = new int[size];

			for (int i = 0; i < set.length; ++ i) {
				set[i] = i;
			}
		}

		public int find(int target) {
			return target == set[target] ? target : (set[target] = find(set[target]));
		}

		public void concat(int x, int y) {
			set[find(x)] = find(y);
		}
	}

	private static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {
		int itemCount = stdin.nextInt(), relativeCount = stdin.nextInt(), reqCount = stdin.nextInt();

		UnionFind uf = new UnionFind(itemCount + 1);

		for (int i = 0; i < relativeCount; ++ i) {
			int x = stdin.nextInt(), y = stdin.nextInt();

			uf.concat(x, y);
		}

		for (int i = 0; i < reqCount; ++ i) {
			int x = stdin.nextInt(), y = stdin.nextInt();

			System.out.println(uf.find(x) == uf.find(y) ? "Yes" : "No");
		}
	}
}
