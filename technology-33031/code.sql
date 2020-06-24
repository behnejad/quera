-- Section1
   select name from singer where balance = 0;
-- Section2
   CREATE TABLE producer (name varchar(20) NOT NULL PRIMARY KEY);
   insert into producer (name) SELECT DISTINCT (producer) as name from song;
-- Section3
   select singer, sum(total_sell) from song where producer = "dr.dre" GROUP by singer order by sum(total_sell) desc limit 1 offset 1;