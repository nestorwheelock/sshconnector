/*
===========================================================================

SSHConnector
Copyright (C) 2013 Spalt3r Development

===========================================================================
*/

#ifndef __config_H__
#define __config_H__

/*
===============================================================================

config

===============================================================================
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

typedef struct t_host {
	string name;
	string host;
	string port;
	string user;
} t_host;

class Config {
public:
					Config( void );
					~Config( void );
	void 			Initialize( char *file );
	vector<t_host> 	GetHosts( void );
	void			CopyToVectorList( vector<char*> &result );
	int				CopyToCharArray( char** &result );
	char*			GetSshCommandById( int index );
private:
	void 			ReadConfig( void );
	void 			SplitLine( char *line );
	vector<string> 	&Split( const string &str, char delimeter, vector<string> &items );
	vector<string>	Split( const string &str, char delimeter );
	char			*ToCharArray( string &value );
	char 			*BuildHostLine( string &name, string &host, string &port, string &user );

	char			*filename;
	vector<t_host> 	hosts;
};

#endif /* !__config_H__ */