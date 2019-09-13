object P4136 {
	@JvmStatic
	fun main(args : Array<String>) {
		readLine() !!.toInt().let { n ->
			if (n != 0) (if (n and 1 != 1) "Alice" else "Bob").run(::println).also { main(args) } else return
		}
	}
}
