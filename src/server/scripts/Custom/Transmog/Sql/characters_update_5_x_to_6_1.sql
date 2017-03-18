ALTER TABLE `custom_transmogrification`
    COMMENT='6_1',
    ADD INDEX `Owner` (`Owner`);

ALTER TABLE `custom_transmogrification_sets`
    COMMENT='6_1';
	
ALTER TABLE `custom_transmogrification`
	COMMENT='6_2',
	COLLATE='utf8_general_ci';
	
REPLACE INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (11129, 'You don\'t have enough %ss', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);