#include <iostream>
#include <stdlib.h>
using namespace std;
#define max 10
class bidderlist
{
    public:
    string person_name;
    string person_location;
    int price_to_buy;
};
class items: protected bidderlist
{
    //Adminstratorm                                   
    string item_name;
    string description;
    int price_to_sell;
    int price_sold;
    int no_of_bidders;

    bidderlist list[max];

    
    public:
    int category;
    int lot_no;
    bool sold;
    static int counter_item;
        items()
        {
            lot_no = 0;
            price_to_sell = 0;
            price_sold = 0;
            description ="";
            item_name ="";
            category = 0;
            no_of_bidders = 0;
            sold = false;
        }

        // Functions
        void Add_item()
        {
            ++counter_item;
            //1
            cout<<"\t\tEnter lot number: ";
            cin>>lot_no;

            //2
            cout<<"\t\tchoose category(number):\n";
            cout<<"\t\t\t 1. Electronics\n";
            cout<<"\t\t\t 2. Home decor\n";
            cout<<"\t\t\t 3. pet\n";
            cout<<"\t\t\t 4. Kitchen items\n";
            cout<<"\t\t\t 5. Vehicles\n";
            cout<<"\t\t\t 6. other items\n";
            cout<<"\t\t\t";
            cin>>category;
            //3
            cout<<"\t\tEnter item name: ";
            cout<<"\t\t";
            cin>>item_name;  
            //4
            cout<<"\n\t\tEnter description: ";
            cout<<"\t\t";
            cin>>description;
            //5
            cout<<"\n\t\tEnter selling price: ";
            cout<<"\t\t";
            cin>>price_to_sell;

            sold = false;
            
        }
        void Display_item(void)
        {
            cout<<"\t\t Item name: "<<item_name<<"\n";//1
            cout<<"\t\t Lot number: "<<lot_no<<"\n";//2
            cout<<"\t\t Description: "<<description<<"\n";//3

            if(sold==false)
                cout<<"\t\t Selling price: "<<price_to_sell<<"\n"; //4
            else
                cout<<"\t\t Item sold at: "<<price_sold<<"\n"; //4

            switch(category)
            {
                case 1:
                    cout<<"\t\t category is Electronics\n";
                    break;
                case 2:
                    cout<<"\t\t category is Home decor\n";
                    break;
                case 3:
                    cout<<"\t\t category is Pet\n";
                    break;
                case 4:
                    cout<<"\t\t category is Kitchen items\n";
                    break;
                case 5:
                    cout<<"\t\t category is Vehicles\n";
                    break;
                case 6:
                    cout<<"\t\t category is Other items\n";
                    break;
            }
        }
        void Sell_item()
        {
            for(int i=0;i<no_of_bidders;i++)
            {
                cout<<"\t\tName: "<<list[no_of_bidders].person_name<<"\n";
                cout<<"\t\tLocation: "<<list[no_of_bidders].person_location<<"\n";
                cout<<"\t\tBid: "<<list[no_of_bidders].price_to_buy<<"\n\n";
            }
            cout<<"\t\tDo you want to sell at bid:"<<list[no_of_bidders-1].price_to_buy<<" to "<<list[no_of_bidders].person_name<<"\n";
            cout<<"\t\tY or N";
            char choice4;
            cin>>choice4;
            if(choice4 == 'Y' || choice4 == 'y')
            {
                sold = true;
                cout<<"\n\t\t sold !!!!!!!\n";
            }
            else
            {
                cout<<"\t\tWaiting for more bids...\n";
            }
        }
        void Buy_item()
        {
            cout<<"/t/tEnter your name: ";
            cin>>list[no_of_bidders].person_name;

            cout<<"/t/tEnter your location: ";
            cin>>list[no_of_bidders].person_location;

            cout<<"/t/tEnter the bid: ";
            cin>>list[no_of_bidders].price_to_buy;
            ++no_of_bidders;
        }
        void show_bidders_list()
        {
            for(int i=0;i<no_of_bidders;i++)
            {
                cout<<"\t\t\tName: "<<list[no_of_bidders].person_name<<endl;
                cout<<"\t\t\tLocation: "<<list[no_of_bidders].person_location<<endl;
                cout<<"\t\t\tBid: "<<list[no_of_bidders].price_to_buy<<"\n\n";
            }
        }
        friend void Delete_item(items x,int k);
        void operator=(items x)
        {
            lot_no = x.lot_no;
            price_to_sell = x.price_to_sell;
            price_sold = x.price_sold;
            description = x.description;
            item_name = x.item_name;
            category = x.category;
            no_of_bidders = x.no_of_bidders;
        }
};
void Delete_item(items x[],int k)
{
    for(int i=k;i<items::counter_item;i++)
    {
        x[i] = x[i+1];
    }
}

int items::counter_item;
int main()
{
    items its[max];
    int flag1=0,flag2=0,flag3=0;
    while(1)
    {
        again:
        int choice1;
        cout<<"Options:\n";
        cout<<"1. Adminstrator (seller)\n";
        cout<<"2. User (bidder)\n";
        cout<<"3. exit\n";
        cout<<"Enter your choice:";
        cin>>choice1;
        if(choice1==1)
        {
            cout<<"*************************************************************\n";
            cout<<"\t\t\t\tADMINSTRATOR WORKSPACE\n";
            int choice2;
            while(1)
            {
                cout<<"Options:\n";
                cout<<"\t1. Add item\n";
                cout<<"\t2. Display item\n";
                cout<<"\t3. Sell item\n";
                cout<<"\t4. Delete sold items\n";
                cout<<"\t5. Exit Workspace\n";
                cout<<"\tEnter your choice:";
                cin>>choice2;
                switch (choice2)
                {
                case 1:
                    cout<<"\t\t\t ADDING ITEM ->\n";
                    its[items::counter_item].Add_item();
                    break;
                case 2:
                    cout<<"\t\t\t LIST OF ALL ITEMS ->\n";
                    if(items::counter_item == 0)
                    {
                        cout<<"\t\t\toops!....no items list\n";
                    }
                    else
                    {
                        for(int i=0;i<items::counter_item;i++)
                        {
                            its[i].Display_item();
                        }
                        char choice3;
                        cout<<"\t\t Do you want to display bidders list of any item? Y/N";
                        cin>>choice3;
                        if(choice3 == 'Y' || choice3 == 'y')
                        {
                            int lot_no;
                            cout<<"\t\tEnter lot number";
                            cin>>lot_no;
                            flag1=0;
                            for(int i=0;i<items::counter_item;i++)
                            {
                                if(lot_no == its[i].lot_no)
                                {
                                    its[i].show_bidders_list();
                                    cout<<"\n";
                                    ++flag1;
                                }
                            }
                            if(flag1 == 0)
                            {
                                cout<<"\t\t\tno such item in list";
                            }
                        }
                    }
                    break;
                case 3:
                    flag2=0;
                    cout<<"\t\t\t SELLING ITEM ->\n";
                    int lot_no;
                    cout<<"\t\tEnter lot number";
                    cin>>lot_no;
                    for(int i=0;i<items::counter_item;i++)
                    {
                        if(lot_no == its[i].lot_no)
                        {
                            its[i].Sell_item();
                            ++flag2;
                        }
                    }
                    if(flag2 == 0)
                    {
                        cout<<"\t\t\tno such item in list";
                    }
                    break;
                case 4:
                    cout<<"\t\t\t DELETING SOLD ITEMS FROM LIST ->\n";
                    for(int i=0;i<items::counter_item;i++)
                    {
                        if(its[i].sold == true)
                        {
                            Delete_item(its,i);
                        }
                    }
                    cout<<"\t\t\t...";
                    cout<<"\t\t\tAll sold items are deleted now\n";
                    break;
                
                case 5:
                cout<<"\t\t\t EXITING THE WORKSPACE...BYE BYE\n";
                cout<<"*************************************************************\n";
                    goto again;
                default:
                    cout<<"\t\twrong input...try again\n";
                    break;
                }
                
            }

        }
        else if(choice1==2)
        {
            cout<<"*************************************************************\n";
            cout<<"\t\t\t\tBIDDER WORKSPACE\n";
            if(items::counter_item == 0)
            {
                cout<<"\t\t\t No items for bidding on server\n";
                goto end;
            }
            int category;
            again1:
            cout<<"\tEnter the category of item you want to buy:\n";
            cout<<"\t\t 1. Electronics\n";
            cout<<"\t\t 2. Home decor\n";
            cout<<"\t\t 3. Electronics\n";
            cout<<"\t\t 4. Kitchen items\n";
            cout<<"\t\t 5. Vehicles\n";
            cout<<"\t\t 6. other items\n";
            cin>>category;
            if(category>6)
            {
                cout<<"\t\t\t wrong input";
                goto again1;
            }
            for(int i=0;i<items::counter_item;i++)
            {
                if(category == its[i].category)
                {
                    its[i].Display_item();
                }
            }
            int lot_no;
            cout<<"\t\tEnter lot number of item you want to buy: ";
            cin>>lot_no;
            for(int i=0;i<items::counter_item;i++)
            {
                if(lot_no == its[i].lot_no)
                {
                    its[i].Buy_item();
                }
            }
            end:{}
        }
        else
        {
            cout<<"Program ends\n";
            cout<<"*************************************************************\n";
            exit(0);
        }
        
    }
    return 0;
}
