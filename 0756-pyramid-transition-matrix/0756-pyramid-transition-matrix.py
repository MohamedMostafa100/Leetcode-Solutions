def solve(bottom: str, top: str, pattern: dict[str, List[str]], visited: set[str], i: int) -> bool:
    print(top)
    if len(bottom) == 1:
        return True
    if top in visited:
        return False
    if i == len(bottom) - 1:
        return solve(top, '', pattern, visited, 0)
    block = bottom[i:i + 2]
    if block in pattern:
        for c in pattern[block]:
            if solve(bottom, top + c, pattern, visited, i + 1):
                return True
    visited.add(bottom)
    return False
class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        pattern = {}
        visited = set()
        for a in allowed:
            if a[:2] not in pattern:
                pattern[a[:2]] = []
            pattern[a[:2]].append(a[2])
        return solve(bottom, '', pattern, visited, 0)