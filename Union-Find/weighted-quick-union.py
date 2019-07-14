class weightedqu:
    def __init__(self,N):
        self.N = N
        self.idx = []
        self.count = N
        self.size = []
        for i in range(0,N):
            self.idx.append(i)
        for i in range(0,N):
            self.size.append(1)

    def countz(self):
        return str(self.count)

    def connected(self,p,q):
        return bool(self.find(p)==self.find(q))

    def union(self,p,q):
        pid = self.find(p)
        qid = self.find(q)
        if pid == qid:
            return
        if self.size[pid]<self.size[qid]: #small root points to large root
            self.idx[pid] = qid
            self.size[qid]+=self.size[pid]
        else:
            self.idx[qid] = pid
            self.size[pid]+=self.size[qid]
            self.count = self.count - 1
        print pid,qid #connections

    def find(self,p):
        while(p != self.idx[p]):
            p = self.idx[p]
        return p

if __name__ == '__main__':
    wqu = weightedqu(10)
    wqu.union(2,3)
    print wqu.connected(2,3)
    wqu.union(2,7)
    print wqu.connected(2,7)
    print wqu.connected(2,5)
    print "components due to union",wqu.count

#OUTPUT
#2 3
#True
#2 7
#True
#False
#components due to union 8
