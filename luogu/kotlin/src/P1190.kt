import java.util.LinkedList
import java.util.Queue
import java.util.Scanner

object P1190 {
	fun shortestTime(q: Queue<Int>, m: Int): Int {
		fun <T> Queue<T>.isZero(): Boolean {
			return fold(true) { bool, cur ->
				bool && cur == 0
			}
		}

		fun fill(container: Queue<Int>, queue: Queue<Int>, contLen: Int) {
			while (container.size < contLen && queue.isNotEmpty()) {
				container.add(queue.remove())
			}
		}

		var usedTime = -1
		var time: Queue<Int> = LinkedList()

		do {
			++ usedTime

			time = LinkedList(time.map { it - 1 }.filter { it != 0 })

			fill(time, q, m)
		} while (time.isZero().not())

		return usedTime
	}

	@JvmStatic
	fun main(args: Array<String>) {
		val stdin = Scanner(System.`in`)
		val n = stdin.nextInt()
		val m = stdin.nextInt()
		val queue = LinkedList<Int>()

		repeat(n) {
			queue.push(stdin.nextInt())
		}

		queue.sortWith(Comparator { o1, o2 ->
			if (o1 < o2) 1 else -1
		})

		println(shortestTime(queue, m))
	}
}