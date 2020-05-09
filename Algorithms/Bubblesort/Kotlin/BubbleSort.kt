class DummyBubbleSort {

    private fun sortArray(numbers: Array<Int>) {
        for (currentPosition in 0 until (numbers.size - 1)) {
            if (numbers[currentPosition] > numbers[currentPosition + 1]) {
                val tmp = numbers[currentPosition]
                numbers[currentPosition] = numbers[currentPosition + 1]
                numbers[currentPosition + 1] = tmp
            }
        }
    }

    fun main(args: Array<String>) {
        val numbers = arrayOf(69, 42, 666, 1, 969, 23, 6, 2, 0, 87)
        sortArray(numbers)
        numbers.forEach(::print)
    }
}
