#include <iostream>
#include <string>
using namespace std;
int compareAlpha(char *sz[500],int last,char *aa[100]);
void After45(char *ss,int w);

void main (int argc,char *argv[]){
	char fname[20]="index.txt";
	char *szBuf[500],*index[500],*tindex[500],*aa[100];
	string sz="0";
	char c[30];
	int count[500],i=0;;
	FILE *fp;
	//preszBuf
	if((fp=fopen(fname,"rb")) == NULL)
		{
		printf("Error: Can't open file.\n");
		return ;
		}
	while((i<500)&&((fscanf(fp,"%s",c))!=EOF)){
		
			szBuf[i]=(char*)malloc(strlen(c));
			strcpy(szBuf[i],c);
			//printf("szBuf[%d] = %s \n",i,szBuf[i]);
		i++;
	}
	fclose(fp);
	printf("Total %d \n",i);
	//szBuf
	int last=i,las;
	las=compareAlpha(szBuf,last,aa);
	last+=las;
	cout<<last<<"PHU\n";
	
	for(i=0;i<last;i++){
		count[i] = 0;
		index[i] = "0";
	}

	for(int n=0;n<last;n++){
		for(int a=0;a<last;a++){
			if(strcmp(szBuf[n],szBuf[a])==0)
				++count[n];	
		}
		//printf("count[%d] = %d \n",n,count[n]);
	}
	
	//preindex
	int lindex=0;
	for(int n=0;n<last;n++){
		while(count[n]<=2)n++;
		if(n>=last)break;
		index[lindex]=szBuf[n];
		//printf("index[%d] = %s \n",n,index[lindex]);
		lindex++;
	}

	//Tindex
	int check=1;
	bool bb=true;
	tindex[0]=index[0];
	for(int n=1;n<lindex;n++){
		bb=true;
		for(i=0;i<check;i++){
			if(strcmp(tindex[i],index[n])==0){
			bb=false;
			}	
		}
		if(bb){
				tindex[check]=index[n];
				check++;
				}
	}
	//show
	for(int n=0;n<last;n++){
		printf("count[%d] = %d ,szBuf[%d] = %s  \n",n,count[n],strlen(szBuf[n]),szBuf[n]);
	}
	for(int n=0;n<check;n++){
		//printf("tindex[%d] = %s  \n",n,tindex[n]);
	}

}
int compareAlpha(char *szBuf[500],int last,char *aa[100]){
	char c[30],cR7[30];
	int bp,oi=0;
	int las=last;
	for(int i=0;i<las;i++){
	strcpy(c,szBuf[i]);
	strcpy(cR7,c);
	bool bnT=false;
		for(int j=0;j<strlen(c);j++){
	
			if((c[j]>=65&&c[j]<=90)){
				c[j]+=32;
			}
			else if((c[j]>=58&&c[j]<=96)||((c[j]<=44)&&(c[j]!=36))||(c[j]==46)){
					c[j]=' ';
					
			}
		}//for
		bool k=false;
		bp=0;
		for(int b=0;b<strlen(c)||k;b++){
				if((c[b]==45)||(c[b]==36)){
						strcpy(cR7,c);
						//aa[oi]=c;
						szBuf[last]=c;
						//printf("szBUF[%d] = %s ,%d\n",last,szBuf[last],strlen(szBuf[last]));
						last++;
						//printf("sz[%d] = %s ,%d\n",oi,aa[oi],strlen(aa[oi]));
						oi++;
						
						After45(cR7,b+1);
						//aa[oi]=cR7;
						szBuf[last]=cR7;
						//printf("szBUF[%d] = %s ,%d\n",last,szBuf[last],strlen(szBuf[last]));
						last++;

						//printf("sz[%d] = %s ,%d\n",oi,aa[oi],strlen(aa[oi]));
						oi++;
						
						
				}
				if((c[b]>=97&&c[b]<=122)||(c[b]>=47&&c[b]<=57)){
					c[bp]=c[b];
					bp++;
					k=true;
				}else if(c[b]==' '&&c[b+1]==' '){
					b++;
				}
				else if(k&&c!=NULL){
					c[bp]=NULL;
					strcpy(szBuf[i],c);
					//printf("aZZ[%d] = %s \n",i,szBuf[i]);
					break;

				}	
		}
			
			
	}//for
	for(int ppt=0;ppt<last;ppt++){
		printf("sz[%d] = %s \n",ppt,szBuf[ppt]);
	}
	return oi;
}
void After45(char *ss,int w){
	char cx[30];
	int cc=0;
	for(;(w<strlen(ss)&&(ss[w]>=97&&ss[w]<=122)||(ss[w]>=47&&ss[w]<=57));w++){
		cx[cc]=ss[w];
		cc++;	
	}
	cx[cc]=NULL;
	strcpy(ss,cx);
	
}