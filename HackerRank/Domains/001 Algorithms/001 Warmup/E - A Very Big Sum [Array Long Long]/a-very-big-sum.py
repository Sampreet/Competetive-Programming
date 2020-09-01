def a_very_big_sum(arr):
    ans = sum(arr)

    print(ans)

if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    a_very_big_sum(arr)