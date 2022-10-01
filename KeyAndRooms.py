class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        #visited = [False for i in range(len(rooms))]
        visited = set()
        def dfs(i):
            if i in visited:
                return
            visited.add(i)
            for child in rooms[i]:
                dfs(child)
        dfs(0)
        return len(rooms) == len(visited)
