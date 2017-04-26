


static result token(char *init_file,char *line,unsigned int *index,char delimiter){
	if(line!=NULL)free(line);
	for(;init_file[index]!=delimiter;index++);
	line=malloc(index*sizeof(char));
	if(line==NULL)return MEMORY_PROBLEM;
	strncpy(line,init_file,i-1);
	line[i]='/0';
	return OK;
}
	
static int char_2_int(char* line){
		int num=0;
		int factor=1;
		for(int i=(strlen(line)-1);i>=0;i--,factor*=10){
			assert(line[i]>='1' && line[i]<='9');
			sum=sum+((int)line[i]-'1')*factor;
		}
		return sum;
}		



Result create_system(char *init_file,ChallengeRoomSystem **sys){
	unsigned int index=0;
	char *line=NULL;
	token(init_file,line,&index,'\n');
	sys->name=malloc((index)*sizeof(char));
	if(sys->name==NULL) return MEMORY_PROBLEM;
	strncpy(sys->name,init_file,i-1);
	sys->name[index++]='/0';
	token(init_file,line,&index,'\n');
	int numOfChallenges=char_2_int(line);
	sys->challenges=malloc(numOfChallenges*sizeof(*Challenge));
	if(sys->challenges==NULL) return MEMORY_PROBLEM;
	
	
}
		
	
	
	
	
	
	
	
	