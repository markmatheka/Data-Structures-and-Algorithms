def find_multiple_duplicates(arr):
    dups = {}
    result = []

    for i in range(len(arr)):
        if arr[i] not in dups:
           dups[arr[i]] = 1

        else:
           dups[arr[i]] += 1

    for val in dups.items():
        if val[1]>1:

           result.append(val[0])

    print(result)

arr = [1, 2, 4, 5, 2, 3, 4, 7] 

find_multiple_duplicates(arr)