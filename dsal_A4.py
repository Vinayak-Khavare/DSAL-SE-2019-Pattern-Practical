# To create ADT that implement the "set" concept. a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the value 
# c. Contains (element) Return true if element is in collection, d. Size () Return number of values in collection Iterator () Return an 
# iterator used to loop over collection, e. Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset

class Set:
    def __init__(self) -> None:
        self.data = {}
    
    def add(self, element):
        self.data[element] = True
        
    def remove(self, element):
        if element in self.data:
            del self.data[element]
    
    def contains(self, element):
        return element in self.data
    
    def size(self):
        return len(self.data)
    
    def __iter__(self):
        return iter(self.data.keys())
    
    def intersection(self, other_set):
        dict = {}
        for key in self.data:
            if key in other_set.data:
                dict[key]=True
        return tuple([i for i in dict])           
    
    def union(self, other_set):
        dict = {}
        for i in self.data:
            dict[i]=True
        for i in other_set.data:
            dict[i]=True
        return tuple([i for i in dict])
        
    def difference(self, other_set):
        dict = {}
        for i in self.data:
            if i not in other_set.data:
                dict[i]=True
        return tuple([i for i in dict])
        
    def subset(self, other_set):
        return all(element in other_set.data for element in self.data)
    
A = Set()
B = Set()
A.add(32)
A.add(24)
A.add(2)
A.add(0)
B.add(21)
B.add(28)
B.add(67)
B.add(2)
B.add(0)
A.remove(0)
print(A.contains(12))
print(A.size())
print(A.__iter__())
print(A.union(B))
print(A.intersection(B))
print(B.difference(A))

