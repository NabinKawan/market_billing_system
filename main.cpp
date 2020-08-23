#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>

using namespace std;
int check(int);

class Product
{
   int p_number=0,pn=0,pno=0;
    int a=0;
    char product_name[50];
    char code;
    float product_price;
    float dis_per;
    int codenum;
    int chk=1;

public:
    int acd,x;
float product_quantity;
    int get_chk(){
         return chk;
    }
    void add_product()
    {   while(1){
        category:
            cout<<endl<<"Please enter the category:\n\tPRESS 1 FOR BISCUITS\n\tPRESS 2 FOR CHOCOLATES\n\tPRESS 3 FOR NOODLES\n\tPRESS 4 TO GO BACK\n\t";
            cin>>code;
        if(code=='4'){
            system("cls");
            chk=0;
            break;
        }
        if(code=='1')
        {
            system("cls");
            cout<<"............................................Add Biscuits....................................\n\n\n"<<endl;
            x:
           cout<<"\tEnter the code from 2000-2999: ";
        while(!(cin>>codenum))
        {
            cin.clear();
            cin.ignore(123,'\n');
            goto category;
            break;
        }
        if(codenum>1999&&codenum<3000)
        {//++p_number;
         acd=codenum;
        x=check(acd);
        if(x==1)
            {goto x;
            }
        else
        //codenum=acd;*/
              goto zx;
              break;
        }
        else{cout<<"Not valid\n"<<endl;
            goto x;
        }

        }
        else if(code=='2')
        {
            system("cls");
            cout<<".....................................Add Chocolates...........................\n\n\n"<<endl;
            y:
        cout<<"\tEnter the code from 3000-3999:";
         while(!(cin>>codenum))
        {
            cin.clear();
            cin.ignore(123,'\n');
            goto category;
            break;
        }
          if(codenum>2999&&codenum<4000)
        {
            acd=codenum;
            x=check(acd);
            if(x==1){
            goto y;
            }
            else{
                goto zx;
                break;
            }
        }
        else{
                cout<<"Not valid\n"<<endl;
            goto y;
        }

        }
        else if(code=='3')
        {system("cls");
            cout<<"..............................................Add Noodles........................................\n\n\n"<<endl;
            z:
           cout<<"\tEnter the code from 4000-4999:";
          while(!(cin>>codenum))
        {
            cin.clear();
            cin.ignore(123,'\n');
            goto category;
            break;
        }
       if(codenum>3999&&codenum<5000)
        {
            acd=codenum;
            x=check(acd);
            if(x==1){
                goto z;
            }
            else{
                  goto zx;
            }

        }
        else{cout<<"Not valid\n"<<endl;;
            goto z;
        }


        }
        else{
            goto category;
        }
        zx:cout<<endl<<"\tPlease Enter The Name of The Product: ";
        cin>>product_name;
        co:cout<<endl<<"\tPlease Enter The Price of The Product: ";
        //cin>>product_price;
        while(!(cin>>product_price))
        {
            cin.clear();
            cin.ignore(123,'\n');
            goto co;
            break;
        }
        cout<<endl<<"\tPlease Enter The Discount % of The Product: ";
        cin>>dis_per;
       ss: cout<<endl<<"\tPlease enter the quantity:";

        //cin>>product_quantity;
        while(!(cin>>product_quantity))
        {
            cin.clear();
            cin.ignore(123,'\n');
            goto ss;
            break;
        }

        if(product_quantity<1)
        {
            cout<<"\tNo quantity added.\nEnter Again";
            goto ss;
        }
        break;
    }
    }

    void show_product()
    {   cout<<"...........................Details...................\n\n\n";
        cout<<endl<<"\tcategory :"<<code;
        cout<<endl<<"\tCode: "<<codenum;
        cout<<endl<<"\tProduct Name: "<<product_name;
        cout<<endl<<"\tProduct Price: "<<product_price;
        cout<<endl<<"\tDiscount percentage :"<<dis_per<<"%";
        cout<<endl<<"\tquantity :"<<product_quantity;
            }
    int getproduct()
    {
        return p_number;
    }
    float get_dis_per(){
        return dis_per;
    }
    void setname(char name[]){
        strcpy(product_name,name);
    }
    void setprice(float price){
    product_price=price;
    }
    void set_dis_per(float dis){
    dis_per=dis;
    }
    void set_quantity(int quant){
    product_quantity=quant;
    }
    int getp()
    {
        return pn;
    }
    int getpo()
    {
        return pno;
    }

    float getquantity()
    {
        return product_quantity;
    }
    void setcode(int code){
     codenum=code;
    }
    int getcode()
    {
        return codenum;
    }

    float getprice()
    {
        return product_price;
    }

    char* getname()
    {
        return product_name;
    }
    char category()
    {
        return code;
    }
    void bill(int[],int[],float,int);
};


fstream fp,f;
Product b;

void savebill(int[],int[],float ,int);
char pass[10],ch,user[20];
void login()
{
    int i=0;
    cout<<"\n\n\tusername: ";
    cin>>user;
    cout <<"\tpassword: ";
    while(1)
    {
        ch=getch();
        //cout<<ch;
        if (ch==13)
        {
            pass[i]='\0';
            break;
        }
        else if(ch==8)
        {
            cout<<"\b \b";
            --i;

        }
        else
        {
            pass[i]=ch;
            cout<<"*";
            i++;
        }

    }

}


void save_product()
{
    b.add_product();
    if(b.get_chk()){
    fp.open("database.txt",ios::out | ios::app);
    fp.write((char*)&b,sizeof(b));
    cout<<endl<<endl<<"The Product Has Been Sucessfully Created.....\n\n";
    fp.close();
    getch();
    }
}


void show_all_product()
{ int count=0;
    system("cls");
    cout<<endl<<"\t\t*************************************************";
    cout<<endl<<"\t\tRECORDS.";
    cout<<endl<<"\t\t\n";
    fp.open("database.txt",ios::in);
    if(!fp)
    {
        cout<<"file not found";

    }
    else
    {cout<<"\n\t\t\t\t\tProducts\n";
    cout<<"S.NO.\t\tNAME\t\tPRICE\t\tDISCOUNT%\t\tQUANTITY\t\tCODE\n";
    while(fp.read((char*)&b,sizeof(Product)))
    {if(b.getcode()>1999&&b.getcode()<3000)
       {
        cout<<b.category()<<++count<<"\t\t"<<b.getname()<<"\t\t"<<b.getprice()<<"\t\t"<<b.get_dis_per()<<"\t\t\t"<<b.getquantity()<<"\t\t\t"<<b.getcode()<<endl;
       }
    }fp.close();
    fp.open("database.txt",ios::in);
    cout<<"\n\t\t\t\t\tCHOCOLATE\n";
    cout<<"     \t\tNAME\t\tPRICE\t\tDISCOUNT%\t\tQUANTITY\t\tCODE\n";

       while(fp.read((char*)&b,sizeof(Product)))
     {if(b.getcode()>2999&&b.getcode()<4000)
     {
       cout<<b.category()<<++count<<"\t\t"<<b.getname()<<"\t\t"<<b.getprice()<<"\t\t"<<b.get_dis_per()<<"\t\t\t"<<b.getquantity()<<"\t\t\t"<<b.getcode()<<endl;

     }}
     fp.close();
     fp.open("database.txt",ios::in);
     cout<<"\n\t\t\t\t\tNOODELS\n";
     cout<<"     \t\tNAME\t\tPRICE\t\tDISCOUNT%\t\tQUANTITY\t\tCODE\n";


     while(fp.read((char*)&b,sizeof(Product)))
     {if(b.getcode()>3999&&b.getcode()<5000)
     {
       cout<<b.category()<<++count<<"\t\t"<<b.getname()<<"\t\t"<<b.getprice()<<"\t\t"<<b.get_dis_per()<<"\t\t\t"<<b.getquantity()<<"\t\t\t"<<b.getcode()<<endl;

    }
    }
    fp.close();
}
}

void display_record(int num)
{
    bool found=false;
    fp.open("database.txt",ios::in);
    while(fp.read((char*)&b,sizeof(Product)))
    {
        if(b.getcode()==num)
        {
            system("cls");
            b.show_product();
            found=true;
        }
    }

    fp.close();
    if(found == false)
        cout<<"\n\nNo record found";
    getch();
}



void edit_product()
{
    int num;
    char ch;
    float price;
    int quanti;
    float disc;
    char name[50];
    bool found=false;

    cout<<endl<<endl<<"\n\n\tPlease Enter The Product code: ";
    cin>>num;

    fp.open("database.txt",ios::in|ios::out);
    while(fp.read((char*)&b,sizeof(Product)) && found==false)
    {
        if(b.getcode()==num)
        {
            b.show_product();
            cout<<"\n\n.....................................................Please Enter The New Details of Product............................ "<<endl;
            cout<<endl<<"\n\tPlease Enter The Name of The Product: ";
            cin>>name;
            b.setname(name);
            //b.setcode(num);
           co:  cout<<endl<<"\tPlease Enter The Price of The Product: ";
           cin>>price;
           b.setprice(price);
        while(!(b.getprice()))
        {
            cin.clear();
            cin.ignore(123,'\n');
            goto co;
            break;
        }
        cout<<endl<<"\tPlease Enter The Discount % of The Product: ";
        cin>>disc;
        b.set_dis_per(disc);
       ss: cout<<endl<<"\tPlease enter the quantity:";
           cin>>quanti;
           b.set_quantity(quanti);
        //cin>>product_quantity;
        while(!(b.getquantity()))
        {
            cin.clear();
            cin.ignore(123,'\n');
            goto ss;
            break;
        }

        if(b.getquantity()<1)
        {
            cout<<"\tNo quantity added.\nEnter Again";
            goto ss;
        }
            int pos=-1*sizeof(b);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&b,sizeof(Product));
             cout<<endl<<endl<<"\t Record Successfully Updated...";
            found=true;
        }
    }
     fp.close();
   if(!found)
        cout<<endl<<endl<<"Record Not Found...";

    getch();
}



void delete_product()
{bool found=false;
    int num;
    cout<<endl<<endl<<"Please Enter The product code#: ";
    cin>>num;
    fp.open("database.txt",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&b,sizeof(Product)))
    {
        if(b.getcode()!=num)
        {
            fp2.write((char*)&b,sizeof(Product));
        }
        else if(b.getcode()==num)
        {
            b.show_product();
            found=true;
        }
    }
    fp2.close();
    fp.close();
    remove("database.txt");
    rename("Temp.txt","database.txt");
    if(found==true)
    {cout<<endl<<endl<<"\tRecord Deleted...";}
    else
    {
        cout<<"record not found";
    }
    getch();
}

void product_menu()
{int i=0;
    system("cls");
    fp.open("database.txt",ios::in);

    cout<<endl<<endl<<"\t\tProduct MENU\n\n";
    cout<<"*****************************************************\n";
     cout<<"\n\t\t\t\tBISCUIT\n";

    cout<<"S.NO.\t\tNAME\t\tPRICE\t\tQUANTITY\t\tCODE\n";
    while(fp.read((char*)&b,sizeof(Product)))
    {if(b.getcode()>1999&&b.getcode()<3000)
       {
        cout<<b.category()<<++i<<"\t\t"<<b.getname()<<"\t\t"<<b.getprice()<<"\t\t"<<b.getquantity()<<"\t\t\t"<<b.getcode()<<endl;
       }
    }fp.close();
    fp.open("database.txt",ios::in);
    cout<<"\n\t\t\t\tCHOCOLATE\n";
    cout<<"     \t\tNAME\t\tPRICE\t\tQUANTITY\t\tCODE\n";

       while(fp.read((char*)&b,sizeof(Product)))
     {if(b.getcode()>2999&&b.getcode()<4000)
     {
       cout<<b.category()<<++i<<"\t\t"<<b.getname()<<"\t\t"<<b.getprice()<<"\t\t"<<b.getquantity()<<"\t\t\t"<<b.getcode()<<endl;

     }}
     fp.close();
     fp.open("database.txt",ios::in);
     cout<<"\n\t\t\t\t\tNOODELS\n";
     cout<<"     \t\tNAME\t\tPRICE\t\tQUANTITY\t\tCODE\n";


     while(fp.read((char*)&b,sizeof(Product)))
     {if(b.getcode()>3999&&b.getcode()<5000)
     {
       cout<<b.category()<<++i<<"\t\t"<<b.getname()<<"\t\t"<<b.getprice()<<"\t\t"<<b.getquantity()<<"\t\t\t"<<b.getcode()<<endl;

    }
    }
    fp.close();
    getch();
}
void place_order()
{
    int order_arr[50],quan[50],c=0;
    float amt=0,damt=0,discount,total=0;
    char ch='Y';
    show_all_product();
aa:
    cout<<"\t\t\n PLACE YOUR ORDER";

    do
    {   // clrscr();
        cout<<"\n\nEnter The Product code: ";
          while(!(cin>>order_arr[c]))
            {
                cin.clear();
                cin.ignore(123,'\n');
                goto aa;
                break;
            }
        fp.open("database.txt",ios::in);
       {
        if(!fp)
            {
           cout<<"file not found";
            }
               while(fp.read((char*)&b,sizeof(Product)))
	         {
	          if(order_arr[c]==b.getcode())
              {
               fp.close();
                goto take;
              }
              else
                {
                cout<<"NO CODE FOUND!";
                getch();
                fp.close();
                goto aa;
              }
	         }
         }fp.close();
      take: cout<<"\nQuantity: ";
               while(!(cin>>quan[c]))
            {
                cin.clear();
                cin.ignore(123,'\n');
                goto take;
                break;
            }
           fp.open("database.txt",ios::in);
           if(!fp)
                 {
            cout<<"file not found";
            }
               while(fp.read((char*)&b,sizeof(Product)))
	            {if(order_arr[c]==b.getcode())
	               {
                     if(quan[c]>b.getquantity()||b.getquantity()<=0)
                      { cout<<"not enough product";
                        getch();
                        fp.close();
                       goto aa;
                     }

                  if(quan[c]<=0)
                     {
                     cout<<"Please enter he quantity of product\n";
                     getch();
                     fp.close();
                     goto aa;
                     }
	               }
	            }
	            fp.close();

        c++;
        discount=b.get_dis_per();
        cout<<"\nDo You Want To Order Another Product ? (y/n)";
        cin>>ch;
    }
    while(ch=='y' ||ch=='Y');
    savebill(order_arr,quan,discount,c);
    cout<<"\n\nThank You...";
    getch();
}
    void Product::bill(int order_arr[],int quan[],float discount,int c)
	{float amt,damt,total=0;
    system("cls");
    cout<<"\n\n********************************BILL************************\n";
    cout<<"\nPr No.\t\tPr Name\t\tQuantity \t\tPrice\t\tAmount\t\tAmount after discount\n";
    for(int x=0; x<=c; x++)
    {

        fp.open("database.dat",ios::in|ios::out);
        fp.read((char*)&b,sizeof(Product));
        while(!fp.eof())
        {
            if(b.getcode()==order_arr[x])
            {
                amt=b.getprice()*quan[x];
                damt=amt-(amt*(discount/100));
                cout<<"\n"<<order_arr[x]<<"\t\t"<<b.getname()<<"\t \t"<<quan[x]<<"\t \t\t"<<b.getprice()<<"\t \t\t"<<amt<<"\t\t \t"<<damt;
                total+=damt;
                b.product_quantity=b.product_quantity-quan[x];
                if(b.product_quantity>-1)
                {int pos=-1*sizeof(b.product_quantity);
                  fp.seekp(pos,ios::cur);
                  fp.write((char*)&b.product_quantity,sizeof(b.product_quantity));
                }
               else
                {
                    break;
                }
            }
            fp.read((char*)&b,sizeof(Product));
        }
        fp.close();

    }
    cout<<"\n\n\t\t\t\t\t\t\t\t\tTOTAL = "<<total;
    getch();
}

void savebill(int order_arr[],int quan[],float discount,int c)
{
    float amt,damt,total=0;
    f.open("bill.txt",ios::out|ios::app);
    b.bill(order_arr,quan,discount,c);
    f<<"\nPr No.\t\tPr Name\t\tQuantity \t\tPrice\t\tAmount\t\tAmount after discount\n";
      for(int x=0; x<=c; x++)
    {
        fp.open("database.txt",ios::in|ios::out);
        fp.read((char*)&b,sizeof(Product));
        while(!fp.eof())
        {
            if(b.getcode()==order_arr[x])
            {
                amt=b.getprice()*quan[x];
                damt=amt-(amt*discount/100);
                f<<order_arr[x]<<"\t\t"<<b.getname()<<"\t \t"<<quan[x]<<"\t \t\t"<<b.getprice()<<"\t \t\t"<<amt<<"\t\t \t"<<damt;
                total+=damt;
                b.product_quantity=b.product_quantity-quan[x];
                if(b.product_quantity>-1)
                {int pos=-1*sizeof(b.product_quantity);
                  fp.seekp(pos,ios::cur);
                  fp.write((char*)&b.product_quantity,sizeof(b.product_quantity));
                }
               else
                {
                    break;
                }
            }
            fp.read((char*)&b,sizeof(Product));
        }
        fp.close();

    }
    f<<"\n\n\t\t\t\t\t\t\t\t\tTOTAL = "<<total;
    f.close();
}
void read()
{char ch;
 string data;
    f.open("bill.txt",ios::in);
    if(f.is_open()){
    cout<<"\n\n********************************BILL************************\n";
    while(getline(f,data))
    {
     cout<<data<<endl;
    }
    f.close();
    }
    getch();
}


void admin_menu()
{
    char password[20]="pass",username[20]="admin";
    int s,w;
    system("cls");
    cout<<"....................Admin Login......................\n"<<endl;
oo:
    login();
    s=strcmp(pass,password);
    w=strcmp(user,username);
    if(s==0&&w==0)
    {
x:
        system("cls");
bb:
        int option;
        cout<<"....................................ADMIN.................................\n\n\n"<<endl;
        cout<<"\tPress 1 to ADD PRODUCT";
        cout<<"\n\tPress 2 to DISPLAY ALL PRODUCTS";
        cout<<"\n\tPress 3 to QUERY PRODUCT";
        cout<<"\n\tPress 4 to MODIFY PRODUCT";
        cout<<"\n\tPress 5 to DELETE PRODUCT";
        cout<<"\n\tPress 6 to SEE BILL";
        cout<<"\n\tPress 7 to GO BACK TO MAIN MENU";
        cout<<"\n\t";

        cout<<"\n\n\tOption: ";
        cin>>option;
        switch(option)
        {
        case 1:
            system("cls");
             save_product();
            goto x;

        case 2:
            show_all_product();
            getch();
            goto x;

        case 3:
            int num;
            system("cls");
            cout<<"................................Query..................................\n\n\n"<<endl;
            cout<<"\tPlease Enter The Product code: ";
            cin>>num;
            display_record(num);
            goto x;

        case 4:
            cout<<"Do you really want to change?(y/n)";
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                show_all_product();
                edit_product();
                goto x;
            }
            else if(ch=='n'||ch=='N')
            {
                goto x;
            }

        case 5:
            show_all_product();
            delete_product();
            goto x;

         case 6:
             system("cls");
            read();
            goto x;


        case 7:
            system("cls");
            break;

        default:
            admin_menu();
        }
    }
    else
    {
        cout<< "\n\n\tIncorrect username or passsword. enter again!!!!";
        goto oo;
    }
}
void user_menu(){
    char pass1[10]="pass",user1[20]="user";
    int z,a;
    system("cls");
     cout<<"....................User Login......................\n"<<endl;
oo:
    login();
    z=strcmp(pass,pass1);
    a=strcmp(user,user1);
     if(z==0&&a==0)
                {
x:
       system("cls");
       int c;
       go:
            cout<<"....................................USER.................................\n"<<endl;
           cout<<"\n\nEnter the choice\n\t1.PRESS 1 FOR QUERY\n\t2.PRESS 2 FOR ORDER\n\t3.PRESS 3 TO GO BACK TO MENU\n\t";
        cin>>c;
        switch(c)
       {
         case 1: system("cls");
                show_all_product();
                getch();
                goto x;
         case 2:
        place_order();
        goto x;
        break;
        case 3:
            system("cls");
        break;
        default:
            user_menu();
}
                }
                  else
    {
        cout<< "\nIncorrect username or passsword. enter again\n";
        goto oo;
    }
}
int main()
{


            system("cls");
            char option;
            while(1)
            {
                 cout<<".............................................Main Menu............................................\n\n\n";
                cout<<"\t1. USER";
                cout<<"\n\t2. ADMINISTRATOR";
                cout<<"\n\t3. EXIT";


                cout<<"\n\tOption: ";
                cin>>option;
                switch(option)
                {
                case '1':
                    user_menu();
                    break;

                case '2':
                    admin_menu();
                    break;

                case '3':
                    cout<<"\n\tGood Bye!";
                    exit(0);
                    break;

                default :
                    cout<<"Invalid Input...\n";
                }



            }




    return 0;


}

int check(int a)
{
    fp.open("database.dat",ios::in);
    fp.seekg(0,ios::beg);
while(fp.read((char*)&b,sizeof(Product)))
  //while(!fp.eof())
    {if(a==b.getcode())
         {
         cout<<"code already exist"<<endl;
         fp.close();
         return 1;
         break;
        }
        else{
            return 0;
            break;
        }
        //else{cout<<"wrong";}
       // fp.read((char*)&b,sizeof(biscuit));
    }
    fp.close();

}

