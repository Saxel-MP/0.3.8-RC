	 // --
  if (szBindAddress) {
		printf( " Started Server on %s:%d, with maxplayers: %d lanmode: %s ac: %s.\n",
			szBindAddress, dwPort, dwMaxPlayers, bLanMode?"ON":"OFF", antiCheat?"ON":"OFF" );
	} else {
		printf( " Started Server on port: %d, with maxplayers: %d lanmode: %s ac: %s.\n",
			dwPort, dwMaxPlayers, bLanMode?"ON":"OFF", antiCheat?"ON":"OFF" );
}

// --
/*
		case ID_AC:
			Packet_AntiCheat(p);
break;
*/


// -- for OnPlayerReconnect -- 
void CNetGame::Packet_NewIncomingConnection(Packet* packet)
{
    in_addr in;
  /*
  
  */
}  



// -- Small fix --

void CNetGame::AddBan(char * nick, char * ip_mask, char * reason)
{
	const struct tm *tm;
	time_t now;
	now = time(NULL);
	tm = localtime(&now);
	char *s;
	s = new char[128];
	strftime(s, 128, "[%d/%m/%y | %H:%M:%S]", tm);

	m_pRak->AddToBanList(ip_mask);
	
	FILE * fileBanList = fopen("samp.ban","a");
	if(!fileBanList) return;
	
	fprintf(fileBanList,"%s %s %s - %s\n", ip_mask, s, nick, reason);
	fclose(fileBanList);

	delete [] s;
} 
