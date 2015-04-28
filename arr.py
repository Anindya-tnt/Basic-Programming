arr=map(int,raw_input().split(' '));
max = arr[0];
for i in arr:
    if(max<arr[i]):
        max=arr[i];
print max

