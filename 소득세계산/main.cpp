#include <bits/stdc++.h>
using namespace std;

int qualified_family_number, real_family_number, children_number;
//공제대상가족의 수, 실제 공제대상가족의 수, 7세~20세 사이의 자녀의 수
int monthly_salary, tax_percentage;
//비과세 및 학자금을 제외한 월급여액(천원), 간이세액표에 따른 세액의 비율
int lower_bound_standard[1010], standard_position;
//월급여액 구분 기준표, 월급여액의 위치
double tax_value;
//실제 내야하는 소득세

struct data{
   int number[1010] = {0};
}tax[13];

int main() {
   printf("이 간이세액표의 해당 세액은 소득세법에 따른 근로소득공제, 기본공제, 특별소득공제 및 특별세액공제 중 일부, 연금보험료공제, 근로소득세액공제와 해당 세율을 반영하여 계산한 금액임. 이 경우 “특별소득공제 및 특별세액공제 중 일부”는 다음의 계산식에 따라 계산한 금액을 소득공제하여 반영한 것임.\n\n");
   printf("부양가족의 수를 입력해주세요(본인 및 배우자도 각각 1명으로 보아 계산하여야 합니다.) : ");
   scanf("%d", &real_family_number);
   printf("\n");
   printf("7세 이상 20세 이하 자녀의 수를 입력해주세요 : ");
   scanf("%d", &children_number);
   printf("\n");
   qualified_family_number = real_family_number+children_number;
   printf("비과세 및 자녀 학자금 지원금액을 제외한 월 급여액을 입력해주세요(천원 단위) : ");
   scanf("%d", &monthly_salary);
   printf("\n");
   printf("선택하신 세액의 비율(80%%, 100%%, 120%%)을 입력해주세요. 선택하지 아니한 경우 100(%%)를 입력해주세요 : ");
   scanf("%d", &tax_percentage);
   printf("\n");

   freopen("standard.txt", "r", stdin);
   for (int i = 1; i <= 653; i++) scanf("%d", &lower_bound_standard[i]);
   freopen("1person.txt", "r", stdin);
   for (int i = 59; i <= 647; i++) scanf("%d", &tax[1].number[i]);
   freopen("2person.txt", "r", stdin);
   for (int i = 115; i <= 647; i++) scanf("%d", &tax[2].number[i]);
   freopen("3person.txt", "r", stdin);
   for (int i = 169; i <= 647; i++) scanf("%d", &tax[3].number[i]);
   freopen("4person.txt", "r", stdin);
   for (int i = 186; i <= 647; i++) scanf("%d", &tax[4].number[i]);
   freopen("5person.txt", "r", stdin);
   for (int i = 203; i <= 647; i++) scanf("%d", &tax[5].number[i]);
   freopen("6person.txt", "r", stdin);
   for (int i = 220; i <= 647; i++) scanf("%d", &tax[6].number[i]);
   freopen("7person.txt", "r", stdin);
   for (int i = 237; i <= 647; i++) scanf("%d", &tax[7].number[i]);
   freopen("8person.txt", "r", stdin);
   for (int i = 254; i <= 647; i++) scanf("%d", &tax[8].number[i]);
   freopen("9person.txt", "r", stdin);
   for (int i = 270; i <= 647; i++) scanf("%d", &tax[9].number[i]);
   freopen("10person.txt", "r", stdin);
   for (int i = 286; i <= 647; i++) scanf("%d", &tax[10].number[i]);
   freopen("11person.txt", "r", stdin);
   for (int i = 299; i <= 647; i++) scanf("%d", &tax[11].number[i]);
   //근로소득 간이세액표 2021년 2월 기준.

   int s = 1, e = 653;
   while(s <= e) {
      int mid = (s+e)/2;
      if(lower_bound_standard[mid] < monthly_salary) s = mid+1;
      else e = mid-1;
   }
   standard_position = s;
   //월급여액이 기준표에서 어디에 들어가는지 계산

   if(qualified_family_number <= 11) {
      if(standard_position <= 647) {
         tax_value = double(tax[qualified_family_number].number[standard_position]);
      }
      else if(standard_position == 648) {
         tax_value = double(tax[qualified_family_number].number[647])+double(monthly_salary-10000)*1000*0.98*0.35;
      }
      else if(standard_position == 649) {
         tax_value = double(tax[qualified_family_number].number[647])+1372000+double(monthly_salary-14000)*1000*0.98*0.38;
      }
      else if(standard_position == 650) {
         tax_value = double(tax[qualified_family_number].number[647])+6585600+double(monthly_salary-28000)*1000*0.98*0.4;
      }
      else if(standard_position == 651) {
         tax_value = double(tax[qualified_family_number].number[647])+7369600+double(monthly_salary-30000)*1000*0.4;
      }
      else if(standard_position == 652) {
         tax_value = double(tax[qualified_family_number].number[647])+13369600+double(monthly_salary-45000)*1000*0.42;
      }
      else if(standard_position == 653) {
         tax_value = double(tax[qualified_family_number].number[647])+31009600+double(monthly_salary-87000)*1000*0.45;
      }
   }
   else {
      if(standard_position <= 647) {
         tax_value = double(tax[10].number[standard_position]);
         tax_value -= double(tax[11].number[standard_position]);
      }
      else if(standard_position == 648) {
         tax_value = double(tax[10].number[647])+double(monthly_salary-10000)*1000*0.98*0.35;
         tax_value -= double(tax[11].number[647])+double(monthly_salary-10000)*1000*0.98*0.35;
      }
      else if(standard_position == 649) {
         tax_value = double(tax[10].number[647])+1372000+double(monthly_salary-14000)*1000*0.98*0.38;
         tax_value -= double(tax[11].number[647])+1372000+double(monthly_salary-14000)*1000*0.98*0.38;
      }
      else if(standard_position == 650) {
         tax_value = double(tax[10].number[647])+6585600+double(monthly_salary-28000)*1000*0.98*0.4;
         tax_value -= double(tax[11].number[647])+6585600+double(monthly_salary-28000)*1000*0.98*0.4;
      }
      else if(standard_position == 651) {
         tax_value = double(tax[10].number[647])+7369600+double(monthly_salary-30000)*1000*0.4;
         tax_value -= double(tax[11].number[647])+7369600+double(monthly_salary-30000)*1000*0.4;
      }
      else if(standard_position == 652) {
         tax_value = double(tax[10].number[647])+13369600+double(monthly_salary-45000)*1000*0.42;
         tax_value -= double(tax[11].number[647])+13369600+double(monthly_salary-45000)*1000*0.42;
      }
      else if(standard_position == 653) {
         tax_value = double(tax[10].number[647])+31009600+double(monthly_salary-87000)*1000*0.45;
         tax_value -= double(tax[11].number[647])+31009600+double(monthly_salary-87000)*1000*0.45;
      }
      tax_value *= (qualified_family_number-11);
   }
   printf("입력하신 데이터를 바탕으로 계산한 공제가족대상의 수는 %d명 입니다.\n", qualified_family_number);
   printf("이때의 원천징수세액은 %d원(소득세 %d원, 지방소득세 %d원) 입니다.\n", int(tax_value*1.1), int(tax_value), int(tax_value*0.1));
   return 0;
}
