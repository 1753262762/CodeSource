def DecToTer_int(d):
    if d==0:
        return 0
    ter=''
    while d>0:
        ter=str(d%3)+ter
        d//=3
    return ter


d=int(input())
t=DecToTer_int(d)
print("%s->%s",(d,t))
