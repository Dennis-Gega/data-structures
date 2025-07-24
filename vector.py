class Vector:
    def __init__(self, capacity = 16):
        self.size = 0
        self.capacity = 16
        while capacity > self.capacity:
            self.capacity *= 2
        self.array = [0] * self.capacity
    
    def get_size(self):
        return self.size
    
    def get_capacity(self):
        return self.capacity
    
    def is_empty(self):
        return self.size == 0
    
    def at(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("list index out of range")
        return self.array[index]
    
    def push(self, value):
        # copy current array into bigger array
        if self.size == self.capacity:
            self._resize(self.capacity * 2)
            
        self.array[self.size] = value
        self.size += 1
    
    def insert(self, index, value):
        if index < 0 or index >= self.size:
            raise IndexError("list index out of range")
            
        if self.size == self.capacity:
            self._resize(self.capacity * 2)
            
        tmp = self.array[index]
        self.array[index] = value
        for i in range(index + 1, self.size + 1):
            self.array[i], tmp = tmp, self.array[i]
        self.size += 1
    
    def prepend(self, value):
        self.insert(0, value)
    
    def pop(self):
        if self.size == 0:
            raise IndexError("pop from empty list")
        
        self.size -= 1
        if self.size <= self.capacity / 4:
            self._resize(self.capacity / 2)
        
        tmp = self.array[self.size]
        self.array[self.size] = 0
        
        return tmp
    
    def delete(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("list index out of range")
        
        for i in range(index, self.size - 1):
            self.array[i] = self.array[i + 1]
        self.array[self.size] = 0
        
        self.size -= 1
        if self.size <= self.capacity / 4:
            self._resize(self.capacity / 2)
        
    
    def find(self, item):
        for i in range(self.size):
            if self.array[i] == item:
                return i
        return -1
        
    def remove(self, item):
        index = self.find(item)
        if index == -1:
            raise ValueError(f"{item} not in list")
        else:
            self.delete(index)
    
    def _resize(self, new_capacity):
        self.capacity = int(new_capacity)
        new_array = [0] * self.capacity
        
        for i in range(self.size):
            new_array[i] = self.array[i]
        
        self.array = new_array