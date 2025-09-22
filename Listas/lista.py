class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_list(head):
    temp = head
    while temp is not None:
        print(f"{temp.data} -> ", end="")
        temp = temp.next
    print("None")

def main():
    head = Node(10)
    current = head

    # Crear 999 nodos adicionales (en total serán 1000)
    for i in range(1, 1000):
        new_node = Node(10 + i)
        current.next = new_node
        current = new_node

    print_list(head)

if __name__ == "__main__":
    main()