//˳��� A �� B ��Ԫ�ظ����ֱ�Ϊ m �� n ���� A �������򣬱� B ���������������ж���������ͬ��Ԫ�أ������
//(1��������ϲ��������е�Ԫ�ض��洢���ǵݼ��� C �С�
//(2���� A �� m + n ���洢�ռ䣬�� A �� B ����ϲ�������Ԫ�ض��洢��A�У�
//(3���� A ǰ r ��Ԫ�ص������򣬶��� A �к� n - r ��Ԫ�صݼ����򣬽��� A ������������

//(1����С�����ֵ���ƶϹ������£����������һ��������з��ʵ���������һ���򣨷ǵݼ� or �ǵ������Ľ��
//��������Ԫ�ض����򣬻�õĽ��ҲҪ��������ô�ڴ���Ĺ����б�ȻҪ��������������������ܽ����㷨��Ƶ��Ѷȡ�
#include "seqlist.h"//�����Լ�д��ͷ����
#include<malloc.h>
#include<algorithm>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}
void andElem1(SeqList &A,SeqList &B,SeqList &C){
    C.Data=(ElemType *)malloc(sizeof(ElemType)*(A.lengthSize+B.lengthSize));
    C.length=(A.length+B.length);
    C.lengthSize=2*C.length;
    int i=0,left=0,right=B.length-1;
    while(left<A.length&&right>=0){
        if(A.Data[left]<B.Data[right])
            C.Data[i++]=A.Data[left++];
        else 
            C.Data[i++]=B.Data[right--];
    }
    while(left<A.length){
        C.Data[i++]=A.Data[left++];
    }
     while(right>=0){
        C.Data[i++]=B.Data[right--];
    }
}
void andElem2(SeqList &A,SeqList &B){
   //A�ռ�Ϊm+n
    ElemType *pNew=(ElemType *)malloc(sizeof(ElemType)*(A.lengthSize+B.lengthSize));
       int L=A.length-1,R=0,newi=A.length+B.length-1;
       for(int i=0;i<A.length;i++){
            pNew[i]=A.Data[i];
       }
       free(A.Data);
       A.Data=pNew; 
       A.length=A.length+B.length;
       A.lengthSize=A.lengthSize+B.lengthSize;
       while(L>=0&&R<B.length&&newi>=0){
            if(A.Data[L]>B.Data[R])
                A.Data[newi--]=A.Data[L--];
            else 
                A.Data[newi--]=B.Data[R++];
       }
        while(L>=0&&newi>=0){
            A.Data[newi--]=A.Data[L--];;
        }
        while(R<B.length&&newi>=0){
            A.Data[newi--]=B.Data[R++];
        }
}
void andElem3(SeqList &A,int r){
    int left=r-1,right=r,temp=0;
    while(right<A.length){
        temp=A.Data[right];
        if(left>=0&&A.Data[left]>A.Data[right])
            left--;
        else{
                for(int i=right;i>left+1;i--){
                   A.Data[i]=A.Data[i-1];
                }  
            A.Data[left+1]=temp;
            right++;
        } 
    }
}
int main(){
    SeqList A,B,C;
    InitList(A,9);
    ChuList(A);
    InitList(B,10);
    ChuList(B);
    sort(A.Data,A.Data+A.length);
    sort(B.Data,B.Data+B.length,cmp);
     printf("ԭ����AΪ:\n");
          print(A);
     printf("ԭ����BΪ:\n");
          print(B);
    /*andElem1(A,B,C);
     printf("����CΪ:\n");
          print(C);
    */
    /*andElem2(A,B);
    printf("����AΪ:\n");
     print(A);
    */
   ElemType ces[9]={2,4,7,8,9,10,4,3,1};
     free(A.Data);
   A.Data=ces;
   printf("����AΪ:\n");
          print(A);
   andElem3(A,6);
      printf("���������AΪ:\n");
          print(A);
    return 0;
}