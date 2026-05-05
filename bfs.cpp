#include<iostream>
using namespace std;

int adj[10][10];
int countAdj[10];
int visited[10];
int n =4;

string landmark[5]= {" ", "Admin","Hostel","Workshop","Sports"};

int queArr[10], front =-1 ,rear = -1;
void enqueue(int x){
    if(front == -1) front =0;
    queArr[++rear] = x;
}

int dequeue(){
    return queArr[front++];
}

bool isEmpty(){
    return(front > rear);
}


void BFS(int start){
    front = rear = -1;

    enqueue(start);
    visited[start] = 1;

    while(!isEmpty()){
        int v = dequeue();
        cout << landmark[v] << " ";

        for(int i = 0; i < countAdj[v]; i++){
            int next = adj[v][i];

            if(visited[next] == 0){
                visited[next] = 1;   
                enqueue(next);
            }
        }
    }
}
void reset(){
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
        countAdj[i] = 0;
    }
}

void createGraph(){
    int edges, u, v;

    reset();

    cout<<"\nLandmarks:\n";
    for(int i=1;i<=n;i++)
        cout<<i<<" -> "<<landmark[i]<<endl;

    cout<<"Enter number of edges: ";
    cin>>edges;

        for(int i=0;i<edges;i++){
            cout<<"Enter edge (u v): ";
            cin>>u>>v;

            adj[u][countAdj[u]++] = v;
            adj[v][countAdj[v]++] = u;
    }
}

void displayList(){
    cout<<"\nAdjacency List:\n";

    for(int i=1;i<=n;i++){
        cout<<landmark[i]<<" -> ";

        for(int j=0;j<countAdj[i];j++){
            cout<<landmark[adj[i][j]]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int choice, start;

    while(true){
        cout<<"\n--- BFS MENU ---";
        cout<<"\n1.Create Graph";
        cout<<"\n2.Display List";
        cout<<"\n3.BFS Traversal";
        cout<<"\n4.Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;
            switch(choice){
            case 1: createGraph(); break;

            case 2: displayList(); break;

            case 3:
                for(int i=1;i<=n;i++) visited[i]=0;
                cout<<"Enter starting node: ";
                cin>>start;
                cout<<"BFS: ";
                BFS(start);
                break;

            case 4: return 0;

            default: cout<<"Invalid choice!";
        }
    }
}


