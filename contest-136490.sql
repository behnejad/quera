-- Section1
    select id as order_id from orders where status = 'warehouse'  order by id DESC;
-- Section2
    select id as customer_id, name as customer_name from customers where id not in (select distinct(customer_id) from orders) order by name ASC;
-- Section3
    
    select created_at, format(sum(case when status = 'canceled' then 1 else 0 end)  * 100 / count(1), 0) as cancellation_rate from orders
    customer_id not in (select id from customers where is_blocked = 1) 
    group by created_at;