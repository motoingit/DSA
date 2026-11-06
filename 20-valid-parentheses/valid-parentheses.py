class Solution:

    def isOpening(self, ch):
        return ch == '(' or ch == '{' or ch == '['

    def isClosing(self, ch):
        return ch == ')' or ch == '}' or ch == ']'

    def isDuplet(self, ch1, ch2):
        if ch1 == '(' and ch2 == ')':
            return True
        elif ch1 == '[' and ch2 == ']':
            return True
        elif ch1 == '{' and ch2 == '}':
            return True
        else:
            return False

    def isValid(self, s):
        n = len(s)
        ss = []

        for i in range(n):
            if self.isOpening(s[i]):
                ss.append(s[i])

            elif self.isClosing(s[i]):
                if len(ss) != 0 and self.isDuplet(ss[-1], s[i]):
                    ss.pop()
                else:
                    return False

        return len(ss) == 0