#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED

#include <stdlib.h>
#include <iomanip>
#include "time.h"
#include <stdlib.h>
#include <iomanip>
#include "windows.h"
#include <iostream>

using namespace std;

class Tela
{
public:
    static void inicio ();
    static void credDeb ();
    static void limpaTela ();
    static void moldura();
    static void molduraPrint();
    static void gotoxy(int ,int);
};

#endif // TELA_H_INCLUDED
