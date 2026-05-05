#include<iostream>
using namespace std;

int G[10][10];
int visited[10];
int n = 4;

string landmark[5]={" ","Admin","Hostel","Workshop","Sports"};

void DFS(int v){
	visited[v] = 1;
	cout<<landmark[v]<<" ";
	
	for(int i =1; i <= n; i++){
		if(G[v][i] == 1 && visited[i] == 0){
			DFS(i);
		}
	}
}

void reset(){
	for(int i = 1; i<= n; i++){
		visited[i]=0;
		for(int j = 1; j <= n; j++){
			G[i][j] = 0;
		}
	}
}

void createGraph(){
	int edges, u, v;
        reset();
	
	cout<<"\n LANDMARKS\n";
	for(int i =1; i <= n; i++){
		cout<<i<<landmark[i]<<endl;
	}

	cout<<"Enter No o Edges:";
	cin>>edges;
	for(int i =0; i < edges; i++){
		cout<<"Enter Edege (u ,v)";
		cin>>u>>v;
		G[u][v] = G[v][u] = 1;
	}


}


void displayMatrix(){
    cout<<"\nAdjacency Matrix:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
	int choice , start;

	    while(true){
        	cout<<"\n--- DFS MENU ---";
        	cout<<"\n1.Create Graph";
        	cout<<"\n2.Display Matrix";
        	cout<<"\n3.DFS Traversal";
        	cout<<"\n4.Exit";
        	cout<<"\nEnter choice: ";
        	cin>>choice;
	switch(choice){
            case 1: createGraph(); break;

            case 2: displayMatrix(); break;

            case 3:
                for(int i=1;i<=n;i++) visited[i]=0;
                cout<<"Enter starting node: ";
                cin>>start;
                cout<<"DFS: ";
                DFS(start);
                break;

            case 4: return 0;

            default: cout<<"Invalid choice!";
        }
    }
}

