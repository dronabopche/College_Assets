lst = list(map(int, input("Enter list: ").split()))
key = int(input("Search key: "))
if key in lst:
    print(f"Found at index {lst.index(key)}")
else:
    print("Not found")
