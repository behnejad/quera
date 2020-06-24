-- Section1
CREATE PROCEDURE `proc1` ()  
begin
update Stadium set capacity = capacity - 100;
end;
-- Section2
CREATE PROCEDURE proc2 (in amount int)
BEGIN
select driver.email from travel, driver where travel.driver_name = driver.name group by (driver.email) having sum(travel.price) > amount;
END;
-- Section3
CREATE PROCEDURE proc3 (in amount int, in mail varchar(100))
begin
select passenger.name from passenger, driver, travel where 
passenger.name = travel.passenger_name and driver.name = travel.driver_name and driver.email = mail
group by passenger.name having count(travel.id) > amount;
end;