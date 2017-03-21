/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// This is where scripts' loading functions should be declared:


// The name of this function should match:
// void Add${NameOfDirectory}Scripts()

void AddSC_Professions_NPC();
void AddSC_npc_enchantment();
void AddSC_Mall_Teleporter();
void AddSC_MTG_Npc_Enchants();
void AddSC_MTG_Npc_Reset();
void AddSC_MTG_Npc_Tools();
void AddSC_MTG_TopHonor();
void AddSC_MTG_TopKills();
void AddSC_Npc_Beastmaster();
void AddSC_Npc_Valto();
void AddSC_Transmogrification();
void AddSC_NPC_Teleporter();

void AddCustomScripts()
{
	AddSC_Professions_NPC();
	AddSC_npc_enchantment();
	AddSC_Mall_Teleporter();
	AddSC_MTG_Npc_Enchants();
	AddSC_MTG_Npc_Reset();
	AddSC_MTG_Npc_Tools();
	AddSC_MTG_TopHonor();
	AddSC_MTG_TopKills();
	AddSC_Npc_Beastmaster();
	AddSC_Npc_Valto();
	AddSC_Transmogrification();
	AddSC_NPC_Teleporter();
}
