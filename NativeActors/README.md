## Native Actors Plugin (wip)

# Notes

Overrides:
engine/include/gbs_types.h
engine/src/core/actor.c

Functions are in actor.c
behaviour flag is just a number for now
two UWORD's are added to the actor struct, they are script_memory[] idx's that point to locals on the actors for x and y movement
This allows the values to be changed by both the native script and GBVM for more complex behaviours

TODOS:
  a better tile collision check that solves both x and y in the same function, reducing the number of tiles lookups
  wram collision tile sets would be nice, for destuctable tiles, doors etc, and possibly better performance
