#include<bits/stdc++.h>
#include<dos.h>
#include<windows.h>
using namespace std;

struct stack {
   int s[5];
   int top;
} st;

struct stack1 {
   int s1[5];
   int top1;
} st1;

void push(int item,int top) {


   st.s[top]=item;
}
void push1(int item1,int top1) {


   st1.s1[top1]=item1;
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int pop(int top) {
    //cout<<top<<" ";
   int item;
   item=st.s[top];
   return (item);
}
int pop1(int top1) {
    //cout<<top1<<" ";
   int item1;
   item1=st1.s1[top1];
   return (item1);
}


           struct node
{
    char key;
    struct node *left, *right;
};

struct nodel
{
    char data;
     struct nodel *next;

}*p=NULL,*start=NULL;

 struct node1
{
    char data1;
     struct node1 *next1;

}*p1=NULL,*start1=NULL;
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }
void ClearConsoleToColors(int ForgC, int BackC)
{
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                     //This is used to reset the carat/cursor to the top left.
 COORD coord = {0, 0};
                  //A return value... indicating how many chars were written
                    //   not used but we need to capture this since it will be
                      //   written anyway (passing NULL causes an access violation).
  DWORD count;

                               //This is a structure containing all of the console info
                      // it is used here to find the size of the console.
 CONSOLE_SCREEN_BUFFER_INFO csbi;
                 //Here we will set the current color
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                          //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
}

void inserte(char x)
{
    struct nodel* ptr = (struct nodel*)malloc(sizeof(struct nodel));
     ptr->data=x;
    if(p==NULL)
    {
        p=ptr;
        p->next=NULL;

    }
    else {
            start=p;// Start is used to keep the track of first pointer, after ending of this part we will point p to start
        while(p->next!=NULL)
        {

            p=p->next;

        }
        p->next=ptr;
        ptr->next=NULL;
        p=start;
    }
}
void inserte1(char x)
{
   struct node1* ptr1 = (struct node1*)malloc(sizeof(struct node1));

     ptr1->data1=x;
    if(p1==NULL)
    {
        p1=ptr1;
        p1->next1=NULL;

    }
    else {
            start1=p1;// Start is used to keep the track of first pointer, after ending of this part we will point p to start
        while(p1->next1!=NULL)
        {

            p1=p1->next1;

        }
        p1->next1=ptr1;
        ptr1->next1=NULL;
        p1=start1;
    }
}
void display()
{

     start=p;// Start is used to keep the track of first pointer, after ending of this part we will point p to start
     while(p!=NULL)
     {
         printf("%c ",p->data);
         p=p->next;
         //printf("HI");
     }
     p=start;
     printf("\n");

}
void display1()
{

     start1=p1;// Start is used to keep the track of first pointer, after ending of this part we will point p to start
     while(p1!=NULL)
     {
         printf("%c ",p1->data1);
         p1=p1->next1;
         //printf("HI");
     }
     p1=start1;
     printf("\n");

}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c \n", root->key);
        inorder(root->right);
    }
}
int search(struct node* root,char key){


   while(root->key != key){

      if(root != NULL) {
        // printf("%c ",root->key);

         //go to left tree
         if(root->key > key){
            root = root->left;
         }//else go to right tree
         else {
            root = root->right;
         }

         //not found
         if(root == NULL){
            return -1;
         }
      }
   }
   return 1;
}
// A utility function to create a new BST node
struct node *newNode(char item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, char key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

int main()

{
    ClearConsoleToColors(0,15);
   do{  system("cls"); SetColor(4);
        string q = "\t\t\tWELCOME TO GAMING ARENA";
    for(int i=0;i<q.size();i++)
    {
        cout<<q[i];
        delay(120);

    }
    cout<<endl; SetColor(1);
    cout<<"\t\t\t1. Bollywood\n\t\t\t2. Line Racing\n\t\t\t3. Country Quiz\n\t\t\t4. Exit\n";
    int c;
    cout<<"\t\t\tEnter your choice: ";
    cin>>c;
    switch(c)
    {
        case 1 : {

            system("cls");
            string q = "WELCOME TO BOLLYWOOD";
          for(int i=0;i<q.size();i++)
         {
        cout<<q[i];
        delay(120);

         }
         cout<<endl<<endl;
         char z;
         cout<<"This is the conventional movie guessing game in which one is asked to correctly guess each letter one at a time. If the letter occurs in movie name, the character is displayed, or else the chance is cut and in this way if you are void of remaining chances, game is over."<<endl<<endl;
         cout<<"Press any letter to continue : ";
         cin>>z;
         system("cls");
         char a[][100]=
    {
        "JOHNNY GADDAR",
        "DRISHYAM",
        "VEER ZAARA",
        "RAMAIYA VASTAVAIYA",
        "AE DIL HAI MUSHKIL",
        "SADDA ADDA",
        "NH10",
        "DUM LAGA KE HAISHA",
        "CHAIN KHULI KI MAIN KHULI",
        "PINK",
        "36 CHINA TOWN",
        "FUN2SHH",
        "3 IDIOTS",
        "CHAK DE INDIA",
        "MUNNA BHAI MBBS",
        "KUCHH KUCHH HOTA HAI",
        "ANDAAZ APNA APNA",
        "TAARE ZAMEEN PAR",
        "KHOSHLA KA GHOSLA",
        "PAAN SINGH TOMAR",
        "MR X",
        "1920",
        "D DAY",
        "COCKTAIL",
        "JAJANTARAM MAMANTARAM",
        "LAGAAN",
        "MS DHONI",
        "KOI MIL GYA",
        "ZINDAGI NA MILEGI DOBARA",
        "ROCK ON"
    };
srand (time(NULL));
int x = rand()%30;
//cout<<x<<endl;
string s = a[x];


struct node *root = NULL;
    root = insert(root,s[0] );
for(int i=1;i<s.size();i++)
{
    if(s[i]!=' ')
    insert(root, s[i]);
}


//cout<<search(root,'M')<<endl;
//cout<<search(root,'L')<<endl;
string s3 = "bollywood";
string s2;
string s4;
int count = 9;
for(int i=0;i<s.size();i++)
{
    if(s[i]==' ')
        s2.push_back('/');
    else s2.push_back('*');


}
for(int i=0;i<s.size();i++)
{
    if(s[i]=='A')
        s2[i]='A';
    if(s[i]=='E')
        s2[i]='E';
    if(s[i]=='I')
        s2[i]='I';
    if(s[i]=='O')
        s2[i]='O';
    if(s[i]=='U')
        s2[i]='U';


}

cout<<"Your movie is"<<endl;
cout<<s2<<endl;
while(1)
{    fflush(stdin);
    char ch;
    cout<<"Enter a character to find : ";
    cin>>ch;
    ch = toupper(ch);
    if(search(root,ch)==-1)
    {
        for(int j=0;j<9;j++)
        {
            if(s3[j]!='*')
                {s3[j]='*';
                break;}

        }
        s4.push_back(ch);
        SetColor(12);
        cout<<"Sorry the character was not present in the string"<<endl;
        SetColor(1);
        cout<<"Characters left : "<<s3<<endl;
        cout<<"Wrong Entries : "<<s4<<endl;
        cout<<"Film Status: "<<s2<<endl;

        count--;
        cout<<endl;
    }
    else
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==ch)
            {
                s2[i]=ch;
            }
        }
        SetColor(10);
        cout<<"Character found!!"<<endl;
        SetColor(1);
        cout<<"Characters left : "<<s3<<endl;
        cout<<"Wrong Entries : "<<s4<<endl;
        cout<<"Film Status: "<<s2<<endl;

      cout<<endl;

    }
    if(count==0)
        {   SetColor(12);
            cout<<"Sorry! You ran out of chances"<<endl;
            SetColor(1);
            cout<<"Movie was: "<<s<<endl;
            break;}
    if(find(s2.begin(),s2.end(),'*')==s2.end())
    {   SetColor(10);
        cout<<"Congrats!!"<<endl;
        cout<<"You guessed it right"<<endl;
        SetColor(1);
        cout<<"The film was : "<<s<<endl;
        break;
    }

    }
    delay(5000);
    free(root);
    break;
        }
        case 2 : {
            system("cls");
            string q = "WELCOME TO LINE RACING";
          for(int i=0;i<q.size();i++)
         {
        cout<<q[i];
        delay(120);
         }
         cout<<endl<<endl;
         char z;
         cout<<"This is the 2 Player racing game based on luck,i.e throw of a dice.Each player is given a chance to roll the dice, and accordingly character is advanced in line. The player whose character reaches the end 1st, is declared as winner. "<<endl<<endl;
         cout<<"Press any letter to continue : ";
         cin>>z;
         system("cls");

    for(int i=0;i<30;i++)
    {   if(i==0)
    {
       inserte('|');}

       else {
            inserte('_');}
    }
    for(int i=0;i<30;i++)
    {   if(i==0)
       {
        inserte1('|');}
       else  {

            inserte1('_');
    }}
    int count =0;
    string s;
    string s1;
    SetColor(11);
    cout<<"Enter name for player 1 : ";
    SetColor(1);
    getline(cin>>ws,s);
    SetColor(13);
    cout<<"Enter name for player 2 : ";
    SetColor(1);
    getline(cin>>ws,s1);
    system("cls");

    while(1)
    {
        string s3 = "......";
        if((count%2)==0)
        {   char ch;
            int flag=0;
            cout<<s<<" , Your turn"<<endl;
            do
                    {cout<<"Press 'y' to roll your dice, Press 'n' to pass : ";
            cin>>ch;}while(ch!='n'&&ch!='y');
            if(ch=='n')
                cout<<"Your turn is passed!!"<<endl;
            if(ch=='y')
            {

                srand (time(NULL));
                int x = rand()%6;
                x = x+1;
                //cout<<x<<" ";
                cout<<"Your Dice Number ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s3[i];
                }
                cout<<" : "<<x<<endl;
                start= p;
                int count1=1,flag1=0,c,flag2=0;
                while(p->next!=NULL)
                {   count1++;
                    if(p->data=='|')
                        {p->data='_';
                         c = count1;
                   flag2=1; }
                    else {
                            //cout<<"hi"<<endl;
                        if(((x+c)==count1)&&flag2==1)
                            {p->data='|';
                            flag1=1;
                            break;}
                    }
                   // cout<<p->data<<" "<<endl;
                    p=p->next;

                }

                p=start;
                cout<<"Status of "<<s<<"'s line : "<<endl;
                SetColor(12);
                display();
                SetColor(1);
                cout<<endl;
                 cout<<"Status of "<<s1<<"'s line : "<<endl;
                 SetColor(10);
                display1();
                SetColor(1);

                if(flag1==0)
                {
                    cout<<"GAME OVER!!"<<endl;
                    cout<<s<<" WON!!"<<endl;
                    delay(3000);
                    break;
                }
                cout<<endl;
delay(3000);
            }
system("cls");
    }
    else
    {
         char ch;
            int flag=0;
            cout<<s1<<" , Your turn"<<endl;
            do
                    {cout<<"Press 'y' to roll your dice, Press 'n' to pass : ";
            cin>>ch;}while(ch!='n'&&ch!='y');
            if(ch=='n')
                cout<<"Your turn is passed!!"<<endl;
            if(ch=='y')
            {

                srand (time(NULL));
                int x = rand()%6;
                x = x+1;
                cout<<"Your Dice Number ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s3[i];
                }
                cout<<" : "<<x<<endl;
                start1= p1;
                int count1=1,flag1=0,c,flag2=0;
                while(p1->next1!=NULL)
                {   count1++;
                    if(p1->data1=='|')
                        {p1->data1='_';
                         c = count1;
                   flag2=1; }
                    else {
                            //cout<<"hi"<<endl;
                        if(((x+c)==count1)&&flag2==1)
                            {p1->data1='|';
                            flag1=1;
                            break;}
                    }
                    //cout<<p1->data1<<" "<<endl;
                    p1=p1->next1;

                }

                p1=start1;
                cout<<"Status of "<<s<<"'s line : "<<endl;
                SetColor(12);
                display();
                SetColor(1);
                cout<<endl;
                 cout<<"Status of "<<s1<<"'s line : "<<endl;
                 SetColor(10);
                display1();
                SetColor(1);
                if(flag1==0)
                {   cout<<endl;
                    cout<<"GAME OVER!!"<<endl;
                    cout<<s1<<" WON!!"<<endl;
                    delay(3000);
                    break;
                }
                cout<<endl;
                delay(3000);
            }
system("cls");
    }
count++;
}
  p=NULL;
  p1=NULL;
  start= NULL;
  start1= NULL;
        break;
        }
        case 3 : {

            system("cls");
            string q = "WELCOME TO COUNTRY QUIZ";
          for(int i=0;i<q.size();i++)
         {
        cout<<q[i];
        delay(120);
         }
         cout<<endl<<endl;
         char z;
         cout<<"This is a 2 player quiz game.\n Each person is given 5 questions to answer,\n correct answer gives 10 marks,\n wrong gives -4, \n passing fetches 0\n and correct with hint gives 7 marks.\n Person with most marks at end, wins. "<<endl<<endl;
         cout<<"Press any letter to continue : ";
         cin>>z;
         system("cls");

            int top = -1;
    int top1 = -1;

char b[][30]=
{
    "INDIA",
    "MALAYSIA",
    "JAPAN",
    "THAILAND",
    "BHUTAN",
    "INDONESIA",
    "AUSTRALIA",
    "SRI LANKA",
    "RUSSIA",
    "CHINA",
    "UKRAINE",
    "PAKISTAN",
    "EGYPT",
    "SOUTH AFRICA",
    "CANADA",
    "ENGLAND",
    "ICELAND",
    "GERMANY",
    "JAMAICA",
    "BRAZIL",
    "UNITED ARAB EMIRATES",
    "NORWAY",
    "NEW ZEALAND",
    "BANGLADESH",
    "ARGENTINA",
    "PORTUGAL",
    "VATICAN CITY",
    "MALDIVES"
};
char s6[][100]=
{

    "It is known to be worlds largest Democracy",
    "Capital of this country is Kuala Lampur",
    "Known as the Land of Rising Sun",
    "This country is home to White Elephants",
    "It is known as Land of Thunder Dragons",
    "The world's largest flower, Rafflesia Arnoldi, grows only in this country",
    "It is home to Kangaroos",
    "Has south borders with India, Home to Ravana",
    "Largest country by land",
    "World largest Population resides in this country",
    "Largest country by area in Europe (excluding Russia)",
    "Divided from India during Independence",
    "Home to Pyramids",
    "Leading producer of Platinum in the world",
    "Most Educated country in the World",
    "Only country not ruled by any other country in history",
    "Mosquito free country, known as oldest democracies",
    "Hitler was from this country",
    "Worlds fastest Man is from this country",
    "Largest Producer of coffee",
    "World tallest building is in this Country",
    "Known as Land of Midnight Sun",
    "Famous for KIWI",
    "Got sepearted from India in 1971",
    "Name comes from the Latin word of silver",
    "Home to famous soccer player - Christiano Ronaldo",
    "Smallest country of the world",
    "Island nation in South of India, Capital is Male"

};

string s,s1;
SetColor(11);
cout<<"Enter the name of Player 1 : ";
SetColor(1);
getline(cin>>ws,s);
SetColor(13);
cout<<"Enter the name of Player 2 : ";
SetColor(1);
getline(cin>>ws,s1);
system("cls");

 cout<<s<<" plays First"<<endl;
 delay(1000);
for(int i=0;i<5;i++)
{
         system("cls");
        srand(time(NULL));
        int x = rand()%28;
        string s2 = s6[x];
        string s3 = b[x];
        string s4;
        int flag = 0;
        cout<<"Your "<<i+1<<" Question is "<<endl;
        cout<<s2<<endl;
        cout<<"Press p to pass(0 score)"<<endl;
        cout<<"Press h for hint( Deducts 3 points )"<<endl;
        getline(cin>>ws,s4);
        for(int i=0;i<s4.size();i++)
        {
            s4[i]=toupper(s4[i]);

        }
         if(s4=="H")
        {
            flag=1;
            cout<<"The name starts from : "<<s3[0]<<endl;
            cout<<"Enter your guess now"<<endl;
            getline(cin>>ws,s4);
            for(int i=0;i<s4.size();i++)
        {
            s4[i]=toupper(s4[i]);

        }


        }
        if(s4=="P")
        {

            top++;
            push(0,top);

            continue;

        }
        if(s4==b[x]&&flag==0)
        {
            SetColor(10);
            cout<<"Your answer is correct!!"<<endl;
            cout<<"You score 10 from this one!"<<endl;
            SetColor(1);
            top++;
            push(10,top);
            delay(3000);
            continue;
        }
        if(s4==b[x]&&flag==1)
        {
            SetColor(14);
            cout<<"Your answer is correct, but you used a hint!!"<<endl;
            cout<<"You score 7 from this one!"<<endl;
            SetColor(1);
            top++;
            push(7,top);
        }
        else {
            SetColor(12);
            cout<<"Sorry, your answer is wrong !!"<<endl;
            cout<<"You scored a -4"<<endl;
            SetColor(1);
            top++;

            push(-4,top);


        }
delay(3000);
}
system("cls");
cout<<s1<<" plays Now"<<endl;
delay(2000);
for(int i=0;i<5;i++)
{
         system("cls");
        int num = 10;
        srand(time(NULL));
        int x = rand()%28;
        string s2 = s6[x];
        string s3 = b[x];
        string s4;
        int flag = 0;
        cout<<"Your "<<i+1<<" Question is "<<endl;
        cout<<s2<<endl;
        cout<<"Press p to pass(0 score)"<<endl;
        cout<<"Press h for hint( Deducts 3 points )"<<endl;
        getline(cin>>ws,s4);
        for(int i=0;i<s4.size();i++)
        {
            s4[i]=toupper(s4[i]);

        }
         if(s4=="H")
        {
            flag=1;
            cout<<"The name starts from : "<<s3[0]<<endl;
            cout<<"Enter your guess now"<<endl;
            getline(cin>>ws,s4);
for(int i=0;i<s4.size();i++)
        {
            s4[i]=toupper(s4[i]);

        }

        }
        if(s4=="P")
        {   top1++;
            push1(0,top1);
            continue;

        }
        if(s4==b[x]&&flag==0)
        {
            SetColor(10);
            cout<<"Your answer is correct!!"<<endl;
            cout<<"You score 10 from this one!"<<endl;
            SetColor(1);
            top1++;
            push1(10,top1);
            delay(3000);
            continue;

        }
        if(s4==b[x]&&flag==1)
        {
            SetColor(14);
            cout<<"Your answer is correct, but you used a hint!!"<<endl;
            cout<<"You score 7 from this one!"<<endl;
            SetColor(1);
            top1++;

            push1(7,top1);
        }
        else {
            SetColor(12);
            cout<<"Sorry, your answer is wrong !!"<<endl;
            cout<<"You scored a -4"<<endl;
            SetColor(1);
            top1++;
            push1(-4,top1);

        }
delay(3000);
}
system("cls");

int sum=0,sum1=0;
for(int j=0;j<5;j++)
{    //cout<<sum<<" "<<sum1<<" ";

    sum+=pop(top);
    top--;
    sum1+=pop1(top1);
    top1--;

}
string s7 = "......";
if(sum>sum1)
{
    cout<<"The scores are : "<<endl;
    cout<<s<<" scores ";
     for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
    cout<<sum<<endl;
    cout<<s1<<" scores ";
     for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
    cout<<sum1<<endl;
    SetColor(10);
    cout<<s<<"WINS"<<endl;
    SetColor(1);

}
else
if(sum<sum1)
{
    cout<<"The scores are : "<<endl;
    cout<<s<<" scores ";
     for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
    cout<<sum<<endl;
    cout<<s1<<" scores ";
     for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
    cout<<sum1<<endl;
    SetColor(10);
    cout<<s1<<" WINS"<<endl;
    SetColor(1);

}else {SetColor(14);
    cout<<"ITS A DRAW!!"<<endl;
    SetColor(1);
         cout<<"Both score : "<<sum<<endl;
}

st.s[5]={0};
st1.s1[5]={0};

delay(3000);


            break;}
        case 4 : {
            system("cls");
            exit(0);}
        default : break;


    }}while(1);

}
