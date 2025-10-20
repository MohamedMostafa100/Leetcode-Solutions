class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        X = 0
        for op in operations:
            if op[0] == '+' or op[2] == '+':
                X += 1
            else:
                X -= 1
        return X