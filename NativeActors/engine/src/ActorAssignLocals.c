#pragma bank 255

#include "vm_actor.h"

#include "actor.h"
#include "data_manager.h"

//#include "vm.h"
//#include "math.h"

void actor_assign_locals(SCRIPT_CTX * THIS) OLDCALL BANKED {
    UBYTE * n_actor = VM_REF_TO_PTR(FN_ARG0);
    actor_t * actor = actors + *n_actor;
    actor->behaviour = *(uint8_t*)VM_REF_TO_PTR(FN_ARG1);
    actor->varref[0] = *(UWORD*)VM_REF_TO_PTR(FN_ARG3);
    actor->varref[1] = *(UWORD*)VM_REF_TO_PTR(FN_ARG2);
}