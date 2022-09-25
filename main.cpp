#include <bits/stdc++.h>
#include <graphics.h>
#define infinit INT_MAX
#define epsi 0.0001
#define MAX1 20
#define MAX_NR 50
#define FUNDAL LIGHTGRAY
#define MAX 500
using namespace std;
int x1_coord_START=45,y1_coord_START=115,x2_coord_START=135,y2_coord_START=145,x1_coord_INPUT=35,y1_coord_INPUT=195,x2_coord_INPUT=125,y2_coord_INPUT=225;
int x1_coord_CALCUL=45,y1_coord_CALCUL=275,x2_coord_CALCUL=135,y2_coord_CALCUL=305,x1_coord_DECIZIE=85,y1_coord_DECIZIE=355,x2_coord_DECIZIE=150,y2_coord_DECIZIE=425;
int x1_coord_OUTPUT=55,y1_coord_OUTPUT=475,x2_coord_OUTPUT=145,y2_coord_OUTPUT=505,x1_coord_STOP=45,y1_coord_STOP=555,x2_coord_STOP=135,y2_coord_STOP=585;
int x1_coord_OPRIRE=15,y1_coord_OPRIRE=680,x2_coord_OPRIRE=165,y2_coord_OPRIRE=775;
int x1_coord_RUN=15,y1_coord_RUN=15,x2_coord_RUN=165,y2_coord_RUN=75;
int x1_coord_STERGERE=900,y1_coord_STERGERE=15,x2_coord_STERGERE=1085,y2_coord_STERGERE=75;

int lungimeBlocStart=x2_coord_START-x1_coord_START,latimeBlocStart=y2_coord_START-y1_coord_START;
int lungimeBlocInput=x2_coord_INPUT-x1_coord_INPUT,latimeBlocInput=y2_coord_INPUT-y1_coord_INPUT;
int lungimeBlocDecizie=x2_coord_DECIZIE-x1_coord_DECIZIE,latimeBlocDecizie=y2_coord_DECIZIE-y1_coord_DECIZIE;
int lungimeBlocOutput=x2_coord_OUTPUT-x1_coord_OUTPUT,latimeBlocOutput=y2_coord_OUTPUT-y1_coord_OUTPUT;
int lungimeBlocStop=x2_coord_STOP-x1_coord_STOP,latimeBlocStop=y2_coord_STOP-y1_coord_STOP;

int x_PORNIRE1=490,x_PORNIRE2=1070,y_PORNIRE1=390,y_PORNIRE2=450;
int x_SETARI1=490,x_SETARI2=1070,y_SETARI1=480,y_SETARI2=540;
int x_EXIT1=490,x_EXIT2=1070,y_EXIT1=570,y_EXIT2=630;

int k=0;
bool ok_schema_creata = 0, ok_schema_incarcata=0,ok_menu=0;
bool ok_cmath=0;//afisare biblioteca in cd C++
int vecLitere[27];
int culbk=12;
int culfundal=4;
char vecsemne[]= {'+','*','-','/','%','>','<','=','^'};
char s[MAX]="",rez[MAX]="";
int top1,top2; // varfurile celor doua stive
const int max_stiva=100;

double Opd[max_stiva]; // stiva operanzilor
char Op[max_stiva]; // stiva operatorilor

char OperatiiBinare[200]="+-*/^ < >= !~% ";
char OperatiiUnare[200] = "SCLEMR";
char Operatii[200] = "+-*/^<>=!&|scarel~%SCLEMR";


int Prioritate(char c)//Andrei  // prioritate operatorilor
{
    if (c == '(' || c == ')')
        return 0;
    if (c == '~')
        return 1;
    if (c == '+' || c == '-')
        return 2;
    if (c == '*' || c == '/' || c == '%')
        return 3;
    if (c == '^')
        return 4;
    if (c == '=' || c == '!' || c == '<' || c == '>')
        return 5;
    if (c == '&' || c == '|')
        return 6;
    if (c == 'C' || c == 'S' || c == 'L' || c == 'E' || c == 'T' || c == 'M' || c == 'R')
        return 7;
}

const float pi = 3.1415926; // se da sub forma literei q

bool DifInf(float x)//Andrei
{
    return fabs(infinit - fabs(x)) > infinit / 2.0;
}

float Logaritm(float x)//Andrei
{
    if (x > epsi && DifInf(x))
        return log(x);
    else
        return infinit;
}

float Exponential(float x)//Andrei
{
    if (DifInf(x)) return exp(x);
    else return infinit;
}

int Inmultit(int x, int y)//Andrei
{
    if (x == 0 || y == 0)
        return 0;
    else if (DifInf(x) && DifInf(y)) return x * y;
    else return infinit;
}

int Putere(int x, int y)//Andrei
{
    // float p;
    if (x == 0) return 0;
    else if (y == 0) return 1;
    else if (x == infinit || y == infinit) return infinit;
    else
    {
        for (int i = 2; i <= y; i++)
            x *= x;
        return x;
    }
}

int Egal(int x, int y)//Andrei
{
    return x == y;
}

int Diferit(int x, int y)//Andrei
{
    return x != y;
}
int Mod1(int x, int y)//Andrei
{
    return x % y;
}
int MaiMic(int x, int y)//Andrei
{
    return x < y;
}

int MaiMicegal(int x, int y)//Andrei
{
    return x <= y;
}

int MaiMare(int x, int y)//Andrei
{
    return x > y;
}
int MaiMareegal(int x, int y)//Andrei
{
    return x >= y;
}
int Si(int x, int y)//Andrei
{
    return (x && y);
}
int Sau(int x, int y)//Andrei
{
    return (x || y);
}
int negat(int x)//Andrei
{
    return !x;
}
float Plus(int x, float y)//Andrei
{
    if (DifInf(x) && DifInf(y))  return x + y;
    else return infinit;
}

float Minus(float x, float y)//Andrei
{
    if (DifInf(x) && DifInf(y))  return x - y;
    else return infinit;
}

float Impartit(float x, float y)//Andrei
{
    if (fabs(y) > epsi) return x / y;
    else return infinit;
}

float Sinus(float x)//Andrei
{
    if (DifInf(x))  return sin(x);
    else return infinit;
}

float Cosinus(float x)//Andrei
{
    if (DifInf(x))  return cos(x);
    else return infinit;
}

float Modul(float x)//Andrei
{
    if (x < 0) return -x;
    else return x;
}

float Radical(float x)//Andrei
{
    return sqrt(x);

}

bool EsteNumar(char sir[MAX1])//Andrei
{
    return (strchr("0123456789", sir[0]));
}

struct functie
{
    char expresie[300];
    char vect[MAX + 1][MAX1];
    // vectorul cuprinzand “cuvintele”ce formeaza expresia}
    int lung; // lungimea efectiva a vectorului
    float a, b; // intervalul de evaluare a functiei
    int n; //numarul de puncte de evaluare
};

void depanare()//Andrei
{
    printf("Stiva operanzilor: ");
    for (int i = 1; i <= top1; i++)
        printf("%f,", Opd[i]);
    printf("\nStiva operatorilor: ");
    for (int i = 1; i <= top2; i++)
        printf("%c,", Op[i]);
    printf("\n");
}

int ValoareFunctie(functie E)//Andrei
{
    int i;
    // returneaza valoarea functiei E in punctul x
    double valo, x_1, x_2;
    //calculul expresiei
    for (i = 1; i <= max_stiva; i++)
    {
        Opd[i] = 0;
        Op[i] = '@';
    }
    top1 = 0;
    top2 = 1;
    Op[top2] = '(';
    i = 0;
    while (i <= E.lung && top2 > 0)
    {
        i++;
        if (EsteNumar(E.vect[i]))
        {
            top1++;

            valo = atof(E.vect[i]);
            while (EsteNumar(E.vect[i + 1]))
            {

                i++;
                int aux;
                aux = atof(E.vect[i]);
                valo *= 10;
                valo += aux;
            }
            Opd[top1] = valo;

        }
        else
            switch (E.vect[i][0])
            {
            /* constanta pi=3.1415926 se da sub forma literei q */
            case 'q':
                top1++;
                Opd[top1] = pi;
                break;
            case 'a':
                top1++;
                Opd[top1] = vecLitere['a' - 'a'];
                break;
            case 'b':
                top1++;
                Opd[top1] = vecLitere['b' - 'a'];
                break;
            case 'c':
                top1++;
                Opd[top1] = vecLitere['c' - 'a'];
                break;
            case 'd':
                top1++;
                Opd[top1] = vecLitere['d' - 'a'];
                break;
            case 'e':
                top1++;
                Opd[top1] = vecLitere['e' - 'a'];
                break;
            case 'f':
                top1++;
                Opd[top1] = vecLitere['f' - 'a'];
                break;
            case 'g':
                top1++;
                Opd[top1] = vecLitere['g' - 'a'];
                break;
            case 'h':
                top1++;
                Opd[top1] = vecLitere['h' - 'a'];
                break;
            case 'i':
                top1++;
                Opd[top1] = vecLitere['i' - 'a'];
                break;
            case 'j':
                top1++;
                Opd[top1] = vecLitere['j' - 'a'];
                break;
            case 'k':
                top1++;
                Opd[top1] = vecLitere['k' - 'a'];
                break;
            case 'l':
                top1++;
                Opd[top1] = vecLitere['l' - 'a'];
                break;
            case 'm':
                top1++;
                Opd[top1] = vecLitere['m' - 'a'];
                break;
            case 'n':
                top1++;
                Opd[top1] = vecLitere['n' - 'a'];
                break;
            case 'o':
                top1++;
                Opd[top1] = vecLitere['o' - 'a'];
                break;
            case 'p':
                top1++;
                Opd[top1] = vecLitere['p' - 'a'];
                break;
            case 'r':
                top1++;
                Opd[top1] = vecLitere['r' - 'a'];
                break;
            case 's':
                top1++;
                Opd[top1] = vecLitere['s' - 'a'];
                break;
            case 't':
                top1++;
                Opd[top1] = vecLitere['t' - 'a'];
                break;
            case 'u':
                top1++;
                Opd[top1] = vecLitere['u' - 'a'];
                break;
            case 'v':
                top1++;
                Opd[top1] = vecLitere['v' - 'a'];
                break;
            case 'w':
                top1++;
                Opd[top1] = vecLitere['w' - 'a'];
                break;
            case 'y':
                top1++;
                Opd[top1] = vecLitere['y' - 'a'];
                break;
            case 'z':
                top1++;
                Opd[top1] = vecLitere['z' - 'a'];
                break;
            case 'x':
                top1++;
                Opd[top1] = vecLitere['z' - 'a'];
                break;
            case '(': /* inceput de bloc */
                top2++;
                Op[top2] = '(';
                break;
            default:
                /* operatii binare si unare */
                while ((top2 > 0) && !(strchr("()", Op[top2])) &&
                        Prioritate(Op[top2]) >= Prioritate(E.vect[i][0]))
                {
                    int k = 1;
                    if (top1 > 1) x_1 = Opd[top1 - 1];
                    x_2 = Opd[top1];
                    //                    for(int j=1; j<=top2; j++)
                    //                        cout<<Op[j]<<" ";
                    //                    cout<<endl;
                    switch (Op[top2])
                    {
                    case '=':
                        if (Op[top2 - 1] == '<')
                        {
                            valo = MaiMicegal(x_1, x_2);
                            k++;
                        }
                        else if (Op[top2 - 1] == '>')
                        {
                            valo = MaiMareegal(x_1, x_2);
                            k++;
                        }
                        else if (Op[top2 - 1] == '!')
                        {
                            valo = Diferit(x_1, x_2);
                            k++;
                        }
                        else
                        {
                            valo = Egal(x_1, x_2);
                            k++;
                        }
                        break;
                    case '~':
                    {
                        valo = negat(x_2);
                        //cout<<valo<<endl;
                    }
                    break;
                    case '<':
                        valo = MaiMic(x_1, x_2);
                        break;
                    case '>':
                        valo = MaiMare(x_1, x_2);
                        break;
                    case '&':
                    {
                        valo = Si(x_1, x_2);
                        k++;
                    }
                    break;
                    case '|':
                    {
                        valo = Sau(x_1, x_2);
                        k++;
                    }
                    break;
                    case '+':
                        valo = Plus(x_1, x_2);
                        break;
                    case '-':
                        valo = Minus(x_1, x_2);
                        break;
                    case '*':
                    {
                        valo = Inmultit(x_1, x_2);
                    }
                    break;
                    case '%':
                    {
                        valo = Mod1(x_1, x_2);

                    }
                    break;
                    case '/':
                        valo = Impartit(x_1, x_2);
                        break;
                    case '^':
                        valo = Putere(x_1, x_2);
                        break;
                    case 'S':
                    {

                        valo = Sinus(x_2);

                        break;
                    }
                    case 'C':
                        valo = Cosinus(x_2);
                        break;
                    case 'L':
                        valo = Logaritm(x_2);
                        break;
                    case 'E':
                        valo = Exponential(x_2);
                        break;
                    case 'M':
                        valo = Modul(x_2);
                        break;
                    case 'R':
                        valo = Radical(x_2);
                        break;
                    } //operator[top2]
                    if (strchr(OperatiiBinare, Op[top2]))
                        top1--;
                    if (strchr(Operatii, Op[top2]))
                    {
                        Opd[top1] = valo;
                    }
                    if (k == 2)
                        top2 -= 2;
                    else
                        top2--;


                }

                if (top2 > 0)
                    if ((Op[top2] != '(') || (strcmp(E.vect[i], ")")))
                    {
                        if (strcmp(E.vect[i], ">") == 0 && strcmp(E.vect[i + 1], "=") == 0)
                        {
                            top2++;
                            Op[top2] = E.vect[i][0];
                            i++;
                            top2++;
                            Op[top2] = E.vect[i][0];
                        }
                        else if (strcmp(E.vect[i], "<") == 0 && strcmp(E.vect[i + 1], "=") == 0)
                        {
                            top2++;
                            Op[top2] = E.vect[i][0];
                            i++;
                            top2++;
                            Op[top2] = E.vect[i][0];
                        }
                        else if (strcmp(E.vect[i], "=") == 0 && strcmp(E.vect[i + 1], "=") == 0)
                        {
                            top2++;
                            Op[top2] = E.vect[i][0];
                            i++;
                            top2++;
                            Op[top2] = E.vect[i][0];
                        }
                        else if (strcmp(E.vect[i], "!") == 0 && strcmp(E.vect[i + 1], "=") == 0)
                        {
                            top2++;
                            Op[top2] = E.vect[i][0];
                            i++;
                            top2++;
                            Op[top2] = E.vect[i][0];
                        }
                        else if (strcmp(E.vect[i], "&") == 0 && strcmp(E.vect[i + 1], "&") == 0)
                        {
                            top2++;
                            Op[top2] = E.vect[i][0];
                            i++;
                            top2++;
                            Op[top2] = E.vect[i][0];
                        }
                        else if (strcmp(E.vect[i], "|") == 0 && strcmp(E.vect[i + 1], "|") == 0)
                        {
                            top2++;
                            Op[top2] = E.vect[i][0];
                            i++;
                            top2++;
                            Op[top2] = E.vect[i][0];
                        }
                        else
                            top2++;
                        Op[top2] = E.vect[i][0];
                    }
                    else top2--;
            }
    }
    if (top2 == 0)
        return Opd[top1];
    else return infinit;
}

void myOuttextXY(int x, int y, int cerneala, char* text)//Andrei
{
    settextstyle(10, 0, 1);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(cerneala);
    setbkcolor(culbk);
    outtextxy(x, y + 3, text);
}
struct Spot
{
    int xPos;
    int yPos;
};
struct punctLegatura
{
    int x, y;
};

struct nod
{
    char tip;//S=start;I=Input;O=Output;C=Calcul;D=Decizie; T=stop
    char info[MAX];
    int x1, y1, x2, y2;
    int culoare, culoarecerc;
    char tiplegatJ1;
    char tiplegatJ2;
    char tiplegatS1;
    char tiplegatS2;
    char tiplegat;
    int sters;
    punctLegatura pLeg[3];
    nod* urm;
    nod* urmT;
    nod* urmF;
    int cnt;
    int culoarelegaturi, culoarelegaturi2;
    int ok1, ok2;
    int lungtext;
    int loop;
};
struct legatura
{
    int nod1, nod2; // cele doua noduri ce se leaga
    int punct1, punct2; // punctele de legatura de la cele doua noduri
    char tipleg; // nu am folosit, dar va trebui folosit
    int x, y;
    int x1, y1;
};
legatura vecLegaturi[MAX_NR];
int nrLegaturi;
nod vecNoduri[MAX_NR];
int nrNoduri = 0;
int index = 0;

void desenare1_dreptunghi(int x1, int y1, int x2, int y2, int cul)//Cosmin
{
    setcolor(cul);
    line(x1, y1, x2, y1);
    line(x2, y1, x2, y2);
    line(x2, y2, x1, y2);
    line(x1, y2, x1, y1);
}
void desenare_dreptunghi(int x1, int y1, int x2, int y2, int cul)//Cosmin
{
    setcolor(cul);
    line(x1, y1, x2, y1);
    line(x2, y1, x2, y2);
    line(x2, y2, x1, y2);
    line(x1, y2, x1, y1);
}
void desenare_triunghi(int x1, int y1, int x2, int y2, int x, int cul)//Andrei
{
    setcolor(cul);
    line(x1, y1, x2, y2);
    line(x2, y2, x2 - 2 * (x2 - x1), y2);
    line(x2 - 2 * (x2 - x1), y2, x1, y1);
}
void desenare_chenar(int x1, int y1, int x2, int y2, int color)//Andrei
{
    setcolor(color);
    setbkcolor(culbk);
    line(x1, y1, x2, y1);
    line(x2, y1, x2, y2);
    line(x2, y2, x1, y2);
    line(x1, y2, x1, y1);
}
void desenare1_trapezI(int x1, int y1, int x2, int y2, int cul) //Cosmin
// coordonatele pentru punctul stanga sus si dreapta jos
{
    setcolor(cul);
    line(x1, y1, x2 + 15, y1);
    line(x2 + 15, y1, x2, y2);
    line(x2, y2, x1 + 15, y2);
    line(x1 + 15, y2, x1, y1);
}
void desenare1_trapezO(int x1, int y1, int x2, int y2, int cul) //Cosmin
{
    setcolor(cul);
    line(x1, y1, x2 - 15, y1);
    line(x2 - 15, y1, x2, y2);
    line(x2, y2, x1 - 15, y2);
    line(x1 - 15, y2, x1, y1);


}

bool este_selectat_creare_schema(int x, int y)//Cosmin
{

    if (x >= 180 && x <= 405 && y >= 15 && y <= 75)
        return true;
    return false;
}
bool este_selectat_incarcare_schema(int x, int y)//Cosmin
{
    if (x >= 420 && x <= 645 && y >= 15 && y <= 75)
        return true;
    return false;

}
bool este_selectat_Exit(int x, int y) //Cosmin
{
    if (x >= 1100 && x <= 1185 && y >= 15 && y <= 75)
        return true;
    return false;
}
bool este_selectat_salvare_schema(int x, int y)//Cosmin
{
    if (x >= 660 && x <= 885 && y >= 15 && y <= 75)
        return true;
    return false;
}

bool este_selectat_buton_stergere(int x, int y)//Andrei
{
    if (x >= 990 && x <= 1185 && y >= 90 && y <= 130)
        return true;
    return false;
}
bool exitmenu(int x, int y)//Cosmin
{
    if (x >= x_EXIT1 && x <= x_EXIT2 && y >= y_EXIT1 && y <= y_EXIT2)
        return true;
    return false;
}
bool nu_este_oprita_desenarea1(int x, int y)//Cosmin
{
    if (x >= x1_coord_OPRIRE && x <= x2_coord_OPRIRE && y >= y1_coord_OPRIRE && y <= y2_coord_OPRIRE)
        return true;
    return false;
}
bool este_selectat_bloculSTART1(int x, int y)//Cosmin
{
    if (x >= x1_coord_START && x <= x2_coord_START && y >= y1_coord_START && y <= y2_coord_START)
        return true;
    return false;
}
bool este_selectat_bloculINPUT1(int x, int y)//Cosmin
{
    if (x >= x1_coord_INPUT && x <= x2_coord_INPUT && y >= y1_coord_INPUT && y <= y2_coord_INPUT)
        return true;
    return false;
}
bool este_selectat_bloculCALCUL1(int x, int y)//Cosmin
{
    if (x >= x1_coord_CALCUL && x <= x2_coord_CALCUL && y >= y1_coord_CALCUL && y <= y2_coord_CALCUL)
        return true;
    return false;
}
bool este_selectat_bloculDECIZIE1(int x, int y)//Cosmin
{
    if (x >= x1_coord_DECIZIE && x <= x1_coord_DECIZIE + 65 && y >= y1_coord_DECIZIE && y <= y1_coord_DECIZIE + 70)
        return true;
    if (x <= x1_coord_DECIZIE && x >= x1_coord_DECIZIE - 65 && y >= y1_coord_DECIZIE && y <= y1_coord_DECIZIE + 70)
        return true;
    return false;
}
bool este_selectat_bloculOUTPUT1(int x, int y)//Cosmin
{
    if (x >= x1_coord_OUTPUT && x <= x2_coord_OUTPUT && y >= y1_coord_OUTPUT && y <= y2_coord_OUTPUT)
        return true;
    return false;
}
bool este_selectat_bloculSTOP1(int x, int y)//Cosmin
{
    if (x >= x1_coord_STOP && x <= x2_coord_STOP && y >= y1_coord_STOP && y <= y2_coord_STOP)
        return true;
    return false;
}
bool este_selectat_bloculRUN(int x, int y)//Andrei
{
    if (x >= x1_coord_RUN && x <= x2_coord_RUN && y >= y1_coord_RUN && y <= y2_coord_RUN)
        return true;
    return false;
}
bool este_selectat_bloculSTERGERE(int x, int y)//Andrei
{
    if (x >= x1_coord_STERGERE && x <= x2_coord_STERGERE && y >= y1_coord_STERGERE && y <= y2_coord_STERGERE)
        return true;
    return false;
}
void desenare1_butoane_blocuri()//Cosmin
{
    //settextjustify(BOTTOM_TEXT,BOTTOM_TEXT);
    setcolor(culbk);

    desenare1_dreptunghi(x1_coord_START, y1_coord_START, x2_coord_START, y2_coord_START, 5);
    myOuttextXY(90, 135, 15, "START");
    desenare1_trapezI(x1_coord_INPUT, y1_coord_INPUT, x2_coord_INPUT, y2_coord_INPUT, 5);
    myOuttextXY(87, 215, 15, "INPUT");
    desenare1_dreptunghi(x1_coord_CALCUL, y1_coord_CALCUL, x2_coord_CALCUL, y2_coord_CALCUL, 5);
    myOuttextXY(90, 295, 15, "CALCUL");
    desenare_triunghi(x1_coord_DECIZIE, y1_coord_DECIZIE, x2_coord_DECIZIE, y2_coord_DECIZIE, 0, 5);
    myOuttextXY(85, 415, 15, "DECIZIE");
    desenare1_trapezO(x1_coord_OUTPUT, y1_coord_OUTPUT, x2_coord_OUTPUT, y2_coord_OUTPUT, 5);
    myOuttextXY(92, 495, 15, "OUTPUT");
    desenare1_dreptunghi(x1_coord_STOP, y1_coord_STOP, x2_coord_STOP, y2_coord_STOP, 5);
    myOuttextXY(89, 575, 15, "STOP");
    myOuttextXY(85, 715, 15, "OPRIRE");
    myOuttextXY(85, 745, 15, "DESENARE");
    myOuttextXY(85, 45, 15, "RUN");
    myOuttextXY(990, 45, 15, "STERGERE");
    myOuttextXY(1360, 35, 15, "Cod c++");

}
void desenare_menu()//Cosmin
{
    setbkcolor(culfundal);
    cleardevice();
    setfillstyle(1, culbk);
    bar(1200, 15, 1515, 630);//cod c++
    bar(1200, 645, 1515, 775);//error box
    bar(1100, 15, 1185, 75);//exit
    bar(900, 15, 1085, 75);//stergere
    bar(660, 15, 885, 75);//salvare
    bar(420, 15, 645, 75);//incarcare
    bar(180, 15, 405, 75);//creare
    bar(15, 15, 165, 75);//run
    bar(15, 90, 165, 655);//blocurile
    bar(15, 680, 165, 775);//oprire
    bar(180, 90, 1185, 775);//cadru blocuri
    setlinestyle(0, 0, 3);
    myOuttextXY(292, 45, 15, "Creare schema noua");
    myOuttextXY(532, 45, 15, "Incarcare schema");
    myOuttextXY(772, 45, 15, "Salvare schema");
    myOuttextXY(1140, 45, 15, "Exit");
    myOuttextXY(1360, 670, 15, "Error box");
}
void mem_text(char* tmp, char* output)//Andrei
{
    strcpy(tmp, output);
}

void place_text(int x, int y, char* tmp, int color)//Andrei
{
    setcolor(color);
    outtextxy(x, y, tmp);

}

void add_key(char pressed_key, char output[MAX], int char_lim)//Andrei
{
    char t[2];
    t[0] = pressed_key;
    t[1] = '\0';
    strcat(output, t);
}
int incrementare(char s[MAX])//Andrei
{
    if ((s[0] >= 'a' && s[0] <= 'z') && s[1] == '+' && s[2] == '+')
        return 1;
    else
        return 0;
}
int decrementare(char s[MAX])
{
    if ((s[0] >= 'a' && s[0] <= 'z') && s[1] == '-' && s[2] == '-')
        return 1;
    else
        return 0;
}
int eval(char s[MAX])//Andrei
{
    char s2[MAX];
    functie F;
    strcpy(s2, s);
    strcpy(s2, s2 + 2);
    strcpy(F.expresie, s2);
    int j = 0;
    for (int i = 2; i < strlen(s); i++)
    {

        strcpy(s2, s);
        strcpy(s2, s2 + i);
        strcpy(s2 + 1, s2 + strlen(s2));
        strcpy(F.vect[j], s2);
        j++;
    }
    F.lung = strlen(F.expresie);
    float a = ValoareFunctie(F);

    if (a == 0)
        return 0;
    else
        return 1;
}
int evalO(char s[MAX])//Andrei
{
    char s2[MAX];
    functie F;
    strcpy(F.expresie, s);
    strcpy(F.vect[0], "(");
    int j = 1;
    for (int i = 0; i < strlen(s); i++)
    {

        strcpy(s2, s);
        strcpy(s2, s2 + i);
        strcpy(s2 + 1, s2 + strlen(s2));
        strcpy(F.vect[j], s2);
        j++;
    }
    F.lung = strlen(F.expresie);
    strcpy(F.vect[j], ")");
    float a = ValoareFunctie(F);

    return a;
}
int aduna(char s[MAX])//Andrei
{
    int a;
    if (s[1] == '=')
    {
        char s2[MAX];
        functie F;
        strcpy(s2, s);
        strcpy(s2, s2 + 2);

        strcpy(F.expresie, s2);
        strcpy(F.vect[0], "(");
        int j = 1;
        for (int i = 2; i < strlen(s); i++)
        {

            strcpy(s2, s);
            strcpy(s2, s2 + i);

            strcpy(s2 + 1, s2 + strlen(s2));

            strcpy(F.vect[j], s2);
            j++;
        }
        F.lung = strlen(F.expresie);
        strcpy(F.vect[j], ")");
        a = ValoareFunctie(F);
    }
    else if (s[2] == '=')
    {
        char s2[MAX];
        functie F;
        strcpy(s2, s);
        strcpy(s2, s2 + 3);
        strcpy(F.expresie, s2);
        strcpy(F.vect[0], "(");
        int j = 1;
        for (int i = 3; i < strlen(s); i++)
        {

            strcpy(s2, s);
            strcpy(s2, s2 + i);
            strcpy(s2 + 1, s2 + strlen(s2));

            strcpy(F.vect[j], s2);
            j++;
        }
        F.lung = strlen(F.expresie);
        strcpy(F.vect[j], ")");
        a = ValoareFunctie(F);
    }

    int sum = 0;
    int sum2 = 0;
    int x = s[0] - 'a';
    if (s[1] == '=')
    {
        sum = a;
        return sum;
    }
    else if (s[1] == '+' && s[2] == '=')
    {
        sum += vecLitere[x];
        sum += a;
        return sum;
    }
    else if (s[1] == '-' && s[2] == '=')
    {
        sum += vecLitere[x];
        sum -= a;
        return sum;
    }
    else if (s[1] == '*' && s[2] == '=')
    {
        sum += vecLitere[x];
        sum *= a;
        return sum;
    }
    else if (s[1] == '/' && s[2] == '=')
    {
        sum += vecLitere[x];
        sum /= a;
        return sum;
    }
    else
        return 0;
}
int maimic(char s[MAX])//Andrei
{
    if (s[4] == '<' && (s[5] >= 'a' && s[5] <= 'z'))
    {
        if (vecLitere[s[3] - 'a'] < vecLitere[s[5] - 'a'])
            return 1;
        else
            return 2;
    }
    else if (s[4] == '<' && s[5] == '=')
    {
        if (vecLitere[s[3] - 'a'] <= vecLitere[s[6] - 'a'])
            return 1;
        else
            return 2;
    }
    else
        return 0;
}
int maimare(char s[MAX])//Andrei
{
    if (s[4] == '>' && (s[5] >= 'a' && s[5] <= 'z'))
    {
        if (vecLitere[s[3] - 'a'] > vecLitere[s[5] - 'a'])
            return 1;
        else
            return 2;
    }
    else if (s[4] == '>' && s[5] == '=')
    {
        if (vecLitere[s[3] - 'a'] >= vecLitere[s[6] - 'a'])
            return 1;
        else
            return 2;
    }
    else
        return 0;
}
int difcif(char s[MAX])//Andrei
{
    int a, b;
    if ((s[3] >= 'a' && s[3] < 'z') && s[4] == '!' && s[5] == '=')
    {
        if (s[6] >= 'a' && s[6] <= 'z')
        {
            a = vecLitere[s[3] - 'a'];
            b = vecLitere[s[6] - 'a'];
            if (a != b)
                return 1;
            else
                return 2;
        }
        else if (s[6] >= '0' && s[6] <= '9')
        {
            a = vecLitere[s[3] - 'a'];
            int i = 6;
            int nr = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                nr = nr * 10 + (s[i] - '0');
                i++;
            }
            if (a != nr)
                return 1;
            else
                return 2;
        }
    }
    else
        return 0;
}
void scan_window_textInput(Spot point, int char_lim, Spot interogation, int nr_bloc, nod N1[])//Andrei
{
    char output[MAX];
    strcpy(output, "");
    char tmp[MAX];
    char pressed_key;
    place_text(1350, 700, "Introduceti input-ul:", 0);
    int wait = 1;
    int x1, y1;
    char message[10];
    do
    {


        if (!kbhit())
        {
            wait = 1;
            continue;
        }
        pressed_key = getch();
        if (pressed_key == 13)//enter
            break;

        if (pressed_key == 8)
        {
            if (strlen(output) > 0)
            {
                mem_text(tmp, output);
                place_text(point.xPos, point.yPos, tmp, culbk);

                output[strlen(output) - 1] = '\0';

                mem_text(tmp, output);

                place_text(point.xPos, point.yPos, tmp, culbk);

                place_text(point.xPos, point.yPos, tmp, 7);
            }
            else
                Beep(1000, 100);
        }
        else
        {
            if (char_lim > strlen(tmp))
            {
                if ((pressed_key < '0' || pressed_key>'9') && pressed_key != '-')
                {
                    place_text(1360, 740, "Doar cifre!", 4);
                }
                else
                {
                    place_text(1360, 740, "Doar cifre!", culbk);
                    add_key(pressed_key, output, char_lim);
                }
            }
            else
            {

                if (interogation.xPos > 0)
                {
                    strcpy(message, "(max. 10)");
                    x1 = 1150 - textwidth(": ") - textwidth(message);
                }
                else
                {
                    strcpy(message, "(max. 10)");
                    x1 = interogation.xPos;
                }

                place_text(interogation.xPos, interogation.yPos, message, 15);
                delay(10);


            }

            mem_text(tmp, output);

            place_text(point.xPos, point.yPos, tmp, 15);
        }
    }
    while (true);
    int nr = 0;
    if (tmp[0] == '-')
    {
        for (int i = 1; i < strlen(tmp); i++)
        {
            nr = nr * 10 + (tmp[i] - '0');
        }
        nr = -nr;
    }
    else
    {
        for (int i = 0; i < strlen(tmp); i++)
        {
            nr = nr * 10 + (tmp[i] - '0');
        }
    }
    vecLitere[N1[nr_bloc].info[0] - 'a'] = nr;
    place_text(1360, 740, "Doar cifre!", culbk);
    place_text(interogation.xPos, interogation.yPos, message, culbk);

    place_text(1350, 700, "Introduceti input-ul:", culbk);
    place_text(point.xPos, point.yPos, tmp, culbk);
}
void scan_window_text1(char output[MAX], Spot point, int char_lim, Spot interogation)//Andrei
{
    strcpy(output, "");
    char tmp[MAX];
    char pressed_key;
    place_text(1350, 700, "Introduceti input-ul:", 0);
    int wait = 1;
    int x1, y1;
    char message[MAX];
    do
    {

        if (!kbhit())
        {
            wait = 1;
            continue;
        }
        pressed_key = getch();
        if (pressed_key == 13)//enter
            break;

        if (pressed_key == 8)
        {
            if (strlen(output) > 0)
            {
                mem_text(tmp, output);
                place_text(point.xPos, point.yPos, tmp, culbk);

                output[strlen(output) - 1] = '\0';

                mem_text(tmp, output);

                place_text(point.xPos, point.yPos, tmp, culbk);

                place_text(point.xPos, point.yPos, tmp, 7);
            }
            else
                Beep(1000, 100);
        }
        else
        {
            if (char_lim > strlen(tmp))
            {
                if (pressed_key < 'a' || pressed_key>'z')
                {
                    place_text(1360, 740, "Doar litere mici!", 4);
                }
                else
                {
                    place_text(1360, 740, "Doar litere mici!", culbk);
                    add_key(pressed_key, output, char_lim);
                }

            }
            else
            {

                if (interogation.xPos > 0)
                {
                    strcpy(message, "(maxim o litera!)");
                    x1 = 1150 - textwidth(": ") - textwidth(message);
                }
                else
                {
                    strcpy(message, "(maxim o litera!)");
                    x1 = interogation.xPos;
                }
                //setcolor( 5 );
                place_text(interogation.xPos, interogation.yPos, message, 15);
                delay(10);

                //setcolor( 8);
            }

            mem_text(tmp, output);

            place_text(point.xPos, point.yPos, tmp, 15);
        }
    }
    while (true);
    place_text(1360, 740, "Doar litere mici!", culbk);
    place_text(interogation.xPos, interogation.yPos, message, culbk);
    place_text(1350, 700, "Introduceti input-ul:", culbk);
    place_text(point.xPos, point.yPos, tmp, culbk);
}
void scan_window_decizie(char output[MAX], Spot point, int char_lim, Spot interogation)//Andrei
{
    strcpy(output, "");
    char tmp[MAX];
    char pressed_key;
    place_text(1350, 700, "Introduceti expresia:", 0);
    int wait = 1;
    int x1, y1;
    char message[10];
    do
    {


        if (!kbhit())
        {
            wait = 1;
            continue;
        }
        pressed_key = getch();
        if (pressed_key == 13)
            break;

        if (pressed_key == 8)
        {
            if (strlen(output) > 0)
            {
                mem_text(tmp, output);
                place_text(point.xPos, point.yPos, tmp, culbk);

                output[strlen(output) - 1] = '\0';

                mem_text(tmp, output);

                place_text(point.xPos, point.yPos, tmp, culbk);

                place_text(point.xPos, point.yPos, tmp, 7);
            }
            else
                Beep(1000, 100);
        }
        else
        {
            if (char_lim > strlen(tmp))
                add_key(pressed_key, output, char_lim);
            else
            {

                if (interogation.xPos > 0)
                {
                    strcpy(message, "(max. 30)");
                }

                place_text(interogation.xPos, interogation.yPos, message, 15);
                delay(10);


            }

            mem_text(tmp, output);
            char s[MAX] = "";
            if (strlen(output) > 25)
                strcat(s, tmp + 25);
            if (strlen(output) > 25)
                place_text(point.xPos, point.yPos + 20, s, 15);
            else
                place_text(point.xPos, point.yPos, tmp, 15);
        }
    }
    while (true);
    char a[MAX] = "if(";
    strcat(a, output);
    strcat(a, ")");
    strcpy(output, a);
    place_text(interogation.xPos, interogation.yPos, message, culbk);

    place_text(1350, 700, "Introduceti expresia:", culbk);
    setfillstyle(1, culbk);
    bar(1200, 700, 1510, 740);

}
void scan_window_calcul(char output[MAX], Spot point, int char_lim, Spot interogation)//Andrei
{
    strcpy(output, "");
    char tmp[MAX];
    char pressed_key;

    place_text(1350, 700, "Introduceti expresia:", 0);
    int wait = 1;
    int x1, y1;
    char message[10];
    do
    {


        if (!kbhit())
        {
            wait = 1;
            continue;
        }
        pressed_key = getch();
        if (pressed_key == 13)//enter
            break;

        if (pressed_key == 8)                                           // backspace
        {
            if (strlen(output) > 0)
            {
                mem_text(tmp, output);
                place_text(point.xPos, point.yPos, tmp, culbk);

                output[strlen(output) - 1] = '\0';

                mem_text(tmp, output);

                place_text(point.xPos, point.yPos, tmp, culbk);

                place_text(point.xPos, point.yPos, tmp, 7);
            }
            else
                Beep(1000, 100);
        }
        else
        {
            if (char_lim > strlen(tmp))
                add_key(pressed_key, output, char_lim);
            else
            {

                if (interogation.xPos > 0)
                {
                    strcpy(message, "(max. 25)");
                }
                //setcolor( 5 );
                place_text(interogation.xPos, interogation.yPos, message, 15);
                delay(10);

                //setcolor( 8);
            }

            mem_text(tmp, output);

            place_text(point.xPos, point.yPos, tmp, 15);
        }
    }
    while (true);
    place_text(interogation.xPos, interogation.yPos, message, culbk);
    place_text(1350, 700, "Introduceti expresia:", culbk);
    place_text(point.xPos, point.yPos, tmp, culbk);
}
void scan_window_output(char output[MAX], Spot point, int char_lim, Spot interogation)//Andrei
{
    strcpy(output, "");
    char tmp[MAX] = "";
    char pressed_key;
    place_text(1350, 700, "Introduceti output-ul:", 0);
    int wait = 1;
    int x1, y1;
    char message[10];
    do
    {


        if (!kbhit())
        {
            wait = 1;
            continue;
        }
        pressed_key = getch();
        if (pressed_key == 13)
            break;

        if (pressed_key == 8)
        {
            if (strlen(output) > 0)
            {
                mem_text(tmp, output);
                place_text(point.xPos, point.yPos, tmp, culbk);

                output[strlen(output) - 1] = '\0';

                mem_text(tmp, output);

                place_text(point.xPos, point.yPos, tmp, culbk);

                place_text(point.xPos, point.yPos, tmp, 7);
            }
            else
                Beep(1000, 100);
        }
        else
        {
            if (char_lim > strlen(tmp))
                add_key(pressed_key, output, char_lim);
            else
            {

                if (interogation.xPos > 0)
                {
                    strcpy(message, "(max. 25)");
                }

                place_text(interogation.xPos, interogation.yPos, message, 15);
                delay(10);


            }

            mem_text(tmp, output);

            place_text(point.xPos, point.yPos, tmp, 15);
        }
    }
    while (true);
    place_text(interogation.xPos, interogation.yPos, message, culbk);
    place_text(1350, 700, "Introduceti output-ul:", culbk);
    place_text(point.xPos, point.yPos, tmp, culbk);
}
void deseneazadreptunghi(nod N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    x2 = N.x2;
    y1 = N.y1;
    y2 = N.y2;
    myOuttextXY((x1 + x2) / 2, (y1 + y2) / 2 + 5, N.culoare, N.info);
    desenare1_dreptunghi(x1, y1, x2, y2, N.culoare);
    setcolor(WHITE);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);
}

void initdreptunghi(nod& N, char text[MAX], int oCuloare, int x1, int y1, int x2, int y2)//Andrei
{
    N.tip = 'S';
    strcpy(N.info, text);
    N.culoare = oCuloare;
    N.x1 = x1;
    N.x2 = x2;
    N.y1 = y1;
    N.y2 = y2;
    N.pLeg[0].x = x1 + (x2 - x1) / 2;
    N.pLeg[0].y = y2;

}
void deseneazadreptunghiC(nod N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    x2 = N.x2;
    y1 = N.y1;
    y2 = N.y2;
    desenare1_dreptunghi(x1, y1, x2, y2, N.culoare);
    myOuttextXY((x1 + x2) / 2, (y1 + y2) / 2 + 5, N.culoare, N.info);
    setcolor(N.culoarecerc);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);
}
void deseneazadreptunghiCsters(nod& N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    x2 = N.x2;
    y1 = N.y1;
    y2 = N.y2;
    desenare1_dreptunghi(x1, y1, x2, y2, N.culoare);
    myOuttextXY((x1 + x2) / 2, (y1 + y2) / 2 + 5, N.culoare, N.info);
    N.culoarecerc = culbk;
    setcolor(N.culoarecerc);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);
}
void initdreptunghiC(nod& N, char text[MAX1], int oCuloare, int x1, int y1, int x2, int y2)//Andrei
{
    N.tip = 'C';
    strcpy(N.info, text);
    N.culoare = oCuloare;
    N.x1 = x1;
    N.x2 = x2;
    N.y1 = y1;
    N.y2 = y2;
    N.pLeg[0].x = x1 + (x2 - x1) / 2;
    N.pLeg[0].y = y2;
    N.pLeg[1].x = x1 + (x2 - x1) / 2;
    N.pLeg[1].y = y1;
}
void inittrapez(nod& N, char text[MAX], int oCuloare, int x1, int y1, int x2, int y2, int x)//Andrei
{
    N.tip = 'I';
    strcpy(N.info, text);
    N.culoare = oCuloare;
    N.x1 = x1;
    N.x2 = x2;
    N.y1 = y1;
    N.y2 = y2;
    N.pLeg[0].x = (N.x1 + N.x2) / 2 + 7;
    N.pLeg[0].y = N.y2;
    N.pLeg[1].x = (N.x1 + N.x2) / 2 + 7;
    N.pLeg[1].y = N.y1;
}

void deseneazatrapez(nod N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    x2 = N.x2;
    y1 = N.y1;
    y2 = N.y2;
    desenare1_trapezI(x1, y1, x2, y2, N.culoare);
    myOuttextXY((x1 + x2) / 2 + 7, (y1 + y2) / 2 + 2, N.culoare, N.info);
    setcolor(N.culoarecerc);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);
}
void deseneazatrapezsters(nod& N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    x2 = N.x2;
    y1 = N.y1;
    y2 = N.y2;
    desenare1_trapezI(N.x1, N.y1, N.x2, N.y2, N.culoare);
    myOuttextXY((x1 + x2) / 2, (y1 + y2) / 2 + 2, N.culoare, N.info);
    N.culoarecerc = culbk;
    setcolor(N.culoarecerc);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);
}
void inittriunghi(nod& N, char text[MAX], int oCuloare, int x1, int y1, int x2, int y2, int x)//Andrei
{
    N.tip = 'D';
    strcpy(N.info, text);
    N.culoare = oCuloare;
    N.x1 = x1;
    N.y1 = y1;
    N.x2 = x2;
    N.y2 = y2;
    N.pLeg[0].x = N.x1 - (N.x2 - N.x1);
    N.pLeg[0].y = N.y2;
    N.pLeg[2].x = N.x2;
    N.pLeg[2].y = N.y2;
    N.pLeg[1].x = N.x1;
    N.pLeg[1].y = N.y1;
}
void deseneazatriunghi(nod N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    y1 = N.y1;
    x2 = N.x2;
    y2 = N.y2;
    desenare_triunghi(x1, y1, x2, y2, N.lungtext, N.culoare);
    myOuttextXY(x1, y2 - 10, N.culoare, N.info);
    setcolor(N.culoarecerc);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);//stanga
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);//varf
    circle(N.pLeg[2].x, N.pLeg[2].y, 5);//dreapta
}
void deseneazatriunghisters(nod& N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    y1 = N.y1;
    x2 = N.x2;
    y2 = N.y2;
    desenare_triunghi(x1, y1, x2, y2, N.lungtext, N.culoare);
    myOuttextXY(x1, y2 - 10, N.culoare, N.info);
    N.culoarecerc = culbk;
    setcolor(N.culoarecerc);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);//stanga
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);//varf
    circle(N.pLeg[2].x, N.pLeg[2].y, 5);//dreapta
}
void deseneazatriunghimutat(nod N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    y1 = N.y1;
    x2 = N.x2;
    y2 = N.y2;
    desenare_triunghi(x1, y1, x2, y2, N.lungtext, culbk);
    myOuttextXY(x1, y2 - 10, culbk, N.info);
    setcolor(culbk);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);//stanga
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);//varf
    circle(N.pLeg[2].x, N.pLeg[2].y, 5);//dreapta
}
void inittrapezO(nod& N, char text[MAX1], int oCuloare, int x1, int y1, int x2, int y2)//Andrei
{
    N.tip = 'O';
    strcpy(N.info, text);
    N.culoare = oCuloare;
    N.x1 = x1;
    N.x2 = x2;
    N.y1 = y1;
    N.y2 = y2;
    N.pLeg[1].x = (x1 + x2 - 15) / 2;
    N.pLeg[1].y = y1;
    N.pLeg[0].x = (x1 + x2 - 15) / 2;
    N.pLeg[0].y = y2;
}
void deseneazatrapezO(nod N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    x2 = N.x2;
    y1 = N.y1;
    y2 = N.y2;
    desenare1_trapezO(x1, y1, x2, y2, N.culoare);
    myOuttextXY((x1 + x2) / 2 - 10, (y1 + y2) / 2, N.culoare, N.info);
    setcolor(N.culoarecerc);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);
}
void deseneazatrapezOsters(nod& N)//Andrei
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    x2 = N.x2;
    y1 = N.y1;
    y2 = N.y2;
    desenare1_trapezO(x1, y1, x2, y2, N.culoare);
    myOuttextXY((x1 + x2) / 2 - 10, (y1 + y2) / 2, N.culoare, N.info);
    N.culoarecerc = culbk;
    setcolor(N.culoarecerc);
    circle(N.pLeg[0].x, N.pLeg[0].y, 5);
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);
}
void initstop(nod& N, char text[MAX1], int oCuloare, int x1, int y1, int x2, int y2)//Cosmin
{
    N.tip = 'T';
    strcpy(N.info, text);
    N.culoare = oCuloare;
    N.x1 = x1;
    N.x2 = x2;
    N.y1 = y1;
    N.y2 = y2;
    N.pLeg[1].x = (x1 + x2) / 2;
    N.pLeg[1].y = y1;
}
void deseneazastopsters(nod& N)//Cosmin
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    x2 = N.x2;
    y1 = N.y1;
    y2 = N.y2;
    desenare1_dreptunghi(x1, y1, x2, y2, N.culoare);
    myOuttextXY((x1 + x2) / 2, (y1 + y2) / 2, N.culoare, N.info);
    N.culoarecerc = culbk;
    setcolor(N.culoarecerc);
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);
}
void deseneazastop(nod N)//Cosmin
{
    int x1, x2, y1, y2;
    setfillstyle(SOLID_FILL, N.culoare);
    x1 = N.x1;
    x2 = N.x2;
    y1 = N.y1;
    y2 = N.y2;
    desenare1_dreptunghi(x1, y1, x2, y2, N.culoare);
    myOuttextXY((x1 + x2) / 2, (y1 + y2) / 2 + 5, N.culoare, N.info);
    setcolor(N.culoarecerc);
    circle(N.pLeg[1].x, N.pLeg[1].y, 5);

}
void salvare_imagine_schema(char nume_imagine[])//Cosmin
{
    writeimagefile(nume_imagine, 180, 90, 1185, 775);


}

int este_selectata_mutarea_unui_bloc1(int x, int y, nod N1[], int nrr_b)//Cosmin
{
    int i;

    for (i = 0; i < nrr_b; i++)
    {
        if (x >= N1[i].x1 && x <= N1[i].x2 && y >= N1[i].y1 && y <= N1[i].y2)
            return i;
        else if (N1[i].tip == 'D')
        {
            if (x <= N1[i].x1 && x >= N1[i].x1 - (N1[i].x2 - N1[i].x1) && y >= N1[i].y1 && y <= N1[i].y2)
                return i;
        }
    }

    return -1;
}
int este_selectat_cerculet(int x, int y)//Andrei
{
    int i;
    for (i = 0; i < index; i++)
    {
        if (x >= vecNoduri[i].pLeg[0].x - 3 && x <= vecNoduri[i].pLeg[0].x + 3 && y >= vecNoduri[i].pLeg[0].y - 3 && y <= vecNoduri[i].pLeg[0].y + 3)
        {
            return 1;
        }
        else if (x >= vecNoduri[i].pLeg[1].x - 3 && x <= vecNoduri[i].pLeg[1].x + 3 && y >= vecNoduri[i].pLeg[1].y - 3 && y <= vecNoduri[i].pLeg[1].y + 3)
            return 1;
        else if (x >= vecNoduri[i].pLeg[2].x - 3 && x <= vecNoduri[i].pLeg[2].x + 3 && y >= vecNoduri[i].pLeg[2].y - 3 && y <= vecNoduri[i].pLeg[2].y + 3)
            return 1;
    }

    return 0;
}
char true_sau_false(int x, int y, int i)//Cosmin
{
    if (x >= vecNoduri[i].pLeg[0].x - 3 && x <= vecNoduri[i].pLeg[0].x + 3 && y >= vecNoduri[i].pLeg[0].y - 3 && y <= vecNoduri[i].pLeg[0].y + 3)
        return 'T';
    else if (x >= vecNoduri[i].pLeg[2].x - 3 && x <= vecNoduri[i].pLeg[2].x + 3 && y >= vecNoduri[i].pLeg[2].y - 3 && y <= vecNoduri[i].pLeg[2].y + 3)
        return 'F';

}
void redeseneaza_blocuri(nod N1[], int nrr_noduri)//Andrei
{
    int j;
    for (j = 0; j < nrr_noduri; j++)
    {
        if (N1[j].tip == 'S' && N1[j].sters == 0)
            deseneazadreptunghi(N1[j]);
        else if (N1[j].tip == 'I' && N1[j].sters == 0)
            deseneazatrapez(N1[j]);
        else if (N1[j].tip == 'O' && N1[j].sters == 0)
            deseneazatrapezO(N1[j]);
        else if (N1[j].tip == 'C' && N1[j].sters == 0)
            deseneazadreptunghiC(N1[j]);
        else if (N1[j].tip == 'D' && N1[j].sters == 0)
            deseneazatriunghi(N1[j]);
        else if (N1[j].tip == 'T' && N1[j].sters == 0)
            deseneazastop(N1[j]);
    }
}

int intalnire_bloc_incarcare_schema(int x1, int y1, int x2, int y2, nod N1[], int nrr_b)//Cosmin
{
    int nr_blocuri_intalnite = 0;
    if (x1 < x2)
        for (int i = x1; i <= x2; i++)
        {

            int nrr_bloc = este_selectata_mutarea_unui_bloc1(i, y1, N1, nrr_b);
            if (nrr_bloc != -1 && N1[nrr_bloc].sters != 1)
                return nrr_bloc;
        }
    else
    {
        for (int i = x1; i >= x2; i--)
        {
            int nrr_bloc = este_selectata_mutarea_unui_bloc1(i, y1, N1, nrr_b);
            if (nrr_bloc != -1 && N1[nrr_bloc].sters != 1)
                return nrr_bloc;
        }
    }
    return -1;

}
int intalnire_bloc1_incarcare_schema(int x1, int y1, int x2, int y2, nod N1[], int nrr_b)//Cosmin
{
    int nr_blocuri_intalnite = 0;
    if (x1 < x2)
        for (int i = x1; i <= x2; i++)
        {
            int nrr_bloc = este_selectata_mutarea_unui_bloc1(y1, i, N1, nrr_b);
            if (nrr_bloc != -1 && N1[nrr_bloc].sters != 1)
                return nrr_bloc;
        }
    else
    {
        for (int i = x1; i >= x2; i--)
        {

            int nrr_bloc = este_selectata_mutarea_unui_bloc1(y1, i, N1, nrr_b);
            if (nrr_bloc != -1 && N1[nrr_bloc].sters != 1)
                return nrr_bloc;
        }
    }
    return -1;

}
void drawLine(int x1, int y1, int x2, int y2, int cul, nod N1[], int nrr_b)//Cosmin
{
    setcolor(cul);
    setlinestyle(0, 0, 1);

    line(x1, y1, x1, y1 + 10);
    int mij = (x1 + x2) / 2;
    int nr1 = intalnire_bloc_incarcare_schema(x1, y1 + 10, mij, y1 + 10, N1, nrr_b);//pentru prima linie (prima orizontala)
    if (nr1 == -1)
        line(x1, y1 + 10, mij, y1 + 10);
    else
    {
        if (x2 > x1)
        {
            if (N1[nr1].tip != 'D')
            {
                line(x1, y1 + 10, N1[nr1].x1 - 15, y1 + 10);
                line(N1[nr1].x1 - 15, y1 + 10, N1[nr1].x1 - 15, N1[nr1].y1 - 10);
                line(N1[nr1].x1 - 15, N1[nr1].y1 - 10, N1[nr1].x2 + 15, N1[nr1].y1 - 10);
                line(N1[nr1].x2 + 15, N1[nr1].y1 - 10, N1[nr1].x2 + 15, y1 + 10);
            }
            else
            {
                line(x1, y1 + 10, N1[nr1].x1 - (N1[nr1].x2 - N1[nr1].x1) - 15, y1 + 10);
                line(N1[nr1].x1 - (N1[nr1].x2 - N1[nr1].x1) - 15, y1 + 10, N1[nr1].x1 - (N1[nr1].x2 - N1[nr1].x1) - 15, N1[nr1].y1 - 10);
                line(N1[nr1].x1 - (N1[nr1].x2 - N1[nr1].x1) - 15, N1[nr1].y1 - 10, N1[nr1].x2 + 15, N1[nr1].y1 - 10);
                line(N1[nr1].x2 + 15, N1[nr1].y1 - 10, N1[nr1].x2 + 15, y1 + 10);

            }
            if (N1[nr1].x2 + 15 > mij)
                mij = N1[nr1].x2 + 15;
            else
                line(N1[nr1].x2 + 15, y1 + 10, mij, y1 + 10);
        }
        else
        {
            if (N1[nr1].tip != 'D')
            {
                line(x1, y1 + 10, N1[nr1].x2 + 15, y1 + 10);
                line(N1[nr1].x2 + 15, y1 + 10, N1[nr1].x2 + 15, N1[nr1].y1 - 10);
                line(N1[nr1].x2 + 15, N1[nr1].y1 - 10, N1[nr1].x1 - 15, N1[nr1].y1 - 10);
                line(N1[nr1].x1 - 15, N1[nr1].y1 - 10, N1[nr1].x1 - 15, y1 + 10);

                if (N1[nr1].x1 - 15 < mij)
                    mij = N1[nr1].x1 - 15;
                else
                    line(N1[nr1].x1 - 15, y1 + 10, mij, y1 + 10);
            }
            else
            {
                line(x1, y1 + 10, N1[nr1].x2 + 15, y1 + 10);
                line(N1[nr1].x1 - (N1[nr1].x2 - N1[nr1].x1) - 15, y1 + 10, N1[nr1].x1 - (N1[nr1].x2 - N1[nr1].x1) - 15, N1[nr1].y1 - 10);
                line(N1[nr1].x1 - (N1[nr1].x2 - N1[nr1].x1) - 15, N1[nr1].y1 - 10, N1[nr1].x2 + 15, N1[nr1].y1 - 10);
                line(N1[nr1].x2 + 15, N1[nr1].y1 - 10, N1[nr1].x2 + 15, y1 + 10);
                if (N1[nr1].x1 - (N1[nr1].x2 - N1[nr1].x1) - 15 < mij)
                    mij = N1[nr1].x1 - (N1[nr1].x2 - N1[nr1].x1) - 15;
                else
                    line(N1[nr1].x1 - 15, y1 + 10, mij, y1 + 10);

            }


        }
    }


    int nr2 = intalnire_bloc1_incarcare_schema(y1 + 10, mij, y2 - 15, mij, N1, nrr_b);//pentru a2a linie (cea verticala)
    if (nr2 == -1)
        line(mij, y1 + 10, mij, y2 - 15);
    else
    {
        if (y1 < y2)
        {
            line(mij, y1 + 10, mij, N1[nr2].y1 - 15);
            line(mij, N1[nr2].y1 - 15, N1[nr2].x2 + 15, N1[nr2].y1 - 15);
            if (N1[nr2].y2 + 15 < y2 - 15)
            {
                line(N1[nr2].x2 + 15, N1[nr2].y1 - 15, N1[nr2].x2 + 15, N1[nr2].y2 + 15);
                line(N1[nr2].x2 + 15, N1[nr2].y2 + 15, mij, N1[nr2].y2 + 15);
                line(mij, N1[nr2].y2 + 15, mij, y2 - 15);
            }
            else
            {
                line(N1[nr2].x2 + 15, N1[nr2].y1 - 15, N1[nr2].x2 + 15, y2 - 15);
                mij = N1[nr2].x2 + 15;

            }


        }
        else
        {
            line(mij, y1 + 10, mij, N1[nr2].y2 + 15);
            line(mij, N1[nr2].y2 + 15, N1[nr2].x2 + 15, N1[nr2].y2 + 15);
            if (N1[nr2].y1 - 15 > y2 - 15)
            {
                line(N1[nr2].x2 + 15, N1[nr2].y2 + 15, N1[nr2].x2 + 15, N1[nr2].y1 - 15);
                line(N1[nr2].x2 + 15, N1[nr2].y1 - 15, mij, N1[nr2].y1 - 15);
                line(mij, N1[nr2].y1 - 15, mij, y2 - 15);
            }
            else
            {
                line(N1[nr2].x2 + 15, N1[nr2].y2 + 15, N1[nr2].x2 + 15, y2 - 15);
                mij = N1[nr2].x2 + 15;
            }



        }


    }

    int nr3 = intalnire_bloc_incarcare_schema(x2, y2 - 15, mij, y2 - 15, N1, nrr_b);//pentru a3a linie (a2-a orizontala)
    if (nr3 == -1)
        line(mij, y2 - 15, x2, y2 - 15);
    else
    {
        if (x2 > x1)
        {
            if (N1[nr3].tip != 'D')
            {
                line(mij, y2 - 15, N1[nr3].x1 - 15, y2 - 15);
                line(N1[nr3].x1 - 15, y2 - 15, N1[nr3].x1 - 15, N1[nr3].y1 - 10);
                line(N1[nr3].x1 - 15, N1[nr3].y1 - 10, N1[nr3].x2 + 15, N1[nr3].y1 - 10);
                line(N1[nr3].x2 + 15, N1[nr3].y1 - 10, N1[nr3].x2 + 15, y2 - 15);
                line(N1[nr3].x2 + 15, y2 - 15, x2, y2 - 15);
            }
            else
            {
                line(mij, y2 - 15, N1[nr3].x1 - (N1[nr3].x2 - N1[nr3].x1) - 15, y2 - 15);
                line(N1[nr3].x1 - (N1[nr3].x2 - N1[nr3].x1) - 15, y2 - 15, N1[nr3].x1 - (N1[nr3].x2 - N1[nr3].x1) - 15, N1[nr3].y1 - 10);
                line(N1[nr3].x1 - (N1[nr3].x2 - N1[nr3].x1) - 15, N1[nr3].y1 - 10, N1[nr3].x2 + 15, N1[nr3].y1 - 10);
                line(N1[nr3].x2 + 15, N1[nr3].y1 - 10, N1[nr3].x2 + 15, y2 - 15);
                line(N1[nr3].x2 + 15, y2 - 15, x2, y2 - 15);

            }
        }
        else
        {
            if (N1[nr3].tip != 'D')
            {
                line(mij, y2 - 15, N1[nr3].x2 + 15, y2 - 15);
                line(N1[nr3].x2 + 15, y2 - 15, N1[nr3].x2 + 15, N1[nr3].y1 - 10);
                line(N1[nr3].x2 + 15, N1[nr3].y1 - 10, N1[nr3].x1 - 15, N1[nr3].y1 - 10);
                line(N1[nr3].x1 - 15, N1[nr3].y1 - 10, N1[nr3].x1 - 15, y2 - 15);
                line(N1[nr3].x1 - 15, y2 - 15, x2, y2 - 15);
            }
            else
            {
                line(mij, y2 - 15, N1[nr3].x2 + 15, y2 - 15);
                line(N1[nr3].x2 + 15, y2 - 15, N1[nr3].x2 + 15, N1[nr3].y1 - 10);
                line(N1[nr3].x2 + 15, N1[nr3].y1 - 10, N1[nr3].x1 - (N1[nr3].x2 - N1[nr3].x1) - 15, N1[nr3].y1 - 10);
                line(N1[nr3].x1 - (N1[nr3].x2 - N1[nr3].x1) - 15, N1[nr3].y1 - 10, N1[nr3].x1 - (N1[nr3].x2 - N1[nr3].x1) - 15, y2 - 15);
                line(N1[nr3].x1 - (N1[nr3].x2 - N1[nr3].x1) - 15, y2 - 15, x2, y2 - 15);

            }
        }

    }
    line(x2, y2 - 15, x2, y2);
    line(x2, y2 - 5, x2 + 4, y2 - 13);
    line(x2, y2 - 5, x2 - 4, y2 - 13);
    setlinestyle(0, 0, 3);


}

void redeseneaza_legaturi(nod N1[], legatura L1[], int nrr_noduri, int nrr_legaturi)//Andrei
{

    for (int i = 1; i <= nrr_legaturi; i++)
    {
        if (L1[i].punct1 == 0 && N1[L1[i].nod1].sters == 0)
            drawLine(N1[L1[i].nod1].pLeg[0].x, N1[L1[i].nod1].pLeg[0].y, N1[L1[i].nod2].pLeg[1].x, N1[L1[i].nod2].pLeg[1].y, N1[L1[i].nod1].culoarelegaturi, N1, nrr_noduri);
        if (L1[i].punct1 == 2 && N1[L1[i].nod1].sters == 0)
            drawLine(N1[L1[i].nod1].pLeg[2].x, N1[L1[i].nod1].pLeg[2].y, N1[L1[i].nod2].pLeg[1].x, N1[L1[i].nod2].pLeg[1].y, N1[L1[i].nod1].culoarelegaturi2, N1, nrr_noduri);
    }
}


void legaturi_sterse(int nod)//Andrei
{
    for (int i = 1; i <= nrLegaturi; i++)
    {
        if (vecLegaturi[i].nod1 == nod)
        {
            if (vecLegaturi[i].punct1 == 0)
                drawLine(vecNoduri[vecLegaturi[i].nod1].pLeg[0].x, vecNoduri[vecLegaturi[i].nod1].pLeg[0].y, vecNoduri[vecLegaturi[i].nod2].pLeg[1].x, vecNoduri[vecLegaturi[i].nod2].pLeg[1].y, culbk, vecNoduri, index);
            if (vecLegaturi[i].punct1 == 2)
                drawLine(vecNoduri[vecLegaturi[i].nod1].pLeg[2].x, vecNoduri[vecLegaturi[i].nod1].pLeg[2].y, vecNoduri[vecLegaturi[i].nod2].pLeg[1].x, vecNoduri[vecLegaturi[i].nod2].pLeg[1].y, culbk, vecNoduri, index);
        }
        else if (vecLegaturi[i].nod2 == nod)
        {
            if (vecLegaturi[i].punct1 == 0)
                drawLine(vecNoduri[vecLegaturi[i].nod1].pLeg[0].x, vecNoduri[vecLegaturi[i].nod1].pLeg[0].y, vecNoduri[vecLegaturi[i].nod2].pLeg[1].x, vecNoduri[vecLegaturi[i].nod2].pLeg[1].y, culbk, vecNoduri, index);
            if (vecLegaturi[i].punct1 == 2)
                drawLine(vecNoduri[vecLegaturi[i].nod1].pLeg[2].x, vecNoduri[vecLegaturi[i].nod1].pLeg[2].y, vecNoduri[vecLegaturi[i].nod2].pLeg[1].x, vecNoduri[vecLegaturi[i].nod2].pLeg[1].y, culbk, vecNoduri, index);
        }
    }
}

void stergere_bloc(int x, int y, int nr_bloc)//Andrei
{
    if (vecNoduri[nr_bloc].tip == 'I')
    {
        inittrapez(vecNoduri[nr_bloc], vecNoduri[nr_bloc].info, culbk, vecNoduri[nr_bloc].x1, vecNoduri[nr_bloc].y1, vecNoduri[nr_bloc].x2, vecNoduri[nr_bloc].y2, vecNoduri[nr_bloc].lungtext);
        deseneazatrapezsters(vecNoduri[nr_bloc]);
        legaturi_sterse(nr_bloc);
    }
    else if (vecNoduri[nr_bloc].tip == 'C')
    {
        initdreptunghiC(vecNoduri[nr_bloc], vecNoduri[nr_bloc].info, culbk, vecNoduri[nr_bloc].x1, vecNoduri[nr_bloc].y1, vecNoduri[nr_bloc].x2, vecNoduri[nr_bloc].y2);
        deseneazadreptunghiCsters(vecNoduri[nr_bloc]);
        legaturi_sterse(nr_bloc);
    }
    else if (vecNoduri[nr_bloc].tip == 'D')
    {
        inittriunghi(vecNoduri[nr_bloc], vecNoduri[nr_bloc].info, culbk, vecNoduri[nr_bloc].x1, vecNoduri[nr_bloc].y1, vecNoduri[nr_bloc].x2, vecNoduri[nr_bloc].y2, vecNoduri[nr_bloc].lungtext);
        deseneazatriunghisters(vecNoduri[nr_bloc]);
        legaturi_sterse(nr_bloc);
    }
    else if (vecNoduri[nr_bloc].tip == 'O')
    {
        inittrapezO(vecNoduri[nr_bloc], vecNoduri[nr_bloc].info, culbk, vecNoduri[nr_bloc].x1, vecNoduri[nr_bloc].y1, vecNoduri[nr_bloc].x2, vecNoduri[nr_bloc].y2);
        deseneazatrapezOsters(vecNoduri[nr_bloc]);
        legaturi_sterse(nr_bloc);
    }


}
void sterge_legaturi1(nod N1[], legatura L1[], int nrr_legaturi, int nrr_noduri)//Cosmin
{
    for (int i = 1; i <= nrr_legaturi; i++)
    {
        int x11 = N1[L1[i].nod1].pLeg[0].x;
        int y11 = N1[L1[i].nod1].pLeg[0].y;
        int x12 = N1[L1[i].nod1].pLeg[2].x;
        int y12 = N1[L1[i].nod1].pLeg[2].y;
        int x2 = N1[L1[i].nod2].pLeg[1].x;
        int y2 = N1[L1[i].nod2].pLeg[1].y;
        if (N1[L1[i].nod2].sters == 0)
        {
            if (x11 != 0 && y11 != 0 && L1[i].nod2 != 0 && L1[i].nod2 != -1)
                drawLine(x11, y11, x2, y2, culbk, N1, nrr_noduri);
            if (x12 != 0 && y12 != 0 && L1[i].nod2 != 0 && L1[i].nod2 != -1)
                drawLine(x12, y12, x2, y2, culbk, N1, nrr_noduri);
        }

    }
}
void desenare_schema_incarcata(nod N1[MAX_NR], legatura L1[MAX_NR], int nrNoduri1, int nrLegaturi1)//Cosmin
{
    //desenare blocuri
    for (int i = 0; i < nrNoduri1; i++)
    {
        if (N1[i].sters == 0)
        {
            if (N1[i].tip == 'S')
                deseneazadreptunghi(N1[i]);
            else if (N1[i].tip == 'I')
                deseneazatrapez(N1[i]);
            else if (N1[i].tip == 'O')
                deseneazatrapezO(N1[i]);
            else if (N1[i].tip == 'C')
                deseneazadreptunghiC(N1[i]);
            else if (N1[i].tip == 'T')
                deseneazastop(N1[i]);
            else if (N1[i].tip == 'D')
                deseneazatriunghi(N1[i]);
        }
    }
    //desenare Legaturi
    for (int i = 1; i <= nrLegaturi1; i++)
    {
        if (L1[i].nod2 != -1 && N1[L1[i].nod1].sters != 1 && L1[i].nod2 != 0 && N1[L1[i].nod1].x1 != 0)
        {
            int x1, y1, x2, y2;
            x2 = N1[L1[i].nod2].pLeg[1].x;
            y2 = N1[L1[i].nod2].pLeg[1].y;

            if (N1[L1[i].nod1].tip != 'D')
            {
                x1 = N1[L1[i].nod1].pLeg[0].x;
                y1 = N1[L1[i].nod1].pLeg[0].y;
            }
            else
            {
                if (L1[i].tipleg == 'F')//a 2-a legatura (ramura Fals)
                {
                    x1 = N1[L1[i].nod1].pLeg[2].x;
                    y1 = N1[L1[i].nod1].pLeg[2].y;
                }
                else
                {
                    x1 = N1[L1[i].nod1].pLeg[0].x;
                    y1 = N1[L1[i].nod1].pLeg[0].y;
                }
            }
            drawLine(x1, y1, x2, y2, 15, N1, nrNoduri1);
        }
    }

}
void desenare_cadre()//Cosmin
{
    setfillstyle(1, culfundal);
    bar(165, 77, 1195, 89);
    bar(1186, 85, 1200, 785);
    bar(170, 776, 1190, 795);
    bar(166, 85, 179, 780);
    setfillstyle(0, culbk);
}
void muta_bloc1(int x, int y, int nr_bloc, nod N1[], legatura L1[], int nrr_noduri, int nrr_legaturi)//Andrei si Cosmin
{
    int x1, y1, x2, y2, x3, y3;
    setfillstyle(0, culbk);
    if (N1[nr_bloc].tip != 'D')
        bar(N1[nr_bloc].x1 - 20, N1[nr_bloc].y1 - 6, N1[nr_bloc].x2 + 17, N1[nr_bloc].y2 + 6);
    else if (N1[nr_bloc].tip == 'D')
        deseneazatriunghimutat(N1[nr_bloc]);
    int x_release = 0, y_release = 0;
    clearmouseclick(WM_LBUTTONUP);
    int ok_cadru1 = 1, ok_cadru2 = 1, ok_cadru3 = 1;
    while (!ismouseclick(WM_LBUTTONUP) && ok_cadru1 && ok_cadru2 && ok_cadru3)
    {


        if (N1[nr_bloc].tip == 'D')
        {
            if (!(mousex() - (N1[nr_bloc].x2 - N1[nr_bloc].x1) - 20 >= 180))
            {
                ok_cadru1 = 0;
                x_release = 180 + (N1[nr_bloc].x2 - N1[nr_bloc].x1) + 20;
            }
            if (!(mousey() + (N1[nr_bloc].y2 - N1[nr_bloc].y1) <= 775))
            {
                y_release = 775 - (N1[nr_bloc].y2 - N1[nr_bloc].y1);
                ok_cadru3 = 0;
            }
        }
        else if (N1[nr_bloc].tip == 'O')
        {
            if (!(mousex() - textwidth(N1[nr_bloc].info) >= 180))
            {
                x_release = 180 + textwidth(N1[nr_bloc].info);
                ok_cadru1 = 0;
            }
            if (!(mousex() + textwidth(N1[nr_bloc].info) - 40 <= 1185))
            {
                x_release = 1185 - textwidth(N1[nr_bloc].info) - 40;
                ok_cadru2 = 0;
            }
        }
        if (!(mousex() - 40 >= 180 && mousey() - 20 >= 90))
            ok_cadru1 = 0;
        if (!(mousex() + 20 <= 1185))
            ok_cadru2 = 0;

        if (!(mousey() <= 775))
            ok_cadru3 = 0;
    };
    clearmouseclick(WM_LBUTTONUP);
    if (x_release == 0)
    {
        x_release = mousex();
        y_release = mousey();
    }
    if (y_release == 0)
        y_release = mousey();

    if (!ok_cadru2)

        x_release -= 150;

    if (!ok_cadru3)
        y_release -= 45;

    x1 = N1[nr_bloc].pLeg[0].x;
    y1 = N1[nr_bloc].pLeg[0].y;
    x2 = N1[nr_bloc].pLeg[1].x;
    y2 = N1[nr_bloc].pLeg[1].y;
    x3 = N1[nr_bloc].pLeg[2].x;
    y3 = N1[nr_bloc].pLeg[2].y;
    if (N1[nr_bloc].tip == 'S')
    {
        initdreptunghi(N1[nr_bloc], N1[nr_bloc].info, N1[nr_bloc].culoare, x_release, y_release, x_release + lungimeBlocStart, y_release + latimeBlocStart);
        deseneazadreptunghi(N1[nr_bloc]);

    }
    else if (N1[nr_bloc].tip == 'I')
    {
        int p;
        inittrapez(N1[nr_bloc], N1[nr_bloc].info, N1[nr_bloc].culoare, x_release - N1[nr_bloc].lungtext, y_release, x_release + lungimeBlocInput + N1[nr_bloc].lungtext, y_release + latimeBlocInput, N1[nr_bloc].lungtext);
        deseneazatrapez(N1[nr_bloc]);

    }
    else if (N1[nr_bloc].tip == 'D')
    {
        inittriunghi(N1[nr_bloc], N1[nr_bloc].info, N1[nr_bloc].culoare, x_release, y_release - (N1[nr_bloc].lungtext / 6), x_release + lungimeBlocDecizie + N1[nr_bloc].lungtext, y_release + latimeBlocDecizie, N1[nr_bloc].lungtext);
        deseneazatriunghi(N1[nr_bloc]);

    }
    else if (N1[nr_bloc].tip == 'O')
    {
        int p;
        inittrapezO(N1[nr_bloc], N1[nr_bloc].info, N1[nr_bloc].culoare, x_release - N1[nr_bloc].lungtext, y_release, x_release + N1[nr_bloc].lungtext + lungimeBlocOutput, y_release + latimeBlocOutput);
        deseneazatrapezO(N1[nr_bloc]);

    }
    else if (N1[nr_bloc].tip == 'T')
    {
        int p;
        initstop(N1[nr_bloc], N1[nr_bloc].info, N1[nr_bloc].culoare, x_release, y_release, x_release + lungimeBlocStop, y_release + latimeBlocStop);
        deseneazastop(N1[nr_bloc]);

    }
    else if (N1[nr_bloc].tip == 'C')
    {
        int p;
        initdreptunghiC(N1[nr_bloc], N1[nr_bloc].info, N1[nr_bloc].culoare, x_release - N1[nr_bloc].lungtext, y_release, x_release + N1[nr_bloc].lungtext + lungimeBlocInput, y_release + latimeBlocInput);
        deseneazadreptunghiC(N1[nr_bloc]);

    }
    desenare_schema_incarcata(N1, L1, nrr_noduri, nrr_legaturi);
    desenare_cadre();

}

void deseneazaLegatura(int& idNod1, int& p1, int& idNod2, int& p2, int& absc, int& ord, int& absc1, int& ord1, int& iesire)//Andrei
{
    bool click = false;
    int i, xMouse, yMouse, ok = 0, okdec = 0;
    // aleg un punct de legatura (p1) de la nodul 1 (idNod1)
    iesire = 0;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            Beep(2000, 100);
            clearmouseclick(WM_LBUTTONDOWN);
            xMouse = mousex();
            yMouse = mousey();
            absc1 = xMouse;
            ord1 = yMouse;
            for (i = 0; i < index; i++)
            {

                if (vecNoduri[i].tip != 'S' && vecNoduri[i].ok2 > 0)
                {
                    if (vecNoduri[i].tip == 'D')
                    {
                        if (abs(vecNoduri[i].pLeg[0].x - xMouse) <= 5
                                && abs(vecNoduri[i].pLeg[0].y - yMouse) <= 5 && vecNoduri[i].ok1 == 0)
                        {
                            Beep(2000, 100);
                            //cout<<1<<endl;
                            idNod1 = i;
                            p1 = 0;
                            click = true;
                            vecNoduri[i].ok1++;
                            ok = 1;
                        }
                        else if (abs(vecNoduri[i].pLeg[2].x - xMouse) <= 5
                                 && abs(vecNoduri[i].pLeg[2].y - yMouse) <= 5 && vecNoduri[i].ok1 == 1)
                        {
                            Beep(2000, 100);
                            idNod1 = i;
                            p1 = 2;
                            click = true;
                            vecNoduri[i].ok1++;
                            ok = 1;
                        }
                        else if (abs(vecNoduri[i].pLeg[2].x - xMouse) <= 5
                                 && abs(vecNoduri[i].pLeg[2].y - yMouse) <= 5 && vecNoduri[i].ok1 != 1)
                            okdec = 1;
                    }
                    else
                    {
                        if (abs(vecNoduri[i].pLeg[0].x - xMouse) <= 5
                                && abs(vecNoduri[i].pLeg[0].y - yMouse) <= 5 && vecNoduri[i].ok1 == 0)
                        {
                            Beep(2000, 100);
                            idNod1 = i;
                            p1 = 0;
                            click = true;
                            vecNoduri[i].ok1 = 1;
                            ok = 1;
                        }
                        else if (abs(vecNoduri[i].pLeg[2].x - xMouse) <= 5
                                 && abs(vecNoduri[i].pLeg[2].y - yMouse) <= 5 && vecNoduri[i].ok1 == 0)
                        {
                            Beep(2000, 100);
                            idNod1 = i;
                            p1 = 2;
                            click = true;
                            vecNoduri[i].ok1 = 1;
                            ok = 1;
                        }
                    }
                }
                else if (vecNoduri[i].tip == 'S')
                {
                    if (abs(vecNoduri[i].pLeg[0].x - xMouse) <= 5
                            && abs(vecNoduri[i].pLeg[0].y - yMouse) <= 5 && vecNoduri[i].ok1 == 0)
                    {
                        Beep(2000, 100);
                        idNod1 = i;
                        p1 = 0;
                        click = true;
                        vecNoduri[i].ok1 = 1;
                        ok = 1;
                    }
                }

            }
            if (ok == 0)
            {

                if (okdec == 0)
                {
                    myOuttextXY(1360, 700, 4, "Blocul trebuie sa fie");
                    myOuttextXY(1360, 720, 4, "legat!");
                }
                else
                {
                    myOuttextXY(1360, 700, 4, "Trebuie legata");
                    myOuttextXY(1360, 720, 4, "ramura true(stanga)!");
                }
                Beep(1500, 100);
                iesire = 1;
            }
        }
    }
    while (!click && iesire == 0);
    // aleg un punct de legatura (p2) de la nodul 2 (idNod2)Beep(2000,100);
    // pana aleg, desenez mereu o linie
    click = false;
    int x1, y1, x2, y2;
    if (!iesire)
    {
        x1 = vecNoduri[idNod1].pLeg[p1].x;
        y1 = vecNoduri[idNod1].pLeg[p1].y;
        xMouse = mousex();
        yMouse = mousey();
    }
    int no;
    do
    {
        no = 0;
        ok = 0;
        if (xMouse - 20 < 180)
            xMouse = 180 + 20;
        if (xMouse + 20 > 1185)
            xMouse = 1185 - 20;
        if (yMouse - 20 < 90)
            yMouse = 90 + 20;
        if (yMouse + 20 > 775)
            yMouse = 775 - 20;
        if (!iesire && este_selectata_mutarea_unui_bloc1(xMouse, yMouse, vecNoduri, index) == -1)
        {
            drawLine(x1, y1, xMouse, yMouse, 15, vecNoduri, index);
            delay(50);
            drawLine(x1, y1, xMouse, yMouse, culbk, vecNoduri, index);
            xMouse = mousex();
            yMouse = mousey();
        }
        xMouse = mousex();
        yMouse = mousey();
        if (ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            Beep(1200, 100);
            clearmouseclick(WM_LBUTTONDOWN);
            xMouse = mousex();
            yMouse = mousey();
            absc = xMouse;
            ord = yMouse;
            for (i = 0; i < index; i++)
            {
                if (vecNoduri[i].tip != 'T' && vecNoduri[i].tip != 'D')
                {
                    if (abs(vecNoduri[i].pLeg[1].x - xMouse) <= 5
                            && abs(vecNoduri[i].pLeg[1].y - yMouse) <= 5 && vecNoduri[i].ok2 == 0 && !iesire)
                    {
                        idNod2 = i;
                        p2 = 1;
                        click = true;
                        vecNoduri[i].ok2 = 1;
                    }
                    else if (iesire == 1)
                        click = true;
                }
                else if (vecNoduri[i].tip == 'T' || vecNoduri[i].tip == 'D')
                {
                    if (abs(vecNoduri[i].pLeg[1].x - xMouse) <= 5
                            && abs(vecNoduri[i].pLeg[1].y - yMouse) <= 5 && !iesire)
                    {
                        idNod2 = i;
                        p2 = 1;
                        click = true;
                        vecNoduri[i].ok2 = 1;
                        vecNoduri[i].cnt++;
                    }
                    else if (iesire == 1)
                        click = true;
                }

            }
        }
    }
    while (!click);

    if (!iesire)
    {
        if (p1 == 0)
        {
            vecNoduri[idNod2].tiplegatS1 = vecNoduri[idNod1].tip;
            vecNoduri[idNod1].tiplegatJ1 = vecNoduri[idNod2].tip;

        }

        if (p1 == 2)
        {
            vecNoduri[idNod2].tiplegatS2 = vecNoduri[idNod1].tip;
            vecNoduri[idNod1].tiplegatJ2 = vecNoduri[idNod2].tip;
        }
        x2 = vecNoduri[idNod2].pLeg[p2].x;
        y2 = vecNoduri[idNod2].pLeg[p2].y;
        drawLine(x1, y1, x2, y2, 15, vecNoduri, index);
    }
    desenare_schema_incarcata(vecNoduri, vecLegaturi, index, nrLegaturi);

}
void convchtoint(int a, char s[MAX])//Andrei
{
    int v[MAX];
    int k = 0;
    int x = 0;
    int neg = 0;
    if (a < 0)
    {
        neg = 1;
        a = -a;
    }
    v[k++] = a % 10;
    a /= 10;
    while (a)
    {
        v[k++] = a % 10;
        a /= 10;
    }
    if (neg == 1)
        s[x++] = '-';
    for (int i = k - 1; i >= 0; i--)
        s[x++] = v[i] + '0';
    s[x] = '\0';
}
int okStart = 1;
int estetext(char s[MAX])//Andrei
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] < 'a' || s[i]>'z')
            return 0;
    return 1;
}
int estenr(char s[MAX])//Andrei
{
    if (s[0] == '-')
    {
        for (int i = 1; i < strlen(s); i++)
            if (s[i] < '0' || s[i]>'9')
                return 0;
    }
    else
    {
        for (int i = 0; i < strlen(s); i++)
            if (s[i] < '0' || s[i]>'9')
                return 0;
    }
    return 1;
}
void executa(nod N1[], legatura L1[], int nrr_noduri, int nrr_legaturi)//Andrei
{
    myOuttextXY(1360, 720, culbk, rez);
    myOuttextXY(1360, 700, culbk, "Rezultatul este:");
    strcpy(rez, "");
    int cnt = 0, aux = 0;
    int leg;
    bool ok = true;
    for (int i = 0; i <= 26; i++)
        vecLitere[i] = infinit;
    int y = 0;
    int x;
    while (N1[y].tip != 'T')
    {
        for (int i = 1; i <= nrr_legaturi; i++)
        {
            if (L1[i].nod1 == y)
            {
                //
                if (N1[L1[i].nod1].tip == 'I')
                {
                    Spot point;
                    Spot interogation;
                    int neg = 0;
                    x = L1[i].nod1;
                    int k;
                    interogation.xPos = 1360;
                    interogation.yPos = 760;
                    point.xPos = 1360;
                    point.yPos = 720;
                    scan_window_textInput(point, 10, interogation, L1[i].nod1, N1);

                }

                if (N1[L1[i].nod1].tip == 'C')
                {
                    x = L1[i].nod1;
                    if (incrementare(N1[x].info) == 1)
                        vecLitere[N1[x].info[0] - 'a']++;
                    else if (decrementare(N1[x].info) == 1)
                        vecLitere[N1[x].info[0] - 'a']--;
                    else
                        vecLitere[N1[x].info[0] - 'a'] = aduna(N1[x].info);
                }
                if (N1[L1[i].nod1].tip == 'O')
                {
                    x = L1[i].nod1;
                    myOuttextXY(1360, 700, 0, "Rezultatul este:");
                    if (N1[L1[i].nod1].info[0] == '"')
                    {
                        strcat(rez, N1[L1[i].nod1].info + 1);
                        rez[strlen(rez) - 1] = 0;
                        strcat(rez, " ");
                    }
                    else if (strlen(N1[L1[i].nod1].info) == 1 && estetext(N1[L1[i].nod1].info))
                    {
                        convchtoint(vecLitere[N1[x].info[0] - 'a'], s);
                        strcat(rez, s);
                        strcat(rez, " ");
                    }
                    else if (estenr(N1[L1[i].nod1].info))
                    {
                        strcat(rez, N1[L1[i].nod1].info);
                        strcat(rez, " ");
                    }
                    else
                    {
                        int val;
                        val = evalO(N1[L1[i].nod1].info);

                        convchtoint(val, s);
                        strcat(rez, s);
                        strcat(rez, " ");
                    }

                    myOuttextXY(1360, 720, 0, rez);

                }
                if (N1[L1[i].nod1].tip != 'D' && N1[L1[i].nod1].tip != 'T')
                {
                    drawLine(N1[L1[i].nod1].pLeg[0].x, N1[L1[i].nod1].pLeg[0].y, N1[L1[i].nod2].pLeg[1].x, N1[L1[i].nod2].pLeg[1].y, 4, N1, nrr_noduri);
                    delay(700);
                    drawLine(N1[L1[i].nod1].pLeg[0].x, N1[L1[i].nod1].pLeg[0].y, N1[L1[i].nod2].pLeg[1].x, N1[L1[i].nod2].pLeg[1].y, 15, N1, nrr_noduri);
                    y = L1[i].nod2;
                }
                if (N1[L1[i].nod1].tip == 'D')
                {

                    x = L1[i].nod1;

                    if (eval(N1[x].info) == 1)
                    {
                        if (x == aux)
                        {
                            i = leg;
                            drawLine(N1[L1[i].nod1].pLeg[0].x, N1[L1[i].nod1].pLeg[0].y, N1[L1[i].nod2].pLeg[1].x, N1[L1[i].nod2].pLeg[1].y, 4, N1, nrr_noduri);
                            delay(700);
                            drawLine(N1[L1[i].nod1].pLeg[0].x, N1[L1[i].nod1].pLeg[0].y, N1[L1[i].nod2].pLeg[1].x, N1[L1[i].nod2].pLeg[1].y, 15, N1, nrr_noduri);
                            y = L1[i].nod2;
                            aux = 0;
                            N1[x].loop++;

                        }
                        else
                        {
                            drawLine(N1[L1[i].nod1].pLeg[0].x, N1[L1[i].nod1].pLeg[0].y, N1[L1[i].nod2].pLeg[1].x, N1[L1[i].nod2].pLeg[1].y, 4, N1, nrr_noduri);
                            delay(700);
                            drawLine(N1[L1[i].nod1].pLeg[0].x, N1[L1[i].nod1].pLeg[0].y, N1[L1[i].nod2].pLeg[1].x, N1[L1[i].nod2].pLeg[1].y, 15, N1, nrr_noduri);
                            y = L1[i].nod2;
                        }
                        if (N1[x].cnt >= 2)
                        {
                            int ind;
                            ok = true;
                            cnt = 1;
                            aux = L1[i].nod1;
                            leg = i;
                        }
                    }
                    else if (eval(N1[x].info) == 0)
                    {
                        ok = false;
                        if (N1[x].cnt >= 2)
                        {
                            if (x == aux)
                                N1[x].loop++;

                            if (N1[x].loop != 0)
                            {
                                for (int j = 1; j <= nrr_legaturi; j++)
                                    if (L1[j].nod1 == L1[i].nod1 && L1[j].nod2 == L1[i].nod2 && N1[L1[i].nod2].tiplegat == 'F')
                                        y = L1[j].nod2;
                                if (y != L1[i].nod1)
                                {
                                    drawLine(N1[L1[i].nod1].pLeg[2].x, N1[L1[i].nod1].pLeg[2].y, N1[y].pLeg[1].x, N1[y].pLeg[1].y, 4, N1, nrr_noduri);
                                    delay(700);
                                    drawLine(N1[L1[i].nod1].pLeg[2].x, N1[L1[i].nod1].pLeg[2].y, N1[y].pLeg[1].x, N1[y].pLeg[1].y, 15, N1, nrr_noduri);
                                }
                            }
                            else
                            {
                                for (int j = 1; j <= nrr_legaturi; j++)
                                    if (L1[j].nod1 == L1[i].nod1 && L1[j].nod2 != L1[i].nod2)
                                        y = L1[j].nod2;
                                drawLine(N1[L1[i].nod1].pLeg[2].x, N1[L1[i].nod1].pLeg[2].y, N1[y].pLeg[1].x, N1[y].pLeg[1].y, 4, N1, nrr_noduri);
                                delay(700);
                                drawLine(N1[L1[i].nod1].pLeg[2].x, N1[L1[i].nod1].pLeg[2].y, N1[y].pLeg[1].x, N1[y].pLeg[1].y, 15, N1, nrr_noduri);
                            }
                        }
                        else
                        {
                            for (int j = 1; j <= nrr_legaturi; j++)
                                if (L1[j].nod1 == L1[i].nod1 && L1[j].nod2 != L1[i].nod2)
                                    y = L1[j].nod2;
                            drawLine(N1[L1[i].nod1].pLeg[2].x, N1[L1[i].nod1].pLeg[2].y, N1[y].pLeg[1].x, N1[y].pLeg[1].y, 4, N1, nrr_noduri);
                            delay(700);
                            drawLine(N1[L1[i].nod1].pLeg[2].x, N1[L1[i].nod1].pLeg[2].y, N1[y].pLeg[1].x, N1[y].pLeg[1].y, 15, N1, nrr_noduri);
                        }
                    }

                }
            }

        }

    }
}
void mouse_hover(int& xMouse, int& yMouse)//Cosmin
{
    bool nu_este_facut_click = 1;
    while (nu_este_facut_click)
    {
        xMouse = mousex();
        yMouse = mousey();
        setfillstyle(0, culbk);

        if (ismouseclick(WM_LBUTTONDOWN))
            nu_este_facut_click = 0;
        if (este_selectat_Exit(xMouse, yMouse))
        {
            myOuttextXY(1140, 45, 9, "Exit");
            while (este_selectat_Exit(xMouse, yMouse) && nu_este_facut_click)
            {
                xMouse = mousex();
                yMouse = mousey();
                setcolor(15);
                rectangle(1100, 15, 1185, 75);
                rectangle(1100, 14, 1185, 74);
                rectangle(1100, 13, 1185, 73);
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            setcolor(culbk);
            rectangle(1100, 15, 1185, 75);
            rectangle(1100, 14, 1185, 74);
            rectangle(1100, 13, 1185, 73);
            myOuttextXY(1140, 45, 15, "Exit");
        }
        else if (este_selectat_creare_schema(xMouse, yMouse))
        {
            myOuttextXY(292, 45, 9, "Creare schema noua");
            while (este_selectat_creare_schema(xMouse, yMouse) && nu_este_facut_click)
            {
                xMouse = mousex();
                yMouse = mousey();
                setcolor(15);
                rectangle(180, 15, 405, 75);
                rectangle(180, 14, 405, 74);
                rectangle(180, 13, 405, 73);
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            setcolor(culbk);
            rectangle(180, 15, 405, 75);
            rectangle(180, 14, 405, 74);
            rectangle(180, 13, 405, 73);
            myOuttextXY(292, 45, 15, "Creare schema noua");
        }
        else if (este_selectat_salvare_schema(xMouse, yMouse))
        {
            myOuttextXY(772, 45, 9, "Salvare schema");
            while (este_selectat_salvare_schema(xMouse, yMouse) && nu_este_facut_click)
            {
                xMouse = mousex();
                yMouse = mousey();
                setcolor(15);
                rectangle(660, 15, 885, 75);
                rectangle(660, 14, 885, 74);
                rectangle(660, 13, 885, 73);
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            setcolor(culbk);
            rectangle(660, 15, 885, 75);
            rectangle(660, 14, 885, 74);
            rectangle(660, 13, 885, 73);
            myOuttextXY(772, 45, 15, "Salvare schema");
        }
        else if (este_selectat_incarcare_schema(xMouse, yMouse))
        {
            myOuttextXY(532, 45, 9, "Incarcare schema");
            while (este_selectat_incarcare_schema(xMouse, yMouse) && nu_este_facut_click)
            {
                xMouse = mousex();
                yMouse = mousey();
                setcolor(15);
                rectangle(420, 15, 645, 75);
                rectangle(420, 14, 645, 74);
                rectangle(420, 12, 645, 73);
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            setcolor(culbk);
            rectangle(420, 15, 645, 75);
            rectangle(420, 14, 645, 74);
            rectangle(420, 12, 645, 73);
            myOuttextXY(532, 45, 15, "Incarcare schema");

        }

        if (ok_schema_creata)
        {
            if (este_selectat_bloculRUN(xMouse, yMouse))
            {
                if (culbk == 12)
                    myOuttextXY(85, 45, 4, "RUN");
                else
                    myOuttextXY(85, 45, 0, "RUN");
                while (este_selectat_bloculRUN(xMouse, yMouse) && nu_este_facut_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    setcolor(15);
                    rectangle(15, 15, 165, 75);
                    rectangle(15, 14, 165, 74);
                    rectangle(15, 13, 165, 73);
                    if (ismouseclick(WM_LBUTTONDOWN))
                        nu_este_facut_click = 0;
                }
                setcolor(culbk);
                rectangle(15, 15, 165, 75);
                rectangle(15, 14, 165, 74);
                rectangle(15, 13, 165, 73);
                myOuttextXY(85, 45, 15, "RUN");
            }
            if (nu_este_oprita_desenarea1(xMouse, yMouse))
            {
                if (culbk == 12)
                {
                    myOuttextXY(85, 715, 4, "OPRIRE");
                    myOuttextXY(85, 745, 4, "DESENARE");
                }
                else
                {
                    myOuttextXY(85, 715, 0, "OPRIRE");
                    myOuttextXY(85, 745, 0, "DESENARE");

                }
                while (nu_este_oprita_desenarea1(xMouse, yMouse) && nu_este_facut_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    setcolor(15);
                    rectangle(15, 680, 165, 775);
                    rectangle(15, 679, 165, 774);
                    rectangle(15, 678, 165, 773);
                    if (ismouseclick(WM_LBUTTONDOWN))
                        nu_este_facut_click = 0;
                }
                setcolor(culbk);
                rectangle(15, 680, 165, 775);
                rectangle(15, 679, 165, 774);
                rectangle(15, 678, 165, 773);
                myOuttextXY(85, 715, 15, "OPRIRE");
                myOuttextXY(85, 745, 15, "DESENARE");
            }
            if (este_selectat_bloculSTERGERE(xMouse, yMouse))
            {
                if (culbk == 12)
                    myOuttextXY(990, 45, 4, "STERGERE");
                else
                    myOuttextXY(990, 45, 0, "STERGERE");

                while (este_selectat_bloculSTERGERE(xMouse, yMouse) && nu_este_facut_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    setcolor(15);
                    rectangle(900, 15, 1085, 75);
                    rectangle(900, 14, 1085, 74);
                    rectangle(900, 13, 1085, 73);
                    if (ismouseclick(WM_LBUTTONDOWN))
                        nu_este_facut_click = 0;
                }
                setcolor(culbk);
                rectangle(900, 15, 1085, 75);
                rectangle(900, 14, 1085, 74);
                rectangle(900, 13, 1085, 73);
                myOuttextXY(990, 45, 15, "STERGERE");
            }
            if (este_selectat_bloculSTART1(xMouse, yMouse))
            {
                myOuttextXY(90, 135, 7, "START");
                while (este_selectat_bloculSTART1(xMouse, yMouse) && nu_este_facut_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN))
                        nu_este_facut_click = 0;
                }
                myOuttextXY(90, 135, 15, "START");
            }
            if (este_selectat_bloculINPUT1(xMouse, yMouse))
            {
                myOuttextXY(87, 215, 7, "INPUT");
                while (este_selectat_bloculINPUT1(xMouse, yMouse) && nu_este_facut_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN))
                        nu_este_facut_click = 0;
                }
                myOuttextXY(87, 215, 15, "INPUT");
            }
            if (este_selectat_bloculCALCUL1(xMouse, yMouse))
            {
                myOuttextXY(90, 295, 7, "CALCUL");
                while (este_selectat_bloculCALCUL1(xMouse, yMouse) && nu_este_facut_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN))
                        nu_este_facut_click = 0;
                }
                myOuttextXY(90, 295, 15, "CALCUL");
            }
            if (este_selectat_bloculDECIZIE1(xMouse, yMouse))
            {
                myOuttextXY(85, 415, 7, "DECIZIE");
                while (este_selectat_bloculDECIZIE1(xMouse, yMouse) && nu_este_facut_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN))
                        nu_este_facut_click = 0;
                }
                myOuttextXY(85, 415, 15, "DECIZIE");
            }

            if (este_selectat_bloculOUTPUT1(xMouse, yMouse))
            {
                myOuttextXY(92, 495, 7, "OUTPUT");
                while (este_selectat_bloculOUTPUT1(xMouse, yMouse) && nu_este_facut_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN))
                        nu_este_facut_click = 0;
                }
                myOuttextXY(92, 495, 15, "OUTPUT");
            }
            if (este_selectat_bloculSTOP1(xMouse, yMouse))
            {
                myOuttextXY(89, 575, 7, "STOP");
                while (este_selectat_bloculSTOP1(xMouse, yMouse) && nu_este_facut_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN))
                        nu_este_facut_click = 0;
                }
                myOuttextXY(89, 575, 15, "STOP");
            }
        }
    }
    setfillstyle(0, culbk);

}
void stergereleg(int i)//Andrei
{
    for (int j = i; j <= nrLegaturi; j++)
        vecLegaturi[j] = vecLegaturi[j + 1];
    nrLegaturi--;
}

int ok_Stop = 1;
void desenare1_blocuri()//Andrei si Cosmin
{
    int x1, x2, y1, y2, nr_bloc, rb = 0;
    char c;
    int ok = 0, okstop = 0;
    int xMouse = 0, yMouse = 0, x2Mouse, y2Mouse;
    clearmouseclick(WM_LBUTTONDOWN);
    int i, j, r;

    int idNod1, idNod2, p1, p2;
    nrLegaturi = 0;
    nrNoduri = 10;
    bool click = 0;
    while (!nu_este_oprita_desenarea1(xMouse, yMouse))
    {
        myOuttextXY(1360, 720, culbk, rez);
        myOuttextXY(1360, 700, culbk, "Rezultatul este:");
        myOuttextXY(1360, 700, culbk, "Blocul trebuie sa fie");
        myOuttextXY(1360, 720, culbk, "legat!");
        myOuttextXY(1360, 700, culbk, "Trebuie legata");
        myOuttextXY(1360, 720, culbk, "ramura true(stanga)!");
        myOuttextXY(1360, 700, culbk, "Apasati butonul");
        myOuttextXY(1360, 720, culbk, "OPRIRE DESENARE!");
        myOuttextXY(1360, 700, culbk, "Introduceti blocul");
        myOuttextXY(1360, 700, culbk, "Blocul de START");
        myOuttextXY(1360, 720, culbk, "nu poate fi sters");
        myOuttextXY(1360, 700, culbk, "Blocul de STOP");
        myOuttextXY(1360, 720, culbk, "nu poate fi sters");
        myOuttextXY(1360, 720, culbk, "STOP!");
        myOuttextXY(1360, 720, culbk, "blocul de START");
        myOuttextXY(1360, 700, culbk, "mai intai trebuie introdus");
        //xMouse=mousex();
        //yMouse=mousey();
        mouse_hover(xMouse, yMouse);
        if (este_selectat_bloculSTART1(xMouse, yMouse) && okStart == 1)
        {
            ok = 1;
            initdreptunghi(vecNoduri[index], "START", 14, x1_coord_START + 250, y1_coord_START, x2_coord_START + 250, y2_coord_START);
            deseneazadreptunghi(vecNoduri[index]);
            vecNoduri[index].ok1 = 0;
            vecNoduri[index].ok2 = 0;
            vecNoduri[index].sters = 0;
            vecNoduri[index].culoarecerc = 15;
            vecNoduri[index].culoarelegaturi = 15;
            index++;
            desenare1_dreptunghi(x1_coord_START, y1_coord_START, x2_coord_START, y2_coord_START, 8);
            myOuttextXY(90, 135, 7, "START");
            click = 0;

            okStart = 0;
        }// bloc de START
        else if (este_selectat_bloculINPUT1(xMouse, yMouse) && ok == 1)
        {
            char arr[40] = "";
            Spot point;
            Spot interogation;
            point.xPos = 1350;
            point.yPos = 720;
            interogation.xPos = 1360;
            interogation.yPos = 760;
            vecNoduri[index].culoarecerc = 15;
            vecNoduri[index].culoarelegaturi = 15;
            scan_window_text1(arr, point, 1, interogation);
            vecNoduri[index].lungtext = 0;
            int lung = vecNoduri[index].lungtext;
            inittrapez(vecNoduri[index], arr, 14, x1_coord_INPUT + 250 - lung, y1_coord_INPUT, x2_coord_INPUT + 250 + lung, y2_coord_INPUT, vecNoduri[index].lungtext);
            deseneazatrapez(vecNoduri[index]);
            vecNoduri[index].sters = 0;
            vecNoduri[index].ok1 = 0;
            vecNoduri[index].ok2 = 0;
            index++;
            k++;
        }

        else if (este_selectat_bloculDECIZIE1(xMouse, yMouse) && ok == 1)
        {
            char arr[100] = "";
            Spot point;
            Spot interogation;
            point.xPos = 1360;
            point.yPos = 720;
            interogation.xPos = 1360;
            interogation.yPos = 760;
            scan_window_decizie(arr, point, 30, interogation);
            if (strlen(arr) >= 9)
                vecNoduri[index].lungtext = 5 * strlen(arr);
            else
                vecNoduri[index].lungtext = 1;
            int lung = vecNoduri[index].lungtext;
            vecNoduri[index].culoarecerc = 15;
            vecNoduri[index].culoarelegaturi = 15;
            vecNoduri[index].culoarelegaturi2 = 15;
            inittriunghi(vecNoduri[index], arr, 3, x1_coord_DECIZIE + 550, y1_coord_DECIZIE - (lung / 6), x2_coord_DECIZIE + 550 + lung, y2_coord_DECIZIE, vecNoduri[index].lungtext);
            deseneazatriunghi(vecNoduri[index]);
            vecNoduri[index].sters = 0;
            vecNoduri[index].ok1 = 0;
            vecNoduri[index].ok2 = 0;
            vecNoduri[index].cnt = 0;
            vecNoduri[index].loop = 0;
            index++;
        }
        else if (este_selectat_bloculCALCUL1(xMouse, yMouse) && ok == 1)
        {
            char arr[100] = "";
            Spot point;
            Spot interogation;
            point.xPos = 1360;
            point.yPos = 720;
            interogation.xPos = 1360;
            interogation.yPos = 760;
            scan_window_calcul(arr, point, 25, interogation);
            vecNoduri[index].culoarecerc = 15;
            vecNoduri[index].culoarelegaturi = 15;
            if (strlen(arr) >= 9)
                vecNoduri[index].lungtext = 5 * strlen(arr);
            else
                vecNoduri[index].lungtext = 1;
            int lung = vecNoduri[index].lungtext;
            initdreptunghiC(vecNoduri[index], arr, 14, x1_coord_CALCUL + 450 - lung, y1_coord_CALCUL, x2_coord_CALCUL + 450 + lung, y2_coord_CALCUL);
            deseneazadreptunghiC(vecNoduri[index]);
            vecNoduri[index].sters = 0;
            vecNoduri[index].ok1 = 0;
            vecNoduri[index].ok2 = 0;
            index++;
        }
        else if (este_selectat_bloculOUTPUT1(xMouse, yMouse) && ok == 1)
        {
            char arr[100] = "";
            Spot point;
            Spot interogation;
            point.xPos = 1350;
            point.yPos = 720;
            interogation.xPos = 1360;
            interogation.yPos = 760;
            scan_window_output(arr, point, 25, interogation);
            vecNoduri[index].culoarecerc = 15;
            vecNoduri[index].culoarelegaturi = 15;
            if (strlen(arr) >= 9)
                vecNoduri[index].lungtext = 5 * strlen(arr);
            else
                vecNoduri[index].lungtext = 1;
            int lung = vecNoduri[index].lungtext;
            inittrapezO(vecNoduri[index], arr, 14, x1_coord_OUTPUT + 450 - lung, y1_coord_OUTPUT, x2_coord_OUTPUT + 450 + lung, y2_coord_OUTPUT);
            deseneazatrapezO(vecNoduri[index]);
            vecNoduri[index].sters = 0;
            vecNoduri[index].ok1 = 0;
            vecNoduri[index].ok2 = 0;
            index++;
        }
        else if (este_selectat_bloculSTOP1(xMouse, yMouse) && ok == 1 && ok_Stop == 1)
        {
            vecNoduri[index].culoarecerc = 15;
            vecNoduri[index].culoarelegaturi = 15;
            initstop(vecNoduri[index], "STOP", 14, x1_coord_STOP + 250, y1_coord_STOP, x2_coord_STOP + 250, y2_coord_STOP);

            deseneazastop(vecNoduri[index]);
            vecNoduri[index].sters = 0;
            vecNoduri[index].ok1 = 0;
            vecNoduri[index].ok2 = 0;
            index++;
            desenare1_dreptunghi(x1_coord_STOP, y1_coord_STOP, x2_coord_STOP, y2_coord_STOP, 8);
            myOuttextXY(89, 575, 7, "STOP");
            okstop = 1;
            ok_Stop = 0;
        }
        else if (este_selectat_bloculSTERGERE(xMouse, yMouse))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            while (!ismouseclick(WM_LBUTTONDOWN));
            getmouseclick(WM_LBUTTONDOWN, xMouse, yMouse);

            nr_bloc = este_selectata_mutarea_unui_bloc1(xMouse, yMouse, vecNoduri, index);
            if (nr_bloc != -1 && vecNoduri[nr_bloc].tip != 'S' && vecNoduri[nr_bloc].tip != 'T')
            {
                stergere_bloc(xMouse, yMouse, nr_bloc);
                vecNoduri[nr_bloc].sters = 1;
                int k = 0;
                for (int i = 1; i <= nrLegaturi; i++)
                {
                    if (vecNoduri[vecLegaturi[i].nod1].tip == 'D')
                    {
                        if (vecLegaturi[i].nod2 == nr_bloc && vecLegaturi[i].punct1 == 0)
                        {
                            vecNoduri[vecLegaturi[i].nod1].ok1 = 0;
                            stergereleg(i);
                        }
                        if (vecLegaturi[i].nod2 == nr_bloc && vecLegaturi[i].punct1 == 2)
                        {
                            vecNoduri[vecLegaturi[i].nod1].ok1 = 1;
                            stergereleg(i);
                        }
                    }
                    else if (vecLegaturi[i].nod2 == nr_bloc)
                    {
                        vecNoduri[vecLegaturi[i].nod1].ok1 = 0;
                        stergereleg(i);
                    }

                }
                for (int i = 1; i <= nrLegaturi; i++)
                {

                    if (vecLegaturi[i].nod1 == nr_bloc)
                    {
                        if (vecNoduri[vecLegaturi[i].nod2].tip == 'D' && vecNoduri[vecLegaturi[i].nod2].cnt >= 2)
                            vecNoduri[vecLegaturi[i].nod2].ok2 = 1;
                        else
                            vecNoduri[vecLegaturi[i].nod2].ok2 = 0;
                        stergereleg(i);
                        k++;
                    }
                    if (vecLegaturi[i].nod1 == nr_bloc && k == 1)
                    {
                        vecNoduri[vecLegaturi[i].nod2].ok2 = 0;
                        stergereleg(i);
                    }

                }

                vecNoduri[nr_bloc].x1 = vecNoduri[nr_bloc].y1 = vecNoduri[nr_bloc].y2 = vecNoduri[nr_bloc].x2 = 0;
                desenare_schema_incarcata(vecNoduri, vecLegaturi, index, nrLegaturi);

            }
            else if (vecNoduri[nr_bloc].tip == 'S')
            {
                myOuttextXY(1360, 700, 4, "Blocul de START");
                myOuttextXY(1360, 720, 4, "nu poate fi sters");


            }
            else if (vecNoduri[nr_bloc].tip == 'T')

            {
                myOuttextXY(1360, 700, 4, "Blocul de STOP");
                myOuttextXY(1360, 720, 4, "nu poate fi sters");

            }


        }
        else if ((este_selectat_bloculSTART1(xMouse, yMouse) || este_selectat_bloculINPUT1(xMouse, yMouse) || este_selectat_bloculDECIZIE1(xMouse, yMouse) || este_selectat_bloculOUTPUT1(xMouse, yMouse) || este_selectat_bloculCALCUL1(xMouse, yMouse) || este_selectat_bloculSTOP1(xMouse, yMouse)) && okStart)
        {
            myOuttextXY(1360, 720, 4, "blocul de START");
            myOuttextXY(1360, 700, 4, "mai intai trebuie introdus");
        }
        else if (este_selectat_bloculRUN(xMouse, yMouse))
        {
            if (okstop == 1)
                executa(vecNoduri, vecLegaturi, index, nrLegaturi);
            else
            {
                myOuttextXY(1360, 700, 4, "Introduceti blocul");
                myOuttextXY(1360, 720, 4, "STOP!");
            }

        }
        else if (este_selectat_cerculet(xMouse, yMouse))
        {
            int absc, ord, absc1, ord1, iesire;

            deseneazaLegatura(idNod1, p1, idNod2, p2, absc, ord, absc1, ord1, iesire);

            if (iesire == 0)
            {
                nrLegaturi++;
                if (vecNoduri[idNod1].tip == 'S')
                {
                    vecLegaturi[nrLegaturi].nod1 = idNod1;
                    vecLegaturi[nrLegaturi].nod2 = idNod2;
                    vecLegaturi[nrLegaturi].punct1 = p1;
                    vecLegaturi[nrLegaturi].punct2 = p2;
                    vecNoduri[vecLegaturi[nrLegaturi].nod1].tiplegat = 'T';
                    vecLegaturi[nrLegaturi].x = absc;
                    vecLegaturi[nrLegaturi].y = ord;
                    vecLegaturi[nrLegaturi].x1 = absc1;
                    vecLegaturi[nrLegaturi].y1 = ord1;
                }
                if (vecNoduri[idNod1].tip == 'D')
                {
                    char true_false = true_sau_false(xMouse, yMouse, idNod1);
                    vecLegaturi[nrLegaturi].tipleg = true_false;
                    vecLegaturi[nrLegaturi].nod1 = idNod1;
                    vecLegaturi[nrLegaturi].nod2 = idNod2;
                    vecLegaturi[nrLegaturi].punct1 = p1;
                    vecLegaturi[nrLegaturi].punct2 = p2;
                    vecNoduri[vecLegaturi[nrLegaturi].nod2].tiplegat = vecLegaturi[nrLegaturi].tipleg;
                    vecLegaturi[nrLegaturi].x = absc;
                    vecLegaturi[nrLegaturi].y = ord;
                    vecLegaturi[nrLegaturi].x1 = absc1;
                    vecLegaturi[nrLegaturi].y1 = ord1;
                    if (vecLegaturi[nrLegaturi].punct1 == 0)
                        for (int i = 1; i < nrLegaturi; i++)
                            if (vecLegaturi[i].nod1 == vecLegaturi[nrLegaturi].nod1 && vecLegaturi[i].punct1 == 2)
                                swap(vecLegaturi[i], vecLegaturi[nrLegaturi]);
                }
                else
                {
                    vecLegaturi[nrLegaturi].nod1 = idNod1;
                    vecLegaturi[nrLegaturi].nod2 = idNod2;
                    vecLegaturi[nrLegaturi].punct1 = p1;
                    vecLegaturi[nrLegaturi].punct2 = p2;
                    vecNoduri[vecLegaturi[nrLegaturi].nod2].tiplegat = vecNoduri[vecLegaturi[nrLegaturi].nod1].tiplegat;
                    vecLegaturi[nrLegaturi].x = absc;
                    vecLegaturi[nrLegaturi].y = ord;
                    vecLegaturi[nrLegaturi].x1 = absc1;
                    vecLegaturi[nrLegaturi].y1 = ord1;
                }
            }
            for (j = 0; j < index; j++)
                if (vecNoduri[j].sters == 0)
                {
                    if (vecNoduri[j].tip == 'S')
                        deseneazadreptunghi(vecNoduri[j]);
                    else if (vecNoduri[j].tip == 'I')
                        deseneazatrapez(vecNoduri[j]);
                    else if (vecNoduri[j].tip == 'O')
                        deseneazatrapezO(vecNoduri[j]);
                    else if (vecNoduri[j].tip == 'C')
                        deseneazadreptunghiC(vecNoduri[j]);
                    else if (vecNoduri[j].tip == 'D')
                        deseneazatriunghi(vecNoduri[j]);
                    else if (vecNoduri[j].tip == 'T')
                        deseneazastop(vecNoduri[j]);
                }
        }
        else if (este_selectat_creare_schema(xMouse, yMouse) || este_selectat_incarcare_schema(xMouse, yMouse) || este_selectat_salvare_schema(xMouse, yMouse) || este_selectat_Exit(xMouse, yMouse))
        {
            myOuttextXY(1360, 700, 4, "Apasati butonul");
            myOuttextXY(1360, 720, 4, "OPRIRE DESENARE!");
        }
        else
        {
            {
                nr_bloc = este_selectata_mutarea_unui_bloc1(xMouse, yMouse, vecNoduri, index);

                if (nr_bloc != -1)
                {
                    sterge_legaturi1(vecNoduri, vecLegaturi, nrLegaturi, index);

                    muta_bloc1(xMouse, yMouse, nr_bloc, vecNoduri, vecLegaturi, index, nrLegaturi);
                    redeseneaza_blocuri(vecNoduri, index);
                }
            }

        }

        clearmouseclick(WM_LBUTTONDOWN);
        mouse_hover(xMouse, yMouse);

    }
    myOuttextXY(1360, 720, culbk, rez);
    myOuttextXY(1360, 700, culbk, "Rezultatul este:");
    myOuttextXY(1360, 700, culbk, "Blocul trebuie sa fie");
    myOuttextXY(1360, 720, culbk, "legat!");
    myOuttextXY(1360, 700, culbk, "Trebuie legata");
    myOuttextXY(1360, 720, culbk, "ramura true(stanga)!");
    myOuttextXY(1360, 700, culbk, "Apasati butonul");
    myOuttextXY(1360, 720, culbk, "OPRIRE DESENARE!");
    myOuttextXY(1360, 700, culbk, "Introduceti blocul");
    myOuttextXY(1360, 720, culbk, "STOP!");
}


void citirea_fisierului(char output[MAX], Spot point, int char_lim, Spot interogation)//Cosmin
{
    settextjustify(LEFT_TEXT, TOP_TEXT);
    strcpy(output, "");
    char tmp[MAX];
    char pressed_key;
    place_text(1250, 680, "Introduceti numele", 0);
    place_text(1300, 700, "fisierului:", 0);
    int wait = 1;
    int x1, y1;
    char message[10];
    do
    {

        if (!kbhit())
        {
            wait = 1;
            continue;
        }
        pressed_key = getch();
        if (pressed_key == 13)//enter
            break;

        if (pressed_key == 8)
        {
            if (strlen(output) > 0)
            {
                mem_text(tmp, output);
                place_text(point.xPos, point.yPos, tmp, culbk);

                output[strlen(output) - 1] = '\0';

                mem_text(tmp, output);

                place_text(point.xPos, point.yPos, tmp, culbk);

                place_text(point.xPos, point.yPos, tmp, 7);
            }
            else
                Beep(1000, 100);
        }
        else
        {
            if (char_lim > strlen(tmp))
                add_key(pressed_key, output, char_lim);
            else
            {

                if (interogation.xPos > 0)
                {
                    strcpy(message, "(max. 30)");
                }

                place_text(interogation.xPos, interogation.yPos, message, 15);
                delay(10);


            }

            mem_text(tmp, output);

            place_text(point.xPos, point.yPos, tmp, 15);
        }
    }
    while (true);
    place_text(interogation.xPos, interogation.yPos, message, culbk);
    place_text(1250, 680, "Introduceti numele", culbk);
    place_text(1300, 700, "fisierului:", culbk);
    place_text(point.xPos, point.yPos, tmp, culbk);
}

void blocul_de_care_este_legat(int b, int& x, int& j, char& c) //Cosmin
{
    for (int i = j; i <= nrLegaturi; i++)

    {
        j++;
        if (vecLegaturi[i].nod1 == b)
        {
            x = vecLegaturi[i].nod2;
            c = vecLegaturi[i].tipleg;
            return;
        }
    }
}
void viziteaza_vec(int a[], int blocc)//Cosmin
{
    for (int i = 1; i <= nrLegaturi; i++)
        if (vecLegaturi[i].nod1 == blocc)
        {
            a[blocc]++;
            if (a[vecLegaturi[i].nod2] == 1)
                a[vecLegaturi[i].nod2]++;
            else
            {
                if (vecLegaturi[i].nod2 != -1)
                    viziteaza_vec(a, vecLegaturi[i].nod2);
            }
        }
}

void transf_in_cod_cpp(char a[])//Cosmin
{
    for (int i = 0; i < strlen(a); i++)
        if (a[i] == '~')
        {
            a[i] = '!';
        }
        else if (a[i] == 'R')
        {
            a[i] = 's';
            char auxt[250];
            strcpy(auxt, a + i + 1);
            a[i + 1] = 0;
            strcat(a, "qrt");
            strcat(a, auxt);
            ok_cmath = 1;
        }
}
void viziteaza_cod(int a[], int blocc, FILE* fisier3)//Cosmin
{
    int nr = 0;
    for (int i = 1; i <= nrLegaturi; i++)
    {
        int nod1 = vecLegaturi[i].nod1, ok_p = 0;
        if (vecLegaturi[i].nod1 == blocc)
        {
            char information[250];
            strcpy(information, vecNoduri[nod1].info);
            if (vecNoduri[nod1].tip != 'S' && vecNoduri[nod1].tip != 'O' && vecNoduri[nod1].tip != 'T')
                transf_in_cod_cpp(information);
            if (vecNoduri[nod1].tip == 'S')
            {
                if (!ok_cmath)
                    fprintf(fisier3, "#include<iostream>\n\nint main()\n{\n");
                else
                {
                    fprintf(fisier3, "#include<iostream>\n#include<cmath>\n\nint main()\n\n{\n");
                    ok_cmath = 0;
                }

            }
            else if (vecNoduri[nod1].tip == 'I')
            {
                fprintf(fisier3, "int %s;\n", information);
                fprintf(fisier3, "cin>>%s;\n", information);
            }
            else if (vecNoduri[nod1].tip == 'C')
            {
                if (information[strlen(information) - 1] == ';')
                    fprintf(fisier3, "%s\n", information);
                else
                    fprintf(fisier3, "%s;\n", information);
            }
            else if (vecNoduri[nod1].tip == 'O')
            {
                fprintf(fisier3, "cout<<%s<<\" \"; \n", information);
            }
            else if (vecNoduri[nod1].tip == 'D')
            {
                if (a[nod1] == 3 && !nr)
                {
                    fprintf(fisier3, "while%s {\n", information + 2);
                    nr++;
                    a[nod1] = 4;
                    viziteaza_cod(a, vecLegaturi[i].nod2, fisier3);
                    fprintf(fisier3, "\n}\n");


                }
                else if (a[nod1] == 4 && nr != 0)
                {
                    fprintf(fisier3, "\n");
                    viziteaza_cod(a, vecLegaturi[i].nod2, fisier3);
                }
                else if (a[nod1] == 2 && !nr)
                {
                    fprintf(fisier3, "%s {\n", information);
                    nr++;
                    viziteaza_cod(a, vecLegaturi[i].nod2, fisier3);
                    fprintf(fisier3, "\n}\n");

                }
                else if (a[nod1] == 2 && nr != 0)
                {
                    fprintf(fisier3, "\t else {\n", information);
                    viziteaza_cod(a, vecLegaturi[i].nod2, fisier3);
                    fprintf(fisier3, "\n}\n");
                }



            }
            if (vecNoduri[vecLegaturi[i].nod2].tip != 'T' && a[vecLegaturi[i].nod2] != 4 && vecNoduri[nod1].tip != 'D')
                viziteaza_cod(a, vecLegaturi[i].nod2, fisier3);
        }

    }

}
void salvare_cod_CPP(char nume_fisier[])//Cosmin
{
    FILE* fisier3;
    fisier3 = fopen(nume_fisier, "w+");
    if (fisier3 == NULL)
        perror("Eroare la deschidere");
    int vizitat[MAX_NR];
    for (int i = 0; i < index; i++)
        vizitat[i] = 0;
    int bloc_curent = vecLegaturi[1].nod1;
    viziteaza_vec(vizitat, bloc_curent);
    bloc_curent = vecLegaturi[1].nod1;
    viziteaza_cod(vizitat, bloc_curent, fisier3);


    fprintf(fisier3, " return 0;\n}");
    fclose(fisier3);

}
void afisare_cod_cpp(char nume_fisier[])//Cosmin
{
    settextstyle(10, 0, 1);
    settextjustify(BOTTOM_TEXT, BOTTOM_TEXT);
    FILE* fisier_cod;
    fisier_cod = fopen(nume_fisier, "r");
    if (!fisier_cod)
        perror("Eroare la deschiderea fisierului: ");

    char rand[256];
    fgets(rand, 256, fisier_cod);
    int x, y;
    x = 1205;
    y = 80;
    int ok_spatiu = 1;
    int ok_latime = 1;
    while (!feof(fisier_cod) && ok_spatiu)
    {
        //bar(1200,15,1515,630);//cod c++
        setcolor(0);
        if (textwidth(rand) < 250)
            outtextxy(x, y, rand);
        else
        {
            while (textwidth(rand) > 250)
                rand[strlen(rand) - 1] = 0;
            outtextxy(x, y, rand);
            outtextxy(x + textwidth(rand), y, " . . .");
            ok_latime = 0;
        }
        y = y + textheight(rand);
        if (y + 3 * textheight(rand) > 630)
        {
            outtextxy(x, y, " . . . . . . .");
            y = y + textheight(rand);
            settextstyle(3, 0, 1);
            outtextxy(x, y, "//Codul complet se poate gasi in fisierul: ");
            y = y + textheight(rand);
            settextstyle(10, 0, 1);

            outtextxy(x, y, nume_fisier);
            ok_spatiu = 0;
        }

        fgets(rand, 256, fisier_cod);
    }
    if (ok_spatiu)
        outtextxy(x, y, rand);
    if (!ok_latime && ok_spatiu)
    {
        settextstyle(3, 0, 1);
        y = y + textheight(rand);
        outtextxy(x, y, "//Codul complet se poate gasi in fisierul: ");
        y = y + textheight(rand);
        settextstyle(10, 0, 1);
        outtextxy(x, y, nume_fisier);
    }
    settextstyle(10, 0, 1);
}
void sterge_caseta_cod()//Cosmin
{
    setfillstyle(0, culbk);
    bar(1205, 60, 1515, 630);
}
void salvare_schema_in_fisier()//Cosmin
{
    char nume_fisier[100] = "";
    Spot point;
    Spot interogation;
    point.xPos = 1325;
    point.yPos = 720;
    interogation.xPos = 1360;
    interogation.yPos = 740;
    citirea_fisierului(nume_fisier, point, 25, interogation);
    FILE* fisier;
    fisier = fopen(nume_fisier, "w+");
    fprintf(fisier, "%d\n", index);

    for (int i = 0; i < index; i++)
    {
        int bloc_legatura = -1, nrr = 1;
        char tiplegD;
        blocul_de_care_este_legat(i, bloc_legatura, nrr, tiplegD);
        if (vecNoduri[i].tip != 'D')
        {
            fprintf(fisier, "%c %d %d %d %d $%s$ %d %d ", vecNoduri[i].tip, vecNoduri[i].x1, vecNoduri[i].y1, vecNoduri[i].x2, vecNoduri[i].y2, vecNoduri[i].info, vecNoduri[i].sters, vecNoduri[i].culoarelegaturi);
            fprintf(fisier, "%d %d\n", i, bloc_legatura);
        }
        else
        {
            fprintf(fisier, "%c %d %d %d %d $%s$ %d %d %d ", vecNoduri[i].tip, vecNoduri[i].x1, vecNoduri[i].y1, vecNoduri[i].x2, vecNoduri[i].y2, vecNoduri[i].info, vecNoduri[i].sters, vecNoduri[i].culoarelegaturi, vecNoduri[i].culoarelegaturi2);
            fprintf(fisier, "%d %d %c ", i, bloc_legatura, tiplegD);

            blocul_de_care_este_legat(i, bloc_legatura, nrr, tiplegD);
            fprintf(fisier, "%d %d %c\n", i, bloc_legatura, tiplegD);

        }
    }

    fclose(fisier);

    nume_fisier[strlen(nume_fisier) - 4] = 0;
    strcat(nume_fisier, "_cod_CPP.txt");
    if (vecLegaturi[1].nod1 != 0)
    {
        ///Obligatoriu pe prima pozitie trebuie sa fie nodul de start;
        ///cazul in care nodul de start nu se afla pe prima pozitie, este atunci cand s-a sters nodul de care era initial legat START_ul
        int _ok = 1;
        for (int i = 2; i <= nrLegaturi && _ok; i++)
            if (vecLegaturi[i].nod1 == 0)
            {
                legatura aux;
                aux = vecLegaturi[1];
                vecLegaturi[1] = vecLegaturi[i];
                vecLegaturi[i] = aux;
                _ok = 0;
            }

    }

    salvare_cod_CPP(nume_fisier);
    afisare_cod_cpp(nume_fisier);
    nume_fisier[strlen(nume_fisier) - 12] = 0;
    strcat(nume_fisier, ".jpg");
    salvare_imagine_schema(nume_fisier);

}
void initialize_vector_from_file_citit(nod& N1)//Cosmin
{
    if (N1.tip == 'S')//Start
    {
        N1.pLeg[0].x = N1.x1 + (N1.x2 - N1.x1) / 2;
        N1.pLeg[0].y = N1.y2;
    }
    else if (N1.tip == 'I')//Input
    {
        N1.pLeg[0].x = (N1.x1 + N1.x2) / 2 + 7;
        N1.pLeg[0].y = N1.y2;
        N1.pLeg[1].x = (N1.x1 + N1.x2) / 2 + 7;
        N1.pLeg[1].y = N1.y1;
    }
    else if (N1.tip == 'O')//Output
    {
        N1.pLeg[1].x = (N1.x1 + N1.x2 - 15) / 2;
        N1.pLeg[1].y = N1.y1;
        N1.pLeg[0].x = (N1.x1 + N1.x2 - 15) / 2;
        N1.pLeg[0].y = N1.y2;
    }
    else if (N1.tip == 'C')//Calcul
    {
        N1.pLeg[0].x = N1.x1 + (N1.x2 - N1.x1) / 2;
        N1.pLeg[0].y = N1.y2;
        N1.pLeg[1].x = N1.x1 + (N1.x2 - N1.x1) / 2;
        N1.pLeg[1].y = N1.y1;
    }
    else if (N1.tip == 'D')//Decizie
    {
        N1.pLeg[0].x = N1.x1 - (N1.x2 - N1.x1);
        N1.pLeg[0].y = N1.y2;
        N1.pLeg[2].x = N1.x2;
        N1.pLeg[2].y = N1.y2;
        N1.pLeg[1].x = N1.x1;
        N1.pLeg[1].y = N1.y1;
    }
    else if (N1.tip == 'T')//Stop
    {
        N1.pLeg[1].x = (N1.x1 + N1.x2) / 2;
        N1.pLeg[1].y = N1.y1;
    }

}

void sterge_date_incarcate(nod N1[MAX_NR], legatura L1[MAX_NR], int nrNoduri1, int nrLegaturi1)//Cosmin
{
    setfillstyle(0, 0);
    for (int i = 0; i < nrNoduri1; i++)
    {
        if (N1[i].sters == 0)
        {
            if (N1[i].tip != 'D')
                bar(N1[i].x1 - 15, N1[i].y1 - 6, N1[i].x2 + 17, N1[i].y2 + 6);
            else
                bar(N1[i].x1 - 190, N1[i].y1 - 6, N1[i].x2 + 17, N1[i].y2 + 6);
        }
        N1[i].ok1 = 0;
        N1[i].ok2 = 0;
        N1[i].tiplegatJ1 = 0;
        N1[i].tiplegatJ2 = 0;
        N1[i].tiplegatS1 = 0;
        N1[i].tiplegatS2 = 0;

    }

    bar(180, 90, 1185, 775);//cadru blocuri
    //stergere legaturi
    for (int i = 1; i < nrLegaturi1; i++)
    {
        if (L1[i].nod2 != -1)
        {
            int x1, y1, x2, y2;
            x2 = N1[L1[i].nod2].pLeg[1].x;
            y2 = N1[L1[i].nod2].pLeg[1].y;

            if (N1[L1[i].nod1].tip != 'D')
            {
                x1 = N1[L1[i].nod1].pLeg[0].x;
                y1 = N1[L1[i].nod1].pLeg[0].y;
            }
            else
            {
                if (L1[i].tipleg == 'F')//a 2-a legatura (ramura Fals)
                {
                    x1 = N1[L1[i].nod1].pLeg[2].x;
                    y1 = N1[L1[i].nod1].pLeg[2].y;
                }
                else
                {
                    x1 = N1[L1[i].nod1].pLeg[0].x;
                    y1 = N1[L1[i].nod1].pLeg[0].y;
                }
            }
            drawLine(x1, y1, x2, y2, culbk, N1, nrNoduri1);
        }
    }


    myOuttextXY(1350, 700, culbk, "Rezultatul este:  ");
    myOuttextXY(1350, 720, culbk, rez);

}
void mouse_hover_button_sterge_schema(int& xMouse, int& yMouse)//Cosmin
{
    bool ok_click = 1;
    while (ok_click)
    {
        xMouse = mousex();
        yMouse = mousey();
        if (este_selectat_buton_stergere(xMouse, yMouse))
        {
            while (este_selectat_buton_stergere(xMouse, yMouse) && ok_click)
            {
                xMouse = mousex();
                yMouse = mousey();
                settextjustify(LEFT_TEXT, TOP_TEXT);
                desenare1_dreptunghi(990, 92, 1182, 130, 15);
                if (culbk == 12)
                    setcolor(4);
                else
                    setcolor(0);
                outtextxy(1000, 95, "Stergere Schema");
                if (ismouseclick(WM_LBUTTONDOWN))
                    ok_click = false;
            }
            settextjustify(LEFT_TEXT, TOP_TEXT);
            if (culbk == 12)
                desenare1_dreptunghi(990, 92, 1182, 130, 4);
            else
                desenare1_dreptunghi(990, 92, 1182, 130, 0);
            setcolor(15);
            outtextxy(1000, 95, "Stergere Schema");
        }
        if (ok_schema_incarcata)
        {
            if (este_selectat_bloculRUN(xMouse, yMouse))
            {
                if (culbk == 4)
                    myOuttextXY(85, 45, 4, "RUN");
                else
                    myOuttextXY(85, 45, 0, "RUN");
                while (este_selectat_bloculRUN(xMouse, yMouse) && ok_click)
                {
                    xMouse = mousex();
                    yMouse = mousey();
                    setcolor(15);
                    rectangle(15, 15, 165, 75);
                    rectangle(15, 14, 165, 74);
                    rectangle(15, 13, 165, 73);
                    if (ismouseclick(WM_LBUTTONDOWN))
                        ok_click = 0;
                }
                setcolor(culbk);
                rectangle(15, 15, 165, 75);
                rectangle(15, 14, 165, 74);
                rectangle(15, 13, 165, 73);
                myOuttextXY(85, 45, 15, "RUN");
            }
        }
        if (ismouseclick(WM_LBUTTONDOWN))
            ok_click = 0;

    }


}

void desenare_buton_stergere()//Cosmin
{
    settextjustify(LEFT_TEXT, TOP_TEXT);
    if (culbk == 12)
        desenare1_dreptunghi(990, 92, 1182, 130, 4);
    else
        desenare1_dreptunghi(990, 92, 1182, 130, 0);

    setcolor(15);
    outtextxy(1000, 95, "Stergere Schema");
}

void stergere_buton_stergere()//Cosmin
{
    setfillstyle(0, 0);
    myOuttextXY(85, 45, culbk, "RUN");
    myOuttextXY(990, 45, culbk, "STERGERE");
    bar(989, 90, 1185, 132);
    ok_schema_incarcata = 0;
}

void sterge_date()//Cosmin
{
    if (ok_schema_creata == 1 || ok_schema_incarcata == 1)
    {
        desenare_buton_stergere();
        clearmouseclick(WM_LBUTTONDOWN);
        int mouse_x = 0, mouse_y = 0;
        while (!este_selectat_buton_stergere(mouse_x, mouse_y))
        {
            mouse_hover_button_sterge_schema(mouse_x, mouse_y);
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }

    setfillstyle(0, 0);
    bar(15, 90, 165, 655);//butoanele din stanga start,input ,,, etc
    for (int i = 0; i < index; i++)
    {
        if (vecNoduri[i].sters == 0)
        {
            if (vecNoduri[i].tip != 'D')
                bar(vecNoduri[i].x1 - 15, vecNoduri[i].y1 - 6, vecNoduri[i].x2 + 17, vecNoduri[i].y2 + 6);
            else
                bar(vecNoduri[i].x1 - 190, vecNoduri[i].y1 - 6, vecNoduri[i].x2 + 17, vecNoduri[i].y2 + 6);
        }
        vecNoduri[i].ok1 = 0;
        vecNoduri[i].ok2 = 0;
        vecNoduri[i].tiplegatJ1 = 0;
        vecNoduri[i].tiplegatJ2 = 0;
        vecNoduri[i].tiplegatS1 = 0;
        vecNoduri[i].tiplegatS2 = 0;
        vecNoduri[i].x1 = vecNoduri[i].y1 = vecNoduri[i].x2 = vecNoduri[i].y2 = 0;


    }
    bar(180, 90, 1185, 775);//cadru blocuri
    //sterge legaturi
    for (int i = 1; i <= nrLegaturi; i++)
    {
        if (vecLegaturi[i].nod2 != -1)
        {
            int x1, y1, x2, y2;
            x2 = vecNoduri[vecLegaturi[i].nod2].pLeg[1].x;
            y2 = vecNoduri[vecLegaturi[i].nod2].pLeg[1].y;

            if (vecNoduri[vecLegaturi[i].nod1].tip != 'D')
            {
                x1 = vecNoduri[vecLegaturi[i].nod1].pLeg[0].x;
                y1 = vecNoduri[vecLegaturi[i].nod1].pLeg[0].y;
            }
            else
            {
                if (vecLegaturi[i].tipleg == 'F')//a 2-a legatura (ramura Fals)
                {
                    x1 = vecNoduri[vecLegaturi[i].nod1].pLeg[2].x;
                    y1 = vecNoduri[vecLegaturi[i].nod1].pLeg[2].y;
                }
                else
                {
                    x1 = vecNoduri[vecLegaturi[i].nod1].pLeg[0].x;
                    y1 = vecNoduri[vecLegaturi[i].nod1].pLeg[0].y;
                }
            }

            drawLine(x1, y1, x2, y2, culbk, vecNoduri, index);
        }
    }


    myOuttextXY(1350, 700, culbk, "Rezultatul este:");
    myOuttextXY(1350, 720, culbk, rez);
    ok_schema_creata = 0;
    index = 0;
    nrLegaturi = 1;
    k = 0;
    okStart = 1;
    ok_Stop = 1;
    sterge_caseta_cod();
    stergere_buton_stergere();
}
void muta_blocuri_incarcate(nod N1[], legatura L1[], int nrr_noduri, int nrr_legaturi)//Cosmin
{
    clearmouseclick(WM_LBUTTONDOWN);
    int mouse_x, mouse_y;
    getmouseclick(WM_LBUTTONDOWN, mouse_x, mouse_y);

    while (!este_selectat_buton_stergere(mouse_x, mouse_y))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        mouse_hover_button_sterge_schema(mouse_x, mouse_y);
        if (este_selectat_bloculRUN(mouse_x, mouse_y))
            executa(N1, L1, nrr_noduri, nrr_legaturi);
        else
        {
            int nr_bloc = este_selectata_mutarea_unui_bloc1(mouse_x, mouse_y, N1, nrr_noduri);
            if (nr_bloc != -1)
            {
                sterge_legaturi1(N1, L1, nrr_legaturi, nrr_noduri);
                muta_bloc1(mouse_x, mouse_y, nr_bloc, N1, L1, nrr_noduri, nrr_legaturi);
                desenare_schema_incarcata(N1, L1, nrr_noduri, nrr_legaturi);

            }
        }

    }

}

void citire_schema_din_fisier()//Cosmin
{
    char nume_file[100] = "";
    Spot point;
    Spot interogation;
    point.xPos = 1325;
    point.yPos = 720;
    interogation.xPos = 1360;
    interogation.yPos = 740;

    FILE* fisier1;
    citirea_fisierului(nume_file, point, 25, interogation);
    fisier1 = fopen(nume_file, "r");
    myOuttextXY(85, 45, 15, "RUN");
    if (!fisier1)
        perror("Eroare la deschidere");
    nod vecNoduri1[MAX_NR];
    legatura vecLegaturi1[MAX_NR];
    int nrNoduri1 = 0, nrLegaturi1 = 1, nr, culoare, culoare2;
    fscanf(fisier1, "%d", &nr);
    nrNoduri1 = nr;
    for (int i = 0; i < nr; i++)
    {
        char tip, info[MAX];
        int sters, x1, x2, y1, y2;
        int nod1, nod2;//legaturile dintre cele 2 noduri
        fgetc(fisier1);

        fscanf(fisier1, "%c", &tip);
        if (tip != 'D')
        {
            fgetc(fisier1);
            fscanf(fisier1, "%d %d %d %d", &x1, &y1, &x2, &y2);
            char c;
            fgetc(fisier1);
            fgetc(fisier1);
            c = fgetc(fisier1);
            int nr_c = 0;
            while (c != '$')
            {
                info[nr_c++] = c;
                c = fgetc(fisier1);
            }
            info[nr_c] = 0;


            fscanf(fisier1, "%d", &sters);
            fscanf(fisier1, "%d", &culoare);
            fscanf(fisier1, "%d %d", &nod1, &nod2);
            if (sters != 1)
            {
                if (culbk != 12)
                    vecNoduri1[i].culoare = RGB(198, 83, 140);
                else
                    vecNoduri1[i].culoare = 5;
                vecNoduri1[i].culoarecerc = 15;
            }
            else
            {
                vecNoduri1[i].culoare = culbk;
                vecNoduri1[i].culoarecerc = culbk;
            }
            vecNoduri1[nod1].tip = tip;
            vecNoduri1[nod1].x1 = x1;
            vecNoduri1[nod1].y1 = y1;
            vecNoduri1[nod1].x2 = x2;
            vecNoduri1[nod1].y2 = y2;
            vecNoduri1[nod1].sters = sters;
            strcpy(vecNoduri1[nod1].info, info);
            if (strlen(info) >= 9)
                vecNoduri1[nod1].lungtext = 5 * strlen(info);
            else
                vecNoduri1[nod1].lungtext = 1;
            vecLegaturi1[nrLegaturi1].nod1 = nod1;
            vecLegaturi1[nrLegaturi1].nod2 = nod2;
            nrLegaturi1++;
        }
        else
        {
            int nod11, nod22;
            char c1, c2;
            fgetc(fisier1);
            fscanf(fisier1, "%d %d %d %d", &x1, &y1, &x2, &y2);
            char c;
            fgetc(fisier1);
            fgetc(fisier1);
            c = fgetc(fisier1);
            int nr_c = 0;
            while (c != '$')
            {
                info[nr_c++] = c;
                c = fgetc(fisier1);
            }
            info[nr_c] = 0;
            fscanf(fisier1, "%d", &sters);
            fscanf(fisier1, "%d", &culoare);
            fscanf(fisier1, "%d", &culoare2);
            fscanf(fisier1, "%d %d %c %d %d %c", &nod1, &nod2, &c1, &nod11, &nod22, &c2);

            if (sters != 1)
            {
                if (culbk != 12)
                    vecNoduri1[i].culoare = RGB(198, 83, 140);
                else
                    vecNoduri1[i].culoare = 5;
                vecNoduri1[i].culoarecerc = 15;
            }
            else
            {
                vecNoduri1[i].culoare = culbk;
                vecNoduri1[i].culoarecerc = culbk;
            }
            vecNoduri1[nod1].sters = sters;
            vecNoduri1[nod1].tip = tip;
            vecNoduri1[nod1].x1 = x1;
            vecNoduri1[nod1].y1 = y1;
            vecNoduri1[nod1].x2 = x2;
            vecNoduri1[nod1].y2 = y2;
            strcpy(vecNoduri1[nod1].info, info);
            if (strlen(info) >= 9)
                vecNoduri1[nod1].lungtext = 5 * strlen(info);
            else
                vecNoduri1[nod1].lungtext = 1;
            vecLegaturi1[nrLegaturi1].nod1 = nod1;
            vecLegaturi1[nrLegaturi1].nod2 = nod2;
            vecLegaturi1[nrLegaturi1].tipleg = c1;
            nrLegaturi1++;
            vecLegaturi1[nrLegaturi1].nod1 = nod11;
            vecLegaturi1[nrLegaturi1].nod2 = nod22;
            vecLegaturi1[nrLegaturi1].tipleg = c2;
            nrLegaturi1++;
        }
        initialize_vector_from_file_citit(vecNoduri1[nod1]);
    }


    desenare_schema_incarcata(vecNoduri1, vecLegaturi1, nrNoduri1, nrLegaturi1);
    for (int i = 0; i < nr; i++)
        printf("%c %d %d %d %d %d %s \n", vecNoduri1[i].tip, vecNoduri1[i].x1, vecNoduri1[i].y1, vecNoduri1[i].x2, vecNoduri1[i].y2, vecNoduri1[i].pLeg[1].x, vecNoduri1[i].info);
    nume_file[strlen(nume_file) - 4] = 0;
    strcat(nume_file, "_cod_CPP.txt");
    afisare_cod_cpp(nume_file);
    desenare_buton_stergere();
    muta_blocuri_incarcate(vecNoduri1, vecLegaturi1, nrNoduri1, nrLegaturi1);
    sterge_caseta_cod();
    sterge_date_incarcate(vecNoduri1, vecLegaturi1, nrNoduri1, nrLegaturi1);
    stergere_buton_stergere();

}



void menu()//Cosmin
{
    clearmouseclick(WM_LBUTTONDOWN);

    int mouse_x = mousex();
    int mouse_y = mousey();
    mouse_hover(mouse_x, mouse_y);
    while (!este_selectat_Exit(mouse_x, mouse_y))
    {

        if (este_selectat_creare_schema(mouse_x, mouse_y))
        {
            ok_schema_creata = 1;
            setfillstyle(1, culbk);
            bar(180, 90, 1185, 775);
            desenare1_butoane_blocuri();
            desenare1_blocuri();

        }
        else if (este_selectat_salvare_schema(mouse_x, mouse_y) && ok_schema_creata)
        {
            salvare_schema_in_fisier();

            sterge_date();

        }
        else if (este_selectat_incarcare_schema(mouse_x, mouse_y))
        {
            ok_schema_incarcata = 1;
            setfillstyle(1, culbk);
            bar(180, 90, 1185, 775);
            citire_schema_din_fisier();

        }
        clearmouseclick(WM_LBUTTONDOWN);
        mouse_hover(mouse_x, mouse_y);
    }
    ok_schema_incarcata = 0;
    ok_schema_creata = 0;
    okStart = 1;
    ok_Stop = 1;
    sterge_date();
}
void myOuttextXYmenu(int x, int y, int cerneala, char* text)//Andrei
{
    settextstyle(10, 0, 5);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(cerneala);
    setbkcolor(RGB(63, 72, 204));
    outtextxy(x, y + 3, text);
}
void myOuttextXYsetting1(int x, int y, int cerneala, char* text)//Andrei
{
    settextstyle(10, 0, 5);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(cerneala);
    setbkcolor(RGB(195, 195, 195));
    outtextxy(x, y + 3, text);
}
void myOuttextXYsetting2(int x, int y, int cerneala, char* text)//Andrei
{
    settextstyle(10, 0, 5);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(cerneala);
    setbkcolor(RGB(58, 58, 58));
    outtextxy(x, y + 3, text);
}
void myOuttextXYmenu2(int x, int y, int cerneala, char* text)//Andrei
{
    settextstyle(10, 0, 5);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(cerneala);
    setbkcolor(RGB(127, 127, 127));
    outtextxy(x, y + 3, text);
}
void myOuttextXYinfo(int x, int y, int cerneala, char* text)//Andrei
{
    settextstyle(10, 0, 5);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(cerneala);
    setbkcolor(RGB(237, 27, 36));
    outtextxy(x, y + 3, text);
}
void myOuttextXYinfo2(int x, int y, int cerneala, char* text)//Andrei
{
    settextstyle(10, 0, 1);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(cerneala);
    setbkcolor(RGB(82, 82, 82));
    outtextxy(x, y + 3, text);
}
void myOuttextXYinfo3(int x, int y, int cerneala, char* text)//Andrei
{
    settextstyle(10, 0, 3);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(cerneala);
    setbkcolor(RGB(82, 82, 82));
    outtextxy(x, y + 3, text);
    settextstyle(10, 0, 1);
}

int x_menu1 = 1270, x_menu2 = 1510, y_menu1 = 20, y_menu2 = 80;
int x_off1 = 50, x_off2 = 470, y_off1 = 380, y_off2 = 460;
int x_on1 = 50, x_on2 = 470, y_on1 = 520, y_on2 = 600;
int x_light1 = 1070, y_light1 = 390, x_light2 = 1480, y_light2 = 480;
int x_night1 = 1070, y_night1 = 520, x_night2 = 1480, y_night2 = 612;
int x_semnint1 = 1449, x_semnint2 = 1505, y_semnint1 = 20, y_semnint2 = 68;
int x_exitinfo1 = 1140, x_exitinfo2 = 1210, y_exitinfo1 = 180, y_exitinfo2 = 235;


bool backmenu(int x, int y)//Cosmin
{
    if (x >= x_menu1 && x <= x_menu2 && y >= y_menu1 && y <= y_menu2)
        return true;
    return false;
}
bool backmenu2(int x, int y)//Cosmin
{
    if (x >= x_exitinfo1 && x <= x_exitinfo2 && y >= y_exitinfo1 && y <= y_exitinfo2)
        return true;
    return false;
}
void mouse_hover_info(int& mouse_x, int& mouse_y)//Cosmin
{
    setfillstyle(0, culbk);
    bool nu_este_facut_click = 1;
    while (nu_este_facut_click)
    {
        mouse_x = mousex();
        mouse_y = mousey();


        if (ismouseclick(WM_LBUTTONDOWN))
            nu_este_facut_click = 0;
        if (backmenu2(mouse_x, mouse_y))
        {
            myOuttextXYinfo(1177, 218, 0, "X");
            while (backmenu2(mouse_x, mouse_y) && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYinfo(1177, 218, 15, "X");
        }
    }
}


void info()//Andrei
{
    readimagefile("info.jpg", 0, 0, 1530, 790);
    myOuttextXYinfo(1177, 218, 15, "X");
    myOuttextXYinfo2(800, 330, 15, "Proiect realizat de: Galan Andrei-Iulian si Sorodoc Tudor-Cosmin.");
    myOuttextXYinfo2(550, 360, 15, "Indicatii in formarea expresiilor:");
    myOuttextXYinfo2(440, 390, 15, "S(x)<=>sin(x)");
    myOuttextXYinfo2(775, 390, 15, "x++<=>x+1");
    myOuttextXYinfo2(440, 420, 15, "C(x)<=>cos(x)");
    myOuttextXYinfo2(775, 420, 15, "x--<=>x-1");
    myOuttextXYinfo2(440, 450, 15, "L(x)<=>log(x)");
    myOuttextXYinfo2(795, 450, 15, "(x+=y)<=>x=x+y");
    myOuttextXYinfo2(425, 480, 15, "E(x)<=>e^x");
    myOuttextXYinfo2(795, 480, 15, "(x-=y)<=>x=x-y");
    myOuttextXYinfo2(425, 510, 15, "M(x)<=>|x|");
    myOuttextXYinfo2(795, 510, 15, "(x*=y)<=>x=x*y");
    myOuttextXYinfo2(445, 540, 15, "R(x)<=>sqrt(x)");
    myOuttextXYinfo2(795, 540, 15, "(x/=y)<=>x=x/y");
    myOuttextXYinfo2(430, 570, 15, "~(x)<=>!(x)");
    myOuttextXYinfo2(480, 600, 15, "x^y<=>x la puterea y");
    myOuttextXYinfo3(800, 660, RGB(237, 27, 36), "Va recomandam sa folositi cat mai multe paranteze pentru");
    myOuttextXYinfo3(800, 690, RGB(237, 27, 36), "a evita eventualele erori!!");
    clearmouseclick(WM_LBUTTONDOWN);

    int mouse_x = mousex();
    int mouse_y = mousey();
    mouse_hover_info(mouse_x, mouse_y);
    int ok = 1;
    while (!backmenu2(mouse_x, mouse_y) && ok == 1)
    {
        info();
        ok = 0;
        clearmouseclick(WM_LBUTTONDOWN);
        //mouse_hover(mouse_x,mouse_y);
    }
}


void mouse_hover_settings(int& mouse_x, int& mouse_y)//Cosmin
{
    setfillstyle(0, culbk);
    bool nu_este_facut_click = 1;
    while (nu_este_facut_click)
    {
        mouse_x = mousex();
        mouse_y = mousey();


        if (ismouseclick(WM_LBUTTONDOWN))
            nu_este_facut_click = 0;
        if (mouse_x >= x_off1 && mouse_x <= x_off2 && mouse_y >= y_off1 && mouse_y <= y_off2)
        {
            myOuttextXYsetting2(300, 435, 0, "MUSIC OFF");
            while (mouse_x >= x_off1 && mouse_x <= x_off2 && mouse_y >= y_off1 && mouse_y <= y_off2 && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYsetting2(300, 435, 15, "MUSIC OFF");
        }
        else   if (mouse_x >= x_on1 && mouse_x <= x_on2 && mouse_y >= y_on1 && mouse_y <= y_on2)
        {
            myOuttextXYsetting2(300, 570, 7, "MUSIC ON");
            while (mouse_x >= x_on1 && mouse_x <= x_on2 && mouse_y >= y_on1 && mouse_y <= y_on2 && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYsetting2(300, 570, 15, "MUSIC ON");
        }
        else if (mouse_x >= x_light1 && mouse_x <= x_light2 && mouse_y >= y_light1 && mouse_y <= y_light2)
        {
            myOuttextXYsetting2(1230, 445, 7, "LIGHT MODE");
            while (mouse_x >= x_light1 && mouse_x <= x_light2 && mouse_y >= y_light1 && mouse_y <= y_light2 && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYsetting2(1230, 445, 15, "LIGHT MODE");
        }
        else if (mouse_x >= x_night1 && mouse_x <= x_night2 && mouse_y >= y_night1 && mouse_y <= y_night2)
        {
            myOuttextXYsetting2(1230, 570, 0, "NIGHT MODE");
            while (mouse_x >= x_night1 && mouse_x <= x_night2 && mouse_y >= y_night1 && mouse_y <= y_night2 && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYsetting2(1230, 570, 15, "NIGHT MODE");
        }
        else if (backmenu(mouse_x, mouse_y))
        {
            myOuttextXYsetting1(1420, 53, 15, "MENIU");
            while (backmenu(mouse_x, mouse_y) && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYsetting1(1420, 53, 0, "MENIU");
        }
    }

}
void setting()//Andrei
{
    readimagefile("settings.jpg", 0, 0, 1530, 790);
    clearmouseclick(WM_LBUTTONDOWN);
    myOuttextXYsetting1(1420, 53, 0, "MENIU");
    myOuttextXYsetting2(300, 435, 15, "MUSIC OFF");
    myOuttextXYsetting2(300, 570, 15, "MUSIC ON");
    myOuttextXYsetting2(1230, 445, 15, "LIGHT MODE");
    myOuttextXYsetting2(1230, 570, 15, "NIGHT MODE");

    int mouse_x = mousex();
    int mouse_y = mousey();
    mouse_hover_settings(mouse_x, mouse_y);
    int ok = 1;
    while (!backmenu(mouse_x, mouse_y) && ok == 1)
    {
        if (mouse_x >= x_off1 && mouse_x <= x_off2 && mouse_y >= y_off1 && mouse_y <= y_off2)
        {
            PlaySound(TEXT("close.wav"), NULL, SND_ASYNC);
            setting();
            ok = 0;
        }
        else if (mouse_x >= x_on1 && mouse_x <= x_on2 && mouse_y >= y_on1 && mouse_y <= y_on2)
        {
            PlaySound(TEXT("music.wav"), NULL, SND_ASYNC);
            setting();
            ok = 0;
        }
        else if (mouse_x >= x_light1 && mouse_x <= x_light2 && mouse_y >= y_light1 && mouse_y <= y_light2)
        {
            culbk = 12;
            culfundal = 4;
            setting();
            ok = 0;
        }
        else if (mouse_x >= x_night1 && mouse_x <= x_night2 && mouse_y >= y_night1 && mouse_y <= y_night2)
        {
            culbk = RGB(89, 89, 89);
            culfundal = 0;
            setting();
            ok = 0;
        }
        else
        {
            setting();
            ok = 0;
        }

        clearmouseclick(WM_LBUTTONDOWN);
    }

}


void mouse_hover_menu(int& mouse_x, int& mouse_y)//Cosmin
{
    setfillstyle(0, culbk);
    bool nu_este_facut_click = 1;
    while (nu_este_facut_click)
    {
        mouse_x = mousex();
        mouse_y = mousey();


        if (ismouseclick(WM_LBUTTONDOWN))
            nu_este_facut_click = 0;
        if (mouse_x >= x_PORNIRE1 && mouse_x <= x_PORNIRE2 && mouse_y >= y_PORNIRE1 && mouse_y <= y_PORNIRE2)
        {
            myOuttextXYmenu(780, 425, 14, "DESCHIDE APLICATIE");
            while (mouse_x >= x_PORNIRE1 && mouse_x <= x_PORNIRE2 && mouse_y >= y_PORNIRE1 && mouse_y <= y_PORNIRE2 && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYmenu(780, 425, 15, "DESCHIDE APLICATIE");
        }
        else if (mouse_x >= x_SETARI1 && mouse_x <= x_SETARI2 && mouse_y >= y_SETARI1 && mouse_y <= y_SETARI2)
        {
            myOuttextXYmenu(775, 515, 14, "SETARI");
            while (mouse_x >= x_SETARI1 && mouse_x <= x_SETARI2 && mouse_y >= y_SETARI1 && mouse_y <= y_SETARI2 && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYmenu(775, 515, 15, "SETARI");
        }
        else if (exitmenu(mouse_x, mouse_y) && nu_este_facut_click)
        {
            myOuttextXYmenu(780, 605, 4, "EXIT");
            while (exitmenu(mouse_x, mouse_y) && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYmenu(780, 605, 15, "EXIT");

        }
        else if (mouse_x >= x_semnint1 && mouse_x <= x_semnint2 && mouse_y >= y_semnint1 && mouse_y <= y_semnint2 && nu_este_facut_click)

        {
            myOuttextXYmenu2(1475, 50, 5, "?");
            while (mouse_x >= x_semnint1 && mouse_x <= x_semnint2 && mouse_y >= y_semnint1 && mouse_y <= y_semnint2 && nu_este_facut_click)
            {
                mouse_x = mousex();
                mouse_y = mousey();
                if (ismouseclick(WM_LBUTTONDOWN))
                    nu_este_facut_click = 0;
            }
            myOuttextXYmenu2(1475, 50, 15, "?");
        }
    }

}

void menuprincipal()//Andrei
{
    readimagefile("bko.jpg", 0, 0, 1530, 790);

    myOuttextXYmenu(780, 425, 15, "DESCHIDE APLICATIE");
    myOuttextXYmenu(775, 515, 15, "SETARI");
    myOuttextXYmenu(780, 605, 15, "EXIT");
    myOuttextXYmenu2(1475, 50, 15, "?");

    clearmouseclick(WM_LBUTTONDOWN);
    int mouse_x = mousex();
    int mouse_y = mousey();
    mouse_hover_menu(mouse_x, mouse_y);

    int ok = 1;
    while (!exitmenu(mouse_x, mouse_y) && ok == 1)
    {
        if (mouse_x >= x_PORNIRE1 && mouse_x <= x_PORNIRE2 && mouse_y >= y_PORNIRE1 && mouse_y <= y_PORNIRE2)
        {
            desenare_menu();
            menu();
            menuprincipal();
            ok = 0;
        }
        else if (mouse_x >= x_SETARI1 && mouse_x <= x_SETARI2 && mouse_y >= y_SETARI1 && mouse_y <= y_SETARI2)
        {
            setting();
            menuprincipal();
            ok = 0;
        }
        else if (mouse_x >= x_semnint1 && mouse_x <= x_semnint2 && mouse_y >= y_semnint1 && mouse_y <= y_semnint2)
        {
            info();
            menuprincipal();
            ok = 0;
        }
        else
        {
            menuprincipal();
            ok = 0;
        }
        clearmouseclick(WM_LBUTTONDOWN);
    }

}

int main()
{
    nod N;
    initwindow(1530, 790, "Interschem");
    setbkcolor(culfundal);
    PlaySound(TEXT("music.wav"), NULL, SND_ASYNC);
    cleardevice();
    menuprincipal();
    //getch();
    closegraph();
    return 0;
}
/*
BLACK	0
BLUE	1
GREEN	2
CYAN	3
RED	4
MAGENTA	5
BROWN	6
LIGHTGRAY	7
DARKGRAY	8
LIGHTBLUE	9
LIGHTGREEN	10
LIGHTCYAN	11
LIGHTRED	12
LIGHTMAGENTA	13
YELLOW	14
WHITE	15*/
