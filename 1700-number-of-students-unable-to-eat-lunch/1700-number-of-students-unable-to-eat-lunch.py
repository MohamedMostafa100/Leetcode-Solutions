class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        c = 0
        sq = 0
        for stud in students:
            if stud == 0:
                c += 1
            else:
                sq += 1
        for sand in sandwiches:
            if sand == 0:
                if c == 0:
                    break
                c -= 1
            else:
                if sq == 0:
                    break
                sq -= 1
        return c + sq
