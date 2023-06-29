num = int(input())
num_list = list(map(int, input().split()))

num_list.sort()

if divmod(num_list.__len__(),2)[1] == 1:
   mid = num_list[divmod(num_list.__len__(),2)[0]]
   print(mid*mid)
else:
   print(num_list[0] * num_list[num_list.__len__() - 1])