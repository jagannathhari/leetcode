class MinStack:
    def __init__(self):
        self.items = []
        self.minimum = []

    def push(self, val: int) -> None:
        if not self.minimum:
            self.minimum.append(val)
        else:
            if self.minimum[-1] >= val:
                self.minimum.append(val)
        self.items.append(val)

    def pop(self) -> None:
        last = self.items.pop()
        if last == self.minimum[-1]:
            self.minimum.pop()

    def top(self) -> int:
        return self.items[-1]

    def getMin(self) -> int:
        return self.minimum[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
