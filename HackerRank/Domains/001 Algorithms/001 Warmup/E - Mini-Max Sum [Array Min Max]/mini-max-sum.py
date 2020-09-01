def mini_max_sum(arr):
    min_sum = sum(arr) - max(arr)
    max_sum = sum(arr) - min(arr)

    print('{0} {1}'.format(min_sum, max_sum))

if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    mini_max_sum(arr)