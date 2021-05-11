#include <iostream>

using namespace std;

class BankUser{
    public:
    int accno;
    string name;
    string acctype;
    string dob;
    string address;
    int balance;
    BankUser *next;
    
    void update( BankUser *head);
    BankUser* deleteuser( BankUser *head);
    void displaybyid( BankUser *head);
    void displaybyname( BankUser *head);
    void displaynonzerobalance( BankUser *head);
    BankUser* getdata( BankUser *head);
};


BankUser* BankUser::getdata( BankUser *head){
    BankUser *thead=head;
    
    while(true){
        BankUser *temp=new BankUser();
    cout<<"enter account number : ";
    cin>>temp->accno;
    cout<<"enter name : ";
    cin>>temp->name;
    cout<<"enter account type : ";
    cin>>temp->acctype;
    cout<<"enter dob : ";
    cin>>temp->dob;
    cout<<"enter address : ";
    cin>>temp->address;
    cout<<"enter balance : ";
    cin>>temp->balance;
    temp->next=NULL;
    if(thead==NULL)
    thead=temp;
    else{
    thead->next=temp;
    thead=thead->next;
    }
    int flag;
    cout<<"enter 1 to stop entering users and 0 to continue users : ";
    cin>>flag;
    if(flag==1)
    break;
    }
    return thead;
}


void BankUser::update( BankUser *head){
        int choice,taccno;
        string taddress,tname;
        cout<<"enter your choice to update either of the following\n1.address\n2.name\nenter your choice";
        cin>>choice;
        cout<<"enter account number : ";
        cin>>taccno;
         BankUser *thead=head;
        while(thead!=NULL){
            if(thead->accno=taccno)
            break;
            thead=thead->next;
        }
        if(thead==NULL){
        cout<<"NO such user\n";
        return;
        }
        switch(choice){
            case 1:
            cin>>taddress;
            thead->address=taddress;
            cout<<"address updated successfully\n";
            break;
            case 2:
            cin>>tname;
            thead->name=tname;
            cout<<"name updated successfully\n";
        }
    }
    
    

 BankUser* BankUser::deleteuser( BankUser *head){
         BankUser *thead=head;
        int taccno;
        cout<<"enter account number : ";
        cin>>taccno;
        if(thead==NULL){
        cout<<"bank users list is empty\n";
        return thead;
        }
        if(thead->accno==taccno){
            head=head->next;
            return head;
        }
        while(thead!=NULL){
            if(thead->next->accno==taccno){
                thead->next=thead->next->next;
                return head;
            }
        }
        return head;
    }

void BankUser::displaybyid( BankUser *head){
        BankUser *thead=head;
        int tid;
        cin>>tid;
        if(thead==NULL){
        cout<<"no users\n";
        return;
        }
        while(thead!=NULL){
            if(thead->accno==tid){
                cout<<"details are : "<<thead->accno<<" "<<thead->name<<" "<<thead->acctype<<" "<<thead->dob<<" "<<thead->balance<<" "<<thead->address<<"\n";
                break;
                return;
            }
            thead=thead->next;
        }
        if(thead==NULL){
            cout<<"account with such account number doesnt exists\n";
            return;
        }
    }
    
    

void BankUser::displaybyname( BankUser *head){
         BankUser *thead=head;
        string tname;
        cin>>tname;
        if(thead==NULL){
        cout<<"no users\n";
        return;
        }
        while(thead!=NULL){
            if(thead->name==tname){
                cout<<"details are : "<<thead->accno<<" "<<thead->name<<" "<<thead->acctype<<" "<<thead->dob<<" "<<thead->balance<<" "<<thead->address<<"\n";
                break;
                return;
            }
            thead=thead->next;
        }
        if(thead==NULL){
            cout<<"account with such account number doesnt exists\n";
            return;
        }
    }
    
    

void BankUser::displaynonzerobalance( BankUser *head){
         BankUser *thead=head;
        if(thead==NULL){
        cout<<"no users\n";
        return;
        }
        while(thead!=NULL){
            //if(thead->accno>0){
                cout<<"details are : "<<thead->accno<<" "<<thead->name<<" "<<thead->acctype<<" "<<thead->dob<<" "<<thead->balance<<" "<<thead->address<<"\n";
                //break;
               // return;
            //}
            thead=thead->next;
        }
        
    }
    
    void displaymenu(){
        cout<<"menu\n1.update \n2.delete\n3.display by id\n4.display by name\n5.display all non zero balance users\n6.exit\nenter your choice : ";
    }
int main()
{
     BankUser *head;
    head->getdata(head);
    while(true){
        int choice;
        displaymenu();
        cin>>choice;
        switch(choice){
            case 1: 
                head->update(head);
                break;
            case 2:
                head=head->deleteuser(head);
                break;
            case 3:
                head->displaybyid( head);
                break;
            case 4:
                head->displaybyname( head);
                break;
            case 5:
                head->displaynonzerobalance( head);
                break;
            case 6:
                    exit(0);
                    cout<<"exited successfully";
            
        }
    }

    return 0;
}