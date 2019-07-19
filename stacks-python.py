class stacks:
    def __init__(self):
        self.items = []

    def push(self,value):
        self.items.append(value)
        print self.items
    def pop(self):
        del self.items[-1]
        print self.items
    def isEmpty(self):
        return self.items == []

if __name__ == '__main__':

    s = stacks()
    #POP if client enters -
    while True:
        input_string = raw_input('Enter string ')
        if input_string == '-':
            if not s.isEmpty():
                s.pop()
            else:
                print "Stack is empty."
                break
        else:
            s.push(input_string)

'''
OUTPUT
Enter string 1
['1']
Enter string 3
['1', '3']
Enter string 5
['1', '3', '5']
Enter string 7
['1', '3', '5', '7']
Enter string 9
['1', '3', '5', '7', '9']
Enter string -
['1', '3', '5', '7']
Enter string -
['1', '3', '5']
Enter string -
['1', '3']
Enter string -
['1']
Enter string -
[]
Enter string -
Stack is empty.

'''
