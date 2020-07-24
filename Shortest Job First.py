print("Enter the number of process: ")
n=int(input())
bt=[]
print("Enter burst time: \n")
bt=list(map(int, input().split()))
bt.sort()
wt=[]
avg=0
end=[]
wt.insert(0,0)
end.insert(0,bt[0])
for i in range(1,len(bt)):
 wt.insert(i,wt[i-1]+bt[i-1])
 end.insert(i,wt[i]+bt[i])
 avg+=wt[i]
avg=float(avg)/n
print(wt[0], end=" ")
for i in range(0,n):
 print(" "+"P"+str(i+1)+" "+str(end[i]), end=" ")
print("\n")
print("Average waiting time is: "+str(avg))

