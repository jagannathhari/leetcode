class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        seen = {}
        for i in range(len(s)-9):
            key = s[i:i+10]
            seen[key] = seen.get(key,0)+1
        return [i for i in seen if seen[i]>1]
