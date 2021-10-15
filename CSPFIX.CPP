#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include "utility.cpp"
//using namespace std;
void help()
{ cout<<"\n\n\tWelcome to our quiz!";
  cout<<"\n\nThis is a multiple choice quiz game where you type in your desired answer choice.";
  cout<<"\nYou have the option of facing an easy, medium or hard level of question \n difficulty.";
  cout<<"\nIf you feel you are not ready yet, you can try the practice round which gives\n you questions based on your performance.";
  cout<<"\n\nYou have one lifeline available to you if you are stuck at a question. Press <e> to use it.";
  cout<<"\n\t1) 50:50 : Eliminate two wrong answer choices.";
  cout<<"\n\t2) Audience poll: View the responses of the audience to the question.";
  cout<<"\n\t3) Phone a friend: Ask a friend for the answer within 30 seconds.\n";
 // goto M;
}
void load()
{
cout<<endl;
for(int ild=0; ild<5; ++ild)
	{
	cout<<"|";
	sleep(1);
	}
}

void audience_pole()
{
cout<<"% of votes"<<"\n\n"<<'^';
for(int iap=1;iap<=6;++iap)
{	for(int jap=1;jap<iap;++jap)
	{cout<<"|  ";}
cout<<"\n";
}
for(int kap=1;kap<15;++kap)
cout<<'-';
cout<<"> Option"<<'\n';
cout<<"   A  B  C  D"<<'\n';
cout<<"  40 30 20 10"<<'\n';
}
void phone()
{
cout<<"You have exactly 30 seconds to ask someone";
sleep(10);
cout<<"\n Your time is up!\n";
}

/*
struct ques
{ char q[50],o[50],corr;
}ob,e[15],m[15],h[15],c[15];
*/
ques ob, e[15], m[15], h[15], c[15], oq[15];

void assign(ques q1[], ques q2[], int l=7)
{
	for(int i=0; i<l; ++i)
	q2[i] = q1[i];
}

void adapt(char curlevel[])
{
 ifstream f(curlevel, ios::binary);
}

int isExist(int a[], int x, int l) {
      int found=0;
      for(int i=0; i<l; ++i) {
	    if(a[i]==x)  {
		  found=1;
	    }

      }
      return found;
}

char *tempTransform(char *lvFile) {
      char *level;
      strcpy(level, "Medium");
      if(!strcmpi(lvFile,"easy.dat")) {
	strcpy(level, "Easy");
      }
      else if(!strcmpi(lvFile, "medium.dat")) {
	strcpy(level, "Medium");
      }
      else if(!strcmpi(lvFile, "hard.dat")) {
	strcpy(level, "Hard");
      }
}

void play(int ch)
{
int score=0; int f50=0,fp=0,fap=0;char curlevel[15]="\0";
if(ch==1)
     strcpy(curlevel,"easy.dat");
else if(ch==2)
     strcpy(curlevel,"medium.dat");
else if(ch==3)
     strcpy(curlevel,"hard.dat");

  if(!strcmpi(curlevel, "easy.dat")) {
	assign(e,oq);
  }
  else if(!strcmpi(curlevel, "medium.dat")) {
	assign(m,oq);
  }
  else if(!strcmpi(curlevel, "hard.dat")) {
	assign(h,oq);
  }
  //ifstream f(curlevel,ios::binary);
  //if(!f) return;
      //while(f.read((char*)&ob,sizeof(ob)))

      if(ch==1 || ch==2 || ch==3) {
	  int askedQn[7] = {-1, -1, -1, -1, -1, -1, -1};
      int rx;
      for(int iq=0; iq<7; ++iq)
      {
		randomize();
		do {
		   rx = random(7);
		}while(isExist(askedQn, rx, iq));
		//cout<<"\nrandom num now"<<rx<<" \n";
		askedQn[iq]=rx;
		sleep(1); clrscr(); gotoxy(3,3);
		Q1: puts(oq[rx].q); puts(oq[rx].o); char a;
		cin>>a;
		if(a==oq[rx].corr || toupper(a)==oq[rx].corr)
		  {
		  cout<<"Correct answer!";
		  score+=1000;
		  cout<<" Your score is "<<score<<"\n\n";
	      }

	    else if(a=='E'||a=='e')
		{ L1:
		int l1;
		sleep(1); clrscr(); gotoxy(3,3); //lifeline clear
		cout<<"\n1. 50:50   2.Audience Poll   3. Phone-a-friend :> ";
		cin>>l1;
		if(l1==1 && f50==0)
		{++f50;
		cout<<oq[rx].corr<<'\t';
		randomize();
		char c=oq[rx].corr;
		while(c==oq[rx].corr)
		 {
		  c=char(random(4)+65);
		 }
	     cout<<c<<endl;
		goto Q1;}
		else if(l1==2 && fap==0)
		{++fap;
		audience_pole(		);
		goto Q1;}
		else if(l1==3 && fp==0)
		{++fp;
		phone();
		goto Q1;}
		else if(l1==1 && f50!=0)
		{cout<<"\n Lifeline already used. Each lifeline can be used only once.\n";
		goto Q1;}
		else if(l1==2 && fap!=0)
		{cout<<"\n Lifeline already used. Each lifeline can be used only once.\n";
		goto Q1;}
		else if(l1==3 && fp!=0)
		{cout<<"\n Lifeline already used. Each lifeline can be used only once.\n";
		goto Q1;}
		else
		{cout<<"Enter valid lifeline ";
		goto Q1;}

	}
       //	cout<<"Your Score is "<<score;

	else
	cout<<"Incorrect answer. The right answer is "<<oq[rx].corr<<"\n\n	";
	//sleep(1);

      }
      if(askedQn[6]!=-1) {
	cout<<"\nYour total score is "<<score<<endl;
      }
}

if(ch==4)
{       strcpy(curlevel,"medium.dat");
	cout<<"\nPractice Loading...\n";
	int S[10],i=0;
	//ifstream f(curlevel,ios::binary);
	//if(!f) return;
	assign(m,c);
	//for(int j=0; j<10; j++)
	//{
	//while(f.read((char*)&ob,sizeof(ob)))
	while(i<7)
	{
		sleep(1);
		clrscr(); gotoxy(5,5);
		//cout<<"\nIndex "<<i;
		cout<<"\nDisplaying qn of difficulty level "<<tempTransform(curlevel)<<"\n\n";
		//puts(ob.q); puts(ob.o);
		puts(c[i].q); puts(c[i].o);
		char a;
		cin>>a;
		//if(a==ob.corr||toupper(a)==ob.corr)
		if(a==c[i].corr || toupper(a)==c[i].corr)
		{
			cout<<"Correct answer!";
			S[i]=1;
		}
		else
		{
			cout<<"Wrong answer!";
			S[i]=0;
		}

		//if(i==3) { cout<<"index of 3 "; cout<<S[0]<<S[1]<<S[2]; }
		//cout<<"\nindex at this point "<<i;
		if(i>=2 && S[i-2]==0 && S[i-1]==0 && S[i]==0 && strcmpi(curlevel,"easy.dat")!=0)
		{       i=0;
			//cout<<"going here";
			cout<<"These questions are a bit challenging, aren't they? Don't worry, try something simpler..";

			if(!strcmpi(curlevel,"hard.dat"))
			{       cout<<"Let's make it easier.."<<endl;
				strcpy(curlevel,"medium.dat");
				//f.close();
				//ifstream f("medium.dat",ios::binary);
				assign(m,c);
			}
			else if(!strcmpi(curlevel,"medium.dat"))
			{
				cout<<"Let's make it easy.."<<endl;
				strcpy(curlevel,"easy.dat");
				//f.close();
				//ifstream f("easy.dat",ios::binary);
				assign(e,c);
			}
		}


		else if(i>=2 && S[i-2]==1 && S[i-1]==1 && S[i]==1 && strcmpi(curlevel,"hard.dat")!=0)
		{       //cout<<"\ngoing to this nest";
			i=0;
			cout<<"Great work! Try these now..";
			//cout<<"\ncurlevel "; puts(curlevel);
			if(strcmpi(curlevel,"medium.dat")==0)
			{
				cout<<"\nLet's make it hard\n!";
				//f.close();
				strcpy(curlevel,"hard.dat");
				assign(h,c);
				//adapt("hard.dat");
			}
			else if(!strcmpi(curlevel,"easy.dat"))
			{
				//cout<<"\ngoing back to nestynest";
				strcpy(curlevel,"medium.dat");
				//f.close();
				assign(m,c);
				//adapt(curlevel);
			}
		 }
		 else
			i++;
	}
}
//}

}
void main()
{
clrscr();
    //creatingFiles
    createEasy();
    createMedium();
    createHard();
    //Reading from easy file:
    ifstream f1("easy.dat",ios::binary);
    if(!f1) return;
    int cte=0;
    while(f1.read((char*)&ob,sizeof(ob)))
     {
       e[cte++]=ob;
     }

     ifstream f2("medium.dat",ios::binary);
    if(!f2) return;
    int ctm=0;
    while(f2.read((char*)&ob,sizeof(ob)))
     {
       m[ctm++]=ob;
     }
     //Checking;

     ifstream f3("hard.dat",ios::binary);
    if(!f3) return;
    int cth=0;
    while(f3.read((char*)&ob,sizeof(ob)))
     {
       h[cth++]=ob;
     }
char c;
textcolor(5);
do {
cout<<"\t\t\t\tGAME:";
int ch;
help();
M: cout<<"\nMenu:\n\t1. Easy round\n\t2. Medium round\n\t3. Tough round\n\t4. Practice round\n\nEnter choice: ";
cin>>ch;
cout<<"\nPlz. Wait. Loading...";
//load();
clrscr();
switch (ch)
{
 //case 1: cout<<"Instructions"; help(); //TODO
 case 1: play(ch); break;
 case 2: play(ch); break;
 case 3: play(ch); break;
 case 4: play(ch); break;
 //case 5: play(ch); break;
 default:cout<<"Invalid option"; goto M;
}
cout<<"\nDo you want to play again? (Y/N) :> "; cin>>c;
}while(c=='Y' || c=='y');
getch();
}




