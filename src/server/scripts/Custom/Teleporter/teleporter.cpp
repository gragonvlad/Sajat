#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "Player.h"

#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

enum{
	
	Hehe = 0,
};

class npc_teleporter : public CreatureScript
{
    public:
        npc_teleporter() : CreatureScript("npc_teleporter") { }
	
	bool OnGossipHello(Player* player, Creature * creature) override
	{
		std::stringstream s;
		
		QueryResult result = WorldDatabase.Query("SELECT id, name, map, x, y, z, o, active FROM npc_teleport WHERE active = 1");
		if (result)
		{
			do
			{
				char const* id = (*result)[0].GetCString();
				std::string name = (*result)[1].GetCString();
				uint32 map = (*result)[2].GetUInt32();
				uint32 x = (*result)[3].GetUInt32();
				uint32 y = (*result)[4].GetUInt32();
				uint32 z = (*result)[5].GetUInt32();
				uint32 o = (*result)[6].GetUInt32();
				uint32 active = (*result)[7].GetUInt32();
				
				
				AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, name, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+(*result)[0].GetUInt32());
			}
			while (result->NextRow());
		}
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}
	
	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	{
		std::stringstream s;
		
		QueryResult result = WorldDatabase.Query("SELECT id FROM npc_teleport WHERE active = 1");
		if (result)
		{
			do
			{
				char const* id = (*result)[0].GetCString();
				
				switch (action)
				{
					
					/* Token váltása Aréna Pontra */
					case Hehe:
					{
						player->TeleportTo(1, -8923.932f, -1360.171f, 25.272f, 0.789f);
					}
					break;
				}
				return true;
			}
			while (result->NextRow());
		}
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}
};


void AddSC_NPC_Teleporter()
{
	new npc_teleporter();
}