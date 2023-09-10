# Enter your code here. Read input from STDIN. Print output to STDOUT

class Stack:
    def __init__(self):
        self.items = []
        
    def push_back(self, val):
        self.items.append(val)
        
    def empty(self):
        return True if not self.items else False
        
    def pop_back(self):
        val = self.items[-1]
        del self.items[-1]
        return val
    
    def back(self):
        return self.items[-1]
    
class Queue:
    def __init__(self):
        self.tail = Stack()
        self.head = Stack()
        
    def enqueue(self, val):
        self.tail.push_back(val)
        
    def dequeue(self):
        #if not self.head.empty():
        
        #else:
        if self.head.empty():
            while not self.tail.empty():
                self.head.push_back(self.tail.pop_back())
        
        self.head.pop_back()
        
    def print(self):
        if self.head.empty():
            while not self.tail.empty():
                self.head.push_back(self.tail.pop_back())
        print(self.head.back())

if __name__ == "__main__":
    myq = Queue()
    q = int(input())
    for i in range(q):
        cmds = input().split()
        if len(cmds) > 1:
            cmd = int(cmds[0])
            arg = int(cmds[1])
        else:
            cmd = int(cmds[0])
            
        if cmd == 1:
            myq.enqueue(arg)
        elif cmd == 2:
            myq.dequeue()
        else:
            myq.print()
