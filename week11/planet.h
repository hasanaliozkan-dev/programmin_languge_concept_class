#if !defined(PLANET_H_INCLUDED)
#define PLANET_H_INCLUDED
#define PLANET_STRSIZ 10
typedef struct 
{
    char name[PLANET_STRSIZ];
    double diameter;
    int moons;
    double orbit_time,rotation_time;
}planet_t;

extern void print_planet(planet_t p1);
extern int planet_equal(planet_t p1 ,planet_t p2);
extern int scan_planet(planet_t *plnp);




#endif // PLANET_H_INCLUDED
