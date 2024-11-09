class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if target == '0000':
            return 0

        deadends = set(deadends)
        if '0000' in deadends:
            return -1

        visited = set()
        queue = [('0000', 0)]

        while queue:
            cur, level = queue.pop(0)
            if cur == target:
                return level

            if cur in visited or cur in deadends:
                continue

            visited.add(cur)

            for i in range(4):
                for j in [-1, 1]:
                    next = str((int(cur[i]) + j) % 10)
                    new = cur[:i] + next + cur[i+1:]

                    if new not in visited and new not in deadends:
                        queue.append((new, level+1))

        return -1