#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class details{
public:
    int date;
    int month;
    int year;
};

class datenumber : public details{
public:
    int getdate()
    {
        return date;
    }
};
class monthcode : public datenumber{

public:
    int monthextraction(){
        if (month == 1)
            return 0;
        else if (month == 2)
            return 3;
        else if (month == 3)
            return 3;
        else if (month == 4)
            return 6;
        else if (month == 5)
            return 1;
        else if (month == 6)
            return 4;
        else if (month == 7)
            return 6;
        else if (month == 8)
            return 2;
        else if (month == 9)
            return 5;
        else if (month == 10)
            return 0;
        else if (month == 11)
            return 3;
        else
            return 5;
    }
};

class centurycode : public monthcode
{
public:
    int getcentury(int year){
        int ccode;
        if (year >= 2000 && year < 2100){
            ccode = 6;
        }
        else if (year >= 1600 && year < 1700){
            ccode = 6;
        }
        else if (year >= 1700 && year < 1800){
            ccode = 4;
        }
        else if (year >= 1800 && year < 1900){
            ccode = 2;
        }
        else if (year >= 1900 && year < 2000){
            ccode = 0;
        }
        else
            ccode = -1;
        // Add other cases for different centuries
        return ccode;
    }
};
class yearremainder : public centurycode{
public:
    int getyear(){
        return year % 100;
    }
    int operator%(int divisor){
        return year % divisor;
    }
};

class yearremainder2 : public yearremainder{
public:
    int caluculatequotient(int year){// quotient
        return year % 100 / 4;
    }
};

class Selection : public yearremainder2{
protected:
    int dayOfWeek;
    friend void printDetails(Selection &obj);
    int calculateDay(){
        int a = getdate();
        int b = monthextraction();
        int dVal = getyear();
        int e = caluculatequotient(getyear());
        int f = getcentury(getyear());

        dayOfWeek = (a + b + dVal + e + f) % 7;

        return dayOfWeek;
    }
};

void printDetails(Selection &obj){
    cout<<"These are the key values for the above date \n";
    cout << "Date: " << obj.getdate() << endl;
    cout << "Month Code: " << obj.monthextraction() << endl;
    cout << "Year: " << obj.getyear() << endl;
    cout << "Century Code: " << obj.getcentury(obj.year) << endl;
    cout << "Quotient: " << obj.caluculatequotient(obj.year) << endl;
    cout<<"By adding all of them we get "<< obj.getdate()+obj.monthextraction()+obj.getyear()+obj.getcentury(obj.year)+obj.caluculatequotient(obj.year) ;
    cout<<"\nThe remainder obtained by dividing it with 7 produces the answer\n";
}

bool checkLeap(int year){
    if (year % 100 == 0){
        if (year % 400 == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if (year % 4 == 0){
            return true;
        }
        else{
            return false;
        }
    }
}

bool checkDate(int year, int month, int date, bool leap){
    if (month > 13){
        return false;
    }
    if (leap){
        if (month == 2){
            if (date >= 1 && date <= 29){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if (month <= 7){
                if (month % 2 == 1){
                    if (date >= 1 && date <= 31){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if (date >= 1 && date <= 30){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                if (month % 2 == 1){
                    if (date >= 1 && date <= 30){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if (date >= 1 && date <= 31){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
    }
    else{
        if (month == 2){
            if (date >= 1 && date <= 28){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if (month <= 7){
                if (month % 2 == 1){
                    if (date >= 1 && date <= 31){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if (date >= 1 && date <= 30){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                if (month % 2 == 1){
                    if (date >= 1 && date <= 30){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if (date >= 1 && date <= 31){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
    }
}

class tofindday : public Selection{
private:
    static int checkCount;

public:
    string getday(){
        calculateDay();
        if (dayOfWeek == 0){
            return "sunday";
        }
        else if (dayOfWeek == 1){
            return "monday";
        }
        else if (dayOfWeek == 2){
            return "tuesday";
        }
        else if (dayOfWeek == 3){
            return "wednesday";
        }
        else if (dayOfWeek == 4){
            return "thursday";
        }
        else if (dayOfWeek == 5){
            return "friday";
        }
        else{
            return "saturday";
        }
    }
    static int getCheckCount(){
        return checkCount;
    }
    // Function to increment the check count
    static void incrementCheckCount(){
        checkCount++;
    }
};

int tofindday::checkCount = 0;
int main(){
    cout << "This sevrvice will provide You the day of the the given date----\n";
    while (1)
    {
        tofindday obj;

        cout << "Enter date: ";
        cin >> obj.date;
        cout << "Enter the month: ";
        cin >> obj.month;
        cout << "Enter year: ";
        cin >> obj.year;
        bool leap = checkLeap(obj.year);

        // Check if the date is valid before calculating and printing the day
        if (checkDate(obj.year, obj.month, obj.date, checkLeap(obj.year))){
            // printDetails(obj);
            cout << "Day of the week: " << obj.getday() << endl;
        }
        else{
            cout << "Invalid date!" << endl;
        }
        if (checkLeap(obj.year)){
            cout << "You are born in a leap year";
        }
        else
            cout << "not born in leap year\n";
        tofindday::incrementCheckCount();
        cout << endl;
        char k;
        cout << "Do You Want To Know Our Calculation ? (Press any key for Yes / 0 for No) ";
        cin>>k;
        if(k!='0'){
            cout<<"Date you Entered : "<<obj.date<<" / "<<obj.month<<" / "<<obj.year<<"\n";
            printDetails(obj);
        }
        char ch;

        cout << "Do you want to check for another data ? (press 1 for Yes / 0 for No) : ";
        cin >> ch;
        if (ch == '0')
            break;
    }
    cout << "You use our service for " << tofindday::getCheckCount() << " times";

    return 0;
}
