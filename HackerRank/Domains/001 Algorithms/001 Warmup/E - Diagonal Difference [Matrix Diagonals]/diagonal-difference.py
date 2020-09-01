def diagonal_difference(arr):
    s1, s2 = 0, 0

    for i in range(len(arr)):
        s1 += arr[i][i]
        s2 += arr[i][len(arr) - 1 - i]

    ans = abs(s1 - s2)

    print(ans)

if __name__ == '__main__':
    n = int(input())

    arr = []

    for i in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    diagonal_difference(arr)