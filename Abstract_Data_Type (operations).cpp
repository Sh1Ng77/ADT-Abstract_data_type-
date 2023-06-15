#include<iostream>
using namespace std;

class dictionary
{
    public:
    int key;
    string value;
    dictionary*next;
    dictionary()
    {
        next=NULL;
    }
};
dictionary*HT[10];
int Hash(dictionary*ptr)
{
    int h=ptr->key%10;
    if(HT[h]==NULL)
        HT[h]=ptr;
    else{
        dictionary*p=HT[h];
        while(p->next!=NULL && p->key!=ptr->key)
        {
            p=p->next;
        }
        if(p->key==ptr->key)
        {
            delete ptr;
            return 0;
        }
        else{
            p->next=ptr;
        }
        return 1;
    }    
}

int insert(int key,string value)
{
    dictionary*d=new dictionary();
    d->key=key;
    d->value=value;
    return Hash(d);
}

bool delete_pair(int key)
{
    dictionary*match_pair=HT[key%10];
    dictionary*prev_pair=NULL;
    if(match_pair!=NULL && match_pair->key!=key)
    {   
        prev_pair=match_pair;
        match_pair=match_pair->next;
    }
    if(match_pair==NULL)
        return 0;
    dictionary*next_pair=match_pair->next;
    if(prev_pair==NULL)
    {
        HT[key%10]=next_pair;
    }else{
        prev_pair->next=next_pair;
    }
    delete match_pair;
    return 1;
}

void display()
{
    cout<<"\n\n\nHASH TABLE"<<endl;
    cout<<"\tKEY    VALUE"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<i;
        if(HT[i]==NULL)
            cout<<"\tEMPTY\n";
        else{
            dictionary*p=HT[i];
            while(p!=NULL)
            {
                cout<<"\t"<<p->key<<"\t"<<p->value;
                p=p->next;
            }
            cout<<endl;
        }    
    }
}

string search(int key)
{
    dictionary*p=HT[key%10];
    while(p!=NULL)
    {
        if(p->key==key)
        {
            return p->value;
        }
        p=p->next;
    }
    cout<<endl;
    return 0;
}

int  main()
{
    int ch,key;
    string value;

    while(true)

    {
        cout<<"\n\n1. Insert\n2. Display\n3. Search\n4. delete\n5. Exit\n\nENTER YOUR CHOICE : ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Enter key : ";
                    cin>>key;
                    cout<<"Enter value : ";
                    cin>>value;
                    if(insert(key,value)==1)
                    {
                        cout<<"Key value pair inserted\n";
                    }
                    else{
                        cout<<"Key already inserted\n";
                    }
                    break;

            case 2:display();
                    break;

            case 3:cout<<"Enter key to be searched : ";
                    cin>>key;
                    cout<<search(key);
                    break;

            case 4: cout << "Enter key to delete: ";
                    cin >> key;
                    if(delete_pair(key) == 1) {
                        cout<<"Key value pair deleted\n";
                    } 
                    else
                        cout<<"Key value pair did not find\n";
                    break; 
            case 5:return 0;  
            default:
                cout<<"Invalid choice\n";
                break;                                                           
        }
    }
    return 0;
}