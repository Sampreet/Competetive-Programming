def plus_minus(arr):
    N = len(arr)
    p = len([ele for ele in arr if ele > 0]) / N
    n = len([ele for ele in arr if ele < 0]) / N
    z = len([ele for ele in arr if ele == 0]) / N

    print('{0:0.6f}\n{1:0.6f}\n{2:0.6f}'.format(p, n, z))

if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plus_minus(arr)