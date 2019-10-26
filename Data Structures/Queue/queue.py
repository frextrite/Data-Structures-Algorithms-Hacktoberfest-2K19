class Queue:

    def __init__(self):
        self._array = []

    def add(self, element):
        self._array.append ( element )

    def peek(self):
        ans = None
        if not self.isEmpty:
            ans = self._array[0]
        return ans


    @property
    def isEmpty(self):
        return len ( self._array ) == 0


    def poll(self):
        ans = None
        if not self.isEmpty:
            ans = self._array[0]
        self._leftShift ()
        self._array.pop()
        return ans

    def _leftShift(self):
        for i in range ( len ( self._array ) - 1 ):
            self._array[i] = self._array[i + 1]
