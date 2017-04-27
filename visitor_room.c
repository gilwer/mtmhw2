#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>


#include "visitor_room.h"

/* IMPLEMENT HERE ALL WHAT IS NEEDED */
Result init_challenge_activity(ChallengeActivity *activity, Challenge *challenge){
    if(activity==NULL) return NULL_PAREMETER;
    if(challenge==NULL) return NULL_PAREMETER;
    activity->challenge=challenge;
    return OK
}

Result reset_challenge_activity(ChallengeActivity *activity){
    if(activity==NULL) return NULL_PAREMETER;
    activity->challenge=NULL;
    activity->visitor=NULL;
    start_time=0;
    return OK;
}

Result init_visitor(Visitor *visitor, char *name, int id){
    if(visitor==NULL || name==NULL) return NULL_PARAMETER;
    visitor->visitor_name=malloc((strlen(name)+1)*sizeof(char));
    if(visitor->visitor_name==NULL)return MEMORY_PROBLEM;
    strcpy(visitor->visitor_name,name);
    return OK;
}

Result reset_visitor(Visitor *visitor){
    if(visitor==NULL) return NULL_PARAMETER;
    visitor->visitor_id=0;
    free(visitor->visitor_name);
    visitor->current_challenge=NULL;
    visitor->room_name=NULL;
    return OK;
}

Result init_room(ChallengeRoom *room, char *name, int num_challenges){
    if(room==NULL || name==NULL)return NULL_PARAMETER;
    if(num_challenges==0)return ILLEGAL_PARAMETER;
    room->name=malloc((strlen(name)+1)*sizeof(char));
    if(room->name==NULL) return MEMORY_PROBLEM;
    strcpy(room->name,name);
    room->num_of_challenges=num_challenges;
    room->challenges=malloc(sizeof(ChallengeActivity)*num_challenges);
    if(room->challenges==NULL)return MEMORY_PROBLEM;
    return OK;
}

Result reset_room(ChallengeRoom *room){
    if(room==NULL)return NULL_PARAMETER;
    free(room->name);
    for(int i=0;i<room->num_of_challenges;i++){
        reset_challenge_activity(room->challenges[i]);
    }
    free(room->challenges);
    room->num_of_challenges=0;
    return OK;
}

Result num_of_free_places_for_level(ChallengeRoom *room, Level level, int *places){

}