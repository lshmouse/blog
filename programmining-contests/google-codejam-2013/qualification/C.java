import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
	private int[] value = new int[50];
	private int limit = 50;
	private List<BigInteger> values = new ArrayList<BigInteger>();

	public void search() {
		for (int i = 1; i <= limit; i++) {
			for (int j = 1; j < 4; j++) {
				dfs(0, j, i, 0);
			}
		}
	}

	private void dfs(int k, int v, int limit, int sum) {
		value[k] = v;
		value[limit - 1 - k] = v;
		sum += v * v;
		if (k != limit - 1 - k) {
			sum += v * v;
		}
		if (sum >= 10)
			return;

		if (2 * (k + 1) >= limit) {
			StringBuilder builder = new StringBuilder();
			for (int i = 0; i < limit; i++) {
				builder.append((char) ('0' + value[i]));
			}
			BigInteger value = new BigInteger(builder.toString());
			values.add(value.multiply(value));
			return;
		}

		for (int j = 0; j < 3; j++) {
			dfs(k + 1, j, limit, sum);
		}
	}
	
	public int count(BigInteger limit) {
		int start = 0;
		int end = values.size() - 1;
		int ret = -1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (values.get(mid).compareTo(limit) <= 0) {
				ret = mid;
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		return ret + 1;
	}

	public static void main(String[] args) {
		C solver = new C();
		solver.search();
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			BigInteger a = in.nextBigInteger();
			BigInteger b = in.nextBigInteger();
			System.out.println("Case #" + t + ": "
					+ (solver.count(b) - solver.count(a.subtract(BigInteger.ONE))));
		}
		in.close();
	}
}
