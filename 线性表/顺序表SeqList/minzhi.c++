#include "seqlist.h"
#include<malloc.h>
//ɾ����СԪ�ز��ҽ����һ��Ԫ�ط�����ɾ��λ�á�
void minz(SeqList &L){
    int Min=L.Data[0],temp=0;
    for(int i=0;i<L.length;i++){
        if(Min>L.Data[i])
        {
            Min=L.Data[i];
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
    minz(L);
    print(L);

}