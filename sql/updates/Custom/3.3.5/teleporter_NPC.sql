SET
@ENTRY          := 200000,
@NAME           := "Portal Master",
@SUBNAME        := "Warsong WoW",
@MODEL          := 21572,

@AURA           := "30540", -- "35766" = casting

@TEXT_ID        := 400000,
@GOSSIP_MENU    := 60000,

@RUNE           := 194394;


-- Deleting code

DELETE FROM creature_template WHERE entry = @ENTRY;
DELETE FROM creature_template_addon WHERE Entry = @ENTRY ;
DELETE FROM gossip_menu WHERE entry BETWEEN @GOSSIP_MENU AND @GOSSIP_MENU+8;
DELETE FROM npc_text WHERE ID BETWEEN @TEXT_ID AND @TEXT_ID+4;
DELETE FROM gossip_menu_option WHERE menu_id BETWEEN @GOSSIP_MENU AND @GOSSIP_MENU+8;
DELETE FROM smart_scripts WHERE entryorguid = @ENTRY AND source_type = 0;
DELETE FROM conditions WHERE (SourceTypeOrReferenceId = 15 OR SourceTypeOrReferenceId = 14) AND SourceGroup BETWEEN @GOSSIP_MENU AND @GOSSIP_MENU+8;
DELETE from creature WHERE ID = @ENTRY;
DELETE from gameobject WHERE ID = @RUNE;

-- Teleporter

INSERT INTO creature_template (entry, modelid1, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, faction, npcflag, speed_walk, speed_run, scale, rank, unit_class, unit_flags, type, type_flags, InhabitType, RegenHealth, flags_extra, AiName) VALUES
(@ENTRY, @MODEL, @NAME, @SUBNAME, "Directions", @GOSSIP_MENU, 71, 71, 35, 3, 1, 1.14286, 1.25, 1, 1, 2, 7, 138936390, 3, 1, 2, "SmartAI");

-- Teleporter aura

INSERT INTO creature_template_addon (entry, mount, bytes1, bytes2, emote, path_id, auras) VALUES (@ENTRY, 0, 0, 0, 0, 0, @AURA);

-- Gossip header text link to menus

INSERT INTO gossip_menu (entry, text_id) VALUES
(@GOSSIP_MENU, @TEXT_ID+1),
(@GOSSIP_MENU, @TEXT_ID);

-- Gossip header texts

INSERT INTO npc_text (ID, text0_0, em0_1) VALUES
(@TEXT_ID+1, "$B For The Alliance!$B", 6),
(@TEXT_ID,  "$B For the Horde!$B", 6);


-- Conditions for gossip option and menu factions





/*------------------------------------------------------------------Innen kell módosítani------------------------------------------------------------------------------------*/






INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ConditionTypeOrReference, ConditionValue1, Comment) VALUES
/* Ha beraksz egy új portál helyet, akkor mind a két sort be kell írni, mert egyik az alli a másik a horda oldal. 

Minta:

(15, @GOSSIP_MENU, 1, 6, 469, "Stormwind"),
(15, @GOSSIP_MENU, 2, 6, 67, "Orgrimmar"),

*/


(15, @GOSSIP_MENU, 1, 6, 469, "Shattrath - Mall"),
(15, @GOSSIP_MENU, 2, 6, 67, "Shattrath - Mall"),
(15, @GOSSIP_MENU, 3, 6, 469, "Farm Zone"),
(15, @GOSSIP_MENU, 4, 6, 67, "Farm Zone"),
(15, @GOSSIP_MENU, 5, 6, 469, "Jump"),
(15, @GOSSIP_MENU, 6, 6, 67, "Jump"),
(15, @GOSSIP_MENU, 7, 6, 469, "Duel Zone"),
(15, @GOSSIP_MENU, 8, 6, 67, "Duel Zone"),
(15, @GOSSIP_MENU, 9, 6, 469, "PVP Zone"),
(15, @GOSSIP_MENU, 10, 6, 67, "PVP Zone"),


/* Ezeket ne bántsd */

(14, @GOSSIP_MENU, @TEXT_ID+1, 6, 469, "For the Alliance"),
(14, @GOSSIP_MENU, @TEXT_ID, 6, 67, "For the Horde");


INSERT INTO gossip_menu_option (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
/* Ha beraksz egy új portál helyet, akkor mind a két sort be kell írni, mert egyik az alli a másik a horda oldal. 

Minta:

(@GOSSIP_MENU, 1, 2, "Stormwind", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Stormwind?"),
(@GOSSIP_MENU, 2, 2, "Orgrimmar", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Orgrimmar?");

*/

(@GOSSIP_MENU, 1, 2, "Shattrath - Mall", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Shattrath - Mall?"),
(@GOSSIP_MENU, 2, 2, "Shattrath - Mall", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Shattrath - Mall?"),
(@GOSSIP_MENU, 3, 2, "Farm Zone", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Farm Zone?"),
(@GOSSIP_MENU, 4, 2, "Farm Zone", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Farm Zone?"),
(@GOSSIP_MENU, 5, 2, "Jump", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Jump?"),
(@GOSSIP_MENU, 6, 2, "Jump", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Jump?"),
(@GOSSIP_MENU, 7, 2, "Duel Zone", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Duel Zone?"),
(@GOSSIP_MENU, 8, 2, "Duel Zone", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to Duel Zone?"),
(@GOSSIP_MENU, 9, 2, "PVP Zone", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to PVP Zone?"),
(@GOSSIP_MENU, 10, 2, "PVP Zone", 1, 1, @GOSSIP_MENU, 0, 0, 0, "Are you sure, that you want to go to PVP Zone?");

INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES 
/* Ha beraksz egy új portál helyet, akkor mind a két sort be kell írni, mert egyik az alli a másik a horda oldal. 

Minta: Megjegyzem itt csak másolni kell és a koordinátákat kell csak átírni.

(@ENTRY, 0, 1, 0, 62, 0, 100, 0, @GOSSIP_MENU, 1, 0, 0, 62, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, -8842.09, 626.358, 94.0867, 3.61363, "Teleporter script"),
(@ENTRY, 0, 2, 0, 62, 0, 100, 0, @GOSSIP_MENU, 2, 0, 0, 62, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 1601.08, -4378.69, 9.9846, 2.14362, "Teleporter script");

*/

(@ENTRY, 0, 1, 0, 62, 0, 100, 0, @GOSSIP_MENU, 1, 0, 0, 62, 530, 0, 0, 0, 0, 0, 7, 0, 0, 0, -1807, 5601, 131, 1, "Teleporter script"),
(@ENTRY, 0, 2, 0, 62, 0, 100, 0, @GOSSIP_MENU, 2, 0, 0, 62, 530, 0, 0, 0, 0, 0, 7, 0, 0, 0, -1807, 5601, 131, 1, "Teleporter script"),
(@ENTRY, 0, 3, 0, 62, 0, 100, 0, @GOSSIP_MENU, 3, 0, 0, 62, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, -2705, -4666, 10, 5, "Teleporter script"),
(@ENTRY, 0, 4, 0, 62, 0, 100, 0, @GOSSIP_MENU, 4, 0, 0, 62, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, -2705, -4666, 10, 5, "Teleporter script"),
(@ENTRY, 0, 5, 0, 62, 0, 100, 0, @GOSSIP_MENU, 5, 0, 0, 62, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, -8626, -4813, 1, 4, "Teleporter script"),
(@ENTRY, 0, 6, 0, 62, 0, 100, 0, @GOSSIP_MENU, 6, 0, 0, 62, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, -8626, -4813, 1, 4, "Teleporter script"),
(@ENTRY, 0, 7, 0, 62, 0, 100, 0, @GOSSIP_MENU, 7, 0, 0, 62, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 5209, -4816, 701, 1, "Teleporter script"),
(@ENTRY, 0, 8, 0, 62, 0, 100, 0, @GOSSIP_MENU, 8, 0, 0, 62, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 5209, -4816, 701, 1, "Teleporter script"),
(@ENTRY, 0, 9, 0, 62, 0, 100, 0, @GOSSIP_MENU, 9, 0, 0, 62, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, -13311.247070, 81.240616, 22.186565, 0.989192, "Teleporter script"),
(@ENTRY, 0, 10, 0, 62, 0, 100, 0, @GOSSIP_MENU, 10, 0, 0, 62, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, -13311.247070, 81.240616, 22.186565, 0.989192, "Teleporter script");