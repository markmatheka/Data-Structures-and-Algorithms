class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseList(head: ListNode) -> ListNode:
    prev = None
    curr = head
    while curr:
        next_node = curr.next   
        curr.next = prev        
        prev = curr            
        curr = next_node
    return prev  


node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)
node5 = ListNode(5)
node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5

reversed_head = reverseList(node1)

current = reversed_head
while current:
    print(current.val, end=" -> ")
    current = current.next
print("None")  