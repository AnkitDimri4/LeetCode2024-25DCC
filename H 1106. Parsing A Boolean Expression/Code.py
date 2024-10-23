class Solution:
    def parseBoolExpr(self, exp: str) -> bool:
        stk = []
        for ch in exp:
            if ch == ',': continue
            if ch == ')':
                t = f = False
                while stk[-1] != '(':
                    top = stk.pop()
                    t |= top == 't'
                    f |= top == 'f'
                stk.pop()  
                op = stk.pop()  
                stk.append('t' if (op == '|' and t) or (op == '&' and not f) else 'f')
                if op == '!': stk[-1] = 'f' if t else 't'
            else: stk.append(ch)
        return stk[-1] == 't'
solution = Solution()
print(solution.parseBoolExpr("&(t,t,t)"))  # Output: True
print(solution.parseBoolExpr("&(|(f))"))    # Output: False
print(solution.parseBoolExpr("|(f,f,f,t)")) # Output: True
print(solution.parseBoolExpr("!(&(f,t))"))  # Output: True
