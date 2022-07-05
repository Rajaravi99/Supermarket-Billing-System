#include <bits/stdc++.h>
using namespace std;

class shopping{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
};

void shopping :: menu(){
	m:
	int choice;
	string email;
	string password;
	cout<<"\t\t\t\t___________________________________________\n";
	cout<<"                                                   \n";
	cout<<"                Supermarket Main Menu              \n";
	cout<<"                                                   \n";
	cout<<"\t\t\t\t___________________________________________\n";
	cout<<"                                                   \n";
	cout<<"\t\t\t\t|    1} Administrator   |\n";
	cout<<"\t\t\t\t|    2} Buyer           |\n";
	cout<<"\t\t\t\t|    3} Exit Mennu      |\n";
	cout<<"\t\t\t\t|                       |\n";
	cout<<"\n\t\t\t  Please Select - ";
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"\n\t\t\t Please Login\n";
			cout<<"\t\t\t Enetr email - ";
			cin>>email;
			cout<<"\t\t\t Enetr password - ";
			cin>>password;
			if(email=="ravinandanray99@gmail.com" && password=="12345"){
				administrator();
			}
			else{
				cout<<"\n\t\t\t   Invalid email/password \n";
			}
			break;
		case 2:
			buyer();
		case 3:
			exit(0);
		default:
			cout<<"\nPlease select fromthe given options\n";
			goto m;
	}
}

void shopping :: administrator(){
	m:
	int choice;
	cout<<"\n\t\t\t Administrator Menu\n";
	cout<<"\n\t\t\t|   1}Add the product   ";
	cout<<"\n\t\t\t|   2}Modify the product";
	cout<<"\n\t\t\t|   3}Delete the product";
	cout<<"\n\t\t\t|   4}Back to main menu ";
	cout<<"\n\t\t\t Please enter  your choice\n";
	cin>>choice;
	switch(choice){
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"\nPlease select the correct choice\n";
			goto m;
	}
}

void shopping :: buyer(){
	m:
	int choice;
	cout<<"\n\t\t\t   Buyer   \n";
	cout<<"\n\t\t\t_______________\n";
	cout<<"\n\t\t\t 1}But Product  \n";
	cout<<"\n\t\t\t 2}Go Back      \n";
	cout<<"\n\t\t\t  Please select - ";
	cin>>choice;
	switch(choice){
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default:
			cout<<"\n\t\t Please lselect correct optin \n";
			goto m;
	}
}

void shopping :: add(){
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	cout<<"\n\t\t\t Add new product\n";
	cout<<"\n\t\t\t Enter product code - ";
	cin>>pcode;
	cout<<"\n\t\t\t Enter product name - ";
	cin>>pname;
	cout<<"\n\t\t\t Enter price of the product - ";
	cin>>price;
	cout<<"\n\t\t\t Enter discount on the product - ";
	cin>>dis;
	data.open("database.txt",ios::in);
	if(!data){
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;
		while(!data.eof()){
			if(c==pcode){
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		if(token>=1){
		    cout<<"\n\t\t\t Product already exists in the list \n";
		    goto m;
	    }
	    else{
		    data.open("database.txt",ios::app|ios::out);
		    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		    data.close();
	    }
	    cout<<"\n\t\t\t Record Inserted !\n";
	}
}

void shopping :: edit(){
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	cout<<"\n\t\t\t Modify the record \n";
	cout<<"\n\t\t\t Enter the Product code - ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\t\t\t File does not exist \n";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pkey=pcode){
				cout<<"\n\t\t\t Enter new product code - ";
				cin>>c;
				cout<<"\n\t\t\t Enter product name - ";
				cin>>n;
				cout<<"\n\t\t\t Enter price of the product - ";
				cin>>p;
				cout<<"\n\t\t\t Enter discount on the product - ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t\t\t Record updated !\n";
				token++;
			}
			else{
				data1<<pcode<<pname<<price<<dis;
			}
			data>>pcode>>pname>>price>>dis;
		}
	}
	data.close();
	data1.close();
	remove("database.txt");
	rename("database1.txt","database.txt");
	if(token<1){
		cout<<"\n\t\t\t Record not found sorry !\n";
	}
}

void shopping :: rem(){
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\t\t\t Delete the product   \n";
	cout<<"\n\t\t\t   Enter the product key  \n";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\t\t\t File does not exist  \n";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pcode==pkey){
				cout<<"\n\t\t\t  Product deleted sucessfully ! \n";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token<1){
			cout<<"\n\t\t\t Record not found sorry ! \n";
		}
	}
}

void shopping :: list(){
	cout<<"\n\t\t\t      List of Products    \n";
	fstream data;
	data.open("database.txt");
	if(!data){
		cout<<"\n\t\t\t  No list exists   \n";
	}
	else{
		cout<<"\n\t\t\t Product code  Product name  price  discount \n";
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			cout<<"\t\t\t "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<" \n";
			data>>pcode>>pname>>price>>dis;
		}
	}
	data.close();
}

void shopping :: receipt(){
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	cout<<"\n\t\t\t  Receipt   \n";
	data.open("database.txt");
	if(!data){
		cout<<"\n\t\t\t  No products to sell  \n";
	}
	else{
		data.close();
		list();
		cout<<"\n\t\t\t  Please place the order \n";
		do{
			m:
			cout<<"\n\t\t\t  Enter product code\n";
			cin>>arrc[c];
			cout<<"\n\t\t\t Enter quamtity \n";
			cin>>arrq[c];
			for(int i=0;i<c;i++){
				if(arrc[c]==arrc[i]){
					cout<<"\n\t\t\t Duplicate product code, please try again\n";
					goto m;
				}
			}
			c++;
			cout<<"\n\t\t\t If need another product press y else press n\n";
			cin>>choice;
		}while(choice=='y');
		cout<<"\n\t\t\t Receipt\n";
		cout<< "\nProduct no.\tProduct name\tQuantity\tamount after discount\n";
		for(int i=0;i<c;i++){
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof()){
				if(arrc[i]==pcode){
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
			data.close();
		}
		cout<<"\n\t  Total amount : "<<total;
	}
}

int main(){
	char ch;
	shopping s;
	s.menu();
	cin>>ch;
	return 0;
}
