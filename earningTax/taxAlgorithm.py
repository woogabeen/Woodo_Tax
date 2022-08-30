lower_bound_standard = [0 for i in range(1010)]
tax_number = [[0 for i in range(1010)] for j in range(13)]
tax_value = 0.0

print("이 간이세액표의 해당 세액은 소득세법에 따른 근로소득공제, 기본공제, 특별소득공제 및 특별세액공제 중 일부, 연금보험료공제, 근로소득세액공제와 해당 세율을 반영하여 계산한 금액임. 이 경우 “특별소득공제 및 특별세액공제 중 일부”는 다음의 계산식에 따라 계산한 금액을 소득공제하여 반영한 것임.\n")
real_family_number = int(input('부양가족의 수를 입력해주세요(본인 및 배우자도 각각 1명으로 보아 계산하여야 합니다.) : ')) 
children_number = int(input('7세 이상 20세 이하 자녀의 수를 입력해주세요 : '))
qualified_family_number = real_family_number+children_number

monthly_salary = int(input('비과세 및 자녀 학자금 지원금액을 제외한 월 급여액을 입력해주세요(천원 단위) : '))
tax_percentage = int(input('선택하신 세액의 비율(80%%, 100%%, 120%%)을 입력해주세요. 선택하지 아니한 경우 100(%%)를 입력해주세요 : '))

f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/standard.txt")
for i in range(1, 654):
    line = f.readline()
    if line =='':
        break
    lower_bound_standard[i] = int(line)

f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/1person.txt")
for i in range(59, 648):
    tax_number[1][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/2person.txt")
for i in range(115, 648):
    tax_number[2][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/3person.txt")
for i in range(169, 648):
    tax_number[3][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/4person.txt")
for i in range(186, 648):
    tax_number[4][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/5person.txt")
for i in range(203, 648):
    tax_number[5][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/6person.txt")
for i in range(220, 648):
    tax_number[6][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/7person.txt")
for i in range(237, 648):
    tax_number[7][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/8person.txt")
for i in range(254, 648):
    tax_number[8][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/9person.txt")
for i in range(270, 648):
    tax_number[9][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/10person.txt")
for i in range(286, 648):
    tax_number[10][i] = int(f.readline())
f = open("/Users/woogabeen/Desktop/Coding/python/earningTax/11person.txt")
for i in range(299, 648):
    tax_number[11][i] = int(f.readline())

s = 1
e = 653
while s <= e:
    mid = int((s+e)/2)
    if lower_bound_standard[mid] < monthly_salary:
        s = mid+1
    else:
        e = mid-1
standard_position = s

if qualified_family_number <= 11:
    if standard_position <= 647:
        tax_value = float(tax_number[qualified_family_number][standard_position])
    elif standard_position == 648:
        tax_value = float(tax_number[qualified_family_number][647])+float(monthly_salary-10000)*1000*0.98*0.35
    elif standard_position == 649:
        tax_value = float(tax_number[qualified_family_number][647])+1372000+float(monthly_salary-14000)*1000*0.98*0.38
    elif standard_position == 650:
        tax_value = float(tax_number[qualified_family_number][647])+6585600+float(monthly_salary-28000)*1000*0.98*0.4
    elif standard_position == 651:
        tax_value = float(tax_number[qualified_family_number][647])+7369600+float(monthly_salary-30000)*1000*0.4
    elif standard_position == 652:
        tax_value = float(tax_number[qualified_family_number][647])+13369600+float(monthly_salary-45000)*1000*0.42
    else:
        tax_value = float(tax_number[qualified_family_number][647])+31009600+float(monthly_salary-87000)*1000*0.45

else:
    if standard_position <= 647:
        tax_value = float(tax_number[10][standard_position])
        tax_value -= float(tax_number[11][standard_position])
    elif standard_position == 648:
        tax_value = float(tax_number[10][647])+float(monthly_salary-10000)*1000*0.98*0.35
        tax_value -= float(tax_number[11][647])+float(monthly_salary-10000)*1000*0.98*0.35
    elif standard_position == 649:
        tax_value = float(tax_number[10][647])+1372000+float(monthly_salary-14000)*1000*0.98*0.38
        tax_value -= float(tax_number[11][647])+1372000+float(monthly_salary-14000)*1000*0.98*0.38
    elif standard_position == 650:
        tax_value = float(tax_number[10][647])+6585600+float(monthly_salary-28000)*1000*0.98*0.4
        tax_value -= float(tax_number[11][647])+6585600+float(monthly_salary-28000)*1000*0.98*0.4
    elif standard_position == 651:
        tax_value = float(tax_number[10][647])+7369600+float(monthly_salary-30000)*1000*0.4
        tax_value -= float(tax_number[11][647])+7369600+float(monthly_salary-30000)*1000*0.4
    elif standard_position == 652:
        tax_value = float(tax_number[10][647])+13369600+float(monthly_salary-45000)*1000*0.42
        tax_value -= float(tax_number[11][647])+13369600+float(monthly_salary-45000)*1000*0.42
    else:
        tax_value = float(tax_number[10][647])+31009600+float(monthly_salary-87000)*1000*0.45
        tax_value -= float(tax_number[11][647])+31009600+float(monthly_salary-87000)*1000*0.45
    
    tax_value *= (qualified_family_number-11)

print("입력하신 데이터를 바탕으로 계산한 공제대상가족의 수는 %d명 입니다\n"%qualified_family_number)
print("이때의 원천징수세액은 %d원(소득세 %d원, 지방소득세 %d원) 입니다."%(int(tax_value*1.1), int(tax_value), int(tax_value*0.1)))

data = str(tax_value*1.1)
