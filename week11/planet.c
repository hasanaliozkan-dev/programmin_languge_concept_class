#include <stdio.h>
#include <string.h>
#include "planet.h"

void print_planet(planet_t pl){

    printf("%s\n",pl.name);
    printf("Equtorial diameter: %.0f  km\n",pl.diameter);
    printf("Number of moons: %d\n",pl.moons);
    printf("Time to complete one orbit of the sun: %.2f years\n",pl.orbit_time);
    printf("Time to complete one rotation on axis: %.4f hours\n",pl.rotation_time);
}
int planet_equal(planet_t planet_1,planet_t planet_2){
    return(strcmp(planet_1.name,planet_2.name) == 0 &&
            planet_1.diameter == planet_2.diameter &&
            planet_1.moons == planet_2.moons &&
            planet_1.orbit_time == planet_2.orbit_time&&
            planet_1.rotation_time == planet_2.rotation_time);
}
int scan_planet(planet_t *plnp){
    int result;
    result = scanf("%s%lf%d%lf%lf",plnp->name,&plnp->diameter,&plnp->moons,&plnp->orbit_time,&plnp->rotation_time);
    if (result == 5)
    {
        result = 1;
    }
    else if (result != EOF)
    {
        result =0;  
    }
    return result;
}