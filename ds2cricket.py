def intersection(l1,l2):
    res = []
    for student in l1:
        if student in l2:
            res.append(student)
    return res
def union(l1,l2):
    res = l2.copy()
    for student in l1:
        if not student in l2:
             res.append(student)
    return res
def diff(l1,l2):
    res = []
    for student in l1:
        if not student in l2:
             res.append(student)
    return res
a = [1,2,3,4,5,6,7]
b = [2,3,6,7,9,10]
c = [2,4,6,8,10,12]
print(f"A(Cricket) ={a} \nB(Badminton) ={b} \nC(Football) ={c} \n")
print(f"a.List of students who play both cricket and badminton:{intersection(a,b)}")
print(f"b.List of students who play either cricket or badminton but not both:{diff(union(a,b), intersection(a,b))}")
print(f"c.Number of students who play neither cricket nor badminton:{diff(diff(c,b),a)}")
print(f"d.Number of students who play cricket and football but not badminton:{diff(union(a,c),b)}")
