//ɾ������ʵ��(ɾ��[s,t]֮���Ԫ��)
#include "seqlist.h"//�����Լ�д��ͷ����
#include<malloc.h>
#include<algorithm>

using namespace std;
//���˷��㷨ʵ��(��Ӧ�����ɾ��[s,t]֮���Ԫ��)
void deleteElem1(ElemType s,ElemType t,SeqList &L){
     int length=0;
     for(int i=0;i<L.length;i++){
        if(L.Data[i]<s||L.Data[i]>t)
            L.Data[length++]=L.Data[i];
     }
     L.length=length;

}
//ƫ�Ʒ�ʵ��(��Ӧɾ���ǵݼ������е�[s,t]֮���Ԫ��)
void deleteElem2(ElemType s,ElemType t,SeqList &L){
     int left=0,right=L.length-1;
     while(left<L.length && L.Data[left]<s){
          left++;
     }
      while(right>=0 && L.Data[right]>t){
          right--;
     }
     for(int i=left;i<L.length-right+left;i++){
          L.Data[i]=L.Data[i+right-left+1];
     }
     L.length-=(right-left+1);
}
//���˷��ǵݼ�����ȥ��
void deleteElem3(SeqList &L){
     int length=0;
     for(int i=0;i<L.length;i++){
          if(length==0||L.Data[length]!=L.Data[i])
           L.Data[length++]=L.Data[i];      
  }
          L.length=length;
}


int main(){
    SeqList L;
    InitList(L);
    ChuList(L);
     printf("ԭ����Ϊ:\n");
          print(L);
    //
    deleteElem1(3,5,L);
          print(L);
     //�����Ϊ�ǵݼ�����
     sort(L.Data,L.Data+L.length);
     printf("�ǵݼ�����Ϊ\n");
          print(L);
     deleteElem2(7,8,L);
          print(L);
return 0;
}