#include <iostream>
#include <stdio.h>
#include <locale.h>
#include "aquila.h"

using namespace std;

int main ()

{

setlocale(LC_ALL,"");

printf("Dó\n") ;
Beep (261, 2000);

printf("Ré\n");
Beep (293, 2000);

printf("Mi\n");
Beep (329, 2000);

printf("Fá\n");
Beep (349, 2000);

printf("Sol\n");
Beep (392, 2000);

printf("Lá\n");
Beep (440, 2000);

printf("Si\n");
Beep (493, 2000);

return 0;
}