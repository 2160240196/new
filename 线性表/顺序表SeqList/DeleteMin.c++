#include "seqlist.h"
#include<malloc.h>
//ɾ����СԪ�ز��ҽ����һ��Ԫ�ط�����ɾ��λ�á�
void DeteleMin(SeqList &L){
    int temp=0;
    for(int i=1;i<L.length;i++){
        if(L.Data[temp]>L.Data[i])
        {
            temp=i;
        }    
    }
    if(temp!=L.length)
        L.Data[temp]=L.Data[L.length-1];
    --L.length;
}
int main(){
    SeqList L;
    InitList(L);
    ChuList(L);
    print(L);
    //���Ե���СֵΪ���һ��Ԫ��ʱ
    //int o=L.Data[0];
    //L.Data[0]=L.Data[9];
    //L.Data[9]=o;
    DeteleMin(L);
    print(L);

}