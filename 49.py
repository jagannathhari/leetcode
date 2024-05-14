class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = {}
        for i in strs:
            key = tuple(sorted(i))
            if key in ans:
                ans[key].append(i)
            else:
                ans[key] = [i]
                
        result = [ans[i] for i in ans]
        return result
