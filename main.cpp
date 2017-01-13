#include <iostream>
#include<windows.h>
#include<math.h>
#include<string.h>

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
    cout<<"9. Presiune"<<endl;
    cout<<"10. Densitate"<<endl;
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
    cout<<"Selectati un numar corespunzator unitati de masura din care doriti sa transformati"<<endl;
    UnitatiLungime();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,10,dinCe)!=1){if(dinCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
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


    cout<<"Selectati un numar corespunzator unitati de masura in care doriti sa transformati"<<endl;
    UnitatiLungime();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,10,inCe)!=1){if(inCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
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
    cout<<"Selectati un numar corespunzator unitati de masura din care doriti sa transformati"<<endl;
    UnitatiArie();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,10,dinCe)!=1){if(dinCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
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


    cout<<"Selectati un numar corespunzator unitati de masura in care doriti sa transformati"<<endl;
    UnitatiArie();
    int inCe;
    cin>>inCe;
    while(alegereUnitate(1,10,inCe)!=1){if(inCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
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
    cout<<"Selectati un numar corespunzator unitati de masura din care doriti sa transformati"<<endl;
    UnitatiVolum();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,10,dinCe)!=1){if(dinCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
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
    while(alegereUnitate(1,10,inCe)!=1){if(inCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
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
     cout<<"Selectati un numar corespunzator unitati de masura din care doriti sa transformati"<<endl;
    UnitatiTimp();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,4,dinCe)!=1){if(dinCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in secunde */

    if(dinCe==2){initial=initial*60;}
    if(dinCe==3){initial=initial*3600;}
    if(dinCe==4){initial=initial*86400;}


    cout<<"Selectati un numar corespunzator unitati de masura in care doriti sa transformati"<<endl;
    UnitatiTimp();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,4,inCe)!=1){if(inCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
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
     cout<<"Selectati un numar corespunzator unitati de masura din care doriti sa transformati"<<endl;
    UnitatiViteza();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,6,dinCe)!=1){if(dinCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
                                        cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in secunde */

    if(dinCe==2){initial=initial/3.600000;}
    if(dinCe==3){initial=initial/2.236936;}
    if(dinCe==4){initial=initial/3937.008;}
    if(dinCe==5){initial=initial/1.943844;}
    if(dinCe==6){initial=initial*340.2900;}


    cout<<"Selectati un numar corespunzator unitati de masura in care doriti sa transformati"<<endl;
    UnitatiViteza();
    int inCe;
    cin>>inCe;

   while(alegereUnitate(1,6,inCe)!=1){if(inCe==0){ cout<<"Cerere invalida!!!";
                                                        return ;
                                                        }
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


void parcurgereMeniu()
{   meniu();
    int x;
    cin>>x;
    while(alegereUnitate(1,11,x)!=1){ cout<<"Ati tastat gresit. Pentru a incerca din nou apasati tasta Enter"<<endl;
                                        cout<<"Alegere:";
                                        cin>>x;
                                        cout<<endl;
                                        }
    ClearScreen();
    if(x==1)Lungime();
    if(x==2) Arie();
    if(x==3) Volum();
    if(x==4) Timp();
    if(x==5) Viteza();
    }



int main()
{

    parcurgereMeniu();
    return 0;
}
