class Solution:
    def maskPII(self, s: str) -> str:
        if '@' in s:
            first, after = s.split('@')
            return f'{first[0].lower()}*****{first[-1].lower()}@{after.lower()}'
        else:
            digits = "".join(filter(str.isdigit, s))
            local = f"***-***-{digits[-4:]}"
            if len(digits) == 10:
                return local
            return f"+{'*' * (len(digits) - 10)}-" + local