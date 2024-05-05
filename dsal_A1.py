class node:
    def __init__(self, name, num):
        self.name = name
        self.num = num
        self.next = None
    
class Hashtable:
    def __init__(self, size):
        self.size = size
        self.table = [None]*self.size
    
    def hashfunc(self, name):
        return hash(name)%self.size
    
    def line_probing(self, name, num):
        key = self.hashfunc(name)
        for i in range(self.size):
            index = (key+i)%self.size
            if(self.table[index] is None):
                self.table[index] = node(name, num)
            elif(self.table[index].name == name):
                self.table[index].num == num
        return
    
    def chaining(self, name, num):
        key = self.hashfunc(name)
        temp = self.table[key]
        while(temp is not None):
            temp = temp.next 
            com+=1
        temp = node(name, num)
        return
    
    def search(self, name):
        com=0
        key = self.hashfunc(name)
        for i in range(self.size):
            index = (key+i)%self.size
            temp = self.table[index]
            while(temp!=None):
                if(temp.name==name):
                    com+=1
                    print("comparisons:", com)
                    return [temp.name, temp.num]
                com+=1
                temp=temp.next     
            
hash_table = Hashtable(4)
hash_table.line_probing("roman", 98)
hash_table.line_probing("norma", 28)
hash_table.line_probing("sara", 22)
res=hash_table.search("roman")
print(res)