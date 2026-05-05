#include<iostream>
#include<cstring>
#include<ios>
#include<limits>
using namespace std;

typedef struct keyword{
    char key[20];
    char meaning[100];
}WORD;

typedef struct node{
    struct node *LC;
    WORD data;
    int height;
    struct node *RC;
}NODE;

class AVL{
    NODE *root;

public:
    AVL(){
        root = NULL;
    }

    NODE* getroot(){
        return root;
    }

    int height(NODE *T){
        if(T == NULL)
            return 0;

        int lh = height(T->LC);
        int rh = height(T->RC);

        return (lh > rh ? lh : rh) + 1;
    }

    int difference(NODE* T){
        return height(T->LC) - height(T->RC);
    }

    // RR Rotation
    NODE* rr_rotate(NODE* Pptr){
        NODE *Aptr = Pptr->RC;
        Pptr->RC = Aptr->LC;
        Aptr->LC = Pptr;
        cout<<"\nRight-Right Rotation";
        return Aptr;
    }

    // LL Rotation
    NODE* ll_rotate(NODE* Pptr){
        NODE *Aptr = Pptr->LC;
        Pptr->LC = Aptr->RC;
        Aptr->RC = Pptr;
        cout<<"\nLeft-Left Rotation";
        return Aptr;
    }

    // LR Rotation (FIXED)
    NODE* lr_rotate(NODE* Pptr){
        Pptr->LC = rr_rotate(Pptr->LC);
        cout<<"\nLeft-Right Rotation";
        return ll_rotate(Pptr);
    }

    // RL Rotation (FIXED)
    NODE* rl_rotate(NODE* Pptr){
        Pptr->RC = ll_rotate(Pptr->RC);
        cout<<"\nRight-Left Rotation";
        return rr_rotate(Pptr);
    }

    NODE* balance(NODE* T){
        int bf = difference(T);

        if(bf > 1){
            if(difference(T->LC) > 0)
                T = ll_rotate(T);
            else
                T = lr_rotate(T);
        }
        else if(bf < -1){
            if(difference(T->RC) > 0)
                T = rl_rotate(T);
            else
                T = rr_rotate(T);
        }
        return T;
    }

    NODE* insert(NODE* T, WORD w){
        if(T == NULL){
            T = new NODE;
            T->data = w;
            T->LC = T->RC = NULL;
            root = T;
            return T;
        }

        if(strcmp(w.key, T->data.key) < 0){
            T->LC = insert(T->LC, w);
        }
        else if(strcmp(w.key, T->data.key) > 0){
            T->RC = insert(T->RC, w);
        }

        T = balance(T);
        root = T;
        return T;
    }

    void searchNode(string key){
        int count = 0;
        NODE *cur = root;

        while(cur){
            count++;
            if(key == cur->data.key){
                cout<<"\nWord found!";
                cout<<"\nComparisons: "<<count;
                return;
            }
            else if(key > cur->data.key)
                cur = cur->RC;
            else
                cur = cur->LC;
        }
        cout<<"\nWord not found";
    }

    void displayIN(NODE *T){
        if(T){
            displayIN(T->LC);
            cout<<T->data.key<<" : "<<T->data.meaning<<endl;
            displayIN(T->RC);
        }
    }
};

int main(){
    AVL B;
    int choice;
    WORD w;
    char key[20];

    while(true){
        cout<<"\n\n*** AVL Dictionary ***";
        cout<<"\n1. Add Word";
        cout<<"\n2. Display Dictionary";
        cout<<"\n3. Search Word";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice){
            case 1:
                cout<<"Enter keyword: ";
                cin.getline(w.key,20);

                cout<<"Enter meaning: ";
                cin.getline(w.meaning,100);

                B.insert(B.getroot(), w);
                break;

            case 2:
                cout<<"\nDictionary (Sorted):\n";
                B.displayIN(B.getroot());
                break;

            case 3:
                cout<<"Enter keyword to search: ";
                cin.getline(key,20);
                B.searchNode(key);
                break;

            case 4:
                cout<<"Exiting...\n";
                return 0;

            default:
                cout<<"Invalid choice!";
        }
    }
}