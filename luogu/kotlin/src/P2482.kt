@file:Suppress("MemberVisibilityCanBePrivate")

import java.util.LinkedList
import java.util.Queue
import java.util.Scanner
import kotlin.IllegalArgumentException

object P2482 {
	fun main() {
		Scanner(System.`in`).let { stdin ->
			stdin.nextInt().let { pc ->
				stdin.nextInt().let { _ ->
					Game().also { game ->
						repeat(pc) { i ->
							val job = stdin.next()
							val cards = stdin.nextLine().split(' ')
							PlayerFactory.newInstance(
									game, i, IPlayer.Job.valueOf(job),
									LinkedList<IAction>().apply {
										cards.forEach { cardName ->
											add(ActionFactory.newInstance(cardName[0]))
										}
									}).run(game::join)
						}

						stdin.nextLine().split(' ').forEach { cardName ->
							ActionFactory.newInstance(cardName[0]).run(game::addCard)
						}
					}.run {
						val result = start()
					}
				}
			}
		}
	}
}

class Game : Iterable<IPlayer> {
	class PlayerIterator(val game : Game, var it : Int = 0) : Iterator<IPlayer> {
		override fun hasNext() : Boolean {
			return game.players.isNotEmpty()
		}

		fun current() : IPlayer {
			return game.players[it]
		}

		override fun next() : IPlayer {
			if (++ it == game.players.size) it = 0

			return current()
		}

		fun last() : IPlayer {
			if (-- it == - 1) it = game.players.lastIndex

			return current()
		}
	}

	private val it = iterator()
	private var mpCount = 0
	private var fpCount = 0

	val cardHeap : Queue<IAction> = LinkedList()
	val players : MutableList<IPlayer> = ArrayList()

	val current : IPlayer get() = it.current()

	fun next() : IPlayer = it.next()

	fun start() : IPlayer.Job {
		while (players.size != 1) {
			checkWin().let {
				if (it == IPlayer.Job.MP) {
					current.startRound()
				} else return IPlayer.Job.MP
			}
		}

		throw IllegalArgumentException("辣鸡玩意")
	}

	/**
	 * 判断是否有某一方获胜
	 * @return FP 表示 反猪获胜, ZP 表示 主猪获胜, MP 表示 暂时无人获胜
	 */
	fun checkWin() : IPlayer.Job {
		return when {
			mpCount == 0 -> IPlayer.Job.FP
			fpCount == 0 -> IPlayer.Job.ZP

			else -> IPlayer.Job.MP
		}
	}

	fun getCards(player : IPlayer) {
		player.cards.add(cardHeap.remove())
		player.cards.add(cardHeap.remove())
	}

	fun died(player : IPlayer) {
		players.indexOfFirst { it == player }.let { ix ->
			if (ix <= it.it) it.last()
			players.removeAt(ix)
		}
	}

	fun join(p : IPlayer) {
		if (p is MPlayer || p is ZPlayer) ++ mpCount else ++ fpCount
		players.add(p)
	}

	fun addCard(c : IAction) {
		cardHeap.add(c)
	}

	override fun iterator() : PlayerIterator {
		return PlayerIterator(this)
	}
}

object PlayerFactory {
	fun newInstance(game : Game, id : Int, job : IPlayer.Job, initCards : Queue<IAction>) : IPlayer {
		return when (job) {
			IPlayer.Job.MP -> ::MPlayer
			IPlayer.Job.ZP -> ::ZPlayer
			IPlayer.Job.FP -> ::FPlayer
		}(id, game, initCards)
	}
}

interface IPlayer {
	enum class Job {
		MP, ZP, FP
	}

	val id : Int
	val isShowed : Boolean        // 是否表身份
	var isLikeFP : Boolean        // 是否为类反猪
	val game : Game
	val maxHealth : Int
	val currentHealth : Int
	val isDeath : Boolean
	val cards : Queue<IAction>
	var canRepeatKill : Boolean

	fun needMiss(from : IPlayer, action : IAction) : Boolean
	fun needKill(from : IPlayer, action : IAction) : Boolean
	fun needInvalid(from : IPlayer, action : IAction) : Boolean
	fun getHurt(from : IPlayer, hurt : Int)
	fun getHealth(from : IPlayer, health : Int)
	fun startRound()
}

abstract class Player(
		override val id : Int,
		override val game : Game,
		override val cards : Queue<IAction>
) : IPlayer {
	override val maxHealth : Int = 4
	override var currentHealth : Int = 4
	override var isShowed : Boolean = false
	override var isLikeFP : Boolean = false
	override var canRepeatKill : Boolean = false

	override val isDeath : Boolean get() = currentHealth <= 0

	private fun needAction(action : IAction) : Boolean {
		return if (cards.contains(action)) {
			cards.remove(action)

			true
		} else false
	}

	private fun whenDying() {
		if (isDeath) {
			while (isDeath && cards.contains(HealthAction)) {
				HealthAction.invoke(this, this)
			}

			if (isDeath) game.died(this)
		}
	}

	override fun needKill(from : IPlayer, action : IAction) : Boolean {
		return needAction(KillAction)
	}

	override fun needMiss(from : IPlayer, action : IAction) : Boolean {
		return needAction(MissAction)
	}

	override fun needInvalid(from : IPlayer, action : IAction) : Boolean {
		return needAction(InvalidAction)
	}

	override fun getHurt(from : IPlayer, hurt : Int) {
		currentHealth -= hurt
		if (isDeath) {
			whenDying()
		}
	}

	override fun getHealth(from : IPlayer, health : Int) {
		currentHealth += health
	}

	override fun startRound() {
		game.getCards(this)
		while (currentHealth != maxHealth && cards.contains(HealthAction)) {
			HealthAction.invoke(this, this)
		}
	}

	override fun equals(other : Any?) : Boolean {
		if (this === other) return true
		if (other !is Player) return false

		if (id != other.id) return false

		return true
	}

	override fun hashCode() : Int {
		return id
	}
}

class MPlayer(id : Int, game : Game, cards : Queue<IAction>) : Player(id, game, cards) {
	override fun getHurt(from : IPlayer, hurt : Int) {
		super.getHurt(from, hurt)

		if (from.isShowed.not()) {
			from.isLikeFP = true
		}
	}

	override fun startRound() {
		super.startRound()


	}
}

class ZPlayer(id : Int, game : Game, cards : Queue<IAction>) : Player(id, game, cards) {
	override fun needKill(from : IPlayer, action : IAction) : Boolean {
		return if (action is DuelAction && from is MPlayer) false else super.needKill(from, action)
	}

	override fun needInvalid(from : IPlayer, action : IAction) : Boolean {
		TODO()
	}
}

class FPlayer(id : Int, game : Game, cards : Queue<IAction>) : Player(id, game, cards)

interface IAction {
	fun invoke(self : IPlayer, target : IPlayer)
}

object ActionFactory {
	fun newInstance(name : Char) : IAction {
		return when (name) {
			'P' -> HealthAction
			'K' -> KillAction
			'D' -> MissAction

			'F' -> DuelAction
			'N' -> SouthPigAction
			'W' -> MillionsArrowAction
			'J' -> InvalidAction

			'Z' -> RepeatKillAction

			else -> throw IllegalArgumentException()
		}
	}
}

abstract class Action : IAction {
	override fun invoke(self : IPlayer, target : IPlayer) {
		self.cards.remove(this)
	}
}

object KillAction : Action() {
	override fun invoke(self : IPlayer, target : IPlayer) {
		super.invoke(self, target)
		if (target.needMiss(self, this).not()) target.getHurt(self, 1)
	}
}

object MissAction : Action()

object HealthAction : Action() {
	override fun invoke(self : IPlayer, target : IPlayer) {
		super.invoke(self, target)
		target.getHealth(self, 1)
	}
}

object DuelAction : Action() {
	override fun invoke(self : IPlayer, target : IPlayer) {
		super.invoke(self, target)

		var mSelf = self
		var mTarget = target

		while (true) {
			if (mTarget.needInvalid(mSelf, this)) return
			if (mTarget.needKill(mSelf, this).not()) break

			mSelf = target
			mTarget = self
		}

		mTarget.getHurt(mSelf, 1)
	}
}

abstract class NeedActionAction(val needAction : IPlayer.(IPlayer, IAction) -> Boolean) : Action() {
	override fun invoke(self : IPlayer, target : IPlayer) {
		super.invoke(self, target)

		val it = Game.PlayerIterator(self.game, self.game.iterator().it)
		while (it.next() != self) {
			if (it.current().needInvalid(self, this)) break
			it.current().needAction(self, this)
		}
	}
}

object SouthPigAction : NeedActionAction(IPlayer::needKill)
object MillionsArrowAction : NeedActionAction(IPlayer::needMiss)

object InvalidAction : Action() {
	override fun invoke(self : IPlayer, target : IPlayer) {
		super.invoke(self, target)

		target.needInvalid(self, this)
	}
}

object RepeatKillAction : Action() {
	override fun invoke(self : IPlayer, target : IPlayer) {
		super.invoke(self, target)
		target.canRepeatKill = true
	}
}