#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int AFDToLanguage(int state, char str){ //Regular Expression: b(a+b)b+(a+b)bb(a+b)+(a+b)(a+b)b(&+(a+b)*b)(a+b)(a+b)

    int i = 0;
    //while(1)
    {

    	//if(str == '\0') break;

        switch(state){

            case 0:

                if(str=='a') state = 2;

                else if(str=='b')state = 1;

                break;

            case 1:

                if(str=='a') state = 4;

                else if(str=='b')state = 3;

                break;

            case 2:

                if(str=='a') state = 6;

                else if(str=='b')state = 5;

                break;

            case 3:

                if(str=='a') state = 8;

                else if(str=='b')state = 7;

                break;

            case 4:

                if(str=='a') state = 8;

                else if(str=='b')state = 9;

                break;

            case 5:

                if(str=='a') state = 8;

                else if(str=='b')state = 10;

                break;

            case 6:

                if(str=='a') state = 8;

                else if(str=='b') state = 11;

                break;

            case 7:

                if(str=='a') state = 12;

                else if(str=='b') state = 7;

                break;

            case 8:

                if(str=='a') state = 8;

                else if(str=='b') state = 8;

                break;

            case 9:

                if(str=='a') state = 13;

                else if(str=='b') state = 10;

                break;

            case 10:

                if(str=='a') state = 12;

                else if(str=='b') state = 7;

                break;

            case 11:

                if(str=='a') state = 13;

                else if(str=='b') state = 10;

                break;

            case 12:

                if(str=='a') state = 14;

                else if(str=='b') state = 9;

                break;

            case 13:

                if(str=='a') state = 14;

                else if(str=='b') state = 9;

                break;

            case 14:

                if(str=='a') state = 15;

                else if(str=='b') state = 11;

                break;

            case 15:

                if(str=='a') state = 15;

                else if(str=='b') state = 11;

                break;
        }
        i++;
    }
    
    return state;

}

int Extended_transition_function(int state, char *word){
	if(word[0] == '\0') return state;

	else {

		char a=word[strlen(word)-1];
		word[strlen(word)-1]='\0';
		return AFDToLanguage(Extended_transition_function(state, word), a);
		//return transictionFunction(word.at(word.length()-1), extendedTransictionFunction(word.left(word.length()-1), initialState));

	}

}

int main(){

    char *str = NULL, c;
    int i, j, state, flag;
    do{
	    printf("\n--------------------------------------------------------------------------\n");
	    printf("\nAlphabet: {a,b}\n");
	    printf("\nRegular Expression: b(a+b)b+(a+b)bb(a+b)+(a+b)(a+b)b(&+(a+b)*b)(a+b)(a+b)\n");
	    printf("\nENTER:\n\t 1 - ENTER WITH STRING\n\t 2 - LEAVE\n\t:");
	    scanf ("%d", &flag);
	     getchar();

	    switch(flag){

		    case 1:

		    	 free(str);

		    	 i = 1;
		    	 j = 2;
			    
			    str = (char*)malloc(sizeof(char));

			    printf("\n\tENTER STRING: ");

			    scanf("%c", &str[0]);

			    while (1) {

			        scanf("%c", &c);

			        if(c == '\n') break;

			        str = (char*)realloc(str, j * sizeof(char));

			        str[i] = c;

			        i++;
			        j++;

			    }

			    str[i] = '\0';

			    printf("\n\tTHE ENTERED STRING IS: %s\n\n", str);//for(j=0;j<=i;j++) printf("%c",*(str+j));

			    state = Extended_transition_function(0,str);
			    //state = extendedTransictionFunction(0,str);
		    	printf("ESTADO: %d\n", state);
		    	if(state == 7 || state == 9 || state == 12 || state == 14) printf("\n\tWas recognized!\n\n");
			    
			    else printf("\n\tThis word was not recognized\n\n");

			    break;
		    	

			default:
				break;
			    
		}

	}while(flag != 2);

    return 0;
}
