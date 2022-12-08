#include <bits/stdc++.h>
using namespace std;
int passes,pos,cycle,declarer;
string curbid,contract;
char dealer;
string bid[10][4];
int main(){
	cout<<"Input dealer: (N/E/S/W) "<<endl;
	cin>>dealer;
	if(dealer=='N'){
		  pos=0;
	}else if(dealer=='E'){
		pos=1;
	}else if(dealer=='S'){
		pos=2;
	}else if(dealer == 'W'){
		pos=3;
	}
	for(int i=0; i<10; i++){
			for(int j=0; j<4; j++){
				bid[i][j]="-";}}
		cout<<endl<<endl;
		cout<<"\tN\tE\tS\tW "<<endl;
		for(int i=0; i<=cycle; i++){
			for(int j=0; j<pos; j++){
				cout<<'\t';
				cout<<bid[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	while(passes<3){
		if(pos==0)
			cout<<"North's";
		else if(pos==1)
			cout<<"East's";
		else if(pos==2)
			cout<<"South's";
		else
			cout<<"West's";
		cout<<" bid: ";
		cin>>curbid;
		if(curbid=="undo"){
			cout<<"undo complete"<<endl;
			pos--;
			continue;
		}
		if(curbid=="p")curbid="P";
		if(curbid=="P"){
			passes++;
		}else{
			passes=0;
			contract=curbid;
			declarer = pos;
		}
		bid[cycle][pos]=curbid;
		
		// print bids
		cout<<endl;
		cout<<"\tN\tE\tS\tW "<<endl;
		for(int i=0; i<=cycle; i++){
			for(int j=0; j<4; j++){
				cout<<'\t';
				cout<<bid[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
		pos++;
		if(pos==4){
			pos=0;
			cycle++;
		}
	}
	cout<<"Your contract is "<<contract<<", by ";
	if(declarer==0)
		cout<<"North-South.";
	else if(declarer==1)
		cout<<"East-West.";
	else if(declarer==2)
		cout<<"North-South.";
	else
		cout<<"East-West.";
	
}
