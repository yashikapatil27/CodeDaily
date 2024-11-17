class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        adj_list = defaultdict(list)
        for src, dest, curr_cost in zip(original, changed, cost):
            adj_list[src].append((dest, curr_cost))

        def dijkstra(src):
            heap = [(0, src)]
            min_cost = {}
    
            while heap:
                cost, node = heapq.heappop(heap)
                if node in min_cost:
                    continue
                min_cost[node] = cost
                for nei, cost2 in adj_list[node]:
                    heapq.heappush(heap, (cost2 + cost, nei))
            return min_cost                

        min_cost_map = {c: dijkstra(c) for c in set(source)}
        res = 0
        for src, dest in zip(source, target):
            if dest not in min_cost_map[src]:
                return -1
            
            res += min_cost_map[src][dest]

        return res