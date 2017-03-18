#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "Player.h"


enum  defines
{
	token = 29434 // Warsong token
};

class Npc_Valto : public CreatureScript
{
public:
        Npc_Valto() : CreatureScript("Npc_Valto") { }
		
	bool OnGossipHello(Player* player, Creature * creature) override
	{
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\INV_Ingot_05:30|t 1 token -> 1000 arena pont", GOSSIP_SENDER_MAIN, 0);
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\INV_Ingot_05:30|t 2 token -> 2000 arena pont", GOSSIP_SENDER_MAIN, 1);
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\INV_Ingot_05:30|t 5 token -> 5000 arena pont", GOSSIP_SENDER_MAIN, 2);
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "---------------", GOSSIP_SENDER_MAIN, 3);
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\INV_Ingot_05:30|t 1 token -> 50000 honor", GOSSIP_SENDER_MAIN, 4);

		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}
	
	bool OnGossipSelect(Player* player, Creature* _creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
		
		uint32 $Warsong_Token = 29434;
 
            switch (uiAction)
            {
				
				/* Token váltása Aréna Pontra */
				case 0:
				{
					if(player->HasItemCount(token, 1))
					{
						player->DestroyItemCount($Warsong_Token, 1, true);
						player->ModifyArenaPoints(1000);
						player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						_creature->TextEmote("Nincs elég tokened a váltáshoz! Kérlek gyere vissza később!", player);
						player->PlayerTalkClass->SendCloseGossip();
						return false;
					}
				}
				break;
				
				/* Token váltása Aréna Pontra */
				case 1:
				{
					if(player->HasItemCount(token, 2))
					{
						player->DestroyItemCount($Warsong_Token, 2, true);
						player->ModifyArenaPoints(2000);
						player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						_creature->TextEmote("Nincs elég tokened a váltáshoz! Kérlek gyere vissza később!", player);
						player->PlayerTalkClass->SendCloseGossip();
						return false;
					}
				}
				break;
				
				/* Token váltása Aréna Pontra */
				case 2:
				{
					if(player->HasItemCount(token, 5))
					{
						player->DestroyItemCount($Warsong_Token, 5, true);
						player->ModifyArenaPoints(5000);
						player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						_creature->TextEmote("Nincs elég tokened a váltáshoz! Kérlek gyere vissza később!", player);
						player->PlayerTalkClass->SendCloseGossip();
						return false;
					}
				}
				break;
					
				/* Token váltása Honor Pontra */
				case 4:
				{
					if(player->HasItemCount(token, 1))
					{
						player->DestroyItemCount($Warsong_Token, 1, true);
						player->ModifyHonorPoints(50000);
						player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						_creature->TextEmote("Nincs elég tokened a váltáshoz! Kérlek gyere vissza később!", player);
						player->PlayerTalkClass->SendCloseGossip();
						return false;
					}
				}
				break;
				
				case 3:
				{
					player->PlayerTalkClass->SendCloseGossip();
				}
				break;
			}
			return true;
    }
};

void AddSC_Npc_Valto()
{
    new Npc_Valto();
}