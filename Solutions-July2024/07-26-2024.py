class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        adj = defaultdict(list)
        for s, d, dist in edges:
            adj[s].append((d, dist))
            adj[d].append((s, dist))

        def dijkstra(src):
            heap = [(0, src)]
            visited = set()
            while heap:
                dist, node = heapq.heappop(heap)
                if node in visited:
                    continue
                visited.add(node)

                for nei, dist2 in adj[node]:
                    if dist + dist2 <= distanceThreshold:
                        heapq.heappush(heap, (dist+dist2, nei))
            return len(visited)-1

        res = -1
        min_count = n

        for src in range(n):
            count = dijkstra(src)
            if count <= min_count:
                res = src
                min_count = count

        return res