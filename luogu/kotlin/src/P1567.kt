import java.util.Scanner

object P1567 {
	@JvmStatic
	fun main(args: Array<String>) {
		val stdin = Scanner(System.`in`)
		val i = stdin.nextInt()
		var max = 0
		var `continue` = 0
		var last = 0

		repeat(i) {
			val cur = stdin.nextInt()

			if (cur >= last) {
				++ `continue`
				last = cur
			} else {
				if (max < `continue`) {
					max = `continue`
				}

				`continue` = 1
				last = cur
			}
		}

		println(if (max == 0) `continue` else max)
	}
}