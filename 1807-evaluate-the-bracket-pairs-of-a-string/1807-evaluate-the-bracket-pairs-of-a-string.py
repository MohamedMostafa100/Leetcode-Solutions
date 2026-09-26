class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        res = ""
        wordMap = {}
        i = 0
        for k, v in knowledge:
            wordMap[k] = v
        while i < len(s):
            if s[i] == '(':
                word = ""
                i += 1 
                while s[i] != ')':
                    word += s[i]
                    i += 1
                if word in wordMap:
                    res += wordMap[word]
                else:
                    res += '?'
            else:
                res += s[i]
            i += 1
        return res 