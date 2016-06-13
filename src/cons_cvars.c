//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2016 by Gareth Nelson (gareth@garethnelson.com)
//
// This file is part of the Lambda engine.
//
// The Lambda engine is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// The Lambda engine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
//
// $Log:$
//
// DESCRIPTION:
//     CVars (Console variables) implementation
//
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "l_console.h"

#include "cons_cvars.h"

struct cons_cvar_t* cvars_ht=NULL;

void dump_cvars() {
     struct cons_cvar_t* entry=NULL;
     for(entry=cvars_ht; entry!=NULL; entry=entry->hh.next) {
         switch(entry->var_type) {
            case CVAR_STRING:
               console_printf("%s=\"%s\"\n",entry->var_name,entry->s_val);
            break;
            case CVAR_FLOAT:
            break;
            case CVAR_BOOL:
            break;
            case CVAR_INT:
            break;
         }
     }
}

void set_cvar_s(char* name, char* val) {
     struct cons_cvar_t* entry=NULL;
     HASH_FIND_STR(cvars_ht,name,entry);
     if(entry==NULL) {
        entry = malloc(sizeof(struct cons_cvar_t));
        snprintf(entry->var_name,32,"%s",name);
        entry->var_type = CVAR_STRING;
        snprintf(entry->s_val,1024,"%s",val);
        HASH_ADD_STR(cvars_ht,var_name,entry);
     } else {
        entry->var_type = CVAR_STRING;
        snprintf(entry->s_val,1024,"%s",val);
     }
}

void set_cvar_f(char* name, float val) {
}

void set_cvar_i(char* name, int val) {
}

void toggle_cvar(char* name) {
}

char* get_cvar_s(char* name) {
}

float get_cvar_f(char* name) {
}

int   get_cvar_i(char* name) {
}

