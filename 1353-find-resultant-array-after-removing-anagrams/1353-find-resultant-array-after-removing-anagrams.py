class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        res = []
        last = words[0]
        words[0] = "".join(sorted(words[0]))
        cur = ""
        for i in range(1, len(words)):
            cur = words[i]
            words[i] = "".join(sorted(words[i])) 
            if words[i] != words[i - 1]:
                res.append(last)
                last = cur
        res.append(last)
        return res