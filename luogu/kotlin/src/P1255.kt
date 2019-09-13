import java.util.Scanner

object P1255 {
	var sum = 0

	fun count(max: Int, counted: Int) {
		if (max < counted) return
		if (max == counted) {
			sum += 1
			return
		}

		count(max, counted + 1)
		count(max, counted + 2)
	}

	@JvmStatic
	fun main(args: Array<String>) {
		count(Scanner(System.`in`).nextInt(), 0)
		println(sum)
	}
}