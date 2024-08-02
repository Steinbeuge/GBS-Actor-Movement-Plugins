#pragma bank 255

#include <gbdk/metasprites.h>

#include "actor.h"
#include "game_time.h"
#include "data_manager.h"
#include "scroll.h"
#include "math.h"
#include "macro.h"
#include "vm_actor.h"
//#include "data/game_globals.h"
//#include "vm.h"

void beugs_actor_move_bounce_x(SCRIPT_CTX * THIS) OLDCALL BANKED {

    UBYTE * n_actor = VM_REF_TO_PTR(FN_ARG0);
    actor_t * actor = actors + *n_actor;

    INT16 *mov = VM_REF_TO_PTR(FN_ARG1); // data from and to VM must be INT16
    UBYTE dir = *mov < 0 ? CHECK_DIR_LEFT : CHECK_DIR_RIGHT;

    INT16 targ = (actor->pos.x + *mov);
    if( (targ & 0xFFF0) == (actor->pos.x & 0xFFF0) ) {
        actor->pos.x = targ; //subpixel movement requires no check
        return;}

    INT16 newpos = check_collision_in_direction(actor->pos.x, actor->pos.y, &actor->bounds, targ, dir);
    if( targ != newpos ){ 
        *(INT16*)VM_REF_TO_PTR(FN_ARG1) = -(*mov); // bounce
    } else {
        actor->pos.x = newpos;
    }
}

void beugs_actor_move_bounce_y(SCRIPT_CTX * THIS) OLDCALL BANKED {

    UBYTE * n_actor = VM_REF_TO_PTR(FN_ARG0);
    actor_t * actor = actors + *n_actor;

    INT16 *mov = VM_REF_TO_PTR(FN_ARG1); // data from and to VM must be INT16
    UBYTE dir = *mov < 0 ? CHECK_DIR_UP : CHECK_DIR_DOWN;

    INT16 targ = (actor->pos.y + *mov);
    if( (targ & 0xFFF0) == (actor->pos.y & 0xFFF0) ) {
        actor->pos.y = targ; //subpixel movement requires no check
        return;}

    INT16 newpos = check_collision_in_direction(actor->pos.x, actor->pos.y, &actor->bounds, targ, dir);
    if( targ != newpos ){ 
        *(INT16*)VM_REF_TO_PTR(FN_ARG1) = -(*mov); // bounce
    } else {
        actor->pos.y = newpos;
    }
}