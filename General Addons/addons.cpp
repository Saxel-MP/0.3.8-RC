// -- Images --

int ImageCreate(char* location, int pos);
// location is ; scriptfiles/images/x.img

int ImageDestroy(int ID);
int ImageSetColor(int id, unsigned int color);
int ImageSetPos(int id, int pos);
int ImageUpdate(int id, char* location);

// -- TextDraw --
int TextDrawUseCustomFont(int textdrawid, char* location);

// -- Hud --
int ToggleHUDComponent(int componentid, bool toggle);
int ToggleHUDComponentForPlayer(int playerid, int componentid, bool toggle);

// -- Client --
// int GCI(int playerid);
//
int GetPlayerCountry(int cid);
//
int AllowPlayerScreenShot(int playerid, bool toggle);
int TakePlayerScreenshot(int playerid);
int ToggleClientCommand(int playerid, char* command, bool toggle);
int IsPlayerDisconnected(char* szName);
//
int SetPlayerGameSpeed(int playerid, float speed);
/*
native SetPlayerGravity(playerid, Float:gravity);
native Float:GetGravity();
//
native GetPlayerScreenResolution(playerid, resolution);
//
native GetPlayerSize(playerid);
native SetPlayerSize(playerid, size);  / forward OnPlayerChangeSize(playerid, newsize, oldsize); 
*/

// -- Vehicles --
int setPlayerVehicleComponent(struct vehicle_info *pComponent);
{
 // ...
}

/*

*/
// forward OnPlayerReconnect(playerid);
int CGameMode::OnPlayerReconnect(cell playerid)
{
        CHECK_INIT();

        int idx;
        cell ret = 0;

        if (!amx_FindPublic(&m_amx, "OnPlayerReconnect", &idx))
        {
                amx_Push(&m_amx, playerid);
                amx_Exec(&m_amx, &ret, idx);
        }
        return (int)ret;
}

// forward OnClientBanned(playerid, serialid);
int CGameMode::OnClientBanned(cell playerid, cell clientid)
{
        CHECK_INIT();

        int idx;
        cell ret = 0;

        if (!amx_FindPublic(&m_amx, "OnClientBanned", &idx))
        {
                amx_Push(&m_amx, amx_ftoc( clientid ) );
                amx_Push(&m_amx, playerid);
                amx_Exec(&m_amx, &ret, idx);
        }
        return (int)ret;
}
// forward OnPlayerPushKey(playerid, key);
	// Support all keys
int CGameMode::OnPlayerPushKey(cell playerid, cell key)
{
        CHECK_INIT();

        int idx;
        cell ret = 0;

        if (!amx_FindPublic(&m_amx, "OnPlayerPushKey", &idx))
        {
            	amx_Push(&m_amx, amx_ftoc( key ) );
                amx_Push(&m_amx, amx_ftoc( playerid ) );
                amx_Exec(&m_amx, &ret, idx);
        }
        return (int)ret;
}
//

/*
native GetVehicleNumberPlate(vehicleid);
*/

// forward OnVehicleCrashVehicle(pveh, iveh);
int CGameMode::OnVehicleCrashVehicle(cell pveh, cell iveh)
{
        CHECK_INIT();

        int idx;
        cell ret = 0;

        if (!amx_FindPublic(&m_amx, "OnVehicleCrashVehicle", &idx))
        {
                amx_Push(&m_amx, pveh);
                amx_Push(&m_amx, iveh);
                amx_Exec(&m_amx, &ret, idx);
        }
        return (int)ret;
}

/*
int CGameMode::OnPlayerCheatDetect(cell playerid, cell cheatID)
*/

// -- passenger 'G' bug fix --

void CPlayer::StorePassengerFullSyncData(PASSENGER_SYNC_DATA *ppsSync)
{
        m_VehicleID  = ppsSync->VehicleID;

        CFilterScripts * pFilterScripts = pNetGame->GetFilterScripts();
        CGameMode * pGameMode = pNetGame->GetGameMode();

        memcpy(&m_psSync,ppsSync,sizeof(PASSENGER_SYNC_DATA));
        UpdatePosition(m_psSync.vecPos.X,m_psSync.vecPos.Y,m_psSync.vecPos.Z);

        m_fHealth = (float)m_psSync.bytePlayerHealth;
        m_fArmour = (float)m_psSync.bytePlayerArmour;

        m_psSync.byteCurrentWeapon = CheckWeapon(m_psSync.byteCurrentWeapon);

        m_byteUpdateFromNetwork = UPDATE_TYPE_PASSENGER;

        /*
                HERE...
        */
/* void CRemotePlayer::StorePassengerFullSyncData(PASSENGER_SYNC_DATA *ppsSync)
{
	if(GetTickCount() < m_dwWaitForEntryExitAnims) return;
	memcpy(&m_psSync,ppsSync,sizeof(PASSENGER_SYNC_DATA));

	m_VehicleID = ppsSync->VehicleID;
	m_byteSeatID = ppsSync->byteSeatFlags & 127;
	m_pCurrentVehicle = pNetGame->GetVehiclePool()->GetAt(m_VehicleID);

	m_fReportedHealth = (float)ppsSync->bytePlayerHealth;
	m_fReportedArmour = (float)ppsSync->bytePlayerArmour;
	m_byteUpdateFromNetwork = UPDATE_TYPE_PASSENGER;

	SetState(PLAYER_STATE_PASSENGER);
}*/

///
/*
		if( pNetGame->GetGameState() == GAMESTATE_CONNECTED &&
			!pNetGame->GetRakClient()->IsConnected() ) {
				break;
}*/
///////////////////////////////////////////////////////////////////////////////////



