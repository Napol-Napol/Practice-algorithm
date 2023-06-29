num = int(input())
date = num
day_list = []
money_list = []

total_money_list = []

while num:
    inputThing = list(map(int, input().split()))
    day_list.append(inputThing[0])
    money_list.append(inputThing[1])
    num -= 1

def findMoney(index:int, last_money:int):
    if(index >= day_list.__len__()):
        total_money_list.append(last_money)
    
    for j in range(index, day_list.__len__()):
        day = day_list[j]
        if(day + j) > date:
            total_money_list.append(last_money)
        else:
            next_day = day+j
            last_money += money_list[j]
            findMoney(next_day, last_money)  
            last_money -= money_list[j]
    return 0

next_date = 0
total_money = 0
for i in range(0, day_list.__len__()):
    next_date = i
    findMoney(next_date, total_money)

total_money_list.sort()
print(total_money_list[total_money_list.__len__() - 1])
