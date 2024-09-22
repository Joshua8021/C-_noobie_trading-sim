#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <unistd.h>
#include <windows.h>

using namespace std;
//Tax
float tax = 0;
float taxStore = 0;
float taxStore2 = 0;
float taxStore3 = 0;
float taxStore4 = 0;

//Taxes
void taxes(void);
void firstBracket(void);
void secondBracket(void);
void thirdBracket(void);
void fourthBracket(void);


// Banking
//Banking System
float debt = 0;
float bankMoney = 0;
float bankMoney2 = 0;
float interest = 5; 
float interest2 = 3; 
float loan1 = 0;
float loan2 = 0; //loan2 = 0 once the user has successfully traded.
float lastDeposit = 0;
float lastDeposit2 = 0;
float borrow2 = 0;
int year = 0;


//Remember Bank
int memBank = 0;
int memLoan = 0;
int memDp = -1;
int memDp2 = 0;
int memDebt = 0;
int loanTurn = 0;

//The Bank Function
void theBank(void);
void rules(void);

// User Debt Function
void userDebt(void);

// Withdraw Function
void withdraw(void);

// Deposit Function
void deposit(void);
void reports(void);

// Loan Function
void loan(void);
void repay(void);
void borrow(void);
void trust(void);
void trusted(void);
void checkDebt(void);

// Compounding Bank Money Function
void compoundBank(void);
// Random Function
float random(float x);
string input;
//Global
//Inventory
int potInv = 0, oilInv = 0, fishInv = 0, woolInv = 0, velvetInv = 0, toolsInv = 0, spiceInv = 0, ironInv = 0, flourInv = 0, dyeInv = 0, leatherInv = 0, furInv = 0, beerInv = 0, saltInv = 0, wineInv = 0;
int qty = 0;	//quantity
int inv = 0;
//User
float balance = 5000;
//Trade Goods Prices, in order: Sweden, Poland
//Escape-add;
float x;
float randomnum = random(x);
float potPrice[7] = {90, 157.5, 157.5, 99, 67.5, 99, 90};
float oilPrice[7] = {400, 300, 700, 700, 440, 440, 400};
float fishPrice[7] = {50, 55, 87.5, 55, 87.5, 55, 50};
float woolPrice[7] = {240, 180, 180, 264, 264, 264, 240};
float velvetPrice[7] = {950, 1662.5, 1662.5, 990, 712.5, 990, 950};
float toolsPrice[7] = {400, 300, 700, 440, 440, 400};
float spicePrice[7] = {800, 1400, 600, 880, 600, 880, 800};
float ironPrice[7] = {220, 365, 365, 365, 165, 242, 220};
float flourPrice[7] = {50, 37.5, 87.5, 55, 87.5, 55, 50};
float dyePrice[7] = {180, 198, 135, 198, 198, 198, 180};
float leatherPrice[7] = {180, 198, 315, 135, 135, 198, 180};
float furPrice[7] = {390, 429, 292.5, 429, 429, 429, 390};
float beerPrice[7] = {100, 75, 175, 175, 175, 110, 100};
float saltPrice[7] = {220, 165, 385, 165, 165, 242, 220};
float winePrice[7] = {200, 220, 150, 220, 220, 220, 200};

float price;
float priceArrays[100];
//Country Mem
string country = "None";	//Starting
string place[7] = { "Sweden", "Poland", "Russia", "Crimea", "Saudi Arabia", "Ukraine", "China"};
int land;	//index
//Country Inv (Default inv)
//surplus 200%;
//well-met 100%; 
//high 75%; med 50%; low 25%;
int potInvSwede = 150, potInvPol = 50, potInvRus = 100, potInvCri = 75, potInvSau= 150, potInvUkr= 75, potInvChi= 100; //well 100
int oilInvSwede = 25, oilInvPol = 75, oilInvRus = 45, oilInvCri= 25, oilInvSau= 38, oilInvUkr= 38, oilInvChi= 50; //well 50
int fishInvSwede = 150, 	fishInvPol = 113, 	fishInvRus = 75, 	fishInvCri= 113, 		fishInvSau = 75, 	fishInvUkr = 113, 	fishInvChi = 150; //well 75
int woolInvSwede = 75, 		woolInvPol = 56, 	woolInvRus = 113, 	woolInvCri= 56, 		woolInvSau = 56,	woolInvUkr = 56,	woolInvChi=75; //well 75 
int velvetInvSwede =25, 	velvetInvPol = 13, 	velvetInvRus = 13, 	velvetInvCri = 19, 		velvetInvSau=38, 	velvetInvUkr = 19,	velvetInvChi=25; //well 25
int toolsInvSwede = 50, 	toolsInvPol = 75, 	toolsInvRus = 38, 	toolsInvCri=38,			toolsInvSau=38,		toolsInvUkr = 38,	toolsInvChi=50; //well 50
int spiceInvSwede = 30, 	spiceInvPol = 15, 	spiceInvRus = 45, 	spiceInvCri= 23, 		spiceInvSau= 23, 	spiceInvUkr = 23, 	spiceInvChi=30; //well 30
int ironInvSwede = 100, 	ironInvPol = 50, 	ironInvRus = 50, 	ironInvCri= 50, 		ironInvSau=75, 		ironInvUkr = 75, 	ironInvChi = 100; //well 100
int flourInvSwede = 150, 	flourInvPol = 113, 	flourInvRus = 75, 	flourInvCri= 113, 		flourInvSau= 75, 	flourInvUkr = 113, 	flourInvChi = 150; //well 150
int dyeInvSwede = 75, 		dyeInvPol = 56, 	dyeInvRus= 113,		dyeInvCri = 56, 		dyeInvSau= 56, 		dyeInvUkr = 56, 	dyeInvChi = 75; //well 75
int leatherInvSwede = 75, 	leatherInvPol = 56, leatherInvRus = 38, leatherInvCri = 113,	leatherInvSau=56,	leatherInvUkr = 56,	leatherInvChi = 75; //well 75
int furInvSwede = 75, 		furInvPol = 56, 	furInvRus = 113,	furInvCri = 56,			furInvSau=56,		furInvUkr = 56,		furInvChi = 75; //well 75
int beerInvSwede =75,		beerInvPol = 113, 	beerInvRus = 56,	beerInvCri = 38,		beerInvSau=38,		beerInvUkr = 56,	beerInvChi = 75; //well 75
int saltInvSwede =75,		saltInvPol = 38, 	saltInvRus = 56,	saltInvCri = 113,		saltInvSau=113,		saltInvUkr = 56,	saltInvChi = 75; //well 75
int wineInvSwede =75,		wineInvPol = 56, 	wineInvRus = 56,	wineInvCri = 113,		wineInvSau=56,		wineInvUkr = 56,	wineInvChi = 75; //well 75


int inv_Country = 0; // For loop inv
//Goods
string tradeGoods[15] = { "Pottery ", "Oil ", "Fish ", "Wool Cloth ", "Velvet " , "Tools ", "Spices ", "Iron ", "Flour ", "Dyes ", "Leatherworks ", "Fur ", "Beer " , "Salt ", "Wine " };int goodNo;
int goodType;
//int remember strings
int mem = 0;	//inv
int mem2 = 0;	//notes
int mem3 = 0;	//buy/sell
//Turn Counter;
//event variables
int GOOJcard=0; // Get out of jail
int turn=1;
int investment=0;
int event35=0;
int Cauldron=0;
int checkers=0;
//End of Global
//Escape add
void random(void);
//What do I do first?
void loc(void);

//User's Inventory
void check(void);

//Trade
void trade(void);

//Buy function
void buy(void);

//traded
void traded(void);

//Quantity function
void quantity(void);

//lack function
void lack(void);

//Sell function
void sell(void);

//Goods function
void goods(void);

//Notes function
void notes(void);

//Balance function
void balance_balance(void);

//todo
void todo(void);
void todo2(void);

//Country Inventory
void countryInv(void);
void determineCountry(void);
//Turn-based Events
void turnCounter(void);
void eventsNumbers(void);
void events(int random);



main(){
	system("color 70");
	if(balance<0){
		if (bankMoney > 0){
			balance -= 3.50;
			balance += bankMoney;
			bankMoney = 0;
			cout << endl;
			cout << endl;
			cout << "Checking Bank Account . . . ";
			sleep(2);
			cout << endl;
			cout << "Withdrawing Bank Balance.";
			cout << endl;
			cout << "Withdrawal Fee: Eur 3.50";
			cout << endl;
			cout << endl;
			system("pause");
			if (balance <= 0){
				cout << endl;
				cout << endl;
				cout << "You are now bankrupt. Game Over."; 
				cout << endl;
				cout << "You lasted for "<< turn <<" turns."; 
				cout << endl;
				cout << endl;
				cout << endl;
				exit(0);
			}
		}
		else {
			cout << endl;
			cout << endl;
			cout << "You are now bankrupt. Game Over.";
			cout << endl;
			cout << "You lasted for "<<turn<<" turns."; 
			cout << endl;
			cout << endl;
			cout << endl;
			exit(0);
		}
	}

	if (turn<=60&&balance>0) loc();

	else if (balance>0){
		cout << setprecision(2) << fixed;
		cout<<"Your total money came to:" << balance + bankMoney;
	}

	cout << "\nThanks for playing this simulator.";

	exit(0);
}

//loc function
void loc(void){
	if (turn<60 && checkers==0)
	{
		cout<<"Turn: "<<turn<<endl;
		eventsNumbers();
	}
	else if (turn==60 && checkers==0)
	{
	cout<<"Turn: "<<turn<<" (LAST TURN!)"<<endl;
	eventsNumbers();
	}
	else if (checkers==0)
	{
	main();
	}
	if (balance<0)
	{
	main();}
	if (turn%4==0) taxes();

	country = "None";
	int x = 0;
	mem = 0;
	mem2 = 0;
	cout << endl;
	cout << endl;
	balance_balance();
	cout << "             =============================================================================";
	cout << endl;
	cout << setw(37);
	cout << "What do you want to do?";
	cout << endl;
	cout << setw(18);
	cout << "[1] " << setw(17) << "Trade";
	cout << endl;
	cout << setw(18);
	cout << "[2] " << setw(17) << "Check Inventory";
	cout << endl;
	cout << setw(18);
	cout << "[3] " << setw(17) << "Bank";
	cout << endl;
	cout << setw(18);
	cout << "[4] " << setw(17) << "Exit";
	cout << endl;
	cout << "             =============================================================================";
	cout << endl;
	do {
		cout << setw(27);
		cout << "Enter Input: ";
		cin >> input;
		stringstream(input) >> x;
		switch (x)
		{
			case 1:
				trade();
				break;
			case 2:
				checkers=1;
				check();
				break;
			case 3:
				theBank();
				break;
			case 4:
				abort();
				break;
			default:
				cout << setw(60);
				cout << "That's an invalid option. Please try again.";
				cout << endl;
		}
		cout << endl;
	} while (input != "1" || input != "2");
}

//check function
void check(void){
    cout << endl;
    cout << setw(33);
    cout << "You currently have:";
    cout << endl;
    cout << setw(20);
    cout << potInv << setw(15) << " - " << setw(17) << " Pottery";
    cout << endl;
    cout << setw(20);
    cout << oilInv << setw(15) << " - " << setw(17) << " Oil";
    cout << endl;
    cout << setw(20);
    cout << fishInv << setw(15) << " - " << setw(17) << " Fish";
    cout << endl;
    cout << setw(20);
    cout << woolInv << setw(15) << " - " << setw(17) << " Wool Cloth";
    cout << endl;
    cout << setw(20);
    cout << velvetInv << setw(15) << " - " << setw(17) << " Velvet";
    cout << endl; 
    cout << setw(20);
    cout << toolsInv << setw(15) << " - " << setw(17) << " Tools";
    cout << endl;
    cout << setw(20);
    cout << spiceInv << setw(15) << " - " << setw(17) << " Spice";
    cout << endl;
    cout << setw(20);
    cout << ironInv << setw(15) << " - " << setw(17) << " Iron";
    cout << endl;
    cout << setw(20);
    cout << flourInv << setw(15) << " - " << setw(17) << " Flour";
    cout << endl;
    cout << setw(20);
    cout << dyeInv << setw(15) << " - " << setw(17) << " Dye";
    cout << endl;
    cout << setw(20);
    cout << leatherInv << setw(15) << " - " << setw(17) << " Leatherworks";
    cout << endl;
    cout << setw(20);
    cout << furInv << setw(15) << " - " << setw(17) << " Fur";
    cout << endl;
    cout << setw(20);
    cout << beerInv << setw(15) << " - " << setw(17) << " Beer";
    cout << endl;
    cout << setw(20);
    cout << saltInv << setw(15) << " - " << setw(17) << " Salt";
    cout << endl;
    cout << setw(20);
    cout << wineInv << setw(15) << " - " << setw(17) << " Wine";
	cout << endl;
	cout << setw(38);
	cout << " . . . in your inventory.";
	cout << endl;
	cout << endl;
	system("pause");
	switch (mem){
		case 0:
			checkers=1;
			loc();
			break;
		case 1:
			trade();
			break;
		case 2:
			buy();
			break;
		case 3:
			sell();
			break;
		case 4:
			todo2();
			break;
	}
}

//trade function
void trade(void){
	mem = 1;
	string input;
	country = "None";
	mem2 = 1;
	int x;
	cout << endl;
	cout << "             =============================================================================";
	cout << endl;
	cout << setw(28);
	cout << "Country List: ";
	cout << endl;
	cout << "             =============================================================================";
	cout << endl;
	cout << setw(18);
	cout << "[1] " << setw(17) << "Sweden";
	cout << endl;
	cout << setw(18);
	cout << "[2] " << setw(17) << "Poland";
	cout << endl;
	cout << setw(18);
    cout << "[3] " << setw(17) << "Russia";
    cout << endl;
    cout << setw(18);
    cout << "[4] " << setw(17) << "Crimea";
    cout << endl;
    cout << setw(18);
    cout << "[5] " << setw(17) << "Saudi Arabia";
    cout << endl;
    cout << setw(18);
    cout << "[6] " << setw(17) << "Ukraine";
    cout << endl;
    cout << setw(18);
    cout << "[7] " << setw(17) << "China";
    cout << endl;
    cout << setw(18);
    cout << "[8] " << setw(17) << "Check inventory";
    cout << endl;
    cout << setw(18);
    cout << "[9] " << setw(17) << "Check notes";
    cout << endl;
    cout << setw(18);
    cout << "[10] " << setw(17) << "Return";
    cout << endl;
    cout << "             =============================================================================";
    cout << endl;
	do{
		cout << setw(27);
		cout << "Enter Input: ";
		cin >> input;
		stringstream(input) >> x;
		switch (x){
case 1:
                land = 0; // Sweden
                todo();
                break;
            case 2:
                land = 1; // Poland
                todo();
                break;
            case 3:
            	land = 2; // Russia
            	todo();
            	break;
            case 4:
            	land = 3; // Crimea
            	todo();
            	break;
            case 5:
            	land = 4; // Saudi
            	todo();
            	break;
            case 6:
            	land = 5; // Ukraine
            	todo();
            	break;
            case 7:
            	land = 6; // China
            	todo();
            	break;
            case 8:
            	checkers=1;
                check();
                break;
            case 9:
            	checkers=1;
                notes();
                break;
            case 10:
            	checkers=1;
                loc();
                break;

			default:
				cout << setw(60);
				cout << "That's an invalid option. Please try again.";
				cout << endl;
				break;
		} 
}while (input != "1" || input != "2" || input != "3" || input != "4" || input != "5" || input != "6"|| input != "7" || input !="8" || input != "9" || input != "10"); 
		cout << endl;
}

//goods function
void goods(void){
	cout << setprecision(2) << fixed;
	cout << endl;
	cout << setw(25);
	cout << "Trade Goods";
	cout << endl;
	cout << "             =============================================================================";
	cout << endl;
	cout << endl;
	random();
	cout << setw(18) << "[16] " << setw(17) << "Check Inventory";
	cout << endl;
	cout << setw(18) << "[17] " << setw(17) << "Check Notes";
	cout << endl;
	cout << setw(18) << "[18] " << setw(17) << "Return";
	cout << endl;
	cout << endl;
	cout << "             =============================================================================";
	cout << endl;
	cout << endl;
}

//buy function
void buy(void){
	string input;
	int x;
	mem = 2;
	mem2 = 2;
	mem3 = 0;
	if (land == 0){
		cout << endl;
		cout << setw(48);
		cout << "You are trading with Sweden . . . ";
		cout << endl;
	}
	else if (land == 1){
		cout << endl;
		cout << setw(48);
		cout << "You are trading with Poland . . . ";
		cout << endl;
	}
      else if (land == 2){
        cout << endl;
        cout << setw(48);
        cout << "You are trading with Russia . . . ";
        cout << endl;
    }
   else if (land == 3){
        cout << endl;
        cout << setw(48);
        cout << "You are trading with Crimea . . . ";
        cout << endl;
    }
    else if (land == 4){
        cout << endl;
        cout << setw(54);
        cout << "You are trading with Saudi Arabia . . . ";
        cout << endl;
    }
    else if (land == 5){
        cout << endl;
        cout << setw(49);
        cout << "You are trading with Ukraine . . . ";
        cout << endl;
    }
    else if (land == 6){
        cout << endl;
        cout << setw(47);
        cout << "You are trading with China . . . ";
        cout << endl;
    }

	country = "None";
	balance_balance();
	goods();
	cout << setw(39);
	cout << "What do you want to buy? ";
	cout << endl;
	do{
		cout << setw(27);
		cout << "Enter Input: ";
		cin >> input;
		stringstream(input) >> x;
		switch (x){
        	case 1:
            	goodType = 0;
            	determineCountry();
            	inv = potInv;
            	price = priceArrays[goodType];
            	quantity();
            	if (balance < qty *price){
                	lack();
                	break;
            	}
            	else if (balance >= qty *price){
                	traded();
                	break;
            	}
 
	        case 2:
	            goodType = 1;
	            determineCountry();
	            inv = oilInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 3:
	            goodType = 2;
	            determineCountry();
	            inv = fishInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 4:
	            goodType = 3;
	            determineCountry();
	            inv = woolInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 5:
	            goodType = 4;
	            determineCountry();
	            inv = velvetInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 6:
	            goodType = 5;
	            determineCountry();
	            inv = toolsInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 7:
	            goodType = 6;
	            determineCountry();
	            inv = spiceInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
			//potInv = 0, oilInv = 0; fishInv = 0; woolInv=0; velvetInv=0; toolsInv=0; spiceInv=0; ironInv=0; flourInv=0; dyeInv=0; leatherInv=0; furInv=0; beerInv=0, saltInv=0; wineInv=0;
	        case 8:
	            goodType = 7;
	            determineCountry();
	            inv = ironInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 9:
	            goodType = 8;
	            determineCountry();
	            inv = flourInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 10:
	            goodType = 9;
	            determineCountry();
	            inv = dyeInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 11:
	            goodType = 10;
	            determineCountry();
	            inv = leatherInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 12:
	            goodType = 11;
	            determineCountry();
	            inv = furInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 13:
	            goodType = 12;
	            determineCountry();
	            inv = beerInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 14:
	            goodType = 13;
	            determineCountry();
	            inv = saltInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 15:
	            goodType = 14;
	            determineCountry();
	            inv = wineInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (balance < qty *price){
	                lack();
	                break;
	            }
	            else if (balance >= qty *price){
	                traded();
	                break;
	            }
	        case 16:
	            check();
	            break;
	        case 17:
	            notes();
	            break;
	        case 18:
	            trade();
	            break;
	
			default:
				cout << setw(60);
				cout << "That's an invalid option. Please try again.";
				cout << endl;
		}
	} while (input != "1" || input != "2"|| input != "3"|| input != "4"|| input != "5"|| input != "6"|| input != "7"|| input != "8"|| input != "9"|| input != "10"|| input != "11"|| input != "12"|| input != "13"|| input != "14"|| input != "15"|| input != "16"|| input != "17"|| input != "18");

}

//traded function
void traded(void){
	cout << setprecision(2) << fixed;
    if (mem3 == 0){ //buy
        balance -= qty * price;
        balance_balance();
        cout << endl;
        cout << setw(40);
        cout << "You bought " << tradeGoods[goodType] << "for Eur " << qty * price << ".";
        cout << endl;
        if (goodType==0) potInv+=qty;
        else if (goodType==1) oilInv+=qty;
        else if (goodType==2) fishInv+=qty;
        else if (goodType==3) woolInv+=qty;
        else if (goodType==4) velvetInv+=qty;
        else if (goodType==5) toolsInv+=qty;
        else if (goodType==6) spiceInv+=qty;
        else if (goodType==7) ironInv+=qty;
        else if (goodType==8) flourInv+=qty;
        else if (goodType==9) dyeInv+=qty;
        else if (goodType==10) leatherInv+=qty;
        else if (goodType==11) furInv+=qty;
        else if (goodType==12) beerInv+=qty;
        else if (goodType==13) saltInv+=qty;
        else if (goodType==14) wineInv+=qty;
    }
    else if (mem3 == 1){ //sell
        balance += qty * price;
        balance_balance();
        cout << endl;
        cout << setw(40);
        cout << "You sold " << tradeGoods[goodType] << " for Eur " << qty * price << ".";
        cout << endl;
        if (goodType==0) potInv-=qty;
        else if (goodType==1) oilInv-=qty;
        else if (goodType==2) fishInv-=qty;
        else if (goodType==3) woolInv-=qty;
        else if (goodType==4) velvetInv-=qty;
        else if (goodType==5) toolsInv-=qty;
        else if (goodType==6) spiceInv-=qty;
        else if (goodType==7) ironInv-=qty;
        else if (goodType==8) flourInv-=qty;
        else if (goodType==9) dyeInv-=qty;
        else if (goodType==10) leatherInv-=qty;
        else if (goodType==11) furInv-=qty;
        else if (goodType==12) beerInv-=qty;
        else if (goodType==13) saltInv-=qty;
        else if (goodType==14) wineInv-=qty;
        cout << endl;

	}
	turn++;
	bankMoney2 = 0;
	compoundBank();
	userDebt();
	memDp2 = 0;
	checkers=0;
	if(turn%6==0)
	{
	potInvSwede += 10;
	potInvPol += 10;
	potInvRus += 10;
	potInvCri += 10;
	potInvSau += 10;
	potInvUkr += 10;
	potInvChi += 10;
	oilInvSwede += 5;
	oilInvPol += 5;
	oilInvRus += 5;
	oilInvCri += 5;
	oilInvSau += 5;
	oilInvUkr += 5;
	oilInvChi += 5;
	fishInvSwede += 15;
	fishInvPol += 15;
	fishInvRus += 15;
	fishInvCri += 15;
	fishInvSau += 15;
	fishInvUkr += 15;
	fishInvChi += 15;
	woolInvSwede += 8;
	woolInvPol += 8;
	woolInvRus += 8;
	woolInvCri += 8;
	woolInvSau += 8;
	woolInvUkr += 8;
	woolInvChi += 8;
	velvetInvSwede += 3;
	velvetInvPol += 3;
	velvetInvRus += 3;
	velvetInvCri += 3;
	velvetInvSau += 3;
	velvetInvUkr += 3;
	velvetInvChi += 3;
	toolsInvSwede += 8;
	toolsInvPol += 8;
	toolsInvRus += 8;
	toolsInvCri += 8;
	toolsInvSau += 8;
	toolsInvUkr += 8;
	toolsInvChi += 8;
	spiceInvSwede += 5;
	spiceInvPol += 5;
	spiceInvRus += 5;
	spiceInvCri += 5;
	spiceInvSau += 5;
	spiceInvUkr += 5;
	spiceInvChi += 5;
	ironInvSwede += 8;
	ironInvPol += 8;
	ironInvRus += 8;
	ironInvCri += 8;
	ironInvSau += 8;
	ironInvUkr += 8;
	ironInvChi += 8;
	flourInvSwede += 15;
	flourInvPol += 15;
	flourInvRus += 15;
	flourInvCri += 15;
	flourInvSau += 15;
	flourInvUkr += 15;
	flourInvChi += 15;
	dyeInvSwede += 8;
	dyeInvPol += 8;
	dyeInvRus += 8;
	dyeInvCri += 8;
	dyeInvSau += 8;
	dyeInvUkr += 8;
	dyeInvChi += 8;
	leatherInvSwede += 8;
	leatherInvPol += 8;
	leatherInvRus += 8;
	leatherInvCri += 8;
	leatherInvSau += 8;
	leatherInvUkr += 8;
	leatherInvChi += 8;
	furInvSwede += 8;
	furInvPol += 8;
	furInvRus += 8;
	furInvCri += 8;
	furInvSau += 8;
	furInvUkr += 8;
	furInvChi += 8;
	beerInvSwede += 8;
	beerInvPol += 8;
	beerInvRus += 8;
	beerInvCri += 8;
	beerInvSau += 8;
	beerInvUkr += 8;
	beerInvChi += 8;
	saltInvSwede +=8;
	saltInvPol += 8;
	saltInvRus += 8;
	saltInvCri += 8;
	saltInvSau += 8;
	saltInvUkr += 8;
	saltInvChi += 8;
	wineInvSwede += 8;
	wineInvPol += 8;
	wineInvRus += 8;
	wineInvCri += 8;
	wineInvSau += 8;
	wineInvUkr += 8;
	wineInvChi += 8;
	}

	system("pause");
	loc();
}

//quantity function
void quantity(void){
	mem = 4;
	if (mem3 == 0){
		//Ask
		cout << setw(30);
		cout << "How many " << tradeGoods[goodType] << "do you want to buy? ";
		cin >> qty;
		if (qty < 0){
			quantity();
		}
		else if (qty == 0){
			cout << endl;
			cout << "You bought nothing . . . ";
			cout << endl;
			system("pause");
			buy();
		}
		countryInv();
	}
	else if (mem3 == 1){
		cout << setw(30);
		cout << "How many " << tradeGoods[goodType] << "do you want to sell? ";
		cin >> qty;
		if (qty < 0){
			quantity();
		}
		else if (qty == 0){
			cout << endl;
			cout << "You sold nothing . . . ";
			cout << endl;
			system("pause");
			sell();
		}
		countryInv();
	}
	else quantity();
}

//lacking function
void lack(void){
	if (mem3 == 0){
		cout << endl;
		cout << endl;
		cout << "You have insufficient balance ... ";
		cout << endl;
		cout << endl;
		system("pause");
		buy();
	}
	else if (mem3 == 1){
		cout << endl;
		cout << endl;
		cout << "You don't have " << qty << " of " << tradeGoods[goodType];
		cout << endl;
		cout << endl;
		system("pause");
		sell();
	}
}

//sell function
void sell(void){
	string input;
	int x;
	mem = 3;
	mem2 = 3;
	mem3 = 1;
	if (land == 0){
		cout << endl;
		cout << setw(48);
		cout << "You are trading with Sweden . . . ";
		cout << endl;
	}
	else if (land == 1){
		cout << endl;
		cout << setw(48);
		cout << "You are trading with Poland . . . ";
		cout << endl;
	}
      else if (land == 2){
        cout << endl;
        cout << setw(48);
        cout << "You are trading with Russia . . . ";
        cout << endl;
    }
   else if (land == 3){
        cout << endl;
        cout << setw(48);
        cout << "You are trading with Crimea . . . ";
        cout << endl;
    }
    else if (land == 4){
        cout << endl;
        cout << setw(54);
        cout << "You are trading with Saudi Arabia . . . ";
        cout << endl;
    }
    else if (land == 5){
        cout << endl;
        cout << setw(49);
        cout << "You are trading with Ukraine . . . ";
        cout << endl;
    }
    else if (land == 6){
        cout << endl;
        cout << setw(47);
        cout << "You are trading with China . . . ";
        cout << endl;
    }
	country = "None";
	balance_balance();
	goods();
	cout << setw(40);
	cout << "What do you want to sell? ";
	cout << endl;
	do {
		cout << setw(27);
		cout << "Enter Input: ";
		cin >> input;
		stringstream(input) >> x;
		switch (x){
	       case 1:
	            goodType = 0;
	            determineCountry();
	            inv = potInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 2:
	            goodType = 1;
	            determineCountry();
	            inv = oilInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 3:
	            goodType = 2;
	            determineCountry();
	            inv = fishInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 4:
	            goodType = 3;
	            determineCountry();
	            inv = woolInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 5:
	            goodType = 4;
	            determineCountry();
	            inv = velvetInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 6:
	            goodType = 5;
	            determineCountry();
	            inv = toolsInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 7:
	            goodType = 6;
	            determineCountry();
	            inv = spiceInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 8:
	            goodType = 7;
	            determineCountry();
	            inv = ironInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 9:
	            goodType = 8;
	            determineCountry();
	            inv = flourInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 10:
	            goodType = 9;
	            determineCountry();
	            inv = dyeInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 11:
	            goodType = 10;
	            determineCountry();
	            inv = leatherInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 12:
	            goodType = 11;
	            determineCountry();
	            inv = furInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 13:
	            goodType = 12;
	            determineCountry();
	            inv = beerInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 14:
	            goodType = 13;
	            determineCountry();
	            inv = saltInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 15:
	            goodType = 14;
	            determineCountry();
	            inv = wineInv;
	            price = priceArrays[goodType];
	            quantity();
	            if (inv < qty){
	                lack();
	                break;
	            }
	            else if (inv >= qty){
	                traded();
	                break;
	            }
	        case 16:
	            check();
	            break;
	        case 17:
	            notes();
	            break;
	        case 18:
	            trade();
	            break;
	        default:
	        	cout << setw(60);
	            cout << "That's an invalid option. Please try again.";
				cout << endl;
    	} 
	}while (input != "1" || input != "2"|| input != "3"|| input != "4"|| input != "5"|| input != "6"|| input != "7");
}
//notes function
void notes(void){
    if (country == "Sweden"){
        cout << endl;
        cout << "Sweden's exports and imports are well-met . . . ";
        cout << endl;
        //For checking . . . 
        cout << "Sweden's Inventory . . . ";
        cout << endl;
        cout << "Pottery: " << potInvSwede;
        cout << endl;
        cout << "Oil: " << oilInvSwede;
        cout << endl;
        cout << "Fish: " << fishInvSwede;
        cout << endl;
        cout << "Wool Cloth:" << woolInvSwede;
        cout << endl;
        cout << "Velvet: " << velvetInvSwede;
        cout << endl;
        cout << "Tools: " << toolsInvSwede;
        cout << endl;
        cout << "Spice: " << spiceInvSwede;
        cout << endl;
        cout << "Iron: " << ironInvSwede;
        cout << endl;
        cout << "Flour: " << flourInvSwede;
        cout << endl;
        cout << "Dyes: " << dyeInvSwede;
        cout << endl;
        cout << "Leatherworks: " << leatherInvSwede;
        cout << endl;
        cout << "Fur: " << furInvSwede;
        cout << endl;
        cout << "Beer: " << beerInvSwede;
        cout << endl;
        cout << "Salt: " << saltInvSwede;
        cout << endl;
        cout << "Wine: " << wineInvSwede;
        cout << endl;
    }
    else if (country == "Poland"){
        cout << endl;
        cout << "Poland's Exports and Imports . . . ";
        cout << endl;
        cout << "Exports: Oil, Beer, Flour, Tools";
        cout << endl;
        cout << "Imports: Velvet, Iron, Spice, Pottery";
        cout << endl;
        // Checking . . . 
        cout << "Poland's Inventory . . . ";
        cout << endl;
        cout << "Pottery: " << potInvPol;
        cout << endl;
        cout << "Oil: " << oilInvPol;
        cout << endl;
        cout << "Fish: " << fishInvPol;
        cout << endl;
        cout << "Wool Cloth:" << woolInvPol;
        cout << endl;
        cout << "Velvet: " << velvetInvPol;
        cout << endl;
        cout << "Tools: " << toolsInvPol;
        cout << endl;
        cout << "Spice: " << spiceInvPol;
        cout << endl;
        cout << "Iron: " << ironInvPol;
        cout << endl;
        cout << "Flour: " << flourInvPol;
        cout << endl;
        cout << "Dyes: " << dyeInvPol;
        cout << endl;
        cout << "Leatherworks: " << leatherInvPol;
        cout << endl;
        cout << "Fur: " << furInvPol;
        cout << endl;
        cout << "Beer: " << beerInvPol;
        cout << endl;
        cout << "Salt: " << saltInvPol;
        cout << endl;
        cout << "Wine: " << wineInvPol;
        cout << endl;
    }
    else if (country == "Russia"){
        cout << endl;
        cout << "Russia's Exports and Imports . . . ";
        cout << endl;
        cout << "Exports: Furs, Dyes, Spice, Wool";
        cout << endl;
        cout << "Imports: Oil, Fish, Salt, Velvet, Flour, Pottery, Beer, Tools, Iron, Leatherworks";
        cout << endl;
        // Checking . . . 
        cout << "Russia's Inventory . . . ";
        cout << endl;
        cout << "Pottery: " << potInvRus;
        cout << endl;
        cout << "Oil: " << oilInvRus;
        cout << endl;
        cout << "Fish: " << fishInvRus;
        cout << endl;
        cout << "Wool Cloth:" << woolInvRus;
        cout << endl;
        cout << "Velvet: " << velvetInvRus;
        cout << endl;
        cout << "Tools: " << toolsInvRus;
        cout << endl;
        cout << "Spice: " << spiceInvRus;
        cout << endl;
        cout << "Iron: " << ironInvRus;
        cout << endl;
        cout << "Flour: " << flourInvRus;
        cout << endl;
        cout << "Dyes: " << dyeInvRus;
        cout << endl;
        cout << "Leatherworks: " << leatherInvRus;
        cout << endl;
        cout << "Fur: " << furInvRus;
        cout << endl;
        cout << "Beer: " << beerInvRus;
        cout << endl;
        cout << "Salt: " << saltInvRus;
        cout << endl;
        cout << "Wine: " << wineInvRus;
        cout << endl;
    }
    else if (country == "Crimea"){
        cout << endl;
        cout << "Crimea's Exports and Imports . . . ";
        cout << endl;
        cout << "Exports: Leatherworks, Salt, Wine";
        cout << endl;
        cout << "Imports: Iron, Oil, Beer";
        cout << endl;
        // Checking . . . 
        cout << "Crimea's Inventory . . . ";
        cout << endl;
        cout << "Pottery: " << potInvCri;
        cout << endl;
        cout << "Oil: " << oilInvCri;
        cout << endl;
        cout << "Fish: " << fishInvCri;
        cout << endl;
        cout << "Wool Cloth:" << woolInvCri;
        cout << endl;
        cout << "Velvet: " << velvetInvCri;
        cout << endl;
        cout << "Tools: " << toolsInvCri;
        cout << endl;
        cout << "Spice: " << spiceInvCri;
        cout << endl;
        cout << "Iron: " << ironInvCri;
        cout << endl;
        cout << "Flour: " << flourInvCri;
        cout << endl;
        cout << "Dyes: " << dyeInvCri;
        cout << endl;
        cout << "Leatherworks: " << leatherInvCri;
        cout << endl;
        cout << "Fur: " << furInvCri;
        cout << endl;
        cout << "Beer: " << beerInvCri;
        cout << endl;
        cout << "Salt: " << saltInvCri;
        cout << endl;
        cout << "Wine: " << wineInvCri;
        cout << endl;
    }
    else if (country == "Saudi"){
        cout << endl;
        cout << "Saudi Arabia's Exports and Imports . . . ";
        cout << endl;
        cout << "Exports: Salt, Pottery, Velvet";
        cout << endl;
        cout << "Imports: Flour, Beer, Fish";
        cout << endl;
        // Checking . . . 
        cout << "Pottery: " << potInvSau;
        cout << endl;
        cout << "Oil: " << oilInvSau;
        cout << endl;
        cout << "Fish: " << fishInvSau;
        cout << endl;
        cout << "Wool Cloth:" << woolInvSau;
        cout << endl;
        cout << "Velvet: " << velvetInvSau;
        cout << endl;
        cout << "Tools: " << toolsInvSau;
        cout << endl;
        cout << "Spice: " << spiceInvSau;
        cout << endl;
        cout << "Iron: " << ironInvSau;
        cout << endl;
        cout << "Flour: " << flourInvSau;
        cout << endl;
        cout << "Dyes: " << dyeInvSau;
        cout << endl;
        cout << "Leatherworks: " << leatherInvSau;
        cout << endl;
        cout << "Fur: " << furInvSau;
        cout << endl;
        cout << "Beer: " << beerInvSau;
        cout << endl;
        cout << "Salt: " << saltInvSau;
        cout << endl;
        cout << "Wine: " << wineInvSau;
        cout << endl;
    }
    else if (country == "Ukraine"){
        cout << endl;
        cout << "Ukraine's exports and imports are slightly well-met . . . ";
        cout << endl;
        //For checking . . . 
        cout << "Ukraine's Inventory . . . ";
        cout << endl;
        cout << "Pottery: " << potInvUkr;
        cout << endl;
        cout << "Oil: " << oilInvUkr;
        cout << endl;
        cout << "Fish: " << fishInvUkr;
        cout << endl;
        cout << "Wool Cloth:" << woolInvUkr;
        cout << endl;
        cout << "Velvet: " << velvetInvUkr;
        cout << endl;
        cout << "Tools: " << toolsInvUkr;
        cout << endl;
        cout << "Spice: " << spiceInvUkr;
        cout << endl;
        cout << "Iron: " << ironInvUkr;
        cout << endl;
        cout << "Flour: " << flourInvUkr;
        cout << endl;
        cout << "Dyes: " << dyeInvUkr;
        cout << endl;
        cout << "Leatherworks: " << leatherInvUkr;
        cout << endl;
        cout << "Fur: " << furInvUkr;
        cout << endl;
        cout << "Beer: " << beerInvUkr;
        cout << endl;
        cout << "Salt: " << saltInvUkr;
        cout << endl;
        cout << "Wine: " << wineInvUkr;
        cout << endl;
    }
    else if (country == "China"){
        cout << endl;
        cout << "China's exports and imports are well-met . . . ";
        cout << endl;
        //For checking . . . 
        cout << "China's Inventory . . . ";
        cout << endl;
        cout << "Pottery: " << potInvChi;
        cout << endl;
        cout << "Oil: " << oilInvChi;
        cout << endl;
        cout << "Fish: " << fishInvChi;
        cout << endl;
        cout << "Wool Cloth:" << woolInvChi;
        cout << endl;
        cout << "Velvet: " << velvetInvChi;
        cout << endl;
        cout << "Tools: " << toolsInvChi;
        cout << endl;
        cout << "Spice: " << spiceInvChi;
        cout << endl;
        cout << "Iron: " << ironInvChi;
        cout << endl;
        cout << "Flour: " << flourInvChi;
        cout << endl;
        cout << "Dyes: " << dyeInvChi;
        cout << endl;
        cout << "Leatherworks: " << leatherInvChi;
        cout << endl;
        cout << "Fur: " << furInvChi;
        cout << endl;
        cout << "Beer: " << beerInvChi;
        cout << endl;
        cout << "Salt: " << saltInvChi;
        cout << endl;
        cout << "Wine: " << wineInvChi;
        cout << endl;
    }

	
	else if (country == "None"){
		cout << "Input country notes: ";
		cin >> country;
		notes();
	}
	else{
		cout << "Input country notes: ";
				cin >> country;
				notes();
	}
	system("pause");
	if (mem2 == 1) trade();
	else if (mem2 == 2) buy();
	else if (mem2 == 3) sell();
	else if (mem2 == 4) quantity();
	else if (mem2 == 5) todo2();
}

//balance function
void balance_balance(void){
	cout << endl;
	cout << setw(27);
	cout << setprecision(2) << fixed;
	cout << "Balance: Eur " << balance;
	cout << endl;
}

//todo function
void todo(void){
	if (land == 0){
		cout << endl;
		cout << "             =============================================================================";
		cout << endl;
		cout << setw(52);
		cout << "You are now trading with Sweden . . . ";
		cout << endl;
		cout << "             =============================================================================";
		cout << endl;
		todo2();
	}
	else if (land == 1){
		cout << endl;
		cout << "             =============================================================================";
		cout << endl;
		cout << setw(52);
		cout << "You are now trading with Poland . . . ";
		cout << endl;
		cout << "             =============================================================================";
		cout << endl;
		todo2();
	}
      else if (land == 2){
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        cout << setw(52);
        cout << "You are now trading with Russia . . . ";
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        todo2();
    }
    else if (land == 3){
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        cout << setw(52);
        cout << "You are now trading with Crimea . . . ";
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        todo2();
    }
    else if (land == 4){
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        cout << setw(58);
        cout << "You are now trading with Saudi Arabia . . . ";
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        todo2();
    }
    else if (land == 5){
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        cout << setw(53);
        cout << "You are now trading with Ukraine . . . ";
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        todo2();
    }
    else if (land == 6){
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        cout << setw(51);
        cout << "You are now trading with China . . . ";
        cout << endl;
        cout << "             =============================================================================";
        cout << endl;
        todo2();
    }

}

//todo2 function
void todo2(void){
	int x;
	country = "None";
	mem = 4;
	mem2 = 5;
	cout << endl;
	cout << setw(18);
	cout << "[1] " << setw(17) << "Buy";
	cout << endl;
	cout << setw(18);
	cout << "[2] " << setw(17) << "Sell";
	cout << endl;
	cout << setw(18);
	cout << "[3] " << setw(17) << "Check inventory";
	cout << endl;
	cout << setw(18);
	cout << "[4] " << setw(17) << "Check notes";
	cout << endl;
	cout << setw(18);
	cout << "[5] " << setw(17)  << "Return";
	cout << endl;
	string input;
	do {
		cout << setw(27);
		cout << "Enter Input: ";
		cin >> input;
		stringstream(input) >> x;
		switch (x){
			case 1:
				buy();
				break;
			case 2:
				sell();
				break;
			case 3:
				check();
				break;
			case 4:
				notes();
				break;
			case 5:
				trade();
				break;
			default:
				cout << setw(60);
				cout << "That's an invalid option. Please try again.";
				cout << endl;
		}
	} while (input != "1" || input != "2"|| input != "3"|| input != "4"|| input != "5"|| input != "6"|| input != "7"|| input != "8"|| input != "9"|| input != "10"|| input != "11"|| input != "12"|| input != "13"|| input != "14"|| input != "15"|| input != "16"|| input != "17"|| input != "18"|| input != "19");


}
//country inventory
void countryInv(void){
	if (land==0){
		//Buy
		//Buying pot
		if (goodType==0 && mem3==0){
			if (qty>potInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " pottery.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else potInvSwede -= qty;
		}
		//Buying oil
		else if (goodType==1 && mem3==0){
			if (qty>oilInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " oil.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else oilInvSwede -= qty;
		}
		else if (goodType==2 && mem3==0){
			if (qty>fishInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " fish.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else fishInvSwede -= qty;
		}
		else if (goodType==3 && mem3==0){
			if (qty>woolInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " wool cloth.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else woolInvSwede -= qty;
		}
		else if (goodType==4 && mem3==0){
			if (qty>velvetInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " velvet.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else velvetInvSwede -= qty;
		}
		else if (goodType==5 && mem3==0){
			if (qty>toolsInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " tools.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else toolsInvSwede -= qty;
		}
		else if (goodType==6 && mem3==0){
			if (qty>spiceInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " spice.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else spiceInvSwede -= qty;
		}
		else if (goodType==7 && mem3==0){
			if (qty>ironInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " iron.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else ironInvSwede -= qty;
		}
		else if (goodType==8 && mem3==0){
			if (qty>flourInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " flour.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else flourInvSwede -= qty;
		}
		else if (goodType==9 && mem3==0){
			if (qty>dyeInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " dyes.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else dyeInvSwede -= qty;
		}
		else if (goodType==10 && mem3==0){
			if (qty>leatherInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " leatherworks.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else leatherInvSwede -= qty;
		}
		else if (goodType==11 && mem3==0){
			if (qty>furInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " fur.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else furInvSwede -= qty;
		}
		else if (goodType==12 && mem3==0){
			if (qty>beerInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " beer.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else beerInvSwede -= qty;
		}
		else if (goodType==13 && mem3==0){
			if (qty>saltInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " salt.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else saltInvSwede -= qty;
		}
		else if (goodType==14 && mem3==0){
			if (qty>wineInvSwede){
				cout << setw(62);
				cout << "Sweden does not have " << qty << " wine.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else wineInvSwede -= qty;
		}
		
		//Sell
		//Selling pot
		if (goodType==0 && mem3==1){
			potInvSwede += qty;
		}
		//Selling oil
		else if (goodType==1 && mem3==1){
			oilInvSwede += qty;
		}
		else if (goodType==2 && mem3==1){
			fishInvSwede += qty;
		}
		else if (goodType==3 && mem3==1){
			woolInvSwede += qty;
		}
		else if (goodType==4 && mem3==1){
			velvetInvSwede += qty;
		}
		else if (goodType==5 && mem3==1){
			toolsInvSwede += qty;
		}
		else if (goodType==6 && mem3==1){
			spiceInvSwede += qty;
		}
		else if (goodType==7 && mem3==1){
			ironInvSwede += qty;
		}
		else if (goodType==8 && mem3==1){
			flourInvSwede += qty;
		}
		else if (goodType==9 && mem3==1){
			dyeInvSwede += qty;
		}
		else if (goodType==10 && mem3==1){
			leatherInvSwede += qty;
		}
		else if (goodType==11 && mem3==1){
			furInvSwede += qty;
		}
		else if (goodType==12 && mem3==1){
			beerInvSwede += qty;
		}
		else if (goodType==13 && mem3==1){
			saltInvSwede += qty;
		}
		else if (goodType==14 && mem3==1){
			wineInvSwede += qty;
		}
	}
	else if (land==1){
		//Buy
		if (goodType==0 && mem3==0){
			if (qty>potInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " pottery.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else potInvPol -= qty;
		}
		else if (goodType==1 && mem3==0){
			if (qty>oilInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " oil.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else oilInvPol -= qty;
		}
		else if (goodType==2 && mem3==0){
			if (qty>fishInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " fish.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else fishInvPol -= qty;
		}
		else if (goodType==3 && mem3==0){
			if (qty>woolInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " wool cloth.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else woolInvPol -= qty;
		}
		else if (goodType==4 && mem3==0){
			if (qty>velvetInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " velvet.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else oilInvPol -= qty;
		}
		else if (goodType==5 && mem3==0){
			if (qty>toolsInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " tools.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else toolsInvPol -= qty;
		}
		else if (goodType==6 && mem3==0){
			if (qty>spiceInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " spice.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else spiceInvPol -= qty;
		}
		else if (goodType==7 && mem3==0){
			if (qty>ironInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " iron.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else ironInvPol -= qty;
		}
		else if (goodType==8 && mem3==0){
			if (qty>flourInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " flour.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else flourInvPol -= qty;
		}
		else if (goodType==9 && mem3==0){
			if (qty>dyeInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " dyes.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else dyeInvPol -= qty;
		}
		else if (goodType==10 && mem3==0){
			if (qty>leatherInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " leatherworks.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else leatherInvPol -= qty;
		}
		else if (goodType==11 && mem3==0){
			if (qty>furInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " fur.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else furInvPol -= qty;
		}
		else if (goodType==12 && mem3==0){
			if (qty>beerInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " beer.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else beerInvPol -= qty;
		}
		else if (goodType==13 && mem3==0){
			if (qty>saltInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " salt.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else saltInvPol -= qty;
		}
		else if (goodType==14 && mem3==0){
			if (qty>wineInvPol){
				cout << setw(62);
				cout << "Poland does not have " << qty << " wine.";
				cout << endl;
                cout << endl;
				quantity();
			}
			else wineInvPol -= qty;
		}
		
		//Sell
		else if (goodType==0 && mem3==1){
			potInvPol += qty;
		}
		else if (goodType== 1 && mem3==1){
			oilInvPol += qty;
		}
		else if (goodType== 2 && mem3==1){
			fishInvPol += qty;
		}
		else if (goodType== 3 && mem3==1){
			woolInvPol += qty;
		}
		else if (goodType== 4 && mem3==1){
			velvetInvPol += qty;
		}
		else if (goodType== 5 && mem3==1){
			toolsInvPol += qty;
		}
		else if (goodType== 6 && mem3==1){
			spiceInvPol += qty;
		}
		else if (goodType== 7 && mem3==1){
			ironInvPol += qty;
		}
		else if (goodType== 8 && mem3==1){
			flourInvPol += qty;
		}
		else if (goodType== 9 && mem3==1){
			dyeInvPol += qty;
		}
		else if (goodType== 10 && mem3==1){
			leatherInvPol += qty;
		}
		else if (goodType== 11 && mem3==1){
			furInvPol += qty;
		}
		else if (goodType== 12 && mem3==1){
			beerInvPol += qty;
		}
		else if (goodType== 13 && mem3==1){
			saltInvPol += qty;
		}
		else if (goodType== 14 && mem3==1){
			wineInvPol += qty;
		}
	}
    else if (land==2){
        //Buy
        if (goodType==0 && mem3==0){
            if (qty>potInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " pottery.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else potInvRus -= qty;
        }
        else if (goodType==1 && mem3==0){
            if (qty>oilInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " oil.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else oilInvRus -= qty;
        }
        else if (goodType==2 && mem3==0){
            if (qty>fishInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " fish.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else fishInvRus -= qty;
        }
        else if (goodType==3 && mem3==0){
            if (qty>woolInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " wool cloth.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else woolInvRus -= qty;
        }
        else if (goodType==4 && mem3==0){
            if (qty>velvetInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " velvet.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else velvetInvRus -= qty;
        }
        else if (goodType==5 && mem3==0){
            if (qty>toolsInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " tools.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else toolsInvRus -= qty;
        }
        else if (goodType==6 && mem3==0){
            if (qty>spiceInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " spice.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else spiceInvRus -= qty;
        }
        else if (goodType==7 && mem3==0){
            if (qty>ironInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " iron.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else ironInvRus -= qty;
        }
        else if (goodType==8 && mem3==0){
            if (qty>flourInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " flour.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else flourInvRus -= qty;
        }
        else if (goodType==9 && mem3==0){
            if (qty>dyeInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " dyes.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else dyeInvRus -= qty;
        }
        else if (goodType==10 && mem3==0){
            if (qty>leatherInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " leatherworks.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else leatherInvRus -= qty;
        }
        else if (goodType==11 && mem3==0){
            if (qty>furInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " fur.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else furInvRus -= qty;
        }
        else if (goodType==12 && mem3==0){
            if (qty>beerInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " beer.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else beerInvRus -= qty;
        }
        else if (goodType==13 && mem3==0){
            if (qty>saltInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << "salt.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else saltInvRus -= qty;
        }
        else if (goodType==14 && mem3==0){
            if (qty>wineInvRus){
            	cout << setw(62);
                cout << "Russia does not have " << qty << " wine.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else wineInvRus -= qty;
        }
        //Sell
        else if (goodType==0 && mem3==1){
            potInvRus += qty;
        }
        else if (goodType==1 && mem3==1){
            oilInvRus += qty;
        }
        else if (goodType==2 && mem3==1){
            fishInvRus += qty;
        }
        else if (goodType==3 && mem3==1){
            woolInvRus += qty;
        }
        else if (goodType==4 && mem3==1){
            velvetInvRus += qty;
        }
        else if (goodType==5 && mem3==1){
            toolsInvRus += qty;
        }
        else if (goodType==6 && mem3==1){
            spiceInvRus += qty;
        }
        else if (goodType==7 && mem3==1){
            ironInvRus += qty;
        }
        else if (goodType==8 && mem3==1){
            flourInvRus += qty;
        }
        else if (goodType==9 && mem3==1){
            dyeInvRus += qty;
        }
        else if (goodType==10 && mem3==1){
            leatherInvRus += qty;
        }
        else if (goodType==11 && mem3==1){
            furInvRus += qty;
        }
        else if (goodType==12 && mem3==1){
            beerInvRus += qty;
        }
        else if (goodType==13 && mem3==1){
            saltInvRus += qty;
        }
        else if (goodType==14 && mem3==1){
            wineInvRus += qty;
        }
    }
   else if (land==3){
        //Buy
        if (goodType==0 && mem3==0){
            if (qty>potInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " pottery.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else potInvCri -= qty;
        }
        else if (goodType==1 && mem3==0){
            if (qty>oilInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " oil.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else oilInvCri -= qty;
        }
        else if (goodType==2 && mem3==0){
            if (qty>fishInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " fish.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else fishInvCri -= qty;
        }
        else if (goodType==3 && mem3==0){
            if (qty>woolInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " wool cloth.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else woolInvCri -= qty;
        }
        else if (goodType==4 && mem3==0){
            if (qty>velvetInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " velvet.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else velvetInvCri -= qty;
        }
        else if (goodType==5 && mem3==0){
            if (qty>toolsInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " tools.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else toolsInvCri -= qty;
        }
        else if (goodType==6 && mem3==0){
            if (qty>spiceInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " spice.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else spiceInvCri -= qty;
        }
        else if (goodType==7 && mem3==0){
            if (qty>ironInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " iron.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else ironInvCri -= qty;
        }
        else if (goodType==8 && mem3==0){
            if (qty>flourInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " flour.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else flourInvCri -= qty;
        }
        else if (goodType==9 && mem3==0){
            if (qty>dyeInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " dyes.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else dyeInvCri -= qty;
        }
        else if (goodType==10 && mem3==0){
            if (qty>leatherInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " leatherworks.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else leatherInvCri -= qty;
        }
        else if (goodType==11 && mem3==0){
            if (qty>furInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " fur.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else furInvCri -= qty;
        }
        else if (goodType==12 && mem3==0){
            if (qty>beerInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " beer.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else beerInvCri -= qty;
        }
        else if (goodType==13 && mem3==0){
            if (qty>saltInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << "salt.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else saltInvCri -= qty;
        }
        else if (goodType==14 && mem3==0){
            if (qty>wineInvCri){
            	cout << setw(62);
                cout << "Crimea does not have " << qty << " wine.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else wineInvCri -= qty;
        }
        //Sell
        else if (goodType==0 && mem3==1){
            potInvCri += qty;
        }
        else if (goodType==1 && mem3==1){
            oilInvCri += qty;
        }
        else if (goodType==2 && mem3==1){
            fishInvCri += qty;
        }
        else if (goodType==3 && mem3==1){
            woolInvCri += qty;
        }
        else if (goodType==4 && mem3==1){
            velvetInvCri += qty;
        }
        else if (goodType==5 && mem3==1){
            toolsInvCri += qty;
        }
        else if (goodType==6 && mem3==1){
            spiceInvCri += qty;
        }
        else if (goodType==7 && mem3==1){
            ironInvCri += qty;
        }
        else if (goodType==8 && mem3==1){
            flourInvCri += qty;
        }
        else if (goodType==9 && mem3==1){
            dyeInvCri += qty;
        }
        else if (goodType==10 && mem3==1){
            leatherInvCri += qty;
        }
        else if (goodType==11 && mem3==1){
            furInvCri += qty;
        }
        else if (goodType==12 && mem3==1){
            beerInvCri += qty;
        }
        else if (goodType==13 && mem3==1){
            saltInvCri += qty;
        }
        else if (goodType==14 && mem3==1){
            wineInvCri += qty;
        }
    }
    else if (land==4){
        //Buy
        if (goodType==0 && mem3==0){
            if (qty>potInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " pottery.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else potInvSau -= qty;
        }
        else if (goodType==1 && mem3==0){
            if (qty>oilInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " oil.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else oilInvSau -= qty;
        }
        else if (goodType==2 && mem3==0){
            if (qty>fishInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " fish.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else fishInvSau -= qty;
        }
        else if (goodType==3 && mem3==0){
            if (qty>woolInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " wool cloth.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else woolInvSau -= qty;
        }
        else if (goodType==4 && mem3==0){
            if (qty>velvetInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " velvet.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else velvetInvSau -= qty;
        }
        else if (goodType==5 && mem3==0){
            if (qty>toolsInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " tools.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else toolsInvSau -= qty;
        }
        else if (goodType==6 && mem3==0){
            if (qty>spiceInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " spice.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else spiceInvSau -= qty;
        }
        else if (goodType==7 && mem3==0){
            if (qty>ironInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " iron.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else ironInvSau -= qty;
        }
        else if (goodType==8 && mem3==0){
            if (qty>flourInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " flour.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else flourInvSau -= qty;
        }
        else if (goodType==9 && mem3==0){
            if (qty>dyeInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " dyes.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else dyeInvSau -= qty;
        }
        else if (goodType==10 && mem3==0){
            if (qty>leatherInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " leatherworks.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else leatherInvSau -= qty;
        }
        else if (goodType==11 && mem3==0){
            if (qty>furInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " fur.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else furInvSau -= qty;
        }
        else if (goodType==12 && mem3==0){
            if (qty>beerInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " beer.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else beerInvSau -= qty;
        }
        else if (goodType==13 && mem3==0){
            if (qty>saltInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " salt.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else saltInvSau -= qty;
        }
        else if (goodType==14 && mem3==0){
            if (qty>wineInvSau){
            	cout << setw(62);
                cout << "Saudi Arabia does not have " << qty << " wine.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else wineInvSau -= qty;
        }
        //Sell
        else if (goodType==0 && mem3==1){
            potInvSau += qty;
        }
        else if (goodType==1 && mem3==1){
            oilInvSau += qty;
        }
        else if (goodType==2 && mem3==1){
            fishInvSau += qty;
        }
        else if (goodType==3 && mem3==1){
            woolInvSau += qty;
        }
        else if (goodType==4 && mem3==1){
            velvetInvSau += qty;
        }
        else if (goodType==5 && mem3==1){
            toolsInvSau += qty;
        }
        else if (goodType==6 && mem3==1){
            spiceInvSau += qty;
        }
        else if (goodType==7 && mem3==1){
            ironInvSau += qty;
        }
        else if (goodType==8 && mem3==1){
            flourInvSau += qty;
        }
        else if (goodType==9 && mem3==1){
            dyeInvSau += qty;
        }
        else if (goodType==10 && mem3==1){
            leatherInvSau += qty;
        }
        else if (goodType==11 && mem3==1){
            furInvSau += qty;
        }
        else if (goodType==12 && mem3==1){
            beerInvSau += qty;
        }
        else if (goodType==13 && mem3==1){
            saltInvSau += qty;
        }
        else if (goodType==14 && mem3==1){
            wineInvSau += qty;
        }
    }
    else if (land==5){
        //Buy
        if (goodType==0 && mem3==0){
            if (qty>potInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " pottery.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else potInvUkr -= qty;
        }
        else if (goodType==1 && mem3==0){
            if (qty>oilInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " oil.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else oilInvUkr -= qty;
        }
        else if (goodType==2 && mem3==0){
            if (qty>fishInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " fish.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else fishInvUkr -= qty;
        }
        else if (goodType==3 && mem3==0){
            if (qty>woolInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " wool cloth.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else woolInvUkr -= qty;
        }
        else if (goodType==4 && mem3==0){
            if (qty>velvetInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " velvet.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else velvetInvUkr -= qty;
        }
        else if (goodType==5 && mem3==0){
            if (qty>toolsInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " tools.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else toolsInvUkr -= qty;
        }
        else if (goodType==6 && mem3==0){
            if (qty>spiceInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " spice.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else spiceInvUkr -= qty;
        }
        else if (goodType==7 && mem3==0){
            if (qty>ironInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " iron.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else ironInvUkr -= qty;
        }
        else if (goodType==8 && mem3==0){
            if (qty>flourInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " flour.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else flourInvUkr -= qty;
        }
        else if (goodType==9 && mem3==0){
            if (qty>dyeInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " dyes.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else dyeInvUkr -= qty;
        }
        else if (goodType==10 && mem3==0){
            if (qty>leatherInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " leatherworks.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else leatherInvUkr -= qty;
        }
        else if (goodType==11 && mem3==0){
            if (qty>furInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " fur.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else furInvUkr -= qty;
        }
        else if (goodType==12 && mem3==0){
            if (qty>beerInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " beer.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else beerInvUkr -= qty;
        }
        else if (goodType==13 && mem3==0){
            if (qty>saltInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " salt.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else saltInvUkr -= qty;
        }
        else if (goodType==14 && mem3==0){
            if (qty>wineInvUkr){
            	cout << setw(62);
                cout << "Ukraine does not have " << qty << " wine.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else wineInvUkr -= qty;
        }
        //Sell
        else if (goodType==0 && mem3==1){
            potInvUkr += qty;
        }
        else if (goodType==1 && mem3==1){
            oilInvUkr += qty;
        }
        else if (goodType==2 && mem3==1){
            fishInvUkr += qty;
        }
        else if (goodType==3 && mem3==1){
            woolInvUkr += qty;
        }
        else if (goodType==4 && mem3==1){
            velvetInvUkr += qty;
        }
        else if (goodType==5 && mem3==1){
            toolsInvUkr += qty;
        }
        else if (goodType==6 && mem3==1){
            spiceInvUkr += qty;
        }
        else if (goodType==7 && mem3==1){
            ironInvUkr += qty;
        }
        else if (goodType==8 && mem3==1){
            flourInvUkr += qty;
        }
        else if (goodType==9 && mem3==1){
            dyeInvUkr += qty;
        }
        else if (goodType==10 && mem3==1){
            leatherInvUkr += qty;
        }
        else if (goodType==11 && mem3==1){
            furInvUkr += qty;
        }
        else if (goodType==12 && mem3==1){
            beerInvUkr += qty;
        }
        else if (goodType==13 && mem3==1){
            saltInvUkr += qty;
        }
        else if (goodType==14 && mem3==1){
            wineInvUkr += qty;
        }
    }
    else if (land==6){
        //Buy
        if (goodType==0 && mem3==0){
            if (qty>potInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " pottery.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else potInvChi -= qty;
        }
        else if (goodType==1 && mem3==0){
            if (qty>oilInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " oil.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else oilInvChi -= qty;
        }
        else if (goodType==2 && mem3==0){
            if (qty>fishInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " fish.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else fishInvChi -= qty;
        }
        else if (goodType==3 && mem3==0){
            if (qty>woolInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " wool cloth.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else woolInvChi -= qty;
        }
        else if (goodType==4 && mem3==0){
            if (qty>velvetInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " velvet.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else velvetInvChi -= qty;
        }
        else if (goodType==5 && mem3==0){
            if (qty>toolsInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " tools.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else toolsInvChi -= qty;
        }
        else if (goodType==6 && mem3==0){
            if (qty>spiceInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " spice.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else spiceInvChi -= qty;
        }
        else if (goodType==7 && mem3==0){
            if (qty>ironInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " iron.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else ironInvChi -= qty;
        }
        else if (goodType==8 && mem3==0){
            if (qty>flourInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " flour.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else flourInvChi -= qty;
        }
        else if (goodType==9 && mem3==0){
            if (qty>dyeInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " dyes.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else dyeInvChi -= qty;
        }
        else if (goodType==10 && mem3==0){
            if (qty>leatherInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " leatherworks.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else leatherInvChi -= qty;
        }
        else if (goodType==11 && mem3==0){
            if (qty>furInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " fur.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else furInvChi -= qty;
        }
        else if (goodType==12 && mem3==0){
            if (qty>beerInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " beer.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else beerInvChi -= qty;
        }
        else if (goodType==13 && mem3==0){
            if (qty>saltInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " salt.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else saltInvChi -= qty;
        }
        else if (goodType==14 && mem3==0){
            if (qty>wineInvChi){
            	cout << setw(62);
                cout << "China does not have " << qty << " wine.";
                cout << endl;
                cout << endl;
                quantity();
            }
            else wineInvChi -= qty;
        }
        //Sell
        else if (goodType==0 && mem3==1){
            potInvChi += qty;
        }
        else if (goodType==1 && mem3==1){
            oilInvChi += qty;
        }
        else if (goodType==2 && mem3==1){
            fishInvChi += qty;
        }
        else if (goodType==3 && mem3==1){
            woolInvChi += qty;
        }
        else if (goodType==4 && mem3==1){
            velvetInvChi += qty;
        }
        else if (goodType==5 && mem3==1){
            toolsInvChi += qty;
        }
        else if (goodType==6 && mem3==1){
            spiceInvChi += qty;
        }
        else if (goodType==7 && mem3==1){
            ironInvChi += qty;
        }
        else if (goodType==8 && mem3==1){
            flourInvChi += qty;
        }
        else if (goodType==9 && mem3==1){
            dyeInvChi += qty;
        }
        else if (goodType==10 && mem3==1){
            leatherInvChi += qty;
        }
        else if (goodType==11 && mem3==1){
            furInvChi += qty;
        }
        else if (goodType==12 && mem3==1){
            beerInvChi += qty;
        }
        else if (goodType==13 && mem3==1){
            saltInvChi += qty;
        }
        else if (goodType==14 && mem3==1){
            wineInvChi += qty;
        }
    }

}


//random function
void random(void){
    goodType = 0;
    for (int i = 1; i <= 15; i++){
        if (goodType == 0){
            if (land == 0){
                inv_Country = potInvSwede;
            } 
            else if (land == 1){
                inv_Country = potInvPol;
            } 
            else if (land == 2){
            	inv_Country = potInvRus;
			}
			else if (land == 3){
            	inv_Country = potInvCri;
			}
			else if (land == 4){
            	inv_Country = potInvSau;
			}
			else if (land == 5){
            	inv_Country = potInvUkr;
			}
			else if (land == 6){
            	inv_Country = potInvChi;
			}
            
            if (inv_Country >= 76 && inv_Country <= 100){
                price = potPrice[land] + randomnum * 1;
            } 
            else if (inv_Country >= 51 && inv_Country <= 75){
                price = potPrice[land] * 1.25 + randomnum;
            } 
            else if (inv_Country >= 26 && inv_Country <= 50){
                price = potPrice[land] * 1.50 + randomnum;
            } 
            else if (inv_Country <= 25){
                price = potPrice[land] * 2 + randomnum;
            } 
            else if (inv_Country > 100){
                price = potPrice[land] * 0.5 + randomnum;
            }
            priceArrays[0] = price;
        }
        else if (goodType == 1){
            if (land == 0){
                inv_Country = oilInvSwede;  
            }
            else if (land == 1){
                inv_Country = oilInvPol;    
            } 
            else if (land == 2){
            	inv_Country = oilInvRus;
			}
			//changes
			else if (land == 3){
            	inv_Country = oilInvCri;
			}
			else if (land == 4){
            	inv_Country = oilInvSau;
			}
			else if (land == 5){
            	inv_Country = oilInvUkr;
			}
			else if (land == 6){
            	inv_Country = oilInvChi;
			}
			
            if (inv_Country >= 38 && inv_Country <= 50){
                price = oilPrice[land] + randomnum;
            } 
            else if (inv_Country >= 26 && inv_Country <= 37){
                price = oilPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 13 && inv_Country <= 25){
                price = oilPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 12){
                price = oilPrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 50){
                price = oilPrice[land] * 0.75 + randomnum;
            }
            priceArrays[1] = price;
        }
        else if (goodType == 2){
            if (land == 0){
                inv_Country = fishInvSwede;  
            }
            else if (land == 1){
                inv_Country = fishInvPol;    
            } 
            else if (land == 2){
            	inv_Country = fishInvRus;
			}
			else if (land == 3){
            	inv_Country = fishInvCri;
			}
			else if (land == 4){
            	inv_Country = fishInvSau;
			}
			else if (land == 5){
            	inv_Country = fishInvUkr;
			}
			else if (land == 6){
            	inv_Country = fishInvChi;
			}
			
            if (inv_Country >= 114 && inv_Country <= 150){
                price = fishPrice[land] + randomnum;
            } 
            else if (inv_Country >= 76 && inv_Country <= 113){
                price = fishPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 39 && inv_Country <= 75){
                price = fishPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 38){
                price = fishPrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 150){
                price = fishPrice[land] * 0.75 + randomnum;
            }
            priceArrays[2] = price;
        }
        else if (goodType == 3){
            if (land == 0){
                inv_Country = woolInvSwede;  
            }
            else if (land == 1){
                inv_Country = woolInvPol;    
            } 
            else if (land == 2){
            	inv_Country = woolInvRus;
			}
			else if (land == 3){
            	inv_Country = woolInvCri;
			}
			else if (land == 4){
            	inv_Country = woolInvSau;
			}
			else if (land == 5){
            	inv_Country = woolInvUkr;
			}
			else if (land == 6){
            	inv_Country = woolInvChi;
			}
			
            if (inv_Country >= 38 && inv_Country <= 75){
                price = woolPrice[land] + randomnum;
            } 
            else if (inv_Country >= 26 && inv_Country <= 56){
                price = woolPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 13 && inv_Country <= 38){
                price = woolPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 12){
                price = woolPrice[land] * 2 + randomnum;
            }
            else if (inv_Country < 75){
                price = woolPrice[land] * 0.75 + randomnum;
            }
            priceArrays[3] = price;
        }
        else if (goodType == 4){
            if (land == 0){
                inv_Country = velvetInvSwede;  
            }
            else if (land == 1){
                inv_Country = velvetInvPol;    
            } 
            else if (land == 2){
            	inv_Country = velvetInvRus;
			}
			else if (land == 3){
            	inv_Country = velvetInvCri;
			}
			else if (land == 4){
            	inv_Country = velvetInvSau;
			}
			else if (land == 5){
            	inv_Country = velvetInvUkr;
			}
			else if (land == 6){
            	inv_Country = velvetInvChi;
			}
			
            if (inv_Country >= 20 && inv_Country <= 25){
                price = velvetPrice[land] + randomnum;
            } 
            else if (inv_Country >= 14 && inv_Country <= 19){
                price = velvetPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 8 && inv_Country <= 13){
                price = velvetPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 7){
                price = velvetPrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 25){
                price = velvetPrice[land] * 0.75 + randomnum;
            }
            priceArrays[4] = price;
        }
        else if (goodType == 5){
            if (land == 0){
                inv_Country = toolsInvSwede;  
            }
            else if (land == 1){
                inv_Country = toolsInvPol;    
            } 
            else if (land == 2){
            	inv_Country = toolsInvRus;
			}
			
			else if (land == 3){
            	inv_Country = toolsInvCri;
			}
			else if (land == 4){
            	inv_Country = toolsInvSau;
			}
			else if (land == 5){
            	inv_Country = toolsInvUkr;
			}
			else if (land == 6){
            	inv_Country = toolsInvChi;
			}
			
            if (inv_Country >= 38 && inv_Country <= 50){
                price = toolsPrice[land] + randomnum;
                if (land == 6){
                    if (price < 0){
                        price *= -1;
                    }
                    price += 350;
                }
            } 
            else if (inv_Country >= 26 && inv_Country <= 37){
                price = toolsPrice[land] * 1.25 + randomnum;
                if (land == 6){
                    if (price < 0){
                        price *= -1;
                    }
                    price += 350;
                }
            }
            else if (inv_Country >= 13 && inv_Country <= 25){
                price = toolsPrice[land] * 1.50 + randomnum;
                 if (land == 6){
                    if (price < 0){
                        price *= -1;
                    }
                    price += 350;
                }
            }
            else if (inv_Country <= 12){
                price = toolsPrice[land] * 2 + randomnum;
                if (land == 6){
                    if (price < 0){
                        price *= -1;
                    }
                    price += 350;
                }
            }
            else if (inv_Country > 50){
                price = toolsPrice[land] * 0.75 + randomnum;
                if (land == 6){
                    if (price < 0){
                        price *= -1;
                    }
                    price += 350;
                }
            }
            priceArrays[5] = price;
        }
        else if (goodType == 6){
            if (land == 0){
                inv_Country = spiceInvSwede;  
            }
            else if (land == 1){
                inv_Country = spiceInvPol;    
            } 
            else if (land == 2){
            	inv_Country = spiceInvRus;
			}
			else if (land == 3){
            	inv_Country = spiceInvCri;
			}
			else if (land == 4){
            	inv_Country = spiceInvSau;
			}
			else if (land == 5){
            	inv_Country = spiceInvUkr;
			}
			else if (land == 6){
            	inv_Country = spiceInvChi;
			}
			
            if (inv_Country >= 24 && inv_Country <= 30){
                price = spicePrice[land] + randomnum;
            } 
            else if (inv_Country >= 16 && inv_Country <= 23){
                price = spicePrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 9 && inv_Country <= 15){
                price = spicePrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 8){
                price = spicePrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 30){
                price = spicePrice[land] * 0.75 + randomnum;
            }
            priceArrays[6] = price;
        }
        else if (goodType == 7){
            if (land == 0){
                inv_Country = ironInvSwede;  
            }
            else if (land == 1){
                inv_Country = ironInvPol;    
            } 
            else if (land == 2){
            	inv_Country = ironInvRus;
			}
			else if (land == 3){
            	inv_Country = ironInvCri;
			}
			else if (land == 4){
            	inv_Country = ironInvSau;
			}
			else if (land == 5){
            	inv_Country = ironInvUkr;
			}
			else if (land == 6){
            	inv_Country = ironInvChi;
			}
			
            if (inv_Country >= 76 && inv_Country <= 100){
                price = ironPrice[land] + randomnum;
            } 
            else if (inv_Country >= 51 && inv_Country <= 75){
                price = ironPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 26 && inv_Country <= 50){
                price = ironPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 25){
                price = ironPrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 100){
                price = ironPrice[land] * 0.75 + randomnum;
            }
            priceArrays[7] = price;
        }
        else if (goodType == 8){
            if (land == 0){
                inv_Country = flourInvSwede;  
            }
            else if (land == 1){
                inv_Country = flourInvPol;    
            } 
            else if (land == 2){
            	inv_Country = flourInvRus;
			}
			else if (land == 3){
            	inv_Country = flourInvCri;
			}
			else if (land == 4){
            	inv_Country = flourInvSau;
			}
			else if (land == 5){
            	inv_Country = flourInvUkr;
			}
			else if (land == 6){
            	inv_Country = flourInvChi;
			}
			
            if (inv_Country >= 114 && inv_Country <= 150){
                price = flourPrice[land] + randomnum;
            } 
            else if (inv_Country >= 76 && inv_Country <= 113){
                price = flourPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 39 && inv_Country <= 75){
                price = flourPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 38){
                price = flourPrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 150){
                price = flourPrice[land] * 0.75 + randomnum;
            }
            priceArrays[8] = price;
        }
        else if (goodType == 9){
            if (land == 0){
                inv_Country = dyeInvSwede;  
            }
            else if (land == 1){
                inv_Country = dyeInvPol;    
            } 
            else if (land == 2){
            	inv_Country = dyeInvRus;
			}
			else if (land == 3){
            	inv_Country = dyeInvCri;
			}
			else if (land == 4){
            	inv_Country = dyeInvSau;
			}
			else if (land == 5){
            	inv_Country = dyeInvUkr;
			}
			else if (land == 6){
            	inv_Country = dyeInvChi;
			}
			
            if (inv_Country >= 57 && inv_Country <= 75){
                price = dyePrice[land] + randomnum;
            } 
            else if (inv_Country >= 40 && inv_Country <= 56){
                price = dyePrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 20 && inv_Country <= 39){
                price = dyePrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 19){
                price = dyePrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 75){
                price = dyePrice[land] * 0.75 + randomnum;
            }
            priceArrays[9] = price;
        }
        else if (goodType == 10){
            if (land == 0){
                inv_Country = leatherInvSwede;  
            }
            else if (land == 1){
                inv_Country = leatherInvPol;    
            } 
            else if (land == 2){
            	inv_Country = leatherInvRus;
			}
			else if (land == 3){
            	inv_Country = leatherInvCri;
			}
			else if (land == 4){
            	inv_Country = leatherInvSau;
			}
			else if (land == 5){
            	inv_Country = leatherInvUkr;
			}
			else if (land == 6){
            	inv_Country = leatherInvChi;
			}
			
            if (inv_Country >= 57 && inv_Country <= 75){
                price = leatherPrice[land] + randomnum;
            } 
            else if (inv_Country >= 39 && inv_Country <= 56){
                price = leatherPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 20 && inv_Country <= 38){
                price = leatherPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 19){
                price = leatherPrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 75){
                price = leatherPrice[land] * 0.75 + randomnum;
            }
            priceArrays[10] = price;
        }
        else if (goodType == 11){
            if (land == 0){
                inv_Country = furInvSwede;  
            }
            else if (land == 1){
                inv_Country = furInvPol;    
            } 
            else if (land == 2){
            	inv_Country = furInvRus;
			}
			else if (land == 3){
            	inv_Country = furInvCri;
			}
			else if (land == 4){
            	inv_Country = furInvSau;
			}
			else if (land == 5){
            	inv_Country = furInvUkr;
			}
			else if (land == 6){
            	inv_Country = furInvChi;
			}
			
            if (inv_Country >= 57 && inv_Country <= 75){
                price = furPrice[land] + randomnum;
            } 
            else if (inv_Country >= 40 && inv_Country <= 56){
                price = furPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 20 && inv_Country <= 39){
                price = furPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 19){
                price = furPrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 75){
                price = furPrice[land] * 0.75 + randomnum;
            }
            priceArrays[11] = price;
        }
        else if (goodType == 12){
            if (land == 0){
                inv_Country = beerInvSwede;  
            }
            else if (land == 1){
                inv_Country = beerInvPol;    
            } 
            else if (land == 2){
            	inv_Country = beerInvRus;
			}
			else if (land == 3){
            	inv_Country = beerInvCri;
			}
			else if (land == 4){
            	inv_Country = beerInvSau;
			}
			else if (land == 5){
            	inv_Country = beerInvUkr;
			}
			else if (land == 6){
            	inv_Country = beerInvChi;
			}
			
            if (inv_Country >= 57 && inv_Country <= 75){
                price = beerPrice[land] + randomnum;
            } 
            else if (inv_Country >= 40 && inv_Country <= 56){
                price = beerPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 20 && inv_Country <= 39){
                price = beerPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 19){
                price = beerPrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 75){
                price = beerPrice[land] * 0.75 + randomnum;
            }
            priceArrays[12] = price;
        }else if (goodType == 13){
            if (land == 0){
                inv_Country = saltInvSwede;  
            }
            else if (land == 1){
                inv_Country = saltInvPol;    
            } 
            else if (land == 2){
            	inv_Country = saltInvRus;
			}
			else if (land == 3){
            	inv_Country = saltInvCri;
			}
			else if (land == 4){
            	inv_Country = saltInvSau;
			}
			else if (land == 5){
            	inv_Country = saltInvUkr;
			}
			else if (land == 6){
            	inv_Country = saltInvChi;
			}
			
            if (inv_Country >= 57 && inv_Country <= 75){
                price = saltPrice[land] + randomnum;
            } 
            else if (inv_Country >= 40 && inv_Country <= 56){
                price = saltPrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 20 && inv_Country <= 39){
                price = saltPrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 19){
                price = saltPrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 50){
                price = saltPrice[land] * 0.75 + randomnum;
            }
            priceArrays[13] = price;
        }
        else if (goodType == 14){
            if (land == 0){
                inv_Country = wineInvSwede;  
            }
            else if (land == 1){
                inv_Country = wineInvPol;    
            } 
            else if (land == 2){
            	inv_Country = wineInvRus;
			}
			else if (land == 3){
            	inv_Country = wineInvCri;
			}
			else if (land == 4){
            	inv_Country = wineInvSau;
			}
			else if (land == 5){
            	inv_Country = wineInvUkr;
			}
			else if (land == 6){
            	inv_Country = wineInvChi;
			}
			
            if (inv_Country >= 57 && inv_Country <= 75){
                price = winePrice[land] + randomnum;
            } 
            else if (inv_Country >= 40 && inv_Country <= 56){
                price = winePrice[land] * 1.25 + randomnum;
            }
            else if (inv_Country >= 20 && inv_Country <= 39){
                price = winePrice[land] * 1.50 + randomnum;
            }
            else if (inv_Country <= 19){
                price = winePrice[land] * 2 + randomnum;
            }
            else if (inv_Country > 75){
                price = winePrice[land] * 0.75 + randomnum;
            }
            priceArrays[14] = price;
        }
        int z;
        if (i < 10){
        	cout << setw(15) << "[" << i << "] " << setw(18) << tradeGoods[goodType] << setw(15) << " - " << setw(15) << "Eur " << setw(5) << price;	
		}
		else if (i >= 10){
			cout << setw(14) << "[" << i << "] " << setw(18) << tradeGoods[goodType] << setw(15) << " - " << setw(15) << "Eur " << setw(5) << price;
		}
        
        cout << endl;
        goodType++;
    }

	}

float random(float x){
	srand(time(0));
	x = rand() % 20 + (-20);
	return x;
}

//inv country function
void determineCountry(void){
    if (land == 0){
        if (goodType == 0) inv_Country = potInvSwede;
//		//potInv = 0, oilInv = 0; fishInv = 0; woolInv=0; velvetInv=0; toolsInv=0; spiceInv=0; ironInv=0; flourInv=0; dyeInv=0; leatherInv=0; furInv=0; beerInv=0, saltInv=0; wineInv=0;
        else if (goodType == 1) inv_Country = oilInvSwede;
        //addition
        else if (goodType == 2) inv_Country = fishInvSwede;
        else if (goodType == 3) inv_Country = woolInvSwede;
        else if (goodType == 4) inv_Country = velvetInvSwede;
        else if (goodType == 5) inv_Country = toolsInvSwede;
        else if (goodType == 6) inv_Country = spiceInvSwede;
        else if (goodType == 7) inv_Country = ironInvSwede;
        else if (goodType == 8) inv_Country = flourInvSwede;
        else if (goodType == 9) inv_Country = dyeInvSwede;
        else if (goodType == 10) inv_Country = leatherInvSwede;
        else if (goodType == 11) inv_Country = furInvSwede;
        else if (goodType == 12) inv_Country = beerInvSwede;
        else if (goodType == 13) inv_Country = saltInvSwede;
        else if (goodType == 14) inv_Country = wineInvSwede;
        
    }
    else if (land == 1){
        if (goodType == 0) inv_Country = potInvPol;
        else if (goodType == 1) inv_Country = oilInvPol;
        else if (goodType == 2) inv_Country = fishInv;
        else if (goodType == 3) inv_Country = woolInvPol;
        else if (goodType == 4) inv_Country = velvetInvPol;
        else if (goodType == 5) inv_Country = toolsInvPol;
        else if (goodType == 6) inv_Country = spiceInvPol;
        else if (goodType == 7) inv_Country = ironInvPol;
        else if (goodType == 8) inv_Country = flourInvPol;
        else if (goodType == 9) inv_Country = dyeInvPol;
        else if (goodType == 10) inv_Country = leatherInvPol;
        else if (goodType == 11) inv_Country = furInvPol;
        else if (goodType == 12) inv_Country = beerInvPol;
        else if (goodType == 13) inv_Country = saltInvPol;
        else if (goodType == 14) inv_Country = wineInvPol;
    }
    else if (land == 2){
        if (goodType == 0) inv_Country = potInvRus;
        else if (goodType == 1) inv_Country = oilInvRus;
        else if (goodType == 2) inv_Country = fishInvRus;
        else if (goodType == 3) inv_Country = woolInvRus;
        else if (goodType == 4) inv_Country = velvetInvRus;
        else if (goodType == 5) inv_Country = toolsInvRus;
        else if (goodType == 6) inv_Country = spiceInvRus;
        else if (goodType == 7) inv_Country = ironInvRus;
        else if (goodType == 8) inv_Country = flourInvRus;
        else if (goodType == 9) inv_Country = dyeInvRus;
        else if (goodType == 10) inv_Country = leatherInvRus;
        else if (goodType == 11) inv_Country = furInvRus;
        else if (goodType == 12) inv_Country = beerInvRus;
        else if (goodType == 13) inv_Country = saltInvRus;
        else if (goodType == 14) inv_Country = wineInvRus;
    }
    //changes
    else if (land == 3){
        if (goodType == 0) inv_Country = potInvCri;
        else if (goodType == 1) inv_Country = oilInvCri;
        else if (goodType == 2) inv_Country = fishInvCri;
        else if (goodType == 3) inv_Country = woolInvCri;
        else if (goodType == 4) inv_Country = velvetInvCri;
        else if (goodType == 5) inv_Country = toolsInvCri;
        else if (goodType == 6) inv_Country = spiceInvCri;
        else if (goodType == 7) inv_Country = ironInvCri;
        else if (goodType == 8) inv_Country = flourInvCri;
        else if (goodType == 9) inv_Country = dyeInvCri;
        else if (goodType == 10) inv_Country = leatherInvCri;
        else if (goodType == 11) inv_Country = furInvCri;
        else if (goodType == 12) inv_Country = beerInvCri;
        else if (goodType == 13) inv_Country = saltInvCri;
        else if (goodType == 14) inv_Country = wineInvCri;
    }
    else if (land == 4){
        if (goodType == 0) inv_Country = potInvSau;
        else if (goodType == 1) inv_Country = oilInvSau;
        else if (goodType == 2) inv_Country = fishInvSau;
        else if (goodType == 3) inv_Country = woolInvSau;
        else if (goodType == 4) inv_Country = velvetInvSau;
        else if (goodType == 5) inv_Country = toolsInvSau;
        else if (goodType == 6) inv_Country = spiceInvSau;
        else if (goodType == 7) inv_Country = ironInvSau;
        else if (goodType == 8) inv_Country = flourInvSau;
        else if (goodType == 9) inv_Country = dyeInvSau;
        else if (goodType == 10) inv_Country = leatherInvSau;
        else if (goodType == 11) inv_Country = furInvSau;
        else if (goodType == 12) inv_Country = beerInvSau;
        else if (goodType == 13) inv_Country = saltInvSau;
        else if (goodType == 14) inv_Country = wineInvSau;
    }
    else if (land == 5){
        if (goodType == 0) inv_Country = potInvUkr;
        else if (goodType == 1) inv_Country = oilInvUkr;
        else if (goodType == 2) inv_Country = fishInvUkr;
        else if (goodType == 3) inv_Country = woolInvUkr;
        else if (goodType == 4) inv_Country = velvetInvUkr;
        else if (goodType == 5) inv_Country = toolsInvUkr;
        else if (goodType == 6) inv_Country = spiceInvUkr;
        else if (goodType == 7) inv_Country = ironInvUkr;
        else if (goodType == 8) inv_Country = flourInvUkr;
        else if (goodType == 9) inv_Country = dyeInvUkr;
        else if (goodType == 10) inv_Country = leatherInvUkr;
        else if (goodType == 11) inv_Country = furInvUkr;
        else if (goodType == 12) inv_Country = beerInvUkr;
        else if (goodType == 13) inv_Country = saltInvUkr;
        else if (goodType == 14) inv_Country = wineInvUkr;
    }
    else if (land == 6){
        if (goodType == 0) inv_Country = potInvChi;
        else if (goodType == 1) inv_Country = oilInvChi;
        else if (goodType == 2) inv_Country = fishInvChi;
        else if (goodType == 3) inv_Country = woolInvChi;
        else if (goodType == 4) inv_Country = velvetInvChi;
        else if (goodType == 5) inv_Country = toolsInvChi;
        else if (goodType == 6) inv_Country = spiceInvChi;
        else if (goodType == 7) inv_Country = ironInvChi;
        else if (goodType == 8) inv_Country = flourInvChi;
        else if (goodType == 9) inv_Country = dyeInvChi;
        else if (goodType == 10) inv_Country = leatherInvChi;
        else if (goodType == 11) inv_Country = furInvChi;
        else if (goodType == 12) inv_Country = beerInvChi;
        else if (goodType == 13) inv_Country = saltInvChi;
        else if (goodType == 14) inv_Country = wineInvChi;
    }

	}

void eventsNumbers(void)
{
	srand(time(0));
	int randomEvent;
	if (turn<=10)
	{randomEvent=rand()%10+1;
	events(randomEvent);}
	else if (turn>=11&&turn<=20)
	{randomEvent=rand()%20+1;
	events(randomEvent);}
	else if (turn>=21&&turn<=30)
	{randomEvent=rand()%30+1;
	events(randomEvent);}
	else if (turn>=31&&turn<=40)
	{randomEvent=rand()%40+1;
	events(randomEvent);}
	else if (turn>=41&&turn<=50)
	{randomEvent=rand()%50+1;
	events(randomEvent);}
}

void events(int random)
{
	int x;
	switch (random){
		case 1:
			cout<<"The company thought that you were incompetent, so they see fit that you would lose Eur 2000! Skip a turn and lose Eur 2000."<<endl;

			if(GOOJcard>=1)
			{
				cout << "Turns out you have that get out of jail card . . . ";
cout << endl << "You can only get so lucky." << endl;
				GOOJcard--;
			}
			else
			{
			turn++;
			balance=balance-2000;
			}
			break;
		case 3:
			cout<<"Psst! Someone just handed you a lucky card!"<<endl;
			GOOJcard=1;
			break;
		case 5:
			cout<<"The company's stocks gambit paid off! Your company saw fit to give you extra money for trading goods. Receive Eur 1000."<<endl;
			balance=balance+1000;
			break;
		case 7:
			cout<<"The company thought that your performance was astounding. Receive Eur 500 for trading."<<endl;
			balance=balance+500;
			break;
		case 9:
			cout<<"Your company wants to use the money from trading for other assets. Lose Eur 1500."<<endl;
			balance=balance-1500;
			break;
		case 11:
			cout<<"It's tax season! Lose a percentage of your trading balance based on the number of goods in Inventory."<<endl;
			balance=balance-(potInv*160*0.075+oilInv*400*0.075);
			break;
		case 13:
			cout<<"You go to jail! Skip a turn and lose Eur 2000."<<endl;
			if(GOOJcard>=1)
			{
				cout<<"Turns out you have that get out of jail card . . . .” << endl << “You can only get so lucky."<<endl;
				GOOJcard--;
			}
			else
			{
			turn++;
			balance=balance-2000;
			}
			break;
		case 15:
			cout<<"The company uses your trading balance to pay its debt. Lose half of your trading balance."<<endl;
			balance=balance/2;
			break;
		case 17:
			cout<<"The company's data was attacked by encryption virus. You lose half of your trading money to pay for ransomware."<<endl;
			balance=balance/2;
			break;
		case 19:
			cout<<"The company invested in a certain stock. The company used your trading money . . . Lose Eur 1000."<<endl;
			balance=balance-1000;
			investment++;
			break;
		case 21:
			cout<<"One of the cargo ships got lost in the transit! Lose Eur 7000."<<endl;
			balance-=7000;
			break;
		case 23:
			cout<<"You go to jail! Skip a turn and lose Eur 2000."<<endl;
			if(GOOJcard>=1)
			{
				cout<<"Turns out you have that get out of jail card . . . ." << endl << "You can only get so lucky." <<endl;
				GOOJcard--;
			}
			else
			{
			turn++;
			balance=balance-2000;
			}
			break;

		case 25:
			cout<<"The company invested in a certain stock. The company used your trading money . . . Lose Eur 1000."<<endl;
			balance=balance-1000;
			investment++;
			break;
		case 27:
			if(investment>=4)
			{
				cout<<"The company's investment paid off! Receive Eur 10000."<<endl;
				balance+=10000;
			}
			else
			{
				cout<<"The company's investment failed. Along with the few assets you gave them! Lose Eur 2000."<<endl;
				balance-=2000;
			}
			break;
		case 29:
			cout<<"A corporation tried a hostile takeover! You managed to drive them off, but at what cost? Lose Eur 5000."<<endl;
			balance-=5000;
break;
		case 31:
			cout<<"The stakes are getting higher, you need more money. Receive 50% added more trading money."<<endl;
			balance=balance*1.5;
break;
		case 33:
			cout<<"Enemy corporations manufactured scandals about your company. Fighting lawsuit after lawsuit is tiring, as well as expensive. Skip 2 turns and lose Eur 8000."<<endl;
			if(GOOJcard>=1)
			{
				cout<<"Fortunately however, you have that mysterious lucky card that man gave you. It vanished, as well as somehow the problems that plagued you."<<endl;
				GOOJcard--;
			}
			else
			{
			turn++;
			balance=balance-2000;
			}
break;
		case 35:
			if (event35==0)
			{
				cout<<"A man approached you, and said, 'I am part of an organization named Cauldron. We would like your sponsorship in order to progress our plans with saving Mother Earth.' What do you do? (1 Yes/2 No)"<<endl;
				do {
					cout << "Enter Input: ";
					cin >> input;
					stringstream(input) >> x;
					switch (x){
						case 1:
							cout<<"Thank you for your patronage. We will not forget this.";
							Cauldron++;
							break;
						case 2:
							cout<<"I see . . . I hope you don't regret your decision.";
							break;
						default:
							cout<<"Invalid input. Please try again.";
							break;
							}
					break;
				} while (input != "1" || input != "2");	
				event35=1;
			}
			else
			{
				cout<<"A strange wind flows today. Had something changed?";
				break;
			}
break;
		case 37:
			cout<<"The company invested in a certain stock. The company used your trading money . . . Lose Eur 1000."<<endl;
			balance=balance-1000;
			investment++;
			break;
		case 39:
			cout<<"A corporation tried a hostile takeover! You managed to drive them off, but at what cost? Lose €5000."<<endl;
			balance-=5000;
break;
		case 41:
			cout<<"A corporation tried a hostile takeover! You managed to drive them off, but at what cost? Lose €5000."<<endl;
			balance-=5000;
		case 43:
			cout<<"You invested in a certain stock. Something may come out of this . . . Lose Eur 1000."<<endl;
			balance=balance-1000;
			investment++;
			break;
		case 45:
			cout<<"A corporation tried a hostile takeover! You managed to drive them off, but at what cost? Lose Eur 5000."<<endl;
			balance-=5000;
		case 47:
			cout<<"The company invested in a certain stock. The company used your trading money . . . Lose Eur 1000."<<endl;
			balance=balance-1000;
			investment++;
			break;
		case 49:
			if(Cauldron==1)
			{
				cout<<"All of a sudden, the company’s profits soared! Your money is doubled.";
				balance=balance*2;
			}
			else
			{
				cout<<"All of a sudden, natural disasters began to strike at your holdings! Your money is quartered.";
				balance=balance/4;
			}
			break;
		default:
			cout << "No significant events have occurred!"<<endl;
			break;
	}
}

// Banking System
//The Bank Function
void theBank(void){
	checkers = 1;
	string input;
	memBank = 0;
	balance_balance();
	cout << endl;
	for (int i = 0; i > 15; i++){
		cout << " ";
	}
	cout << endl;
	cout << setw(37);
	cout << "Welcome to Jasper's Bank!";
	cout << endl;
	for (int i = 0; i > 15; i++){
		cout << " ";
	}
	cout << endl;
	cout << setw(37);
	cout << "What do you wish to do?";
	cout << endl;
	cout << "             =============================================================================";
	cout << endl;
	cout << setw(18);
	cout << "[1] " << setw(17) << "Withdraw";
	cout << endl;
	cout << setw(18);
	cout << "[2] " << setw(17) << "Deposit";
	cout << endl;
	cout << setw(18);
	cout << "[3] " << setw(17) << "Loan";
	cout << endl;
	cout << setw(18);
	cout << "[4] " << setw(17) << "Check Debt";
	cout << endl;
	cout << setw(18);
	cout << "[5] " << setw(17) << "Deposit Report";
	cout << endl;
	cout << setw(18);
	cout << "[6] " << setw(17) << "Rules";
	cout << endl;
	cout << setw(18);
	cout << "[7] " << setw(17) << "Return";
	cout << endl;
	cout << "             =============================================================================";
	cout << endl;
	cout << setw(27);
	do {
	cout << "Enter Input: ";
	cin >> input;
	if (input == "1"){
		withdraw();
	}
	else if (input == "2"){
		deposit();
	}
	else if (input == "3"){
		loan();
	}
	else if (input == "4"){	
		checkDebt();
	}
	else if (input == "5"){
		reports();
	}
	else if (input == "6"){
		rules();
	}
	else if (input == "7"){
		loc();
	}
	else cout<<"Invalid input. Please try again."<<endl;
	} while (input != "1" || input != "2"|| input != "3"|| input != "4"|| input != "4"|| input != "4"|| input != "7");
}

// User Debt Function
void userDebt(void){
	if (loanTurn > 0){
		float A, P, r, n, t;
		int convert;
		r = 0.05;
		t = 1;
		n = 4;
		P = loan1;
		A = P * (pow(1 + (r / n), (n * t)));
		convert = A;
		loan1 = convert;
	}
	//loanTurn = 4 (Start)
	if (loanTurn < 0){
		loanTurn = 0;
	}
	else if (loanTurn == 0) loanTurn = 0;
	else if (loanTurn <= 4){
		loanTurn--;
		if (loanTurn == 0){
			cout << endl;
			cout << endl;
			cout << "You were not able to pay your loan.";
			cout << endl;
			cout << "Defaulting Loan . . . ";
			sleep(2);
			cout << endl;
			sleep(3);
			cout << "Adding penalties . . . ";
			cout << endl;
			sleep(3);
			cout << "Adding collection charges . . . ";
			cout << endl;
			sleep(3);
			cout << "Garnishing Balance . . . ";
			cout << endl;
			float charge = loan1 * 0.25;
			balance -= (loan1 + charge);
			loan1 = 0;
			loanTurn = 0;
			cout << endl;
			cout << "Updated Balance: Eur " << balance;
			cout << endl;
			cout << endl;
			system("pause");
		}
	}
}

// Withdraw Function
void withdraw(void){
	float wd;
	balance_balance();
	cout << endl;
	cout << setw(40);
	cout << "\t\tHow much money do you wish to withdraw?";
	cout << endl;
	cout << "\t\tEnter Input: Eur ";
	cin >> wd;
	if (wd < 0){
		cout << endl;
		cout << "\t\tInvalid input. Please try again!";
		cout << endl;
		system("pause");
		withdraw();
	}
	else if (wd > bankMoney){
		
		if (memDp2 == 1){
			cout << endl;
			cout << "You've just recently deposited Eur " << bankMoney2 << ".";
			cout << endl;
			cout << "Please wait for another turn.";
			cout << endl;
			cout << endl;
			sleep(2);
			system("pause");
			theBank();
		}
		
		cout << endl;
		cout << "\t\tYou do not have that amount in your bank account . . . ";
		cout << endl;
		system("pause");
		withdraw();
	}
	else if (wd == 0){
		cout << endl;
		cout << "\t\tYou withdrew nothing . . . ";
		cout << endl;
		system("pause");
		theBank();
	}
	else if (wd <= bankMoney){
		
		if (memDp2 == 1){
			cout << endl;
			cout << "You've just recently deposited Eur " << bankMoney2 << ".";
			cout << endl;
			cout << "Please wait for another turn.";
			cout << endl;
			sleep(2);
			system("pause");
			theBank();
		}
		cout << endl;
		cout << "You withdrew Eur " << wd << " to your balance . . . ";
		cout << endl;
		cout << "Withdrawal Fee: Eur 3.50";
		cout << endl;
		cout << "Your balance has been updated . . . ";
		balance += wd;
		bankMoney -= wd;
		balance -= 3.50;
		if (bankMoney == 0){
			memDp = 0;
		}
		system("pause");
		theBank();
	}
}

// Deposit Function
void deposit(void){
	balance_balance();
	float dp;
	cout << endl;
	cout << "\t\tHow much money do you wish to deposit?";
	cout << endl;
	cout << setprecision(2) << fixed;
	cout << "\t\tInterest: " << interest2 << "%"; // Note: Please replace this with a randomizer percentage between 5 to 10.8 percent. Thanks.
	cout << endl;
	cout << "\t\tEnter Input: Eur ";
	cin >> dp;
	if (dp < 0){
		cout << endl;
		cout << "\t\tnvalid input. Please try again . . . ";
		cout << endl;
		system("pause");
		deposit();
		
	}
	else if (dp == 0){
		cout << endl;
		cout << "\t\tYou deposited nothing . . . ";
		cout << endl;
		system("pause");
		theBank();
	}
	else if (dp > balance){
		cout << endl;
		cout << "\t\tYou do not have that amount of money in your balance . . . ";
		cout << endl;
		system("pause");
		deposit();
	}
	else if (dp <= balance){
		if (dp <= balance && dp >= balance * 0.9){
			cout << endl;
			cout << "\t\tYou are not allowed to input 90% of your balance.";
			cout << endl;
			system("pause");
			deposit();
		}
		cout << endl;
		cout << "\t\tYou deposited Eur " << dp << " to your bank account . . . ";
		cout << endl;
		cout << "\t\tYour balance has been updated . . . ";
		cout << endl;
		if (memDp2 == 0){
			lastDeposit = bankMoney;
			lastDeposit2 = lastDeposit;
			bankMoney2 = dp;
		}
		else if (memDp2 == 1){
			lastDeposit = bankMoney;
			lastDeposit2 = lastDeposit;
			bankMoney2 = dp;
		}
		memDp = 1;
		memDp2 = 1;
		balance -= dp;
		bankMoney += dp;
		system("pause");
		theBank();
	}
}

// Loan Function
void loan(void){
	int sw;
	memBank = 1;
	string input;
	balance_balance();
	cout << endl;
	cout << "\t\tYou chose loan . . . ";
	cout << endl;
	cout << endl;
	cout << "\t\tWhat do you wish to do?";
	cout << endl;
	cout << "\t\t[1] " << "Repay";
	cout << endl;
	cout << "\t\t[2] " << "Borrow";
	cout << endl;
	cout << "\t\t[3] " << "Check Debt";
	cout << endl;
	cout << "\t\t[4] " << "Return";
	cout << endl;
	cout << endl;
	do {
	cout << "\t\tEnter Input: ";
	cin >> input;
	stringstream(input)>>sw;
	switch (sw){
		case 1: repay();
		break;
		case 2: 
		    if (loan1 > 0){
			 cout << endl;
			 cout << "\t\tYou already have a loan. Please repay your debt . . . ";
			 cout << endl;
			 cout << "\t\tDebt: Eur " << loan1;
			 cout << endl;
			 system("pause");
			 loan();
 
		}
		else{ borrow(); 
		break;}
		case 3: checkDebt();
		break;
		case 4: theBank();
		break;
		default:
			cout << endl;
			cout << "\t\tInvalid input. Please try again.";
			cout << endl;
			}
 
	} while (input != "1" || input != "2"|| input != "3"|| input != "4");
}

// Repay
void repay(void){
	if (loan1 <= 0){
		cout << endl;
		cout << endl;
		cout << "You cannot repay anything if you borrowed nothing.";
		cout << endl;
		cout << endl;
		loan();
	}
	balance_balance();
	float repay2 = 0;
	cout << endl;
	cout << "\t\tHow much money do you want to repay?";
	cout << endl;
	cout << "\t\tEnter Input: Eur ";
	cin >> repay2;
	if (loan1 > 0){
		if (repay2 == 0){
			cout << endl;
			cout << endl;
			cout << "\t\tYou repaid nothing.";
			cout << endl;
			cout << endl;
			system("pause");
			loan();
		}
		else if (repay2 < 0){
			cout << endl;
			cout << endl;
			cout << "\t\tInvalid input. Please try again.";
			cout << endl;
			cout << endl;
			repay();
		}
		else if (repay2 <= loan1 + 0.09){
			cout << endl;
			cout << endl;
			if (loanTurn == 4){
				float repay3;
				cout << endl;
				cout << "You paid the loan too early. " << interest2 << "% repayment penalty.";
				loan1 -= repay2;
				repay3 = repay2 * interest2/100;
				loan2 = loan1;
				balance -= (repay2 + repay3);
				cout << endl;
				if(loan1 == 0){
					memLoan = 0;
				}
				else if (loan1 <= 0.009) loan1= 0;
				cout << endl;
				system("pause");
				cout << endl;
				loan();
			}
			else if (loanTurn < 4){
				cout << endl;
				cout << "\t\tYou have chosen to repay Eur " << loan1 << " by " << repay2 << ".";
				cout << endl;
				loan1 -= repay2;
				balance -= repay2;
				if(loan1 == 0){
					memLoan = 0;
					loanTurn = -1;
				}
				else if (loan1 <= 0.009) loan1= 0;
				system("pause");
				loan();
			}
		}
	}
}
// Borrow
void borrow(void){
	balance_balance();
	int borrow_ = 0;
	cout << endl;
	cout << "\t\tHow much money do you want to borrow?";
	cout << endl;
	cout << "\t\tEnter Input: Eur ";
	cin >> borrow2;
	if (borrow2 < 0){
		cout << endl;
		cout << "\t\tInvalid input. Please try again.";
		cout << endl;
		system("pause");
		borrow();
	}
	else if (borrow2 == 0){
		cout << endl;
		cout << "\t\tYou borrowed nothing . . . ";
		cout << endl;
		system("pause");
		loan();
	}
	else if (borrow2 < 1000){
		cout << endl;
		cout << "\t\tOnly Eur 1,000 and above will be allowed as an input.";
		cout << endl;
		system("pause");
		borrow();
	}
	else if (borrow2 <= 1100000){
		//Eur 5000
		if (balance < 5000){
			if (borrow2 > 20000){
				cout << endl;
				trust(); cout << "20000.";
				cout << endl;
				cout << endl;
				system("pause");
				borrow();
			}
			else{
				trusted();
			}
		}
		//Eur 10000
		else if (balance < 10000){
			if (borrow2 > 40000){
				cout << endl;
				trust(); cout << "40,000.";
				cout << endl;
				system("pause");
				borrow();
			}
			else{
				trusted();
			}
		}
		else if (balance < 20000){
			if (borrow2 > 120000){
				cout << endl;
				trust(); cout << "120,000.";
				cout << endl;
				system("pause");
				borrow();
			}
			else{
				trusted();
			}
		}
		else if (balance < 120000){
			if (borrow2 > 400000){
				cout << endl;
				trust(); cout << "400,000.";
				cout << endl;
				system("pause");
				borrow();
			}
			else{
				trusted();
			}
		}
		else if (balance < 400000){
			if (borrow2 > 1100000){
				cout << endl;
				cout << "Jasper's Bank is only allowed to loan 15% of its legal capital . . . ";
				cout << endl;
				cout << "Please choose a value that is less than or equal to Eur 1,100,000";
				cout << endl;
				system("pause");
				borrow();
			}
			else{
				trusted();
			}
		}
	}
	else {
		cout << endl;
		cout << "Jasper's Bank is only allowed to loan 15% of its legal capital . . . ";
		cout << endl;
		cout << "Please choose a value that is less than or equal to Eur 1,100,000";
		cout << endl;
		system("pause");
		borrow();
	}
}

void compoundBank(void){
	float A, P, r, n, t; 
	/*
	A - Final Amount
	P - Initial Principal Balance
	r - Interest Rate
	n - Number of Times Interest Applied per Turn Period
	t - Number of 4-Turns
	1 turn = 4 months
	3 turns = 12 months
	*/
	r = 0.03;
	t = 1;
	n = 1;
	P = bankMoney;
	A = P * (pow((1 + (r / n)), (n * t)));
	A -= bankMoney;
	bankMoney += A;
}

void trust(void){
	cout << endl;
	cout << "Jasper's Bank doesn't trust you to repay your loan.";
	cout << endl;
	cout << "Please input a value less than or equal to Eur ";
}

void trusted(void){
	cout << endl;
	cout << "You borrowed Eur " << borrow2 << " from Jasper's Bank with " << interest << "% compound interest.";
	loan1 += borrow2;
	balance += borrow2;
	loan2 = loan1;
	cout << endl;
	system("pause");
	memLoan = 1;
	loanTurn = 4;
	loan();
}

void checkDebt(void){
	cout << endl;
	cout << "\t\tDebt: Eur " << loan1;
	cout << endl;
	system("pause");
	if (memBank == 0){
		theBank();
	}
	else if (memBank == 1){
		loan();
	}
}

void rules(void){
	cout << endl;
	cout << endl;
	cout << "              Rules";
	cout << endl;
	cout << "             =============================================================================";
	cout << endl;
	cout << "              Every turn is equal to four months.";
	cout << endl;
	cout << "              Every three turns is equal to one year.";
	cout << endl;
	cout << "              Every turn your loan debt increases.";
	cout << endl;
	cout << "              If you have not paid in the fourth turn your balance will be garnished.";
	cout << endl;
	cout << "              There is a penalty for not paying your debt.";
	cout << endl;
	cout << "             =============================================================================";
	cout << endl;
	cout << endl;
	system("pause");
	theBank();
}

void reports(void){
	if (memDp == -1){
		cout << endl;
		cout << endl;
		cout << "You have not deposited any money yet.";
		cout << endl;
		cout << endl;
		system("pause");
		theBank();
	}
	else if (memDp == 0){
		cout << endl;
		cout << endl;
		cout << "********** Financial Report **********";
		cout << endl;
		cout << "********** Jasper's Bank ***********";
		cout << endl;
		lastDeposit = bankMoney;
		cout << "Current Deposit: Eur " << bankMoney;
		cout << endl;
		cout << "Last Deposit: Eur " << lastDeposit;
		cout << endl;
		cout << "Increased by: " << (lastDeposit2 / lastDeposit) * 100 << "%.";
		cout << endl;
		cout << "********** End of Report **********";
		cout << endl;
		cout << endl;
		system("pause");
		theBank();
	}
	else if (memDp == 1){
		cout << endl;
		cout << endl;
		cout << "********** Financial Report **********";
		cout << endl;
		cout << "************ Jasper's Bank ***********";
		cout << endl;
		lastDeposit = bankMoney;
		cout << "        Current Deposit: Eur " << lastDeposit;
		cout << endl;
		//cout << "        Increased by: " << (lastDeposit2 / lastDeposit) * 100 << "%.";
		cout << endl;
		cout << "************* End of Report **********";
		cout << endl;
		cout << endl;
		system("pause");
		theBank();
	}
}

void taxes(void){ // Based on Germany
	//taxed at the fourth turn
	taxStore = balance;
	taxStore -= loan1;
	taxStore2 = 0;
	taxStore3 = 0;
	taxStore4 = 0;
	if(taxStore <= 9000){
		taxStore *= 0;
		cout << endl;
		cout << endl;
		cout << "Fourth Turn: You paid no taxes as your balance is too low . . . ";
		cout << endl;
		cout << endl;
	}
	else if (taxStore > 9000){
		if (taxStore >= 9001 && balance <= 13996){
			taxStore2 = taxStore;
			taxStore2 = taxStore2 - 9000;
			taxStore3 = taxStore2 * 0.15;
			taxStore2 = taxStore2 - taxStore3;
			cout << endl;
			cout << endl;
			cout << "Fourth Turn: You paid Eur " << taxStore2 << " on taxes . . . ";
			cout << endl;
			cout << endl;
			balance -= taxStore2;
		}
		else if (taxStore >= 13997 && taxStore <= 54949){
			taxStore2 = taxStore;
			taxStore2 = taxStore2 - 13996;
			taxStore3 = taxStore2 * 0.2397;
			taxStore4 = taxStore2 - taxStore3;
			taxStore2 = taxStore3;
			firstBracket();
			cout << endl;
			cout << endl;
			cout << "Fourth Turn: You paid Eur " << taxStore2 << " on taxes . . . ";
			cout << endl;
			cout << endl;
			balance -= taxStore2;
		}
		else if (taxStore >= 54950 && taxStore <= 260532){
			taxStore2 = taxStore;
			taxStore2 = taxStore2 - 54949;
			taxStore3 = taxStore2 * 0.42;
			taxStore4 = taxStore2 - taxStore3;
			taxStore2 = taxStore3;
			secondBracket();
			firstBracket();
			cout << endl;
			cout << endl;
			cout << "Fourth Turn: You paid Eur " << taxStore2 << " on taxes . . . ";
			cout << endl;
			cout << endl;
			balance -= taxStore2;
		}
		else if (taxStore >= 260533){
			taxStore2 = taxStore;
			taxStore2 = taxStore2 - 260532;
			taxStore3 = taxStore2 * 0.45;
			taxStore4 = taxStore2 - taxStore3;
			taxStore2 = taxStore3;
			thirdBracket();
			secondBracket();
			firstBracket();
			cout << endl;
			cout << endl;
			cout << "Fourth Turn: You paid Eur " << taxStore2 << " on taxes . . . ";
			cout << endl;
			cout << endl;
			balance -= taxStore2;
		}
	}
}

void firstBracket(void){
	float taxStore5 = 0;
	taxStore5 += (13996 * 0.15);
	taxStore2 = taxStore2 + taxStore5;
}

void secondBracket(void){
	float taxStore5 = 0;
	taxStore5 += (54949 * 0.2397);
	taxStore2 = taxStore2 + taxStore5;
}

void thirdBracket(void){
	float taxStore5 = 0;
	taxStore5 += (260532 * 0.42);
	taxStore2 = taxStore2 + taxStore5;
}

void fourthBracket(void){
	float taxStore5 = 0;
	taxStore5 += (balance * 0.45);
	taxStore2 = taxStore2 + taxStore5;
}

