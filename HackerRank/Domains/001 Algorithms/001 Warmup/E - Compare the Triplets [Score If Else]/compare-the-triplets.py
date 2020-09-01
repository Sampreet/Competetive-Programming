def compare_the_triplets(arr_a, arr_b):
    n = len(arr_a)

    a = sum([1 for i in range(n) if arr_a[i] > arr_b[i]])
    b = sum([1 for i in range(n) if arr_a[i] < arr_b[i]])
    
    print(str(a) + ' ' + str(b))

if __name__ == '__main__':
    arr_a = list(map(int, input().rstrip().split()))
    arr_b = list(map(int, input().rstrip().split()))

    compare_the_triplets(arr_a, arr_b)