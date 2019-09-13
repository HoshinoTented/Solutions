import java.util.Scanner

/**
 * TODO RE
 */
object P1554 {

	@JvmStatic
	fun main() {
		Scanner(System.`in`).let { stdin ->
			stdin.nextInt().let { begin ->
				stdin.nextInt().let { end ->
					IntArray(10).let { nums ->
						(begin..end).forEach { num ->
							num.toString().forEach { c ->
								nums[c.toInt() - '0'.toInt()] += 1
							}
						}

						nums.joinToString(" ") { it.toString() }.run(::println)
					}
				}
			}
		}
	}
}
