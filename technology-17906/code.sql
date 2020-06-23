-- Section1
   insert into Player (id, age, team) select id, 24, "Chelsea" from Person where id not in (select id from Refree union select id from Player union select id from Coach);
-- Section2
   select id, name from person where id in (select coach.id as id from coach, player where coach.id = player.id and coach.team <> player.team);
-- Section3
   alter table player ADD CONSTRAINT fk_l_id FOREIGN KEY (team) REFERENCES team(name) ON DELETE CASCADE;