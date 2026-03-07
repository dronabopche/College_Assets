# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, left: ListNode, right: ListNode) -> None:
        temp = left
        arr = []
        
        while temp != right:
            arr.append(temp.val)
            temp = temp.next
        arr.append(right.val) 
        
        arr = arr[::-1]
        
        temp = left
        i = 0
        while temp != right:
            temp.val = arr[i]
            temp = temp.next
            i += 1
        right.val = arr[-1] 

    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or left == right:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        
        for _ in range(left - 1):
            prev = prev.next

        left_node = prev.next
        right_node = left_node
        
        for _ in range(right - left):
            right_node = right_node.next
        
        after_right = right_node.next

        self.reverse(left_node, right_node)
        
        return dummy.next