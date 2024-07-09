#include<iostream>
#include<cstdlib>
using namespace std;
enum enStonPaperscissor {stone=1,paper=2,scissor=3,NoWanner=4};
enum enWinnerUserOrPc {user = 1,pc = 2,noWanner=3};
int ReadPositiveNumberInRange(int from,int to,string massege)
{
    int number;
    do {
        cout<<massege<<endl;
        cin>>number;
    }while(!(number>from && number<to));
    return number;
}
int RandomNumber(int from,int to)
{
    return rand()%(to-from+1)+from;
}
void UserChoisefunc(int& UserChoise) {
 UserChoise = ReadPositiveNumberInRange(0,4,"Enter Your Choise Stone [1] || Paper [2]  || scissor [3]");
}
void PcChoisefunc(int& PcChoise) {
    PcChoise = RandomNumber(1,3);
}
void checkresult(int UserChoise,int PcChoise,int& result)
{
    if(UserChoise == enStonPaperscissor::paper && PcChoise ==enStonPaperscissor::stone)
       result = enStonPaperscissor::paper;
    else if(UserChoise == enStonPaperscissor::paper && PcChoise ==enStonPaperscissor::scissor)
       result = enStonPaperscissor::scissor;

    else if(UserChoise == enStonPaperscissor::stone && PcChoise == enStonPaperscissor::scissor)
        result = enStonPaperscissor::stone;
    else if(UserChoise == enStonPaperscissor::stone && PcChoise == enStonPaperscissor::paper)
        result = enStonPaperscissor::paper;

    else if(UserChoise = enStonPaperscissor::scissor && PcChoise == enStonPaperscissor::paper) 
        result = enStonPaperscissor::scissor;
    else if(UserChoise = enStonPaperscissor::scissor && PcChoise == enStonPaperscissor::stone) 
        result = enStonPaperscissor::stone;
    else if(UserChoise == PcChoise)
        result = enStonPaperscissor::NoWanner;
    
}
int whoIsTheWinner(int result,int UserChoise,int PcChoise,int& Winner) {
    if(result == UserChoise)
       Winner=enWinnerUserOrPc::user;
    else if(result == PcChoise)
      Winner=enWinnerUserOrPc::pc;
    else if(result == UserChoise && result == PcChoise)
     Winner = enWinnerUserOrPc::noWanner;
 return Winner;
}
string WinnerOutPut(int choiseValue) {
    string OutPut="";
    if(choiseValue == enWinnerUserOrPc::user)
        OutPut = "User";
    else if(choiseValue == enWinnerUserOrPc::pc)
        OutPut = "Pc";
    else if(choiseValue == enWinnerUserOrPc::noWanner)
        OutPut = "No Winner";
return OutPut;
}
string GetChoise(int Choise) {
    string StrChoise = "";
   if(Choise == enStonPaperscissor::paper)
        StrChoise = "Paper";
    else if(Choise == enStonPaperscissor::stone)
        StrChoise = "Stone";
    else if(Choise == enStonPaperscissor::scissor)
        StrChoise = "Scissor";
  return StrChoise;
}
string ChoiseOutPut(int choiseValue) {
    string OutPut="";
    if(choiseValue == enStonPaperscissor::paper)
        OutPut = "Paper";
    else if(choiseValue == enStonPaperscissor::stone)
        OutPut = "Stone";
    else if(choiseValue == enStonPaperscissor::scissor)
        OutPut = "Scissor";
return OutPut;
}
void GameOverInfo(int& UserWins,int& PcWins,int& DrowTimes,int& RoundTimes,int Winner) {
RoundTimes++;
if(Winner == enWinnerUserOrPc::pc)
    PcWins++;
else if(Winner == enWinnerUserOrPc::user)
    UserWins++;
else if(Winner == enWinnerUserOrPc::pc && Winner == enWinnerUserOrPc::user)
    DrowTimes++;
};
void GameOverMenu(int UserWins,int PcWins,int DrowTimes,int RoundTimes) {
cout<<"------------[Game Over]----------"<<endl;
cout<<"User Wins : "<<UserWins<<endl;
cout<<" Pc Wins : "<<PcWins<<endl;
cout<<"Drow Times : "<<DrowTimes<<endl;
cout<<"Round Times : "<<RoundTimes<<endl;
cout<<"-----------------------------------"<<endl;
}

void StonePaperScissorGame(int UserChoise,int PcChoise,int& Result,int& Userwins,int& PcWins,int& DrowTimes,int& RoundTimes,int& Winner)
{
UserChoisefunc(UserChoise);
PcChoisefunc(PcChoise);

cout<<"user : "<<ChoiseOutPut(UserChoise)<<endl;
cout<<"Pc : "<<ChoiseOutPut(PcChoise)<<endl;
checkresult(UserChoise,PcChoise,Result);
cout<<"the Winner : "<<WinnerOutPut( whoIsTheWinner(Result,UserChoise,PcChoise,Winner));
GameOverInfo(Userwins,PcWins,DrowTimes,RoundTimes,Winner);
 }

char PlayAgainFunc()
{
    char YesOrNo='y';
    
     cout<<"Do You Want To Play Again?Y Or No"<<endl;
        cin>>YesOrNo;
    return YesOrNo;
}
void TimesOfRounds()
{
    
    int TimesOfRounds;
    int UserChoise=0,PcChoise=0,result=0,UserWins=0,PcWins=0,DrowTimes=0,RoundTimes=0, Winner=0;
    char PlayAgain='n';
        do
        {
 TimesOfRounds = ReadPositiveNumberInRange(0,11,"How many Rounds Do You Want To Play [1-10]");
        for(int i=1;i<=TimesOfRounds;i++)
        {
            cout<<"-------------Round "<<i<<"  began  -----------"<<endl;
            StonePaperScissorGame(UserChoise,PcChoise,result,UserWins,PcWins,DrowTimes,RoundTimes,Winner);
            cout<<endl;
        }
        GameOverMenu(UserWins,PcWins,DrowTimes,RoundTimes);
       PlayAgain =PlayAgainFunc();
        }while(PlayAgain == 'Y' || PlayAgain =='y');
       
      
}
int main() {
 srand((unsigned)time(NULL));
TimesOfRounds();
}