#include <iostream>
using namespace std;

class TNode{
	
  public:
    
	int data;
    TNode *next;
};

TNode *up;
TNode *down;
TNode *del;

void init()
{
    up=NULL;
    down = NULL;
}

int isEmpty ()
{
	if (down==NULL){
	return true;
	}
	else{
	return false;
	}
}

void tambahDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        up=baru;
        down=baru;
        up->next=up;
        down->next=down;
    }
    else
    {
    	
        baru->next=up;
        up=baru;
        down->next=up;
    
	}
}

void tambahBelakang(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        up= baru;
        down = baru;
        up->next =up;
        down->next= down;
    }
    else
    {
        down->next = baru;
        down = baru;
        down->next =up;
    }
}

void cetak(){
    
        TNode *bantu;
        bantu =up;
    if (isEmpty() == 0){
		
        do{
            cout<<bantu->data<<"---->";
            bantu=bantu->next;
        }while (bantu!=down->next);
    } else {
        cout<<"List Kosong";
    }
}



void hapusDepan(){
	TNode *hapus;
	if (isEmpty()==0){
		int x;
		hapus =up;
		x =up->data;
		if(up!=down){
			hapus=up;
			up=up->next;
			down->next=up;
			delete hapus;
		}else{
			up=NULL;
			down=NULL;
		}
		cout<<"Hilang --> "<<x<<endl;
	} else cout<<"Kosong\n";
}

void hapusBelakang(){
	TNode *hapus,*bantu;
	if (isEmpty()==0){
		int y;
		if(up==down){
			y=down->data;
			up=NULL;
			down=NULL;
		}else{
			bantu=up;
			while(bantu->next != down){
				bantu = bantu->next;
			}
			hapus=down;
			down=bantu;
			y=hapus->data;
			down->next=up;
			delete hapus;
		}
		cout<<"Hilang "<<y<<endl;
	} else cout<<"Kosong\n";
}

void insertNode(int databaru, int datasebelum){
	
	   	TNode *bantu;
    	bantu =up;
    if (isEmpty() == 0){
        do{
            if(bantu->data == datasebelum){
			TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        up= baru;
        down = baru;
        up->next =up;
        down->next = down;
    }
    else
    {
        baru->next =up;
        up= baru;
        down->next =up;
    }
			
			
			}
            bantu=bantu->next;
        }while (bantu!=down->next);
    } else {
        cout<<"List Kosong";
    }
	
	
	}



void hapusNode(int datahapus){
	TNode *hapus = new TNode;
	TNode *bantu = new TNode;
	hapus =up;
	for(int i=1;i<datahapus;i++){
		bantu = hapus;
		hapus = hapus->next;
}

bantu->next=hapus->next;

}


int main()
{
    init();
    tambahBelakang(9);
    tambahBelakang(3);
    tambahDepan(5);
    tambahDepan(6);
    tambahBelakang(11);
    cetak();
    hapusDepan();
    hapusBelakang();
    cetak();
    cout<<endl;
    insertNode(3,5);
    cetak();
    cout<<endl;
    cout<<endl;
    hapusNode(3);
    cout<<endl;
    cetak();
    
    return 0;
}

