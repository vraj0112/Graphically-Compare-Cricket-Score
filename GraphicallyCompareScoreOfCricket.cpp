#include<iostream>
#include<string.h>
#include<graphics.h>
#include<ctime>
#include<cstdlib>
#include<cstdio>
using namespace std;

static int wkt;
static int total;
static int noball;
static int key=0;
static int extra;
static int decision;
static int wonkey;
int first_team_key=0,second_team_key=0;
int total_first_team,total_second_team,extra_first_team,extra_second_team;
int passkey=0;

class Over
{
    string run[6];
public:
    int orun[6]={0};//original Run
    bool wicket[6]={0};

public:

    int i;

    void getOver()
    {
    for(i=0;i<6 && wonkey==0 && wkt!=10;i++)
    {
        start:
        key=0;
        cout<<"Ball :: "<<i+1<<" : ";
        cin>>run[i];


        if(run[i]=="0")
        {
            orun[i]=0;
        }
        else if(run[i]=="1")
        {
            orun[i]=1;
        }
        else if(run[i]=="2")
        {
            orun[i]=2;
        }
        else if(run[i]=="4")
        {
            orun[i]=4;
        }
        else if(run[i]=="6")
        {
            orun[i]=6;
        }
        else if(run[i]=="wkt" && key==0)
        {
            orun[i]=0;
            wkt++;
            wicket[i]=1;

        }
        else if(run[i]=="lbw" && key==0)
        {
            orun[i]=0;
            wkt++;
            wicket[i]=1;
        }
        else if(run[i]=="wide" && key==0)
        {
            orun[i]=0;
            extra++;
            goto start;

        }
        else if(run[i]=="noball")
        {
            noball++;
            extra++;
            if(noball<1)
            {
                goto start;
            }
            else
            {
                cout<<"\nThis Is Free Hit..\n";
                noball=0;
                key=1;
                goto start;
            }
        }
        else if(run[i]=="3")
        {
            orun[i]=3;
        }
        else if(run[i]=="5")
        {
            orun[i]=5;
        }
        else if(key==1 && (run[i]=="wkt" || run[i]=="lbw"))
        {
            if(run[i]=="wkt")
            {
                orun[i]=0;
            }
            if(run[i]=="lbw")
            {
                orun[i]=0;
            }
            key=0;
        }
        else
        {
            cout<<"\nInvalid Input....\n";
            goto start;
        }

        total=total+orun[i];

    if(((first_team_key==1 && decision==1) || (second_team_key==1 && decision==2)) && passkey==1 )
        {
            if((total+extra)>(total_first_team+extra_first_team))
            {
                wonkey=1;
            }
        }
        else if(((first_team_key==1 && decision==2) || (second_team_key==1 && decision==1)) && passkey==1)
        {
            if((total+extra)>(total_second_team+extra_second_team))
            {
                wonkey=1;
            }
        }

    }
    }
};

int main()
{
    int i;
    cout<<"/*This Is A Project To Graphically Compare Score Of Cricket*/";

    int no_of_over;
    cout<<"\nEnter Over Of Match : ";
    cin>>no_of_over;
    fflush(stdin);
    cout<<endl;
    string first_team_name,second_team_name;
    cout<<"Enter Name Of First Team   :: ";
    getline(cin,first_team_name);
    cout<<"Enter Name Of Second Team  :: ";
    getline(cin,second_team_name);

    Over run_of_first_team[no_of_over],run_of_second_team[no_of_over];
    cout<<"\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Match Started \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";

    int selected_toss,original_toss;
    cout<<"**********Coin Tosses.*********** \n";
    starttoss:
    cout<<"Team "<<first_team_name<<" Select Head(Press 1) OR Tail(Press 2) :: ";
    cin>>selected_toss;
    if(selected_toss!=1 && selected_toss!=2)
    {
        cout<<"\nINVALID INPUT!!!!";
        cout<<"\nEnter Again ";
        goto starttoss;
    }

    srand(time(NULL));
    original_toss=(1+rand()%2);
    if(original_toss==1)
    {
        cout<<endl<<"Toss Result :: Head\n\n";
    }
    else
    {
        cout<<endl<<"Toss Result :: Tail\n\n";
    }

    if(selected_toss==original_toss)
    {
        cout<<"Team "<<first_team_name<<" Won The Toss ";
        first_team_key=1;
    }
    else
    {
        cout<<"Team "<<second_team_name<<" Won The Toss ";
        second_team_key=1;
    }

    startdecision:
    cout<<"\nChoose Batting(press 1) OR Bowling(Press 2) :: ";
    cin>>decision;
    if(decision!=1 && decision!=2)
    {
        cout<<"INVALID INPUT!!!!";
        goto startdecision;
    }

    int wkt_first_team,wkt_second_team;

    if((first_team_key==1 && decision==1) || (second_team_key==1 && decision==2) )
    {
        cout<<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Bating Of Team : "<<first_team_name<<" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
     for(i=0;i<no_of_over;i++)
        {
            cout<<"\nEnter Keywords For Wicket(\"wkt\") | Lbw(\"lbw\") | NoBall (\"noball\") | Wide(\"wide\")";
            cout<<"\nOver No: "<<i+1<<">>>\n";
            run_of_first_team[i].getOver();
        }

        total_first_team=total;
        extra_first_team=extra;
        wkt_first_team=wkt;
    }
    else if((first_team_key==1 && decision==2) || (second_team_key==1 && decision==1))
    {
    cout<<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Bating Of Team : "<<second_team_name<<" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        for(i=0;i<no_of_over;i++)
        {
            cout<<"\nEnter Keywords For Wicket(\"wkt\") | Lbw(\"lbw\") | NoBall (\"noball\") | Wide(\"wide\")";
            cout<<"\nOver No: "<<i+1<<">>>\n";
            run_of_second_team[i].getOver();
        }

        total_second_team=total;
        extra_second_team=extra;
        wkt_second_team=wkt;
    }

    passkey=1;
    total=0;
    extra=0;
    wkt=0;
    if((first_team_key==1 && decision==2) || (second_team_key==1 && decision==1))
    {
    cout<<"\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Bating Of Team : "<<first_team_name<<" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        for(i=0;i<no_of_over;i++)
        {
            cout<<"\nEnter Keywords For Wicket(\"wkt\") | Lbw(\"lbw\") | NoBall (\"noball\") | Wide(\"wide\")";
            cout<<"\nOver No: "<<i+1<<">>>\n";
            run_of_first_team[i].getOver();
        }

        startfirstteam:
        total_first_team=total;
        extra_first_team=extra;
        wkt_first_team=wkt;


    }
    else if((first_team_key==1 && decision==1) || (second_team_key==1 && decision==2) )
    {
        cout<<"\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Bating Of Team : "<<second_team_name<<" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
        for(i=0;i<no_of_over;i++)
        {
            cout<<"\nEnter Keywords For Wicket(\"wkt\") | Lbw(\"lbw\") | NoBall (\"noball\") | Wide(\"wide\")";
            cout<<"\nOver No: "<<i+1<<">>>\n";
            run_of_second_team[i].getOver();
        }

        total_second_team=total;
        extra_second_team=extra;
        wkt_second_team=wkt;

    }
    fflush(stdin);
    if((total_first_team+extra_first_team)>(total_second_team+extra_second_team))
    {
    cout<<"\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Team "<<first_team_name<<" Won \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    }
    else
    {
    cout<<"\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Team "<<second_team_name<<" Won \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    }


    cout<<"\n\n\t\t\t\t\tMatch Summary : "<<first_team_name<<endl;
    cout<<"\t\t\t\t\tRun = "<<total_first_team<<endl;
    cout<<"\t\t\t\t\tExtra = "<<extra_first_team<<endl;
    cout<<"\t\t\t\t\tTotal Score = "<<total_first_team+extra_first_team<<"/"<<wkt_first_team<<endl<<endl;

    cout<<"\t\t\t\t\t\tMatch Summary : "<<second_team_name<<endl;
    cout<<"\t\t\t\t\t\tRun = "<<total_second_team<<endl;
    cout<<"\t\t\t\t\t\tExtra = "<<extra_second_team<<endl;
    cout<<"\t\t\t\t\t\tTotal Score = "<<total_second_team+extra_second_team<<"/"<<wkt_second_team<<endl<<endl;

    if((total_first_team+extra_first_team)>(total_second_team+extra_second_team))
    {
    cout<<"\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Team "<<first_team_name<<" Won \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    }
    else
    {
    cout<<"\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Team "<<second_team_name<<" Won \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    }
    cout<<endl<<"X-axis = Balls";
    cout<<endl<<"Y-axis = Runs";
    cout<<endl<<"First Team Graph = Light Green Colour";
    cout<<endl<<"Second Team Graph = Brown Colour"<<endl<<endl;


    //graph Making Coding*/
    int gd = DETECT, gm;//graphic driver
    initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
    line(70,10,70,470);
    line(20,450,600,450);


    int j,scale,h=0,k=0;
    scale=(int)(400/(no_of_over*6));

    setcolor(BLUE);
    for(i=1;i<=6;i++)
    {
        line(20,450-scale*i,600,450-scale*i);
    }
    h=70+scale*6;
    for(i=0;i<no_of_over;i++)
    {
        line(h,10,h,470);
        h=h+scale*6;
    }

//first team graph.....
    h=0;
    setcolor(LIGHTGREEN);
    for(i=0;i<no_of_over;i++)
    {

        for(j=1;j<6;j++)
        {

            line(((h+70)+(j*scale)),(450-(run_of_first_team[i].orun[j-1])*scale),h+(70+(j+1)*scale),(450-(run_of_first_team[i].orun[j])*scale));
            if(j==5)
            {
                h=h+(70+(j+1)*scale)-70;
            }
        }
    }

    h=0;                       //joining two overs
    for(i=1;i<no_of_over;i++)
    {
        line(h+(70+6*scale),(450-(run_of_first_team[i-1].orun[5])*scale),h+70+7*(scale),(450-(run_of_first_team[i].orun[0])*scale));
        h=h+(70+(6)*scale)-70;
    }

    setcolor(YELLOW);
    h=0;
    for(i=0;i<no_of_over;i++)
    {

        for(j=1;j<6;j++)
        {
            setcolor(YELLOW);
            if(run_of_first_team[i].wicket[j-1]==1)
                setcolor(WHITE);

            circle(((h+70)+(j*scale)),(450-(run_of_first_team[i].orun[j-1])*scale),1);
            circle(((h+70)+(j*scale)),(450-(run_of_first_team[i].orun[j-1])*scale),2);
            circle(((h+70)+(j*scale)),(450-(run_of_first_team[i].orun[j-1])*scale),3);
            if(run_of_first_team[i].wicket[j-1]==1)
            circle(((h+70)+(j*scale)),(450-(run_of_first_team[i].orun[j-1])*scale),6);

            setcolor(YELLOW);

            if(run_of_first_team[i].wicket[5]==1)
                setcolor(WHITE);
            circle(((h+70)+(6*scale)),(450-(run_of_first_team[i].orun[5])*scale),1);
            circle(((h+70)+(6*scale)),(450-(run_of_first_team[i].orun[5])*scale),2);
            circle(((h+70)+(6*scale)),(450-(run_of_first_team[i].orun[5])*scale),3);
            if(run_of_first_team[i].wicket[5]==1)
            circle(((h+70)+(6*scale)),(450-(run_of_first_team[i].orun[5])*scale),6);
            if(j==5)
            {
                h=h+(70+(j+1)*scale)-70;
            }
        }

    }

//second team graph making
    setcolor(BROWN);
    h=0;
    for(i=0;i<no_of_over;i++)
    {

        for(j=1;j<6;j++)
        {

            line(((h+70)+(j*scale)),(450-(run_of_second_team[i].orun[j-1])*scale),h+(70+(j+1)*scale),(450-(run_of_second_team[i].orun[j])*scale));
            if(j==5)
            {
                h=h+(70+(j+1)*scale)-70;
            }
        }
    }
    h=0;                                               //joininng two overs
    for(i=1;i<no_of_over;i++)
    {
        line(h+(70+6*scale),(450-(run_of_second_team[i-1].orun[5])*scale),h+70+7*(scale),(450-(run_of_second_team[i].orun[0])*scale));
        h=h+(70+(6)*scale)-70;
    }

    setcolor(YELLOW);
    h=0;
    for(i=0;i<no_of_over;i++)
    {

        for(j=1;j<6;j++)
        {
            setcolor(YELLOW);
            if(run_of_second_team[i].wicket[j-1]==1)
                setcolor(WHITE);

            circle(((h+70)+(j*scale)),(450-(run_of_second_team[i].orun[j-1])*scale),1);
            circle(((h+70)+(j*scale)),(450-(run_of_second_team[i].orun[j-1])*scale),2);
            circle(((h+70)+(j*scale)),(450-(run_of_second_team[i].orun[j-1])*scale),3);
            if(run_of_second_team[i].wicket[j-1]==1)
            circle(((h+70)+(j*scale)),(450-(run_of_second_team[i].orun[j-1])*scale),6);

            setcolor(YELLOW);

            if(run_of_second_team[i].wicket[5]==1)
                setcolor(WHITE);
            circle(((h+70)+(6*scale)),(450-(run_of_second_team[i].orun[5])*scale),1);
            circle(((h+70)+(6*scale)),(450-(run_of_second_team[i].orun[5])*scale),2);
            circle(((h+70)+(6*scale)),(450-(run_of_second_team[i].orun[5])*scale),3);
            if(run_of_second_team[i].wicket[5]==1)
            circle(((h+70)+(6*scale)),(450-(run_of_second_team[i].orun[5])*scale),6);
            if(j==5)
            {
                h=h+(70+(j+1)*scale)-70;
                k=k+(450-(run_of_first_team[i].orun[j])*scale);
            }
        }

    }
    getch();
    closegraph();
    return 0;
}
