class Solution:
    def countAndSay(self, n: int) -> str:
        ans = "1"
        for _ in range(n-1):
            res = ""
            i = 0
            current = ans[0]
            x = 1
            while i < len(ans)-1:
                if ans[i] != ans[i+1]:
                    res += str(x) + ans[i]
                    x = 0
                i += 1
                x+=1
            res += str(x) + ans[-1]
            ans = res
        return ans
