#include <iostream>
#include<windows.h>
#include<math.h>
#include<string.h>
#include<limits>

using namespace std;

void ClearScreen()
{
    HANDLE                                   hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                                    count;
    DWORD                                    cellCount;
    COORD                                    homeCoords = { 0, 0 };
    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;
/* Obține numărul de celule din buffer-ul curent */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;
/* Umple întregul buffer cu spații */
    if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
        &count
    )) return;
/* Umple întregul buffer cu culorile curente și atributele */
    if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;
/* Muta cursorul acasă */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}

void meniu()
{
    cout<< "Selectati un numar corespunzator unei marimi fizica de mai jos:"<<endl;
    cout<<"1. Lungime"<<endl;
    cout<<"2. Arie"<<endl;
    cout<<"3. Volum"<<endl;
    cout<<"4. Timp"<<endl;
    cout<<"5. Viteza"<<endl;
    cout<<"6. Temperatura"<<endl;
    cout<<"7. Masa"<<endl;
    cout<<"8. Energie"<<endl;
    cout<<"9. Densitate"<<endl;
    cout<<"10. Presiune"<<endl;
    cout<<"11. Consum combustibil"<<endl;
}

void UnitatiLungime()
{
    cout<<"1. mm"<<endl;
    cout<<"2. cm"<<endl;
    cout<<"3. dm"<<endl;
    cout<<"4. m"<<endl;
    cout<<"5. dam"<<endl;
    cout<<"6. hm"<<endl;
    cout<<"7. km"<<endl;
    cout<<"8. inch"<<endl;
    cout<<"9. ft"<<endl;
    cout<<"10. yd"<<endl;
}

bool alegereUnitate(unsigned x,unsigned y, unsigned alegere)
{
    if (alegere>=x &&alegere<=y){return 1;}
    return 0;
}


void Lungime()
{
    cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiLungime();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,10,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in metri */
    if(dinCe<4){initial=initial/pow(10,4-dinCe);}
        else {
                if(dinCe<=7){initial=initial*pow(10,dinCe-4);}
              }
    if(dinCe==8){initial=initial/39.37007;}
    if(dinCe==9){initial=initial/3.28083;}
    if(dinCe==10){initial=initial/1.0936;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiLungime();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,10,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe<4){finall=initial*pow(10,4-inCe);}
        else {
                if(inCe<=7){finall=initial/pow(10,inCe-4);}
              }
    if(inCe==8){finall=initial*39.37007;}
    if(inCe==9){finall=initial*3.28083;}
    if(inCe==10){finall=initial*1.0936;}

    /* Afisarea */

    ClearScreen();
    char s[11][5];
    strcpy(s[1],"mm");strcpy(s[2],"cm");strcpy(s[3],"dm");strcpy(s[4],"m");strcpy(s[5],"dam");strcpy(s[6],"hm");
    strcpy(s[7],"km");strcpy(s[8],"inch");strcpy(s[9],"ft");strcpy(s[10],"yd");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void UnitatiArie ()
{
    cout<<"1. mm^2"<<endl;
    cout<<"2. cm^2"<<endl;
    cout<<"3. dm^2"<<endl;
    cout<<"4. m^2"<<endl;
    cout<<"5. dam^2"<<endl;
    cout<<"6. hm^2"<<endl;
    cout<<"7. km^2"<<endl;
    cout<<"8. inch^2"<<endl;
    cout<<"9. ft^2"<<endl;
    cout<<"10. yd^2"<<endl;
}


void Arie ()
{
    cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiArie();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,10,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in metri^2 */
    if(dinCe<4){initial=initial/pow(pow(10,4-dinCe),2);}
        else {
                if(dinCe<=7){initial=initial*pow(pow(10,4-dinCe),2);}
              }
    if(dinCe==8){initial=initial/1550.003;}
    if(dinCe==9){initial=initial/10.76391;}
    if(dinCe==10){initial=initial/1.1960;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiArie();
    int inCe;
    cin>>inCe;
    while(alegereUnitate(1,10,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe<4){finall=initial*pow(pow(10,4-inCe),2);}
        else {
                if(inCe<=7){finall=initial/pow(pow(10,4-inCe),2);}
              }
    if(inCe==8){finall=initial*1550.003;}
    if(inCe==9){finall=initial*10.76391;}
    if(inCe==10){finall=initial*1.1960;}

    /* Afisarea */

    ClearScreen();
    char s[11][7];
    strcpy(s[1],"mm^2");strcpy(s[2],"cm^2");strcpy(s[3],"dm^2");strcpy(s[4],"m^2");strcpy(s[5],"dam^2");strcpy(s[6],"hm^2");
    strcpy(s[7],"km^2");strcpy(s[8],"inch^2");strcpy(s[9],"ft^2");strcpy(s[10],"yd^2");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}


void UnitatiVolum ()
{
    cout<<"1. mm^3"<<endl;
    cout<<"2. cm^3"<<endl;
    cout<<"3. dm^3"<<endl;
    cout<<"4. m^3"<<endl;
    cout<<"5. dam^3"<<endl;
    cout<<"6. hm^3"<<endl;
    cout<<"7. km^3"<<endl;
    cout<<"8. inch^3"<<endl;
    cout<<"9. ft^3"<<endl;
    cout<<"10. yd^3"<<endl;
}


void Volum ()
{
    cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiVolum();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,10,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in metri^3 */
    if(dinCe<4){initial=initial/pow(pow(10,4-dinCe),3);}
        else {
                if(dinCe<=7){initial=initial*pow(pow(10,4-dinCe),3);}
              }
    if(dinCe==8){initial=initial/61023.74;}
    if(dinCe==9){initial=initial/35.31467;}
    if(dinCe==10){initial=initial/1.307951;}


    cout<<"Selectati un numar corespunzator de masura in care doriti sa transformati"<<endl;
    UnitatiVolum();
    int inCe;
    cin>>inCe;
    while(alegereUnitate(1,10,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe<4){finall=initial*pow(pow(10,4-inCe),3);}
        else {
                if(inCe<=7){finall=initial/pow(pow(10,4-inCe),3);}
              }
    if(inCe==8){finall=initial*61023.74;}
    if(inCe==9){finall=initial*35.31467;}
    if(inCe==10){finall=initial*1.307951;}

    /* Afisarea */

    ClearScreen();
    char s[11][7];
    strcpy(s[1],"mm^3");strcpy(s[2],"cm^3");strcpy(s[3],"dm^3");strcpy(s[4],"m^3");strcpy(s[5],"dam^3");strcpy(s[6],"hm^3");
    strcpy(s[7],"km^3");strcpy(s[8],"inch^3");strcpy(s[9],"ft^3");strcpy(s[10],"yd^3");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}


void UnitatiTimp ()
{
    cout<<"1. s"<<endl;
    cout<<"2. min"<<endl;
    cout<<"3. hr"<<endl;
    cout<<"4. day"<<endl;
}

void Timp ()
{
     cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiTimp();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,4,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in secunde */

    if(dinCe==2){initial=initial*60;}
    if(dinCe==3){initial=initial*3600;}
    if(dinCe==4){initial=initial*86400;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiTimp();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,4,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe==1){finall=initial;}
    if(inCe==2){finall=initial/60;}
    if(inCe==3){finall=initial/3600;}
    if(inCe==4){finall=initial/86400;}

    /* Afisarea */

    ClearScreen();
    char s[5][4];
    strcpy(s[1],"s");strcpy(s[2],"min");strcpy(s[3],"hr");strcpy(s[4],"day");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void UnitatiViteza ()
{
    cout<<"1. m/s"<<endl;
    cout<<"2. km/h"<<endl;
    cout<<"3. mph"<<endl;
    cout<<"4. yd/h"<<endl;
    cout<<"5. knots"<<endl;
    cout<<"6. Mach"<<endl;
}

void Viteza ()
{
     cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiViteza();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,6,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in metri pe secunda */

    if(dinCe==2){initial=initial/3.600000;}
    if(dinCe==3){initial=initial/2.236936;}
    if(dinCe==4){initial=initial/3937.008;}
    if(dinCe==5){initial=initial/1.943844;}
    if(dinCe==6){initial=initial*340.2900;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiViteza();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,6,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe==1){finall=initial;}
    if(inCe==2){finall=initial*3.600000;}
    if(inCe==3){finall=initial*2.236936;}
    if(inCe==4){finall=initial*3937.008;}
    if(inCe==5){finall=initial*1.943844;}
    if(inCe==6){finall=initial/340.2900;}

    /* Afisarea */

    ClearScreen();
    char s[7][6];
    strcpy(s[1],"m/s");strcpy(s[2],"km/h");strcpy(s[3],"mph");strcpy(s[4],"yd/h");
    strcpy(s[5],"knots");strcpy(s[6],"Mach");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void UnitatiTemperatura ()
{
    cout<<"1. C"<<endl;
    cout<<"2. F"<<endl;
    cout<<"3. K"<<endl;
    cout<<"4. R"<<endl;
}

void Temperatura ()
{
     cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiTemperatura();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,4,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in secunde */

    if(dinCe==2){initial=(initial-32)/1.8000;}
    if(dinCe==3){initial=initial- 273.15;}
    if(dinCe==4){initial=(initial-491.67)/1.800000;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiTemperatura();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,4,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe==1){finall=initial;}
    if(inCe==2){finall=(initial*1.8000)+32;}
    if(inCe==3){finall=initial+273.15;}
    if(inCe==4){finall=(initial*1.800000)+491.67;}

    /* Afisarea */

    ClearScreen();
    char s[5][2];
    strcpy(s[1],"C");strcpy(s[2],"F");strcpy(s[3],"K");strcpy(s[4],"R");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void UnitatiMasa()
{
    cout<<"1. mg"<<endl;
    cout<<"2. cg"<<endl;
    cout<<"3. dg"<<endl;
    cout<<"4. g"<<endl;
    cout<<"5. dag"<<endl;
    cout<<"6. hg"<<endl;
    cout<<"7. kg"<<endl;
    cout<<"8. lb"<<endl;
    cout<<"9. oz"<<endl;
    cout<<"10. t"<<endl;
}

void Masa()
{
    cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiMasa();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,10,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in grame */
    if(dinCe<4){initial=initial/pow(10,4-dinCe);}
        else {
                if(dinCe<=7){initial=initial*pow(10,dinCe-4);}
              }
    if(dinCe==8){initial=initial*453.592;}
    if(dinCe==9){initial=initial*28.34952;}
    if(dinCe==10){initial=initial*1000000;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiMasa();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,10,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe<4){finall=initial*pow(10,4-inCe);}
        else {
                if(inCe<=7){finall=initial/pow(10,inCe-4);}
              }
    if(inCe==8){finall=initial/453.592;}
    if(inCe==9){finall=initial/28.34952;}
    if(inCe==10){finall=initial/1000000;}

    /* Afisarea */

    ClearScreen();
    char s[11][5];
    strcpy(s[1],"mg");strcpy(s[2],"cg");strcpy(s[3],"dg");strcpy(s[4],"g");strcpy(s[5],"dag");strcpy(s[6],"hg");
    strcpy(s[7],"kg");strcpy(s[8],"lb");strcpy(s[9],"oz");strcpy(s[10],"t");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void UnitatiEnergie ()
{
    cout<<"1. J"<<endl;
    cout<<"2. kJ"<<endl;
    cout<<"3. W/s"<<endl;
    cout<<"4. W/h"<<endl;
    cout<<"5. erg"<<endl;
    cout<<"6. cal"<<endl;
    cout<<"7. kcal"<<endl;

}

void Energie ()
{
     cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiEnergie();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,7,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in Jouli */

    if(dinCe==2){initial=initial*1000;}
    if(dinCe==4){initial=initial*3600;}
    if(dinCe==5){initial=initial/10000000;}
    if(dinCe==6){initial=initial*4.1868;}
    if(dinCe==7){initial=initial*4186.8;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiEnergie ();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,7,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe==1){finall=initial;}
    if(inCe==2){finall=initial/1000;}
    if(inCe==3){finall=initial;}
    if(inCe==4){finall=initial/3600;}
    if(inCe==5){finall=initial*10000000;}
    if(inCe==6){finall=initial/4.1868;}
    if(inCe==7){finall=initial/4186.8;}

    /* Afisarea */

    ClearScreen();
    char s[8][5];
    strcpy(s[1],"J");strcpy(s[2],"kJ");strcpy(s[3],"W/s");strcpy(s[4],"W/h");
    strcpy(s[5],"erg");strcpy(s[6],"cal");strcpy(s[7],"kcal");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void UnitatiDensitate ()
{
    cout<<"1. kg/m^3"<<endl;
    cout<<"2. g/l"<<endl;
    cout<<"3. g/m^3"<<endl;
    cout<<"4. kg/l"<<endl;
    cout<<"5. mg/cm^3"<<endl;
    cout<<"6. mg/l"<<endl;
    cout<<"7. lb/in^3"<<endl;
    cout<<"8. t/m^3"<<endl;

}

void Densitate ()
{
     cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiDensitate();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,8,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in kg/m^3 */

    if(dinCe==3){initial=initial/1000;}
    if(dinCe==4){initial=initial*1000;}
    if(dinCe==5){initial=initial/1000;}
    if(dinCe==6){initial=initial/1000;}
    if(dinCe==7){initial=initial*27679.89858;}
    if(dinCe==8){initial=initial*1000;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiDensitate();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,8,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe==1){finall=initial;}
    if(inCe==2){finall=initial;}
    if(inCe==3){finall=initial*1000;}
    if(inCe==4){finall=initial/1000;}
    if(inCe==5){finall=initial*1000;}
    if(inCe==6){finall=initial*1000;}
    if(inCe==7){finall=initial/27679.89858;}
    if(inCe==8){finall=initial/1000;}

    /* Afisarea */

    ClearScreen();
    char s[9][8];
    strcpy(s[1],"kg/m^3");strcpy(s[2],"g/l");strcpy(s[3],"g/m^3");strcpy(s[4],"kg/l");
    strcpy(s[5],"mg/cm^3");strcpy(s[6],"mg/l");strcpy(s[7],"lb/in^3");strcpy(s[8],"t/m^3");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void UnitatiConsumCombustibil ()
{
    cout<<"1. l/100km"<<endl;
    cout<<"2. km/l"<<endl;
    cout<<"3. mi/gal"<<endl;
    cout<<"4. gal/100mi"<<endl;
}

void ConsumCombustibil ()
{
     cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiConsumCombustibil();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,4,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in l/100km */

    if(dinCe==2){initial=initial/100;}
    if(dinCe==3){initial=initial/235.2;}
    if(dinCe==4){initial=initial*2.352;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiConsumCombustibil();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,4,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe==1){finall=initial;}
    if(inCe==2){finall=initial*100;}
    if(inCe==3){finall=initial*235.2;}
    if(inCe==4){finall=initial/2.352;}

    /* Afisarea */

    ClearScreen();
    char s[5][10];
    strcpy(s[1],"l/100km");strcpy(s[2],"km/l");strcpy(s[3],"mi/gal");strcpy(s[4],"gal/100mi");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void UnitatiPresiune ()
{
    cout<<"1. Pa"<<endl;
    cout<<"2. kPa"<<endl;
    cout<<"3. MPa"<<endl;
    cout<<"4. bar"<<endl;
    cout<<"5. N/mm^2"<<endl;
    cout<<"6. Torr"<<endl;
    cout<<"7. atm"<<endl;
    cout<<"8. PSI"<<endl;

}

void Presiune ()
{
     cout<<"Selectati un numar corespunzator unitatii de masura din care doriti sa transformati"<<endl;
    UnitatiPresiune();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,8,dinCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    if(cin.good()==0){cout<<"Eroare, programul s-a oprit fiindca ati introdus ceva gresit.Cititi cu atentie data viitoare!";
                    return;}
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in Pa */

    if(dinCe==2){initial=initial*1000;}
    if(dinCe==3){initial=initial*1000000;}
    if(dinCe==4){initial=initial*98000;}
    if(dinCe==5){initial=initial*1000000;}
    if(dinCe==6){initial=initial*133.322368421;}
    if(dinCe==7){initial=initial*101325.2738;}
    if(dinCe==8){initial=initial*6894.75729317;}


    cout<<"Selectati un numar corespunzator unitatii de masura in care doriti sa transformati"<<endl;
    UnitatiPresiune();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,8,inCe)!=1){cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe==1){finall=initial;}
    if(inCe==2){finall=initial/1000;}
    if(inCe==3){finall=initial/1000000;}
    if(inCe==4){finall=initial/98000;}
    if(inCe==5){finall=initial/1000000;}
    if(inCe==6){finall=initial/133.322368421;}
    if(inCe==7){finall=initial/101325.2738;}
    if(inCe==8){finall=initial/6894.75729317;}

    /* Afisarea */

    ClearScreen();
    char s[9][7];
    strcpy(s[1],"Pa");strcpy(s[2],"kPa");strcpy(s[3],"MPa");strcpy(s[4],"bar");
    strcpy(s[5],"N/mm^2");strcpy(s[6],"Torr");strcpy(s[7],"atm");strcpy(s[8],"PSI");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void parcurgereMeniu()
{
    meniu();
    int x;
    cin>>x;
    while(alegereUnitate(1,11,x)!=1){cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                    cin>>x;
                                    cout<<endl;
                                    }
    ClearScreen();
    if(x==1)Lungime();
    if(x==2) Arie();
    if(x==3) Volum();
    if(x==4) Timp();
    if(x==5) Viteza();
    if(x==6) Temperatura();
    if(x==7) Masa();
    if(x==8) Energie();
    if(x==9) Densitate();
    if(x==10) Presiune();
    if(x==11) ConsumCombustibil();
    }

int main()
{
    parcurgereMeniu();
    return 0;
}
