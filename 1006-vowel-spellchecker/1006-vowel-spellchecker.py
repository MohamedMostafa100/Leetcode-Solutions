class Solution:
    def preVow(self, s: str) -> str:
        return ''.join('*' if ch in 'aeiouAEIOU' else ch.lower() for ch in s) 
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        exMatch = set()
        capMatch = {}
        vowMatch = {}
        for s in wordlist:
            exMatch.add(s)
            capMatch.setdefault(s.lower(), s)
            vowMatch.setdefault(self.preVow(s), s)
        for i in range(len(queries)):
            if queries[i] in exMatch:
                continue
            elif queries[i].lower() in capMatch:
                queries[i] = capMatch[queries[i].lower()]
            elif self.preVow(queries[i]) in vowMatch:
                queries[i] = vowMatch[self.preVow(queries[i])]
            else:
                queries[i] = ''
        return queries