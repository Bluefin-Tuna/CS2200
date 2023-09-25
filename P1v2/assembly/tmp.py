check = pow =  []
with open("check.hex", "r") as file:
    check = file.readlines()
with open("pow.hex", "r") as f:
    pow = f.readlines()

for i in range(len(check)):
    if check[0].lower() != pow[0].lower():
        print(check[0], pow[0])