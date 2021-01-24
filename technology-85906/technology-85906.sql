-- Section1
UPDATE foods SET recipe = REPLACE(recipe , '@hamid_ashpazbashi2', '@hamid_ashpazbashi');
-- Section2
select T.id as id, T.name as name, case when T.rating is null then 0 else T.rating end as rating, T.rate_count as rate_count from 
(select foods.id as id, foods.name as name , avg(ratings.rate) as rating, count(ratings.rate) as rate_count
from foods left join ratings on foods.id = ratings.food_id group by foods.id) as T
order by T.rating desc, T.rate_count desc, T.id desc limit 10;
-- Section3
select foods.id as id, foods.name as name, foods.recipe as recipe, 
case when T.total_price is null then 0.0 else T.total_price end as total_price
from foods left join 
(select food_ingredients.food_id as id, 
sum(food_ingredients.amount * ingredients.price_per_unit) as total_price 
from food_ingredients join ingredients on food_ingredients.ingredient_id = ingredients.id
GROUP by food_ingredients.food_id) as T on foods.id = T.id;
-- Section4
select id
from foods 
where foods.id not in
(select food_ingredients.food_id as id
from food_ingredients join user_ingredients
on food_ingredients.ingredient_id = user_ingredients.ingredient_id
where user_ingredients.amount < food_ingredients.amount and user_ingredients.user_id in 
(select id from users where users.username = "quera"))
and (select count(1) from food_ingredients where food_ingredients.food_id = foods.id) > 0
order by id desc;
