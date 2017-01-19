#include "ScriptMgr.h"


class npc_teleporter_1 : public CreatureScript
{
    public:
        npc_teleporter_1() : CreatureScript("npc_teleporter_1") { }
 
        struct npc_teleporter_1AI : public ScriptedAI
        {
            npc_teleporter_1AI(Creature* creature) : ScriptedAI(creature) { }
 
            void  UpdateAI(uint32 diff)
            {
                if (Player* player = me->SelectNearestPlayer(1.0f))
                {
                    if (!player || player->IsBeingTeleported() || !player->IsAlive() || player->IsInCombat())
                        return;
 
					player->TeleportTo(1, -8923.866f, -1454.928f, 25.272f, 5.459f);
                }
            }
        };
 
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_teleporter_1AI(creature);
        }
};

class npc_teleporter_2 : public CreatureScript
{
    public:
        npc_teleporter_2() : CreatureScript("npc_teleporter_2") { }
 
        struct npc_teleporter_2AI : public ScriptedAI
        {
            npc_teleporter_2AI(Creature* creature) : ScriptedAI(creature) { }
 
            void  UpdateAI(uint32 diff)
            {
                if (Player* player = me->SelectNearestPlayer(1.0f))
                {
                    if (!player || player->IsBeingTeleported() || !player->IsAlive() || player->IsInCombat())
                        return;
 
					player->TeleportTo(1, -8923.932f, -1360.171f, 25.272f, 0.789f);
                }
            }
        };
 
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_teleporter_2AI(creature);
        }
};

class npc_teleporter_3 : public CreatureScript
{
    public:
        npc_teleporter_3() : CreatureScript("npc_teleporter_3") { }
 
        struct npc_teleporter_3AI : public ScriptedAI
        {
            npc_teleporter_3AI(Creature* creature) : ScriptedAI(creature) { }
 
            void  UpdateAI(uint32 diff)
            {
                if (Player* player = me->SelectNearestPlayer(1.0f))
                {
                    if (!player || player->IsBeingTeleported() || !player->IsAlive() || player->IsInCombat())
                        return;
 
					player->TeleportTo(1, -8828.410f, -1380.191f, 25.272f, 0.792f);
                }
            }
        };
 
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_teleporter_3AI(creature);
        }
};

class npc_teleporter_4 : public CreatureScript
{
    public:
        npc_teleporter_4() : CreatureScript("npc_teleporter_4") { }
 
        struct npc_teleporter_4AI : public ScriptedAI
        {
            npc_teleporter_4AI(Creature* creature) : ScriptedAI(creature) { }
 
            void  UpdateAI(uint32 diff)
            {
                if (Player* player = me->SelectNearestPlayer(1.0f))
                {
                    if (!player || player->IsBeingTeleported() || !player->IsAlive() || player->IsInCombat())
                        return;
 
					player->TeleportTo(1, -8828.477f, -1441.674f, 25.209f, 5.505f);
                }
            }
        };
 
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_teleporter_4AI(creature);
        }
};

class npc_teleporter_5 : public CreatureScript
{
    public:
        npc_teleporter_5() : CreatureScript("npc_teleporter_5") { }
 
        struct npc_teleporter_5AI : public ScriptedAI
        {
            npc_teleporter_5AI(Creature* creature) : ScriptedAI(creature) { }
 
            void  UpdateAI(uint32 diff)
            {
                if (Player* player = me->SelectNearestPlayer(1.0f))
                {
                    if (!player || player->IsBeingTeleported() || !player->IsAlive() || player->IsInCombat())
                        return;
 
					player->TeleportTo(1, -9005.089f, -1441.344f, 25.272f, 4.763f);
                }
            }
        };
 
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_teleporter_5AI(creature);
        }
};

class npc_teleporter_6 : public CreatureScript
{
    public:
        npc_teleporter_6() : CreatureScript("npc_teleporter_6") { }
 
        struct npc_teleporter_6AI : public ScriptedAI
        {
            npc_teleporter_6AI(Creature* creature) : ScriptedAI(creature) { }
 
            void  UpdateAI(uint32 diff)
            {
                if (Player* player = me->SelectNearestPlayer(1.0f))
                {
                    if (!player || player->IsBeingTeleported() || !player->IsAlive() || player->IsInCombat())
                        return;
 
					player->TeleportTo(1, -9005.132f, -1373.829f, 25.272f, 1.649f);
                }
            }
        };
 
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_teleporter_6AI(creature);
        }
};


void AddSC_Mall_Teleporter()
{
    new npc_teleporter_1();
	new npc_teleporter_2();
	new npc_teleporter_3();
	new npc_teleporter_4();
	new npc_teleporter_5();
	new npc_teleporter_6();
}