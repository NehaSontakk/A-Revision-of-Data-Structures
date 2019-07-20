class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        #rear is at position 0
        self.items.insert(0,item)
        print self.items

    def dequeue(self):
        #removes front element of list
        print self.items
        return self.items.pop()

    def size(self):
        return len(self.items)

if __name__ == '__main__':
    q = Queue()
    while True:
        input_string = raw_input("Enter string to add to Q: ")
        if input_string == "-":
            if len(q.items) == 0:
                print "Queue is empty."
                break
            else:
                q.dequeue()
        else:
            q.enqueue(input_string)

'''
OUTPUT
Enter string to add to Q: a
['a']
Enter string to add to Q: b
['b', 'a']
Enter string to add to Q: c
['c', 'b', 'a']
Enter string to add to Q: -
['c', 'b', 'a']
Enter string to add to Q: -
['c', 'b']
Enter string to add to Q: -
['c']
Enter string to add to Q: -
Queue is empty.
'''
