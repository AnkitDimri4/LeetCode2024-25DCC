class Solution:
    def nthUglyNumber(self, n):
        u = [1] * n
        i2 = i3 = i5 = 0
        for i in range(1, n):
            u[i] = min(u[i2] * 2, u[i3] * 3, u[i5] * 5)
            if u[i] == u[i2] * 2:
                i2 += 1
            if u[i] == u[i3] * 3:
                i3 += 1
            if u[i] == u[i5] * 5:
                i5 += 1
        return u[-1]

if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter the value of n: "))
    print(f"The {n}th ugly number is: {sol.nthUglyNumber(n)}")
