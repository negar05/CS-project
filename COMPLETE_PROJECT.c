#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main();
void age();
void Gregorian();
void conversion();

void invalid(){
    system("cls");
    printf("\ninvalid input!\n");
    sleep(2);
}

void menu()
{
    system("cls");
    printf("\nback to menu!\n");
    sleep(2);
}

void calendar()
{
    system("cls");
    int year, month;
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("----------------------------------\n");
    printf("enter year: ");
    scanf("%d", &year);
    if (year == 0)
    {
        system("cls");
        menu();
        main();
    }
    else if (year < 1206 || year > 1498)
    {
        system("cls");
        invalid();
        calendar();
    }
    printf("enter month: ");
    scanf("%d", &month);
    if (month == 0)
    {
        system("cls");
        menu();
        main();
    }
    else if (month > 12 || month < 1)
    {
        system("cls");
        invalid();
        calendar();
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////

    int yearsPassed = year - 1206;
    int fiveYears;
    if (year < 1210)
    {
        fiveYears = 0;
    }
    else
    {
        fiveYears = 1 + (yearsPassed - 4) / 33;
    }
    int fourYears = (yearsPassed - (fiveYears * 5)) / 4;
    int leapYears = fourYears + fiveYears;
    int monthdays;
    if (month <= 7)
    {
        monthdays = (month - 1) * 31;
    }
    else
    {
        monthdays = ((month - 1) - 6) * 30 + 6 * 31;
    }
    int remainder = (yearsPassed * 365 + leapYears + monthdays) % 7;
    int noemah;
    if (month <= 6)
    {
        noemah = 31;
    }
    else if (month == 12 && (yearsPassed - 4) % 33 != 0 && ((yearsPassed - 4) % 33) % 4 != 0)
    {
        noemah = 29;
    }
    else
    {
        noemah = 30;
    }
    int date = 0;
    int m = 0;
    int i = 0;
    if (remainder >= 2)
    {
        remainder -= 2;
    }
    else
    {
        remainder += 5;
    }
    system("cls");
    printf("year : %d\nmonth : %d\n", year, month);
    switch (month)
    {
    case 1:
        printf("        FARVARDIN\n");
        break;
    case 2:
        printf("        ORDIBEHESHT\n");
        break;
    case 3:
        printf("         KHORDAD\n");
        break;
    case 4:
        printf("           TIR\n");
        break;
    case 5:
        printf("          MORDAD\n");
        break;
    case 6:
        printf("        SHAHRIVAR\n");
        break;
    case 7:
        printf("           MEHR\n");
        break;
    case 8:
        printf("           ABAN\n");
        break;
    case 9:
        printf("           AZAR\n");
        break;
    case 10:
        printf("           DEY\n");
        break;
    case 11:
        printf("          BAHMAN\n");
        break;
    case 12:
        printf("          ESFAND\n");
        break;
    }
    printf("SH  YK  DO  SE  CH  PN  JM\n");
    for (; date < noemah; i++)
    {
        for (int j = 1; j <= 7 && date < noemah; j++)
        {
            for (; m < remainder; m++)
            {
                printf("    ");
                j++;
                if (j == 8)
                {
                    printf("\n");
                    j = 1;
                }
            }
            printf("%02d  ", ++date);
        }
        printf("\n");
    }
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("[1] Back to calendar\n");
    printf("----------------------------------\n");
    int again;
    scanf("%d", &again);
    if (again == 1)
    {
        calendar();
    }
    else if (again == 0)
    {
        main();
    }
    else
    {
        invalid();
        menu();
        main();
    }
}
int Tyear;
int Tmonth;
int Tday;
void birthday(int remainder)
{
    switch (remainder)
    {
    case 0:
        printf("Shoma PANJSHANBE be donya Omadid!\n");
        break;
    case 1:
        printf("Shoma JOME be donya Omadid!\n");
        break;
    case 2:
        printf("Shoma SHANBE be donya Omadid!\n");
        break;
    case 3:
        printf("Shoma YEKSHANBE be donya Omadid!\n");
        break;
    case 4:
        printf("Shoma DOSHANBE be donya Omadid!\n");
        break;
    case 5:
        printf("Shoma SESHANBE be donya Omadid!\n");
        break;
    case 6:
        printf("Shoma CHAHARSHNBE be donya Omadid!\n");
        break;
    }
    printf("select option: ");
    int again;
    scanf("%d", &again);
    if (again == 1)
    {
        age();
    }
    else if (again == 0)
    {
        main();
    }
    else
    {
        invalid();
        menu();
        main();
    }
}
int daysleft(int Byear, int Bmonth, int Bday)
{
    int yearspassed = Byear - 1206;
    int fiveyears = 1 + (yearspassed - 4) / 33;
    int fouryears = (yearspassed - (fiveyears * 5)) / 4;
    int leapyears = fouryears + fiveyears;
    int Bmonthdays;
    if (Bmonth <= 7)
    {
        Bmonthdays = (Bmonth - 1) * 31;
    }
    else
    {
        Bmonthdays = ((Bmonth - 1) - 6) * 30 + 6 * 31;
    }
    int remainder = (yearspassed * 365 + leapyears + Bmonthdays + (Bday - 1)) % 7;
    return remainder;
}
void age()
{
    int Byear, Bmonth, Bday;
    system("cls");
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("[1] Back to age\n");
    printf("----------------------------------\n");
    printf("Enter current year : ");
    scanf("%d", &Tyear);
    if (Tyear == 0)
    {
        main();
    }
    if (Tyear == 1)
    {
        age();
    }
    printf("Enter current month : ");
    scanf("%d", &Tmonth);
    if (Tmonth == 0)
    {
        main();
    }
    if (Tmonth == 1)
    {
        age();
    }
    printf("Enter current day : ");
    scanf("%d", &Tday);
    if (Tday == 0)
    {
        main();
    }
    if (Tday == 1)
    {
        age();
    }
    system("cls");

    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("----------------------------------\n");

    printf("Enter your birth year : ");
    scanf("%d", &Byear);
    if (Byear == 0)
    {
        main();
    }
    if (Byear < 1206)
    {
        system("cls");
        invalid();
        system("cls");
        age();
    }
    printf("Enter your birth month : ");
    scanf("%d", &Bmonth);
    if (Bmonth == 0)
    {
        main();
    }
    if (Bmonth > 12)
    {
        system("cls");
        invalid ();
        system("cls");
        printf("\nback to age!\n");
        sleep(2);
        age();
    }
    printf("Enter your birth day : ");
    scanf("%d", &Bday);
    if (Bday == 0)
    {
        main();
    }
    if (Bday > 31 || (Bday > 30 && Bmonth > 7))
    {
        system("cls");
        invalid ();
        system("cls");
        printf("\nback to age!\n");
        sleep(2);
        age();
    }
    int years = Tyear - Byear;
    int months = Tmonth - Bmonth;
    int days = Tday - Bday;
    if (days < 0)
    {
        months -= 1;
        days += 30;
    }
    if (months < 0)
    {
        years -= 1;
        months += 12;
    }
    system("cls");
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("[1] Back to age\n");
    printf("----------------------------------\n");
    printf("%d years & %d months & %d days passed!", years, months, days);
    int passeddays = (years / 4) + years * 365 + months * 30 + days;
    printf("\n%d days passed!\n", passeddays);
    birthday(daysleft(Byear, Bmonth, Bday));
}
void Lunar()
{
    int syear, smonth, sday;
    int lyear, lmonth, lday;

    system("cls");
    printf("Solar to Lunar conversion!\n");
    printf("----------------------------------\n");
    printf("Enter Year:");
    scanf("%d", &syear);
    if (syear < 1206){
        invalid();
        system("cls");
        conversion();
    }
    printf("Enter month:");
    scanf("%d", &smonth);
    if (smonth > 12){
        invalid();
        system("cls");
        conversion();
    }
    printf("Enter day:");
    scanf("%d", &sday);
    if ((sday > 30 && smonth > 6) || sday > 31 || (sday > 29 && smonth == 12))
    {
        invalid();
        system("cls");
        conversion();
    }
    system("cls");
    printf("Solar to Lunar conversion!\n");
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("[1] Solar to Lunar\n");
    printf("[2] Solar to Gregorian\n");
    printf("----------------------------------\n");
    
    lday = sday + 8;
    lmonth = smonth + 8;
    lyear = syear + 42;
    int x = (1500 - syear) * 11;
    lday -= x;
    int count = 0;
    while (lday < 0)
    {
        lday += 30;
        lmonth -= 1;
        if (count % 2 == 1)
        {
            lday -= 1;
            count++;
        }
    }
    while (lmonth > 12)
    {
        lmonth -= 12;
        lyear += 1;
    }
    if (lmonth > 12 && lday > 30)
    {
        lday -= 30;
        lmonth += 1;
    }
    else if (lmonth > 12)
    {
        lmonth -= 12;
        lyear += 1;
    }
    else if (lday > 30 && (lmonth % 2 == 0))
    {
        lday -= 30;
        lmonth += 1;
        if (lmonth > 12)
        {
            lmonth -= 12;
            lyear += 1;
        }
    }
    else if (lday > 29 && (lmonth % 2 == 1))
    {
        lday -= 29;
        lmonth += 1;
    }
    printf("%04d/%02d/%02d\n", lyear, lmonth, lday);
    printf("select option: ");
    int towhat;
    scanf("%d", &towhat);
    if (towhat == 2)
    {
        Gregorian();
    }
    else if (towhat == 1)
    {
        Lunar();
    }
    else if (towhat == 0)
    {
        main();
    }
}
void Gregorian()
{

    int syear, smonth, sday;
    int gyear, gmonth, gday;
    system("cls");
    printf("Solar to Gregorian conversion!\n");
    printf("----------------------------------\n");
    printf("Enter Year:");
    scanf("%d", &syear);
    if (syear < 1206){
        invalid();
        Gregorian();
    }
    printf("Enter month:");
    scanf("%d", &smonth);
    if (smonth > 12){
        invalid();
        Gregorian();
    }
    printf("Enter day:");
    scanf("%d", &sday);
    if ((sday > 30 && smonth > 6) || sday > 31 || (sday > 29 && smonth == 12))
    {
        invalid();
        Gregorian();
    }
    system("cls");
    printf("Solar to Gregorian conversion!\n");
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("[1] Solar to Gregorian\n");
    printf("[2] Solar to Lunar\n");
    printf("----------------------------------\n");
    
    gday = sday + 19;
    gmonth = smonth + 2;
    gyear = syear + 621;
    switch (smonth)
    {
    case 1:
        gday += 1;
        break;
    case 2:
        gday += 1;
        break;
    case 3:
        gday += 2;
        break;
    case 4:
        gday += 2;
        break;
    case 5:
        gday += 3;
        break;
    case 6:
        gday += 3;
        break;
    case 7:
        gday += 3;
        break;
    case 8:
        gday += 3;
        break;
    case 9:
        gday += 2;
        break;
    case 10:
        gday += 2;
        break;
    case 11:
        gday += 1;
        break;
    }

    ///////////////////////////////////////////
    if ((gmonth == 4 || gmonth == 6 || gmonth == 9 || gmonth == 11) && gday > 30)
    {
        gday -= 30;
        gmonth += 1;
    }
    else if ((gmonth == 1 || gmonth == 3 || gmonth == 5 || gmonth == 7 || gmonth == 8 || gmonth == 10 || gmonth == 12) && gday > 31)
    {
        gday -= 31;
        gmonth += 1;
    }
    else if (gmonth == 2 && gday > 28)
    {
        gday -= 28;
        gmonth += 1;
    }
    if (gmonth > 12 && gday > 31)
    {
        gday -= 31;
        gmonth += 1;
        gmonth -= 12;
        gyear += 1;
    }
    else if (gmonth > 12)
    {
        gmonth -= 12;
        gyear += 1;
    }
    printf("%04d/%02d/%02d\n", gyear, gmonth, gday);
    printf("select option: ");
    int towhat;
    scanf("%d", &towhat);
    if (towhat == 1)
    {
        Gregorian();
    }
    else if (towhat == 2)
    {
        Lunar();
    }
    else if (towhat == 0)
    {
        main();
    }
}
void conversion()
{
    system("cls");
    ////
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("[1] Solar to Gregorian\n");
    printf("[2] Solar to Lunar\n");
    printf("----------------------------------\n");
    int towhat;
    scanf("%d", &towhat);
    if (towhat == 1)
    {
        Gregorian();
    }
    else if (towhat == 2)
    {
        Lunar();
    }
    else if (towhat == 0)
    {
        main();
    }
}
void differance(){
    system("cls");
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("----------------------------------\n");
    int myyear,mymonth,myday;
    int heryear,hermonth,herday;
    printf ("Enter your birth year : ");
    scanf ("%d",&myyear);
    if (myyear > 1402 || myyear < 1206){
        system("cls");
        invalid();
        system("cls");
        differance();

    }
    if (myyear == 0){
        system("cls");
        menu ();
        main ();

    }
    printf ("Enter your birth month : ");
    scanf ("%d",&mymonth);
    if (mymonth == 0){
        system("cls");
        menu ();
        main ();
    }
    if (mymonth > 12 || mymonth < 1){
        system("cls");
        invalid();
        system("cls");
        differance();
    }
    printf ("Enter your birth day : ");
    scanf ("%d",&myday);
    if (myday == 0){
        system("cls");
        menu ();
        main ();
    }
    if ((myday > 30 && mymonth > 6) || myday > 31 || (myday > 29 && mymonth == 12)){
        system("cls");
        invalid();
        system("cls");
        differance();
    }
    /////////////////////////////////////////////////////////////////////////////////////////////
    
    system("cls");
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("----------------------------------\n");


    printf ("Enter her birth year : ");
    scanf ("%d",&heryear);
    if (heryear > 1402 || heryear < 1206){
        system("cls");
        invalid();
        system("cls");
        differance();

    }
    printf ("Enter her birth month : ");
    scanf ("%d",&hermonth);
    if (hermonth == 0){
        differance();
    }
    if (hermonth > 12 || hermonth < 1){
        system("cls");
        invalid();
        system("cls");
        differance();
    }
    printf ("Enter her birth day : ");
    scanf ("%d",&herday);
    if (herday == 0){
        differance();
    }
    if ((herday > 30 && hermonth > 6) || herday > 31 || (herday > 29 && hermonth == 12)){
        system("cls");
        invalid();
        system("cls");
        differance();
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////
    int years,months,days;
    if (myyear > heryear ){
        years = myyear - heryear;
        months = mymonth - hermonth;
        days = myday - herday;
        if (days < 0){
            days += 30;
            months -= 1;
        }
        if (months < 0){
            months += 12;
            years -= 1;
        }
        
        
    }
    else {
        years = heryear - myyear;
        months = hermonth - mymonth;
        days = herday - myday;
        if (days < 0){
            days += 30;
            months -= 1;
        }
        if (months < 0){
            months += 12;
            years -= 1;
        }
    }
    
    system("cls");
    printf("----------------------------------\n");
    printf("[0] Back to menu\n");
    printf("----------------------------------\n");
    
    printf("%dyears && %d months && %d days\n", years, months, days);
    printf("select option: ");
    int towhat;
    scanf("%d", &towhat);
    if (towhat == 0)
    {
        system("cls");
        menu ();
        main ();
    }

}
int main()
{
    system("cls");
    printf("[0] Quit\n[1] Calendar\n[2] Age\n[3] Conversion\n[4] differance\n");
    printf("----------------------------------\n");
    printf("select option: ");
    int option;
    scanf("%d", &option);
    system("cls");

    switch (option)
    {
    case 0:
        printf("\nBye!\n");
        return 0;
    case 1:
        calendar();
        break;
    case 2:
        age();
        break;
    case 3:
        conversion();
        break;
    case 4:
        differance();
        break;
    default:
        printf("Invalid input!\n");
        break;
    }

    return 0;
}
