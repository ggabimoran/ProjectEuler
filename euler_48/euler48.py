#!/usr/bin/env python3
import time
start_time = time.time()
sum=0
for k in range(1,1001):
    sum+=(k**k)
sum = str(sum)
print(sum[-10:])
print("---%s seconds ---" % (time.time()-start_time))

'''---0.010003328323364258 seconds ---'''

start_time2 = time.time()

def last10digits(number):
    st=str(number)
    if (len(st)>10):
        st=st[-10:]
    return int(st)

def l10d_iterative_power(x,y):
    res=1
    while (y>1):
        if (y%2==1):
            res=res*x
            res=last10digits(res)
        x=x*x
        x=last10digits(x)
        y=y//2
    res = res*x
    res = last10digits(res)
    return res

def euler48(max):
    S=0
    for k in range(1,max+1):
        S+=l10d_iterative_power(k,k)
    return S

print(euler48(1000))
print("---%s seconds ---" % (time.time()-start_time2))
'''---0.009464263916015625 seconds ---'''
