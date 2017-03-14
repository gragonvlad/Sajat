#include "ScriptPCH.h"
#include "Language.h"

class Npc_Valto : public CreatureScript
{
public:
        Npc_Valto() : CreatureScript("Npc_Valto") { }
		
	bool OnGossipHello(Player* player, Creature * creature) override
	{
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\Achievement_BG_winWSG:35:35:-14|t Badge of Justice -> Aréna Pont", GOSSIP_SENDER_MAIN, 1);
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\Achievement_BG_winWSG:35:35:-14|t Badge of Justice -> Honor Pont", GOSSIP_SENDER_MAIN, 2);

		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}
	
	bool OnGossipSelect(Player* player, Creature* _creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
		
		uint32 $Token = player->HasItemCount(29434);
		uint32 $Warsong_Token = 29434;
 
        if (uiSender == GOSSIP_SENDER_MAIN)
        {
 
            switch (uiAction)
            {
				case 1:
					AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\INV_Ingot_05:30|t 1 token -> 1000 arena pont", GOSSIP_SENDER_MAIN, 11);
					AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\INV_Ingot_05:30|t 2 token -> 2000 arena pont", GOSSIP_SENDER_MAIN, 12);
					AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\INV_Ingot_05:30|t 5 token -> 5000 arena pont", GOSSIP_SENDER_MAIN, 13);
					player->PlayerTalkClass->SendGossipMenu(1, _creature->GetGUID());
					break;
					
				case 2:
					AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\INV_Ingot_05:30|t 1 token -> 50000 honor", GOSSIP_SENDER_MAIN, 21);
					player->PlayerTalkClass->SendGossipMenu(1, _creature->GetGUID());
					break;
					
				/* Token váltása Aréna Pontra */
				case 11:
					if ($Token >= 1)
					{
						player->DestroyItemCount($Warsong_Token, 1, true);
						player->ModifyArenaPoints(1000);
						player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						_creature->TextEmote("Nincs elég tokened a váltáshoz! Kérlek gyere vissza később!", player);
						player->PlayerTalkClass->SendCloseGossip();
					}
						
				case 12:
					if ($Token >= 2)
					{
						player->DestroyItemCount($Warsong_Token, 2, true);
						player->ModifyArenaPoints(2000);
						player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						_creature->TextEmote("Nincs elég tokened a váltáshoz! Kérlek gyere vissza később!", player);
						player->PlayerTalkClass->SendCloseGossip();
					}
						
				case 13:
					if ($Token >= 5)
					{
						player->DestroyItemCount($Warsong_Token, 5, true);
						player->ModifyArenaPoints(5000);
						player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						_creature->TextEmote("Nincs elég tokened a váltáshoz! Kérlek gyere vissza később!", player);
						player->PlayerTalkClass->SendCloseGossip();
					}
					
				/* Token váltása Honor Pontra */
				case 21:
					if ($Token >= 1)
					{
						player->DestroyItemCount($Warsong_Token, 1, true);
						player->ModifyHonorPoints(2000);
						player->PlayerTalkClass->SendCloseGossip();
					}
					else
					{
						_creature->TextEmote("Nincs elég tokened a váltáshoz! Kérlek gyere vissza később!", player);
						player->PlayerTalkClass->SendCloseGossip();
					}
			}
 
 
        }
        return true;
    }
};

void AddSC_Npc_Valto()
{
    new Npc_Valto();
}