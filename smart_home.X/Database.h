#ifndef DATABASE_H
#define	DATABASE_H


int check_str_user(unsigned int address,char *Input_username);
int check_str_pass(unsigned int address, char *Input_username);

int check_user(char *username,char *password);
int check_admin(char *username, char *password);
#endif	/* DATABASE_H */

