class Solution:
    def spiralOrder(self, matrix):
        ans = []
        if len(matrix) == 0:
            return ans
        if len(matrix) == 1:
            for i in matrix[0]:
                ans += [i]
            return ans
        if len(matrix[0]) == 1:
            for i in matrix:
                ans += [i[0]]
            return ans
        start = [0,0]
        end = [len(matrix)-1, len(matrix[0])-1]

        while (start[0] < end[1] and start[1] < end[0]):
            r = start[0]
            c = start[1]
            # Top row.
            while (c <= end[1]):
                ans += [matrix[r][c]]
                c += 1
            # Right col.
            c = end[1]
            while (r < end[0]):
                r += 1
                ans += [matrix[r][c]]

            # Bow row.
            while (c > start[1]):
                c -= 1
                ans += [matrix[r][c]]

            # Left col.
            while (r > start[0]+1):
                r -= 1
                ans += [matrix[r][c]]

            start[0] += 1
            start[1] += 1
            end[0] -= 1
            end[1] -= 1

        # Square and odd number of rows and columns.
        if (len(matrix) == len(matrix[0]) and (len(matrix) % 2) == 1):
            ans += [matrix[start[0]][start[1]]]
        elif (len(matrix) > len(matrix[0])) and (len(matrix[0]) % 2 == 1):
            while start[0] <= end[0]:
                ans += [matrix[start[0]][start[1]]]
                start[0] += 1
        elif len(matrix) % 2 == 1:
            while start[1] <= end[1]:
                ans += [matrix[start[0]][start[1]]]
                start[1] += 1
        return ans
