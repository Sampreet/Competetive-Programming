def birthday_cake_candles(arr):
    ans = arr.count(max(arr))
    
    print(ans)

if __name__ == '__main__':
    n = int(input())
    
    arr = list(map(int, input().rstrip().split()))

    birthday_cake_candles(arr)