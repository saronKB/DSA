class Solution:
    def customSortString(self, order: str, s: str) -> str:
        result = ""

        for char in order:
            result += char * s.count(char)

        for char in s:
            if char not in order:
                result += char

        return result