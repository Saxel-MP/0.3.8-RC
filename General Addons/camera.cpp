/*
	-- FPS Mode --
*/
	int GetPlayerCameraID(int playerid, int camid);
	int SetPlayerCameraID(int playerid, int camid);
//

// -- Chat --
/*
native MakeChatboxLink(text[], linkdata[])

/*
forward OnPlayerClickChatboxLink(playerid, fromplayer, linkdata[])
*/

/*
format( string, 64, "%s", MakeChatboxLink("checkme", myLink);
*/


// -- Client check debug --
//
//for(new i= 0x00; i <= 0xff; i++) SendClientCheck(playerid, i, i, i, 0x4);
//


//
/*

	case 0x [               ]:
		Log( " XXX " );
	break;
*/


// -- For game files --
native GetModuleHandle(file[]);
