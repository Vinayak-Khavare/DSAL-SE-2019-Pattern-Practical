# second hash technique  ---> Linear probing
class HashTable:
    def __init__(self, capacity):
        self.capacity = capacity
        self.table = [None] * capacity
        self.filled = 0  # Track filled slots

    def _hash(self, key):
        # Simple hash function (can be improved)
        return key % self.capacity

    def insert(self, key, value):
        index = self._hash(key)
        for i in range(self.capacity):
            new_index = (index + i) % self.capacity
            if self.table[new_index] is None:
                self.table[new_index] = (key, value)
                self.filled += 1
                return
            elif self.table[new_index][0] == key:
                self.table[new_index] = (key, value)  # Update existing key
                return

    def get(self, key):
        index = self._hash(key)
        for i in range(self.capacity):
            new_index = (index + i) % self.capacity
            if self.table[new_index] is None:
                return None
            elif self.table[new_index][0] == key:
                return self.table[new_index][1]
        return None

    def compare_performance(self, keys):
        # Count comparisons for linear probing
        comparisons = 0
        for key in keys:
            index = self._hash(key)
            for i in range(self.capacity):
                new_index = (index + i) % self.capacity
                comparisons += 1
                if self.table[new_index] is None or self.table[new_index][0] == key:
                    break
        return comparisons
