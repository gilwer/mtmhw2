#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>


#include "visitor_room.h"

/* IMPLEMENT HERE ALL WHAT IS NEEDED */




static void compare(void* a,void* b){
	return strcmp((*ChallengeActivity)a->challenge->name),(*ChallengeActivity)b->challenge->name));
}


Result init_challenge_activity(ChallengeActivity *activity, Challenge *challenge){
    if(activity==NULL) return NULL_PARAMETER;
    if(challenge==NULL) return NULL_PARAMETER;
    activity->challenge=challenge;
    return OK
}

Result reset_challenge_activity(ChallengeActivity *activity){
    if(activity==NULL) return NULL_PARAMETER;
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
	if(room==NULL) return NULL_PARAMETER;
	*places=0;
	for(int i=0;i<room->num_of_challenges;i++){
		if(room->challenges->visitor!=NULL)continue;
		if((room->challenges->challenge->level==level) || (level==All_Levels)){
			*places++;
		}
	}
	return OK;
}

result change_room_name(ChallengeRoom *room,char *new_name){
		if(room==NULL || new_name==NULL)return NULL_PARAMETER;
		free(room->name);
		room->name=malloc((strlen(new_name)+1)*sizeof(char));
		if(room->name==NULL) return MEMORY_PROBLEM;
		strcpy(room->name,new_name);
		return OK;
}

result room_of_visitor(Visitor *visitor,char **room_name){
	if(visitor==NULL) return NULL_PARAMETER;
	if(visitor->room_name==NULL) return NOT_IN_ROOM;
	room_name=malloc((strlen(visitor->room_name)+1)*sizeof(char));
	if(room_name==NULL) return MEMORY_PROBLEM;
	strcpy(*room_name,visitor->room_name);
	return OK;
}



result visitor_enter_room(ChallengeRoom *room,Visitor *visitor,Level level,int start_time){
	if(room==NULL || visitor==NULL) return NULL_PARAMETER;
	if(visitor->room_name!=NULL) return ALREADY_IN_ROOM;
	int places=0;
	num_of_free_places_for_level(room,level,&places);
	if(places==0) return NO_AVAILABLE_CHALLENGES;
	qrort(room->challenges,room->num_of_challenges,sizeof(ChallengeActivity),cmpare());
	for(int i=0;i<room->num_of_challenges;i++){
		if(room->challenges[i]->visitor==NULL &&(level==All_Levels ||room->challenges[i]->challenge->level==level)){
			room->challenges[i]->start_time=start_time;
			room->challenges[i]->visitor=*visitor;
			visitor->room_name=*room->name;
			break;
		}
	}
	return OK;
}

result visitor_quit_room(Visitor *visitor,int quit_time){
	if(visitor==NULL)return NULL_PARAMETER;
	char** room_name=NULL
	if(room_of_visitor(visitor,room_name)==NOT_IN_ROOM)return NOT_IN_ROOM;
	int bestTime=0;
	best_time_ofchallenge(visitor->current_challenge,&bestTime)
	int newTime=(quit_time-visitor->current_challenge->start_time);
	if(newTime<bestTime){
		set_best_time_of_challenge(visitor->current_challenge,newTime);
	}
	visitor->current_challenge->visitor=NULL;
	visitor->current_challenge=NULL;
	visitor->room_name=NULL;
	return OK;
}


	
	



