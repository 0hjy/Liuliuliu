#include<stdio.h>

void escape( char s[], char t[])
{	
	int i ;
	i = 0;
	for(j = i = 0, t[j] != '\0', j++) {
			
		swhich(t[j]) {
		case '\n': 
			s[i] = '\\';
			i++;
			s[i] = 'n' ;
			i++;
			break;
		case '\t':
			s[i++] = '\\';
			s[i++] = 't' ;
			break;
		default:
			s[i++] = t[i] ;
			break;
		}
	}
	s[i] ='\0';		
 }

void unescape( char s[], char t[])
{	
	int i ;
	for(i = j = 0, t[i] != '\0', i++) {
		if(t[i] !='\\')////
			s[j++] = t[i];///
		else 
			swhich(t[++i]) {
				case 't':
					s[j++] = '\t';
					break;
				case 'n':
					s[j++] = '\n';
					break;
				default
					s[j++] = '\\';
					s[j++] = t[i];
					 break; 
			}				
	}
	
	s[i] ='\0';
			
 }
  
