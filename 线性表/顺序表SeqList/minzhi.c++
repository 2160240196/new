#include<seqlist.h>
#include<malloc.h>
//ɾ����СԪ��
void minz(SeqList &L){
    int temp=L.Data[0];
    for(int i=0;i<L.length;i++){
        if(temp>L.Data[i])
            temp=L.Data[i];
    }

}
int main(){
    SeqList L;
     InitList(L);
    ChuList(L);
    print(L);

}