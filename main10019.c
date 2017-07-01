/*
===========UVA10019==========
===Funny Encryption Method===
�\��G������X�S��޳N��s�ǰ|�ҵo�����ƭȥ[�K�t��k
Steps : Example
1) ���]�ON = M = 265�����[�K���Ʀr
2) ��N�����Q�i��ƭȡA�OX1=265(�Q�i��)
3) ��X1�ѤQ�i���ର�G�i��A�GX1=100001001(�G�i��)
4) �w��H�G�i����ܪ�X1�p��@���X��1�AX1=100001001�@��3��1�A�Y�OB1=3
5) ��N�����Q���i��ƭȡA�OX2=265(�Q���i��)
6) ��X2�ѤQ���i���ର�G�i��A�GX2=1001100101(�G�i��)
7) �w��H�G�i����ܪ�X2�p��@���X��1�AX2=1001100101�@��5��1�A�Y�OB2=5
8) �̫᪺�s�X�� M xor (b1*b2) M xor (3*5) = 262
*/

#include <stdio.h>
#include <stdlib.h>

int b[20],h[20];
int b1=0,b2=0;

int hex(int a)//�N�Q���i����G�i��Ƶ{��
{
  int s[10];         //�ŧi�s��Q��ƼƭȰ}�C 
  int p=0,x=0,c=0;   //�ŧi�Q����,(�p���),�p�ƭ�
  int i;             //�ŧifor�j��}�C
  x=a;               //�N��ƶǵ�x
  while(x!=0){
    p=x/10; s[c]=x%10; x=p; c++;      //�Q����=x/10,�N�l�ưO����}�C��,p���ȶǵ�x,�p�ƭ�+1
  }
  for(i=0;i<c;i++){
    if(s[i]==0){h[(i*4)+3]=0; h[(i*4)+2]=0; h[(i*4)+1]=0; h[(i*4)]=0;}//�p�Gs=0,h=0000 
    if(s[i]==1){h[(i*4)+3]=0; h[(i*4)+2]=0; h[(i*4)+1]=0; h[(i*4)]=1;}//�p�Gs=1,h=0001
    if(s[i]==2){h[(i*4)+3]=0; h[(i*4)+2]=0; h[(i*4)+1]=1; h[(i*4)]=0;}//�p�Gs=2,h=0010
    if(s[i]==3){h[(i*4)+3]=0; h[(i*4)+2]=0; h[(i*4)+1]=1; h[(i*4)]=1;}//�p�Gs=3,h=0011
    if(s[i]==4){h[(i*4)+3]=0; h[(i*4)+2]=1; h[(i*4)+1]=0; h[(i*4)]=0;}//�p�Gs=4,h=0100
    if(s[i]==5){h[(i*4)+3]=0; h[(i*4)+2]=1; h[(i*4)+1]=0; h[(i*4)]=1;}//�p�Gs=5,h=0101
    if(s[i]==6){h[(i*4)+3]=0; h[(i*4)+2]=1; h[(i*4)+1]=1; h[(i*4)]=0;}//�p�Gs=6,h=0110
    if(s[i]==7){h[(i*4)+3]=0; h[(i*4)+2]=1; h[(i*4)+1]=1; h[(i*4)]=1;}//�p�Gs=7,h=0111
    if(s[i]==8){h[(i*4)+3]=1; h[(i*4)+2]=0; h[(i*4)+1]=0; h[(i*4)]=0;}//�p�Gs=8,h=1000
    if(s[i]==9){h[(i*4)+3]=1; h[(i*4)+2]=0; h[(i*4)+1]=0; h[(i*4)]=1;}//�p�Gs=9,h=1001
  }
  
  return c*4;
}
int bin(int a)//�N�Q�i����G�i��Ƶ{�� 
{
  int p=0,x=0,c=0;                 //�ŧi�Q����,(�p���),�p�ƭ� 
  x=a;                             //�N��ƶǵ�x
  while(x!=0){
    p=x/2; b[c]=x%2; x=p; c++;     //�Q����=x/2,�N�l�ưO����}�C��,p���ȶǵ�x,�p�ƭ�+1 
  }
  return c;                        //�N�p�ƭȦ^�� 
}
void method(int a)
{
  int x1=0,x2=0;  //�ŧi�ƭȪ����ܼ� 
  int i;          //�ŧifor�j��}�C
  
  b1=0; b2=0;                           //�N�p��1���ܼ��k0 
  x1=bin(a); x2=hex(a);                 //�N�Q�i���ন2�i��(x1),�Q���i���ন2�i��(x2) 
  for(i=0;i<x1;i++){if(b[i]==1) b1++;}  //�����G�i��1���Ӽ� 
  for(i=0;i<x2;i++){if(h[i]==1) b2++;}  //����16�i��1���Ӽ� 
  
}
int main(int argc, char *argv[])
{
  int n[1000]={0};      //�ŧi���[�K�}�C 
  int a=0;              //�ŧi�Ӽư}�C 
  int i;                //�ŧifor�j��}�C 
  
  scanf("%d",&a);                                          //��J���[�K�ƭȭӼ� 
  for(i=0;i<a;i++){scanf("%d",&n[i]);}                     //��J���[�K�ƭ� 
  for(i=0;i<a;i++){method(n[i]); printf("%d %d\n",b1,b2);} //�N�ƭȶǵ��Ƶ{��,�ñNb1,b2��X 
	
  return 0;
}