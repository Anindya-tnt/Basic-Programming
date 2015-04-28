arr=map(int,raw_input().split(' '));
max = arr[0];
for i in arr:
    if(max<i):
        max=i;
print max

