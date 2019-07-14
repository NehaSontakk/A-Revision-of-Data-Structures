class unionfind:
  #  int count
    def __init__(self,N):
        self.N = N
        self.count = N
        self.idx = []

    def uf(self):
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
    uf = unionfind(5)
    uf.uf()
    uf.countz()
    uf.union(1,2)
    uf.connected(1,2)
    uf.union(3,2)
    uf.connected(3,2)
    uf.union(0,1)
    print uf.connected(0,1)
    print uf.connected(4,1)
    print uf.quick_find(3)
    print "These union operations form ",uf.count," seperate components."

