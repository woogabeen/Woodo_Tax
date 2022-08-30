#include <bits/stdc++.h>
using namespace std;

int qualified_family_number, real_family_number, children_number;
//����������� ��, ���� ����������� ��, 7��~20�� ������ �ڳ��� ��
int monthly_salary, tax_percentage;
//����� �� ���ڱ��� ������ ���޿���(õ��), ���̼���ǥ�� ���� ������ ����
int lower_bound_standard[1010], standard_position;
//���޿��� ���� ����ǥ, ���޿����� ��ġ
double tax_value;
//���� �����ϴ� �ҵ漼

struct data{
   int number[1010] = {0};
}tax[13];

int main() {
   printf("�� ���̼���ǥ�� �ش� ������ �ҵ漼���� ���� �ٷμҵ����, �⺻����, Ư���ҵ���� �� Ư�����װ��� �� �Ϻ�, ���ݺ�������, �ٷμҵ漼�װ����� �ش� ������ �ݿ��Ͽ� ����� �ݾ���. �� ��� ��Ư���ҵ���� �� Ư�����װ��� �� �ϺΡ��� ������ ���Ŀ� ���� ����� �ݾ��� �ҵ�����Ͽ� �ݿ��� ����.\n\n");
   printf("�ξ簡���� ���� �Է����ּ���(���� �� ����ڵ� ���� 1������ ���� ����Ͽ��� �մϴ�.) : ");
   scanf("%d", &real_family_number);
   printf("\n");
   printf("7�� �̻� 20�� ���� �ڳ��� ���� �Է����ּ��� : ");
   scanf("%d", &children_number);
   printf("\n");
   qualified_family_number = real_family_number+children_number;
   printf("����� �� �ڳ� ���ڱ� �����ݾ��� ������ �� �޿����� �Է����ּ���(õ�� ����) : ");
   scanf("%d", &monthly_salary);
   printf("\n");
   printf("�����Ͻ� ������ ����(80%%, 100%%, 120%%)�� �Է����ּ���. �������� �ƴ��� ��� 100(%%)�� �Է����ּ��� : ");
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
   //�ٷμҵ� ���̼���ǥ 2021�� 2�� ����.

   int s = 1, e = 653;
   while(s <= e) {
      int mid = (s+e)/2;
      if(lower_bound_standard[mid] < monthly_salary) s = mid+1;
      else e = mid-1;
   }
   standard_position = s;
   //���޿����� ����ǥ���� ��� ������ ���

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
   printf("�Է��Ͻ� �����͸� �������� ����� ������������� ���� %d�� �Դϴ�.\n", qualified_family_number);
   printf("�̶��� ��õ¡�������� %d��(�ҵ漼 %d��, ����ҵ漼 %d��) �Դϴ�.\n", int(tax_value*1.1), int(tax_value), int(tax_value*0.1));
   return 0;
}
