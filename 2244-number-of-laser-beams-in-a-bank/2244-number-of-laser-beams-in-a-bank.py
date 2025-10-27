class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        res = 0
        prev = 0
        for floor in bank:
            cur = 0
            for cell in floor:
                if cell == '1':
                    cur += 1
            
            res += cur * prev
            prev = cur if cur > 0 else prev
        return res
