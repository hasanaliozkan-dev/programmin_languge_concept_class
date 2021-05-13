#include <stdio.h>
#include "planet.h"


int main(){

    planet_t myPlanet;
    int i = scan_planet(&myPlanet);
    printf("%d",i);



    return 0;
}