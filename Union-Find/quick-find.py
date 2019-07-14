class quickfind:
  #  int count
    def __init__(self,N):
        self.N = N
        self.count = N
        self.idx = []

    def qf(self):
        for i in range(0,self.N):
            self.idx.append(i)
        print self.idx

    def countz(self):
        print self.count

    def quick_find(self,p):
        return self.idx[p]

    def connected(self,p,q):
        return bool(self.quick_find(p)==self.quick_find(q))

    def union(self,p,q):
        pid = self.quick_find(p)
        qid = self.quick_find(q)
        if pid == qid:
            return
        for j in range(len(self.idx)):
            if self.idx[j] == pid:
                self.idx[j] = qid
        self.count = self.count-1
        print pid,qid

if __name__ == "__main__":
    qf = quickfind(5)
    qf.qf()
    qf.countz()
    qf.union(1,2)
    qf.connected(1,2)
    qf.union(3,2)
    qf.connected(3,2)
    qf.union(0,1)
    print qf.connected(0,1)
    print qf.connected(4,1)
    print qf.quick_find(3)
    print "These union operations form ",qf.count," seperate components."

#OUTPUT:
# [0, 1, 2, 3, 4]
#5
#1 2
#3 2
#0 2
#True
#False
#2
#These union operations form  2  seperate components.
#[Finished in 0.0s]
