class quickunion:
    def __init__(self,N):
        self.N = N
        self.idx = []
        for i in range(0,N):
            self.idx.append(i)

    def root(self,i):
        while(i != self.idx[i]):
            i = self.idx[i]
        return i

    def connected(self,p,q):
        return bool(self.root(p)==self.root(q))

    def union(self,p,q):
        self.p = p
        self.q = q
        pid = self.root(p)
        qid = self.root(q)
        self.idx[pid] = qid

if __name__ == '__main__':
    qu = quickunion(10)
    print qu.root(2)
    qu.union(1,2)
    print qu.connected(1,2)
    print qu.connected(3,4)


    #OUTPUT

    #2
    #True
    #False
