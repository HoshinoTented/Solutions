import java.util.Scanner
import kotlin.math.*

object P1426 {
	//TODO WA
	@JvmStatic
	fun main(args: Array<String>) {
		Scanner(System.`in`).let { s ->
			(s.nextInt() to s.nextInt()).let { (s, x) ->
				val speed = fun(i: Int) = 7.0 * (0.98.pow(i))
				if (speed(s) <= x) 'y' else 'n'
			}.run(::println)
		}
	}
}