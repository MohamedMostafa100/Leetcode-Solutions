class Spreadsheet:

    def __init__(self, rows: int):
        self.values = [[0 for j in range(26)] for i in range(rows)]

    def setCell(self, cell: str, value: int) -> None:
        self.values[int(cell[1:]) - 1][ord(cell[0]) - ord('A')] = value

    def resetCell(self, cell: str) -> None:
        self.values[int(cell[1:]) - 1][ord(cell[0]) - ord('A')] = 0

    def getValue(self, formula: str) -> int:
        ops = formula[1:].split("+")
        print(ops)
        if ops[0].isdigit():
            ops1 = int(ops[0])
        else:   
            ops1 = self.values[int(ops[0][1:]) - 1][ord(ops[0][0]) - ord('A')]

        if ops[1].isdigit():
            ops2 = int(ops[1])
        else:   
            ops2 = self.values[int(ops[1][1:]) - 1][ord(ops[1][0]) - ord('A')]
        return ops1 + ops2


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)