"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        mapping = {}
        visited = set()
        def dfs(node, newNode):
            if not node or node in visited:
                return
            mapping[node] = newNode
            visited.add(node)
            for child in node.neighbors:
                if child in mapping:
                    temp = mapping[child]
                else:
                    temp = Node(child.val)
                newNode.neighbors.append(temp)
                dfs(child, temp)
            #print(node.val)
        dfs(node, Node(node.val))
        return mapping[node]
