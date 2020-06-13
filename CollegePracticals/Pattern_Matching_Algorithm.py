str1 = input("Enter the String: ")
str2 = input("Enter the Pattern to be checked: ")
print('The length of String is : ' + str(len(str1)))
print('The length of Pattern is : ' + str(len(str2)))
l1 = len(str1)
l2 = len(str2)
k = 0
i = 0
count = 0
str3 = ""
loc = []
test = []
State = []
while k < l1:
    while i < l2:
        if (k == l1):
            break
        State.append([])
        State[k].append(i)
        State[k].append(str1[k])
        State[k].append(0)
        if (str1[k] == str2[i]):
            State[k][2] = i + 1
            str3 += str1[k]
            if (str3 == str2):
                loc.append(k - l2 + 1)
                i = 0
                State[k][2] = "P"
            else:
                i += 1
        else:
            i = 0
            str3 = ""
        k += 1
        count = count + 1

if (loc != test):
    print("Pattern Found")
    print("The Index of pattern is found to be : ")
    print(loc)
    print("The Number of Comparison are : " + str(count))
    k = 0
    print("The State Transition for given String are:")
    while k <= 11:
        strP = "q" + str(State[k][2])
        if (strP == "qP"):
            strP = "P"
        print("(q" + str(State[k][0]) + "," + State[k][1] + ")-->" + strP)
        k += 1
else:
      print("The Pattern is not found in the String")
print("The program is executed Successfully")