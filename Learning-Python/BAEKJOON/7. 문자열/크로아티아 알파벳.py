cro_alphabet = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

string = input()
# string = "ljes=njak"

for i in cro_alphabet:
    if i in string:
        string = string.replace(i, "*")

print(len(string))
