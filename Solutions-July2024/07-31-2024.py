class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        cache = {}
        def helper(idx):
            if idx == len(books):
                return 0

            if idx in cache:
                return cache[idx]

            curr_width = shelfWidth
            max_height = 0
            cache[idx] = float("inf")

            for i in range(idx, len(books)):
                width, height = books[i]
                if curr_width < width:
                    break

                curr_width -= width
                max_height = max(max_height, height)

                cache[idx] = min(cache[idx], helper(i+1) + max_height)

            return cache[idx]

        return helper(0)

