-- Section1
	select max(salary) as salary from employees ;
-- Section2
	select teams.name as team, te.name as employee, te.salary as salary from teams join (select name, salary, employees.team_id from employees join (select max(salary) as s, team_id from employees group by team_id order by s desc) as t on employees.team_id = t.team_id and employees.salary = t.s order by salary desc) as te on te.team_id = teams.id;