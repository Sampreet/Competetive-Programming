def simple_array_sum(arr):
    ans = sum(arr)

    print(ans)

if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    simple_array_sum(arr)