def generateParenthesis(self, n: int) -> List[str]:
    ans = []
    def backtrack( start = 0, end = 0, stack =[] ):
        if len(stack) == n*2:
            ans.append("".join(stack))
            return
        if start < n:
            stack.append("(")
            backtrack( start + 1, end, stack )
            stack.pop()
        if end < start:
            stack.append(")")
            backtrack(start, end + 1, stack )
            stack.pop()
    backtrack()
    return ans
