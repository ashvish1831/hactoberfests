"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        mapping = {}
        def build(head):
            if not head:
                return None
            if head in mapping:
                return mapping[head]
            newNode = Node(head.val)
            mapping[head] = newNode
            newNode.random = build(head.random)
            newNode.next = build(head.next)
            return newNode
        return build(head)
