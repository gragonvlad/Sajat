#include "ScriptPCH.h"
#include "ScriptedGossip.h"

class MTG_Npc_Tools : public CreatureScript
{
public:
        MTG_Npc_Tools() : CreatureScript("MTG_Npc_Tools") { }
 
        bool OnGossipHello(Player *player, Creature *creature)
        {
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\Spell_Nature_Regenerate:40:40:-14|t Restaurar HP and MP", GOSSIP_SENDER_MAIN, 1);			// Restaurar HP and MP
		//AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\Achievement_BG_winAB_underXminutes:40:40:-14|t Resetar Instances", GOSSIP_SENDER_MAIN, 2);	// Resetar Instances
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\SPELL_HOLY_BORROWEDTIME:40:40:-14|t Resetar Cooldowns", GOSSIP_SENDER_MAIN, 3);				// Resetar Cooldowns
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\Achievement_BG_AB_defendflags:40:40:-14|t Resetar Combate", GOSSIP_SENDER_MAIN, 4);			// Resetar Combate
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\Spell_Shadow_DeathScream:40:40:-14|t Remover Sickness", GOSSIP_SENDER_MAIN, 5);				// Remover Sickness
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\INV_Hammer_24:40:40:-14|t Reparar Items", GOSSIP_SENDER_MAIN, 6);							// Reparar Items
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface\\icons\\Achievement_WorldEvent_Lunar:40:40:-14|t Resetar Talents", GOSSIP_SENDER_MAIN, 7);			// Resetar Talents
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface/Icons/INV_Misc_Bag_07:40:40:-14|tBank", GOSSIP_SENDER_MAIN, 8);
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface/Icons/INV_Letter_11:40:40:-14|tMail", GOSSIP_SENDER_MAIN, 9);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
        return true;
	}
	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();

		switch (action)
		{
		case 1: // Restaurar HP e MP
				player->PlayerTalkClass->SendCloseGossip();
			if (player->IsInCombat())
			{
				player->PlayerTalkClass->SendCloseGossip();
				player->GetSession()->SendNotification("Você está em combate!", LANG_UNIVERSAL, player);
				return false;
				}
				else if(player->getPowerType() == POWER_MANA)
						player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));

				player->SetHealth(player->GetMaxHealth());
				player->GetSession()->SendNotification("|cffFFFF00NPC TOOLS \n |cffFFFFFFHP & MP Resetados com Sucesso!");
				player->CastSpell(player, 31726);
				break;

	   /* case 2: // Resetar Instances
				player->PlayerTalkClass->SendCloseGossip();
				for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
				{
						Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
						for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
						{
								player->UnbindInstance(itr, Difficulty(i));
						}
				}
				player->GetSession()->SendNotification("|cffFFFF00NPC TOOLS \n |cffFFFFFFInstances Resetados com Sucesso!");
				player->CastSpell(player, 59908);
				break;*/

		case 3: // Resetar Cooldowns
				player->PlayerTalkClass->SendCloseGossip();
				if (player->IsInCombat())
				{
				player->PlayerTalkClass->SendCloseGossip();
				player->GetSession()->SendNotification("Você está em combate!", LANG_UNIVERSAL, player);
				return false;
				}

				player->GetSpellHistory()->ResetAllCooldowns();
				player->GetSession()->SendNotification("|cffFFFF00NPC TOOLS \n |cffFFFFFFCooldowns Resetados com Sucesso!");
				player->CastSpell(player, 31726);
				break;

		case 4: // Resetar Combat
				player->PlayerTalkClass->SendCloseGossip();
				player->CombatStop();
				player->GetSession()->SendNotification("|cffFFFF00NPC TOOLS \n |cffFFFFFFCombate Removido com Sucesso!");
				player->CastSpell(player, 31726);
				break;

		case 5: // Remover Sickness
				player->PlayerTalkClass->SendCloseGossip();
				if(player->HasAura(15007))
				player->RemoveAura(15007);
				player->GetSession()->SendNotification("|cffFFFF00NPC TOOLS \n |cffFFFFFFSickness Removido com Sucesso!");
				player->CastSpell(player, 31726);
				break;

		case 6: // Reparar Items
				player->PlayerTalkClass->SendCloseGossip();
				player->DurabilityRepairAll(false, 0, false);
				player->GetSession()->SendNotification("|cffFFFF00NPC TOOLS \n |cffFFFFFFEquipamentos Reparados com Sucesso!");
				player->CastSpell(player, 31726);
				break;

	   case 7: // Resetar Talents
				player->PlayerTalkClass->SendCloseGossip();
				player->ResetTalents(true);
				player->SendTalentsInfoData(false);
				player->GetSession()->SendNotification("|cffFFFF00NPC TOOLS \n |cffFFFFFFTalentos Resetados com Sucesso!");
				player->CastSpell(player, 31726);
				break;
				
		case 8:	// BANK
				player->PlayerTalkClass->SendCloseGossip();
				player->GetSession()->SendShowBank(player->GetGUID());
				break;
				
		case 9: // MAIL
				player->PlayerTalkClass->SendCloseGossip();
				player->GetSession()->SendShowMailBox(player->GetGUID());
				break;

             }
                return true;
        }
};
 
void AddSC_MTG_Npc_Tools()
{
        new MTG_Npc_Tools();
}