class Solution:
    def reverse(self, head: ListNode) -> ListNode:
        curr = head
        prev = None

        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        return prev

    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:

        curr_head = self.reverse(head)
        stack = []
        ans = []

        while curr_head:
            while stack and stack[-1] <= curr_head.val:
                stack.pop()

            if not stack:
                ans.append(0)
            else:
                ans.append(stack[-1])

            stack.append(curr_head.val)
            curr_head = curr_head.next

        return ans[::-1]