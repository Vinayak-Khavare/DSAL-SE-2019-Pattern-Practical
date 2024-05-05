# first hash technique  --> Seperate chaining

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashTable:
    def __init__(self, capacity):
        self.capacity = capacity
        self.table = [None] * capacity

    def _hash(self, key):
        # Simple hash function (can be improved)
        return key % self.capacity

    def insert(self, key, value):
        index = self._hash(key)
        if self.table[index] is None:
            self.table[index] = Node(key, value)
        else:
            # Collision handling (separate chaining)
            temp = self.table[index]
            while temp.next is not None:
                temp = temp.next
            temp.next = Node(key, value)

    def get(self, key):
        index = self._hash(key)
        temp = self.table[index]
        while temp:
            if temp.key == key:
                return temp.value
            temp = temp.next
        return None

    def compare_performance(self, keys):
        # Count comparisons for separate chaining
        comparisons = 0
        for key in keys:
            index = self._hash(key)
            temp = self.table[index]
            while temp:
                comparisons += 1
                if temp.key == key:
                    break
                temp = temp.next
        return comparisons
